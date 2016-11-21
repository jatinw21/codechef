#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// for 4 6 12
// answer is 2*6, 3*4, 4*3
int main(int argc, char const *argv[]) {
    int T,i,n,m,c,j, answer;
    scanf("%d", &T);
    for (i = 0; i < T; i++) {
        answer = 0;
        scanf("%d", &m);
        scanf("%d", &n);
        scanf("%d", &c);
        for (j = 1; j <= m; j++) {
            if (c % j == 0) {
                if (c/j <= n) {
                    answer++;
                }
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}
