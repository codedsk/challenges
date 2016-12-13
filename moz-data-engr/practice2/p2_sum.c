/*
 * Read in an integer s representing the number of values in the
 * array to sum. Then read in s integers into an array. Sum the
 * integers and return the result, and print it to the file
 * stored in the environment variable OUTPUT_PATH
 * Example:
 * OUTPUT_PATH="soln.out" ./p2_sum
 * 5
 * 1 2 3 4 5
 * cat soln.out
 * 15
 */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int sum(int numbers_size, int* numbers) {
    int s = 0;
    for (int i = 0; i < numbers_size; i++) {
        s += numbers[i];
    }
    return s;
}

int main() {
    FILE *f = fopen(getenv("OUTPUT_PATH"), "w");
    int res;

    int _numbers_size = 0;
    int _numbers_i;
    scanf("%d\n", &_numbers_size);
    int _numbers[_numbers_size];
    for (_numbers_i = 0; _numbers_i < _numbers_size; _numbers_i++) {
        int _numbers_item;
        scanf("%d", &_numbers_item);

        _numbers[_numbers_i] = _numbers_item;
    }

    res = sum(_numbers_size, _numbers);
    fprintf(f, "%d\n", res);

    fclose(f);
    return 0;
}
