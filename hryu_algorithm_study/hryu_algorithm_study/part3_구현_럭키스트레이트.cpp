# include <stdio.h>
# include <iostream>

using namespace std;

string str;
int summary = 0;

int main(void) {
    cin >> str;

    // 왼쪽 부분의 자릿수의 합 더하기
    for (int i = 0; i < str.size() / 2; i++) {
        summary += str[i] - '0';
    }

    // 오른쪽 부분의 자릿수의 합 빼기
    for (int i = str.size() / 2; i < str.size(); i++) {
        summary -= str[i] - '0';
    }

    // 왼쪽 부분과 오른쪽 부분의 자릿수 합이 동일한지 검사
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


