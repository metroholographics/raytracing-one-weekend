#include <stdio.h>
#include <windows.h>

#define IMG_WIDTH 256
#define IMG_HEIGHT 256

int main (void) {
    SetConsoleOutputCP(CP_UTF8);
    FILE* image = fopen(".\\image.ppm", "w");
    if (!image) {
        printf("eror opening file\n");
        return -1;
    } else {
        printf("image file created\n");
    }
    
    fprintf(image, "P3\n%d %d\n255\n", IMG_WIDTH, IMG_HEIGHT);
    for (int j = 0; j < IMG_HEIGHT; j++) {
        printf("\rScanlines remaining: %d", IMG_HEIGHT - j);
        fflush(stdout);
        for (int i = 0; i < IMG_WIDTH; i++) {
            double r = (double)i / (IMG_WIDTH-1);
            double g = (double)j / (IMG_HEIGHT-1);
            double b = 0.0;
            int ir = (int) 255.999 * r;
            int ig = (int) 255.999 * g;
            int ib = (int) 255.999 * b;
            fprintf(image, "%d %d %d\n", ir, ig, ib);
        }
    }
    printf("\rImage written.                 \n");
    if (image) {
        fclose(image);
    }
    return 0;
}

