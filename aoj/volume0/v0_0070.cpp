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

void print_arr(int arr[10]) {
    cout << "----------------------------" << endl;
    REP(i, 10) cout << arr[i] << ", ";
    cout << endl;
}

//debug
//-------------------------------------------
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
int N = 0;
int S = 0;
int result = 0;
int memo[1 << 10][332][11];
int dfs(int used, int sum, int n) {
    if (sum < 0) return 0;
    if (n == N + 1) return sum == 0;

    if (memo[used][sum][n] >= 0) {
        return memo[used][sum][n];
    }
    int res = 0;

    for (int i = 0; i < 10; i++) {
        if ((used >> i) & 1) {
            res += dfs(used&~(1 << i), sum - n * i, n + 1);
        }
    }
    memo[used][sum][n] = res;
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    memset(memo, -1, sizeof(memo));
    int n, s;
    while(1) {
        cin >> n >> s;
        if (cin.eof()) break;
        N = n;
        if (s >= 331) {
            cout << 0 << endl;
            continue;
        }
        cout << dfs((1 << 10) - 1, s, 1) << endl;
    }
    return 0;
}
