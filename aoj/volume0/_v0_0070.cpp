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
inline double toDouble(string s) {double v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
vector<string> split(const string &s, char delim) {
    vector<string> elems;
    string item;
    for (char ch: s) {
        if (ch == delim) {
            if (!item.empty())
                elems.push_back(item);
            item.clear();
        }
        else {
            item += ch;
        }
    }
    if (!item.empty())
        elems.push_back(item);
    return elems;
}

int dp[11][10001];
void dump_arr(int n, int m) {
    REP(i, n) {
        REP(j, m) cout << dp[i][j] << ",";
        cout << endl;
    }
    cout << "----------------------" << endl;
}

//debug
//-------------------------------------------
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int s, n;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(1) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        dp[1][0] = 1;
        cin >> n >> s;
        REP(k, 10) {
            FORR(i, n + 1, 0) {
                FOR(j, 0, s + 1) {
                    if (j >= k * i)
                        dp[i][j] += dp[i - 1][j - k * i];
                }
            }
            dump_arr(n + 1, s + 1);
        }
        cout << dp[n][s] << endl;
    }

    return 0;
}
