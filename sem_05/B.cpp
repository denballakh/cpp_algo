#include<iostream>
#include<string>

using namespace std;

#define T int

struct Stack {
    int size; // выделенный размер массива
    int ptr; // указатель на первый незаполненный элемент
    T* data; // массив элементов (кому я вообще пишу комментарии?)
};

Stack* newStack(int size=256) {
    Stack* stack = new Stack;
    stack->size = size;
    stack->ptr = 0;
    stack->data = new T[size];
    return stack;
}

void push(Stack* stack, T val) {
    if (stack->ptr >= stack->size) { return; /*stack overflow*/ }
    stack->data[stack->ptr] = val;
    stack->ptr++;
}

T pop(Stack* stack) {
    if (stack->ptr <= 0) { return 0; /*stack underflow*/ }
    stack->ptr--;
    T result = stack->data[stack->ptr];
    return result;
}

T getTop(Stack* stack) {
    if (stack->ptr <= 0 || stack->ptr > stack->size) { return 0; /*что происходит?*/ }
    return stack->data[stack->ptr - 1];
}



T op(T v1, T v2, string cmd) {
    if (cmd == "+") return v1 + v2;
    if (cmd == "-") return v1 - v2;
    if (cmd == "*") return v1 * v2;
    if (cmd == "/") return v1 / v2;
    return 0;
} 

// 10 6 9 3 + -11 * / * 17 + 5 +

int main() {
    Stack* stack = newStack();
    string s;
    while (cin >> s) {
        if (s == "+" || s == "-" || s == "*" || s == "/") {
            T v2 = pop(stack);
            T v1 = pop(stack);
            T result = op(v1, v2, s);
            push(stack, result);
        } else {
            T x = stoi(s);
            push(stack, x);
        }
    }
    T result = pop(stack);
    cout << result << endl;
    return 0;
}
