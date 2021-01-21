/*
n명의 학생 정보
학생정보는 이름과 성적으로 구성
성적 낮은 순서대로 이름 출력하기

입력 
2       => 1~100,000
aa 95   (<= 100 , 자연수)
bb 75

출력
bb aa
*/
# include <stdio.h>
# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;


class Student {
public: //자바와 달리 한꺼번에 접근 지정자 선언
	string name; 
	int score;   // 멤버 변수 선언, 선언부 끝 , 여기서 초기화 x

	Student(string name, int score) {  // 멤버 함수 구현부
		this->name = name;
		this->score = score;
	}
	// 정렬 기준은 '점수 낮은 순서
	/*
	연산자 오버로딩
	*/
	bool operator <(Student &other) {
		return this->score < other.score; //오름차순으로 점수만 리턴
		// https://ko.wikipedia.org/wiki/C%EC%99%80_C%2B%2B%EC%9D%98_%EC%97%B0%EC%82%B0%EC%9E%90 
	}
};
int n; 
vector<Student> v;

int main(void) {
	// n입력 받기
	cin >> n;

	// N명의 학생 정보를 입력받아 리스트에 저장
	for (int i = 0; i < n; i++) {
		string name;
		int score;
		cin >> name >> score;
		v.push_back(Student(name, score));
	}

	sort(v.begin(), v.end());

	// 정렬이 수행된 결과를 출력
	for (int i = 0; i < n; i++) {
		cout << v[i].name << ' ';
	}

}
// 모든 멤버함수는 함수가 호출된 인스턴스를 가리키는 this 포인터 가지고 있다
// 위 코드에서 this는 명시적으로 참조
// 멤버변수와 이름이 같은 매개변수 가진 멤버함수가 있는 경우
// this-> name(멤버변수)=name(매개 변수);
// 같은 이름 쓰지 않고 m_접두사 활용하여 중복 방지하는 방법도 있따