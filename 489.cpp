#include <bits/stdc++.h>
using namespace std;

int main() {
    int r;
    while (cin >> r, r>-1) {
        cout << "Round " << r << "\n";
        set<char> st;
        string s;
        cin >> s;
        for (const auto &letter: s) {
            st.insert(letter);
        }
        int att = 7;
        string t;
        cin >> t;
        set<char> guesses;
        for (const auto &guess: t){
            att -= !st.count(guess) && !guesses.count(guess);
            guesses.insert(guess);
            st.erase(guess);
            if (!att || st.empty()) break;
        }
        if (st.empty()){
            cout << "You win.\n";
        } else if (!att){
            cout << "You lose.\n";
        } else {
            cout << "You chickened out.\n";
        }
    }
}
