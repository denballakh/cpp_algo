#include<iostream>

using std::cin, std::cout, std::endl;

#define T int

struct Node {
    T value;
    struct Node* next;
};



bool is_empty(Node* head) {
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
    if (is_empty(p)) return NULL;
    while (!is_end(p)) {
        step(&p);
    }
    return p;
}

int length(Node* head) {
    Node* p = head;
    if (is_empty(p)) return 0;
    int l = 0;
    while (!is_end(p)) {
        step(&p);
        l++;
    }
    return l;
}

// 1. Добавление элемента в начало списка
// Реализуйте функцию, добавляющую элемент в начало списка. Поскольку указатель на первый элемент будет изменён, функция должна принимать указатель на указатель.
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

    if (is_empty(*head)) {
        *head = node;
    } else {
        Node* last = last_node(*head);
        last->next = node;
    }
}


// 2. Удаление всех элементов списка
// Реализуйте функцию очистки списка. С освобождением памяти и записью NULL в указатель на первый элемент:
void clear_list(Node** head) {
    while (is_node(*head)) {
        delete *head;
        step(head);
    }
}

// 3. Удаление элемента по заданному индексу с возвратом его значения:
T pop(Node** head, int index) {
    if(is_empty(*head)) return 0;
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

// 4. Удаление первого элемента списка с данным значением:
void remove(Node** head, T value) {
    Node* prev = NULL;
    Node* p = *head;
    while (is_node(p)) {
        if (p->value == value) {
            if (prev != NULL) {
                prev->next = p->next;
            } else {
                *head = p->next;
            }
            delete p;
            return;
        }
        prev = p;
        step(&p);
    }
}

// 5. Удаление всех элементов списка с данным значением:
void remove_all(Node** head, T value) {
    Node* prev = NULL;
    Node* p = *head;
    while (is_node(p)) {
        if (p->value == value) {
            if (prev != NULL) {
                prev->next = p->next;
            } else {
                *head = p->next;
            }
            delete p;
            // return;
        }
        prev = p;
        step(&p);
    }
}

// 6. Изменение всех элементов списка с данным значением на новое.
void replace_all(Node* head, T old_value, T new_value) {
    Node* prev = NULL;
    Node* p = head;
    while (is_node(p)) {
        if (p->value == old_value) {
            p->value = new_value;
        }
        prev = p;
        step(&p);
    }
}

// 7. Определение, сколько различных значений содержится в списке.
int unique(Node* head) {

}

// 8. Изменение порядка элементов на обратный.
void reverse(Node** head) {
    Node* prev = NULL;
    Node* p = *head;
    Node* truenext;
    while (is_node(p)) {
        truenext = p->next;
        p->next = prev;
        prev = p;
        p = truenext;
    }
    *head = prev;
}

// 9*. Сортировка элементов списка двумя способами (изменение указателей, изменение значений элементов).
void sort_1() {

}
void sort_2() {

}

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

int main(){
    Node* a = new Node;
    Node* b = new Node;
    Node* c = new Node;
    Node* d = new Node;
    Node* e = new Node;

    a->value = 0; a->next = b;
    b->value = 1; b->next = c;
    c->value = 2; c->next = d;
    d->value = 3; d->next = e;
    e->value = 4; e->next = NULL;

    print(a);
    push_left(&a, 7);
    print(a);
    push_right(&a, 9);
    print(a);
    pop(&a, 3);
    print(a);
    remove(&a, 4);
    print(a);
    reverse(&a);
    print(a);
    clear_list(&a);
    print(a);

}