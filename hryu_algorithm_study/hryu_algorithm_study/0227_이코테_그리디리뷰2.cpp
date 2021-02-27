// 볼링공고르기, 만들수없는금액, 무지먹방라이브 풀기
//만들수없는금액
/*
만들수없는 양의 정수금액중 최솟값
5
3 2 1 1 9 -> 8
3
3 5 7 -> 1

조건 : 
입력
1 ~ 1000
각 화폐단위 1,000,000 이하

- 1. 주어진 동전 오름차순
- 2. target =1 로 지정
- 3. target 매번 반복하여, 주어진 동전 더하기
- 4. target < 주어진 동전 , target 반환
(target이 가지고 있는 동전리스트 중 어떤수보다 작은수라면, 그 아래수까지는 만들수있음)
*/
//# include <iostream>
//# include <vector>
//# include <algorithm>
//
//using namespace std;
//
//int n;
//vector <int> arr;
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int x;
//		cin >> x;
//		arr.push_back(x);
//	}
//	sort(arr.begin(), arr.end());
//
//	int target = 1;
//	for (int i = 0; i < n; i++) {
//		if (target < arr[i]) break;
//		target += arr[i];
//	}
//	cout << target;
//}

// 볼링공 고르기
/*
두사람은 서로 무게가 다른 공을 고른다
공의 번호는 1번부터 순서대로
n =5 m=3(무게)이라면
무게 1 3 2 3 2 (1~5 순서대로 번호)
두사람이 공고르는 경우의수 8

조건 
입력 n : 1~1000, m : 10

시간복잡도 : 경우의수비교 O(N*N) = 1,000,000 고려 안해도 됨

SOL
- 볼링공의 무게 별로 개수 집계
- 최소무게 1 부터 최대무게 m까지 반복문
 {	전체 볼링골 개수 = 전체 볼링골 개수 - 무게가 i인 볼링골 개수
	반환값 += 무게가 i인 볼링골 개수 * 전체볼링골 개수
 }
*/

//# include <iostream>
//
//using namespace std;
//
//int n, m;
//int arr[11];
//int result = 0;
//
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		int x;
//		cin >> x;
//		arr[x] += 1; // 집계하는 거
//	}
//	for (int i = 1; i <= m; i++) { // 최소무게1 부터 최대무게m까지 반복
//		n = n - arr[i]; 
//		result += arr[i] * n;
//	}
//	cout << result;
//
//}

