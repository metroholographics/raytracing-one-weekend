#ifndef VEC3_H
#define VEC3_H

#include <stdio.h>

typedef struct vec3 {
    float x;
    float y;
    float z; 
} vec3;

typedef vec3 point3;
typedef vec3 color;

float vec3_x(vec3 v);
float vec3_y(vec3 v);
float vec3_z(vec3 v);
float vec3_value(vec3 v, char c);
vec3  vec3_negative(vec3 v);
vec3  vec3_add_vec(vec3 v, vec3 u);
vec3  vec3_subtract_vec(vec3 v, vec3 u);
vec3  vec3_multiply(vec3 v, float t);
vec3  vec3_multiply_vec(vec3 v, vec3 u);
vec3  vec3_divide(vec3 v, float t);
float vec3_length_sqrd(vec3 v);
float vec3_length(vec3 v);
float vec3_dot(vec3 v, vec3 u);
vec3  vec3_cross(vec3 v, vec3 u);
vec3  vec3_unit_vector(vec3 v);
void  vec3_show(vec3 v);
void  write_color(FILE* f, color pixel_color);

#endif