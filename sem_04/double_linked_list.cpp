#include<iostream>

using std::cin, std::cout, std::endl;

#define T int

struct Node {
    T value;
    struct Node* next;

    Node(T value=0, Node* next=nullptr): next(next), value(value) {}
};



Node* last_node(Node* head) {
    Node* p = head;
    if (p == nullptr) return nullptr;
    while (p->next != nullptr) {
        p = p->next;
    }
    return p;
}

int length(Node* head) {
    Node* p = head;
    if (p == nullptr) return 0;
    int l = 0;
    while (p->next != nullptr) {
        p = p->next;
        l++;
    }
    return l;
}

void insert_after(Node** head, T value) {
    Node* node = new Node(value);
    if (*head == nullptr) {
        *head = node;
    } else {
        node->next = (*head)->next;
        (*head)->next = node;
    }
}

void insert_in_sorted(Node** head, T value) {
    Node* node = new Node(value);
    if (*head == nullptr) {
        *head = node;
    } else {
        Node* prev = nullptr;
        Node* p = *head;
        while (p != nullptr && p->value < value) {
            prev = p;
            p = p->next;
        }
        node->next = p;
        if (prev == nullptr) {
            *head = node;
        } else {
            prev->next = node;
        }
    }
}

void push_left(Node** head, T value) {
    Node* node = new Node(value, *head);
    *head = node;
}

void push_right(Node** head, T value) {
    Node* node = new Node(value);

    if (*head == nullptr) {
        *head = node;
    } else {
        Node* last = last_node(*head);
        last->next = node;
    }
}

void push_index(Node** head, T value, int index) {
    Node* node = new Node(value);

    int i = 0;
    Node* prev = nullptr;
    Node* p = *head;
    while (i < index) {
        i++;
        prev = p;
        p = p-> next;
    }
    if (prev == nullptr) {
        node->next = *head;
        *head = node;
    } else {
        prev->next = node;
        node->next = p;
    }
}

void clear_list(Node** head) { // пока не делает ничего, только присваивает nullptr сложным способом
    // while ((*head) != nullptr) {
    //     delete head; // почему-то не работает
    //     *head = (*head)->next;
    // }
    *head = nullptr;
}

T pop(Node** head, int index) {
    if(*head == nullptr) return 0;
    int i = 0;
    Node* prev = nullptr;
    Node* p = *head;
    while (i < index && p != nullptr && p->next != nullptr) {
        i++;
        prev = p;
        p = p-> next;
    }
    if (prev == nullptr) {
        *head = p->next;
    } else {
        prev->next = p->next;
    }
    T result = p->value;
    delete p;
    return result;
}

T pop_left(Node** head, int index) { return pop(head, 0); }
T pop_right(Node** head, int index) { return pop(head, length(*head)); } //переделать


void remove(Node** head, T value) {
    Node* prev = nullptr;
    Node* p = *head;
    while (p != nullptr) {
        if (p->value == value) {
            if (prev != nullptr) {
                prev->next = p->next;
            } else {
                *head = p->next;
            }
            delete p;
            return;
        }
        prev = p;
        p = p-> next;
    }
}

void remove_all(Node** head, T value) {
    Node* prev = nullptr;
    Node* p = *head;
    while (p != nullptr) {
        if (p->value == value) {
            if (prev != nullptr) {
                prev->next = p->next;
            } else {
                *head = p->next;
            }
            delete p;
            // return;
        }
        prev = p;
        p = p-> next;
    }
}

void replace_all(Node* head, T old_value, T new_value) {
    Node* prev = nullptr;
    Node* p = head;
    while (p != nullptr) {
        if (p->value == old_value) {
            p->value = new_value;
        }
        prev = p;
        p = p-> next;
    }
}

// 7. Определение, сколько различных значений содержится в списке.
int unique(Node* head) {
    return 0;
}

void reverse(Node** head) {
    Node* prev = nullptr;
    Node* p = *head;
    Node* truenext;
    while (p != nullptr) {
        truenext = p->next;
        p->next = prev;
        prev = p;
        p = truenext;
    }
    *head = prev;
}

// 9*. Сортировка элементов списка двумя способами (изменение указателей, изменение значений элементов).
void sort_1(Node** head) {
    Node* sorted = nullptr;
    Node* top = *head;
    while (top != nullptr) {
        insert_in_sorted(&sorted, top->value);
        top = top->next;
    }
    clear_list(head);
    *head = sorted;
}
void sort_2() {

}

void print(Node* head) {
    while (true) {
        if (head == nullptr) {
            cout << "nullptr\n";
            break;
        } else {
            cout << head->value << "\t-> ";
            head = head->next;
        }
    }
}

int main() {
    Node* a = nullptr;

    push_left(&a, 0);
    push_left(&a, 1);
    push_left(&a, 2);
    push_left(&a, 3);
    push_left(&a, 4);
    push_left(&a, 5);
    push_left(&a, 6);
    push_left(&a, 7);
    push_left(&a, 8);
    push_left(&a, 9);


    print(a);
    sort_1(&a);
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
