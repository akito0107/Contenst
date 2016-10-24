#include <iostream>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> P;

int n;
int fish[1000001];

int main() {
    cin >> n;

    priority_queue<P> pq;

    for(int i = 0; i < n; i++) {
        int a, v;
        cin >> a >> v;
        fish[a] += v;
        pq.push(P(fish[a], a * (-1)));
    }

    P p = pq.top();
    cout << p.second * (-1) << " " << p.first << endl;
    return 0;
}
