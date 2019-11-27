#ifndef VEC3_H_INCLUDED
#define VEC3_H_INCLUDED

struct mat33_t {
    double matrix[3][3];
    mat33_t left_mul(mat33_t &matin0);
};
struct vec3_t {
    double vector[3];
    vec3_t left_mul(mat33_t &matin0);
};

#endif // VEC3_H_INCLUDED
