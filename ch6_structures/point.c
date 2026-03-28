#include <stdio.h>


struct point {      //structure tag
        int x, y;       //structure memmbers
    };


int main(void) {
    struct point maxpt = { 320, 200 };
    printf("%d, %d\n", maxpt.x, maxpt.y);

    struct rect {
        struct point pt1, pt2;
    };

    struct rect screen = {3, 4, 4, 3};
    // screen.pt1.x = 5;
    // screen.pt1.y = 4;
    printf("(%d, %d) | (%d, %d)\n", screen.pt1.x, screen.pt1.y, screen.pt2.x, screen.pt2.y);
}