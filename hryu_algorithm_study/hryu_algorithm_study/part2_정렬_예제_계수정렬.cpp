# include <stdio.h>
#include <iostream>

using namespace std;

#define MAX_VALUE 9

int n = 15;
int arr[15] = { 7, 5,9, 0,3,1,6,2, 9,1,4,8,0,5,2 };

int cnt[MAX_VALUE + 1];

int main() {
	// 각 데이터에 해당하는 인덱스 값 증가
	for (int i = 0; i < n; i++) {
		cnt[arr[i]]++;
	}
	// 정렬 확인
	for (int i = 0; i <= MAX_VALUE; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			cout << i << ' ';
		}
	}
}