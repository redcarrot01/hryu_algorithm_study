// 볼링공고르기, 만들수없는금액, 무지먹방라이브 풀기
//만들수없는금액
/*
만들수없는 양의 정수금액중 최솟값
5
3 2 1 1 9 -> 8
3
3 5 7 -> 1

조건 : 
입력
1 ~ 1000
각 화폐단위 1,000,000 이하

- 1. 주어진 동전 오름차순
- 2. target =1 로 지정
- 3. target 매번 반복하여, 주어진 동전 더하기
- 4. target < 주어진 동전 , target 반환
(target이 가지고 있는 동전리스트 중 어떤수보다 작은수라면, 그 아래수까지는 만들수있음)
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

// 볼링공 고르기
/*
두사람은 서로 무게가 다른 공을 고른다
공의 번호는 1번부터 순서대로
n =5 m=3(무게)이라면
무게 1 3 2 3 2 (1~5 순서대로 번호)
두사람이 공고르는 경우의수 8

조건 
입력 n : 1~1000, m : 10

시간복잡도 : 경우의수비교 O(N*N) = 1,000,000 고려 안해도 됨

SOL
- 볼링공의 무게 별로 개수 집계
- 최소무게 1 부터 최대무게 m까지 반복문
 {	전체 볼링골 개수 = 전체 볼링골 개수 - 무게가 i인 볼링골 개수
	반환값 += 무게가 i인 볼링골 개수 * 전체볼링골 개수
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
//		arr[x] += 1; // 집계하는 거
//	}
//	for (int i = 1; i <= m; i++) { // 최소무게1 부터 최대무게m까지 반복
//		n = n - arr[i]; 
//		result += arr[i] * n;
//	}
//	cout << result;
//
//}

// 무지 먹방 라이브
/*
food_times 각 음식 먹는데 필요한 시간이 음식 번호 순대로 있는 배열
k 중단된 시간
더 섭취할 음식 없다면 -1 반환

방법 : 우선순위 큐
핵심 포인트
- 시간 적게 걸리는 음식부터 확인하는 그리디
- 음식의 수를 줄인 뒤에는 k시간 이후에 어떤 음식 먹으면 되는지 확인
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
//    return a.second < b.second; //second는 번호
//}
//
//int solution(vector<int> food_times, long long k) {
//
//    // 2번 해결
//    long long summary = 0;
//
//
//    // 전체 음식을 먹는 시간보다 k가 크거나 같다면 -1
//    for (int i = 0; i < food_times.size(); i++) {
//        summary += food_times[i];
//    }
//    if (summary <= k) return -1;
//
//    // 1번 해결
//    // 시간이 작은 음식부터 빼야 하므로 우선순위 큐 이용
//    priority_queue<pair<int, int>> pq;
//    for (int i = 0; i < food_times.size(); i++) {
//        // (음식시간, 음식번호)형태로 우선순위 큐에 삽입
//        pq.push({ -food_times[i], i + 1 }); // 남은음식의수가 가장작은게 맨위, 인덱스는 1부터 시작
//    }
//
//    // 2번 해결
//    // 알고리즘 시작 , 초기화 부분
//    summary = 0;// 먹기위해 사용한 시간
//    long long previous = 0; // 직전에 다 먹은 음식 시간
//    long long length = food_times.size(); //  남은 음식의 개수
//    //summary + (현재의 음식 시간-이전음식시간)*현재남은음식개수를 k와 비교
//    while (summary + ((-pq.top().first - previous) * length) <= k) {
//        int now = -pq.top().first;
//        pq.pop();
//        summary += (now - previous) * length;
//        length -= 1; // 다 먹은 음식 제외
//        previous = now; // 이전 음식 재설정
//    }
//
//    // 3번 해결
//    //남은 음식 중에서 몇번째 음식인지 확인하여 출력
//    vector<pair<int, int> > result;
//    while (!pq.empty()) {
//        int food_time = -pq.top().first;
//        int num = pq.top().second;
//        pq.pop();
//        result.push_back({ food_time, num }); //벡터에 넣는이유는 남은 음식이 여러개일수있으니까
//    }
//    sort(result.begin(), result.end(), compare);// 음식의 번호 기준으로 정렬
//    return result[(k - summary) % length].second;// 위 알고리즘에서 summary는 k 보다 작게 
//
//}
///