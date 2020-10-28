#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cctype>

using namespace std;

int main() {
	string s;
	cin >> s;

	vector<int> multi;

	int answer = 0;
	int check = 0;

	for (int i = 0; i < s.size(); i++) {
		int num = s[i] - '0';
		if (multi.empty()) { // 괄호가 하나도 없을 때
			if (isdigit(s[i])) { // 숫자일 때
				if (i + 1 < s.size() && s[i + 1] == '(') // 만약 다음이 ( 면 곱할 값을 벡터에 추가
					multi.push_back(num);
				else // answer 값 + 1 해주기
					answer++;
			}
		}
		else { // 괄호가 이미 존재할 때
			if (isdigit(s[i])) { // 숫자일 때
				if (i + 1 < s.size() && s[i + 1] == '(') { // 만약 다음이 ( 면
					int a = multi.back(); // 얼마를 곱해줘야하는지
					multi.push_back(num * a); // 다음 괄호 안은 계속 더 곱한 숫자 값을 곱해야함
					answer += check * a; // answer 추가
					check = 0; // 괄호안의 string 수 초기화
				}
				else // 다음이 ( 가 아니면 괄호안의 string 갯수 올려주기
					check++;
			}
			else {
				if (s[i] == ')') {
					int a = multi.back(); // 얼마를 곱해줘야하는지
					multi.pop_back(); //  곱했으며
					answer += check * a; // 앞에서 안 더해준 애들은 여기서 더하고 더해준 애들은 check가 0
					check = 0;
				}
			}
		}
	}
	cout << answer;
	return 0;
}