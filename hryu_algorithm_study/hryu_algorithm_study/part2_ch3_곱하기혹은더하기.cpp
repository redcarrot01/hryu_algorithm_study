// �Է� : ��������� �ִ� ���� ū�� 20�� ���� ����
// �������� c������ ���� ū�� int������ 21�� �����ϱ�

// �ð� ���� 1��
// �޸� ���� 128mb
// �μ� �� �ϳ��� 1������ ��� ���ϱ�, ��� 2�̻��� ��� ���ϱ�

// long long / long long int 8����Ʈ 
// int ���� ���� 

# include <stdio.h>
# include <iostream>

using namespace std;
string str;

int main() {
	cin >> str;
	// ù ��° ���ڸ� ���ڷ� ������ ���� ����
	long long result = str[0] - '0';

	for (int i = 1; i < str.size(); i++) {
		// �� �� �߿��� �ϳ��� '0' Ȥ�� '1' �� ���, ���ϱ� ���ٴ� ���ϱ� ����
		int num = str[i] - '0';
		if (num <= 1 || result <= 1) result += num;
		else result *= num;

	}
	cout << result << '\n';
}


