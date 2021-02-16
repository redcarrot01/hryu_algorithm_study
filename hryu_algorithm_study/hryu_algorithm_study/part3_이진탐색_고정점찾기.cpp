# include <iostream>
#include <vector>
using namespace std;

// sol1
/*
static int N, arr[10000000];

int solve(int left, int right) {
	// 조건 1 : left > right 이면 고정점 없음
	if (left > right) return 0;
	
	int mid = (left + right) / 2;
	// 조건 2 : 불가능한 인덱스. 왼쪽 탐색
	if (N - 1 < arr[mid]) solve(left, mid - 1);
	// 조건 3 : 불가능한 인덱스 , 오른쪽 탐색
	if (arr[mid] < 0) solve(mid + 1, right);

	// 탐색결과에서 고정점 발견되었다면
	if (mid == arr[mid]) return mid;
	// 조건 1 : 불가능, 왼쪽 탐색
	else if (mid < arr[mid]) solve(left, mid - 1);
	// 조건 2 : 오른쪽 탐색 mid > arr[mid]
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

// 이진 탐색 소스코드 구현 (재귀 함수)
int binarySearch(vector<int>& arr, int start, int end) {
	// 고정점 없음
	if (start > end) return - 1;
	int mid = (start + end) / 2;
	// 고정점 찾았다면 반환
	if (arr[mid] == mid) return mid;
	// 중간점의 값보다 중간점이 작은 경우 왼쪽 탐색
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
	//이진 탐색
	int index = binarySearch(arr, 0, n - 1);

	// 결과
	cout << index << "\n";
}