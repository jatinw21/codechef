#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#define LONG_MAX 9223372036854775807

// by eucleadian theorem gcd(a,b)=gcd(b,r) where a =b*q +r , so a%b = r
long long gcd(long long a, long long b) {
    if(b == 0) {
        return a;
    } else {
        return(gcd(b,a%b));
    }
}

long long lcm(long long a, long long b) {
    return (a*b)/gcd(a,b);
}

int main(int argc, char *argv[]) {
    int T, i, j, k, l, N;
    scanf("%d", &T);
    // DEBUG
    // printf("T: %d\n",T); // we get num of test cases

    long long minLcm, m;
    // for each test cases
    // get N then get all N's from next line, solve it
    for (i = 0; i < T; i++) {
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
        // the smallest lcm of any two numbers is our solution.
        minLcm = LONG_MAX;
        for (k = 0; k < N-1; k++) {
            for (l = k+1; l < N; l++) {
                m = lcm(times[k],times[l]);
                if (m < minLcm) {
                    minLcm = m;
                }
            }
        }
        printf("%lld\n",minLcm);

    }
    return 0;
}
