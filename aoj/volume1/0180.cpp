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
#define VISITED 1
#define NOT_VISITED 0
#define INF (1<<21)

//typedef
//-------------------------------------------
typedef long long ll;
int g[101][101];
int visited[101];
int d[101];
int n, m;

int prim() {
    d[0] = 0;

    while(true) {
        int min = INF;
        int u = -1;
        REP(i, n) {
            if (visited[i] != VISITED && d[i] < min) {
                min = d[i];
                u = i;
            }
        }
        if (u < 0) break;

        visited[u] = VISITED;

        REP(v, n) {
            if (visited[v] != VISITED && g[u][v] != INF) {
                if (g[u][v] < d[v]) {
                    d[v] = g[u][v];
                }
            }
        }
    }
    int sum = 0;
    REP(i, n) sum += d[i];
    return sum;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    while(true) {
        cin >> n >> m;
        if (!n && !m) break;
        REP(i, n) {
            visited[i] = NOT_VISITED;
            d[i] = INF;
        }
        REP(i, 101) REP(j, 101) g[i][j] = INF;
        REP(i, m) {
            int s, d, c;
            cin >> s >> d >> c;
            g[s][d] = c;
            g[d][s] = c;
        }
        cout << prim() << endl;
    }

    return 0;
}
