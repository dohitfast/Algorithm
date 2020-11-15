#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	vector<vector<bool>> map(n + 1, vector<bool>(n + 1, false));

	for (int i = 0; i < results.size(); i++)
		map[results[i][0]][results[i][1]] = true;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				if (map[j][i] && map[i][k])
					map[j][k] = 1;

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			if (map[i][j] || map[j][i])
				cnt++;
		}
		if (cnt == n - 1)
			answer++;
	}
	return answer;
}

int main() {
	vector<vector<int>> results = { {4,3}, {4,2}, {3,2}, {1,2}, {2,5} };
	int n = 5;
	solution(n, results);
	return 0;
}