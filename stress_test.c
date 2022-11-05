#include <stdio.h>
#include <stdlib.h>

void main() {
    for (float i=0.0; i<0.0000001; i+=0.00000001) {
        printf("%d, ", i);
    }
}
