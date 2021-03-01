#include<iostream>

using namespace std;

#define T int

struct Node {
    T value;
    struct Node* next;
};



bool is_empty_(Node* head) {
    return head == NULL;
}

bool is_node(Node* node) {
    return node != NULL;
}

bool is_end(Node* node) {
    return node == NULL || node->next == NULL;
}

void step(Node** node) {
    (*node) = (*node)->next;
}

Node* last_node(Node* head) {
    Node* p = head;
    if (is_empty_(p)) return NULL;
    while (!is_end(p)) {
        step(&p);
    }
    return p;
}

int length(Node* head) {
    Node* p = head;
    if (is_empty_(p)) return 0;
    int l = 0;
    while (!is_end(p)) {
        step(&p);
        l++;
    }
    return l;
}

void clear_list(Node** head) {
    while (is_node(*head)) {
        delete *head;
        step(head);
    }
}

void push_left(Node** head, T value) {
    Node* node = new Node;
    node->value = value;
    node->next = *head;

    *head = node;
}

void push_right(Node** head, T value) {
    Node* node = new Node;
    node->value = value;
    node->next = NULL;

    if (is_empty_(*head)) {
        *head = node;
    } else {
        Node* last = last_node(*head);
        last->next = node;
    }
}

void push_index(Node** head, T value, int index) {
    Node* node = new Node;
    node->value = value;
    node->next = NULL;

    int i = 0;
    Node* prev = NULL;
    Node* p = *head;
    while (i < index) {
        i++;
        prev = p;
        step(&p);
    }
    if (prev == NULL) {
        node->next = *head;
        *head = node;
    } else {
        prev->next = node;
        node->next = p;
    }
}

T pop(Node** head, int index) {
    if(is_empty_(*head)) return 0;
    int i = 0;
    Node* prev = NULL;
    Node* p = *head;
    while (i < index && is_node(p)) {
        i++;
        prev = p;
        step(&p);
    }
    if (prev == NULL) {
        *head = p->next;
    } else {
        prev->next = p->next;
    }
    T result = p->value;
    delete p;
    return result;
}

T pop_left(Node** head) { return pop(head, 0); }
T pop_right(Node** head) { return pop(head, length(*head)); } // тут дважды происходит проход по массиву, это плохо

void print(Node* head) {
    while(1) {
        if (head == NULL) {
            cout << "null\n";
            return;
        } else {
            cout << head->value << "\t-> ";
            head = head->next;
        }
    }
}

/*
Гоблины Мглистых гор очень любят ходить к своим шаманам. Так как гоблинов много, к шаманам часто образуются очень длинные очереди. А поскольку много гоблинов в одном месте быстро образуют шумную толку, которая мешает шаманам проводить сложные медицинские манипуляции, последние решили установить некоторые правила касательно порядка в очереди.

Обычные гоблины при посещении шаманов должны вставать в конец очереди. Привилегированные же гоблины, знающие особый пароль, встают ровно в ее середину, причем при нечетной длине очереди они встают сразу за центром.

Так как гоблины также широко известны своим непочтительным отношением ко всяческим правилам и законам, шаманы попросили вас написать программу, которая бы отслеживала порядок гоблинов в очереди.

Формат входных данных
В первой строке входных данный записано число N (1≤N≤10^3) - количество запросов к программе. Следующие N строк содержат описание запросов в формате:

"+ i" - гоблин с номером i (1≤i≤N) встает в конец очереди.
"* i" - привилегированный гоблин с номером i встает в середину очереди.
"-" - первый гоблин из очереди уходит к шаманам. Гарантируется, что на момент такого запроса очередь не пуста.
Формат выходных данных
Для каждого запроса типа "-" программа должна вывести номер гоблина, который должен зайти к шаманам.
*/

int main() {
    Node* list = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        int x;
        cin >> c;
        if (c != '-') cin >> x;

        if (c == '+') {
            push_left(&list, x);
        }
        if (c == '*') {
            push_index(&list, x, (length(list) + 1) / 2);   
        }
        if (c == '-') {
            cout << pop_right(&list) << endl;
        }
    }
    clear_list(&list);
    return 0;
}
