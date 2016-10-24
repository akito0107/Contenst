#include <iostream>
#include <sstream>
#include <algorithm>
#define rep(i, n) for(int i=0;i<n;i++)
#define FOR(i, j, n) for(int i=j;i<n;i++)
#define N 2001

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0096
int memo[N];
int main() {

    for (int i = 0; i < N; i++) {
        if (i <= 1000) {
            memo[i] = i + 1;
            continue;
        }
    }
    int n = 0;
    while(std::cin >> n) {
        int result = 0;
        for(int i = 0; i <= n; i++) {
            result += memo[i] * memo[n - i];
        }
        std::cout << result << std::endl;
    }
}

