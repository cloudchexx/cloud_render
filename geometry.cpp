#include <iostream>
#include <vector>
#include <cassert>

#include "geometry.h"

Matrix::Matrix(int r,int c)
    :m(std::vector<std::vector<float>>(r, std::vector<float>(c, 0.f))), rows(r), cols(c){}

inline int Matrix::nrows()  {return rows;}
inline int Matrix::ncols()  {return cols;}

Matrix Matrix::identity(int n){
    Matrix E(n,n);
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            E[i][j] = (i == j ? 1.f : 0.f);
        }
    }
    return E;
}