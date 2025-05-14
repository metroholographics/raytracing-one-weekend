#include <stdio.h>
#include <windows.h>
#include "vec3.h"
#include "ray.h"

color ray_color(ray r) {
    vec3 unit_direction = vec3_unit_vector(r.direction);
    float a = 0.5 * (unit_direction.y + 1.0);

    return vec3_add_vec(
        vec3_multiply((color){1.0, 1.0, 1.0}, (1.0 - a)),
        vec3_multiply((color) {0.5, 0.7, 1.0}, a)
    );
}

int main (void) {
    SetConsoleOutputCP(CP_UTF8);

    float aspect_ratio = 16.0 / 9.0;
    int image_width = 400;
    int image_height = (int) (image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // Camera
    float focal_length = 1.0;
    float viewport_height = 2.0;
    float viewport_width = viewport_height * (double)(image_width / image_height);
    point3 camera_center = (point3) {0, 0, 0};

    vec3 viewport_u = (vec3) {viewport_width, 0, 0};
    vec3 viewport_v = (vec3) {0, -viewport_height, 0};
    vec3 pixel_delta_u = vec3_divide(viewport_u, (float) image_width);
    vec3 pixel_delta_v = vec3_divide(viewport_v, (float) image_height);

    point3 viewport_upper_left = vec3_subtract_vec(
        vec3_subtract_vec(
            vec3_subtract_vec(
                camera_center, (vec3) {0, 0, focal_length}
            ),
            vec3_divide(viewport_u, 2.0f)
        ),
        vec3_divide(viewport_v, 2.0f)
    );
    
    point3 pixel100_loc = vec3_add_vec(
        viewport_upper_left, vec3_multiply(
            vec3_add_vec(pixel_delta_u, pixel_delta_v),
            0.5f
        ) 
    );

    FILE* image = fopen(".\\image.ppm", "w");
    if (!image) {
        printf("error creating file\n");
        return -1;
    } else {
        printf("image file created\n");
    }

    fprintf(image, "P3\n%d %d\n255\n", image_width, image_height);
    for (int j = 0; j < image_height; j++) {
        printf("\rScanlines remaining: %d", image_height - j);
        fflush(stdout);
        for (int i = 0; i < image_width; i++) {
            point3 pixel_center = vec3_add_vec(
                vec3_add_vec(
                    pixel100_loc, vec3_multiply(pixel_delta_u, i)
                ),
            (vec3_multiply(pixel_delta_v, j)));

            vec3 ray_direction = vec3_subtract_vec(pixel_center, camera_center);
            ray r = (ray) {camera_center, ray_direction};

            color pixel_color = ray_color(r);
            write_color(image, pixel_color);
        }
    }
    printf("\rImage written.                 \n");
    if (image) {
        fclose(image);
    }
    return 0;
} 

