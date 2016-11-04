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

Pair solve(int cnt, int idx, int used, int w) {
    Pair result(0, vector<int>());
    result.second.push_back(s[idx]);
    if (cnt == N) return result;
    if (dp[idx][used].first != INF) return dp[idx][used];
    result.first = INF;
    FOR(i, 1, N + 1) {
        if((used>>(i - 1))&1) {
            Pair tmp = solve(cnt + 1, i, used&~(1<<(i - 1)), w + v[i] * 20);
            tmp.first += abs(d[i] - d[idx]) / (2000.0 / (70 + w));
            if (result.first > tmp.first) {
                result = tmp;
            }
        }
    }
    result.second.insert(result.second.begin(), s[idx]);
    return dp[idx][used] = result;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    int init = (1<<15) - 1;
    FOR(i, 1, N + 1) cin >> s[i] >> d[i] >> v[i];
    FOR(i, 1, N + 1) {
        FOR(j, 1, 1<<15) {
            dp[i][j] = Pair(INF, vector<int>());
        }
    }
    Pair ans(INF, vector<int>());
    FOR(i, 1, N + 1) {
        Pair tmp = solve(1, i, init&~(1<<(i - 1)), v[i] * 20);
        if (ans.first > tmp.first) ans = tmp;
    }

    REP(i, N - 1) cout << ans.second[i] << " ";
    cout << ans.second[N - 1] << endl;

    return 0;
}
