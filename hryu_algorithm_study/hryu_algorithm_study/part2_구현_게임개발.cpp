// continue�� ���� ������ ������ �̵��ϴ� ��� ->�Ϻ� �ڵ� ������ϰ� ����

# include <stdio.h>
#include <iostream>

using namespace std;

int n, m, x, y, direction;

// �湮 ��
int visit[50][50];
// ��ü ��
int arr[50][50];

// �� �� �� �� ���� ����
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// ���� ȸ�� 
void turn_left() { // �� 0    �� 1     �� 2     �� 3
	direction -= 1;
	if (direction == -1) direction = 3;
}

int main() {
	// �� ������ ������ �������� �����Ͽ� �Է�
	cin >> n >> m;
	// ���� ��ġ�� ����
	cin >> x >> y >> direction;
	// ���� ��ġ �湮
	visit[x][y] = 1;
	// �� ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			arr[i][j] = x;
		}
	}

	// �ù� 
	// cnt�� �̵� Ƚ��
	int cnt = 1;
	// �������� �������� �ٶ󺸴� Ƚ��
	int turn_time = 0;
	while (true) {
		// �������� ȸ��
		turn_left();
		// �ٶ󺸴� ���� + �������� �̵�
		int nx = x + dx[direction];
		int ny = y + dy[direction];

		//ȸ���� ���� ���鿡 ������ ���� ĭ �����ϴ� ��� �̵�
		if (visit[nx][ny] == 0 && arr[nx][ny] == 0) {
			visit[nx][ny] = 1;
			x = nx;
			y = ny;
			cnt += 1;
			// �̵� ������ ���̿��� -> 0
			turn_time = 0;
			continue; // �̵��� ������ �� �̵��ϱ� ���� continue
		}
		// ȸ���� ���� ������ ���� ĭ ���ų� �ٴ� ���
		else turn_time += 1;
		if (turn_time == 4) {
			nx = x - dx[direction];
			ny = y - dy[direction];
			// �ڷ� �� �� �ִٸ� �̵�
			if (arr[nx][ny] == 0) {
				x = nx;
				y = ny;
			}
			// �ڰ� �ٴ�
			else break;
			// �� �� �ִٴ� ���̹Ƿ� �ʱ�ȭ
			turn_time = 0;
		}

	}
	cout << cnt << '\n';
}
