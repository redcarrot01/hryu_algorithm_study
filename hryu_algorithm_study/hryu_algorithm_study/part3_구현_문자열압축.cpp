# include <stdio.h>
# include <iostream>
# include <vector>
# include <string>

// 모르겠다 나중에 풀기


// to_string : int to string
using namespace std;

int solution(string s) {

}







void print(string s, int answer) {
    int t = solution(s);
    if (answer == t)
        cout << "정답" << endl;
    else
        cout << "틀림" << endl;
}

int main() {
    print("a", 1);
    print("aaaaa", 2);
    print("aaaaaaaaaa", 3);
    print("aabbaccc", 7);
    print("ababcdcdababcdcd", 9);
    print("abcabcdede", 8);
    print("abcabcabcabcdededededede", 14);
    print("xababcdcdababcdcd", 17);
    return 0;
}