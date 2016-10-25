#include <iostream>
#include <string.h>
#define rep(i, n) for(int i=0;i<n;i++)
#define repr(i, n) for(int i=n;i>=0;i--)
#define FOR(i, j, n) for(int i=j;i<n;i++)
#define FORR(i, j, n) for(int i=j;i>=n;i--)
using namespace std;
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0097
//
int main() {
    int n, s;
    long long dp[11][1001];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    rep(k, 101) {
        FORR(i, 9, 0) {
            rep(j, 1001 - k) {
                dp[i + 1][j + k] += dp[i][j];
            }
        }
    }

    while (cin >> n >> s) {
        if (!n && !s) return 0;
        cout << dp[n][s] << endl;
    }
    return 0;
}


