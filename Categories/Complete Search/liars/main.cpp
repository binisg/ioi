#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_max(vector<int> &G, vector<int> &L) {
    vector<int> val(G.size()+L.size(), 0);

    for (int i = 0; i < G.size(); i++) {
        for (int j = 0; j < L.size(); j++) {
            if (L[j] < G[i]) {
                val[i]++;
                val[G.size()+j]++;
            }
        }
    }

    int output = -1, output_index = -1;
    for (int i = 0; i < val.size(); i++) {
        if (val[i] > 0 && val[i] > output) {
            output = val[i];
            output_index = i;
        }
    }

    return output_index;
}

int main() {
    int N;
    scanf("%d", &N);
    cin.ignore();

    vector<int> G, L;
    for (int i = 0; i < N; i++) {
        char c; int x;
        scanf("%c%d", &c, &x);
        cin.ignore();
        if (c == 'G') G.push_back(x);
        else L.push_back(x);
    }

    int result = find_max(G, L), counter = 0;

    while (result != -1) {
        if (result >= G.size()) {
            L.erase(L.begin()+(result - G.size()));
        } else if (result >= 0) {
            G.erase(G.begin()+result);
        }
        counter++;
        result = find_max(G, L);
    } 

    printf("%d\n", counter);

    return 0;
}