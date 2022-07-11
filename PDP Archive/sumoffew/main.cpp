#include <iostream>
#include <cstdio>
#include <unordered_set>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
    FILE *in = fopen("sumoffew.in", "r");
    FILE *out = fopen("sumoffew.out", "w");

    int N, K;
    fscanf(in, "%d%d", &N, &K);

    int arr[N];
    for (int i = 0; i < N; i++) {
        fscanf(in, "%d", &arr[i]);
    }

    int sum = 0, max_sum = 0, counter = 0;
    unordered_set<int> s;
    unordered_map<int, int> m;
    vector<int> d;

    for (int i = 0; i < N; i++) {
        if (!s.count(arr[i])) {
            if (counter + 1 <= K) {
                s.insert(arr[i]);
                d.push_back(arr[i]);
                sum += arr[i];
                m[arr[i]] = 1;
                counter++;
                max_sum = max(max_sum, sum);
            } else {
                for (int j = 0; j < i; j++) {
                    sum -= d[j];
                    m[d[j]]--;
                    if (m[d[j]] == 0) {
                        auto del = s.find(d[j]);
                        s.erase(del);
                        d.erase(d.begin(), d.begin()+j+1);
                        break;
                    }
                }
                s.insert(arr[i]);
                d.push_back(arr[i]);
                sum += arr[i];
                m[arr[i]] = 1;
                max_sum = max(max_sum, sum);
            }
        } else {
            sum += arr[i];
            d.push_back(arr[i]);
            m[arr[i]]++;
            max_sum = max(max_sum, sum);
        }
    }

    fprintf(out, "%d\n", max_sum);

    return 0;
}