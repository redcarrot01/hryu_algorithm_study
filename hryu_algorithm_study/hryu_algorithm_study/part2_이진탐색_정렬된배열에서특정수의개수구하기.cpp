#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// 값이 {left_value, right_vlaue}인 데이터의 개수 반환 함수
int countbyrange(vector<int>& v, int leftvalue, int rightvalue) {
	vector<int>::iterator rightindex = upper_bound(v.begin(), v.end(), rightvalue);
	vector<int>::iterator leftindex = lower_bound(v.begin(), v.end(), leftvalue);
	return rightindex - leftindex;
}

int n, x;
vector<int> v;

int main() {
	// 데이터의 개수n, 찾고자 하는 값 x 입력받기
	cin >> n >> x;

	// 전체 데이터 입력 받기
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	cout << countbyrange(v, x, x) << '\n';

}
/*
lower_bound
- 이진탐색 기반 탐색 방법
- key가 없으면 key보다 큰 가장 작은 정수 값(이터레이터) 찾기
- value를 포함한 이상인 값 반환
- 같은 원수 여러개 여도 상관 없음
lower_bound(arr, arr+n, key)
- 이터레이터 반환 말고 인덱스 반환하려면 lower_bound(~)-vertor.begin()

upper_bound
- value보다 큰 값을 가지는 이터레이터 반환
- 이터레이터 반환 말고 인덱스 반환하려면 upper_bound(~)-vertor.begin()
*/