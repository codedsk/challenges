/*
 * Read in an integer n and print out a right aligned triangle of
 * hash marks, padded by spaces on the left, with n rows, each
 * row with n-row number spaces and row number of hash marks.
 * EX: if n = 5, print
 *     #
 *    ##
 *   ###
 *  ####
 * #####
 */

#include <stdio.h>

void StairCase(int n) {

    for (int row = 1; row <= n; row++) {
        // print leading spaces
        for (int i = 0; i < n-row; i++) {
            printf(" ");
        }
        // print hashes
        for (int i = 0; i < row; i++) {
            printf("#");
        }
        printf("\n");
    }
}

int main() {
    int _n;
    scanf("%d", &_n);

    StairCase(_n);

    return 0;
}
