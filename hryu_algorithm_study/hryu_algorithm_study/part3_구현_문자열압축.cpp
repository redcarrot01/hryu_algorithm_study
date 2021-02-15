# include <stdio.h>
# include <iostream>
# include <vector>
# include <string>


using namespace std;
/*
1. 문자열 자르는 단위를 1부터 시작해서 모두 해보면 된다
단위가 문자열의 길이의 반보다 커지면 절대 더 압축되지 않으므로 1~문자열길이/2 까지만 함

2. i개로 자른다고 했을 떄, 문자열의 처음부터 i개만큼씩을 문자열 끝까지 계속 검사
(i개로 나누어 떨어지지 않고, 남은 부분은 마지막에 추가적으로 붙여준다)

3. i개로 자른 문자열이 바로 이어서 나타난다면, cnt 값을 증가시킨다
그렇지 않다면, 압축된 결과를 저장할 문자열(result)에 문자열 단위를 붙여주고
문자열 단위를 새로 j번부터 i개로 업데이트한다
이떄, 문제 조건에 따라서 이 문자열 단위가 여러 개였다면(cnt > 1) cnt를 문자열 앞에
붙여서 result에 추가하고 cnt=1로 다시 초기화한다
 
*/


int solution(string s) {
	int len = s.size(); //문자열 전체 길이
	int answer = len; // 처음 문자열 상태
	int n = len / 2; // 단위 최대 길이

	//i개 단위로 잘라서 압축
	for (int i = 1; i <= n; i++) {
		int len = s.length();

		// i개 단위로 잘라서 압축한 뒤 만들어지는 문자열
		string result = "";

		// 자를 문자열 단위
		string ss = s.substr(0, i);

		int cnt = 1;

		// 앞에서 자른 문자열 단위를 제외한 뒷부분 (j번 문자부터) 문자열을 검사
		for (int j = i; j <= len; j += i) {
			// j번 부터 i개 만큼이 문자열 단위와 똑같은 경우 cnt 증가
			if (ss == s.substr(j, i)) {
				cnt += 1;
			}
			else {
				// 다른 경우 중 cnt가 1이면 result에 그대로 ss를 붙인다
				if (cnt == 1) {
					result += ss;
				}
				else {
					// cnt가 1보다 크다면 cnt를 문자열 단위 앞에 붙여서 result에 이어준다
					result += (to_string(cnt) + ss);
				}
				// 문자열 단위를 j 번 부터 i 개로 변경
				ss = s.substr(j, i);
				// cnt 값 다시 1로 초기화
				cnt = 1;
			}
		}

		// 문자열이 i로 나누어 떨어지지 않는다면 result에 나머진 부분을 붙여줘야 한다
		if ((len % i) != 0) {
			result += s.substr((len / i) * i);
		}
		// 최솟값을 answer 에 저장
		if (answer > result.size()) answer = result.size();
	}
	return answer;
}























// 모르겠다 나중에 풀기

//// to_string : int to string
//using namespace std;
//
//
//int solution(string s) {
//    int answer = s.length();
//    //경우의 수 탐색하기
//    for (int i = 1; i <= s.length() / 2; i++) {
//        int len = s.length();
//        //문자열을 전체 돌면서 반복
//        for (int j = 0; j < s.length(); j++) {
//            //부분 비교하기
//            for (int count = 0, z = i; j + z < s.length(); z += i) {
//                //뒤부분과 일치한다면 count 증가
//                if (s.substr(j, i) == s.substr(j + z, i))    count++;
//
//
//                // ```````````````` 여기까지 이해''''''''''''''''''''
//
//                //뒤에부분이 일치하지않는다면 count확인후 중복되는 문자열만큼 길이줄임
//                //추가되는 숫자만큼 길이증가
//                else {
//                    len -= i * count;
//                    if (count)     len += to_string(count + 1).length();
//                    j += z - 1;
//                    break;
//                }
//                // 한번이라도 압축이 된상태에서 뒤에가 계산이 안된다면
//                //압축후 추가하고 나머지를 뒤에 추가
//                if (j + z + i >= s.length()) {
//                    len -= i * count;
//                    len += to_string(count + 1).length();
//                    j += z;
//                }
//            }
//        }
//        //문자열 길이를 비교해서 적어진다면 적은걸로 변경
//        if (len < answer)    answer = len;
//    }
//    return answer;
//}
//
//
//
//
//void print(string s, int answer) {
//    int t = solution(s);
//    if (answer == t)
//        cout << "정답" << endl;
//    else
//        cout << "틀림" << endl;
//}
//
//int main() {
//    print("a", 1);
//    print("aaaaa", 2);
//    print("aaaaaaaaaa", 3);
//    print("aabbaccc", 7);
//    print("ababcdcdababcdcd", 9);
//    print("abcabcdede", 8);
//    print("abcabcabcabcdededededede", 14);
//    print("xababcdcdababcdcd", 17);
//    return 0;
//}

