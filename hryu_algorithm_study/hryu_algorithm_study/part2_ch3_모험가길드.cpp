
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int n;
vector<int> arr;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
	int result = 0; //�׷��
	int cnt = 0; // �׷쿡 ���Ե� ���谡 �� 
	for (int i = 0; i < n; i++) {
		cnt++ ;
		// ���谡�� >= ������ �̸� �׷� �Ἲ
		if (cnt >= arr[i]) {
			result++;
			cnt = 0;
		}
	}
	cout << result << '\n'; 
}