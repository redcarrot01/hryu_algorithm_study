#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
// 계산 결과 저장 테이블
// 헐 어려워
int d[30001];
int x;

int main() {
	cin >> x;
	for (int i = 2; i <= x; i++) {
		d[i] = d[i - 1] + 1;

		if (i % 2 == 0)
			d[i] = min(d[i], d[i / 2] + 1);
		if (i % 3 == 0)
			d[i] = min(d[i], d[i / 3] + 1);
		if (i % 5 == 0)
			d[i] = min(d[i], d[i / 5] + 1);
	}
	cout << d[x] << '\n';
	return 0;
}