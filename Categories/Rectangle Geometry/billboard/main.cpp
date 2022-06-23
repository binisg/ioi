#include <iostream>
#include <cstdio>

using namespace std;

FILE *in = fopen("billboard.in", "r");
FILE *out = fopen("billboard.out", "w");

struct board {
    int x1, y1, x2, y2;
    int width() {
        return x2 - x1;
    } 
    int height() {
        return  y2 - y1;
    }
};

int covered (board &x, board &t) {
    int x_covered = max(0, min(x.x2, t.x2) - max(x.x1, t.x1));
    int y_covered = max(0, min(x.y2, t.y2) - max(x.y1, t.y1));
    if ((x_covered == x.width() && (t.y1 <= x.y1 || t.y2 >= x.y2)) || (y_covered == x.height() && (t.x1 <= x.x1 || t.x2 >= x.x2))) return x_covered * y_covered;
    return 0;
}

int main() {
    board x, t;
    int input[8];
    fscanf(in, "%d%d%d%d%d%d%d%d", &input[0], &input[1], &input[2], &input[3], &input[4], &input[5], &input[6], &input[7]);
    for (int i = 0; i < 8; i++) {
        input[i] += 1000;
    }

    x.x1 = input[0], x.y1 = input[1], x.x2 = input[2], x.y2 = input[3], t.x1 = input[4], t.y1 = input[5], t.x2 = input[6], t.y2 = input[7];

    int area = x.width() * x.height();
    int result = area - covered(x, t);

    fprintf(out, "%d", result);

    fclose(in);
    fclose(out);
    return 0;
}