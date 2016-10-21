#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#define rep(i, n) for(int i=0;i<n;i++)
#define FOR(i, j, n) for(int i=j;i<n;i++)

int N;
char data[1000][1000];
int dp[1000][1000];

int search() {
    int max = 0;
    FOR(i, 1, N) {
        FOR(j, 1, N) {
            if(data[i][j] == '*') {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = std::min({dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j]}) + 1;
            max = dp[i][j] > max ? dp[i][j] : max;
        }
    }
    return max;
}

int main() {
    while(1) {
        std::cin >> N;
        if (N == 0) return 0;
        memset(dp, 0, sizeof(dp));
        rep(i, N) {
            rep(j, N) std::cin >> data[i][j];
            dp[i][0] = data[i][0] == '.' ? 1 : 0;
            dp[0][i] = data[0][i] == '.' ? 1 : 0;
        }

        std::cout << search() << std::endl;
    }

    return 0;
}

