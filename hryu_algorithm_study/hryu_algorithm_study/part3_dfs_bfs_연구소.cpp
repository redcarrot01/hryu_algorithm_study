/*
1. 이 문제는 완전탐색과 dfs/bfs 2가지 알고리즘 모두 사용
2. 0이 있는 지점에서 만들 수 있는 3개의 벽을 다 만들어본 후에, bfs/dfs를 통해서 바이러스가 있는
	지점에서 바이러스를 모두 퍼뜨린 후, 안전영역의 크기(0)를 count해줘서 최댓값 찾는다
3. 2와 같은 작업을 하기 위해서 맵을 복사하는 과정 필요. 원본맵에 했다가 원본맵 잃어버릴수도
4. 2에서 말한 만들수 있는 3개의 벽 다 만들어본 후 => 조합의 개념 들어간다
모든 0 중에서 3개를 골라야 하니까.. 이 부분 때문에 check[]라는 1차원 배열 사용했고, 
이 배열의 max 크기는 64로 설정(한변 최대길이8, 8*8)
4-1 입력 받을때 0의 갯수 모두 count 해줌. 0 있는 지점 모두 큐에 삽입, 큐의 사이즈가 0의갯수
4-2 조합을 구하고 최종 결과값 구하는 과정 
	1. 모든 0중에서 3개 골라
	2. 원본의 맵을 임시 맵으로 복사 C_MAP
	3. 고른 3개의 0에 대해서, 그 값을 1로 바꾸어준다 (복사한 맵에서)
	4. BFS/DFS를 통해 복사한 맵에서 바이러스 퍼뜨린다
	5. 모두 퍼뜨린 후 남아있는 0의값을 COUNT하고 이전까지의 최대값과 비교하여 갱신
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define endl "\n"
#define MAX 8
using namespace std;

int N, M, Space, Answer;
int MAP[MAX][MAX]; //원본
int C_MAP[MAX][MAX]; // 복사본
bool Check[MAX * MAX]; //0을 3개 고르는 1차 배열
bool Visit[MAX][MAX]; 

int dx[] = { 0,0,1,-1 };
int dy[] = { 1, -1, 0, 0 };

vector<pair<int, int>> Empty, Virus;

int Bigger(int A, int B) { 
	if (A > B) return A; 
	return B; 
}

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 0) Empty.push_back(make_pair(i, j));
			else if (MAP[i][j] == 2) Virus.push_back(make_pair(i, j));
		}

	}
	Space = Empty.size();
}
void Copy_MAP() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			C_MAP[i][j] = MAP[i][j];
		}
	}
}

void BFS(int a, int b) {
	queue<pair<int, int>> Q;
	Q.push(make_pair(a, b));
	Visit[a][b] = true; // 방문 표시 여기서

	while (Q.empty() == 0) {
		int x = Q.front().first;
		int y = Q.front().second;  //0일때 그 지점을 시작으로 탐색할 것임
		Q.pop();

		for (int i = 0; i < 4; i++) {  //탐색
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M) { // 그 지점의 인접 지점 살피기
				if (Visit[nx][ny] == false && C_MAP[nx][ny] == 0) {  // 방문안했고, 복사본 맵이 0이라면
					C_MAP[nx][ny] = 2; // 바이러스 퍼뜨려
					Visit[nx][ny] = true; // 방문 함
					Q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int Count_Safe_Area() { // 0인지점 찾는거지
	int Cnt = 0;
	for(int i =0; i< N; i++){
			for (int j = 0; j < M; j++) {
				if (C_MAP[i][j] == 0) Cnt++;
			 }
	}
	return Cnt;
}

void Spread_Virus() { // 바이러스 퍼뜨리는거지
	int Cnt = 0;
	Copy_MAP();
	memset(Visit, false, sizeof(Visit)); // 일단 방문하지 않은 걸로 초기화
	for (int i = 0; i < Space; i++) { // 방문하지 않은 큐의 사이즈
		if (Cnt == 3) break;
		if (Check[i] == true) { // 0이라면
			int x = Empty[i].first;
			int y = Empty[i].second;
			C_MAP[x][y] = 1;
			Cnt++;

		}
	} // 0을 3개 고르는 과정

	for (int i = 0; i < Virus.size(); i++) { 
		int x = Virus[i].first;
		int y = Virus[i].second;
		BFS(x, y);

	}
	//for문 다 돌리면 0의 개수 최댓값 찾기
	int Temp_Answer = Count_Safe_Area();
	Answer = Bigger(Answer, Temp_Answer);
}


void Make_Wall(int Idx, int Cnt) {
	if (Cnt == 3) {
		Spread_Virus();
		return;
	}
	for (int i = Idx; i < Space; i++) //Q의 비어있는 사이즈 만큼
	{
		if (Check[i] == true) continue; //1이면 벽이 있으니까 
		Check[i] = true; 
		Make_Wall(i, Cnt + 1);
		Check[i] = false;
	}

}

void Solution()
{
	Make_Wall(0, 0);
}

void Solve()
{
	Input();
	Solution();
	cout << Answer << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//    freopen("Input.txt", "r", stdin);
	Solve();

	return 0;
}


