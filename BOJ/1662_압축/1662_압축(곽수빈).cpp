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
		if (multi.empty()) { // ��ȣ�� �ϳ��� ���� ��
			if (isdigit(s[i])) { // ������ ��
				if (i + 1 < s.size() && s[i + 1] == '(') // ���� ������ ( �� ���� ���� ���Ϳ� �߰�
					multi.push_back(num);
				else // answer �� + 1 ���ֱ�
					answer++;
			}
		}
		else { // ��ȣ�� �̹� ������ ��
			if (isdigit(s[i])) { // ������ ��
				if (i + 1 < s.size() && s[i + 1] == '(') { // ���� ������ ( ��
					int a = multi.back(); // �󸶸� ��������ϴ���
					multi.push_back(num * a); // ���� ��ȣ ���� ��� �� ���� ���� ���� ���ؾ���
					answer += check * a; // answer �߰�
					check = 0; // ��ȣ���� string �� �ʱ�ȭ
				}
				else // ������ ( �� �ƴϸ� ��ȣ���� string ���� �÷��ֱ�
					check++;
			}
			else {
				if (s[i] == ')') {
					int a = multi.back(); // �󸶸� ��������ϴ���
					multi.pop_back(); //  ��������
					answer += check * a; // �տ��� �� ������ �ֵ��� ���⼭ ���ϰ� ������ �ֵ��� check�� 0
					check = 0;
				}
			}
		}
	}
	cout << answer;
	return 0;
}