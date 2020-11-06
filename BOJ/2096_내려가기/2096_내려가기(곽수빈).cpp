#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	int max_num[2][3];
	int min_num[2][3];

	cin >> max_num[0][0] >> max_num[0][1] >> max_num[0][2];
	min_num[0][0] = max_num[0][0];
	min_num[0][1] = max_num[0][1];
	min_num[0][2] = max_num[0][2];

	int a, b, c;
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;

		max_num[1][0] = max(max_num[0][0], max_num[0][1]) + a;
		max_num[1][1] = max(max(max_num[0][1], max_num[0][2]), max_num[0][0]) + b;
		max_num[1][2] = max(max_num[0][1], max_num[0][2]) + c;

		min_num[1][0] = min(min_num[0][0], min_num[0][1]) + a;
		min_num[1][1] = min(min(min_num[0][1], min_num[0][2]), min_num[0][0]) + b;
		min_num[1][2] = min(min_num[0][1], min_num[0][2]) + c;

		max_num[0][0] = max_num[1][0];
		max_num[0][1] = max_num[1][1];
		max_num[0][2] = max_num[1][2];

		min_num[0][0] = min_num[1][0];
		min_num[0][1] = min_num[1][1];
		min_num[0][2] = min_num[1][2];
	}

	cout << max(max_num[0][0], max(max_num[0][1], max_num[0][2])) << " " << min(min_num[0][0], min(min_num[0][1], min_num[0][2]));
	return 0;
}