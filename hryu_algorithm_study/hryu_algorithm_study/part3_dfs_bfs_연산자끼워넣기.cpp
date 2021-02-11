// �����ڴ� operators ��� 4¥�� �迭 ����
// �� ��, ��Ʈ��ŷ ����Ͽ� ��ͷ� �ذ�
// �Ű������� ���±��� ������ result, ������ ������ ���� �ε����� �Է¹޵��� �ϴ�
// ��Ʈ��ŷ ��� �Լ��� �����Ͽ� Ǯ���Ѵ�

 // �̹����� ����� �帧�� �Ű������� � ���� ����ؾ����� �����ϴ� �ɷ� �ʿ�

#include <iostream>
using namespace std;

int N; // n :2~11
int operands[11]; //����
int operators[4]; // ������ 4���ϱ�
int mymin = 1000000001;
int mymax = -1000000001;

// ��ͷ�
void get_answer(int result, int idx) {
	if (idx == N) {
		if (result > mymax) mymax = result;
		if (result < mymin) mymin = result;
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (operators[i] > 0) {

			operators[i]--; // ������ ����ϸ� 1�� �ٿ��ֱ�
			if (i == 0)
				get_answer(result + operands[idx], idx + 1);
			else if (i == 1)
				get_answer(result + operands[idx], idx + 1);
			else if (i == 2)
				get_answer(result * operands[idx], idx + 1);
			else
				get_answer(result / operands[idx], idx + 1);

			operators[i]++; // �ٸ� �����ڸ� ����� ���̹Ƿ�
			// �Ʊ� �ٿ��� ������ ���� �÷��� 
		}
	}
	return ;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> operands[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
	}
	get_answer(operands[0], 1);
	cout << mymax << '\n';
	cout << mymin;
}

