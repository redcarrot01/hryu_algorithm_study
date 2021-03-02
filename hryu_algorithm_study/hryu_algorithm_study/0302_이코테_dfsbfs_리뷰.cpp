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