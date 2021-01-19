/*
1 Ž�� ���� ��带 ť�� �����ϰ� �湮 ó��
2 ť���� ��带 ���� �� �ش� ����� ���� ��� �� �湮���� �ʾҴٸ�
  ��� ��� ť�� ����, �湮 ó��
3 2�� ���� �ݺ�
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

    //���� ��带 �湮 ó��
    visited[start] = true;
    // ť�� �������� �ݺ�
    while (!q.empty()) {
        // ť�����ϳ��� ���� �̾� ���
        int x = q.front();
        q.pop();
        cout << x << ' ';

        // ���� ��� �湮�ϰ� ť�� ����
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