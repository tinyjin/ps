/* https://www.acmicpc.net/problem/1476
 * Exhaustive Search
 * http://boj.kr/f51209e94d524291a183208da49688f7
 * */

#include <iostream>

using namespace std;

int main() {
    int E, S, M;
    int e = 0, s = 0, m = 0;
    int cnt = 0;

    cin >> E >> S >> M;

    while (true) {
        cnt++;

        e++;
        s++;
        m++;

        if (e > 15) e = 1;
        if (s > 28) s = 1;
        if (m > 19) m = 1;

        if (e == E && s == S && m == M) {
            break;
        }
    }

    cout << cnt << endl;
    return 0;
}
