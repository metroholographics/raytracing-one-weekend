#include "ray.h"
#include "vec3.h"

point3 ray_at(ray r, double t) {
    vec3 dir = vec3_multiply(r.direction, t);
    return vec3_add_vec(r.origin, dir);
}