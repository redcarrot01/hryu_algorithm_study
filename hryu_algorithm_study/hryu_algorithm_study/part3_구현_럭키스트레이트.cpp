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
    /*
    string scores;
    cin >> scores;
    int sum1 = 0;
    int sum2 = 0;
    if(scores.size()%@ == 0){
        for(int i=0; i<socres.size()/2 ; i++){
            sum1 += scores[i];
        }
        for(int i=scores.size()/2 ; i<scores.size(); i++){
            sum2 += socres[i];
        }
        if(sum1==sum2)
            cout << "LUCKY\n";
        else
            cout << "READY\n";
    }


    */
}


