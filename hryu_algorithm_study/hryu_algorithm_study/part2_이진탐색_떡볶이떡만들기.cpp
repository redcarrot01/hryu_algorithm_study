#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	int start = 0;
	// 입력한 숫자 중 어떤 숫자가 가장 클지 모르니까
	int end = 1e9; // 10의 9승
	int result=0;

	while (start <= end) {
		long long int total = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < n; i++) {
			if (arr[i] > mid) total += arr[i] - mid;
		}
		if (total < m) {
			end = mid - 1;
		}
		else {
			result = mid; //최대한 덜 잘랐을 때가 정답이니까 기록해주기
			start = mid + 1;
		}
	}
	cout << result << '\n';

}