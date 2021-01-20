# include <stdio.h>
# include <iostream>

using namespace std;

int n=10;
int arr[10] = { 7, 5, 9, 0, 3 ,1, 6 ,2 ,4 , 8 };

void quickSort(int* arr, int start, int end) {
	// 원소가 1개인 경우 종료
	if (start >= end) return;
	int pivot = start;
	int left = start + 1;
	int right = end;
	while (left <= right) {
		// left : 피벗보다  큰 데이터 찾을 때까지
		// left <=end 는 {1,2} 인경우, 
		while (left <= end && arr[left] <= arr[pivot]) left++;
		// right : 피벗보다 작은 데이터 찾을 때까지
		while (right > start && arr[right] >= arr[pivot]) right--;
		// 엇갈렸다면 작은 데이터와 피벗을 교체 
		// => right인덱스에 pivot값 들어감, 즉 right이 pivot
		// if 실행함으로써 left > right이 됨
		if (left > right) swap(arr[pivot], arr[right]);
		// 엇갈리지 않았다면 작은 데이터와 큰 데이터를 교체
		else swap(arr[left], arr[right]);
	}
	// 분할 이후 왼쪽, 오른쪽도 정렬 파티션(전의 피봇이 right)이 right????
	quickSort(arr, start, right - 1);
	quickSort(arr, right + 1, end);
}

int main() {
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}