#include <vector>
#include <cmath>
#include "tgaimage.h"   //tga画图库
#include "model.h"      //模型类，主要实现模型的读取
#include "geometry.h"   //几何库，主要定义了Vec2和Vec3类型

//定义颜色
const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);
const TGAColor green = TGAColor(0,   255, 0,   255);
Model *model = NULL;
//定义宽度高度
const int width  = 800;
const int height = 800;

//世界坐标转化为屏幕坐标 , NDC坐标转化为屏幕坐标
Vec3f world2screen(Vec3f v)
{
    return Vec3f(int((v.x + 1.) * width / 2. + .5), int((v.y + 1.) * height / 2. + .5), v.z);  
}

//计算三角形的重心坐标
Vec3f barycentric(Vec3f* pts, Vec3f P) {
    float xa = pts[0].x;
    float ya = pts[0].y;
    float xb = pts[1].x;
    float yb = pts[1].y;
    float xc = pts[2].x;
    float yc = pts[2].y;
    float x = P.x;
    float y = P.y;

    float gamma = ((ya - yb) * x + (xb - xa) * y + xa * yb - xb * ya) / ((ya - yb) * xc + (xb - xa) * yc + xa * yb - xb * ya);
    float beta = ((ya - yc) * x + (xc - xa) * y + xa * yc - xc * ya) / ((ya - yc) * xb + (xc - xa) * yb + xa * yc - xc * ya);
    float alpha = 1 - gamma - beta;
    
    return Vec3f(alpha, beta, gamma);
}

//画线算法
void line(Vec2f t0, Vec2f t1,TGAImage &image,TGAColor color){

    int x0 = t0.x;
    int y0 = t0.y;
    int x1 = t1.x;
    int y1 = t1.y;

    bool steep = false;
    if(abs(x1-x0) < abs(y1-y0)){
        std::swap(x0,y0);
        std::swap(x1,y1);
        steep = true;
    }
    if(x0 > x1){
        std::swap(x0,x1);
        std::swap(y0,y1);
    }
    int dx = x1 - x0;
    int dy = abs(y1 - y0);
    int p = 2*dy - dx;
    int error_1 = 2 * dy;
    int error_2 = 2 * (dy - dx);
    
    int x = x0 , y = y0;
    if(steep)
        image.set(y,x,color);
    else
        image.set(x,y,color);
    for(int x = x0+1; x < x1; x++){
        if(p < 0){
            p+= error_1;
        }
        else{
            p += error_2;
            y += y1>y0 ? 1:-1;
        }
        if(steep)
            image.set(y,x,color);
        else
            image.set(x,y,color);
    }
}

//向量叉乘算法，通过向量判断点是否在三角形内
void triangle(Vec3f *pts ,Vec2i *uvs ,  float* zBuffer ,TGAImage &image, float intensity) { 

    //提出三个坐标
    Vec3f t0 = pts[0];
    Vec3f t1 = pts[1];
    Vec3f t2 = pts[2];

    //按照y值对三点排序
    if(t0.y > t1.y) std::swap(t0, t1);
    if(t0.y > t2.y) std::swap(t0, t2);
    if(t1.y > t2.y) std::swap(t1, t2);

    // 包围盒,虽然是三维坐标，但实际上我门只需要x和y坐标，z坐标是深度值
    Vec2f boxmin = Vec2f(std::min(t0.x, std::min(t1.x, t2.x)), std::min(t0.y, std::min(t1.y, t2.y)));
    Vec2f boxmax = Vec2f(std::max(t0.x, std::max(t1.x, t2.x)), std::max(t0.y, std::max(t1.y, t2.y)));

    // 提升到 3D（z=1）
    Vec3f v0 = t0;
    Vec3f v1 = t1;
    Vec3f v2 = t2;

    // 遍历包围盒
    for (int i = boxmin.x; i <= boxmax.x; i++) {
        for (int j = boxmin.y; j <= boxmax.y; j++) {
            Vec3f p(i, j, 0);
            Vec2i uvP;
            Vec3f baryCoord = barycentric(pts, p);

            // 计算三个边的叉乘（注意方向一致性）
            Vec3f cross0 = (v1 - v0) ^ (p - v0);  // 边 v0→v1 和 v0→p
            Vec3f cross1 = (v2 - v1) ^ (p - v1);  // 边 v1→v2 和 v1→p
            Vec3f cross2 = (v0 - v2) ^ (p - v2);  // 边 v2→v0 和 v2→p

            // 判断叉乘结果的 z 分量是否同号（点在三角形内）
            if ((cross0.z >= 0 && cross1.z >= 0 && cross2.z >= 0) ||(cross0.z <= 0 && cross1.z <= 0 && cross2.z <= 0)){
                float z_interpolation = baryCoord.x * pts[0].z + baryCoord.y * pts[1].z + baryCoord.z * pts[2].z;
                if(z_interpolation > zBuffer[static_cast<int>(p.x + p.y * width)]){ //只有z值大于zBuffer的值才会更新
                    zBuffer[static_cast<int>(i + j * width)] = z_interpolation;  //插值z
                    uvP = uvs[0] * baryCoord.x + uvs[1] * baryCoord.y + uvs[2] * baryCoord.z;
                    TGAColor texColor = model->diffuse(uvP);
                    //加上光照
                    TGAColor color = TGAColor(texColor.r * intensity, texColor.g * intensity, texColor.b * intensity, 255);
                    image.set(p.x, p.y, color);
                }
            }
        }
    }
}


int main(int argc, char** argv) {
    if (2 == argc) {
        model = new Model(argv[1]);
    }
    else {
        model = new Model("../obj/diablo3_pose/diablo3_pose.obj");
        // model = new Model("../obj/african_head/african_head.obj");
    }

    TGAImage image(width, height, TGAImage::RGB);
    Vec3f light_dir(0, 0, -1);

    //z-buffer  我们这里屏幕的点将需要z值，所以变为三维坐标
    float* zBuffer = new float[width * height];
    for (int i = 0; i < width * height; i++)
    {
        zBuffer[i] = -std::numeric_limits<float>::max();
    }

    for (int i = 0; i < model->nfaces(); i++)
    {
        std::vector<int> face = model->face(i);//获取模型的第i个面片
        Vec3f screenCoords[3];//屏幕坐标
        Vec3f worldCoords[3];//世界坐标
        for (int j = 0; j < 3; j++)
        {
            worldCoords[j] = model->vert(face[j]);//分别取出第i个面片三个顶点的世界坐标（其实应该是NDC坐标了）
            // screenCoords[j] = Vec2f((worldCoords[j].x + 1.) * width / 2., (worldCoords[j].y + 1.) * height / 2.);//转换为屏幕坐标
            screenCoords[j] = world2screen(worldCoords[j]);//转换为屏幕坐标
        }
        Vec3f normal = (worldCoords[2] - worldCoords[0]) ^ (worldCoords[1] - worldCoords[0]);//计算三角形法线
        normal.normalize();
        float intensity = normal * light_dir;
        if(intensity > 0){
            Vec2i uv[3];//uv坐标
            for (int j = 0; j < 3; j++) uv[j] = model->uv(i, j);
            triangle(screenCoords, uv ,  zBuffer , image, intensity);
        }
    }

    image.flip_vertically(); 
    image.write_tga_file("output.tga");
    
    return 0;
}