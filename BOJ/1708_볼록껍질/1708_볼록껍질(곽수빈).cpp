#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &p1, vector<int> &p2) {
	if (p1[0] == p2[0]) return p1[1] < p2[1];
	return p1[0] < p2[0];
}

vector<int> inclination(vector<int> &p1, vector<int> &p2) {
	vector<int> v(2);
	v[0] = p2[0] - p1[0];
	v[1] = p2[1] - p1[1];
	return v;
}

bool ccw(vector<int> &p1, vector<int> &p2, vector<int> &p3) {
	vector<int> v = inclination(p1, p2), u = inclination(p2, p3);
	if ((long long)v[0] * u[1] > (long long)v[1] * u[0])
		return true;
	return false;
}


int convex(vector<vector<int>> &positions) {
	vector<vector<int> > convex;
	convex.reserve(positions.size());
	for (vector<int> &p3 : positions) {
		while (convex.size() >= 2) {
			int l = convex.size();
			vector<int> &p1 = convex[l - 2];
			vector<int> &p2 = convex[l - 1];
			if (ccw(p1, p2, p3))
				break;
			convex.pop_back();
		}
		convex.push_back(p3);
	}
	return convex.size();
}

int main() {
	int n, answer = -2;
	cin >> n;
	vector<vector<int>> positions;

	positions.resize(n, vector<int>(2));
	for (int i = 0; i < n; i++)
		cin >> positions[i][0] >> positions[i][1];
	sort(positions.begin(), positions.end(), cmp);
	answer += convex(positions);

	reverse(positions.begin(), positions.end());
	answer += convex(positions);
	cout << answer;
	return 0;
}