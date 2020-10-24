#include<iostream>

using namespace std;


int main() {
	int h, w;
	cin >> h >> w;
	
	int *arr = new int[w];

	int max_index = 0;
	int max_value = 0;
	int answer = 0;

	for (int i = 0; i < w; i++) {
		cin >> arr[i];
		if (arr[i] > max_value) {
			max_value = arr[i];
			max_index = i;
		}
	}

	int min_value = arr[0];
	for (int i = 0; i < max_index; i++) {
		if (arr[i] < min_value) 
			answer += min_value - arr[i];
		else 
			min_value = arr[i];
	}

	min_value = arr[w - 1];
	for (int i = w - 2; i > max_index; i--) {
		if (arr[i] < min_value) 
			answer += min_value - arr[i];
		else 
			min_value = arr[i];
	}

	cout << answer;
	return 0;
}
