#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int cnt(int num) {
	string s = to_string(num);
	int a = 0;

	for (int i = 0; i < s.size(); i++)
		if (s[i] == '9')
			a++;

	return a;
}

int main() {
	int n, m;
	cin >> n >> m;
	int row[500] = { 0, };
	int col[500] = { 0, };


	int total = 0;
	int max_value = 0;

	int num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> num;

			int a = cnt(num);
			total += a;
			row[i] += a;
			col[j] += a;
		}
	}

	for (int i = 0; i < n; i++) 
		max_value = max(max_value, row[i]);
	
	for (int i = 0; i < m; i++) 
		max_value = max(max_value, col[i]);
	
	cout << total - max_value;
	return 0;
}