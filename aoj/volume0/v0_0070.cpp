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
#include <iterator>
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
int N = 0;
int memo[10][1 << 10][331];
int dfs(int used, int sum, int n) {
    if (sum < 0) return 0;
    if (n == N) return sum == 0;

    if (~memo[n][used][sum]) return memo[n][used][sum];

    int res = 0;

    for (int i = 0; i < 10; i++) {
        if ((used >> i) & 1) {
            res += dfs(used&~(1 << i), sum - ((1 + n) * i), n + 1);
        }
    }
    memo[n][used][sum] = res;
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, s;
    while(1) {
        cin >> n >> s;
        if (cin.eof()) break;
        N = n;
        memset(memo, -1, sizeof(memo));
        cout << dfs((1 << 10) - 1, s, 0) << endl;
    }
    return 0;
}
