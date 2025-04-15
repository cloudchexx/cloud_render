#ifndef __MODEL_H__
#define __MODEL_H__

#include <vector>
#include "geometry.h"
#include "tgaimage.h"   //tga画图库

//模型类
class Model {
private:
	std::vector<Vec3f> verts_;//顶点集，每个顶点都是三维向量
	std::vector<std::vector<Vec3i>> faces_;//面片集
	//我们还需要，uv纹理坐标集，法线集，纹理地址
	std::vector<Vec3f> norms_;//法线集
	std::vector<Vec2f> uv_;//uv纹理坐标集
	TGAImage diffuseMap_;//纹理地址
	void loadTexture(std::string filename, const char* suffix, TGAImage& image);  //加载纹理坐标

public:
	Model(const char *filename);//根据.obj文件路径导入模型
	~Model();
	int nverts();//返回模型顶点数量
	int nfaces();//返回模型面片数量
	Vec3f vert(int i);//返回第i个顶点
	std::vector<int> face(int idx);//返回第idx个面片
	Vec2i uv(int iface , int nvert);//返回第iface个面片的第nvert个顶点的uv坐标
	TGAColor diffuse(Vec2i uv);//返回uv坐标的纹理颜色
};

#endif //__MODEL_H__