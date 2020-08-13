#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> paper;
int whiteCount = 0;
int blueCount = 0;
int N;

void cut(int cnt) {
    if (cnt > N) return;
    int M = N / cnt;

    vector<int> dividers;

    for (int i = 0; i < N; i++) {
        if ((i + 1) % M == 0) {
            dividers.push_back(i + 1);
        }
    }

    for (int x : dividers) {
        for (int y : dividers) {
            int value = paper[x - M][y - M];
            bool flag = true;

            if (value == 3) continue;

            for (int i = x - M; i < x; i++) {
                for (int j = y - M; j < y; j++) {
                    int v = paper[i][j];
                    if (value != v) {
                        flag = false;
                        break;
                    }
                }

                if (!flag) break;
            }

            if (flag) {
                for (int i = x - M; i < x; i++) {
                    for (int j = y - M; j < y; j++) {
                        paper[i][j] = 3;
                    }
                }

                if (value == 0) {
                    whiteCount++;
                }

                if (value == 1) {
                    blueCount++;
                }
            }
        }
    }

    cut(cnt * 2);
}


int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        vector<int> v;
        paper.push_back(v);

        for (int j = 0; j < N; j++) {
            int tmp;
            cin >> tmp;

            paper[i].push_back(tmp);
        }
    }

    cut(1);

    cout << whiteCount << endl;
    cout << blueCount << endl;

    return 0;
}

/* 메모 - 분할 정복 */
// 색종이를 탐색하기 위한 조각을
// 기준에 따라 N개로 나뉘었을 때
// 같은 행의 첫번째 조각이 이미 검증(코드상 3표기)되었을 때
// break 시켜 다음 조각이 판정되지 못항여 '틀렸습니다'가 떴었음.
// 무엇 때문에 틀렸는지 몰라 헤멨었지만, 코드를 찬찬히 다시 읽어보고
// break 문을 continue 문으로 바꾸어 '맞았습니다!!'



/* 구현 매커니즘 */
// 문제(정삭각형 범위 내 값이 모두 같은가?)가 풀리지 않을 때 마다
// 색종이의 가로/세로를 잘라 작은 문제로 다시 푸는
// 매커니즘을 가지고 있기 떄문에, '분할정복' 알고리즘으로 해결함.

// cnt를 1부터 N까지 증가시키고
// 재귀함수로 반복하며, 각 cnt * cnt 만큼의 종이 조각이 나오도록 플로우를 구성했다.
// 8 * 8의 색종이가 있다고 가정하면
// cnt가 1일 때는 divider를 8로, 2일 때는 4, 8 지정하여
// 순회하는 2차원 배열의 세로/가로 인덱스가 divider로 나누어질 때까지의
// 값을 비교하여 정사각형 단위로 동일한 값을 가지고 있는지 판별했다.

// 판별이 끝나고 난 다음에는 재귀함수를 호출하여
// cnt가 N보다 커질 때까지
// cnt를 2로 계속 곱해주면서, 분할하여 색종이를 판별하도록 했다.



// 아래는 문제를 풀면서 구현해야 할 매커니즘이 떠오르지 않아
// 색종이와 divider의 후보를 그려가며 문제를 해결할 때 적었던 낙서

/*
    1 -> 8
    2 -> 4, 8
    4 -> 2, 4, 6, 8
    8 -> 1


    0,0 0,1 0,2 0,3 0,4 0,5 0,6 0,7
    1,0 1,1 1,2 1,3 1,4 1,5 1,6 1,7
    2,0 2,1 2,2 2,3 2,4 2,5 2,6 2,7
    3,0 3,1 3,2 3,3 3,4 3,5 3,6 3,7
    */
