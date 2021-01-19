/*
1 탐색 시작 노드를 큐에 삽입하고 방문 처리
2 큐에서 노드를 꺼낸 뒤 해당 노드의 인접 노드 중 방문하지 않았다면
  노드 모두 큐에 삽입, 방문 처리
3 2번 과정 반복
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool visited[9];
vector<int> graph[9];

// bfs
void bfs(int start) {
    queue<int> q;
    q.push(start);

    //현재 노드를 방문 처리
    visited[start] = true;
    // 큐가 빌때까지 반복
    while (!q.empty()) {
        // 큐에서하나의 원소 뽑아 출력
        int x = q.front();
        q.pop();
        cout << x << ' ';

        // 인접 노드 방문하고 큐에 삽입
        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if (!visited[y]) {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main() {
	graph[1].push_back(2); 
    graph[1].push_back(3);
    graph[1].push_back(8);

    graph[2].push_back(1);
    graph[2].push_back(7);

    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);

    graph[4].push_back(3);
    graph[4].push_back(5);

    graph[5].push_back(3);
    graph[5].push_back(4);

    graph[6].push_back(7);

    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    graph[8].push_back(1);
    graph[8].push_back(7);

    bfs(1);
}