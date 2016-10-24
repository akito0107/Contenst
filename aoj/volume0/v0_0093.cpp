#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define rep(i, n) for(int i=0;i<n;i++)
using namespace std;

int main() {
    int start = 0, end = 0;
    cin >> start >> end;
    while(1) {
        bool flag = false;
        for(int i = start; i <= end; i++) {
            if (i % 4  == 0 && (i % 100 != 0 || i % 400 == 0)) {
                flag = true;
                cout << i << endl;
            }
        }
        if (!flag) {
            cout << "NA" << endl;
        }
        cin >> start >> end;
        if (!start && !end) return 0;
        cout << endl;
    }
}
