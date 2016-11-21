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
#define dump(x)  cerr << #x << " = " << (x) << ;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << ;

//typedef
//-------------------------------------------
typedef long long ll;

void print_dist(double d) {
    if ( 11.25 <= d && d < 33.75) {
        cout << "NNE"  ;
        return;
    } else if (33.75 <= d && d < 56.25) {
        cout << "NE"  ;
        return;
    }else if (56.25 <= d && d < 78.75) {
        cout << "ENE" ;
        return;
    }else if (78.75 <= d && d < 101.25) {
        cout << "E"  ;
        return;
    }else if (101.25 <= d && d < 123.75) {
        cout << "ESE"  ;
        return;
    }else if (123.75 <= d && d < 146.25) {
        cout << "SE"  ;
        return;
    }else if (146.25 <= d && d < 168.75) {
        cout << "SSE"  ;
        return;
    }else if (168.75 <= d && d < 191.25) {
        cout << "S"  ;
        return;
    }else if (191.25 <= d && d < 213.75) {
        cout << "SSW"  ;
        return;
    }else if (213.75 <= d && d < 236.25) {
        cout << "SW"  ;
        return;
    }else if (236.25 <= d && d < 258.75) {
        cout << "WSW" ;
        return;
    }else if (258.75 <= d && d < 281.25) {
        cout << "W" ;
        return;
    }else if (281.25 <= d && d < 303.75) {
        cout << "WNW";
        return;
    }else if (303.75 <= d && d < 326.25) {
        cout << "NW" ;
        return;
    }else if (326.25 <= d && d < 348.75) {
        cout << "NNW";
        return;
    }
    cout << "N";
}

int print_wind(double w) {
    if (0.0 <= w && w <= 0.2) {
        return 0;
    } else if (0.3 <= w && w <= 1.5) {
        return 1;
    }else if (1.6 <= w && w <= 3.3) {
        return 2;
    }else if (3.4 <= w && w <= 5.4) {
        return 3;
    }else if (5.5 <= w && w <= 7.9) {
        return 4;
    }else if (8.0 <= w && w <= 10.7) {
        return 5;
    }else if (10.8 <= w && w <= 13.8) {
        return 6;
    }else if (13.9 <= w && w <= 17.1) {
        return 7;
    }else if (17.2 <= w && w <= 20.7) {
        return 8;
    }else if (20.8 <= w && w <= 24.4) {
        return 9;
    }else if (24.5 <= w && w <= 28.4) {
        return 10;
    }else if (28.5 <= w && w <= 32.6) {
        return 11;
    }else if (32.7 <= w) {
        return 12;
    }
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int d, w;
    cin >> d >> w;
    if (w == 0) {
        cout << "C" << " " << 0 << endl;
        return 0;
    }


    double wd = (double)w / 60;
    wd = (round(wd * 10)) / 10;
    w = print_wind(wd);

    if (w == 0) {
        cout << "C" << " " << 0 << endl;
        return 0;
    }

    d = round((double)d / 100) * 100;
    print_dist(d/10);
    cout << " ";
    cout << w << endl;

    return 0;
}
