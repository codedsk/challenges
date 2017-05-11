// https://www.hackerrank.com/challenges/diagonal-difference

#include <stdio.h>
#include <stdlib.h>

// index into the array with:
// idx = (n*row)+col
//
//  11   2    4
//   4   5    6
//  10   8  -12
//
//  (11 + 5 + -12) - (4 + 5 + 10)
//  11 + 5 + -12 - 4 - 5 - 10
//  (11 - 4) + (5 - 5) + (-12 - 10)
//
// or as indecies (row,col)
//
// (0,0) (0,1) (0,2)
// (1,0) (1,1) (1,2)
// (2,0) (2,1) (2,2)
//
// ((0,0)-(0,2)) + ((1,1)-(1,1)) + ((2,2)-(2,0))
//
// This is an O(n) solution.


int diagdiff(int* a, size_t n) {
    int result = 0;
    size_t idx1 = 0;
    size_t idx2 = 0;

    for (size_t row = 0; row < n; row++) {
        // col equals either row or (n-row-1)
        idx1 = (n*row) + row;
        idx2 = (n*row) + (n-row-1);
        if (row <= n) {
            result += a[idx1] - a[idx2];
        } else {
            result += a[idx2] - a[idx1];
        }
    }
    return abs(result);
}

#ifndef TESTING
// Constraints
// -100 <= Elements in the matrix <= 100

int main() {
    size_t n;
    scanf("%zd",&n);

    /*
    int a[n][n];
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            scanf("%d",&a[i][j]);
        }
    }
    */

    int a[n*n];
    for (size_t i = 0; i < n*n; i++) {
        scanf("%d",&a[i]);
    }

    printf("%d",diagdiff(a,n));
    return 0;
}
#endif
