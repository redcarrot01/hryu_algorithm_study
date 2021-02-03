# include <stdio.h>
# include <iostream>
# include <vector>
# include <string>

using namespace std;

int solution(string s) {
	int answer = s.size();
	// 1개 단위부터 압축단위 늘려가면서 확인
	for (int step = 1; step < s.size() / 2; step++) {
		string comp = "";
		string pre = s.substr(0, step); //앞에서부터 step만큼의 문자열 추출
		int cnt = 1;
		// 단위 (step)크기 만큼 증가시키며 이전 문자열과 비교
		for (int j = step; j < s.size(); j += step) {
			//이전 상태와 동일하다면 압축횟수추가
			if (pre == s.substr(j, step)) cnt += 1;
			//다른 문자열이 나왔다면
			else {
				comp += (cnt >= 2) ? to_string(cnt) + pre : pre;
				pre = s.substr(j, step); // 다시 상태 초기화
				cnt = 1;
			}
		}
	}
}


