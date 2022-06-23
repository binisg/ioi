#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

#define ll long long

using namespace std;

vector<string> paths (vector<vector<int>> &vec) {

    vector<string> result = {};

    int x = 0, y = 0;
    for (int i{}; i < vec.size(); i++) {
        for (int j{}; j < vec.size(); j++) {
            if (vec[i][j] == 2) {
                x = i;
                y = j;
            }
        }
    }


    if (x == vec.size()-1 && y == vec.size()-1) {
        vector<string> nothing = {""};
        return nothing;
    }

    vec[x][y] = 0;

    vector<string> v1 = {}, v2 = {}, v3 = {}, v4 = {}, to_add_v1 = {}, to_add_v2 = {}, to_add_v3 = {}, to_add_v4 = {};

    if (x-1 >= 0 && vec[x-1][y] == 1) {
        vec[x-1][y] = 2;
        v1 = paths(vec);
        for (string s: v1) {
            to_add_v1.push_back("U" + s);
        }
        vec[x-1][y] = 1;
    }
    
    if (x+1 < vec.size() && vec[x+1][y] == 1) {
        vec[x+1][y] = 2;
        v2 = paths(vec);
        for (string s: v2) {
            to_add_v2.push_back("D" + s);
        }
        vec[x+1][y] = 1;
    }

    if (y-1 >= 0 && vec[x][y-1] == 1) {
        vec[x][y-1] = 2;
        v3 = paths(vec);
        for (string s: v3) {
            to_add_v3.push_back("L" + s);
        }
        vec[x][y-1] = 1;
    }

    if (y+1 < vec.size() && vec[x][y+1] == 1) {
        vec[x][y+1] = 2;
        v4 = paths(vec);
        for (string s: v4) {
            to_add_v4.push_back("R" + s);
        }
        vec[x][y+1] = 1;
    }

    for (string s: to_add_v1) result.push_back(s);
    for (string s: to_add_v2) result.push_back(s);
    for (string s: to_add_v3) result.push_back(s);
    for (string s: to_add_v4) result.push_back(s);

    return result;

}   

int main() {

    FILE *in = fopen("numOfGridPaths.in", "r");
    FILE *out = fopen("numOfGridPaths.out", "w");

    int N;
    fscanf(in, "%d", &N);

    vector<vector<int>> vec (N, vector<int> (N));

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            fscanf(in, "%d", &vec[i][j]);
        }
    }

    vector<string> final = paths(vec);
    for (string s: final) {
        fprintf(out, "%s\n", s.c_str());
    }

    // fprintf(out, "%lld", paths(vec));

    return 0;
}