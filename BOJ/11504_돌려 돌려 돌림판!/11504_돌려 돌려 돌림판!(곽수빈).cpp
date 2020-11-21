#include <iostream>

using namespace std;

int main() {
	int test_case;
	cin >> test_case;

	for (int i = 0; i < test_case; i++) {
		int n, m;
		cin >> n >> m;
		
		int x[9];
		int y[9];
		int *arr = new int[n + 1];

		for (int j = 0; j < m; j++)
			cin >> x[j];

		for (int j = 0; j < m; j++)
			cin >> y[j];

		for (int j = 0; j < n; j++)
			cin >> arr[j];

		int a = 0;
		int b = 0;
		int idx = 1;
		for (int j = 0; j < m; j++) {
			a += x[m - j - 1] * idx;
			b += y[m - j - 1] * idx;
			idx *= 10;
		}

		int answer = 0;
		for (int j = 0; j < n; j++) {
			int temp = idx / 10;
			int sum = 0;
			for (int k = 0; k < m; k++) {
				sum += arr[(j + k) % n] * temp;
				temp /= 10;
			}
			if (a <= sum && b >= sum)
				answer++;
		}
		cout << answer << "\n";
	}
	return 0;
}