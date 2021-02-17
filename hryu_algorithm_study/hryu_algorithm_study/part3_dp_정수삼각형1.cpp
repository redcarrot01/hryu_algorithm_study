//sol1 : bottom up �ݺ���
#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
�ð����⵵ O(N*N) = O(250000)
�˰��� DP
�ڷᱸ�� 2���迭
*/
int answer, height, d[501][501];
int n;
vector<vector<int>> tri;

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> d[i][j];
		}
	}
	//���� ���, �ʱⰪ�� ����
	answer = d[0][0] = tri[0][0];
	// �ﰢ�� ����
	height = (int)tri.size();

	// �� ������ �� ���� ������ ����ó��
	for (int i = 1; i < height; i++) {
		for (int j = 0; j <= i; j++) {
			// �ﰢ�� ���� ��
			if (j == 0) {
				d[i][j] = d[i - 1][j] + tri[i][j];
			}
			// �ﰢ�� ������ ��
			else if (j == i) {
				d[i][j] = d[i - 1][j - 1] + tri[i][j];
			}
			// �ﰢ�� ���� , ������ ���� �ƴ� ����
			else {
				d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + tri[i][j];
			}
			// ����
			answer = max(answer, d[i][j]);
		}

	}
	cout << answer;
	return 0;

}
