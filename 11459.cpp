#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--){
        solve();
    }
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    map<int, int> ladderAndSnakes;
    vector<int> players(a, 1);
    for (int i = 0; i < b; ++i) {
        int st, en;
        cin >> st >> en;
        ladderAndSnakes[st] = en;
    }
    vector<int> moves(c);
    for (int i = 0; i < c; ++i) {
        cin >> moves[i];
    }
    for (int i = 0; i < c; ++i){
        int move = moves[i];
        players[i % a] = min(players[i % a] + move, 100);
        if (ladderAndSnakes.count(players[i % a])) {
            players[i % a] = ladderAndSnakes[players[i % a]];
        }
        if (players[i % a] >= 100) break;
    }
    for (int i = 0; i < a; ++i) {
        cout << "Position of player " << i + 1 << " is " << players[i] << ".\n";
    }
}
