#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define rep(i, n) for(int i=0;i<n;i++)
#define FOR(i, j, n) for(int i=j;i<n;i++)
#define IS_NEGATIVE(i) 0>i
#define BIG 2
#define MEDIUM 1
#define SMALL 0
#define DEBUG 0

using namespace std;

int N = 0;
int data[10][10];
int result[12][3];
int can_fill(int x, int y, int type);
int spoit(int x, int y, int type, int n, int v);

void print_data() {
    rep(i, 10) {
        rep(j, 10) {
            if(DEBUG) cout << data[i][j] << ",";
        }
        if(DEBUG) cout << endl;
    }
}

int dfs(int n) {
    if (n == N) {
        rep(i, 10) {
            rep(j, 10) {
                if (data[i][j]) {
                    return 0;
                }
            }
        }
        rep(i, N) cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;
        return 1;
    }

    rep(i, 10) {
        rep(j, 10) {
            if(!data[i][j]) continue;
            rep(type, 3) {
                if(!can_fill(j, i, type)) {
                    continue;
                }
                spoit(j, i, type, n, 1);
                if (dfs(n + 1)) {
                    return 1;
                }
                spoit(j, i, type, n, -1);
            }
            return 0;
        }
    }
    return 0;
}

int spoit(int x, int y, int type, int n, int v) {
    switch(type)
    {
        case BIG:
            data[y][x] -= v;
            data[y + 1][x - 1] -= v;
            data[y + 1][x] -= v;
            data[y + 1][x + 1] -= v;
            data[y + 2][x - 2] -= v;
            data[y + 2][x - 1] -= v;
            data[y + 2][x] -= v;
            data[y + 2][x + 1] -= v;
            data[y + 2][x + 2] -= v;
            data[y + 3][x - 1]-= v;
            data[y + 3][x]-= v;
            data[y + 3][x + 1]-= v;
            data[y + 4][x] -=v;
            if (v) {
                result[n][0] = x;
                result[n][1] = y + 2;
                result[n][2] = type + 1;
            }
            break;
        case MEDIUM:
            data[y][x] -= v;
            data[y][x + 1] -= v;
            data[y][x + 2] -= v;
            data[y + 1][x] -= v;
            data[y + 1][x + 1] -= v;
            data[y + 1][x + 2] -= v;
            data[y + 2][x] -= v;
            data[y + 2][x + 1] -= v;
            data[y + 2][x + 2] -= v;
            if (v) {
                result[n][0] = x + 1;
                result[n][1] = y + 1;
                result[n][2] = type + 1;
            }
            break;
        case SMALL:
            data[y][x] -= v;
            data[y + 1][x - 1] -= v;
            data[y + 1][x] -= v;
            data[y + 1][x + 1] -= v;
            data[y + 2][x] -= v;
            if (v) {
                result[n][0] = x;
                result[n][1] = y + 1;
                result[n][2] = type + 1;
            }
            break;
        default:
            break;
    }
    if (DEBUG) cout << "----------------------------" << endl;
    print_data();



    return 1;
}

int can_fill(int x, int y, int type) {
    switch(type)
    {
        case BIG:
            if (y < 0 || y > 5 || x < 2 || x > 7)
                return 0;

            if (!data[y][x]
                    || !data[y + 1][x - 1]
                    || !data[y + 1][x]
                    || !data[y + 1][x + 1]
                    || !data[y + 2][x - 2]
                    || !data[y + 2][x - 1]
                    || !data[y + 2][x]
                    || !data[y + 2][x + 1]
                    || !data[y + 2][x + 2]
                    || !data[y + 3][x - 1]
                    || !data[y + 3][x]
                    || !data[y + 3][x + 1]
                    || !data[y + 4][x]) {
                return 0;
            }
            return 1;
        case MEDIUM:
            if (y < 0 || y > 7 || x < 0 || x > 7)
                return 0;

            if (!data[y][x]
                    || !data[y][x + 1]
                    || !data[y][x + 2]
                    || !data[y + 1][x]
                    || !data[y + 1][x + 1]
                    || !data[y + 1][x + 2]
                    || !data[y + 2][x]
                    || !data[y + 2][x + 1]
                    || !data[y + 2][x + 2]) {
                return 0;
            }
            return 1;
        case SMALL:
            if (y < 0 || y > 7 || x < 1 || x > 8)
                return 0;

            if (!data[y][x]
                    || !data[y + 1][x - 1]
                    || !data[y + 1][x]
                    || !data[y + 1][x + 1]
                    || !data[y + 2][x]) {
                return 0;
            }
            return 1;
        default:
            break;
    }

    return 1;
}

int main() {
    cin >> N;
    rep(i, 10) rep(j, 10) cin >> data[i][j];
    dfs(0);
    return 0;
}

