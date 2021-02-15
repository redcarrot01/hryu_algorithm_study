#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct STU {
	string name;
	int ko, en, ma;
};

// ���� �Լ��� ����� �Լ�
bool cmp(STU a, STU b) {
	//��� ���� ��� ���� ���е� ������ �̸� �������� 
	if (a.ko == b.ko && a.en == b.en && a.ma == b.ma)
		return a.name < b.name;
	// ���� ���� ���� ������, ������ ��������
	if (a.ko == b.ko && a.en == b.en)
		return a.ma > b.ma;
	// ���� ������ ���� ��������
	if (a.ko == b.ko)
		return a.en < b.en;
	// ���� �������� 
	return a.ko > b.ko;
}

int main() {
	int N;
	cin >> N;

	vector<STU> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].name >> v[i].ko >> v[i].en >> v[i].ma;

	}
	// sort �Լ�
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << v[i].name << '\n';
	}

}