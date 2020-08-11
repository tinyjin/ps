#include <iostream>

using namespace std;

int main() {
    int N;
    int M;
    int buttons[10];

    fill_n(buttons, 11, 0);

    cin >> N;
    cin >> M;

    // 고장난 버튼 입력
    char inputs[M];
    for (int i = 0; i < M; i++) {
        cin >> inputs[i];
    }

    // 고장난 버튼 체크
    for (int i = 0; i < M; i++) {
        int tmp = inputs[i] - '0';
        buttons[tmp] = 1;
    }

    int min = 500003;
    int num;

    // N의 최대 입력값은 500000이지만, 최대 채널의 제한은 없기 때문에
    // 최악의 경우인 999999를 입력해야하는 상황을 커버하기 위해
    // 약 1000000까지 완전 탐색 진행
    for (int i = 0; i <= 1000000; i++) {
        // 숫자 분리, 사용할 수 없는 버튼이 포함된 경우 continue;
        bool flag = false;
        int n = i;

        do {
            int number = n % 10;
            n /= 10;

            if (buttons[number] == 1) flag = true;
        } while(n > 0);

        if (flag) continue;

        int diff = abs(N - i);
        if (diff < min) {
            min = diff;
            num = i;
        }
    }

    /* min + num의 자리수 = 채널 입력 + (+, -) 조작 조합
     * 기반의 채널 이동의 최소 값
     */

    // num 자리수 구하기
    int n = num;
    int len = 0;
    do {
        n /= 10;
        len++;
    } while(n > 0);

    // 최종 cnt 구하기
    int cnt = min + len;

    // 100번 채널에서 목적지 채널까지 (+, -) 조작으로만 이동할 떄의 버튼 클릭 횟수가
    // 구해진 카운트보다 적으면 해당 횟수를 출력
    int diff = abs(N - 100);
    if (diff < cnt) {
        cout << diff << endl;
        return 0;
    }

    cout << cnt << endl;

    return 0;
}

// 메모
// 처음에 이 문제를 풀려고 할 때
// 5457을 입력받는다고 치면
// 5, 4, 5, 7 이런식으로 자릿수를 나눈 뒤 각 자리수를 순회하며
// 순회된 자리수와 가장 가까운 사용가능한 숫자 버튼과의 차이만큼을 카운팅한 뒤
// cnt에 더하여 답을 도출하려고 했으나
// N의 값에 십의자리 이상부터 사용불가능한 숫자가 있을 경우
// 자리수별로 독립적인 연산을 취해버리니, 오차가 발생해서 failed... 했었음
// ex_ 6이라는 숫자를 사용하지 못할 때 5465가 들어올 때 5460+++++ 로 풀이를 해야하는 것이
// 547-5로 풀이되어버려 9번 입력이 5번 입력으로 풀이되어버리는 문제였다.
// 망각하고 있던 사실(완전 탐색을 이용해야하는 문제다)를 깨닫고 무식하게 풀어버리니 풀렸다.
// 왜 사용하라는 완전 탐색은 사용하지도 않고 어렵게 풀려한 것인가...
