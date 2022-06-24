#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cow {
    int x, y, index;
};

int north_sort(cow a, cow b) {
    if (a.x > b.x) return 0;
    else if (a.x == b.x) {
        if (a.y > b.y) return 1;
        else return 0;
    }
    return 1;
}

int east_sort(cow a, cow b) {
    if (a.y > b.y) return 0;
    else if (a.y == b.y) {
        if (a.x > b.x) return 1;
        else return 0;
    }
    return 1;
}

int main() {
    int N;
    cin >> N;

    vector<cow> north{};
    vector<cow> east{};

    char direction;
    int x_ax, y_ax;
    for (int i = 0; i < N; i++) {
        cin >> direction >> x_ax >> y_ax;
        cow to_add;
        to_add.x = x_ax;
        to_add.y = y_ax;
        to_add.index = i;
        if (direction == 'E') east.push_back(to_add);
        else north.push_back(to_add);
    }

    sort(north.begin(), north.end(), north_sort);
    sort(east.begin(), east.end(), east_sort);

    vector<int> result (N, -1);


    for (int i = 0; i < east.size(); i++) {
        for (int j = 0; j < east.size(); j++) {
            if (j == i) continue;
            if (east[j].y == east[i].y && east[j].x > east[i].x) result[east[i].index] = east[j].x - east[i].x;
        }
        for (int j = 0; j < north.size(); j++) {
            if (result[north[j].index] != -1) continue;
            if (result[east[i].index] != -1 && north[j].x > east[i].x + result[east[i].index]) goto end;
            if (north[j].x < east[i].x) continue;
            if (north[j].y > east[i].y) continue;
            if (east[i].y - north[j].y < north[j].x - east[i].x) {
                int deb1 = north[j].x - east[i].x;
                result[east[i].index] = north[j].x - east[i].x;
                goto end;
            } else if (east[i].y - north[j].y > north[j].x - east[i].x) {
                int deb2 = east[i].y - north[j].y;
                result[north[j].index] = east[i].y - north[j].y;
            }
        }
        end:
        continue;
    }

    for (int i = 0; i < north.size(); i++) {
        for (int j = 0; j < north.size(); j++) {
            if (j == i) continue;
            if (north[j].x == north[i].x && north[j].y > north[i].y) {
                result[north[i].index] = min(result[north[i].index], north[j].y - north[i].y);
                if (result[north[i].index] == -1) result[north[i].index] = north[j].y - north[i].y;
            }
        }
    }

    for (int i = 0; i < result.size(); i++) {
        if (result[i] >= 0) {
            cout << result[i] << "\n";
        } else cout << "Infinity\n";
    }

    return 0;
}