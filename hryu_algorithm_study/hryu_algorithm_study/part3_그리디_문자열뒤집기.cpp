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
		// 왼 -> 오 이동하면서 인접한 숫자가 서로 다를때
		if (str[i] != str[i + 1]) {
			if (str[i + 1] == '1') cnt0++;
			else cnt1++;
		}
	}
	cout << min(cnt0, cnt1) << '\n';
}