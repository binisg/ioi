#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

int main() {
    FILE *in = fopen("longsumk.in", "r");
    FILE *out = fopen("longsumk.out", "w");

    int N, K;
    fscanf(in, "%d%d", &N, &K);

    int arr[N];
    for (int i = 0; i < N; i++) {
        fscanf(in, "%d", &arr[i]);
    }

    deque<int> d;
    int sum = 0, max_result = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
        d.push_back(arr[i]);
        while (sum > K) {
            sum -= d.front();
            d.pop_front();
        }
        if (sum == K) max_result = max(max_result, (int)d.size());
    }

    fprintf(out, "%d", max_result);

    return 0;
}