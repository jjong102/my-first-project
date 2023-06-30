#if 0
#include<stdio.h>



#define MAZE_SIZE 6
#define STACK_SIZE MAZE_SIZE*MAZE_SIZE

// row, column 좌표를 저장하는 데이터형
typedef struct {
    int r;
    int c;
}LOC;

LOC stack[STACK_SIZE];
int top = -1;

int isFull(void) {
    return (top == (STACK_SIZE - 1));
}
int isempty() {
    return (top == -1);
}

char maze[MAZE_SIZE][MAZE_SIZE] = {
   {'1','1','1','1','1','1'},
   {'e','0','1','0','0','1'}, // e = entrance
   {'1','0','0','0','1','1'},
   {'1','0','1','0','1','1'},
   {'1','0','1','0','0','x'}, // x = exit
   {'1','1','1','1','1','1'},
};

// 미로를 예쁘게 출력해보는 함수
void printMaze() {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

//push할 좌표 (_r, _c)를 받아서 앞으로 갈 곳들만 stack에 push한다
// 벽 ('1'), 지나온 곳('.'), 음수 좌표등은 모두 제외.
void push(int _r, int _c) {
    //음수 좌표를 거르자
    if ((_r < 0) || (_c < 0)) {
        return; // 음수좌표 무시
    }
    // 벽, 지나온 곳 걸러내자
    if ((maze[_r][_c] == '1') || (maze[_r][_c] == '.')) {
        return;
    }
    //full인지 검사
    if (isFull()) {
        return;
    }

    // 이제 진짜로 push
    LOC temp = { _r, _c };
    top++;
    stack[top] = temp;

    return;
}

LOC pop(void) {
    //에러조건
    if (isempty()) {
        LOC err_loc = { -1,-1 }; // 스택이 비었다는 의미
        return err_loc;
    }
    // 정상상태 
    LOC result = stack[top];
    top--;
    return result;
}

int main() {

    printMaze();

    LOC cur = { 1,0 }; // 시작위치
    while (1) {
        // 탈출조건부터 --> x에 도착하면 끝
        if (maze[cur.r][cur.c] == 'x') {
            printf("길 찾았음... 집간다.\n");
            return 0;
        }

        // 내가 다녀갔음을 표시
        maze[cur.r][cur.c] = '.'; // 나의 발자국을 남긴다 왜냐? 다시 오지 않기 위해서

        //잠깐, 지도를 보자
        printMaze();

        // 현재 위치에서 갈 수 있는 곳들을 모두 stack에 집어 넣는다.
        // 모두 4군데, 상/하/좌/우
        push(cur.r - 1, cur.c);
        push(cur.r + 1, cur.c);
        push(cur.r, cur.c - 1);
        push(cur.r, cur.c + 1);

        // 스택에 저장된 좌표를 꺼내서 현재 위치로 삼는다.
        cur = pop();

        //스택이 비어있는지 확인, 만약 비었다면 ===> 길없음.
        if ((cur.r == -1) && (cur.c == -1)) {
            printf("길없음");
            return -1;
        }

    };

    return 0;
}
#endif