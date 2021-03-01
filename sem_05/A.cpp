#include<iostream>

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

T abs(T val) {
    return val >= 0 ? val : -val;
}

// Дана последовательность чисел, оканчивающаяся нулём. Последовательность обрабатывается по следующим правилам: если число положительное оно добавляется в стек, если отрицательное и по модулю меньше значения на вершине стека — прибавляется к числу на вершине, если больше или равно — убирает его с вершины стека (в случае когда стек пустой, отрицательное число просто игнорируется). Необходимо определить какая будет глубина стека и какое значение окажется на его вершине.

// Формат входных данных
// Последовательность чисел, оканчивающаяся нулём.

// Формат выходных данных
// Два числа, разделённых пробелом: глубина стека и число на вершине (-1 если стек пустой)

int main() {
    Stack* stack = newStack();
    while (true) {
        T x;
        cin >> x;
        if (x == 0) break;
        if (x > 0) push(stack, x);
        if (x < 0) {
            T top = pop(stack); // тут нет проверки, что плохо, но заданную задачу это решает :-)
            if (abs(x) < top) {
                push(stack, top + x);
            }
        }
    }
    int len = stack->ptr;
    T top = len == 0 ? -1 : getTop(stack);
    cout << len << ' ' << top << endl;
    return 0;
}
