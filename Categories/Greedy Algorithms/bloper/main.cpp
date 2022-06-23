#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<int> canSum (vector<int> vec, int diff, int to_delete) {
    if (diff < 0) return {-1};
    if (diff == 0) return {};
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == to_delete) {
            vec.erase(vec.begin()+i);
            break;
        }
    }
    for (int i = 0; i < vec.size(); i++) {
        vector<int> to_return = canSum(vec, diff-vec[i], vec[i]);
        if (to_return.size() == 0 || to_return[0] != -1) {
            to_return.push_back(vec[i]);
            return to_return;
        }
    }
    return {-1};
}

string negative(vector<int> &vec, int &S) {
    int sum = -1;
    for (int i = 1; i < vec.size(); i++) {
        sum += (vec[i]*(-1));
    }
    int diff = S - sum;
    double div = (double)diff / 2.0;
    if (div != (int)div) return "Impossible";
    unordered_map<int, bool> memo{};
    vector<int> result = canSum(vec, div, 0); // positives
    sort(result.begin(), result.end());
    string final = "1";
    if (result[0] == 1) result.erase(result.begin());
    if (result.size() > 1 && result[0] != -1) {
        for (int i = 1; i < vec.size(); i++) {
            if (result.size() > 0 && result[0] == vec[i]) {
                final += ("+" + to_string(vec[i]));
                result.erase(result.begin());
            } else {
                final += ("-" + to_string(vec[i]));
            }
        }
        return final;
    }
    else return "Impossible";
}

string positive(vector<int> &vec, int &S) {
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i];
    }
    int diff = sum - S;
    double div = (double)diff / 2.0;
    if (div != (int)div) return "Impossible";
    unordered_map<int, bool> memo{};
    vec.erase(vec.begin());
    vector<int> result = canSum(vec, div, 0); // negatives
    sort(result.begin(), result.end());
    string final = "1";
    if (result.size() > 1 && result[0] != -1) {
        for (int i = 0; i < vec.size(); i++) {
            if (result.size() > 0 && result[0] == vec[i]) {
                final += ("-" + to_string(vec[i]));
                result.erase(result.begin());
            } else {
                final += ("+" + to_string(vec[i]));
            }
        }
        return final;
    }
    else return "Impossible";
}

int main() {
    int N, S;
    scanf("%d%d", &N, &S);
    
    vector<int> vec;
    for (int i = 0; i < N; i++ ) {
        vec.push_back(i+1);
    }

    if (S < 0) {
        string output = negative(vec, S);
        printf("%s", output.c_str());
    } else {
        string output = positive(vec, S);
        printf("%s", output.c_str());
    }

    return 0;
}