# include <stdio.h>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
set<int> s; // ��ǰ ��ü ���� ���� 
vector<int> targets;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int target;
        cin >> target;
        targets.push_back(target);
    }
    // �մ��� Ȯ�� ��û�� ��ǰ ��ȣ Ȯ��
    for (int i = 0; i < m; i++) {
        // s.find() ã�� ���� ������ �ش� ��ġ�� iterator ��ȯ, �ƴϸ� s.end()��ȯ 
        if (s.find(targets[i]) != s.end()) {
            cout << "yes" << ' ';
        }
        else cout << "no" << ' ';
    }
}