#include <stdio.h>
#include <iostream>
using namespace std;
int n, m;
int graph[1001][1001];

// dfs�� Ư�� ��带 �湮�ϰ� ����� ��� ���鵵 �湮
bool dfs(int x, int y) {
	// �־��� ������ ����� ��쿡�� ��� ����
	if (x < 0 || x >= n || y < 0 || y >= m) {
		return false;
	}
	// ���� ��带 ���� �湮���� �ʴ´ٸ�
	if (graph[x][y] == 0) {
		// �湮ó��
		graph[x][y] = 1;
		// �����¿�
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

	//2���� ����Ʈ�� �� ���� �Է�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &graph[i][j]); 
			// ��ġ �Ű����� 1�� ��ĭ�� Ȯ���ϰڴ�
		}
	}
	// ��� ��忡 ���Ͽ� ����� ä���
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// ���� ��ġ���� dfs ����
			if (dfs(i, j)) result += 1;
		}
	}
	cout << result << '\n';
}

