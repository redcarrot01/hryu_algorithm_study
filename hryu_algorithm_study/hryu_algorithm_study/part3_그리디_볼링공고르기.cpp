#include <stdio.h>
#include <iostream>
using namespace std;
int n, m;
int arr[11];
int result = 0;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[x] += 1; // �Է��� ���� ���� �ε����� �迭�� �߰��ϰ� ������
	}

	
	for (int i = 1; i <= m; i++) {
	 // ������ġ���� ���� �ִ� ���� ����
		n = n - arr[i]; 
		result += arr[i] * n; 
	}
	cout << result << '\n';
}