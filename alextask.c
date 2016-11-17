#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    // DEBUG
    // printf("T: %d\n",T); // we get num of test cases
    int i, j, k;
    int N;
    long long lcm;
    int numDiv = 0;
    // for each test cases
    // get N then get all N's from next line, solve it
    for (i = 0; i < T; i++) {
        lcm = 1;
        scanf("%d", &N);
        // DEBUG
        // printf("N: %d\n", N);
        long long times[N];
        for (j = 0; j < N; j++) {
            scanf("%lld",&(times[j]));
            // DEBUG
            // printf("%d ",times[j] );
        }
        // DEBUG
        // printf("\n");

        // After getting all N's, now we do actual stuff
        // smallest number that divides two numbers out of given N's is our answer
        // so check foreach N if LCM % N is 0. when it reaches 2, break and lcm is answer
        bool lcmNotFound = true;
        while (lcmNotFound) {
            // printf("Inside while loop\n");
            // printf("Going into for loop\n");
            for (k = 0; k < N; k++) {
                // printf("Checking if %d is divided by %d\n",lcm,times[k] );
                if (lcm % times[k] == 0) {
                    // printf("%d is divisible by %d\n",lcm,times[k]);
                    // printf("Incrementing numDiv now. Rn it is %d\n",numDiv );
                    numDiv++;
                    // printf("Now it is %d\n",numDiv );
                    if (numDiv == 2) {
                        // printf("numDiv == 2 so print lcm and break\n");
                        printf("%lld\n", lcm);
                        lcmNotFound = false;
                        // printf("Should go outside loop now\n");
                        break;
                    }
                }
            }
            if(!lcmNotFound) break;
            lcm++;
            numDiv = 0;
        }


    }
    return 0;
}
