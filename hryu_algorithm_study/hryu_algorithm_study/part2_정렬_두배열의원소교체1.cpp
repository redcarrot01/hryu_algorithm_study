#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, cnt;
vector<int> a, b;

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		b.push_back(x);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());
	
	for (int i = 0; i < k; i++) {
		swap(a[i], b[i]);
	}
	for (int i = 0; i < n; i++) {
		cnt += a[i];
	}
	cout << cnt<<'\n';
	return 0;
}