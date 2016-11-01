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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    while(1) {
        cin >> n;
        if (!n) break;
        int c = 0;
        long long data[4001] = {0};
        REP(i, n) {
            int e;
            long long p, q;
            cin  >> e >> p >> q;

            if (data[e] < 1000000 && data[e] + p * q >= 1000000) {
                cout << e << endl;
                ++c;
            }
            data[e] += p * q;
        }
        if (!c) cout << "NA" << endl;
    }
    return 0;
}
