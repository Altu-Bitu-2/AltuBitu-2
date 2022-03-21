/* 외계인의 기타 연주 : Sample */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int n, p, guitar_string, fret, ans = 0;

    cin >> n >> p;                // 음의 수 & 프렛 수 입력받기
    vector<stack<int>> guitar(7); // 1번 줄부터 6번줄 까지 음 저장
    for (int i = 1; i <= 6; i++)  // 음 개수만큼 6번 반복
    {
        guitar[i].push(0); //스택에 미리 0을 넣기
    }
    while (n--) // 음의 수가 0이 될때까지 감소하며...
    {
        cin >> guitar_string >> fret; // 줄의 번호 & 프렛 번호 입력받기

        while (guitar[guitar_string].top() > fret) //프렛에서 손가락 떼기
        {
            ans++;                       // 결과값 증가
            guitar[guitar_string].pop(); // 음 빼기
        }
        if (guitar[guitar_string].top() != fret) //프렛 누르기
        {
            ans++;                            // 결과값 증가
            guitar[guitar_string].push(fret); // 음 넣기
        }
    }

    cout << ans; // 결과 출력
}
