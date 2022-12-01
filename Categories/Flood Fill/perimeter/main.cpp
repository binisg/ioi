#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
#define x first 
#define y second 

const int MAX_N = 10e3+5;

int N, M;
vector<string> vec(MAX_N);
bool visited[MAX_N][MAX_N];

bool mysort (pi &a, pi &b) {
    if (a.x != b.x) return a.x > b.x;
    else return b.y > a.y;  
}

pi solve (int i, int j) {
    pi result = {0, 0};

    stack<pi> s; s.push({i, j});
    int a, b;

    while (!s.empty()) {
        a = s.top().x, b = s.top().y;
        s.pop();

        if (a < 0 || a >= N || b < 0 || b >= M) {
            result.y++;
            continue;
        }

        if (visited[a][b]) continue;

        if (vec[a][b] == '.') {
            result.y++;
            continue;
        }

        if (vec[a][b] == '#') {
            visited[a][b] = true;
            result.x++;
        }

        s.push({a-1, b}); s.push({a, b-1}); s.push({a+1, b}); s.push({a, b+1});

    }

    return result;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }
    M = vec[0].size();

    vector<pi> pairs;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            if (!visited[i][j] && vec[i][j] != '.') {
                pairs.push_back(solve(i, j));
            }
        }
    }

    sort(pairs.begin(), pairs.end(), mysort);
    cout << pairs[0].x << ' ' << pairs[0].y << '\n';

    return 0;
}