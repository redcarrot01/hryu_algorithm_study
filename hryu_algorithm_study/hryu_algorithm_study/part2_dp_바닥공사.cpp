#include <iostream>
#include <stdio.h>
using namespace std;

// ��� ���� ���� dp �ʱ�ȭ
int d[1001];
int n;

int main() {
	cin >> n;
	d[1] = 1;
	d[2] = 3;
	// ���Ҿ�
	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + d[i - 2] * 2) % 796796;
	}
	cout << d[n] << '\n';
}