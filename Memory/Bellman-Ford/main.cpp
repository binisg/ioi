#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define INF 100000005
typedef tuple<int, int, int> tu;

int main() {
    ifstream in("bellman-ford.in");

    int N, K;
    in >> N >> K;
    vector<tu> edges(K);
    vector<bool> visited(N);
    vector<int> distance(N, INF);
    for (int i = 0; i < N; i++) visited[i] = false;
    for (int i = 0; i < K; i++) {
        int a, b, c;
        in >> a >> b >> c;
        edges[i] = make_tuple(a, b, c);
    }

    distance[0] = 0;
    bool b;
    for (int i = 0; i < N-1; i++) {
        b = false;
        for (auto e: edges) {
            int a, b, w;
            tie(a, b, w) = e;
            if (distance[a]+w < distance[b]) {
                distance[b] = distance[a]+w;
                b = true;
            }
        }
        if (!b) break;
    }

    for (int i = 0; i < N; i++) cout << distance[i] << "\n";

    return 0;
}