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
#include <limits>
using namespace std;

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,a,b) for(int i=(a);i>(b);i--)
#define REP(i,n)  FOR(i,0,n)
#define INF 999999999.0

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//debug
//-------------------------------------------
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

//typedef
//-------------------------------------------
typedef long long ll;
typedef pair<double, vector<int>> Pair;

int s[16];
int d[16];
int v[16];
Pair dp[16][1<<15];
int N;

Pair solve(int idx, int used, int w) {
    Pair result(0, vector<int>());
    result.second.push_back(s[idx]);

    if (used == 0) return res;
    if(dp[idx][used].first != INF) return dp[idx][used];

    FOR(i, 1, N + 1) {
        if((used>>i)&1) {
            Pair tmp = solve(i, used&~(1<<(i - 1)), w + w[i] * 20);
            tmp.first += abs(d[i] - d[idx]) / (2000.0 / (70 + w));
            if (result.first > tmp.first) {
                res = tmp;
            }
        }
    }

    res.second.insert(res.second.begin(), s[idx]);
    return dp[idx][used] = res;
}

int dfs(int c, int n, int w, int m, int broked) {
    if (c == N) return m;

    int res = numeric_limits<int>::max();
    FOR(i, 1, N + 1) {
        if ((broked>>i) & 1) {
            int dist = n != 0 ? abs(d[n] - d[i]) : d[i];
            int weight = n != 0 ? v[n] * 20 : 0;
            int minutes = n != 0 ? dist / (2000 / (70 + w + weight)) : 0;
            res = min(res, dfs(c + 1, i, w + weight, m + minutes, broked&~(1<<i)));
        }
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    int init = (1<<15) - 1;
    FOR(i, 1, N + 1) cin >> s[i] >> d[i] >> v[i];
    memset(dp, -1, sizeof(dp));
    FOR(i, 1, N + 1) {
        dp[0][used&~(1<<(i - 1))] = Pair(0, vector<int>(1, i));
    }
    int res = dfs(0, 0, 0, 0, init);
    cout << res << endl;

    return 0;
}
