
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
	// 문자를 하나씩 확인
	for (int i = 0; i < str.size(); i++) {
		if (isalpha(str[i])) {
			result.push_back(str[i]);
		}
		else {
			sum += str[i] - '0';
		}
	}
	// 알파벳 정렬
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
	if (sum != 0) {
		cout << sum;
	}
	cout << '\n';
}
// int isalpha(int c);
/*
인자가 알파벳이라면 0 아닌수, 알파벳 아니라면 0 반환
대문자 -> 1 반환(아스키 코드 65~ 90) 
소문자 -> 2 반환(아스키 코드 97~122)
나머지 -> 0 반환

*/
// push_back()
/*
vector의 멤버함수
vector는 자동으로 줄고 늘어나는 배열?
*/
