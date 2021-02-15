# include <stdio.h>
# include <iostream>
# include <vector>
# include <string>


using namespace std;
/*
1. ���ڿ� �ڸ��� ������ 1���� �����ؼ� ��� �غ��� �ȴ�
������ ���ڿ��� ������ �ݺ��� Ŀ���� ���� �� ������� �����Ƿ� 1~���ڿ�����/2 ������ ��

2. i���� �ڸ��ٰ� ���� ��, ���ڿ��� ó������ i����ŭ���� ���ڿ� ������ ��� �˻�
(i���� ������ �������� �ʰ�, ���� �κ��� �������� �߰������� �ٿ��ش�)

3. i���� �ڸ� ���ڿ��� �ٷ� �̾ ��Ÿ���ٸ�, cnt ���� ������Ų��
�׷��� �ʴٸ�, ����� ����� ������ ���ڿ�(result)�� ���ڿ� ������ �ٿ��ְ�
���ڿ� ������ ���� j������ i���� ������Ʈ�Ѵ�
�̋�, ���� ���ǿ� ���� �� ���ڿ� ������ ���� �����ٸ�(cnt > 1) cnt�� ���ڿ� �տ�
�ٿ��� result�� �߰��ϰ� cnt=1�� �ٽ� �ʱ�ȭ�Ѵ�
 
*/


int solution(string s) {
	int len = s.size(); //���ڿ� ��ü ����
	int answer = len; // ó�� ���ڿ� ����
	int n = len / 2; // ���� �ִ� ����

	//i�� ������ �߶� ����
	for (int i = 1; i <= n; i++) {
		int len = s.length();

		// i�� ������ �߶� ������ �� ��������� ���ڿ�
		string result = "";

		// �ڸ� ���ڿ� ����
		string ss = s.substr(0, i);

		int cnt = 1;

		// �տ��� �ڸ� ���ڿ� ������ ������ �޺κ� (j�� ���ں���) ���ڿ��� �˻�
		for (int j = i; j <= len; j += i) {
			// j�� ���� i�� ��ŭ�� ���ڿ� ������ �Ȱ��� ��� cnt ����
			if (ss == s.substr(j, i)) {
				cnt += 1;
			}
			else {
				// �ٸ� ��� �� cnt�� 1�̸� result�� �״�� ss�� ���δ�
				if (cnt == 1) {
					result += ss;
				}
				else {
					// cnt�� 1���� ũ�ٸ� cnt�� ���ڿ� ���� �տ� �ٿ��� result�� �̾��ش�
					result += (to_string(cnt) + ss);
				}
				// ���ڿ� ������ j �� ���� i ���� ����
				ss = s.substr(j, i);
				// cnt �� �ٽ� 1�� �ʱ�ȭ
				cnt = 1;
			}
		}

		// ���ڿ��� i�� ������ �������� �ʴ´ٸ� result�� ������ �κ��� �ٿ���� �Ѵ�
		if ((len % i) != 0) {
			result += s.substr((len / i) * i);
		}
		// �ּڰ��� answer �� ����
		if (answer > result.size()) answer = result.size();
	}
	return answer;
}























// �𸣰ڴ� ���߿� Ǯ��

//// to_string : int to string
//using namespace std;
//
//
//int solution(string s) {
//    int answer = s.length();
//    //����� �� Ž���ϱ�
//    for (int i = 1; i <= s.length() / 2; i++) {
//        int len = s.length();
//        //���ڿ��� ��ü ���鼭 �ݺ�
//        for (int j = 0; j < s.length(); j++) {
//            //�κ� ���ϱ�
//            for (int count = 0, z = i; j + z < s.length(); z += i) {
//                //�ںκа� ��ġ�Ѵٸ� count ����
//                if (s.substr(j, i) == s.substr(j + z, i))    count++;
//
//
//                // ```````````````` ������� ����''''''''''''''''''''
//
//                //�ڿ��κ��� ��ġ�����ʴ´ٸ� countȮ���� �ߺ��Ǵ� ���ڿ���ŭ ��������
//                //�߰��Ǵ� ���ڸ�ŭ ��������
//                else {
//                    len -= i * count;
//                    if (count)     len += to_string(count + 1).length();
//                    j += z - 1;
//                    break;
//                }
//                // �ѹ��̶� ������ �Ȼ��¿��� �ڿ��� ����� �ȵȴٸ�
//                //������ �߰��ϰ� �������� �ڿ� �߰�
//                if (j + z + i >= s.length()) {
//                    len -= i * count;
//                    len += to_string(count + 1).length();
//                    j += z;
//                }
//            }
//        }
//        //���ڿ� ���̸� ���ؼ� �������ٸ� �����ɷ� ����
//        if (len < answer)    answer = len;
//    }
//    return answer;
//}
//
//
//
//
//void print(string s, int answer) {
//    int t = solution(s);
//    if (answer == t)
//        cout << "����" << endl;
//    else
//        cout << "Ʋ��" << endl;
//}
//
//int main() {
//    print("a", 1);
//    print("aaaaa", 2);
//    print("aaaaaaaaaa", 3);
//    print("aabbaccc", 7);
//    print("ababcdcdababcdcd", 9);
//    print("abcabcdede", 8);
//    print("abcabcabcabcdededededede", 14);
//    print("xababcdcdababcdcd", 17);
//    return 0;
//}

