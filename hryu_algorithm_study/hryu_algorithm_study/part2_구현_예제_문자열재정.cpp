
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string str;
vector<char> result;
int sum = 0;

int main() {
	cin >> str;
	// ���ڸ� �ϳ��� Ȯ��
	for (int i = 0; i < str.size(); i++) {
		if (isalpha(str[i])) {
			result.push_back(str[i]);
		}
		else {
			sum += str[i] - '0';
		}
	}
	// ���ĺ� ����
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
	if (sum != 0) {
		cout << sum;
	}
	cout << '\n';
}

