# include <stdio.h>
# include <iostream>
# include <algorithm>
using namespace std;

string str;

int cnt0 = 0;
int cnt1 = 0;

int main() {
	cin >> str;
	if (str[0] == '1')cnt0++;
	else cnt1++;

	for (int i = 0; i < str.size() - 1; i++) {
		// �� -> �� �̵��ϸ鼭 ������ ���ڰ� ���� �ٸ���
		if (str[i] != str[i + 1]) {
			if (str[i + 1] == '1') cnt0++;
			else cnt1++;
		}
	}
	cout << min(cnt0, cnt1) << '\n';
}