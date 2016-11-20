#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define A_LARGE_NUMBER 1000000
bool isSpecialFriend(int id, int numSpFriends, int spFriendIds[]);
typedef struct nodePosts {
    bool special;
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
    // int max = 0;
    // int j, jWithMax = 0;
    // int prevMax = A_LARGE_NUMBER;
    // for (i = 0; i < numPosts; i++) {
    //     for (j = 0; j < numPosts; j++) {
    //         if (posts[j].special == 1) {
    //             if (posts[j].popularity > max && posts[j].popularity < prevMax) {
    //                 max = posts[j].popularity;
    //                 jWithMax = j;
    //                 prevMax = max;
    //             }
    //         }
    //     }
    //     printf("%s\n", posts[j].content);
    //     max = 0;
    // }

    int k;
    for (k = 0; k < numPosts; k++) {
        showStruct(posts[k]);
    }





    return 0;
}

bool isSpecialFriend(int id, int numSpFriends, int spFriendIds[]) {
    int i;
    for (i = 0; i < numSpFriends; i++) {
        if (id == spFriendIds[i]) return true;
    }
    return false;
}

void showStruct(nodePosts k) {
    printf("===============\nisSpecial: %d\nid: %d\nPopularity: %d\nContent: %s\nNextAddress: %p\n", k.special, k.id, k.popularity, k.content, k.next);
}
