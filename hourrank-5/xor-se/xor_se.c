#include<stdio.h>
#include<stdlib.h>

// https://www.hackerrank.com/contests/hourrank-5/challenges/xor-se

long int xor_sum(long int L, long int R) {
    int ones = 1;
    long s = 0;
    long start = L;
    long stop = R;
    long i = 0;
    int m = 0;

    printf("start = %ld, stop = %ld\n",L,R);

    if (start%2 != 0) {
        s = s ^ start;
        start += 1;
    }

    if (stop%2 == 0) {
        s = s ^ stop;
        stop = R-1;
    }

    for (i = start; i <= stop; i+=2) {
        printf("iterating %ld\n",i);
        m = i&3;
        if (m == 0) {
            s = s ^ i;
        } else if (m == 2) {
            s = s ^ (i+1);
        }
    }

    return s;
}

int main() {

    int a = 0;
    int Q = 0;
    long *ranges = NULL;
    long s = 0;

    scanf("%d",&Q);

    ranges = (long*) calloc(2*Q,sizeof(Q));

    for (a = 0; a < 2*Q; a+=2) {
        scanf("%ld %ld", &ranges[a], &ranges[a+1]);
    }

    for (a = 0; a < 2*Q; a+=2) {
        s = xor_sum(ranges[a],ranges[a+1]);
        printf("%ld",s);
    }

    free(ranges);

    return 0;
}
