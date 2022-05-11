/* 마인크래프트 : Sample */

#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;

int mineLand(int n, int m, int b, int height, vector<vector<int>> &land) {
    int tot_time = 0;   // 총시간 초기화
    for (int i = 0; i < n; i++) {   // 세로 크기만큼 반복
        for (int j = 0; j < m; j++) {   // 가로 크기만큼 반복
            if (land[i][j] > height) { // 블록 제거 : 땅의 높이가 확인하는 높이보다 높을 때
                b += (land[i][j] - height); // 블록개수 업데이트
                tot_time += 2 * (land[i][j] - height);  // 총 시간 업데이트
            } else if (land[i][j] < height) { // 블록 쌓기 : 땅의 높이가 확인하는 높이보다 낮을 때
                b -= (height - land[i][j]); // 블록개수 업데이트
                tot_time += (height - land[i][j]);  // 총 시간 업데이트
            }
        }
    }
    if (b < 0) //최종적으로 블럭이 음수면 불가능한 높이
        return INF + 1;
    return tot_time;    // 총 시간 반환
}

int main() {
    int n, m, b, min_height = 256, max_height = 0;  // 세로크기, 가로크기, 블록개수...

    cin >> n >> m >> b;     // 세로&가로 크기, 블록 개수 입력받기
    vector<vector<int>> land(n, vector<int>(m, 0)); // 땅의 높이 입력받을 위치
    for (int i = 0; i < n; i++) {   // 세로 크기만큼 반복
        for (int j = 0; j < m; j++) {   // 가로 크기만큼 반복
            cin >> land[i][j];  // 땅의 높이 입력받기
            min_height = min(min_height, land[i][j]); //제일 낮은 땅 높이
            max_height = max(max_height, land[i][j]); //제일 높은 땅 높이
        }
    }

    int min_time = INF, height = 0;     // 최단 시간, 높이
    for (int i = min_height; i <= max_height; i++) {    // 제일 낮은 땅부터 제일 높은 땅 높이까지..
        int t = mineLand(n, m, b, i, land);     // 연산
        if (t <= min_time) { // 가장 빨리 작업이 끝나는 높이
            min_time = t;   // 땅을 고르는 데 걸리는 최단 시간 저장
            height = i;     // 땅의 높이 저장
        }
    }

    cout << min_time << ' ' << height;  // 연산 결과 출력
    return 0;
}