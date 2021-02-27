// �Ϳ� �� �����
// �켱 ���� ť �̿�?
// �켱 ���� ť ã�ƺ��� �����غ���
// īī�� ����



		/*
		1�� [7, 6, 4] - 2�� [7, 5, 4] - 3�� [7, 5, 3] - 4�� [6, 5, 3] -5�� [6, 4, 3] - 6�� [6, 4, 2] - 7�� [5, 4, 2] -

        8�� [5, 3, 2] - 9�� [5, 3, 1] - 10�� [4, 3, 1] - 11�� [4, 2, 1] - 12�� [4, 3, 0](3��° ���� �����) -

            13�� [3, 2, 0] - 14�� [3, 1, 0], - 15�� [2, 1, 0](����ߴ�, �������� 1�������� �Ծ����Ƿ� ������ 2������)

            16�� [2, 0, 0] (2������ �ٸ���)
		*/


#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second; //second�� ��ȣ
}

int solution(vector<int> food_times, long long k) {

    // 2�� �ذ�
    long long summary = 0;


    // ��ü ������ �Դ� �ð����� k�� ũ�ų� ���ٸ� -1
    for (int i = 0; i < food_times.size(); i++) {
        summary += food_times[i];
    }
    if (summary <= k) return -1;

    // 1�� �ذ�
    // �ð��� ���� ���ĺ��� ���� �ϹǷ� �켱���� ť �̿�
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < food_times.size(); i++) {
        // (���Ľð�, ���Ĺ�ȣ)���·� �켱���� ť�� ����
        pq.push({ -food_times[i], i + 1 }); // ���������Ǽ��� ���������� ����, �ε����� 1���� ����
    }

    // 2�� �ذ�
    // �˰��� ���� , �ʱ�ȭ �κ�
    summary = 0;// �Ա����� ����� �ð�
    long long previous = 0; // ������ �� ���� ���� �ð�
    long long length = food_times.size(); //  ���� ������ ����
    //summary + (������ ���� �ð�-�������Ľð�)*���糲�����İ����� k�� ��
    while (summary + ((-pq.top().first - previous) * length) <= k) {
        int now = -pq.top().first;
        pq.pop();
        summary += (now - previous) * length;
        length -= 1; // �� ���� ���� ����
        previous = now; // ���� ���� �缳��
    }

    // 3�� �ذ�
    //���� ���� �߿��� ���° �������� Ȯ���Ͽ� ���
    vector<pair<int, int> > result;
    while (!pq.empty()) {
        int food_time = -pq.top().first;
        int num = pq.top().second;
        pq.pop();
        result.push_back({ food_time, num }); //���Ϳ� �ִ������� ���� ������ �������ϼ������ϱ�
    }
    sort(result.begin(), result.end(), compare);// ������ ��ȣ �������� ����
    return result[(k - summary) % length].second;// �� �˰��򿡼� summary�� k ���� �۰� 

}