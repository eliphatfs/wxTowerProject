#include "vec3.h"
#include <cstring>
using namespace std;
//ע�⣺matin����˵ľ����Ӧ��������vecout��matout����������Ӧ����������ʹ��ʱ��Ҫ����
vec3_t vec3_t::left_mul(mat33_t &matin) {
    vec3_t vecout;
    memset(vecout.vector, 0, sizeof(double) * 3);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            vecout.vector[i] += vector[j] * matin.matrix[i][j];
        }
    }
    return vecout;
}
mat33_t mat33_t::left_mul(mat33_t &matin) {
    mat33_t matout;
    memset(matout.matrix, 0, sizeof(double) * 9);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                matout.matrix[i][j] += matin.matrix[i][k] * matrix[k][j];
            }
        }
    }
    return matout;
}
