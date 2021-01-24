#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// ���� {left_value, right_vlaue}�� �������� ���� ��ȯ �Լ�
int countbyrange(vector<int>& v, int leftvalue, int rightvalue) {
	vector<int>::iterator rightindex = upper_bound(v.begin(), v.end(), rightvalue);
	vector<int>::iterator leftindex = lower_bound(v.begin(), v.end(), leftvalue);
	return rightindex - leftindex;
}

int n, x;
vector<int> v;

int main() {
	// �������� ����n, ã���� �ϴ� �� x �Է¹ޱ�
	cin >> n >> x;

	// ��ü ������ �Է� �ޱ�
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	cout << countbyrange(v, x, x) << '\n';

}
/*
lower_bound
- ����Ž�� ��� Ž�� ���
- key�� ������ key���� ū ���� ���� ���� ��(���ͷ�����) ã��
- value�� ������ �̻��� �� ��ȯ
- ���� ���� ������ ���� ��� ����
lower_bound(arr, arr+n, key)
- ���ͷ����� ��ȯ ���� �ε��� ��ȯ�Ϸ��� lower_bound(~)-vertor.begin()

upper_bound
- value���� ū ���� ������ ���ͷ����� ��ȯ
- ���ͷ����� ��ȯ ���� �ε��� ��ȯ�Ϸ��� upper_bound(~)-vertor.begin()
*/