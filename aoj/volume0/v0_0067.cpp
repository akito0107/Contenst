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

int island[12][12] = {0};

void dfs(int i, int j) {
    island[i][j] = 0;

    if (i > 0 && island[i - 1][j]) {
        dfs(i - 1, j);
    }
    if (i < 11 && island[i + 1][j]) {
        dfs(i + 1, j);
    }
    if (j < 11 && island[i][j + 1]) {
        dfs(i, j + 1);
    }
    if (j > 0 && island[i][j - 1]) {
        dfs(i, j - 1);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    while(1) {
        memset(island, 0, sizeof(island));
        if (cin.eof()) break;
        REP(i, 12) {
            string line;
            if (!(cin >> line)) {
                break;
            }
            REP(j, 12) island[i][j] = line[j] - '0';
        }

        int cnt = 0;
        REP(i, 12) REP(j, 12) {
            if (island[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
