#include <iostream>
using namespace std;

class Queue
{
private:
    int data;
    int front;
    int back;
public:
    void push();
    void pop();
    void size();
    void empty();
    void front_func();
    void back_func();
};

void Queue::push()
{




/*
int main()
{
    int i, case_num;
    char c[6];

    scanf("%d", &case_num);
    for (i = 0; i < case_num; i++) {
        scanf("%s", c);
        if (!strcmp(c, "push")) push();
        else if (!strcmp(c, "pop")) pop();
        else if (!strcmp(c, "size")) size();
        else if (!strcmp(c, "empty")) empty();
        else if (!strcmp(c, "front")) front();
        else if (!strcmp(c, "back")) back();
        else printf("input error\n");
    }
    return 0;
}

*/