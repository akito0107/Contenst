#include <iostream>
#define rep(i, n) for(int i=0;i<n;i++)
#define FOR(i, j, n) for(int i=j;i<n;i++)
using namespace std;
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0096
//
int main() {
    int n;

    long long dp[4][4001] = {};
    rep(i, 1001) dp[0][i] = 1;

    for (int i = 1; i < 4; i++) {
        for (int j = 4000; j >= 0; j--) {
            for (int k = 0; k <= 1000; k++) {
                if (j - k < 0) break;
                dp[i][j] += dp[i - 1][j - k];
            }
        }
    }

    while(1) {
        cin >> n;
        if (cin.eof()) break;
        cout << dp[3][n] << endl;
    }
    return 0;
}


