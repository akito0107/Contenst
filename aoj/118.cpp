#include <iostream>
using namespace std;

void dfs(int H, int W, char** field, int x, int y, char s);
void print_field(char** field, int H);

int main() {
  int H,W;
  char** field;

  cin >> H >> W;

  field =(char**) malloc(sizeof(char*)*H);

  for(int i=0; i<H;i++){
      char* row = (char*)malloc(sizeof(char)*W);
      cin >> row;
      field[i] = row;
  }

  int zero, zero1;
  cin >> zero  >> zero1;
  

  int result = 0;

  for(int i=0; i < H; i++){
      for(int j=0; j < W; j++){

          if(field[i][j] == '#' || field[i][j] == '*' || field[i][j]=='@'){
              dfs(H, W, field, j, i, field[i][j]);
              result++;
          }
      }
      //print_field(field, H);
  }

  cout << result << endl;

  return 0;
}

void dfs(int H, int W, char** field, int x, int y, char s){

    field[y][x] = '0';

    int pattern[4][2]= { {-1,0}, {1,0}, {0,-1}, {0,1}};

    for(int i = 0; i<4; i++){
    
        int nx = x + pattern[i][0];
        int ny = y + pattern[i][1];
       
        if(0<=nx && nx < W && 0<=ny && ny < H && field[ny][nx]==s){
            dfs(H,W,field,nx,ny,s);
        }
    }
}

void print_field(char** field, int H){

    for(int i=0; i<H; i++){
        cout << field[i] << endl;
    }
    cout << "-----------------" << endl;
}
