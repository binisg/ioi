#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct cow {
    int start;
    int duration;
    int index;
};

bool startsort (cow &a, cow &b) {
    return a.start < b.start;
}

int main() {
    FILE *in = fopen("convention2.in", "r");
    FILE *out = fopen("convention2.out", "w");

    int N; fscanf(in, "%d", &N);
    vector<cow> cows(N);

    for (int i = 0; i < N; i++) {
        fscanf(in, "%d%d", &cows[i].start, &cows[i].duration);
        cows[i].index = i;
    }

    vector<cow> sec = cows;
    sort(cows.begin(), cows.end(), startsort);

    int time = cows[0].start;
    priority_queue<int> pq;
    int result[N];

    int i = 0;
    while (i < N || !pq.empty()) {
        if (i < N && cows[i].start <= time) { 
            while (i < N && cows[i].start <= time) {
                pq.push(-cows[i].index);
                i++;
            }
        }
        if (pq.empty()) {
            pq.push(-cows[i].index);
            time = cows[i].start;
            i++;
        }
        result[-pq.top()] = time;
        time = time + sec[-pq.top()].duration;
        pq.pop();
    }

    int max_wait = 0;
    for (int i = 0; i < N; i++) {
        int curr_wait = result[i] - sec[i].start;
        max_wait = max(max_wait, curr_wait);
    }

    fprintf(out, "%d\n", max_wait);

    return 0;
}