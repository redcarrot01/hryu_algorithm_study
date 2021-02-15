# include <iostream>
# include <vector>
# include <queue>

// privatequeue �̿��ϱ�, �� �����ϱ�
// �׸��� ���

/*
�켱���� ť
- �� ������ ������� �켱������ ���� ������ ���� ������ ��
- ���̶�� �ڷᱸ���� ������ ������
- ���� �켱���� ���� �����͸� ��Ʈ ��忡 ��ġ
*/

using namespace std;
	
int N;
// �켱������ �������� , ��Ʈ��尡 ���� ����?
priority_queue<int, vector<int>, greater<int>> Q;


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	/* ios_base::sync_with_stdio(false); 
		- c�� stdio�� cpp�� iostream�� ����ȭ�ϴ� ����
		- ���۸� ��� ����ϹǷ� ������ �߻�
		- false�� �ϸ� ����ȭ ��Ȱ��ȭ
		- ���� �и���, cin�� C�� scanf, gets, getchar ���� ���� ����ϸ� �ȵǰ�
		  cout�� C�� printf, puts, putchar ���� ���� ����ϸ� ������ ��� ���ü�����

       cin.tie(NULL);
	   - cin �� cout�� ������ Ǯ���ش�
	   - cin�� cout�� �����ְ� �����ִ� ��Ʈ������ �� ��Ʈ���� �ٸ� ��Ʈ������ 
	     �� IO �۾��� �����ϱ� ���� �ڵ����� ���� ����� ����

	*/

	cin >> N;
	// ���ĵ� ������ �Ѱ��� ������ �� ����
	if (N == 1) {
		cout << 0 << '\n';
		return 0;
	}
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		Q.push(a);
	}
	int ans = 0;
	// �ִ��� ���� �ֵ��� ���� ���´�
	while (Q.size() > 1) {
		int a = Q.top();
		Q.pop();
		int b = Q.top();
		Q.pop();
		ans += a + b;
		Q.push(a + b);
	}
	cout << ans << '\n';
	return 0;
}