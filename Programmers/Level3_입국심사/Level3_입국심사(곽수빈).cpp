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

		for (int i = 0; i < times.size(); i++) // mid_time에 심사 받을 수 있는 사람의 수
			people += mid_time / times[i];

		if (people >= n) { // max를 줄여서 사람 수를 줄여줌
			if (mid_time < answer)
				answer = mid_time;
			max_time = mid_time - 1;
		}
		else { // min을 늘려서 사람 수를 늘려줌
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