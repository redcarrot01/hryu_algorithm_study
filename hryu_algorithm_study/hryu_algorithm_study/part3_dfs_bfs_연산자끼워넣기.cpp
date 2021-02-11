// 연산자는 operators 라는 4짜리 배열 선언
// 그 후, 백트래킹 사용하여 재귀로 해결
// 매개변수는 여태까지 연산의 result, 연산을 진행할 수의 인덱스를 입력받도록 하는
// 백트래킹 재귀 함수를 정의하여 풀이한다

 // 이문제는 재귀의 흐름과 매개변수를 어떤 값을 사용해야할지 설계하는 능력 필요

#include <iostream>
using namespace std;

int N; // n :2~11
int operands[11]; //수열
int operators[4]; // 연산자 4개니까
int mymin = 1000000001;
int mymax = -1000000001;

// 재귀로
void get_answer(int result, int idx) {
	if (idx == N) {
		if (result > mymax) mymax = result;
		if (result < mymin) mymin = result;
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (operators[i] > 0) {

			operators[i]--; // 연산자 사용하면 1개 줄여주기
			if (i == 0)
				get_answer(result + operands[idx], idx + 1);
			else if (i == 1)
				get_answer(result + operands[idx], idx + 1);
			else if (i == 2)
				get_answer(result * operands[idx], idx + 1);
			else
				get_answer(result / operands[idx], idx + 1);

			operators[i]++; // 다른 연산자를 사용할 것이므로
			// 아까 줄였던 연산자 개수 늘려줌 
		}
	}
	return ;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> operands[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
	}
	get_answer(operands[0], 1);
	cout << mymax << '\n';
	cout << mymin;
}

