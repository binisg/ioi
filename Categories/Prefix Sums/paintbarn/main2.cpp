#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    FILE *in = fopen("paintbarn.in", "r");
    FILE *out = fopen("paintbarn.out", "w");

    int N, K;
    fscanf(in, "%d%d", &N, &K);

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        fscanf(in, "%d%d%d%d", &x1, &y1, &x2, &y2);
        
    }

    return 0;
}