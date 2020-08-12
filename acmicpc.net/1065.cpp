#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    int cnt = 0;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int n = i;

        vector<int> numbers;
        do {
            numbers.push_back(n % 10);
            n /= 10;
        } while (n > 0);

        if (numbers.size() <= 1) {
            cnt++;
            continue;
        }

        int diff = numbers[1] - numbers[0];
        bool flag = true;
        for (int j = 1; j < numbers.size(); j++) {
            int _diff = numbers[j] - numbers[j - 1];

            if (diff != _diff) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}

// 브루트 포스 완전 탐색
