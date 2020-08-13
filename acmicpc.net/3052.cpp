#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> S;

    for (int i = 0; i < 10; i++) {
        int n;
        cin >> n;

        S.insert(n % 42);
    }

    cout << S.size() << endl;
}

// 메모
// 중복 문제에는 set을 쓰면 정말 편하지!
