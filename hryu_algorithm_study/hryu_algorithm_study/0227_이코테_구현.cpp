// 왕실의 나이트
/*
나이트의 이동 L자 모양
1. 수평 두칸 + 수직 한칸
2. 수직 두칸 + 수평 한칸

8 *8 좌표 나이트 이동할 수 있는 경우의수
행위치 1~8 열위치 a~h

입력  출력
a1     2
c2     6

문제유형 : 완탐

idea : 8가지 경로를 확인한다
*/
# include <iostream>
# include <string>

using namespace std;

string s;

int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

int main() {
	// 현재 나이트의 위치 입력, 숫자로 변환()
	cin >> s;
	int row = s[1] - '0'; // 행 1~8
	int col = s[0] - 'a' + 1; //열 1~8

	// 8 가지 방향에 대해 가능한지 위치 확인
	int result = 0;
	for (int i = 0; i < 8; i++) {
		// 이동하고자 하는 위치 확인
		int nextr = row + dx[i];
		int nextc = col + dy[i];
		// 해당 위치로 이동이 가능 -> 카운트 증가
		if (nextr >= 1 && nextc >= 1 && nextr <= 8 && nextc <= 8) {
			result++;
		}
	}
	cout << result << '\n';

}

// 예제 문자 쭉 풀어보기 
/*
구현은 완전탐색, 시뮬레이션이 있다
완전탐색 : 모든 경우의 수를 주저 없이 다 계산
시뮬레이션 : 문제에서 제시한 알고리즘을 한 단계씩 차례대로 직접 수행
*/


// 예제_ 상하좌우
/*
5 (1~100)
R R R U D D(1~100)    -> 3 4
*/
# include <iostream>
# include <string>

using namespace std;

int n;
string plans;
int x = 1, y = 1; // 스타트 

// L R U D
int dx[4] = { 0, 0, -1, 1 }; // 행
int dy[4] = { -1, 1, 0 , 0 }; // 열
char moveType[4] = { 'L','R', 'U', 'D' };

int main() {
	cin >> n;
	cin.ignore(); //버퍼초기화 -> 버퍼에 입력된 값으로 에러 생길까봐
	// 문자열 저장(파일입력/표준입력, 저장할 string형 변수, 어느 문자전까지 저장)
	getline(cin, plans);

	for (int i = 0; i < plans.size(); i++) {
		char plan = plans[i];
		// 이동 후 좌표구하기
		int nx = 0, ny = 0; // 초기화 반드시 필요
		for (int j = 0; j < 4; j++) {
			if (plan == moveType[j]) {
				nx = x + dx[j];
				ny = y + dy[j];
			}
		}
		// 공간 벗어나는 경우 무시
		if (nx < 1 || ny <1 || ny >n || ny >n)
			continue;
		x = nx;
		y = ny;
	}
	cout << x << ' ' << y;
}

// 예제_ 문자열 재정렬
/*
알파벳오름차순, 숫자는더해서 출력
K1KA5CB7 -> ABCKK13

팁
- 문자하나씩 확인
	- 숫자의 경우 합계
	- 알파벳은 다른 리소스에 저장
*/

# include <iostream>
# include <vector>
# include <string>
# include <algorithm>

using namespace std;

string str;
vector<char> result;
int sum = 0;

int main() {
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (isalpha(str[i]))
			result.push_back(str[i]);
		else
			sum += str[i] - '0';
	}

	// 알파벳 오름차순
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
	if (sum != 0) {
		cout << sum;
	}
	cout << '\n';
}

// 시각
/*
입력 n (0~ 23)
00시 00분 00초에 n:59:59 3이 하나라도 포함된 경우의 수
완전탐색문제
하루는 60 * 60*24= 86400

*/

# include <iostream>

using namespace std;

int h, cnt;

bool check(int h, int m, int s) { // m / 3 == 3은 십의자리 3일때
	if (h % 10 == 3 || m / 10 == 3 || m % 10 == 3 || s / 10 == 3 || s % 10 == 3)
		return true;
	return false;
}

int main(void) {
   //  h를 입력받기 
    cin >> h;
    for (int i = 0; i <= h; i++) {
        for (int j = 0; j < 60; j++) {
            for (int k = 0; k < 60; k++) {
              //   매 시각 안에 '3'이 포함되어 있다면 카운트 증가
                if (check(i, j, k)) cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}

// 게임개발
/*
1. 현재 방향 기준으로 왼족 방향 전진
2. 왼쪽에 가보지 않았다가 존재 한다면 -> 왼쪽 회전 + 한 칸 전진
						  존재 안해 -> 회전만하고 1단계
3. 네방향 다 가봤다, 바다 -> 바라보는 방향 유지 + 한칸 뒤로 가고 1단계, 뒤쪽이 바다라면 스탑
캐릭터가 방문한 칸의 수

0 1 2 3 북 동 남 서
처음 캐릭터가 위치한 칸의 상태 -> 항상육지

4 4 맵생성
1 1 0 캐릭터 1,1에있고 북쪽 바라봄
1 1 1 1     1은 바다
1 0 0 1
1 1 0 1
1 1 1 1

출력 3
*/

# include <iostream>

using namespace std;

int n, m, x, y, direction;

// 방문 맵
int visit[50][50];
// 전체 맵
int arr[50][50];

// 북 동 남 서 방향 정의
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

// 왼쪽 회전
void turn_left() { // 북 동 남 서 0 1 2 3, 1을빼는 이유 반시계 회전땜
	direction -= 1;
	if (direction == -1) direction = 3;

}
int main() {
	// 맴 정보를 공백 기준으로 구분 입력
	cin >> n >> m;
	// 현재 위치, 방향
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
		// 바라보는 방향 + 전진
		int nx = x + dx[direction];
		int ny = y + dy[direction];

		
		// 회전한 이후 정면에 가보지 않은 칸 존재하는 경우 이동
		if (visit[nx][ny] == 0 && arr[nx][ny] == 0) {
			visit[nx][ny] = 1;
			x = nx;
			y = ny;
			cnt += 1;
			// 이동 가능한 곳이라면
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
			// 갈 수있다는 것이므로 초기화
			turn_time = 0;
		}

	}
	cout << cnt << '\n';
}