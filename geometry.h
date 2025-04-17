#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include <cmath>


//模板类，2d向量，用法是Vec2<int>(2d整形向量)、Vec2<float>(2d浮点数向量)
template <class t> 
struct Vec2 {
	union {
		struct {t u, v;};
		struct {t x, y;};
		t raw[2];
	};
	Vec2() : u(0), v(0) {}
	Vec2(t _u, t _v) : u(_u),v(_v) {}
	inline Vec2<t> operator +(const Vec2<t> &V) const { return Vec2<t>(u+V.u, v+V.v); }//向量加法
	inline Vec2<t> operator -(const Vec2<t> &V) const { return Vec2<t>(u-V.u, v-V.v); }//向量减法
	inline Vec2<t> operator *(float f)          const { return Vec2<t>(u*f, v*f); }//向量的数乘运算
	inline t& operator[](const int idx){ if (idx <= 0) return x; else return y; }
	template <class > friend std::ostream& operator<<(std::ostream& s, Vec2<t>& v);//向量输出
};

//模板类，3d向量，用法是Vec3<int>(3d整形向量)、Vec3<float>(3d浮点数向量)
template <class t> 
struct Vec3 {
	union {
		struct {t x, y, z;};
		struct { t ivert, iuv, inorm; };
		t raw[3];
	};
	Vec3() : x(0), y(0), z(0) {}
	Vec3(t _x, t _y, t _z) : x(_x),y(_y),z(_z) {}
	inline Vec3<t> operator ^(const Vec3<t> &v) const { return Vec3<t>(y*v.z-z*v.y, z*v.x-x*v.z, x*v.y-y*v.x); }//向量叉乘运算（外积）
	inline Vec3<t> operator +(const Vec3<t> &v) const { return Vec3<t>(x+v.x, y+v.y, z+v.z); }//向量加法
	inline Vec3<t> operator -(const Vec3<t> &v) const { return Vec3<t>(x-v.x, y-v.y, z-v.z); }//向量减法
	inline Vec3<t> operator *(float f)          const { return Vec3<t>(x*f, y*f, z*f); }//向量的数乘运算
	inline t       operator *(const Vec3<t> &v) const { return x*v.x + y*v.y + z*v.z; }//向量的点乘（内积）
	inline t& operator[](const int idx){ if (idx <= 0) return x; else if (idx == 1) return y; else return z; }
	float norm () const { return std::sqrt(x*x+y*y+z*z); }//向量的模长
	Vec3<t> & normalize(t l=1) { *this = (*this)*(l/norm()); return *this; }//向量归一化
	template <class > friend std::ostream& operator<<(std::ostream& s, Vec3<t>& v);//向量输出
};

typedef Vec2<float> Vec2f;//几个常用的模板特化，并且重命名
typedef Vec2<int>   Vec2i;
typedef Vec3<float> Vec3f;
typedef Vec3<int>   Vec3i;

template <class t> std::ostream& operator<<(std::ostream& s, Vec2<t>& v) {
	s << "(" << v.x << ", " << v.y << ")\n";
	return s;
}

template <class t> std::ostream& operator<<(std::ostream& s, Vec3<t>& v) {
	s << "(" << v.x << ", " << v.y << ", " << v.z << ")\n";
	return s;
}

//以下是矩阵类的定义,我们会在geometry.cpp实现这个矩阵类
const int DEFAULT_ALLOC = 4; //默认默认是四行四列方阵

class Matrix{
	private:
		std::vector<std::vector<float>> m; //二维数组，存储矩阵	
		int rows; //行数
		int cols; //列数
	public:
		Matrix(int r = DEFAULT_ALLOC, int c = DEFAULT_ALLOC); //矩阵的构造函数，默认是四行四列矩阵，除非用户自己定义
		inline int nrows();  //返回行数
		inline int ncols();  //返回列数

		static Matrix identity(int n); //创建n行n列的单位矩阵
		std::vector<float>& operator[](int i); //重载下标运算符，返回第i行
		Matrix operator *(Matrix& m2); //重载乘法运算符，返回两个矩阵的乘积
		// Matrix operator*(float f); //重载乘法运算符，返回矩阵和数的乘积
		Matrix operator+(Matrix& m2); //重载加法运算符，返回两个矩阵的和
		Matrix operator-(Matrix& m2); //重载减法运算符，返回两个矩阵的差
		Matrix transpose(); //转置矩阵
		Matrix inverse(); //求逆矩阵
		Matrix adjoint(); //求伴随矩阵

		friend std::ostream& operator<<(std::ostream& s, Matrix& m); //重载输出运算符，输出矩阵
};

#endif //__GEOMETRY_H__