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
vector<int> intersection[103];

int search() {
    int odd = 0;
    if (intersection[1].size() % 2 != 1 || intersection[2].size() % 2 != 1) {
        return 0;
    }
    FOR(i, 3, 103) {
        if (intersection[i].size() % 2 == 1) {
            return 0;
        }
    }
    return 1;
}

void init() {
    REP(i, 103) {
        intersection[i].clear();
        intersection[i].shrink_to_fit();
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    while(1) {
        int s, d;
        cin >> s >> d;
        if (cin.eof()) break;

        intersection[s].push_back(d);
        intersection[d].push_back(s);

        if (!s && !d) {
            if(search()) {
                cout << "OK" << endl;
            } else {
                cout << "NG" << endl;
            }
            init();
        }
    }

    return 0;
}
