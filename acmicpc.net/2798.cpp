#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define CNT 3

int N, M;
int result = 0;

vector<int> cards;
vector<int> selects;

void pick(int cnt) {
    if (cnt == CNT) {
        int sum = 0;
        for (int card : selects) {
            sum += card;
        }

        if (sum <= M && abs(M - sum) <= abs(M - result)) {
            result = sum;
        }

        return;
    }

    for (int i = 0; i < N; i++) {
        int card = cards[i];
        if (find(selects.begin(), selects.end(), card) != selects.end()) continue;

        selects.push_back(card);
        pick(cnt+1);
        selects.pop_back();

    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        cards.push_back(tmp);
    }

    pick(0);
    cout << result;

    return 0;
}

// 메모
// 'M을 넘지 않으면서'라는 문제의 조건을 제대로 살피지 못하고
// 특정 경우의 수의 SUM이 M이 넘을 때도 출력값으로 반영하도록 예외처리가 누락되어
// 두번의 '틀렸습니다'를 맛보았다.
