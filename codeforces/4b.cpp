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

//typedef
//-------------------------------------------
typedef long long ll;
int d, sumTime;
typedef pair<int, int> day;
day days[31];
vector<int> result;

int dfs(int cnt, int sum) {
    if (d == cnt) {
        if (sum == 0 ) {
            return 1;
        } else {
            return 0;
        }
    }

    if (sum < 0) return 0;

    int minTime = days[cnt].first;
    int maxTime = days[cnt].second;

    int res = 0;
    for (int i = minTime; i <= maxTime; i++) {
        int tmp = 0;
        tmp = dfs(cnt + 1, sum - i);
        if (tmp != 0) {
            result.push_back(i);
            res += 1;
        }
    }

    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> d >> sumTime;

    FOR(i, 0, d) {
        int minTime, maxTime;
        cin >> minTime >> maxTime;
        days[i] = day(minTime, maxTime);
    }
    int s = dfs(0, sumTime);

    if (s) {
        cout << "YES" << endl;
        reverse(result.begin(), result.end());

        REP(i, d - 1) cout << result[i] << " ";
        cout << result[d - 1] << endl;

    } else {
        cout << "NO" << endl;
    }

    return 0;
}
