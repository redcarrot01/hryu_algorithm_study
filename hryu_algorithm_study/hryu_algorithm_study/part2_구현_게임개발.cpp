// continue는 현재 루프의 끝으로 이동하는 방법 ->일부 코드 실행안하고 점프

# include <stdio.h>
#include <iostream>

using namespace std;

int n, m, x, y, direction;

// 방문 맵
int visit[50][50];
// 전체 맵
int arr[50][50];

// 북 동 남 서 방향 정의
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// 왼쪽 회전 
void turn_left() { // 북 0    동 1     남 2     서 3
	direction -= 1;
	if (direction == -1) direction = 3;
}

int main() {
	// 맵 정보를 공백을 기준으로 구분하여 입력
	cin >> n >> m;
	// 현재 위치와 방향
	cin >> x >> y >> direction;
	// 현재 위치 방문
	visit[x][y] = 1;
	// 맵 정보
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			arr[i][j] = x;
		}
	}

	// 시뮬 
	// cnt는 이동 횟수
	int cnt = 1;
	// 동서남북 방향으로 바라보는 횟수
	int turn_time = 0;
	while (true) {
		// 왼쪽으로 회전
		turn_left();
		// 바라보는 방향 + 그쪽으로 이동
		int nx = x + dx[direction];
		int ny = y + dy[direction];

		//회전한 이후 정면에 가보지 않은 칸 존재하는 경우 이동
		if (visit[nx][ny] == 0 && arr[nx][ny] == 0) {
			visit[nx][ny] = 1;
			x = nx;
			y = ny;
			cnt += 1;
			// 이동 가능한 곳이였음 -> 0
			turn_time = 0;
			continue; // 이동한 곳에서 또 이동하기 위해 continue
		}
		// 회전한 이후 가보지 않은 칸 없거나 바다 라면
		else turn_time += 1;
		if (turn_time == 4) {
			nx = x - dx[direction];
			ny = y - dy[direction];
			// 뒤로 갈 수 있다면 이동
			if (arr[nx][ny] == 0) {
				x = nx;
				y = ny;
			}
			// 뒤가 바다
			else break;
			// 갈 수 있다는 것이므로 초기화
			turn_time = 0;
		}

	}
	cout << cnt << '\n';
}
