#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll INF = 3 * 1e9 + 1;

ll min_diff = INF;

//다른 위치에서 시작하여 서로를 향해 가까워지는 투 포인터
pair<ll, ll> liquid(vector<ll> &arr, ll fixed, int left, int right) {
    pair<ll, ll> ans;   
    ans = make_pair(INF, INF);

    while (left < right) {  // 주어진 범위만큼 반복
        ll mix = fixed + arr[left] + arr[right];    
        if (mix == 0) {     // 0인 경우
            return make_pair(arr[left], arr[right]);    
        }
        if (abs(mix) < min_diff) {  // mix의 절대값이 min_diff보다 작을 경우
            min_diff = abs(mix);    // min_diff 업데이트
            ans = make_pair(arr[left], arr[right]);     // ans에 새로운 값 저장
        }
        if (mix > 0) {  // 양수인 경우
            right--;    // 왼쪽으로 한 칸 이동
        } else {
            left++;     // 오른쪽으로 한 칸 이동
        }   
    }
    return ans; // ans 반환
}

int main() {
    int n;      // 전체 용액의 수 n

    //입력
    cin >> n;   // 전체 용액의 수 입력받기
    vector<ll> arr(n, 0);   // 용액의 특성값 입력받을 위치
    for (int i = 0; i < n; i++) {   // 용액의 수만큼 반복
        cin >> arr[i];  // 용액의 특성값 입력받기
    }

    //연산  
    sort(arr.begin(), arr.end());   // 용액의 특성값 오름차순으로 정렬
    tuple<ll, ll, ll> ans;  // 출력할 세 특성값 저장 위치
    for (int i = 0; i < n - 2; i++) {   // n-2만큼 반복
        pair<ll, ll> p = liquid(arr, arr[i], i + 1, n - 1); //arr[i] 용액은 고정
        if ((p.first != INF) && (p.second != INF)) { //최솟값이 갱신된 경우
            ans = make_tuple(arr[i], p.first, p.second);    // ans 값 저장
        }
    }

    //출력
    cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans);    // 저장된 ans 출력
    return 0;
}