// 상하좌우 문제 -> 시뮬레이션/구현/완전탐색 문제
// n*n 정사각형
// (1,1 )가장 왼쪽 위 좌표, (n,n) 가장 오른쪽 아래
// 시작 (1,1)
// L왼쪽 R오른쪽  U이 D아래
// 정사각형 공간 벗어나는 움직임 무시

// 시간제한 2초
// 입력 N 1~100, 이동할 계획서
// 출력 도착좌표


# include <stdio.h>
# include <iostream>
# include <string>
using namespace std;

int n;
string plans;
int x = 1, y = 1;

// L R U D
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0 , 0};
char moveType[4] = { 'L', 'R', 'U', 'D' };

int main() {
	cin >> n;
	cin.ignore(); //버퍼초기화-> 버퍼에 입력된 값으로 에러 발생한다면
	// 문자열 저장(파일입력/표준입력, 저장할 string형 변수, 어느 문자전까지 저장)
	getline(cin, plans);

	for (int i = 0; i < plans.size(); i++) {
		char plan = plans[i];
		// 이동 후 좌표 구하기
		int nx = 0, ny = 0; //초기화 반드시 필요
		for (int j = 0; j < 4; j++) {
			if (plan == moveType[j]) {
				nx = x + dx[j];
				ny = y + dy[j];
			}
		}
		// 공간벗어나는경우 무시
		if (nx<1 || ny<1 || ny >n || ny> n)
			continue;
		x = nx;
		y = ny;
	}
	cout << x << ' ' << y << '\n';
	return 0;

}