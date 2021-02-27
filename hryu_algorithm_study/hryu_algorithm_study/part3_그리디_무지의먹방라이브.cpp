// 와우 넘 어려웡
// 우선 순위 큐 이용?
// 우선 순위 큐 찾아보고 생각해보기
// 카카오 문제



		/*
		1초 [7, 6, 4] - 2초 [7, 5, 4] - 3초 [7, 5, 3] - 4초 [6, 5, 3] -5초 [6, 4, 3] - 6초 [6, 4, 2] - 7초 [5, 4, 2] -

        8초 [5, 3, 2] - 9초 [5, 3, 1] - 10초 [4, 3, 1] - 11초 [4, 2, 1] - 12초 [4, 3, 0](3번째 음식 사라짐) -

            13초 [3, 2, 0] - 14초 [3, 1, 0], - 15초 [2, 1, 0](방송중단, 마지막은 1번음식을 먹었으므로 다음은 2번음식)

            16초 [2, 0, 0] (2번음식 다먹음)
		*/


#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second; //second는 번호
}

int solution(vector<int> food_times, long long k) {

    // 2번 해결
    long long summary = 0;


    // 전체 음식을 먹는 시간보다 k가 크거나 같다면 -1
    for (int i = 0; i < food_times.size(); i++) {
        summary += food_times[i];
    }
    if (summary <= k) return -1;

    // 1번 해결
    // 시간이 작은 음식부터 빼야 하므로 우선순위 큐 이용
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < food_times.size(); i++) {
        // (음식시간, 음식번호)형태로 우선순위 큐에 삽입
        pq.push({ -food_times[i], i + 1 }); // 남은음식의수가 가장작은게 맨위, 인덱스는 1부터 시작
    }

    // 2번 해결
    // 알고리즘 시작 , 초기화 부분
    summary = 0;// 먹기위해 사용한 시간
    long long previous = 0; // 직전에 다 먹은 음식 시간
    long long length = food_times.size(); //  남은 음식의 개수
    //summary + (현재의 음식 시간-이전음식시간)*현재남은음식개수를 k와 비교
    while (summary + ((-pq.top().first - previous) * length) <= k) {
        int now = -pq.top().first;
        pq.pop();
        summary += (now - previous) * length;
        length -= 1; // 다 먹은 음식 제외
        previous = now; // 이전 음식 재설정
    }

    // 3번 해결
    //남은 음식 중에서 몇번째 음식인지 확인하여 출력
    vector<pair<int, int> > result;
    while (!pq.empty()) {
        int food_time = -pq.top().first;
        int num = pq.top().second;
        pq.pop();
        result.push_back({ food_time, num }); //벡터에 넣는이유는 남은 음식이 여러개일수있으니까
    }
    sort(result.begin(), result.end(), compare);// 음식의 번호 기준으로 정렬
    return result[(k - summary) % length].second;// 위 알고리즘에서 summary는 k 보다 작게 

}