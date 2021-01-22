# include <stdio.h>
# include <iostream>
# include <vector>

using namespace std;

int n, target;
vector<int> arr;

// &�� ������ �迭 ������ ī������ �ʰ� �̹� �����ϴ� ���ͺ����� ���۷����� �����ϰ��� �� . 
// ���� &�� ���ٸ� �Լ��� ȣ���� �� ������ ���ͺ����� ���� ī���ϹǷ� �ð����⵵ o(n)�̵�

int binarySearch(vector<int>& arr, int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		// ã�� ��� �߰��� �ε��� ��ȯ
		if (arr[mid] == target) return mid;
		else if (arr[mid] > target) end = mid - 1;
		else start = mid + 1;
	}
return -1;
}

int main() {
	cin >> n >> target;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	// ���� Ž�� ���� ��� ���
	int result = binarySearch(arr, target, 0, n - 1);
		if (result == -1) {
			cout << "���Ұ� �������� �ʽ��ϴ�." << '\n';
		}
		else {
			cout << result + 1 << '\n';
		}
}