/*
1. �� ������ ����Ž���� dfs/bfs 2���� �˰��� ��� ���
2. 0�� �ִ� �������� ���� �� �ִ� 3���� ���� �� ���� �Ŀ�, bfs/dfs�� ���ؼ� ���̷����� �ִ�
	�������� ���̷����� ��� �۶߸� ��, ���������� ũ��(0)�� count���༭ �ִ� ã�´�
3. 2�� ���� �۾��� �ϱ� ���ؼ� ���� �����ϴ� ���� �ʿ�. �����ʿ� �ߴٰ� ������ �Ҿ��������
4. 2���� ���� ����� �ִ� 3���� �� �� ���� �� => ������ ���� ����
��� 0 �߿��� 3���� ���� �ϴϱ�.. �� �κ� ������ check[]��� 1���� �迭 ����߰�, 
�� �迭�� max ũ��� 64�� ����(�Ѻ� �ִ����8, 8*8)
4-1 �Է� ������ 0�� ���� ��� count ����. 0 �ִ� ���� ��� ť�� ����, ť�� ����� 0�ǰ���
4-2 ������ ���ϰ� ���� ����� ���ϴ� ���� 
	1. ��� 0�߿��� 3�� ���
	2. ������ ���� �ӽ� ������ ���� C_MAP
	3. �� 3���� 0�� ���ؼ�, �� ���� 1�� �ٲپ��ش� (������ �ʿ���)
	4. BFS/DFS�� ���� ������ �ʿ��� ���̷��� �۶߸���
	5. ��� �۶߸� �� �����ִ� 0�ǰ��� COUNT�ϰ� ���������� �ִ밪�� ���Ͽ� ����
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define endl "\n"
#define MAX 8
using namespace std;

int N, M, Space, Answer;
int MAP[MAX][MAX]; //����
int C_MAP[MAX][MAX]; // ���纻
bool Check[MAX * MAX]; //0�� 3�� ���� 1�� �迭
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
	Visit[a][b] = true; // �湮 ǥ�� ���⼭

	while (Q.empty() == 0) {
		int x = Q.front().first;
		int y = Q.front().second;  //0�϶� �� ������ �������� Ž���� ����
		Q.pop();

		for (int i = 0; i < 4; i++) {  //Ž��
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M) { // �� ������ ���� ���� ���Ǳ�
				if (Visit[nx][ny] == false && C_MAP[nx][ny] == 0) {  // �湮���߰�, ���纻 ���� 0�̶��
					C_MAP[nx][ny] = 2; // ���̷��� �۶߷�
					Visit[nx][ny] = true; // �湮 ��
					Q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int Count_Safe_Area() { // 0������ ã�°���
	int Cnt = 0;
	for(int i =0; i< N; i++){
			for (int j = 0; j < M; j++) {
				if (C_MAP[i][j] == 0) Cnt++;
			 }
	}
	return Cnt;
}

void Spread_Virus() { // ���̷��� �۶߸��°���
	int Cnt = 0;
	Copy_MAP();
	memset(Visit, false, sizeof(Visit)); // �ϴ� �湮���� ���� �ɷ� �ʱ�ȭ
	for (int i = 0; i < Space; i++) { // �湮���� ���� ť�� ������
		if (Cnt == 3) break;
		if (Check[i] == true) { // 0�̶��
			int x = Empty[i].first;
			int y = Empty[i].second;
			C_MAP[x][y] = 1;
			Cnt++;

		}
	} // 0�� 3�� ���� ����

	for (int i = 0; i < Virus.size(); i++) { 
		int x = Virus[i].first;
		int y = Virus[i].second;
		BFS(x, y);

	}
	//for�� �� ������ 0�� ���� �ִ� ã��
	int Temp_Answer = Count_Safe_Area();
	Answer = Bigger(Answer, Temp_Answer);
}


void Make_Wall(int Idx, int Cnt) {
	if (Cnt == 3) {
		Spread_Virus();
		return;
	}
	for (int i = Idx; i < Space; i++) //Q�� ����ִ� ������ ��ŭ
	{
		if (Check[i] == true) continue; //1�̸� ���� �����ϱ� 
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


