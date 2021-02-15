#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct STU {
	string name;
	int ko, en, ma;
};

// 정렬 함수에 사용할 함수
bool cmp(STU a, STU b) {
	//국어도 같고 영어도 같고 수학도 같으면 이름 오름차순 
	if (a.ko == b.ko && a.en == b.en && a.ma == b.ma)
		return a.name < b.name;
	// 국어 같고 영어 같으면, 수학은 내림차순
	if (a.ko == b.ko && a.en == b.en)
		return a.ma > b.ma;
	// 국어 같으면 영어 오름차순
	if (a.ko == b.ko)
		return a.en < b.en;
	// 국어 내림차순 
	return a.ko > b.ko;
}

int main() {
	int N;
	cin >> N;

	vector<STU> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].name >> v[i].ko >> v[i].en >> v[i].ma;

	}
	// sort 함수
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << v[i].name << '\n';
	}

}