#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {

   int count = 1;
   float increment = 1.0;
   float max = 10.0;

   for (int count = 1; count <= 10; count++) {

		float increment = increment/10.0;
		float max = max/10.0;

		float i = 0.0;
		int counter = 0;
		for (i = 0.0; counter < 10; i += increment) {
			counter += 1;
		}

		printf("%d \n", count);
	}
	
	return 0;
}
