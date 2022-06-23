#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

#define ll long long

using namespace std;

ll paths (vector<vector<int>> &vec) {

    ll result = 0;

    int x = 0, y = 0;
    for (int i{}; i < vec.size(); i++) {
        for (int j{}; j < vec.size(); j++) {
            if (vec[i][j] == 2) {
                x = i;
                y = j;
            }
        }
    }

    if (x == vec.size()-1 && y == vec.size()-1) return 1;

    vec[x][y] = 0;

    if (x-1 >= 0 && vec[x-1][y] == 1) {
        vec[x-1][y] = 2;
        result += paths(vec);
        vec[x-1][y] = 1;
    }
    
    if (x+1 < vec.size() && vec[x+1][y] == 1) {
        vec[x+1][y] = 2;
        result += paths(vec);
        vec[x+1][y] = 1;
    }

    if (y-1 >= 0 && vec[x][y-1] == 1) {
        vec[x][y-1] = 2;
        result += paths(vec);
        vec[x][y-1] = 1;
    }

    if (y+1 < vec.size() && vec[x][y+1] == 1) {
        vec[x][y+1] = 2;
        result += paths(vec);
        vec[x][y+1] = 1;
    }

    return result;

}   

int main() {

    FILE *in = fopen("pathsInGrid.in", "r");
    FILE *out = fopen("pathsInGrid.out", "w");

    int N;
    fscanf(in, "%d", &N);

    vector<vector<int>> vec (N, vector<int> (N));

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            fscanf(in, "%d", &vec[i][j]);
        }
    }

    // map<pair<int, int>, ll> memo;
    fprintf(out, "%lld", paths(vec));

    return 0;
}