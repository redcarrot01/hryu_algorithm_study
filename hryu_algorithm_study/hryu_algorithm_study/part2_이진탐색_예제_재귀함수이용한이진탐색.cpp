#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& arr, int target, int start, int end) {
	if (start > end) return -1;
	int mid = (start + end) / 2;
	// mid는 중간점 인덱스 
	if (arr[mid] == target) return mid;
	else if (arr[mid] > target) return binarySearch(arr, target, start, mid - 1);
	else return  binarySearch(arr, target, mid + 1, end);

}
int n, target;
vector<int> arr;

int main() {
	cin >> n >> target;
	for (int i = 0; i < n; i++) {
		int x; 
		cin >> x;
		arr.push_back(x);
	}

	int result = binarySearch(arr, target, 0, n - 1);
	if (result == -1) {
		cout << "원소 존재 안해요" << '\n';
	}
	else cout << result + 1 << '\n';
}