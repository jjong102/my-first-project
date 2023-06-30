#include <stdio.h>

#define SSZ 7
int s[SSZ];
int top = -1;

int isEmpty() {
    return (top == -1);
}
int isFull() {
    return (top == (SSZ - 1));
}

void push(int _v) {
    if (isFull()) {
        return;
    }
    s[++top] = _v;
    return;
}
int pop() {
    if (isEmpty()) {
        return -999;
    }
    return s[top--];
}

int main() {
    int temp;

    scanf_s("%d", &temp);
    while (temp != 0) {
        if (temp == -1) {
            pop();
        }
        else {
            push(temp);
            int i,j = 0;
            for (i = 0; i <= top; i++) {
                if ((i != top) && (s[i] == temp)) {
                    for (j = i + 1; j <= top; j++) {
                        s[j - 1] = s[j];
                    }
                    s[top] = 0;
                    top--;
                    break;
                }
            }
            
        }
        scanf_s("%d", &temp);
    }
    if (isEmpty()) {
        printf("0");
    }
    else {
        while (!isEmpty()) {
            printf("%d ", pop());
        }
    }
    return 0;
}