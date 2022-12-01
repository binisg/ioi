#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

struct pos {
    int i, j, val;
    pi right = {-1, -1}, left = {-1, -1}, up = {-1, -1}, down = {-1, -1};
};

vector<vector<pos>> vec;
vector<vector<bool>> visited;

int grass(pos &p, int K) {
    if (visited[p.i][p.j]) return 0;
    if (K == -1) return 0;
    visited[p.i][p.j] = true;
    int sum = p.val;
    if (p.right.first != -1) sum += grass(vec[p.right.first][p.right.second], K-1);
    if (p.left.first != -1) sum += grass(vec[p.left.first][p.left.second], K-1);
    if (p.up.first != -1) sum += grass(vec[p.up.first][p.up.second], K-1);
    if (p.down.first != -1) sum += grass(vec[p.down.first][p.down.second], K-1);
    return sum;
}

int main() {
    FILE *in = fopen("lazy.in", "r");
    FILE *out = fopen("lazy.out", "w");

    int N, K;
    fscanf(in, "%d%d", &N, &K);
    vec.resize(N, vector<pos>(N));
    visited.resize(N, vector<bool> (N));

    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            pos p;
            fscanf(in, "%d", &p.val);
            p.i = a; p.j = b;
            vec[a][b] = p;
        }
    }

    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            if (a - 1 >= 0) {
                vec[a][b].up.first = a-1; vec[a][b].up.second = b;
            }
            if (b - 1 >= 0) {
                vec[a][b].left.first = a; vec[a][b].left.second = b-1;
            }
            if (a + 1 < N) {
                vec[a][b].down.first = a+1; vec[a][b].down.second = b;
            }
            if (b + 1 < N) {
                vec[a][b].right.first = a; vec[a][b].right.second = b+1;
            }   
        }
    }

    // O(n*)

    int result = 0, max_result = 0;
    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    visited[i][j] = 0;
                }
            }
            result = grass(vec[a][b], K);
            max_result = max(max_result, result);
            if (result == 373) cout << a << " " << b << endl;
        }
    }

    cout << max_result << endl;
    fprintf(out, "%d\n", max_result);

    return 0;
}