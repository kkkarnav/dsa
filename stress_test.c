#include <stdio.h>
#include <stdlib.h>

void main() {
    for (float a=0.0; a<0.0000001; a=a+0.00000001) {
        printf("%d, ", a);
    }
}
