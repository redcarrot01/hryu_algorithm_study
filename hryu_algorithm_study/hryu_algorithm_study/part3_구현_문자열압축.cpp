# include <stdio.h>
# include <iostream>
# include <vector>
# include <string>

using namespace std;

int solution(string s) {
	int answer = s.size();
	// 1�� �������� ������� �÷����鼭 Ȯ��
	for (int step = 1; step < s.size() / 2; step++) {
		string comp = "";
		string pre = s.substr(0, step); //�տ������� step��ŭ�� ���ڿ� ����
		int cnt = 1;
		// ���� (step)ũ�� ��ŭ ������Ű�� ���� ���ڿ��� ��
		for (int j = step; j < s.size(); j += step) {
			//���� ���¿� �����ϴٸ� ����Ƚ���߰�
			if (pre == s.substr(j, step)) cnt += 1;
			//�ٸ� ���ڿ��� ���Դٸ�
			else {
				comp += (cnt >= 2) ? to_string(cnt) + pre : pre;
				pre = s.substr(j, step); // �ٽ� ���� �ʱ�ȭ
				cnt = 1;
			}
		}
	}
}


