#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class game {
    public:
        int p = 0, h = 0, s = 0;
};

int main() {
    ifstream in ("hps.in");
    ofstream out ("hps.out");

    int N; in >> N;
    vector<game> vec(N);

    for (int i = 0; i < N; i++) {
        if (i != 0) vec[i] = vec[i-1];
        char c; in >> c;
        if (c == 'P') vec[i].p++;
        else if (c == 'H') vec[i].h++;
        else vec[i].s++;
    }

    int max_result = 0;
    for (int i = 1; i < N; i++) {
        int result = 0;
        result = max(
            max(
                vec[i-1].p,
                vec[i-1].h
            ), max(
                vec[i-1].p,
                vec[i-1].s
            )
        );
        result += max(
            max(
                (vec[N-1].p - vec[i-1].p), 
                (vec[N-1].h - vec[i-1].h)
            ), max(
                (vec[N-1].p - vec[i-1].p),
                (vec[N-1].s - vec[i-1].s)
            )
        );
        max_result = max(max_result, result);
    }

    out << max_result << "\n";

    return 0;
}