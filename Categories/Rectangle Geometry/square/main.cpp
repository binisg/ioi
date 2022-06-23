#include <iostream>
#include <cstdio>

using namespace std;

struct board {
	int x1, y1, x2, y2;
};

int width(board &a, board &b) {
	return max(a.x2, b.x2) - min(a.x1, b.x1);
}

int height(board &a, board &b) {
	return max(a.y2, b.y2) - min(a.y1, b.y1);
}

int main() {
	FILE *in = fopen("square.in", "r");
	FILE *out = fopen("square.out", "w");

	board a, b;
    int input[8];
    fscanf(in, "%d%d%d%d%d%d%d%d", &input[0], &input[1], &input[2], &input[3], &input[4], &input[5], &input[6], &input[7]);
    for (int i = 0; i < 8; i++) {
        input[i] += 1000;
    }

    a.x1 = input[0], a.y1 = input[1], a.x2 = input[2], a.y2 = input[3], b.x1 = input[4], b.y1 = input[5], b.x2 = input[6], b.y2 = input[7];

	int result = max(width(a, b), height(a, b));
	result *= result;

	fprintf(out, "%d", result);

	return 0;
}