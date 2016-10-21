#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define rep(i, n) for(int i=0;i<n;i++)
#define FOR(i, j, n) for(int i=j;i<n;i++)
#define LEVEL 0

using namespace std;

int N;
char** data;
int** dp;

int search() {

    rep(i, N) {
        rep(j, N) {
        }
    }
   
    return 1;
}


int main() {
    while(1) {
        cin >> N;
        if (N == 0) return 0;
        data = (char**)malloc(sizeof(char*) * N);
        rep(i, N) data[i] = (char*)malloc(sizeof(char) * N);
        dp = (int**)malloc(sizeof(int*) * N);
        rep(i, N) dp[i] = (int*)malloc(sizeof(int) * N);

        rep(i, N) rep(j, N) cin >> data[i][j];
        search();
        cout << dp[N - 1][N - 1] << endl;
        free(data);
        free(dp);
    }

    return 0;
}


/**
int N = 0;
char** data;
int result = 0;
int search(int x, int y);

int next_search(int x, int y) {
    int next_x, next_y = 0;
    if (x == N - 1) {
        if (y == N - 1) return 0;

        return search(0, y + 1);
    }

    return search(x + 1, y);
}

int search(int x, int y) {
    if (x + result >= N) return next_search(x, y);
    if (y + result >= N) return 0;
    if (data[x][y] == '*') return next_search(x, y);

    result = result == 0 ? 1 : result;

   for (int i = 1; i <= N - x; i++) {

        if (y + i > N)
            return next_search(x, y);

        FOR(k, x, x + i) {
            FOR(l, y,  y + i) {
                if(data[k][l] == '.') {
                    continue;
                }
                return next_search(x, y);
            }
        }
        result = result < i ? i : result;
    }

    return next_search(x, y);
}


int main() {
    while(1) {
        cin >> N;
        if (N == 0) return 0;
        data = (char**)malloc(sizeof(char*) * N);
        rep(i, N) data[i] = (char*)malloc(sizeof(char) * N);
        rep(i, N) rep(j, N) cin >> data[i][j];
        search(0, 0);
        cout << result << endl;
        result = 0;
        free(data);
    }

    return 0;
}


**/
