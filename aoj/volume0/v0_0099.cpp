#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0099
// AC

int find_max(int* arr, int size) {
    int max = -1;
    for (int i = 0; i < size; i++) {
        if (arr[max] < arr[i]) {
            max = i;
        }
    }
    return max;
}

int main() {
    int n, q;
    cin >> n >> q;
    int* m = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        m[i] = 0;

    int max = -1;
    for (int i = 0; i < q; i++) {
        int a, v;
        cin >> a >> v;
        m[a - 1] += v;

        if (v > 0) {
            if (m[max] < m[a - 1]) {
                max = a - 1;
            } else if (m[max] == m[a-1]) {
                for (int j = 0; j < n; j++) {
                    if (m[max] == m[j]) {
                        max = j;
                        break;
                    }
                }
            }
        } else {
            max = find_max(m, n);
        }

        cout << max + 1 << " " << m[max] << endl;
    }
    return 0;
}

