// �ս��� ����Ʈ
/*
����Ʈ�� �̵� L�� ���
1. ���� ��ĭ + ���� ��ĭ
2. ���� ��ĭ + ���� ��ĭ

8 *8 ��ǥ ����Ʈ �̵��� �� �ִ� ����Ǽ�
����ġ 1~8 ����ġ a~h

�Է�  ���
a1     2
c2     6

�������� : ��Ž

idea : 8���� ��θ� Ȯ���Ѵ�
*/
//# include <iostream>
//# include <string>
//
//using namespace std;
//
//string s;
//
//int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
//int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
//
//int main() {
//	// ���� ����Ʈ�� ��ġ �Է�, ���ڷ� ��ȯ()
//	cin >> s;
//	int row = s[1] - '0'; // �� 1~8
//	int col = s[0] - 'a' + 1; //�� 1~8
//
//	// 8 ���� ���⿡ ���� �������� ��ġ Ȯ��
//	int result = 0;
//	for (int i = 0; i < 8; i++) {
//		// �̵��ϰ��� �ϴ� ��ġ Ȯ��
//		int nextr = row + dx[i];
//		int nextc = col + dy[i];
//		// �ش� ��ġ�� �̵��� ���� -> ī��Ʈ ����
//		if (nextr >= 1 && nextc >= 1 && nextr <= 8 && nextc <= 8) {
//			result++;
//		}
//	}
//	cout << result << '\n';
//
//}

// ���� ���� �� Ǯ��� 
/*
������ ����Ž��, �ùķ��̼��� �ִ�
����Ž�� : ��� ����� ���� ���� ���� �� ���
�ùķ��̼� : �������� ������ �˰����� �� �ܰ辿 ���ʴ�� ���� ����
*/


// ����_ �����¿�
/*
5 (1~100)
R R R U D D(1~100)    -> 3 4
*/
# include <iostream>
# include <string>

using namespace std;

int n;
string plans;
int x = 1, y = 1;

// L R U D
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0 , 0 };
char moveType[4] = { 'L','R', 'U', 'D' };

int main() {
	cin >> n;
	cin.ignore(); //�����ʱ�ȭ -> ���ۿ� �Էµ� ������ ���� ������
	// ���ڿ� ����(�����Է�/ǥ���Է�, ������ string�� ����, ��� ���������� ����)
	getline(cin, plans);

	for (int i = 0; i < plans.size(); i++) {
		char plan = plans[i];
		// �̵� �� ��ǥ���ϱ�
		int nx = 0, ny = 0; // �ʱ�ȭ �ݵ�� �ʿ�
		for (int j = 0; j < 4; j++) {
			if
		}
	}
}
gg