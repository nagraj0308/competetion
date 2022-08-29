#include <bits/stdc++.h>
#define INPUT_FILE "input_2022_second_hands.txt"
#define OUTPUT_FILE "output_2022_second_hands.txt"
using namespace std;

string result(int n, int k, vector<int> v) {
    int res = 1;
    if (n > (2 * k)) {
        res = 0;
    } else {
        sort(v.begin(), v.end());
        for (int i = 0; i < (n - 2); i++) {
            if (v[i] == v[i + 1] && v[i + 1] == v[i + 2]) {
                res = 0;
                break;
            }
        }
    }
    return res ? "YES" : "NO";
}

int main() {
    int t;
    vector<int> arr;
    vector<vector<vector<char>>> vol;
    ifstream infile(INPUT_FILE);
    ofstream outfile(OUTPUT_FILE);

    infile >> t;
    for (int i = 0; i < t; i++) {
        int n;
        int k;
        infile >> n >> k;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int d;
            infile >> d;
            v.push_back(d);
        }
        outfile << "Case #" << i + 1 << ": " << result(n, k, v) << endl;
    }
    return 0;
}
