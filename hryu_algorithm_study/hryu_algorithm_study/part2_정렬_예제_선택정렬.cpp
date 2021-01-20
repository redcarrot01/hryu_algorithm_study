#include <stdio.h>
#include <iostream>

using namespace std;

int n = 10;
int arr[10] = { 7, 5, 9, 0, 3, 1, 6, 2, 4 ,8 };

int main() {
	for (int i = 0; i < n; i++) {
		int m_in = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[m_in] > arr[j]) {
				m_in = j;
			}
		}
		swap(arr[i], arr[m_in]); // ½º¿ÍÇÁ
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}