#include <stdio.h>
#include <iostream>

using namespace std;

// 계산 결과 저장 위한 dp테이블 초기화
long long d[100];

int main() {
	d[1] = 1;
	d[2] = 1;
	int n = 50; 

	// 반복문
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}
	cout << d[n] << '\n';
	return 0;
}