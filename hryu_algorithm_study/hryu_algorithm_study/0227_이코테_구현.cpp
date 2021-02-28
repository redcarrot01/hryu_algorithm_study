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
//# include <iostream>
//# include <string>
//
//using namespace std;
//
//string s;
//
//int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
//int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
//
//int main() {
//	// 현재 나이트의 위치 입력, 숫자로 변환()
//	cin >> s;
//	int row = s[1] - '0'; // 행 1~8
//	int col = s[0] - 'a' + 1; //열 1~8
//
//	// 8 가지 방향에 대해 가능한지 위치 확인
//	int result = 0;
//	for (int i = 0; i < 8; i++) {
//		// 이동하고자 하는 위치 확인
//		int nextr = row + dx[i];
//		int nextc = col + dy[i];
//		// 해당 위치로 이동이 가능 -> 카운트 증가
//		if (nextr >= 1 && nextc >= 1 && nextr <= 8 && nextc <= 8) {
//			result++;
//		}
//	}
//	cout << result << '\n';
//
//}

// 예제 문자 쭉 풀어보기 
/*
구현은 완전탐색, 시뮬레이션이 있다
완전탐색 : 모든 경우의 수를 주저 없이 다 계산
시뮬레이션 : 문제에서 제시한 알고리즘을 한 단계씩 차례대로 직접 수행
*/


// 예제_ 상하좌우
/*
5 (1~100)
R R R U D D(1~100)    -> 3 4
*/
# include <iostream>
# include <string>

using namespace std;

int n;
string plans;
int x = 1, y = 1;

// L R U D
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0 , 0 };
char moveType[4] = { 'L','R', 'U', 'D' };

int main() {
	cin >> n;
	cin.ignore(); //버퍼초기화 -> 버퍼에 입력된 값으로 에러 생길까봐
	// 문자열 저장(파일입력/표준입력, 저장할 string형 변수, 어느 문자전까지 저장)
	getline(cin, plans);

	for (int i = 0; i < plans.size(); i++) {
		char plan = plans[i];
		// 이동 후 좌표구하기
		int nx = 0, ny = 0; // 초기화 반드시 필요
		for (int j = 0; j < 4; j++) {
			if
		}
	}
}
gg