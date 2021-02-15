# include <iostream>
# include <vector>
# include <queue>

// privatequeue 이용하기, 힙 공부하기
// 그리디 기법

/*
우선순위 큐
- 들어간 순서에 상관없이 우선순위가 높은 데이터 먼저 나오는 것
- 힙이라는 자료구조를 가지고 구현함
- 힙은 우선순위 높은 데이터를 루트 노드에 위치
*/

using namespace std;
	
int N;
// 우선순위가 오름차순 , 루트노드가 작은 숫자?
priority_queue<int, vector<int>, greater<int>> Q;


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	/* ios_base::sync_with_stdio(false); 
		- c의 stdio와 cpp의 iostream을 동기화하는 역할
		- 버퍼를 모두 사용하므로 딜레이 발생
		- false로 하면 동기화 비활성화
		- 버퍼 분리로, cin과 C의 scanf, gets, getchar 등을 같이 사용하면 안되고
		  cout과 C의 printf, puts, putchar 등을 같이 사용하면 엉뚱한 결과 나올수있음

       cin.tie(NULL);
	   - cin 과 cout의 묶음을 풀어준다
	   - cin과 cout은 묶여있고 묶여있는 스트림들은 한 스트림이 다른 스트림에서 
	     각 IO 작업을 진행하기 전에 자동으로 버퍼 비워줌 보장

	*/

	cin >> N;
	// 정렬된 묶음이 한개만 들어오면 비교 안함
	if (N == 1) {
		cout << 0 << '\n';
		return 0;
	}
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		Q.push(a);
	}
	int ans = 0;
	// 최대한 작은 애들을 먼저 묶는다
	while (Q.size() > 1) {
		int a = Q.top();
		Q.pop();
		int b = Q.top();
		Q.pop();
		ans += a + b;
		Q.push(a + b);
	}
	cout << ans << '\n';
	return 0;
}