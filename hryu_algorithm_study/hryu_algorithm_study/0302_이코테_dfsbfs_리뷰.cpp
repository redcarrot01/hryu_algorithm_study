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