#include <iostream>
#include <cstdio> 
#include <map>

using namespace std;

int main() {
    FILE *in = fopen("pails.in", "r");
    FILE *out = fopen("pails.out", "w");

    int X, Y, M;
    fscanf(in, "%d%d%d", &X, &Y, &M);

    int max_num = 0;

    for (int i = 0; ; i++) {
        int current_num = 0;
        int a = X * i;
        current_num += a;
        if (a > M) break;
        current_num += (M-a) - ((M-a) % Y);
        if (current_num > max_num) max_num = current_num;
    }

    for (int i = 0; ; i++) {
        int current_num = 0;
        int b = Y * i;
        current_num += b;
        if (b > M) break;
        current_num += (M-b) - ((M-b) % X);
        if (current_num > max_num) max_num = current_num;
    }

    fprintf(out, "%d", max_num);

    fclose(in);
    fclose(out);

    return 0;
}