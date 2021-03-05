// ������
/*
������ n* m
0 ��ĭ 1 �� 2 ���̷���
�������� �ִ� ũ�⸦ ����϶�

��
1. �� ������ ����Ž��, dfs.bfs �� ���
2. 0�� �ִ� �������� ���� �� �ִ� 3���� ���� �� ���� �Ŀ�
bfs.dfs�� ���� ���̷����� �ִ� �������� ���̷��� ��� �۶߸� ��,
��������ũ�⸦ cnt���༭ �ִ� ã�´�
3. 2�� ���� ������ ���� �� ���� �ʿ�
4. 2���� ���� �� �ִ� �� �� ����� -> �������� �ذ�
��� 0 �߿��� 3���� ���� �ϴϱ� �� �κ� ������ check[] 1���� �迭 , �迭 maxũ�� 64
4-1 �Է¹��� �� 0�� ���� ��� ī��Ʈ
	0�ִ� ���� ��� ť�� ����
	ť�� ����� 0�� ����
4-2 ���ձ��ϰ� ���� ����� ���ϴ� ����
	1 ��� 0 �� 3�� ���
	2 ���� ���� �ӽ� �ʿ� ����
	3 �� 3���� 0�� ����, �� ���� 1�� �ٲ�(������ �ʿ���)
	4 bfs/dfs ���̷��� �۶߸�
	5 ��� �۶߸� ��, �����ִ� 0�� �� ī��Ʈ, ���������� �ִ񰪰� �� ����
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
//int MAP[MAX][MAX]; // ����
//int C_MAP[MAX][MAX]; // ���纻
//bool Check[MAX * MAX]; // 0�� 3�� ���� 1�� �迭
//bool Visit[MAX][MAX];
//
//// �� �� �� ��
//int dx[] = { 0,0,1,-1 };
//int dy[] = { 1,-1,0,0 };
//
//vector<pair<int, int>> Empty, Virus;
//
//// �Ƹ��� �������� ũ�� �ϵ�
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
//	Visit[a][b] = true; // �湮 ǥ��
//
//	while (q.empty() == 0) {
//		int x = q.front().first;
//		int y = q.front().second; // 0�϶� �� ���� �������� Ž���� ����
//		q.pop();
//
//		for (int i = 0; i < 4; i++) { // Ž��
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//
//			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
//				// �� ������ ���� ���� ���Ǳ�
//				if (Visit[nx][ny] == false && C_MAP[nx][ny] == 0) {
//					// �湮���߰� ���纻����0�̶��
//					C_MAP[nx][ny] = 2; // ���̷��� �۶߷�
//					Visit[nx][ny] = true; // �湮 ��
//					q.push(make_pair(nx, ny)); //q���� ���̷����� ���̰���?
//				}
//			}
//		}
//	}
//}
//int Count_Safe(){ // 0 ������ ã��
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
//	memset(Visit, false, sizeof(Visit)); // �ϴ� �湮���� ���� �ɷ� �ʱ�ȭ
//	for (int i = 0; i < Space; i++) {// �湮���� ���� ť�� ������
//		if (cnt == 3) break;
//		if (Check[i] == true) { //0�̶��
//			int x = Empty[i].first;
//			int y = Empty[i].second;
//			C_MAP[x][y] = 1; //�湮ǥ��
//			cnt++;
//		}
//	}// 0�� 3�� ���� ����
//
//	for (int i = 0; i < Virus.size(); i++) {
//		int x = Virus[i].first;
//		int y = Virus[i].second;
//		BFS(x, y);
//	}
//	// for�� �� ������ 0�� ���� �ִ� ã��
//	int T_Answer = Count_Safe();
//	Answer = Bigger(Answer, T_Answer);
//
//}
//void Make_Wall(int Idx, int cnt) {
//	if (cnt == 3) {
//		Spread_Virus();
//		return;
//	}
//	for (int i = Idx; i < Space; i++) { //q�� ����ִ� ������ ��ŭ
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

//  ������ ���߿� �ٽ�
// ������ 2��° ���� Ǯ��

# include <iostream>
# include <algorithm>

using namespace std;

int n, m;
int arr[8][8]; //�ʱ� �� �迭
int temp[8][8]; // �� ���� �� �� �迭

// 4���� �̵� ���⿡ ���� �迭 �� �� �� ��
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int result;

// ���� �켱 Ž�� �̿��� �� ���̷����� ������� �������� �ϱ�
void virus(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		// �����¿� �� ���̷��� ���� �� �ִ� ���
		if (nx >= 0 & nx < n && ny >= 0 && ny < m) {
			if (temp[nx][ny] == 0) {
				// �ش� ��ġ�� ���̷��� ��ġ�ϰ� �ٽ� ��� ����
				temp[nx][ny] = 2;
				virus(nx, ny);
			}
		}
	}
}
// ���� �ʿ��� ���� ���� ũ�� ���
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

// ���� �켱 Ž���� �̿��� ��Ÿ�� ��ġ�ϸ鼭, �Ź� �������� ũ�� ���
void dfs(int cnt) {
	// ��Ÿ���� 3�� ��ġ�� ���, ���纻 �ʿ� ����
	if (cnt == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp[i][j] = arr[i][j];
			}
		}
		// �� ���̷����� ��ġ���� ���� ����
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (temp[i][j] == 2)
					virus(i, j);
			}
		}

		// �������� �ִ밪 ���
		result = max(result, getScore());
		return;
	}


	// �� ������ ��Ÿ�� ��ġ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				cnt += 1;
				dfs(cnt);
				arr[i][j] = 0; //dfs �� ������ ���� �ʱ�ȭ
				cnt -= 1; // �ʱ�ȭ ���־��
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