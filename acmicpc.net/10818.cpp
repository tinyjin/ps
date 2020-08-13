#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    vector<int> counts;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        counts.push_back(tmp);
    }

    sort(counts.begin(), counts.end());

    cout << counts[0] << " " << counts[counts.size() - 1];
}

// 메모
// 100만건의 입력이 발생할 수 있어
// 모두 입력받고 정렬해서 앞,뒤 값을 출력하면 '시간 초과'가 뜰줄 알았는데, 통과했다.
// 하지만 굳이 정렬하지 않고, min과 max를 각각 큰 값과 작은 값으로 초기화한 뒤
// 입력 받을 때마다 대소를 비교해서 최종 출력해도 되는 문제
// 필요없는 정렬이 발생했으므로, 실무에서 구현할 때는 가급적 연산횟수가 적은 방향으로 작업하자.
