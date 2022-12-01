#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pi;
#define x first 
#define y second

int main() {
    FILE *in = fopen("diamond.in", "r");
    FILE *out = fopen("diamond.out", "w");

    int N, K;
    fscanf(in, "%d%d", &N, &K);

    int arr[N];
    for (int i = 0; i < N; i++) {
        fscanf(in, "%d", &arr[i]);
    }

    sort(arr, arr+N);

    vector<pi> result(N);
    int end = -1;
    for (int i = 0; i < N; i++) {
        int sum = (i > 0) ? result[i-1].x-1 : 0;
        while (end+1 != N && arr[end+1] - arr[i] <= K) {
            sum++;
            end++;
        }
        result[i] = {sum, end+1};
    }

    vector<int> max_asc(N), max_desc(N);
    for (int i = 0; i < N; i++) max_asc[i] = (i > 0) ? max(result[i].x, max_asc[i-1]): result[i].x;

    int output = 0;
    for (int i = 0; i < N-1; i++) {
        int sec = max_asc[i];
        if (result[i].y < N) sec += max_desc[result[i].y];
        output = max(output, sec);
    }
    output = max(output, max_asc[N-1]);

    fprintf(out, "%d\n", output);

    return 0;
}