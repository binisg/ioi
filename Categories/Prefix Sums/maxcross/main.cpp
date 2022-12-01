#include <bits/stdc++.h>
using namespace std;

#define scan(x) fscanf(in, "%d", &x);
#define print(x) fprintf(out, "%d\n", x);

int main() {
    FILE *in = fopen("maxcross.in", "r");
    FILE *out = fopen("maxcross.out", "w");

    int N, K, B;
    scan(N); scan(K); scan(B);

    int arr[B+2]; arr[0] = 0; arr[1] = N+1;
    for (int i = 0; i < B; i++) scan(arr[i+2]);

    sort(arr, arr+B+2);
    int sum[B+1], before[B+1];

    for (int i = 1; i < B+2; i++) {
        sum[i-1] = arr[i+1]-1 - arr[i-1];
        before[i-1] = arr[i] - arr[i-1] - 1;
    }

    int min_result = N, curr_sum = before[0], i = 0, j = 0;
    for (j = 0; j < B+1; j++) {
        curr_sum += (sum[j] - before[j]);
        if (curr_sum == K) min_result = min(min_result, j-i+1);
        else if (curr_sum > K && i < B) {
            while (curr_sum > K) {
                min_result = min(min_result, j-i+1);
                curr_sum -= (sum[i] - before[i+1]);
                i++;
            }
            if (curr_sum == K) min_result = min(min_result, j-i+1);
        }
    }

    if (N - arr[B-1] >= K) min_result = min(min_result, 0);

    print(min_result);
    
    return 0;
}