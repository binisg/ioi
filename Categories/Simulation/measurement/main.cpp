#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    FILE *in = fopen("measurement.in", "r");
    FILE *out = fopen("measurement.out", "w");

    int N;
    fscanf(in, "%d", &N);

    unordered_map<string, int> cows;
    cows["Bessie"] = 7;
    cows["Elsie"] = 7;
    cows["Mildred"] = 7;

    int max_milk = 7;
    vector<string> max_cows = {"Bessie", "Elsie", "Mildred"};
    int changes = 0;

    vector<tuple<int, string, int>> input (N);

    for (int i = 0; i < N; i++) {
        int day, num;
        char cow[100];
        fscanf(in, "%d%s%d", &day, &cow, &num);
        tuple<int, string, int> current = {day, cow, num};
        input[i] = current;
    }

    sort(input.begin(), input.end());

    for (int i = 0; i < input.size(); i++) {
        bool changed = false;
        auto t = input[i];
        cows[get<1>(t)] += get<2>(t);
        max_milk = 0;
        max_milk = max(max_milk, max(max(cows["Bessie"], cows["Elsie"]), max(cows["Elsie"], cows["Mildred"])));
        
        for (int j = 0; j < max_cows.size(); j++) {
            if (cows[max_cows[j]] < max_milk) {
                max_cows.erase(max_cows.begin()+j);
                changed = true;
                j--;
            }
        }

        if (cows["Bessie"] == max_milk) {
            bool found = false;
            for (int p = 0; p < max_cows.size(); p++) {
                if (max_cows[p] == "Bessie") found = true;
            }
            if (!found) {
                max_cows.push_back("Bessie");
                changed = true;
            }
        } 
        
        if (cows["Elsie"] == max_milk) {
            bool found = false;
            for (int p = 0; p < max_cows.size(); p++) {
                if (max_cows[p] == "Elsie") found = true;
            }
            if (!found) {
                max_cows.push_back("Elsie");
                changed = true;
            }
        } 

        if (cows["Mildred"] == max_milk) {
            bool found = false;
            for (int p = 0; p < max_cows.size(); p++) {
                if (max_cows[p] == "Mildred") found = true;
            }
            if (!found) {
                max_cows.push_back("Mildred");
                changed = true;
            }
        }

        if (changed) changes++;
    }

    fprintf(out, "%d", changes);

    fclose(in);
    fclose(out);
    return 0;
}