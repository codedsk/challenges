// https://www.hackerrank.com/challenges/plus-minus

#include <stdio.h>
#include <stdlib.h>

void plusminus(int* a, size_t n, float* result) {
    result[0] = 0;  // positive
    result[1] = 0;  // negative
    result[2] = 0;  // zeros
    for (size_t i = 0; i < n; i++) {
        if (a[i] < 0) {
            result[1] += 1;
        } else if (a[i] > 0) {
            result[0] += 1;
        } else {
            result[2] += 1;
        }
    }
    result[0] = (1.0*result[0])/n;
    result[1] = (1.0*result[1])/n;
    result[2] = (1.0*result[2])/n;
}

#ifndef TESTING
int main() {
    size_t n;
    scanf("%zd",&n);

    int a[n];
    for (size_t i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }

    float result[3];
    plusminus(a,n,(float*)&result);
    printf("%6f\n%6f\n%6f",result[0],result[1],result[2]);

    return 0;
}
#endif
