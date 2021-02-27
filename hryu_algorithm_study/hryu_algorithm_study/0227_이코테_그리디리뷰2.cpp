// ����������, ��������±ݾ�, �����Թ���̺� Ǯ��
//��������±ݾ�
/*
��������� ���� �����ݾ��� �ּڰ�
5
3 2 1 1 9 -> 8
3
3 5 7 -> 1

���� : 
�Է�
1 ~ 1000
�� ȭ����� 1,000,000 ����

- 1. �־��� ���� ��������
- 2. target =1 �� ����
- 3. target �Ź� �ݺ��Ͽ�, �־��� ���� ���ϱ�
- 4. target < �־��� ���� , target ��ȯ
(target�� ������ �ִ� ��������Ʈ �� ������� ���������, �� �Ʒ��������� ���������)
*/
//# include <iostream>
//# include <vector>
//# include <algorithm>
//
//using namespace std;
//
//int n;
//vector <int> arr;
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int x;
//		cin >> x;
//		arr.push_back(x);
//	}
//	sort(arr.begin(), arr.end());
//
//	int target = 1;
//	for (int i = 0; i < n; i++) {
//		if (target < arr[i]) break;
//		target += arr[i];
//	}
//	cout << target;
//}

// ������ ����
/*
�λ���� ���� ���԰� �ٸ� ���� ����
���� ��ȣ�� 1������ �������
n =5 m=3(����)�̶��
���� 1 3 2 3 2 (1~5 ������� ��ȣ)
�λ���� ������ ����Ǽ� 8

���� 
�Է� n : 1~1000, m : 10

�ð����⵵ : ����Ǽ��� O(N*N) = 1,000,000 ��� ���ص� ��

SOL
- �������� ���� ���� ���� ����
- �ּҹ��� 1 ���� �ִ빫�� m���� �ݺ���
 {	��ü ������ ���� = ��ü ������ ���� - ���԰� i�� ������ ����
	��ȯ�� += ���԰� i�� ������ ���� * ��ü������ ����
 }
*/

//# include <iostream>
//
//using namespace std;
//
//int n, m;
//int arr[11];
//int result = 0;
//
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		int x;
//		cin >> x;
//		arr[x] += 1; // �����ϴ� ��
//	}
//	for (int i = 1; i <= m; i++) { // �ּҹ���1 ���� �ִ빫��m���� �ݺ�
//		n = n - arr[i]; 
//		result += arr[i] * n;
//	}
//	cout << result;
//
//}

// ���� �Թ� ���̺�
/*
food_times �� ���� �Դµ� �ʿ��� �ð��� ���� ��ȣ ����� �ִ� �迭
k �ߴܵ� �ð�
�� ������ ���� ���ٸ� -1 ��ȯ

��� : �켱���� ť
�ٽ� ����Ʈ
- �ð� ���� �ɸ��� ���ĺ��� Ȯ���ϴ� �׸���
- ������ ���� ���� �ڿ��� k�ð� ���Ŀ� � ���� ������ �Ǵ��� Ȯ��
food_times 3 ,1, 2    k 5    result 1
*/



//#include <vector>
//#include <iostream>
//#include <queue>
//#include <algorithm>
//
//
//using namespace std;
//
//bool compare(pair<int, int> a, pair<int, int> b) {
//    return a.second < b.second; //second�� ��ȣ
//}
//
//int solution(vector<int> food_times, long long k) {
//
//    // 2�� �ذ�
//    long long summary = 0;
//
//
//    // ��ü ������ �Դ� �ð����� k�� ũ�ų� ���ٸ� -1
//    for (int i = 0; i < food_times.size(); i++) {
//        summary += food_times[i];
//    }
//    if (summary <= k) return -1;
//
//    // 1�� �ذ�
//    // �ð��� ���� ���ĺ��� ���� �ϹǷ� �켱���� ť �̿�
//    priority_queue<pair<int, int>> pq;
//    for (int i = 0; i < food_times.size(); i++) {
//        // (���Ľð�, ���Ĺ�ȣ)���·� �켱���� ť�� ����
//        pq.push({ -food_times[i], i + 1 }); // ���������Ǽ��� ���������� ����, �ε����� 1���� ����
//    }
//
//    // 2�� �ذ�
//    // �˰��� ���� , �ʱ�ȭ �κ�
//    summary = 0;// �Ա����� ����� �ð�
//    long long previous = 0; // ������ �� ���� ���� �ð�
//    long long length = food_times.size(); //  ���� ������ ����
//    //summary + (������ ���� �ð�-�������Ľð�)*���糲�����İ����� k�� ��
//    while (summary + ((-pq.top().first - previous) * length) <= k) {
//        int now = -pq.top().first;
//        pq.pop();
//        summary += (now - previous) * length;
//        length -= 1; // �� ���� ���� ����
//        previous = now; // ���� ���� �缳��
//    }
//
//    // 3�� �ذ�
//    //���� ���� �߿��� ���° �������� Ȯ���Ͽ� ���
//    vector<pair<int, int> > result;
//    while (!pq.empty()) {
//        int food_time = -pq.top().first;
//        int num = pq.top().second;
//        pq.pop();
//        result.push_back({ food_time, num }); //���Ϳ� �ִ������� ���� ������ �������ϼ������ϱ�
//    }
//    sort(result.begin(), result.end(), compare);// ������ ��ȣ �������� ����
//    return result[(k - summary) % length].second;// �� �˰��򿡼� summary�� k ���� �۰� 
//
//}
///