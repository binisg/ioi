#include <iostream>
#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

int my_cow_sort(pi x, pi y) {
    if (x.second > y.second) return 0;
    else if (x.second < y.second) return 1;
    else {
        if (x.first > y.first) return 0;
        else return 1;
    }
}

int main() {
    FILE *in = fopen("reduce.in", "r");
    FILE *out = fopen("reduce.out", "w");

    int N;
    fscanf(in, "%d", &N);

    vector<pi> cows(N);
    int max_x = 0, max_y = 0;
    for (int i = 0; i < N; i++) {
        fscanf(in, "%d%d", &cows[i].first, &cows[i].second);
        max_x = max(max_x, cows[i].first);
        max_y = max(max_y, cows[i].second);
    }

    tuple<int, int, int> x1;
    tuple<int, int, int> x2;
    tuple<int, int, int> y1;
    tuple<int, int, int> y2;

    int prev_area = 0;

    sort(cows.begin(), cows.end());
    int a = cows[cows.size()-1].first - cows[0].first + 1;

    if (cows.size() < 4 || cows[1].first != cows[4].first) {
        get<0>(x1) = cows[1].first-1;
        if (cows.size() < 4 || cows[2].first != cows[4].first) {
            get<1>(x1) = cows[2].first-1;
            if (cows.size() < 4 || cows[3].first != cows[4].first) {
                get<2>(x1) = cows[3].first-1;
            }
        }
    }

    get<0>(x2) = max_x - cows[cows.size()-2].first;
    get<1>(x2) = max_x - cows[cows.size()-3].first;
    get<2>(x2) = max_x - cows[cows.size()-4].first;

    sort(cows.begin(), cows.end(), my_cow_sort);
    int b = cows[cows.size()-1].second - cows[0].second + 1;

    if (cows.size() < 4 || cows[1].second != cows[4].second) {
        get<0>(y1) = cows[1].second-1;
        if (cows.size() < 4 || cows[2].second != cows[4].second) {
            get<1>(y1) = cows[2].second-1;
            if (cows.size() < 4 || cows[3].second != cows[4].second) {
                get<2>(y1) = cows[3].second-1;
            }
        }
    }

    get<0>(y2) = max_y - cows[cows.size()-2].second;
    get<1>(y2) = max_y - cows[cows.size()-3].second;
    get<2>(y2) = max_y - cows[cows.size()-4].second;

    cout << get<0>(x1) << " "  << get<1>(x1) << " "  << get<2>(x1) << endl;
    cout << get<0>(x2) << " "  << get<1>(x2) << " "  << get<2>(x2) << endl;
    cout << get<0>(y1) << " "  << get<1>(y1) << " "  << get<2>(y1) << endl;
    cout << get<0>(y2) << " "  << get<1>(y2) << " "  << get<2>(y2) << endl;
    cout << (a*b) << " " << (a-42)*(b-88) << endl; // find overlap spot?

    return 0;
}