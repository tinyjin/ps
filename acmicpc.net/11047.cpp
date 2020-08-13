#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int cnt = 0;
    int N, K;
    cin >> N >> K;

    vector<int> coins;

    for (int i = 0; i < N; i++) {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    sort(coins.begin(), coins.end(), greater<int>());

    for (int coin : coins) {
        cnt += K / coin;
        K %= coin;
    }

    cout << cnt << endl;

    return 0;
}
