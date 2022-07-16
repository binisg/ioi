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
    int counter = i-1, end = i-1;
    if (sum >= K) return counter;

    int c = 0, p = 0;

    while (true) {
        if (sum + (temp * 2) + i < K) {
            c++;
            temp += i;
            i++;
        } else if (sum + (temp * 2) < K) {
            sum += (i-1);
            p++;
        } else {
            temp -= (i-1);
            sum += (temp*2);
            temp += (i-1);
            sum += (i-1);
            c--;
            c *= 2;
            c++;
            break;
        }
    }

    counter += c;
    counter += p;
    while (sum < K) {
        sum += end;
        counter++;
    }

    return counter;
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
        int res = solve(arr[i]);
        fprintf(out, "%d\n", res);
    }

    return 0;
}