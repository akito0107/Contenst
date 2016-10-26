#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#define rep(i, n) for(int i=0;i<n;i++)
#define FOR(i, j, n) for(int i=j;i<n;i++)
#define FORE(i, j, n) for(int i=j;i<=n;i++)

int N;
int data[101][101];
long long buf[101][101];

using namespace std;

long search() {
    buf[1][1] = data[1][1];
    long long max = data[1][1];

    FOR(i, 2, N) {
        buf[1][i] = buf[1][i - 1] + data[1][i];
        buf[i][1] = buf[i - 1][1] + data[i][1];
    }

    FOR(i, 2, N) FOR(j, 2, N) buf[i][j] = data[i][j] + buf[i - 1][j] + buf[i][j - 1] - buf[i - 1][j - 1];

    FOR(i, 1, N) {
        FOR(j, 1, N) {
            FOR(k, i, N) {
                FOR(l, j, N) {
                    long long t = buf[k][l] + buf[i - 1][j - 1] - buf[i - 1][l] - buf[k][j - 1];
                    if (max < t) max = t;
                }
            }
        }
    }

    return max;
}

int main() {
    std::cin >> N;
    N += 1;
    memset(data, 0, sizeof(data));
    memset(buf, 0, sizeof(buf));
    FOR(i, 1, N) FOR(j, 1, N) std::cin >> data[i][j];
    std::cout << search() << std::endl;

    return 0;
}

