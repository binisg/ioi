#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int N, M, K; cin >> N >> M >> K;
    cin.ignore();

    vector<string> strings(N);
    for (int i = 0; i < N; i++) {
        cin >> strings[i];
    }

    vector<vector<char>> initial(N, vector<char> (M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            initial[i][j] = strings[i][j];
        }
    }

    vector<vector<char>> res(N*K);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int l = ((i+1)*K)-K; l < ((i+1)*K); l++) {
                for (int k = 0; k < K; k++) {
                    res[l].push_back(initial[i][j]);
                }
            }
        }
    } 

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j];
        }
        cout << '\n';
    }

    return 0;
}