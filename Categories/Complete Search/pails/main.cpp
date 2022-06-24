#include <iostream>
#include <cstdio> 

using namespace std;

int max_milk (int &X, int &Y, int M) {
    if (M <= 0) return 0;
    int a = max_milk(X, Y, M-X) + X;
    int b = max_milk(X, Y, M-Y) + Y;
    return max(a, b);
}

int main() {
    FILE *in = fopen("pails.in", "r");
    FILE *out = fopen("pails.out", "w");

    int X, Y, M;
    fscanf(in, "%d%d%d", &X, &Y, &M);

    int result = max_milk(X, Y, M);

    fprintf(out, "%d", result);

    return 0;
}