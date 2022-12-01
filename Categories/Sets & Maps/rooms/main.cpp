#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
#define x first 
#define y second 

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;

    vector<pair<pi, int>> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i].x.x >> vec[i].x.y;
        vec[i].y = i;
    }

    sort(vec.begin(), vec.end());

    priority_queue<pi> pq;
    vector<int> result(N);
    int counter = 0;

    for (int i = 0; i < N; i++) {
        if (pq.empty() || -pq.top().x >= vec[i].x.x) {
            counter++;
            pq.push({-vec[i].x.y, counter});
            result[vec[i].y] = counter;
        } else {
            result[vec[i].y] = pq.top().y;
            pq.pop();
            pq.push({-vec[i].x.y, result[vec[i].y]});
        }
    }

    cout << counter << '\n';
    for (int i = 0; i < N; i++) {
        cout << result[i] << ' ';
    }
    cout << '\n';

    return 0;
}