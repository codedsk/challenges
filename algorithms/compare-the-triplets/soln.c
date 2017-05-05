// https://www.hackerrank.com/challenges/compare-the-triplets

#include <stdio.h>
#include <stdlib.h>

int int_cmp(int a, int b) {
    int result = 0;
    if (a < b) {
        result = -1;
    } else if (a > b) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

int* solve(int a0, int a1, int a2, int b0, int b1, int b2, int* result_size) {
    int a[3] = {a0, a1, a2};
    int b[3] = {b0, b1, b2};
    int* result = NULL;

    *result_size = 2;

    result = (int*) calloc((*result_size),sizeof(int));

    for (size_t i = 0; i < 3; i++) {
        switch ( int_cmp(a[i],b[i]) ) {
            case 1 :
                result[0] += 1;
                break;
            case -1 :
                result[1] += 1;
                break;
            default :
                // do nothing
                ;
        }
    }

    return result;
}

#ifndef TESTING
int main() {
    int a0;
    int a1;
    int a2;
    scanf("%d %d %d", &a0, &a1, &a2);
    int b0;
    int b1;
    int b2;
    scanf("%d %d %d", &b0, &b1, &b2);
    int result_size;
    int* result = solve(a0, a1, a2, b0, b1, b2, &result_size);
    for (int result_i = 0; result_i < result_size; result_i++) {
        if (result_i) {
            printf(" ");
        }
        printf("%d",result[result_i]);
    }

    return 0;
}
#endif
