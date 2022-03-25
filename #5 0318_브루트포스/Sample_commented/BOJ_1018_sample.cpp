/* 체스판 다시 칠하기 : Sample */

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 64; // 체스판 칸 개수 (8*8)

int chessChange(int row, int col, vector<vector<char>> &board)
{
    int b_cnt = 0; // B(black) 상태로 시작하는 체스판 만들기 위한 카운트

    for (int i = 0; i < 8; i++) // 8번 반복 (행)
    {
        for (int j = 0; j < 8; j++) // 8번 반복 (열)
        {
            if ((i + j) % 2 == 0 && board[row + i][col + j] != 'B') // i+j 짝수 & [row+i][col+j] 칸의 상태가 B가 아니면...
            {
                b_cnt++; // B(black) 상태로 시작하는 체스판 만들기 위한 카운트 증가
            }
            else if ((i + j) % 2 && board[row + i][col + j] != 'W') // i+j 홀수 & [row+i][col+j] 칸의 상태가 W가 아니면...
            {
                b_cnt++; // B(black) 상태로 시작하는 체스판 만들기 위한 카운트 증가
            }
        }
    }

    //최솟값 리턴
    if (b_cnt > SIZE / 2) // B(black) 상태로 시작하는 체스판 만들기 위한 카운트가 크기의 반을 넘으면...
    {
        return SIZE - b_cnt; // 크기에서 b_cnt 빼기
    }
    return b_cnt; // B(black) 상태로 시작하는 체스판 만들기 위한 카운트 반환
}

int main()
{
    int n, m;           // 8보다 크거나 같고, 50보다 작거나 같은 자연수
    int ans = SIZE + 1; // 정답은 체스판 칸 개수 + 1 로 초기화

    cin >> n >> m;                                  // n, m 입력받기
    vector<vector<char>> board(n, vector<char>(m)); // 행: n, 열: m
    for (int i = 0; i < n; i++)                     // n만큼 반복
    {
        for (int j = 0; j < m; j++) // m만큼 반복 -> 결과적으로 이 루프는 n*m만큼 반복
        {
            cin >> board[i][j]; // 보드의 상태 입력 받기 (w : white, b : black)
        }
    }

    for (int i = 0; i <= n - 8; i++) // n-8 만큼 반복
    {
        for (int j = 0; j <= m - 8; j++) // m-8만큼 반복
        {
            int cnt = chessChange(i, j, board); // 시작 인덱스가 (i,j)인 체스판 만드는 최솟값 연산
            ans = min(ans, cnt);                // 최솟값 갱신
        }
    }

    cout << ans << '\n'; // 정사각형 개수의 최솟값 출력
    return 0;
}