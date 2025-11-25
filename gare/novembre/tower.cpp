#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N, S;
    cin >> N >> S;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];

    // prefix DP
    vector<vector<char>> pref(N+1, vector<char>(S+1, false));
    pref[0][0] = true;
    for (int i = 0; i < N; i++) {
        for (int h = 0; h <= S; h++) {
            if (pref[i][h]) {
                pref[i+1][h] = true;
                if (h + H[i] <= S) pref[i+1][h + H[i]] = true;
            }
        }
    }

    // suffix DP
    vector<vector<char>> suff(N+1, vector<char>(S+1, false));
    suff[N][0] = true;
    for (int i = N-1; i >= 0; i--) {
        for (int h = 0; h <= S; h++) {
            if (suff[i+1][h]) {
                suff[i][h] = true;
                if (h + H[i] <= S) suff[i][h + H[i]] = true;
            }
        }
    }

    // per ogni i verifichiamo se esiste una somma senza utilizzare i S = h + h2
    for (int i = 0; i < N; i++) {
        bool indispensable = true;
        for (int h = 0; h <= S; h++) {
            if (pref[i][h]) {
                int h2 = S - h;
                if (h2 >= 0 && suff[i+1][h2]) {
                    // trovato modo senza usare H[i]
                    indispensable = false;
                    break;
                }
            }
        }
        cout << (indispensable ? "YES" : "NO") << "\n";
    }

    return 0;
}