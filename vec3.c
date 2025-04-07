#include <stdio.h>
#include <math.h>

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



void write_color(FILE* f, color px_col) {
    float r = px_col.x;
    float g = px_col.y;
    float b = px_col.z;

    int rbyte = (int) (255.999 * r);
    int gbyte = (int) (255.999 * g);
    int bbyte = (int) (255.999 * b);

    fprintf(f, "%d %d %d\n", rbyte, gbyte, bbyte);
}

void vec3_show(vec3 v) {
    printf("%f %f %f\n", v.x, v.y, v.z);
}

float vec3_x(vec3 v) {
    return v.x;
}

float vec3_y(vec3 v) {
    return v.y;
}

float vec3_z(vec3 v) {
    return v.z;
}

vec3 vec3_negative(vec3 v) {
    return (vec3) {
        .x = -v.x,
        .y = -v.y,
        .z = -v.z
    };
}

float vec3_value(vec3 v, char c) {
    switch (c) {
        case 'x': return v.x;
        case 'y': return v.y;
        case 'z': return v.z;
        default: return 0.0f;
    }
}

vec3 vec3_add_vec(vec3 v, vec3 u) {
    return (vec3) {
        .x = v.x + u.x,
        .y = v.y + u.y,
        .z = v.z + u.z
    };
}

vec3 vec3_subtract_vec(vec3 v, vec3 u) {
    return (vec3) {
        .x = v.x - u.x,
        .y = v.y - u.y,
        .z = v.z - u.z
    };
}

vec3 vec3_multiply(vec3 v, float t) {
    return (vec3) {
        .x = v.x * t,
        .y = v.y * t,
        .z = v.z * t
    };
}

vec3 vec3_multiply_vec(vec3 v, vec3 u) {
    return (vec3) {
        .x = v.x * u.x,
        .y = v.y * u.y,
        .z = v.z * u.z
    };
} 

vec3 vec3_divide(vec3 v, float t) {
    return vec3_multiply(v, 1.0 / t);
}

float vec3_length_sqrd(vec3 v) {
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

float vec3_length(vec3 v) {
    return sqrtf(vec3_length_sqrd(v));
}

float vec3_dot(vec3 v, vec3 u) {
    return v.x * u.x + v.y * u.y + v.z * u.z; 
}

vec3 vec3_cross(vec3 v, vec3 u) {
    return (vec3) {
        .x = v.y * u.z - v.z * u.y,
        .y = v.z * u.x - v.x * u.z,
        .z = v.x * u.y - v.y * u.x     
    };    
}

vec3 vec3_unit_vector(vec3 v) {
    return vec3_divide(v, vec3_length(v));
}

