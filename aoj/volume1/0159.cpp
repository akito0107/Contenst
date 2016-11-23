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
int p[1001];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while (true) {
        double min = 1 << 21;
        int mini = 0;

        int n;
        cin >> n;
        if (!n) return 0;

        int h, w;
        REP(i, n) {
            cin >> p[i] >> h >> w;
            double hd = ((double) h ) / 100;
            double bmi = (double)w / (hd * hd);
            if (min > fabs(bmi - 22.0)) {
                min = fabs(bmi - 22.0);
                mini = i;
            } else if (min == fabs(bmi - 22.0)) {
                if (mini > i) {
                    mini = i;
                }
            }
        }
        cout << p[mini] << endl;
    }
    return 0;
}

