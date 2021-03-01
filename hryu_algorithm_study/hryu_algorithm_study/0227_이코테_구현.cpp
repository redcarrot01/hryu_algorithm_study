// �ս��� ����Ʈ
/*
����Ʈ�� �̵� L�� ���
1. ���� ��ĭ + ���� ��ĭ
2. ���� ��ĭ + ���� ��ĭ

8 *8 ��ǥ ����Ʈ �̵��� �� �ִ� ����Ǽ�
����ġ 1~8 ����ġ a~h

�Է�  ���
a1     2
c2     6

�������� : ��Ž

idea : 8���� ��θ� Ȯ���Ѵ�
*/
# include <iostream>
# include <string>

using namespace std;

string s;

int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

int main() {
	// ���� ����Ʈ�� ��ġ �Է�, ���ڷ� ��ȯ()
	cin >> s;
	int row = s[1] - '0'; // �� 1~8
	int col = s[0] - 'a' + 1; //�� 1~8

	// 8 ���� ���⿡ ���� �������� ��ġ Ȯ��
	int result = 0;
	for (int i = 0; i < 8; i++) {
		// �̵��ϰ��� �ϴ� ��ġ Ȯ��
		int nextr = row + dx[i];
		int nextc = col + dy[i];
		// �ش� ��ġ�� �̵��� ���� -> ī��Ʈ ����
		if (nextr >= 1 && nextc >= 1 && nextr <= 8 && nextc <= 8) {
			result++;
		}
	}
	cout << result << '\n';

}

// ���� ���� �� Ǯ��� 
/*
������ ����Ž��, �ùķ��̼��� �ִ�
����Ž�� : ��� ����� ���� ���� ���� �� ���
�ùķ��̼� : �������� ������ �˰����� �� �ܰ辿 ���ʴ�� ���� ����
*/


// ����_ �����¿�
/*
5 (1~100)
R R R U D D(1~100)    -> 3 4
*/
# include <iostream>
# include <string>

using namespace std;

int n;
string plans;
int x = 1, y = 1; // ��ŸƮ 

// L R U D
int dx[4] = { 0, 0, -1, 1 }; // ��
int dy[4] = { -1, 1, 0 , 0 }; // ��
char moveType[4] = { 'L','R', 'U', 'D' };

int main() {
	cin >> n;
	cin.ignore(); //�����ʱ�ȭ -> ���ۿ� �Էµ� ������ ���� ������
	// ���ڿ� ����(�����Է�/ǥ���Է�, ������ string�� ����, ��� ���������� ����)
	getline(cin, plans);

	for (int i = 0; i < plans.size(); i++) {
		char plan = plans[i];
		// �̵� �� ��ǥ���ϱ�
		int nx = 0, ny = 0; // �ʱ�ȭ �ݵ�� �ʿ�
		for (int j = 0; j < 4; j++) {
			if (plan == moveType[j]) {
				nx = x + dx[j];
				ny = y + dy[j];
			}
		}
		// ���� ����� ��� ����
		if (nx < 1 || ny <1 || ny >n || ny >n)
			continue;
		x = nx;
		y = ny;
	}
	cout << x << ' ' << y;
}

// ����_ ���ڿ� ������
/*
���ĺ���������, ���ڴ´��ؼ� ���
K1KA5CB7 -> ABCKK13

��
- �����ϳ��� Ȯ��
	- ������ ��� �հ�
	- ���ĺ��� �ٸ� ���ҽ��� ����
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

	// ���ĺ� ��������
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
	if (sum != 0) {
		cout << sum;
	}
	cout << '\n';
}

// �ð�
/*
�Է� n (0~ 23)
00�� 00�� 00�ʿ� n:59:59 3�� �ϳ��� ���Ե� ����� ��
����Ž������
�Ϸ�� 60 * 60*24= 86400

*/

# include <iostream>

using namespace std;

int h, cnt;

bool check(int h, int m, int s) { // m / 3 == 3�� �����ڸ� 3�϶�
	if (h % 10 == 3 || m / 10 == 3 || m % 10 == 3 || s / 10 == 3 || s % 10 == 3)
		return true;
	return false;
}

int main(void) {
   //  h�� �Է¹ޱ� 
    cin >> h;
    for (int i = 0; i <= h; i++) {
        for (int j = 0; j < 60; j++) {
            for (int k = 0; k < 60; k++) {
              //   �� �ð� �ȿ� '3'�� ���ԵǾ� �ִٸ� ī��Ʈ ����
                if (check(i, j, k)) cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}

// ���Ӱ���
/*
1. ���� ���� �������� ���� ���� ����
2. ���ʿ� ������ �ʾҴٰ� ���� �Ѵٸ� -> ���� ȸ�� + �� ĭ ����
						  ���� ���� -> ȸ�����ϰ� 1�ܰ�
3. �׹��� �� ���ô�, �ٴ� -> �ٶ󺸴� ���� ���� + ��ĭ �ڷ� ���� 1�ܰ�, ������ �ٴٶ�� ��ž
ĳ���Ͱ� �湮�� ĭ�� ��

0 1 2 3 �� �� �� ��
ó�� ĳ���Ͱ� ��ġ�� ĭ�� ���� -> �׻�����

4 4 �ʻ���
1 1 0 ĳ���� 1,1���ְ� ���� �ٶ�
1 1 1 1     1�� �ٴ�
1 0 0 1
1 1 0 1
1 1 1 1

��� 3
*/

# include <iostream>

using namespace std;

int n, m, x, y, direction;

// �湮 ��
int visit[50][50];
// ��ü ��
int arr[50][50];

// �� �� �� �� ���� ����
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

// ���� ȸ��
void turn_left() { // �� �� �� �� 0 1 2 3, 1������ ���� �ݽð� ȸ����
	direction -= 1;
	if (direction == -1) direction = 3;

}
int main() {
	// �� ������ ���� �������� ���� �Է�
	cin >> n >> m;
	// ���� ��ġ, ����
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
		// �ٶ󺸴� ���� + ����
		int nx = x + dx[direction];
		int ny = y + dy[direction];

		
		// ȸ���� ���� ���鿡 ������ ���� ĭ �����ϴ� ��� �̵�
		if (visit[nx][ny] == 0 && arr[nx][ny] == 0) {
			visit[nx][ny] = 1;
			x = nx;
			y = ny;
			cnt += 1;
			// �̵� ������ ���̶��
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
			// �� ���ִٴ� ���̹Ƿ� �ʱ�ȭ
			turn_time = 0;
		}

	}
	cout << cnt << '\n';
}