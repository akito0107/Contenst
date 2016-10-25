#include <iostream>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> P;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0099
// AC

int n, q;
int* set;

int main() {
    cin >> n >> q;
    set = (int*)malloc(sizeof(int) * n);

    priority_queue<P> queue;

    for (int i = 0; i < q; i++) {
        int a, v;
        cin >> a >> v;
        set[a] += v;
        queue.push(P(set[a], a * (-1)));

        while(!queue.empty()) {
            P p = queue.top();
            p.second *= -1;
            if (p.first == set[p.second]) {
                cout << p.second << ' ' << p.first << endl;
                break;
            }
            queue.pop();
        }
    }

    return 0;
}

