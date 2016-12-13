#include <cstdlib>
#include <cstdio>

int main() {
    int c = 0;
    int arr[1000];

    // read in the count
    scanf("%d",&c);

    // read in the array
    for (int i = 0; i < c; i++) {
        scanf("%d",&(arr[i]));
    }

    // print out the array in reverse
    for (int i = c-1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

    return 0;
}
