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
		arr[x] += 1; // 입력한 수와 같은 인덱스의 배열에 추가하고 수세기
	}

	
	for (int i = 1; i <= m; i++) {
	 // 현재위치에서 고를수 있는 공의 개수
		n = n - arr[i]; 
		result += arr[i] * n; 
	}
	cout << result << '\n';
}