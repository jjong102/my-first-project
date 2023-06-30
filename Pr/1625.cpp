#include <stdio.h>

#define SSZ 20
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
    scanf("%d", &temp);
    while (temp != 0) {
        if (temp == -1) {
            pop();
        }
        else {
            push(temp);
        }
        scanf("%d", &temp);
    }
    if (isEmpty()) {
        printf("-999");
    }
    else {
        printf("%d", s[0] + s[top]);
    }
    return 0;
}