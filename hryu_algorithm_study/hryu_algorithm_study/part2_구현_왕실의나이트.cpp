// �ս��� ����Ʈ
// �ùķ��̼�, ����Ž��

// 8���� ���� ���͸� ������ �ش�

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string input;

int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

int main() {
	// ���� ����Ʈ�� ��ġ �Է�
	cin >> input;
	int row = input[1] - '0'; //1~8
	int col = input[0] - 'a' + 1; //1~8

	// 8���� ������ ���Ͽ� �� ��ġ�� �̵��� �������� Ȯ��
	int result=0;
	for (int i = 0; i < 8; i++) {
		// �̵��ϰ��� �ϴ� ��ġ Ȯ��
		int nextr = row + dx[i];
		int nextc = col + dy[i];
		// �ش� ��ġ�� �̵��� �����ϴٸ� ī��Ʈ ����
		if (nextr >= 1 && nextc >= 1 && nextr <= 8 && nextc <= 8) {
			result++;
		}
	}
	cout << result << '\n';
	return 0;


}