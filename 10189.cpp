#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<pair<int, int>> eightDir = {
            {0,  -1},
            {-1, 0},
            {0,  1},
            {1,  0},
            {1,  1},
            {-1, -1},
            {1,  -1},
            {-1, 1}
    };
    int n, m;
    int test = 1;
    while (cin >> n >> m, n || m) {
        if (test > 1) cout << "\n";
        vector<vector<char>> field(n + 2, vector<char>(m + 2));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> field[i][j];
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (field[i][j] == '*') continue;
                field[i][j] = '0';
                for (int k = 0; k < 8; ++k) {
                    field[i][j] += field[i + eightDir[k].first][j + eightDir[k].second] == '*';
                }
            }
        }
        cout << "Field #" << test++ << ":\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cout << field[i][j];
            }
            cout << "\n";
        }
    }
}
