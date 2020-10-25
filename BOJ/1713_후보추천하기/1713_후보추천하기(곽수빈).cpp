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
	int n; // 사진틀의 개수
	cin >> n;

	int cnt; // 전체 학생의 추천 횟수
	cin >> cnt;

	int a;
	for (int i = 0; i < cnt; i++) {
		cin >> a;

		bool flag = false;
		int tag;
		for (int j = 0; j < value.size(); j++) { // 이미 사진틀에 있는 후보 찾기
			if (a == value[j].index) {
				flag = true; // 사진틀에 있으면 true
				tag = j;
				break;
			}
		}

		if (value.size() < n && !flag) // 사진틀이 비어있고 틀에 없는 후보
			value.push_back({ a, 1, i });
		else if (value.size() == n && !flag) { // 사진틀이 꽉 찼는데 틀에 없는 후보
			value.pop_back();
			value.push_back({ a, 1, i });
		}
		else if (flag) { // 사진틀에 있는 후보
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