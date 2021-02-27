// 왕실의 나이트
/*
나이트의 이동 L자 모양
1. 수평 두칸 + 수직 한칸
2. 수직 두칸 + 수평 한칸

8 *8 좌표 나이트 이동할 수 있는 경우의수
행위치 1~8 열위치 a~h

입력  출력
a1     2
c2     6

문제유형 : 완탐

idea : 8가지 경로를 확인한다
*/
# include <iostream>
# include <string>

using namespace std;

string s;

int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

int main() {
	// 현재 나이트의 위치 입력, 숫자로 변환()
	cin >> s;
	int row = s[1] - '0'; // 행 1~8
	int col = s[0] - 'a' + 1; //열 1~8

	// 8 가지 방향에 대해 가능한지 위치 확인
	int result = 0;
	for (int i = 0; i < 8; i++) {
		// 이동하고자 하는 위치 확인
		int nextr = row + dx[i];
		int nextc = col + dy[i];
		// 해당 위치로 이동이 가능 -> 카운트 증가
		if (nextr >= 1 && nextc >= 1 && nextr <= 8 && nextc <= 8) {
			result++;
		}
	}
	cout << result << '\n';

}

// 예제 문자 쭉 풀어보기 