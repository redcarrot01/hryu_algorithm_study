// 입력 : 만들어질수 있는 가장 큰수 20억 이하 정수
// 그이유는 c에서는 가장 큰수 int형으로 21억 정도니까

// 시간 제한 1초
// 메모리 제한 128mb
// 두수 중 하나라도 1이하인 경우 더하기, 모두 2이상인 경우 곱하기

// long long / long long int 8바이트 
// int 생략 가능 

# include <stdio.h>
# include <iostream>

using namespace std;
string str;

int main() {
	cin >> str;
	// 첫 번째 문자를 숫자로 변경한 값을 대입
	long long result = str[0] - '0';

	for (int i = 1; i < str.size(); i++) {
		// 두 수 중에서 하나라도 '0' 혹은 '1' 인 경우, 곱하기 보다는 더하기 수행
		int num = str[i] - '0';
		if (num <= 1 || result <= 1) result += num;
		else result *= num;

	}
	cout << result << '\n';
}


