# include <stdio.h>
# include <iostream>
# include <string>
# include <vector>

using namespace std;

 //���� Ž�� �ҽ��ڵ�
int sequantialSearch(int n, string target, vector<string> arr) {
	// �� ���Ҹ� �ϳ��� Ȯ��
	for (int i = 0; i < n; i++) {
		// ������ ���Ұ� ã���� �ϴ� ���ҿ� ������ ���
		if (arr[i] == target) {
			return i+1; //�ε��� ����
		}
	}
	return -1; // ���� ��ã�� ���
}

int n;
string target;
vector<string> arr;

int main(void) {
	cout << "������ ���� ������ �Է��� ���� �� ĭ ��� ã�� ���ڿ��� �Է��ϼ���." << '\n';
	cin >> n >> target ;
	cout << "�ռ� ���� ���� ������ŭ ���ڿ��� �Է��ϼ���. ������ ���� �� ĭ���� �մϴ�." << '\n';
	for (int i = 0; i < n;  i++) {
		string x;
		cin >> x;
		arr.push_back(x);
	}
	cout << sequantialSearch(n, target, arr) << '\n';
}

// �ּ� ctrl + k+ c ���� ctrl+k+u 

