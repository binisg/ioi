#include <iostream>
#include <cstdio>

using namespace std;

#define ll long long

int main() {
    FILE *in = fopen("div7.in", "r");
    FILE *out = fopen("div7.out", "w");

    ll N;
    fscanf(in, "%lld", &N);

    ll arr[N], sums[N+1];
    for (int i = 0; i < N; i++) fscanf(in, "%lld", &arr[i]);

    sums[0] = 0;
    for (int i = 1; i <= N; i++) sums[i] = sums[i-1] + arr[i-1];

    ll sum = 0, dif = 0, max_dif = 0;
    for (int i = 0; i < N; i++) {
        sum = sums[i+dif] - sums[i];
        for (int j = i+dif; j < N; j++) {
            sum += arr[j];
            if (sum % 7 == 0 && j-i+1 > max_dif) {
                max_dif = j-i+1;
                dif = max_dif-1;
            }
        }
        sum = 0;
    }

    fprintf(out, "%lld\n", max_dif);

    return 0;
}