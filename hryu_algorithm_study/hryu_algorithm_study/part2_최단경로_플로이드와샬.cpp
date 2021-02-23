# include <iostream>
# include <algorithm>
# define INF 1e9 // 10억

using namespace std;

// 노드 개수 n 간선 개수 m
// 노드 개수 최대 500
int n, m;
// 2차원 배열 만들기
int graph[501][501];

int main() {
	cin >> n >> m;

	// 최단 거리 테이블 무한으로 초기화
	for (int i = 0; i < 501; i++) {
		fill(graph[i], graph[i] + 501, INF);
	}
	// 자기 자신에게 자기 자신으로 가는 비용은 0
	for (int a = 1; a <= n; a++) {  //a 시작노드
		for (int b = 1; b <= n; b++) {  //b 도착노드
			if (a == b) graph[a][b] = 0;
		}
	}
	// 각 간선에 대한 정보를 입력 받아 그 값으로 초기화
	for (int i = 0; i < m; i++) {
		// A-> B로 가는 비용은 c라고 설정
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
	}

	// 점화식에 따라 플로이드 와샬 
	for (int k = 1; k <= n; k++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k]+graph[k][b] );
			}
		}
	}

	// 수행된 결과를 출력
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if (graph[a][b] == INF) { // 도달못하는 경우
				cout << "infinity" << ' ';
			}
			// 도달할 수 있는 경우
			else cout << graph[a][b] << ' ';
		}
		cout << '\n';
	}

}