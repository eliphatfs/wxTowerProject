#ifndef VEC3_H_INCLUDED
#define VEC3_H_INCLUDED

struct mat33_t {
    double matrix[3][3];
    mat33_t left_mul(mat33_t &matin0);
    static mat33_t translate(double a, double b);
};
struct vec3_t {
    double vector[3];
    vec3_t left_mul(mat33_t &matin0);
    double& operator[](int num);
};

#endif // VEC3_H_INCLUDED
