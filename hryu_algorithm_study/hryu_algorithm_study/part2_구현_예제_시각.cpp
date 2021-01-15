// 시각문제
// N : 0~23
// 완전탐색문제
// 하루는 86400 
// 00시 00분 00초에tj n:59:59 3이 하나라도 포함된 경우의 수

// c++은 시분초를 다 문자열로 만드는 방법보다 매개변수로 입력받는 함수 생성
# include <iostream>
# include <stdio.h>

using namespace std;
int h, cnt;

bool check(int h, int m, int s) {
	if (h % 10 == 3 || m % 10 == 3 || m / 3 == 3 || s % 10 == 3 || s / 10 == 3)
		return true;
	return false;
}
int main() {
	cin >> h;
	for (int i = 0; i <= h; i++) {
		for (int j = 0; j < 60; j++) {
			for (int k = 0; k < 60; k++) {
				if (check(i, j, k)) cnt++;
			}
		}
	}

	cout << cnt << '\n';
	return 0;

}