// �����¿� ���� -> �ùķ��̼�/����/����Ž�� ����
// n*n ���簢��
// (1,1 )���� ���� �� ��ǥ, (n,n) ���� ������ �Ʒ�
// ���� (1,1)
// L���� R������  U�� D�Ʒ�
// ���簢�� ���� ����� ������ ����

// �ð����� 2��
// �Է� N 1~100, �̵��� ��ȹ��
// ��� ������ǥ


# include <stdio.h>
# include <iostream>
# include <string>
using namespace std;

int n;
string plans;
int x = 1, y = 1;

// L R U D
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0 , 0};
char moveType[4] = { 'L', 'R', 'U', 'D' };

int main() {
	cin >> n;
	cin.ignore(); //�����ʱ�ȭ-> ���ۿ� �Էµ� ������ ���� �߻��Ѵٸ�
	// ���ڿ� ����(�����Է�/ǥ���Է�, ������ string�� ����, ��� ���������� ����)
	getline(cin, plans);

	for (int i = 0; i < plans.size(); i++) {
		char plan = plans[i];
		// �̵� �� ��ǥ ���ϱ�
		int nx = 0, ny = 0; //�ʱ�ȭ �ݵ�� �ʿ�
		for (int j = 0; j < 4; j++) {
			if (plan == moveType[j]) {
				nx = x + dx[j];
				ny = y + dy[j];
			}
		}
		// ��������°�� ����
		if (nx<1 || ny<1 || ny >n || ny> n)
			continue;
		x = nx;
		y = ny;
	}
	cout << x << ' ' << y << '\n';
	return 0;

}