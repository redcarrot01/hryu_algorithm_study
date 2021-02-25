/*
그리디 : 현재 상황에서 지금 당장 좋은 것만 고르는 방법
매순간 가장 좋아 보이는 것을 택한다

*/

// ------------------------------------------------------------
// 1이 될때까지
/*
n이 1될때까지 -1 or /3 중 선택하여 반복 수행한 최소 횟수
최대한 많이 나눈다
k가 2이상이면 나눌수 있음 나누고 아니면 -1을 한다
*/
//# include <iostream>
//using namespace std;
//
//int n, k;
//int cnt;
//
//int main() {
//	cin >> n >> k;
//
//	while (true) {
//		// 몫 * k는 나누어 떨어질 수 있는 n과 가까운 수
//		int target = (n / k) * k;
//		// 나누어 떨어지기 위해, 즉 target이 되기 위해 몇번 1을 빼줘야 하는지를 셈
//		cnt += n - target;
//		// 나누어 떨어지는 수로
//		n = target;
//
//		if (n < k) break;
//		// 나누었으니까
//		cnt++;
//		n /= k;
//	}
//	// 마지막 남은 수 -1 , 1로만들기 니까 1은 남겨둬야
//	cnt += (n - 1);
//	cout << cnt;
//}
//-------------------------------------------------------------
// 곱하기 혹은 더하기
/*
 두수중 하나라도 1이하인 경우 +, 2이상인경우 x
 입력수 : 20억 이하 정수, c에서는 가장 큰 int형으로 21억 정도
 시간 제한 1초
 // long long / long long int 8바이트 
// int 생략 가능 
*/
//# include <iostream>
//using namespace std;
//
//string str;
//
//int main() {
//	cin >> str;
//	// 첫번째 문자 숫자로 변경
//	long long result = str[0] - '0';
//	for (int i = 1; i<str.size(); i++) {
//		int num = str[i] - '0';
//		if (num <= 1 || result <= 1) result += num;
//		else result *= num;
//	}
//	cout << result<<'\n';
//}
// -----------------------------------------------------------
// 모험가길드
/*
x인 모험가는 반드시 x명ㅇ이상으로 구성된 모험가 그룹에 참여
그룹수 최대값
몇명의 모험가는 그대로 남아있어도 됨
모든 모험가를 특정한 그룹에 넣을 필요 없음
- 오름차순
- 현재 그룹에 포함된 모험가수 >= 현재 확인하고 있는 공포도 => 그룹 결성
*/
//# include <iostream>
//# include <vector>
//# include <algorithm>
//using namespace std;
//int n;
//vector<int> arr;
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int x;
//		cin >> x;
//		arr.push_back(x);
//	}
//	// 오름차순
//	sort(arr.begin(), arr.end());
//	int result = 0;// 그룹수 
//	int cnt = 0; // 그룹에 포함된 모험가수
//	for (int i = 0; i < n; i++) {
//		cnt++;
//		// 모험가수 >= 공포도이면 그룹 결성
//		                                                                                                                                                                     
//		if (cnt >= arr[i]) {
//			result++;
//			cnt = 0;
//		}
//	}
//	cout << result;
//
//}

//---------------------------------------------------------------
// 문자열 뒤집기
/*
문자열 s 안에 같게 만들기
연속된 하나 이상의 숫자 잡고 모두 뒤집기
001100 -> 000000 
경우의수는 0 또는 1
따라서 모두 0으로 치환횟수와 모두 1로 치환횟수 구해 비교
치환 방법
- 변수 cnt0, cnt1 설정
- str[0]에 대한 cnt0, cnt1 처리
- str[i] == str[i+1] ->  cnt0, cnt1 처리
- 두개중 최솟값
*/

//# include <iostream>
//# include <algorithm>
//using namespace std;
//string str;
//
//int cnt0 = 0;
//int cnt1 = 1;
//
//int main() {
//	cin >> str;
//	if (str[0] == '1')cnt0++;
//	else cnt1++;
//
//	for (int i = 1; i< str.size()-1 ; i++) {
//		if (str[i] != str[i + 1]) {
//			if (str[i + 1] == '1')cnt0++;
//			else cnt1++;
//		}
//	}
//	cout << min(cnt0, cnt1);
//}
//----------------------------------------------------------------
// 볼링공고르기, 만들수없는금액, 무지먹방라이브 풀기
