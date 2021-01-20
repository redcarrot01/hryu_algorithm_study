# include <stdio.h>
# include <iostream>

using namespace std;

int n=10;
int arr[10] = { 7, 5, 9, 0, 3 ,1, 6 ,2 ,4 , 8 };

void quickSort(int* arr, int start, int end) {
	// ���Ұ� 1���� ��� ����
	if (start >= end) return;
	int pivot = start;
	int left = start + 1;
	int right = end;
	while (left <= right) {
		// left : �ǹ�����  ū ������ ã�� ������
		// left <=end �� {1,2} �ΰ��, 
		while (left <= end && arr[left] <= arr[pivot]) left++;
		// right : �ǹ����� ���� ������ ã�� ������
		while (right > start && arr[right] >= arr[pivot]) right--;
		// �����ȴٸ� ���� �����Ϳ� �ǹ��� ��ü 
		// => right�ε����� pivot�� ��, �� right�� pivot
		// if ���������ν� left > right�� ��
		if (left > right) swap(arr[pivot], arr[right]);
		// �������� �ʾҴٸ� ���� �����Ϳ� ū �����͸� ��ü
		else swap(arr[left], arr[right]);
	}
	// ���� ���� ����, �����ʵ� ���� ��Ƽ��(���� �Ǻ��� right)�� right????
	quickSort(arr, start, right - 1);
	quickSort(arr, right + 1, end);
}

int main() {
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}