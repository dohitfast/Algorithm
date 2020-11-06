#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int solution(vector<int> a) {
	int right = a[a.size() - 1];
	int left = a[0];
	int answer = 0;
	int i = 1;
	while (right != left) {
		if (right > a[a.size() - 1 - i]) {
			right = a[a.size() - 1 - i];
			answer++;
		}

		if (left > a[i]) {
			left = a[i];
			answer++;
		}
		i++;
	}

	if (left == right)
		return answer + 1;
	else
		return answer + 2;
}

int main() {
	vector<int> a = { -16,27,65,-2,58,-92,-71,-68,-61,-33 };
	solution(a);
	return 0;
}