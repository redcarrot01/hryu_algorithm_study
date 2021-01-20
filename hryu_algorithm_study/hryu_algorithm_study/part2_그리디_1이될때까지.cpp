
// 1이 될 때까지
/*
설명

N이 1이 될 때까지 반복 수행(선택하여)
 1 - N에서 1 뺴기
 2 - N을 K로 나누기
 1번 혹은 2번 과정 수행해야 하는 최소 횟수
*/

# include <stdio.h>
# include <iostream>
using namespace std;

int n, k;
int cnt;

int main(void) {
	cin >> n >> k;

	while (true) {
		// 몫*k는 k로 나누어 떨어질 수 있는 n과 가까운 수
		int target = (n/k) *k;
		// tafget이 되기 위해 1을 몇번빼야하는지를 센다
		cnt += (n - target);
		// target이 되어야 나누어 떨어짐
		n = target;

		if (n < k) break;

		cnt ++;
		n /= k;
	}
	// 마지막에 남으수 -1 하기
	cnt += (n - 1);
	cout << cnt << '\n';

}