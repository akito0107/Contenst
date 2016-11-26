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

#define INF (1<<21)

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

//typedef
//-------------------------------------------
typedef long long ll;

int g[21][21];
int visited[21];
int d[21];
int n;

int dijkstra(int start) {
    d[start] = 0;

    while(1) {
        int u = -1;
        int tmpd = INF;
        REP(i, n + 1) {
            if (visited[i] == NOT_VISITED) {
                if (tmpd > d[i]) {
                    u = i;
                    tmpd = d[i];
                }
            }
        }
        if (u < 0) break;
        visited[u] = VISITED;

        REP(i, n + 1) {
            if (g[u][i] != INF && visited[i] == NOT_VISITED) {
               if ((d[u] + g[u][i]) < d[i]) {
                   d[i] = d[u] + g[u][i];
               }
            }
        }
    }
    return 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    REP(i, 21) REP(j, 21) g[i][j] = INF;
    int m;
    cin >> n;
    cin >> m;
    REP(i, m) {
        string str;
        cin >> str;
        stringstream ss(str);
        string buf;
        vector<int> tmp;
        while (getline(ss, buf, ',')) {
            tmp.push_back(stoi(buf));
        }
        int a = tmp[0];
        int b = tmp[1];
        int c = tmp[2];
        int d = tmp[3];

        g[a][b] = c;
        g[b][a] = d;
    }

    string str;
    cin >> str;
    stringstream ss(str);
    string buf;
    vector<int> tmp;
    while (getline(ss, buf, ',')) {
        tmp.push_back(stoi(buf));
    }
    int s = tmp[0];
    int goal = tmp[1];
    int v = tmp[2];
    int p = tmp[3];

    REP(i, 21) visited[i] = NOT_VISITED;
    REP(i, 21) d[i] = INF;
    dijkstra(s);
    int up = d[goal];

    REP(i, 21) visited[i] = NOT_VISITED;
    REP(i, 21) d[i] = INF;
    dijkstra(goal);
    int down = d[s];

    cout << v - p - (up + down) << endl;

    return 0;
}
