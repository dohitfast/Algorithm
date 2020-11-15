#include <iostream>
#include <queue>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int test = 0; test < t; test++) {
		int n, m;
		cin >> n >> m;

		int a;
		queue < pair<int, int>> q;
		priority_queue<int> pq;

		for (int i = 0; i < n; i++) {
			cin >> a;
			q.push({ i, a });
			pq.push(a);
		}

		int cnt = 0;
		while (!q.empty()) {
			int idx = q.front().first;
			int val = q.front().second;
			q.pop();

			if (pq.top() == val) {
				pq.pop();
				cnt++;
				if (idx == m)
					break;
			}
			else
				q.push({ idx, val });
		}
		cout << cnt << "\n";
	}
	return 0;
}