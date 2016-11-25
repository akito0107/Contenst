//include
//------------------------------------------
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,a,b) for(int i=(a);i>(b);i--)
#define REP(i,n)  FOR(i,0,n)

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//debug
//-------------------------------------------
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

#define INF (1<<21)
#define RETURNED 2
#define VISITED 1
#define NOT_VISITED 0

//typedef
//-------------------------------------------
typedef long long ll;

int g[10][10];
int visited[10];
vector<int> result;

int s, d;

int dfs(int now, int parent, int cost) {
    visited[now] += 1;
    if (now == d) return cost;

    int test = 0;
    int tmp = INF;
    int mini = -1;
    REP(i, 10) {
        if(g[now][i] != INF && visited[i] != 2) {
            if (parent == 9 && now == 5 && i == 6) continue;
            int r = dfs(i, now, cost + 1);
            if (tmp > r) {
                tmp = r;
                mini = i;
            }
        }
    }
    if (mini > -1) result.push_back(mini);

    return tmp;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    REP(i, 10) REP(j, 10) g[i][j] = INF;
    g[0][1] = 1, g[1][0] = 1;
    g[1][2] = 1, g[2][1] = 1;
    g[2][3] = 1, g[3][2] = 1;
    g[3][4] = 1, g[4][3] = 1;
    g[4][5] = 1, g[5][4] = 1;
    g[5][6] = 1, g[6][7] = 1, g[7][8] = 1, g[8][9] = 1, g[9][5] = 1;

    int n;
    cin >> n;
    REP(j, n) {
        REP(i, 10) visited[i] = NOT_VISITED;
        if (!n) return 0;
        cin >> s >> d;
        result.clear();
        dfs(s, -1, 0);
        reverse(result.begin(), result.end());
        cout << s << " ";
        for (int i = 0; i < result.size() - 1; i++) {
            cout << result[i] << " ";
        }
        cout << result[result.size() - 1] << endl;
    }
    return 0;
}

