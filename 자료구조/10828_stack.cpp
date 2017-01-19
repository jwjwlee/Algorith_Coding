#include <iostream>
#include <string>
using namespace std;

int stack[10001];
int n = 0;
void push()
{
    int data;

    cin >> data;
    n++;
    stack[n] = data;
}

void pop()
{
    if (n == 0) cout << "-1" << endl;
    else {
        cout << stack[n] << endl;
        stack[n] = 0;
        n--;
    }
}

void size()
{
    cout << n << endl;
}

void empty()
{
    if (stack[1] == 0) cout << "1" << endl;
    else cout << "0" << endl;
}

void top(int n)
{
    if (n == 0) cout << "-1" << endl;
    else cout << stack[n] << endl;
}

int main()
{
    int case_num;
    string input;
    string order[5] = { "push", "pop", "size", "empty", "top" };

    cin >> case_num;
    for (int i = 0; i < case_num; i++) {
        cin >> input;
        if (input == order[0]) push();
        else if (input == order[1]) pop();
        else if (input == order[2]) size();
        else if (input == order[3]) empty();
        else if (input == order[4]) top(n);
        else
            cout << "input error" << endl;
    }
    return 0;
}

