
// 1�� �� ������
/*
����

N�� 1�� �� ������ �ݺ� ����(�����Ͽ�)
 1 - N���� 1 ����
 2 - N�� K�� ������
 1�� Ȥ�� 2�� ���� �����ؾ� �ϴ� �ּ� Ƚ��
*/

# include <stdio.h>
# include <iostream>
using namespace std;

int n, k;
int cnt;

int main(void) {
	cin >> n >> k;

	while (true) {
		// ��*k�� k�� ������ ������ �� �ִ� n�� ����� ��
		int target = (n/k) *k;
		// tafget�� �Ǳ� ���� 1�� ��������ϴ����� ����
		cnt += (n - target);
		// target�� �Ǿ�� ������ ������
		n = target;

		if (n < k) break;

		cnt ++;
		n /= k;
	}
	// �������� ������ -1 �ϱ�
	cnt += (n - 1);
	cout << cnt << '\n';

}