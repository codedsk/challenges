#include <stdlib.h>
#include <stdio.h>

int main() {
    size_t c = 0;
    int *arr = NULL;

    // read in the count
    scanf("%d",&c);

    // allocate space for the array
    arr = (int*) calloc(c,sizeof(int));

    for (int i = 0; i < c; i++) {
        scanf("%d",&(arr[i]));
    }

    for (int i = c-1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
