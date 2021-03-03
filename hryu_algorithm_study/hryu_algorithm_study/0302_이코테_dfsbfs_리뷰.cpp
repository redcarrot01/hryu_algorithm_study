// Ž��
/*
���� filo
ť fifo
����Լ� 
- ����� ��� ���� ���� ��� �ʿ�
- ��Ŭ���� ȣ����
- ���� ��� ��� ��� -> �Լ� ȣ�� �������� ���ÿ� ����

dfs
- ���� �켱 Ž��
- ���� �ڷᱸ���� �̿�
	- Ž�� ���� ��带 ���ÿ� �����ϰ� �湮 ó��
	- ������ �ֻ�� ��忡 �湮���� ���� ���� ��� ������ ���ÿ� �ְ� �湮 ó��
	  �湮�F �Ӿ��� ������� ���ٸ� ���ÿ��� �ֻ�� ��� ������
	- �ι�° ���� �ݺ�

bfs
- �ʺ� �켱 Ž��
- ť �̿�
	- Ž�� ���� ��带 ť�� �����ϰ� �湮 ó��
	- ť���� ��� ���� �� �ش� ����� ���� ��� �� �湮�F �ӾʾҴٸ�
	  ��� ��� ť�� ���� �׸��� �湮 ó��
	- �ι��� �ݺ�
*/

// dfs ����
//# include <iostream>
//# include <vector>
//
//using namespace std;
//
//bool visited[9];
//vector <int> graph[9];
//
//// ������ ����Ʈ �ڷ��� �̿�
//
//// dfs 
//void dfs(int x) {
//    // ���� ��带 �湮 ó��
//    visited[x] = true;
//    cout << x << ' ';
//    // ���� ���� ����� �ٸ� ��� ��� �湮
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
1 Ž�� ���� ��带 ť�� �����ϰ� �湮 ó��
2 ť���� ��带 ���� �� �ش� ����� ���� ��� �� �湮���� �ʾҴٸ�
   ��� ��� ť�� ����, �湮 ó��
3 �ݺ�
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
//    //���� ��带 �湮 ó��
//    visited[start] = true;
//    // ť�� �������� �ݺ�
//    while (!q.empty()) {
//        // ť���� �ϳ��� ���� �̾� ���
//        int x = q.front();
//        q.pop();
//        cout << x << " ";
//
//        // ���� ��� �湮�ϰ� ť�� ����
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

// ����� ����Ա�

/*
n*m ���۶շ��ִ� 0, ĭ���� 1
n,m 1~1000
�ѹ��� ������ִ� ���̽�ũ������ 
00110
00011
11111
00000   -> 3�� ����

��
1. �����¿� ���Ǳ� -> 0�̸鼭 �湮���� �ʾҴٸ� �湮
2. �湮�������� ���� �ݺ�
3. �湮�� �� ���� �� ī��Ʈ
*/
//#include <stdio.h>
//#include <iostream>
//using namespace std;
//
//int n, m;
//int graph[1001][1001];
//
//// dfs�� Ư�� ��带 �湮�ϰ� ����� ��� ���鵵 �湮
//bool dfs(int x, int y) {
//	// �־��� ���� ����� ��쿡�� ��� ����
//	if (x < 0 || x >= n || y < 0 || y >= m) {
//		return false;
//	}
//	// ���� ��带 ���� �湮���� �ʴ´ٸ�
//	if (graph[x][y] == 0) {
//		// �湮 ó��
//		graph[x][y] = 1;
//		// �����¿�
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
//	// 2���� ����Ʈ�� �� ���� �Է�, 
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j <m ; j++) {
//			scanf_s("%1d", &graph[i][j]);
//			// ��ġ�Ű����� 1�� �ٴڴٴ� �پ��ִ� �Է�ó�� ����
//		}
//	}
//	// ��� ��忡 ���Ͽ� ����� ä���
//	int result = 0;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			// ���� ��ġ���� dfs ����
//			if (dfs(i, j)) result += 1;
//		}
//	}
//	cout << result << '\n';
//}




// �̷�Ż��
/*
(1,1) -> (N,M)���� ����
����o 0, ����x 1
Ż���ϱ� ���� �������� �ϴ� �ּ����� ����

n,m 1~200
������ ������� �־���

�� 
bfs => ���۳�忡�� ���������� ���ʴ�� �׷����� ����� Ž��
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
//// ���� �����¿�
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
//		// ���� ��ġ���� 4���� ���������� ��ġ
//		for (int i = 0; i < 4; i++) {
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
//				continue;
//			if (graph[nx][ny] == 0)
//				continue;
//
//			//�ش� ��带 ó�� �湮�ϴ� ��� �ִ� �Ÿ� ���
//			if (graph[nx][ny] == 1) {
//				graph[nx][ny] = graph[x][y] + 1;
//				q.push({ nx, ny });
//			}
//		}
//	}
//	// ���� ������ �Ʒ������� �ִ� �Ÿ� �湮
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

// ������ �����ֱ�
/*
n 2~11
a 1~100
+ - * /  �� n-1���� ����

��� : �ִ�, �ּڰ� -10�� ~10��

// �����ڴ� operators��� 4¥�� �迭 ����
�� ��, ��Ʈ��ŷ ����Ͽ� ��� �ذ�
�Ű������� ���±��� ������ result, ������ ������ ���� �ε��� �Է¹޵��� �ϴ� 
��Ʈ��ŷ ��� �Լ� �����Ͽ� Ǯ��

����� �帧�� �Ű����� � ���� ������� �����ϴ� �ɷ� �ʿ�

2
5 6 
0 0 1 0    ->  30 30

3
3 4 5
1 0 1 0  ->	 35 17

*/

# include <iostream>
using namespace std;

int N; // n 2~11
int operands[11];
int operators[4];
int mymin = 1000000001;
int mymax = -1000000001;

// ��ͷ�
void get_answer(int result, int idx) {
	if (idx == N) { // ������ �� ���
		if (result > mymax) mymax = result;
		if (result < mymin) mymin = result;
	}

	for (int i = 0; i < 4; i++) {
		if (operators[i] > 0) { // �� �ε����� ������ ����ִٸ�
			operators[i]--; // ������ ����ϸ� �Ѱ� �ٿ���
			if (i == 0)
				get_answer(result + operands[idx], idx + 1);
			else if (i == 1)
				get_answer(result - operands[idx], idx + 1);
			else if (i == 2)
				get_answer(result * operands[idx], idx + 1);
			else
				get_answer(result / operands[idx], idx + 1);

			operators[i]++; // �ٸ� ������ ����� ���̹Ƿ� 
			// �Ʊ� �ٿ��� ������ ���� �÷���
		}
	}
	return;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> operands[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
	}
	get_answer(operands[0], 1); // idx�� ������ ����, 1������ �����̴ϱ�
	cout << mymax << '\n';
	cout << mymin << '\n';

}