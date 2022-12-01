#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
#define x first
#define y second
#define ll long long

int main() {
    FILE *in = fopen("rental.in", "r");
    FILE *out = fopen("rental.out", "w");

    int N, M, R;
    fscanf(in, "%d%d%d", &N, &M, &R);

    vector<pi> cows(N);
    for (int i = 0; i < N; i++) {
        fscanf(in, "%d", &cows[i].x);
        cows[i].y = i;
    }

    sort(cows.rbegin(), cows.rend());

    vector<pi> gallons(M);
    for (int i = 0; i < M; i++) {
        fscanf(in, "%d%d", &gallons[i].y, &gallons[i].x);
    }

    sort(gallons.begin(), gallons.end());

    vector<int> neighbors(R);
    for (int i = 0; i < R; i++) {
        fscanf(in, "%d", &neighbors[i]);
    }

    sort(neighbors.begin(), neighbors.end());

    vector<int> money(N);
    for (int i = 0; i < N; i++) {
        int milk = cows[i].x, val = 0;
        while (milk != 0 && gallons.size() > 0) {
            int sub = min(milk, gallons[gallons.size()-1].y);
            gallons[gallons.size()-1].y -= sub;
            val += (sub * gallons[gallons.size()-1].x);
            if (gallons[gallons.size()-1].y == 0)
                gallons.pop_back();
            milk -= sub;
        }
        money[i] = val;
    }

    for (int i = N-1; i >= 0; i--) {
        if (money[i] < neighbors[neighbors.size()-1]) {
            money[i] = neighbors[neighbors.size()-1];
            neighbors.pop_back();
        }
    }

    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum += money[i];
    }

    fprintf(out, "%lld\n", sum);

    return 0;
}