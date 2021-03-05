// 탐색
/*
스택 filo
큐 fifo
재귀함수 
- 재귀의 경우 종료 조건 명시 필요
- 유클리드 호제법
- 스택 대신 재귀 사용 -> 함수 호출 연속으로 스택에 쌓임

dfs
- 깊이 우선 탐색
- 스택 자료구조를 이용
	- 탐색 시작 노드를 스택에 삽입하고 방문 처리
	- 스택의 최상단 노드에 방문하지 않은 인접 노드 있으면 스택에 넣고 방문 처리
	  방문핮 ㅣ않은 인접노드 없다면 스택에서 최상단 노드 꺼내기
	- 두번째 과정 반복

bfs
- 너비 우선 탐색
- 큐 이용
	- 탐색 시작 노드를 큐에 삽입하고 방문 처리
	- 큐에서 노드 꺼낸 뒤 해당 노드의 인접 노드 중 방문핮 ㅣ않았다면
	  노드 모두 큐에 삽입 그리고 방문 처리
	- 두번쨰 반복
*/

// dfs 예제
//# include <iostream>
//# include <vector>
//
//using namespace std;
//
//bool visited[9];
//vector <int> graph[9];
//
//// 스택은 리스트 자료형 이용
//
//// dfs 
//void dfs(int x) {
//    // 현재 노드를 방문 처리
//    visited[x] = true;
//    cout << x << ' ';
//    // 현재 노드와 연결된 다른 노드 재귀 방문
//    for (int i = 0; i < graph[x].size(); i++) {
//        int y = graph[x][i];
//        if (!visited[y]) dfs(y);
//    }
//}
//
//int main() {
//	graph[1].push_back(2);
//	graph[1].push_back(3);
//    graph[1].push_back(8);
//
//    graph[2].push_back(1);
//    graph[2].push_back(7);
//
//    graph[3].push_back(1);
//    graph[3].push_back(4);
//    graph[3].push_back(5);
//
//    graph[4].push_back(3);
//    graph[4].push_back(5);
//
//    graph[5].push_back(3);
//    graph[5].push_back(4);
//
//    graph[6].push_back(7);
//
//    graph[7].push_back(2);
//    graph[7].push_back(6);
//    graph[7].push_back(8);
//
//    graph[8].push_back(1);
//    graph[8].push_back(7);
//
//    dfs(1);
//} // 1 2 7 6 8 3 4 5

// bfs
/*
1 탐색 시작 노드를 큐에 삽입하고 방문 처리
2 큐에서 노드를 꺼낸 뒤 해당 노드의 인접 노드 중 방문하지 않았다면
   노드 모듀 큐에 삽입, 방문 처리
3 반복
*/
//# include <iostream>
//# include <vector>
//# include <queue>
//using namespace std;
//
//bool visited[9];
//vector<int> graph[9];
//
//
//void bfs(int start) {
//    queue<int> q;
//    q.push(start);
//
//    //현재 노드를 방문 처리
//    visited[start] = true;
//    // 큐가 빌때까지 반복
//    while (!q.empty()) {
//        // 큐에서 하나의 원소 뽑아 출력
//        int x = q.front();
//        q.pop();
//        cout << x << " ";
//
//        // 인접 노드 방문하고 큐에 삽입
//        for (int i = 0; i < graph[x].size(); i++) {
//            int y = graph[x][i];
//            if (!visited[y]) {
//                q.push(y); 
//                visited[y] = true;
//            }
//        }
//    }
//
//} // 1 2 3 8 7 4 5 6
//
//int main() {
//    graph[1].push_back(2);
//    graph[1].push_back(3);
//    graph[1].push_back(8);
//
//    graph[2].push_back(1);
//    graph[2].push_back(7);
//
//    graph[3].push_back(1);
//    graph[3].push_back(4);
//    graph[3].push_back(5);
//
//    graph[4].push_back(3);
//    graph[4].push_back(5);
//
//    graph[5].push_back(3);
//    graph[5].push_back(4);
//
//    graph[6].push_back(7);
//
//    graph[7].push_back(2);
//    graph[7].push_back(6);
//    graph[7].push_back(8);
//
//    graph[8].push_back(1);
//    graph[8].push_back(7);
//
//    bfs(1);
//}

// 음료수 얼려먹기

/*
n*m 구멍뚫려있는 0, 칸막이 1
n,m 1~1000
한번에 만들수있는 아이스크림개수 
00110
00011
11111
00000   -> 3개 가능

팁
1. 상하좌우 살피기 -> 0이면서 방문하지 않았다면 방문
2. 방문지점에서 과정 반복
3. 방문안 한 지점 수 카운트
*/
//#include <stdio.h>
//#include <iostream>
//using namespace std;
//
//int n, m;
//int graph[1001][1001];
//
//// dfs로 특정 노드를 방문하고 연결된 모든 노드들도 방문
//bool dfs(int x, int y) {
//	// 주어진 범위 벗어나는 경우에는 즉시 종료
//	if (x < 0 || x >= n || y < 0 || y >= m) {
//		return false;
//	}
//	// 현재 노드를 아직 방문하지 않는다면
//	if (graph[x][y] == 0) {
//		// 방문 처리
//		graph[x][y] = 1;
//		// 상하좌우
//		dfs(x - 1, y);
//		dfs(x, y - 1);
//		dfs(x + 1, y);
//		dfs(x, y + 1);
//		return true;
//	}
//	return false;
//}
//
//int main() {
//	cin >> n >> m;
//
//	// 2차원 리스트의 맵 정보 입력, 
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j <m ; j++) {
//			scanf_s("%1d", &graph[i][j]);
//			// 위치매개변수 1은 다닥다닥 붙어있는 입력처리 위함
//		}
//	}
//	// 모든 노드에 대하여 음료수 채우기
//	int result = 0;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			// 현재 위치에서 dfs 수행
//			if (dfs(i, j)) result += 1;
//		}
//	}
//	cout << result << '\n';
//}




// 미로탈출
/*
(1,1) -> (N,M)으로 도착
괴물o 0, 괴물x 1
탈출하기 위해 움직여야 하는 최소한의 개수

n,m 1~200
수들은 공백없이 주어짐

팁 
bfs => 시작노드에서 가까운노드부터 차례대로 그래프의 모든노드 탐색
*/
//# include <stdio.h>
//# include <iostream>
//# include <queue>
//
//using namespace std;
//
//int n, m;
//int graph[201][201];
//
//// 방향 상하좌우
//
//int dx[] = { -1, 1, 0, 0 };
//int dy[] = { 0, 0, -1, 1 };
//
//int bfs(int x, int y) {
//	queue<pair<int, int>> q;
//	q.push({ x,y });
//
//	while (!q.empty()) {
//		int x = q.front().first; // (1,2) -> 1
//		int y = q.front().second; // (1,2) -> 2
//		q.pop();
//		// 현재 위치에서 4가지 방향으로의 위치
//		for (int i = 0; i < 4; i++) {
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
//				continue;
//			if (graph[nx][ny] == 0)
//				continue;
//
//			//해당 노드를 처음 방문하는 경우 최단 거리 기록
//			if (graph[nx][ny] == 1) {
//				graph[nx][ny] = graph[x][y] + 1;
//				q.push({ nx, ny });
//			}
//		}
//	}
//	// 가장 오른쪽 아래까지의 최단 거리 방문
//	return graph[n - 1][m - 1];
//}
//
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			scanf_s("%1d", &graph[i][j]);
//		}
//	}
//	cout << bfs(0, 0) << '\n';
//	return 0;
//}

// 연산자 끼워넣기
/*
n 2~11
a 1~100
+ - * /  총 n-1개의 정수

출력 : 최댓값, 최솟값 -10억 ~10억

// 연산자는 operators라는 4짜리 배열 선언
그 후, 백트래킹 사용하여 재귀 해결
매개변수는 여태까지 연산의 result, 연산을 진행할 수의 인덱스 입력받도록 하는 
백트래킹 재귀 함수 정의하여 풀이

재귀의 흐름과 매개변수 어떤 값을 사용할지 설계하는 능력 필요

2
5 6 
0 0 1 0    ->  30 30

3
3 4 5
1 0 1 0  ->	 35 17

*/
//
//# include <iostream>
//using namespace std;
//
//int N; // n 2~11
//int operands[11];
//int operators[4];
//int mymin = 1000000001;
//int mymax = -1000000001;
//
//// 재귀로
//void get_answer(int result, int idx) {
//	if (idx == N) { // 연산자 다 사용
//		if (result > mymax) mymax = result;
//		if (result < mymin) mymin = result;
//	}
//
//	for (int i = 0; i < 4; i++) {
//		if (operators[i] > 0) { // 그 인덱스에 연산자 살아있다면
//			operators[i]--; // 연산자 사용하면 한개 줄여줘
//			if (i == 0)
//				get_answer(result + operands[idx], idx + 1);
//			else if (i == 1)
//				get_answer(result - operands[idx], idx + 1);
//			else if (i == 2)
//				get_answer(result * operands[idx], idx + 1);
//			else
//				get_answer(result / operands[idx], idx + 1);
//
//			operators[i]++; // 다른 연산자 사용할 것이므로 
//			// 아까 줄였던 연산자 개수 늘려줌
//		}
//	}
//	return;
//}
//
//int main() {
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> operands[i];
//	}
//	for (int i = 0; i < 4; i++) {
//		cin >> operators[i];
//	}
//	get_answer(operands[0], 1); // idx는 연산자 개수, 1개부터 시작이니까
//	cout << mymax << '\n';
//	cout << mymin << '\n';
//
//}


// N-QUEEN 백준 9663 백트래킹 문제
//# include <stdio.h>
//# include <iostream>
//
//int cnt = 0;
//int n;
//int board[15];
//
//// 유망한지 판단하는 함수
//int promising(int cdx) {
//
//	// 같은 열이면 안되고, 대각선상에 있어서도 안 된다
//	for (int i = 0; i < cdx; i++) { // 대각선상 : cdx 행 - 앞 행 == cdx 열 -  앞 행의 열
//		if (board[cdx] == board[i] || cdx - i == abs(board[cdx] - board[i]))
//			return 0;
//	}	
//	return 1;
//}
//// 백트래킹 알고리즘 수행
//void nqueen(int cdx) {
//
//	// cdx가 마지막 행까지 수행하고 여기까지 오면 찾기 완료
//	if (cdx == n)
//	{
//		cnt++;
//		return;
//	}
//	for (int i = 0; i < n; i++) {
//		board[cdx] = i;  //cdx번째 행, i번째 열에 퀸을 놓아본다
//		// 이후 그 행에 둔 것에 대한 유망성 판단
//		if (promising(cdx)) // 그자리에 두어도 오케이라면
//			nqueen(cdx + 1); // 그 다음행에 퀸 놓기 시도
//
//	}
//
//}
//int main() {
//	scanf_s("%d", &n);
//	nqueen(0);
//	printf("%d", cnt);
//}

// 연구소
/*
연구소 n* m
0 빈칸 1 벽 2 바이러스
안전영역 최대 크기를 출력하라

팁
1. 이 문제는 완전탐색, dfs.bfs 다 사용
2. 0이 있는 지점에서 만들 수 있는 3개의 벽을 다 만들어본 후에
bfs.dfs를 통해 바이러스가 있는 지점에서 바이러스 모두 퍼뜨린 후, 
안전영역크기를 cnt해줘서 최댓값 찾는다
3. 2와 같은 과정을 위해 맵 복사 필요
4. 2에서 만들 수 있는 벽 다 만들기 -> 조합으로 해결
모든 0 중에서 3개를 골라야 하니까 이 부분 떄문에 check[] 1차원 배열 , 배열 max크기 64
4-1 입력받을 때 0의 갯수 모두 카운트
	0있는 지점 모두 큐에 삽입
	큐의 사이즈가 0의 갯수
4-2 조합구하고 최종 결과값 구하는 과정
	1 모든 0 중 3개 골라
	2 원본 맵을 임시 맵에 복사
	3 고른 3개의 0에 대해, 그 값을 1로 바꿈(복사한 맵에서)
	4 bfs/dfs 바이러스 퍼뜨림
	5 모두 퍼뜨린 후, 남아있는 0의 값 카운트, 이전까지의 최댓값과 비교 갱신
*/

//# include <cstring>
//# include <vector>
//# include <iostream>
//# include <queue>
//
//# define endl "\n"
//# define MAX 8
//using namespace std;
//
//int N, M, Space, Answer;
//int MAP[MAX][MAX]; // 원본
//int C_MAP[MAX][MAX]; // 복사본
//bool Check[MAX * MAX]; // 0을 3개 고르는 1차 배열
//bool Visit[MAX][MAX];
//
//// 하 상 우 좌
//int dx[] = { 0,0,1,-1 };
//int dy[] = { 1,-1,0,0 };
//
//vector<pair<int, int>> Empty, Virus;
//
//// 아마도 안전영역 크기 일듯
//int Bigger(int A, int B) {
//	if (A > B) return A;
//	return B;
//}
//
//void Input() {
//	cin >> N >> M;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> MAP[i][j];
//			if (MAP[i][j] == 0) Empty.push_back(make_pair(i, j));
//			else if (MAP[i][j] == 2) Virus.push_back(make_pair(i, j));
//		}
//
//	}
//	Space = Empty.size();
//}
//
//void Copy_MAP() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			C_MAP[i][j] = MAP[i][j];
//		}
//	}
//}
//
//void BFS(int a, int b) {
//	queue<pair<int, int >> q;
//	q.push(make_pair(a, b));
//	Visit[a][b] = true; // 방문 표시
//
//	while (q.empty() == 0) {
//		int x = q.front().first;
//		int y = q.front().second; // 0일때 그 지점 시작으로 탐색할 것임
//		q.pop();
//
//		for (int i = 0; i < 4; i++) { // 탐색
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//
//			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
//				// 그 지점의 인접 지점 살피기
//				if (Visit[nx][ny] == false && C_MAP[nx][ny] == 0) {
//					// 방문안했고 복사본맵이0이라면
//					C_MAP[nx][ny] = 2; // 바이러스 퍼뜨려
//					Visit[nx][ny] = true; // 방문 함
//					q.push(make_pair(nx, ny)); //q에는 바이러스만 쌓이겠지?
//				}
//			}
//		}
//	}
//}
//int Count_Safe(){ // 0 인지점 찾기
//	int cnt = 0;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			if (C_MAP[i][j] == 0) cnt++;
//		}
//	}
//	return cnt;
//}
//
//void Spread_Virus() {
//	int cnt = 0;
//	Copy_MAP();
//	memset(Visit, false, sizeof(Visit)); // 일단 방문하지 않은 걸로 초기화
//	for (int i = 0; i < Space; i++) {// 방문하지 않은 큐의 사이즈
//		if (cnt == 3) break;
//		if (Check[i] == true) { //0이라면
//			int x = Empty[i].first;
//			int y = Empty[i].second;
//			C_MAP[x][y] = 1; //방문표시
//			cnt++;
//		}
//	}// 0을 3개 고르는 과정
//
//	for (int i = 0; i < Virus.size(); i++) {
//		int x = Virus[i].first;
//		int y = Virus[i].second;
//		BFS(x, y);
//	}
//	// for문 다 돌리면 0의 개수 최댓값 찾기
//	int T_Answer = Count_Safe();
//	Answer = Bigger(Answer, T_Answer);
//
//}
//void Make_Wall(int Idx, int cnt) {
//	if (cnt == 3) {
//		Spread_Virus();
//		return;
//	}
//	for (int i = Idx; i < Space; i++) { //q의 비어있는 사이즈 만큼
//		if (Check[i] == true) continue;
//		Check[i] = true;
//		Make_Wall(i, cnt + 1);
//		Check[i] = false;
//
//	}
//}
//void Solution()
//{
//	Make_Wall(0, 0);
//}
//
//void Solve()
//{
//	Input();
//	Solution();
//	cout << Answer << endl;
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	//    freopen("Input.txt", "r", stdin);
//	Solve();
//
//	return 0;
//}

//  연구소 나중에 다시
// 연구소 2번째 버전 풀이

