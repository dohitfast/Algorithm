#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, w, l;
	cin >> n >> w >> l;

	int *truck = new int[n];
	for (int i = 0; i < n; i++) 
		cin >> truck[i];
	
	queue<int> q;
	int time = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		while (1) {
			if (q.size() == w) {
				sum -= q.front();
				q.pop();
			}
			if (sum + truck[i] <= l)
				break;
			q.push(0);
			time++;
		}
		q.push(truck[i]);
		sum += truck[i];
		time++;
	}

	time += w;
	cout << time;
	return 0;
}