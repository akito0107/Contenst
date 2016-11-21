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

//typedef
//-------------------------------------------
typedef long long ll;

int memo[10001];
int isprime(int x) {
    if (x < 0 ) return 0;
    if (x == 2) return 1;
    if (x % 2 == 0) return 0;

    int l = (int)sqrt(x);
    for (int i = 3; i <= l; i += 2) {
        if (x % i == 0) return 0;
    }

    return 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int m;
    while(1) {
        cin >> m;
        if (m == 0) break;
        FORR(j, m, 0) {
            if (isprime(j) && isprime(j - 2)) {
                cout << j - 2 << " " << j << endl;
                break;
            }
        }
    }

    return 0;
}
