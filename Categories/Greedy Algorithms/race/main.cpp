// to_be_solved

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int K, N;

int solve(int limit) {
    int temp = 0, sum = 0, i = 0;
    while (sum < K && i <= limit) {
        sum += i;
        i++;
    }
    int counter = i-1;
    if (sum >= K) return counter;

    int small_k = K - (i-1);
    small_k--;
    int result = i + calc(small_k);

    return 0;
}

int main() {
    FILE *in = fopen("race.in", "r");
    FILE *out = fopen("race.out", "w");

    fscanf(in, "%d%d", &K, &N);

    int arr[N]; 

    for (int i = 0; i < N; i++) {
        fscanf(in, "%d", &arr[i]);
    }

    for (int i = 0; i < N; i++) {
        cout << solve(arr[i]) << endl;
    }

    return 0;
}