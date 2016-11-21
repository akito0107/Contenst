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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;

    while(cin >> n >> m && n && m) {
        vector<char> passengers;
        char* seat = (char*) malloc(sizeof(char));
        REP(i, m) seat[i] = '#';
        REP(i, m) {
            char c;
            cin >> c;
            passengers.push_back(c);
        }

        REP(i, passengers.size()) {
            char p = passengers[i];
            if (p == 'A') {
                REP(j, m) if (seat[j] == '#') {
                    seat[j] = 'A';
                    break;
                }
            } else if ( p == 'B') {
                FORR(j, m - 1, -1) {
                    if (seat[j] == '#') {
                        if ((j == 0 || seat[j - 1] != 'A') && (j == m - 1 || seat[j + 1] != 'A')) {
                            seat[j] = 'B';
                            break;
                        }
                    }
                }
                REP(j, m) if (seat[j] == '#') {
                    seat[j] = 'B';
                    break;
                }
            } else if ( p == 'C') {

            } else if ( p == 'D') {

            }
        }

        cout << seat << endl;
    }

    return 0;
}
