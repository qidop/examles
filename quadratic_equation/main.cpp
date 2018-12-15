#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Log(fmt, ...) {printf("" fmt,  ##__VA_ARGS__); printf("\n"); }

#include <cmath>

int main(int argc, char *argv[]) {

	double a = 0.0, b = 0.0, c = 0.0, x = 0.0;

	// ax^2 + bx + c = 0

	a = 1;	// 2;
	b = 10;	// 3;
	c = 1; 	// 5;

	// D - дискриминант

	Log("уравнение: %.6f*x^2 + %.6f*x + %.6f= ... ", a, b, c);

	double D = b * b - 4 * a * c;

	// sqrt(x)  -  функция sqrt берет квадратный корень от числа X, функция описана и реализована в наборе стандартной математики еще от СИ (#include <cmath>)

	// если дискриминант больше или равен нулю
	if(D >= 0) {
        double x1 = ( -b + sqrt(D) ) / ( 2 * a );
		Log("первый корень уравнения: %.6f", x1);
        double x2 = ( -b - sqrt(D) ) / (2 * a);
        Log("второй корень уравнения: %.6f", x2);
    } else {
    	Log("для данных переменных - уравнение не имеет действительных корней!");
    }
        

	return 0;
}