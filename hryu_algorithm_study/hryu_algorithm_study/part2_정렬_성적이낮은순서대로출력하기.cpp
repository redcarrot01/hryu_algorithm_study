/*
n���� �л� ����
�л������� �̸��� �������� ����
���� ���� ������� �̸� ����ϱ�

�Է� 
2       => 1~100,000
aa 95   (<= 100 , �ڿ���)
bb 75

���
bb aa
*/
# include <stdio.h>
# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;


class Student {
public: //�ڹٿ� �޸� �Ѳ����� ���� ������ ����
	string name; 
	int score;   // ��� ���� ����, ����� �� , ���⼭ �ʱ�ȭ x

	Student(string name, int score) {  // ��� �Լ� ������
		this->name = name;
		this->score = score;
	}
	// ���� ������ '���� ���� ����
	/*
	������ �����ε�
	*/
	bool operator <(Student &other) {
		return this->score < other.score; //������������ ������ ����
		// https://ko.wikipedia.org/wiki/C%EC%99%80_C%2B%2B%EC%9D%98_%EC%97%B0%EC%82%B0%EC%9E%90 
	}
};
int n; 
vector<Student> v;

int main(void) {
	// n�Է� �ޱ�
	cin >> n;

	// N���� �л� ������ �Է¹޾� ����Ʈ�� ����
	for (int i = 0; i < n; i++) {
		string name;
		int score;
		cin >> name >> score;
		v.push_back(Student(name, score));
	}

	sort(v.begin(), v.end());

	// ������ ����� ����� ���
	for (int i = 0; i < n; i++) {
		cout << v[i].name << ' ';
	}

}
// ��� ����Լ��� �Լ��� ȣ��� �ν��Ͻ��� ����Ű�� this ������ ������ �ִ�
// �� �ڵ忡�� this�� ��������� ����
// ��������� �̸��� ���� �Ű����� ���� ����Լ��� �ִ� ���
// this-> name(�������)=name(�Ű� ����);
// ���� �̸� ���� �ʰ� m_���λ� Ȱ���Ͽ� �ߺ� �����ϴ� ����� �ֵ�