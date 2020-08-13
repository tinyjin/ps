#include <cstdio>
#include <cstring>

int main() {
    int M;
    int bin = 0;

    scanf("%d",&M);

    for(int i = 0; i < M; i++) {
        char cmd[10];
        scanf("%s",cmd);

        int N;

        if (strcmp(cmd, "all") != 0 && strcmp(cmd, "empty") != 0) {
            scanf("%d",&N);
        }

        if (strcmp(cmd, "add") == 0) {
            bin = bin | (1 << N);
        } else if (strcmp(cmd, "remove") == 0) {
            bin = bin & ~(1 << N);
        } else if (strcmp(cmd, "check") == 0)  {
            int check = bin & (1 << N);

            if (check > 0) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        } else if (strcmp(cmd, "toggle") == 0) {
            bin = bin ^ (1 << N);
        } else if (strcmp(cmd, "all") == 0) {
            bin = 2097150;
        } else if (strcmp(cmd, "empty") == 0) {
            bin = 0;
        }
    }

    return 0;
}

// 메모
// 비트 와이즈 연산을 쉽게 외우자
// 기본 베이스 (1 << N)
// ON 시킬 때는 OR 연산
// OFF 시킬 때는 앤'낫'
// TOGGLE 시킬 때는 XOR
// 조회할 때는 앤드 '&'


// C++ IO 스타일로 cin/cout 을 사용해서 구현했더니 27% 정도에서 '시간초과' 발생
// C++ IO 성능을 올려주는 sync_with_stdio, tie 메소드를 사용했지만 50% 정도에서 '시간초과' 발생
// 아예 C 스타일로 string -> char[], cout -> printf, cin -> scanf로 비꾸어 '성공'

// 입력값이 100만개 이상일 경우에는 IO를 C 스타일로 작성하자
