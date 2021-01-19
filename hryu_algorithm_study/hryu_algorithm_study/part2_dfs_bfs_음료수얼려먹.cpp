#include <stdio.h>
#include <iostream>
using namespace std;
int n, m;
int graph[1001][1001];

// dfs로 특정 노드를 방문하고 연결된 모든 노드들도 방문
bool dfs(int x, int y) {
	// 주어진 범위를 벗어나는 경우에는 즉시 종료
	if (x < 0 || x >= n || y < 0 || y >= m) {
		return false;
	}
	// 현재 노드를 아직 방문하지 않는다면
	if (graph[x][y] == 0) {
		// 방문처리
		graph[x][y] = 1;
		// 상하좌우
		dfs(x - 1, y);
		dfs(x, y - 1);
		dfs(x + 1, y);
		dfs(x, y + 1);
		return true;

	}
	return false;
}

int main() {
	cin >> n >> m;

	//2차원 리스트의 맵 정보 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &graph[i][j]); 
			// 위치 매개변수 1은 한칸을 확보하겠다
		}
	}
	// 모든 노드에 대하여 음료수 채우기
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 현재 위치에서 dfs 수행
			if (dfs(i, j)) result += 1;
		}
	}
	cout << result << '\n';
}

