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

# include <iostream>
# include <algorithm>

using namespace std;

int n, m;
int arr[8][8]; //초기 맵 배열
int temp[8][8]; // 벽 세운 후 맵 배열

// 4가지 이동 방향에 대한 배열 상 하 우 좌
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int result;

// 깊이 우선 탐색 이용해 각 바이러스가 사방으로 퍼지도록 하기
void virus(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 상하좌우 중 바이러스 퍼질 수 있는 경우
		if (nx >= 0 & nx < n && ny >= 0 && ny < m) {
			if (temp[nx][ny] == 0) {
				// 해당 위치에 바이러스 배치하고 다시 재귀 수행
				temp[nx][ny] = 2;
				virus(nx, ny);
			}
		}
	}
}
// 현재 맵에서 안전 영역 크기 계산
int getScore() {
	int score = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0)
				score += 1;
		}
	}
	return score;
}

// 깊이 우선 탐색을 이용해 울타리 설치하면서, 매번 안전영역 크기 계산
void dfs(int cnt) {
	// 울타리가 3개 설치된 경우, 복사본 맵에 복사
	if (cnt == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp[i][j] = arr[i][j];
			}
		}
		// 각 바이러스의 위치에서 전파 진행
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (temp[i][j] == 2)
					virus(i, j);
			}
		}

		// 안전영역 최대값 계산
		result = max(result, getScore());
		return;
	}


	// 빈 공간에 울타리 설치
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				cnt += 1;
				dfs(cnt);
				arr[i][j] = 0; //dfs 다 돌리고 나서 초기화
				cnt -= 1; // 초기화 해주어야
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(0);
	cout << result << '\n';
}