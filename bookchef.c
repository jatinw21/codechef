#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define A_LARGE_NUMBER 1000000
int isSpecialFriend(int id, int numSpFriends, int spFriendIds[]);
typedef struct nodePosts {
    int special;
    int id;
    int popularity;
    char content[101];
    struct nodePosts *next;
} nodePosts;

typedef struct nodePosts *Link;

void showStruct(nodePosts k);

int main(int argc, char const *argv[]) {
    // get numSpFriends and numPosts - first line of input
    int numSpFriends, numPosts;
    scanf("%d", &numSpFriends);
    // printf("%d\n", numSpFriends);
    scanf("%d", &numPosts);
    // printf("%d\n", numPosts);
    // next line - N integers specifiers of special friends
    int i;
    int spFriendIds[numSpFriends]; // array which contains IDs of special friends
    for (i = 0; i < numSpFriends; i++) {
        scanf("%d", &(spFriendIds[i]));
    }
    // for (i = 0; i < numSpFriends; i++) {
    //     printf("%d\n", (spFriendIds[i]));
    // }

    // next M lines, get identifier, popularity, content
    nodePosts posts[numPosts];
    Link postsHead;
    for (i = 0; i < numPosts; i++) {
        if (i == 0) {
            postsHead = &(posts[i]);
        } else {
            posts[i-1].next = &(posts[i]);
        }
        scanf("%d", &posts[i].id);
        scanf("%d", &posts[i].popularity);
        scanf("%s", posts[i].content);
        posts[i].special = isSpecialFriend(posts[i].id, numSpFriends, spFriendIds);
        posts[i].next = NULL;
    }

    // for each post with special = 1, print most popularity one
    int max;
    int flag1 = 1;
    int flag2 = 1;
    int reqdIndex;
    while (flag1 || flag2) {
        max = 0; flag1 = 0; flag2 = 0;
        // printf("Going into 1st loop for checking if there is any special == 1\n");
        for (i = 0; i < numPosts; i++) {
            if (posts[i].special == 1) {
                // printf("A special == 1 is found at %d\nFlag1 is set as 1\n",i );
                flag1 = 1;
                // printf("%d\n", flag1);
                if (posts[i].popularity > max) {
                    // printf("It's pop = %d is more than max = %d\n", posts[i].popularity, max);
                    max = posts[i].popularity;
                    // printf("so new max is pop\n");
                    reqdIndex = i;
                    // printf("Reqd Index is %d\n", i);
                }
            }
        }
        // printf("%d <- This is the value of flag1\nIf 1 should go in in statement.\n", flag1 );
        if (flag1 == 1) {
            // printf("Flag1 is 1 so printing the (reqdIndex)th post and setting its special to -1\n");
            printf("%s\n", posts[reqdIndex].content);
            // HERE IS THE PROBLEM
            posts[reqdIndex].special = -1;
            // printf("posts[%d].special is now %d\n",reqdIndex, posts[reqdIndex].special );
        } else {
            for (i = 0; i < numPosts; i++) {
                if (posts[i].special == 0) {
                    flag2 = 1;
                    if (posts[i].popularity > max) {
                        max = posts[i].popularity;
                        reqdIndex = i;
                    }
                }
            }
            if (flag2 == 1) {
                printf("%s\n", posts[reqdIndex].content);
                posts[reqdIndex].special = -1;
            }
        }
    }
    // int k;
    // for (k = 0; k < numPosts; k++) {
    //     showStruct(posts[k]);
    // }

    return 0;
}

int isSpecialFriend(int id, int numSpFriends, int spFriendIds[]) {
    int i;
    for (i = 0; i < numSpFriends; i++) {
        if (id == spFriendIds[i]) return 1;
    }
    return 0;
}

void showStruct(nodePosts k) {
    printf("===============\nisSpecial: %d\nid: %d\nPopularity: %d\nContent: %s\nNextAddress: %p\n", k.special, k.id, k.popularity, k.content, k.next);
}
