# include <iostream>
#include <vector>
using namespace std;

// sol1
/*
static int N, arr[10000000];

int solve(int left, int right) {
	// ���� 1 : left > right �̸� ������ ����
	if (left > right) return 0;
	
	int mid = (left + right) / 2;
	// ���� 2 : �Ұ����� �ε���. ���� Ž��
	if (N - 1 < arr[mid]) solve(left, mid - 1);
	// ���� 3 : �Ұ����� �ε��� , ������ Ž��
	if (arr[mid] < 0) solve(mid + 1, right);

	// Ž��������� ������ �߰ߵǾ��ٸ�
	if (mid == arr[mid]) return mid;
	// ���� 1 : �Ұ���, ���� Ž��
	else if (mid < arr[mid]) solve(left, mid - 1);
	// ���� 2 : ������ Ž�� mid > arr[mid]
	else solve(mid + 1, right);

}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	int answer = solve(0, N - 1);
	if (answer) cout << answer << '\n';
	else cout << -1 << '\n';
}
*/

// sol2

// ���� Ž�� �ҽ��ڵ� ���� (��� �Լ�)
int binarySearch(vector<int>& arr, int start, int end) {
	// ������ ����
	if (start > end) return - 1;
	int mid = (start + end) / 2;
	// ������ ã�Ҵٸ� ��ȯ
	if (arr[mid] == mid) return mid;
	// �߰����� ������ �߰����� ���� ��� ���� Ž��
	else if (arr[mid] > mid) return binarySearch(arr, start, mid - 1);
	else return binarySearch(arr, mid + 1, end);

}

int n;
vector <int> arr;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);

	}
	//���� Ž��
	int index = binarySearch(arr, 0, n - 1);

	// ���
	cout << index << "\n";
}