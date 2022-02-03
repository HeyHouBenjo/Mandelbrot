
#include "../headers/Mandelbrot.h"

void Mandelbrot::init() {
	initializeOpenGLFunctions();


}

void Mandelbrot::draw() {

}

void Mandelbrot::zoom(double delta) {
	scale *= delta;
}

void Mandelbrot::setIterations(int value) {
	iterations = value;
}


