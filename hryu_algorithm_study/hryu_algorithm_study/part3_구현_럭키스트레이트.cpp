# include <stdio.h>
# include <iostream>

using namespace std;

string str;
int summary = 0;

int main(void) {
    cin >> str;

    // ���� �κ��� �ڸ����� �� ���ϱ�
    for (int i = 0; i < str.size() / 2; i++) {
        summary += str[i] - '0';
    }

    // ������ �κ��� �ڸ����� �� ����
    for (int i = str.size() / 2; i < str.size(); i++) {
        summary -= str[i] - '0';
    }

    // ���� �κа� ������ �κ��� �ڸ��� ���� �������� �˻�
    if (summary == 0) cout << "LUCKY" << '\n';
    else cout << "READY" << '\n';
}