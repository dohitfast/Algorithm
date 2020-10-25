#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct student {
	int index;
	int count;
	int time;
}student;

bool cmp(const student &a, const student &b) {
	if (a.count > b.count)
		return true;
	else if (a.count == b.count)
		if (a.time > b.time)
			return true;
	return false;
}

bool last(const student &a, const student &b) {
	if (a.index < b.index)
		return true;
	return false;
}

int main() {
	vector<student> value;
	int n; // ����Ʋ�� ����
	cin >> n;

	int cnt; // ��ü �л��� ��õ Ƚ��
	cin >> cnt;

	int a;
	for (int i = 0; i < cnt; i++) {
		cin >> a;

		bool flag = false;
		int tag;
		for (int j = 0; j < value.size(); j++) { // �̹� ����Ʋ�� �ִ� �ĺ� ã��
			if (a == value[j].index) {
				flag = true; // ����Ʋ�� ������ true
				tag = j;
				break;
			}
		}

		if (value.size() < n && !flag) // ����Ʋ�� ����ְ� Ʋ�� ���� �ĺ�
			value.push_back({ a, 1, i });
		else if (value.size() == n && !flag) { // ����Ʋ�� �� á�µ� Ʋ�� ���� �ĺ�
			value.pop_back();
			value.push_back({ a, 1, i });
		}
		else if (flag) { // ����Ʋ�� �ִ� �ĺ�
			value[tag].count++;
			//value[tag].time = i;
		}

		sort(value.begin(), value.end(), cmp);
	}

	sort(value.begin(), value.end(), last);
	for (int i = 0; i < n; i++)
		cout << value[i].index << " ";
	return 0;
}