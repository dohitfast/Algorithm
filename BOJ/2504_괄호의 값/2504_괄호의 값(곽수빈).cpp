#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
	string str;
	stack<char> s;
	int answer = 0;
	int tmp = 1;

	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			tmp *= 2;
			s.push('(');
		}
		else if (str[i] == '[') {
			tmp *= 3;
			s.push('[');
		}
		else if (str[i] == ')' && (s.empty() || s.top() != '(')) {
			answer = 0;
			break;
		}
		else if (str[i] == ']' && (s.empty() || s.top() != '[')) {
			answer = 0;
			break;
		}
		else if (str[i] == ')') {
			if (str[i - 1] == '(')
				answer += tmp;
			s.pop();
			tmp /= 2;
		}
		else if (str[i] == ']') {
			if (str[i - 1] == '[')
				answer += tmp;
			s.pop();
			tmp /= 3;
		}
		else {
			answer = 0;
			break;
		}
	}

	if (!s.empty())
		cout << 0;
	else
		cout << answer;
	return 0;
}