#include <stdlib.h>
#include <stdio.h>

int main() {

    const char *v[] = {"one","two","three",
                       "four","five","six",
                       "seven","eight","nine"};
    int a = 0;
    int b = 0;

    scanf("%d\n%d",&a,&b);

    for (int i = a; i <= b; i++) {
        if ((i >= 1) && (i <= 9)) {
            printf("%s\n",v[i-1]);
        } else if (i > 9) {
            if (i%2 == 0) {
                printf("even\n");
            } else {
                printf("odd\n");
            }
        }
    }

    return 0;
}
