// 왕실의 나이트
// 시뮬레이션, 완전탐색

// 8가지 방향 벡터를 설정해 준다

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string input;

int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

int main() {
	// 현재 나이트의 위치 입력
	cin >> input;
	int row = input[1] - '0'; //1~8
	int col = input[0] - 'a' + 1; //1~8

	// 8가지 방향이 대하여 각 위치로 이동이 가능한지 확인
	int result=0;
	for (int i = 0; i < 8; i++) {
		// 이동하고자 하는 위치 확인
		int nextr = row + dx[i];
		int nextc = col + dy[i];
		// 해당 위치로 이동이 가능하다면 카운트 증가
		if (nextr >= 1 && nextc >= 1 && nextr <= 8 && nextc <= 8) {
			result++;
		}
	}
	cout << result << '\n';
	return 0;


}