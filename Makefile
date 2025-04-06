default:
	gcc -std=c99 -o main.exe main.c
run:
	.\main.exe

show: default > image.ppm
	
