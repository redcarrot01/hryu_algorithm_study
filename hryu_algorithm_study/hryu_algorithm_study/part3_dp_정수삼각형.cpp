//sol1 : bottom up 반복문
#include <string>
# include <vector>
#define max_int 501

using namespace std;

/*
시간복잡도 O(N*N) = O(250000)
알고리즘 DP
자료구조 2차배열
*/
int answer, height, d[max_int][max_int];

int max(int a, int b) {
	return a > b ? a : b;
}

int solution(vector<vector<int>> tri) {
	//예외 사례, 초기값을 설정
	answer = d[0][0] = tri[0][0];
	// 삼각형 높이
	height = (int)tri.size();

	// 맨 위층의 한 점은 위에서 예외처리
	for (int i = 1; i < height; i++) {
		for (int j = 0; j <= i; j++) {
			// 삼각형 왼쪽 끝
			if (j == 0) {
				d[i][j] = d[i - 1][j] + tri[i][j];
			}
			// 삼각형 오른쪽 끝
			else if (j == i) {
				d[i][j] = d[i - 1][j - 1] + tri[i][j];
			}
			// 삼각형 왼쪽 , 오른쪽 끝이 아닌 내부
			else {
				d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + tri[i][j];
			}
			// 갱신
			answer = max(answer, d[i][j]);
		}

	}
	return answer;
}
