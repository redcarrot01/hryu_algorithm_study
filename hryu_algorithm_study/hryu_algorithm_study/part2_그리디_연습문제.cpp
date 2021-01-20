// °Å½º¸§µ·
#include <stdio.h>
#include <iostream>
using namespace std;

int n = 1260;
int cnt;

int coin[4] = { 500, 100, 50, 10 };

int main(void) {
	for (int i = 0; i < 4; i++) {
		cnt += n / coin[i];
		n %= coin[i];
	}
	cout << cnt << '\n';
}
//¤·¤·¤·¤·