// https://www.hackerrank.com/challenges/a-very-big-sum

#include <stdio.h>
#include <stdlib.h>

long long bigsum(long long* arr, size_t n) {
    long long result = 0;
    for (size_t i = 0; i < n; i++) {
        result += arr[i];
    }
    return result;
}


#ifndef TESTING
// Constraints
// 1 <= N <= 10
// 0 <= A[i] <= pow(10,10)

int main() {
    size_t n;
    scanf("%zd",&n);

    long long arr[n];
    for (size_t arr_i = 0; arr_i < n; arr_i++) {
        scanf("%lld",&arr[arr_i]);
    }
    printf("%lld",bigsum(arr,n));
    return 0;

}
#endif
