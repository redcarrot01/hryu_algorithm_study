// 럭키스트레이트
/*
정수n을 반으로 나누어 왼쪽부분합 == 오른부분합 
-> 동일 상황을 만족하면 럭키

입력 정수 n (10 ~ 99,999,999) , 짝수
*/
//# include <iostream>
//using namespace std;
//
//string str;
//int summary = 0;
//
//int main() {
//	cin >> str;
//
//	// 왼쪽 부분 합
//	for (int i = 0; i < str.size() / 2; i++) {
//		summary += str[i] - '0';
//	}
//	// 오른쪽 부분 합
//	for (int i = 0; i < str.size() / 2; i++) {
//		summary -= str[i] - '0';
//	}
//
//	// 왼쪽 부분과 오른쪽 부분의 자릿수 합이 동일한지 검사
//	if (summary == 0) cout << "LUCKY";
//	else cout << "READY";
//}

// 문자열 압축
/*
같은 값 연속 -> 그 문자의 개수와 반복되는 값으로 표현
더 짧은 문자열로 줄여서 표현하는 알고리즘 
입력 : s(1~1000), s는 소문자

aabbaccc -> 2a2ba3c  7
ababcdcdababcdcd -> 2ab2cd2ab2cd  // 2ababcdcd (가장 짧은 압축) 9
xababcdcdababcdcd  17
abcabcdede -> 2abcdede 8
문자열은 앞에서 부터 축약된다


sol
1. 문자열 자르는 단위를 1부터 시작해서 모두 해본다
	단위가 문자열 길이의 반보다 커지면 안되니까 1~문자열길이/2 까지

2. i개로 자른다 했을 때, 문자열의 처음부터 i개씩 만큼 문자열 끝까지 계속 검사
	(i개로 나누어 떨어지지 않는부분은 남은 부분은 마지막에 추가적으로 붙여줌)

3. i개로 자른 문자열이 바로 이어서 나타난다면, cnt 값을 증가시킨다
	그렇지 않다면, 압축된 결과를 저장할 문자열에 문자열 단위 붙여주고,
	문자열 단위를 새로 j번부터 i개로 update
	이때, 문자열 단위가 cnt >1이라면, cnt를 문자열 앞에 붙여서
	result에 추가하고 cnt=1로 다시 초기화

*/

//# include <iostream>
//# include <vector>
//# include <string>
//
//
//using namespace std;
//
//int solution(string s) {
//	int len = s.size(); // 문자열 전체 길이
//	int answer = len;  // 처음 문자열 상태
//	int n = len / 2;
//
//	// i개 단위로 잘라서 압축
//	for (int i = 1; i <= n; i++) {
//		int len = s.length();
//
//		// i개 단위로 잘라서 압축한 뒤 만들어지는 문자열
//		string result = "";
//
//		// 자를 문자열 단위
//		string ss = s.substr(0, i);
//
//		int cnt = 1;
//
//		// 앞에서 자른 문자열 단위를 제외한 뒷부분(j번 문자부터) 문자열 검사
//		for (int j = i; j <= len; j += i) {
//			//j번부터 i개만큼 문자열단위와 똑같은경우 cnt 증가
//			if (ss == s.substr(j, i)) {
//				cnt += 1;
//			}
//			else {
//				// 다른 경우 중 cnt가 1이면 result에 그대로 ss를 붙인다
//				if (cnt == 1) {
//					result += ss;
//				}
//				else {
//					// cnt가 1보다 크다면 cnt를 문자열 단위 앞에 붙여서 result에 이어줌
//					result += (to_string(cnt) + ss);
//				}
//				// 문자열 단위를 j번부터 i개로 변경
//				ss = s.substr(j, i);
//				cnt = 1;
//			}
//		}
//		// 문자열이 i로 나누어 떨어지지 않는다면 result에 나머지 부분 붙인다
//		if ((len % i) != 0) {
//			result += s.substr((len / i) * i);
//		}
//		// 최솟값을 answer에 저장
//		if (answer > result.size()) answer = result.size();
//	}
//	return answer;
//}


// 외벽점검
/*
친구들은 시계/반시계로 돌수 있음
n (1~ 200)
weak의 길이(1~15), weak의 원소 (0~n-1)
dist의 길이(1~8), dist의 원소 1~100
전부 점검 불가 -1 c출력
*/
// 나중에 