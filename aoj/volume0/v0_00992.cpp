#include <iostream>
#include <queue>
#include <map>

using namespace std;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0099
// AC

typedef pair<int, int> P;

int n, q;
int fish[1000001];

int main() {
    cin >> n >> q;

    priority_queue<P> pq;

    for(int i = 0; i < q; i++) {
        int a, v;
        cin >> a >> v;
        fish[a] += v;
        pq.push(P(fish[a], a * (-1)));

        while(!pq.empty()) {
            P p = pq.top();
            if (fish[p.second * (-1)] == p.first) {
                cout << p.second * (-1) << " " << p.first << endl;
                break;
            }
            pq.pop();
        }
    }

    return 0;
}
