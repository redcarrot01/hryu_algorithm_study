// �ð�����
// N : 0~23
// ����Ž������
// �Ϸ�� 86400 
// 00�� 00�� 00�ʿ�tj n:59:59 3�� �ϳ��� ���Ե� ����� ��

// c++�� �ú��ʸ� �� ���ڿ��� ����� ������� �Ű������� �Է¹޴� �Լ� ����
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