#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tieNumber(vector<int> &arr) {
    int total = 0;
    int size = arr.size();
    for (int i = 0; i < size - 1; i += 2) {
        total += arr[i] * arr[i + 1];
    }
    //하나 남은 수 더해줌
    if (size % 2) {
        total += arr[size - 1];
    }
    return total;
}

int main() {
    int n, x, cnt1 = 0;

    //입력
    cin >> n;
    vector<int> arr_pos, arr_neg;
    while (n--) {
        cin >> x;
        if (x > 1) {
            arr_pos.push_back(x);
        } else if (x < 1) {
            arr_neg.push_back(x);
        } else {
            cnt1++;
        }
    }

    //절댓값이 큰 순으로 정렬
    sort(arr_pos.begin(), arr_pos.end(), greater<>());
    sort(arr_neg.begin(), arr_neg.end());

    //연산 & 출력
    cout << cnt1 + tieNumber(arr_pos) + tieNumber(arr_neg);
    return 0;
}