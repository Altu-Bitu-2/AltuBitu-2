#include <iostream>
#include <vector>

using namespace std;

int steal(int n, int m, int k, vector<int> &house) {
    //윈도우 초기화
    int money = 0;
    for (int i = 0; i < m; i++) {
        money += house[i];
    }
    int ans = money < k; //훔쳐야 하는 집 초기화

    if (n == m) { //훔칠 수 있는 경우 딱 1개인 경우
        return ans;
    }
    for (int i = m; i < n + m - 1; i++) {
        money -= house[i - m];
        money += house[i % n];
        if (money < k) {
            ans++;
        }
    }
    return ans;
}

int main() {
    int t, n, m, k;

    cin >> t;
    while (t--) {
        //입력
        cin >> n >> m >> k;
        vector<int> house(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> house[i];
        }

        //연산 & 출력
        cout << steal(n, m, k, house) << '\n';
    }
    return 0;
}