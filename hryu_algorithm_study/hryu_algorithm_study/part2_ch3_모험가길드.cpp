
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
	int result = 0; //그룹수
	int cnt = 0; // 그룹에 포함된 모험가 수 
	for (int i = 0; i < n; i++) {
		cnt++ ;
		// 모험가수 >= 공포도 이면 그룹 결성
		if (cnt >= arr[i]) {
			result++;
			cnt = 0;
		}
	}
	cout << result << '\n'; 
}