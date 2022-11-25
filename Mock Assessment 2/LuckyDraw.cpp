
#include <bits/stdc++.h>
using namespace std;

class LuckyDraw {
public:
    int luckyDraw(vector<int>& tokens, int x) {
        sort(tokens.begin(),tokens.end());
        return tokens[x-1];
    }
};

int main() {
    int n, x;
    cin >> n;
    vector<int> tokens(n);
    for ( int i = 0; i < n; i++) {
        cin >> tokens[i];
    }
    cin >> x;
    int result = LuckyDraw().luckyDraw(tokens, x);
    cout << result;
    return 0;
}
