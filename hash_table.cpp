#include<iostream>

using namespace std;

#define BIG_PRIME 2147482223
#define DEFAULT_SIZE 100

#define log(expr) cout << (#expr) << " = " << (expr) << endl;

struct Node {
    int value;
    int key;
    Node* next;

    Node(int key, int value, Node* next): value(value), key(key), next(next) {}
    Node(int key, int value): Node(key, value, nullptr) {}
    Node(const Node& node): value(node.value), key(node.key), next(node.next) {}
};

template<typename KEY_TYPE, typename VALUE_TYPE>
class HashTable {
/*

dict[key] = value
dict[key]
del dict[key]

dict.in(key)

dict.resize()
dict.get_pairs()

for k, v in dict
*/
// int -> int
// data = [*Node]
// Node = (key, value)

 private:
    unsigned int size;
    const unsigned int seed;
    Node** data;
    const unsigned int* h(KEY_TYPE);

 public:
    HashTable(unsigned int size, unsigned int seed): size(size), seed(seed) {
        this->data = new Node*[size];
        for (int i = 0; i < size; i++)
            this->data[i] = nullptr;
    }
    HashTable(unsigned int size): HashTable(size, BIG_PRIME) {}
    HashTable(): HashTable(DEFAULT_SIZE) {}

    unsigned int hash(KEY_TYPE key) const {
        return (key * this->seed) % this->size;
    }

    bool in(KEY_TYPE key) {
        unsigned int index = hash(key);
        Node* ptr = this->data[index];
        while (ptr != nullptr) {
            if (ptr->key == key) return true;
            ptr = ptr->next;
        }
        return false;
    }

    Node* last_node(KEY_TYPE key) {
        unsigned int index = hash(key);
        Node* ptr = this->data[index];
        if (ptr == nullptr) return nullptr;
        while (ptr->next != nullptr)
            ptr = ptr->next;
        return ptr;
    }

    // возвращает пару по ключу или nullptr, если такого ключа нет
    Node* get_node(KEY_TYPE key) {
        unsigned int index = hash(key);
        if (this->data[index] == nullptr) return nullptr;
        Node* ptr = this->data[index];
        while (ptr != nullptr) {
            if (ptr->key == key) return ptr;
            ptr = ptr->next;
        }
        return nullptr;
    }

    Node* create_node(KEY_TYPE key, VALUE_TYPE value) {
        unsigned int index = hash(key);
        if (this->data[index] == nullptr) {
            Node* node = new Node(key, value);
            this->data[index] = node;
            return node;
        } else {
            Node* ptr = this->data[index];
            while (ptr->next != nullptr) {
                if (ptr->key == key) return ptr;
                ptr = ptr->next;
            }
            if (ptr->key == key) return ptr;
            Node* node = new Node(key, value);
            ptr->next = node;
            return node;
        }
    }

    void set(KEY_TYPE key, VALUE_TYPE value) {
        if (this->in(key)) {

        } else {
            Node* node = new Node(key, value);
            unsigned int index = hash(key);
            Node* ptr = this->data[index];
            if (ptr == nullptr)
                this->data[index] = node;
            else {
                while (ptr->next != nullptr)
                    ptr = ptr->next;
                ptr->next = node;
            }
        }
    }

    VALUE_TYPE get(KEY_TYPE key, VALUE_TYPE def = INT_MAX) {
        unsigned int index = hash(key);
        if (!this->in(key)) return def;
        Node* node = this->data[index];
        while (node != nullptr) {
            if (node->key == key)
                return node->value;
            node = node->next;
        }
    }

    void del(KEY_TYPE key) {

    }

    VALUE_TYPE& operator[](KEY_TYPE key) {
        // оператор получения ссылки на поле value
        // если соответствующей пары нет, то она будет создана
        if (this->in(key)) {

        } else {
            Node* node = new Node(key, INT_MAX);
            Node* last = this->last_node(key);
            if (last == nullptr) {
                this->data[hash(key)] = node;
            } else {
                last->next = node;
            }
            return node->value;
        }
    }
};



template<class K, class V>
void print(const HashTable<K, V>& h) {
    // printf("size: %d\n", h.size);
    // printf("seed: %d\n", h.seed);
    // for (int i = 0; i < h.size; i++) {
    //     Node* ptr = h.data[i];
    //     printf("%2d: ", i);
    //     while (ptr != nullptr) {
    //         printf("(%d: %d)\t", ptr->key, ptr->value);
    //         ptr = ptr->next;
    //     }
    //     printf("\n");
    // }
    // printf("------------------------------------------------------------\n");
}

int main() {
    HashTable<int, int> h(17);
    // print(h);
    // h.set(1, 2); print(h);
    // h.set(5, 3); print(h);
    // h.set(10, 4); print(h);
    // h.set(100, 6); print(h);
    // h.set(1000, 7); print(h);
    // h.set(10000, 8); print(h);
    // printf("\n");
    // cout << h.get(1) << endl;
    // cout << h.get(2) << endl;
    // cout << h.get(5) << endl;
    // cout << h.get(10) << endl;
    // cout << h.get(100) << endl;
    // cout << h.get(1000) << endl;
    // cout << h.get(10000) << endl;
    h[1] = 2;
    h[2] = 3;
    h[3] = 4;
    h[4] = 5;
    h[5] = 6;
    print(h);

    getchar();
}
