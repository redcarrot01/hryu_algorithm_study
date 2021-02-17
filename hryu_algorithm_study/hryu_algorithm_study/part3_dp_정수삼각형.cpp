//sol1 : bottom up �ݺ���
#include <string>
# include <vector>
#define max_int 501

using namespace std;

/*
�ð����⵵ O(N*N) = O(250000)
�˰��� DP
�ڷᱸ�� 2���迭
*/
int answer, height, d[max_int][max_int];

int max(int a, int b) {
	return a > b ? a : b;
}

int solution(vector<vector<int>> tri) {
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
	return answer;
}
