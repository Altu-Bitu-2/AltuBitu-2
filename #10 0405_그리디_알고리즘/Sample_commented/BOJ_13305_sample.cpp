#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll greedyOil(vector<pair<ll, ll>> &city, int n) {
    ll cur_cost = city[0].second, tot_cost = 0;

    for (int i = 0; i < n; i++) {   // 도시의 개수만큼 반복
        if (city[i].second < cur_cost) { // 이 도시의 기름값이 더 저렴하면 교체
            cur_cost = city[i].second;  // 더 저렴한 기름값으로 cur_cost 업데이트
        }
        tot_cost += (cur_cost * city[i].first); // 이동 비용 더하기
    }
    return tot_cost;    // 총 비용 반환
}

int main() {
    int n;  // 도시의 개수

    cin >> n;   // 도시의 개수 입력받기
    vector<pair<ll, ll>> city(n, {0, 0});   // 도로의 길이&주유소의 리터당 가격 저장하는 vector
    for (int i = 0; i < n - 1; i++) {   // 도시의 개수-1만큼 반복
        cin >> city[i].first;   // 도로의 길이 입력받기
    }
    for (int i = 0; i < n; i++) {   // 도시의 개수만큼 반복
        cin >> city[i].second;  // 주유소의 리터 당 가격 입력받기
    }

    cout << greedyOil(city, n);     // 제일 왼쪽 도시에서 제일 오른쪽 도시로 가는 최소비용 연산 + 출력
    return 0;
}