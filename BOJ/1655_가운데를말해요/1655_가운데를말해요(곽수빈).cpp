#include<iostream>
#include<queue>
#include <algorithm>
#include<functional>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	priority_queue< int, vector<int>> big;
	priority_queue< int, vector<int>, greater<int>> small;

	int a;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		
		if (big.size() > small.size())
			small.push(a);
		else
			big.push(a);

		if (!big.empty() && !small.empty() && (big.top() > small.top())) {
			int top1 = big.top();
			int top2 = small.top();
			big.pop();
			small.pop();
			big.push(top2);
			small.push(top1);
		}

		cout << big.top() << "\n";
	}
	return 0;
}