#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long solution(int n, vector<int> times) {
	long long min_time = 1;
	long long max_time = n * (long long)times.back();
	long long mid_time;
	long long answer = max_time;

	while (min_time <= max_time) {
		long long people = 0;
		mid_time = (min_time + max_time) / 2;

		for (int i = 0; i < times.size(); i++) // mid_time�� �ɻ� ���� �� �ִ� ����� ��
			people += mid_time / times[i];

		if (people >= n) { // max�� �ٿ��� ��� ���� �ٿ���
			if (mid_time < answer)
				answer = mid_time;
			max_time = mid_time - 1;
		}
		else { // min�� �÷��� ��� ���� �÷���
			min_time = mid_time + 1;
		}
	}
	return answer;
}

int main() {
	int n = 6;
	vector<int> times = { 7, 10 };
	cout << solution(n, times);
	return 0;
}