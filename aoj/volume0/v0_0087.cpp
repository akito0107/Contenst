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

//debug
//-------------------------------------------
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

stack<double> st;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    while(getline(cin, s)) {
        vector<string> str = split(s, ' ');

        for(auto const& v: str){
            if (v == "+") {
                double a = st.top();
                st.pop();
                double b = st.top();
                st.pop();
                st.push(a + b);
                continue;
            } else if (v == "-") {
                double a = st.top();
                st.pop();
                double b = st.top();
                st.pop();
                st.push(b - a);
                continue;
            } else if (v == "/") {
                double a = st.top();
                st.pop();
                double b = st.top();
                st.pop();
                st.push(b / a);
                continue;
            } else if (v == "*") {
                double a = st.top();
                st.pop();
                double b = st.top();
                st.pop();
                st.push(a * b);
                continue;
            }
            st.push(toDouble(v));
        }

        printf("%.6f\n", st.top());
        st.pop();
    }

    return 0;
}
