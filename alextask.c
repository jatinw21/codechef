#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    // DEBUG
    printf("T: %d\n",T); // we get num of test cases
    int i, j;
    int N;

    // for each test cases
    // get N then get all N's from next line, solve it
    for (i = 0; i < T; i++) {
        scanf("%d", &N);
        // DEBUG
        printf("N: %d\n", N);
        int times[N];
        for (j = 0; j < N; j++) {
            scanf("%d",&(times[j]));
            // DEBUG
            printf("%d ",times[j] );
        }
        // DEBUG
        printf("\n");
    }
}
