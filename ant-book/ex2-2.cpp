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

void dfs(int x, int y, int N, int M, char** field);

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N,M;
  char** field;

  cin >> N;
  cin >> M;

  field = (char**)malloc(sizeof(char*)*N);

  char** head = field;

  for(int i = 0; i< N; i++){
      char* row = (char*)malloc(sizeof(char)*M);
      cin >> row;
      head[i] = row;
  }


  int res = 0;
  for(int i=0; i< N; i++){
      for(int j=0; j<M; j++){

          dfs(i,j,N,M,field);
          res++;
      }
  }

  return 0;
} 

void dfs(int x, int y, int N, int M, char** field){

    field[x][y] = '.';

    for(int dx = -1; dx < 2; dx++){
        for(int dy = -1; dy<2; dy++){
            int nx = x + dx;
            int ny = y + dy;

            if( 0 <= nx && nx < N && 0 <= ny && nx < M && field[nx][ny] == 'W'){
                dfs(nx, ny, N, M, field);
            }
        }
    }
}
