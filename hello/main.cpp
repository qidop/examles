#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Log(fmt, ...) {printf("" fmt,  ##__VA_ARGS__); printf("\n"); }

int main(int argc, char *argv[]) {

	int A = 1, B = 2, C = 3;

	int R = A + B + C;

	Log("result=%i", R);

	return 0;
}