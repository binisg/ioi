#include <iostream>
#include <map>
#include <unordered_map>
#include <cmath>
#include <vector>

using namespace std;

int N; unordered_map<int, int> m;
map<int, vector<int>> memo;

void gd(int &num) {
    if (memo.count(num)) {
        for (int i: memo[num]) m[i]++;
        return;
    }
    vector<int> vec;
    for (int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            if (num / i == i) {
                m[i]++;
                vec.push_back(i);
            } else {
                m[i]++; m[num/i]++;
                vec.push_back(i);
                vec.push_back(num/i);
            }
        }
    }
    memo[num] = vec;
}

int main() {
    int N; scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int x; scanf("%d", &x);
        gd(x);
    }

    int max_num = 0;
    for (auto i: m) {
        if (i.second == N || i.second == N-1) {
            max_num = max(max_num, i.first);
        }
    }

    printf("%d", max_num);

    return 0;
}