/* 블랙잭 : Sample */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// prev_permutation()을 활용한 조합을 이용한 풀이
int blackJackC(int n, int m, vector<int> &card)
{
    int ans = 0; //정답

    vector<bool> is_selected(n, false); //고른 카드가 true인 경우 저장
    for (int i = 0; i < 3; i++)         // 3번 반복 : 가장 가까운 카드 3장이니까
    {
        is_selected[i] = true; // 3장 카드 고른 것(true)으로 초기화
    }

    do
    {
        int sum = 0;                // 고른 3장의 카드 합 저장
        for (int i = 0; i < n; i++) // 카드의 개수만큼 반복
        {
            if (is_selected[i]) // 값이 true이면...
            {
                sum += card[i]; // 카드에 쓰여있는 숫자를 sum에 더하기
            }
        }

        if (sum <= m) // 고른 3장 카드 합이 m보다 작으면...
        {
            ans = max(ans, sum); // 기존 ans보다 큰 경우 ans를 sum으로 갱신
        }
    } while (prev_permutation(is_selected.begin(), is_selected.end())); // 현재 나와 있는 수열에서 인자로 넘어간 범위에 해당하는 이전 순열
    return ans;                                                         // 정답 반환
}

// // 3중 for문 풀이
// int blackJackFor(int n, int m, vector<int> &card)
// {
//     int ans = 0; //정답

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             for (int k = j + 1; k < n; k++)
//             {
//                 int sum = card[i] + card[j] + card[k];
//                 if (sum > m)
//                 {          // m을 넘었다면
//                     break; //(생각해보세요) 바로 return ans; 를 하면 어떻게 될까요?
//                 }
//                 ans = max(ans, sum);
//             }
//         }
//     }
//     return ans;
// }

int main()
{
    int n, m; // n : 카드의 개수, m : 숫자

    cin >> n >> m;              // n,m 입력받기
    vector<int> card(n, 0);     // 카드에 쓰여 있는 수들 저장 vector
    for (int i = 0; i < n; i++) // 카드 개수만큼 반복
    {
        cin >> card[i]; // 카드에 쓰여있는 수들 입력받기
    }

    int ans = blackJackC(n, m, card); // 연산 결과 ans에 저장

    cout << ans; // 연산 결과 출력
    return 0;
}