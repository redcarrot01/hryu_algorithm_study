#include <stdio.h>
#include <iostream>

using namespace std;

long long d[100];

long long fibo(int x) {

	if (x == 1 || x == 2) {
		return 1;
	}
	if (d[x] != 0) { // 이미 계산 했다면
		return d[x];
	}
	d[x] = fibo(x - 1) + fibo(x - 2);
	return d[x];
}
int main() {
	cout << fibo(50) << '\n';
}