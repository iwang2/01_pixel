all: pixel.c
	gcc -o pixel pixel.c

clean:
	rm image.ppm
	rm pixel
	rm *~

run: all
	./pixel

create: run
	convert image.ppm image.png

display: run
	display image.ppm
