#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
#define x first 
#define y second 

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);

    int N; cin >> N;
    vector<pi> vec(N);

    for (int i = 0; i < N; i++) {
        cin >> vec[i].x >> vec[i].y;
    }

    return 0;
}