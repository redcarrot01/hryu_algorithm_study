#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

bool visited[9];
vector<int> graph[9];

// dfs 함수 정의
void dfs(int x) {
	// 현재 노드를 방문 처리
	visited[x] = true;
	cout << x << ' ';
	// 현재 노드와 연결된 다른 노드 재귀적으로 방문
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited[y]) dfs(y);
	}
}
// 방문처리 -> 노드 출력 -> 인접 노드 조사 (dfs) 반복


int main(void) {
	// 초기화
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

    dfs(1);

}
