#include <iostream>
#include <queue>
#include <map>
#define rep(i, n) for(int i=0;i<n;i++)

using namespace std;

int dfs() {
}

int main() {
    int n = 0;
    cin >> n;
    double seals[100][100];
    memset(seals, -1, sizeof(seals));

    for (int i = 0; i < n; i++)
        cin >> seals[i][0] >> seals[i][1];

    int results = 1;

    rep(i, n) {
        for (int j = i + 1; j < n; j++) {
        }
    }

    return 0;
}
