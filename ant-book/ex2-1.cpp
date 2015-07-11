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
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//debug
//-------------------------------------------
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;


bool dfs(int n, int k, int* a, int i, int sum);

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  int* a;
  int k;

  cin >> n;

  a = (int*)malloc(sizeof(int)*n);

  for(int i = 0; i< n; i++){
      cin >> a[i];
  }

  cin >> k;

  bool result = dfs(n, k, a, 0,0);

  if(result){
      cout << "Yes" << endl;
  }else{
      cout << "NO" << endl;
  }

  return 0;
}

bool dfs(int n, int k, int* a, int i, int sum){

    if(i==n) return sum==k;

    if(dfs(n, k, a, i+1, sum + a[i])) return true;

    if(dfs(n, k, a, i+1, sum)) return true;

    return false;
} 
