# include <stdio.h>
# include <iostream>
# include <vector>

using namespace std;

int n, target;
vector<int> arr;

// &는 별도로 배열 변수를 카피하지 않고 이미 존재하는 벡터변수의 래퍼런스를 전달하고자 함 . 
// 만약 &이 없다면 함수를 호출할 때 기존의 벡터변수의 값을 카피하므로 시가녹잡도 o(n)이됨

int binarySearch(vector<int>& arr, int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		// 찾은 경우 중간점 인덱스 변환
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

	// 이진 탐색 수행 결과 출력
	int result = binarySearch(arr, target, 0, n - 1);
		if (result == -1) {
			cout << "원소가 존재하지 않습니다." << '\n';
		}
		else {
			cout << result + 1 << '\n';
		}
}