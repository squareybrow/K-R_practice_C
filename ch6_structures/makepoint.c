#include <stdio.h>

struct point {      //structure tag
        int x, y;       //structure memmbers
    };

struct point maxpt = { 320, 200 };
struct point origin = { 0, 0 };

struct rect {
    struct point pt1, pt2;
};


struct point makepoint(int x, int y) {
    struct point temp = {x, y};
    return temp;
}

struct point addpoint(struct point p1, struct point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

int main(void) {
    struct rect screen;
    struct point middle;

    screen.pt1 = makepoint(0, 0);
    screen.pt2 = maxpt;
    middle = makepoint((screen.pt1.x + screen.pt2.x) / 2, (screen.pt1.y + screen.pt2.y) / 2);
    printf("Middle of rectangle = (%d, %d)\n", middle.x, middle.y);

    struct point *pp;
    pp = &origin;
    printf("origin = (%d, %d) | *pp = (%d, %d)\n", origin.x, origin.y, (*pp).x, pp -> y);

    return 0;
}