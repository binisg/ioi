#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int front(vector<int> &vec, int &index) {
    int place;
    for (int i = index+1; i < vec.size(); i++) {
        if (vec[i] >= vec[index]) {
            place = i;
            break;
        }
    }

    int counter = 0;
    for (int i = index+1; i <= place; i++) {
        if (i < vec.size()-1 && vec[i] < vec[index]) {
            int k = i+1;
            while (k < vec.size() && vec[k] == vec[k-1]) k++;
            counter++;
            i = k-1;
        }
    }

    return counter;
}

int back(vector<int> &vec, int &index) {
    int place;
    for (int i = index-1; i >= 0; i--) {
        if (vec[i] <= vec[index]) {
            place = i;
            break;
        }
    }

    int counter = 0;
    for (int i = index-1; i >= place; i--) {
        if (i > 0 && vec[i] > vec[index]) {
            int k = i-1;
            while (k >= 0 && vec[k] == vec[k+1]) k--;
            counter++;
            i = k+1;
        }
    }

    return counter;
}

int main() {
    FILE *in = fopen("outofplace.in", "r");
    FILE *out = fopen("outofplace.out", "w");

    int N;
    fscanf(in, "%d", &N);

    vector<int> vec(N);

    for (int i = 0; i < N; i++) {
        fscanf(in, "%d", &vec[i]);
    }

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            if (vec[i+1] < vec[i]) {
                fprintf(out, "%d\n", front(vec, i));
                return 0;
            } else continue;
        } else if (i == N-1) {
            fprintf(out, "%d\n", back(vec, i));
            return 0;
        } else if (vec[i-1] > vec[i] && vec[i+1] > vec[i]) {
            if (vec[i+1] < vec[i-1]) continue;
            fprintf(out, "%d\n", back(vec, i));
            return 0;
        } else if (vec[i-1] < vec[i] && vec[i+1] < vec[i]) {
            if (vec[i+1] < vec[i-1]) continue;
            fprintf(out, "%d\n", front(vec, i));
            return 0;
        }
    }

    return 0;
}