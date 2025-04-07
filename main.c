#include <stdio.h>
#include <windows.h>
#include "vec3.c"

#define IMG_WIDTH 256
#define IMG_HEIGHT 256

int main (void) {
    SetConsoleOutputCP(CP_UTF8);
    FILE* image = fopen(".\\image.ppm", "w");
    if (!image) {
        printf("error creating file\n");
        return -1;
    } else {
        printf("image file created\n");
    }
    fprintf(image, "P3\n%d %d\n255\n", IMG_WIDTH, IMG_HEIGHT);
    for (int j = 0; j < IMG_HEIGHT; j++) {
        printf("\rScanlines remaining: %d", IMG_HEIGHT - j);
        fflush(stdout);
        for (int i = 0; i < IMG_WIDTH; i++) {
            color pixel_color = (color) {
                .x = (float)i / (IMG_WIDTH-1),
                .y = (float)j / (IMG_HEIGHT-1),
                .z = 0.0f,
            };
            write_color(image, pixel_color);
        }
    }
    printf("\rImage written.                 \n");
    if (image) {
        fclose(image);
    }
    return 0;
} 

