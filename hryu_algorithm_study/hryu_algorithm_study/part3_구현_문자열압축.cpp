# include <stdio.h>
# include <iostream>
# include <vector>
# include <string>

// �𸣰ڴ� ���߿� Ǯ��


// to_string : int to string
using namespace std;


int solution(string s) {
    int answer = s.length();
    //����� �� Ž���ϱ�
    for (int i = 1; i <= s.length() / 2; i++) {
        int len = s.length();
        //���ڿ��� ��ü ���鼭 �ݺ�
        for (int j = 0; j < s.length(); j++) {
            //�κ� ���ϱ�
            for (int count = 0, z = i; j + z < s.length(); z += i) {
                //�ںκа� ��ġ�Ѵٸ� count ����
                if (s.substr(j, i) == s.substr(j + z, i))    count++;


                // ```````````````` ������� ����''''''''''''''''''''

                //�ڿ��κ��� ��ġ�����ʴ´ٸ� countȮ���� �ߺ��Ǵ� ���ڿ���ŭ ��������
                //�߰��Ǵ� ���ڸ�ŭ ��������
                else {
                    len -= i * count;
                    if (count)     len += to_string(count + 1).length();
                    j += z - 1;
                    break;
                }
                // �ѹ��̶� ������ �Ȼ��¿��� �ڿ��� ����� �ȵȴٸ�
                //������ �߰��ϰ� �������� �ڿ� �߰�
                if (j + z + i >= s.length()) {
                    len -= i * count;
                    len += to_string(count + 1).length();
                    j += z;
                }
            }
        }
        //���ڿ� ���̸� ���ؼ� �������ٸ� �����ɷ� ����
        if (len < answer)    answer = len;
    }
    return answer;
}




void print(string s, int answer) {
    int t = solution(s);
    if (answer == t)
        cout << "����" << endl;
    else
        cout << "Ʋ��" << endl;
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