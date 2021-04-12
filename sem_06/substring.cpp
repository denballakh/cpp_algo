#include <iostream>

using namespace std;

#define __DEBUG__

int min(int a, int b) { return a < b ? a : b; }

struct String {
    char *str;
    size_t size;
    size_t capacity;

    String() {
        this->size = 0;
        this->capacity = 1;
        this->str = new char[this->capacity];
    }

    String(size_t cnt, char c): String() {
        for (int i = 0; i < cnt; i++)
            this->push_back(c);
    }

    String(const String& s): String() {
        for (int i = 0; i < this->capacity; i++)
            this->push_back(s.str[i]);
    }

    String(char c): String(1, c) {}  // Конструктор строки из одного символа

    String(const char* c_str): String() {
        // cout << __PRETTY_FUNCTION__ << endl;
        for (int i = 0; c_str[i] != '\0'; i++) {
            this->push_back(c_str[i]);
        }
    }

    ~String() { delete[] this->str; }

    void push_back(char c) {
        if (this->size == this->capacity)
            this->resize(this->capacity ? this->capacity * 2 : 1);

        this->str[this->size] = c;
        this->size++;
    }

    char pop() {
        if (this->size <= 0) throw;
        this->size--;
        return this->str[this->size];
    }

    String& operator =(const String& new_str) {
        this->clear();
        for (int i = 0; i < new_str.len(); i++)
            this->push_back(new_str[i]);
        return (*this);
    }

    bool operator ==(const String& other) const {
        if (this->size != other.size) return false;
        for (int i = 0; i < this->size; i++)
            if ((*this)[i] != other[i])
                return false;
        return true;
    }

    bool operator !=(const String& other) const { return !((*this) == other); }

    bool operator >(const String& other) const {
        int i = 0;
        while (i < min(this->len(), other.len())) {
            char c1 = (*this)[i];
            char c2 = other[i];
            if (c1 < c2) return false;
            if (c1 > c2) return true;
            i++;
        }
        return this->len() > other.len();
    }

    bool operator <(const String& other) const { return !((*this) > other); }

    String& operator +=(const String& other) {
        for (int i = 0; i < other.len(); i++)
            this->push_back(other[i]);
        return (*this);
    }

    char& operator [](int pos) const { 
        if (pos >= 0) return this->str[pos];
        else return this->str[this->size + pos];
    }

    void append(const String& other) {
        for (int i = 0; i < other.len(); i++)
            this->push_back(other[i]);
    }

    void resize(unsigned int new_capacity) {
        // cout << __PRETTY_FUNCTION__ << endl;
        // cout << "resizing " << this->capacity << " to " << new_capacity << "!\n";
        if (new_capacity == 0) {
            new_capacity = 1;
            this->size = 0;
        }
        char* new_str = new char[new_capacity];
        for (int i = 0; i < min(this->capacity, new_capacity); i++)
            new_str[i] = this->str[i];
        delete[] this->str;
        this->str = new_str;
        this->capacity = new_capacity;
        this->size = min(this->size, this->capacity);
    }

    void reserve(unsigned int new_capacity) { this->resize(new_capacity); }

    void insert(unsigned int pos, String& other) {
        String temp;
        while (this->len() > pos)
            temp.push_back(this->pop());
        for (int i = 0; i < other.len(); i++)
            this->push_back(other[i]);
        while (temp.len())
            this->push_back(temp.pop());
    }

    void shrink_to_fit() { this->resize(this->size); }

    void clear() { this->size = 0; }

    int len() const { return this->size; }

    String slice(int begin, int end) const {
        String result;
        for (int i = begin; i <= end; i++)
            result.push_back((*this)[i]);
        return result;
    }

    String reverse() const {
        String result;
        for (int i = this->len() - 1; i >= 0; i--)
            result.push_back((*this)[i]);
        return result;
    }

    friend ostream& operator <<(ostream& ostr, const String& str) {
        #ifdef __DEBUG__
            ostr << "[" << str.size << "/" << str.capacity << "]\t";
        #endif
        for (int i = 0; i < str.len(); i++)
            ostr << str[i];
        #ifdef __DEBUG__
            for (int i = str.len(); i < str.capacity; i++)
                ostr << '.';
        #endif
        return ostr;
    }

    friend istream& operator >>(istream& istr, String& str) {
        while (1) {
            char x;
            istr >> x;
            if (x == '\0' || x == '\n') break;
            str.push_back(x);
        }
        return istr;
    }



};


String operator +(const String& str1, const String& str2) {
    String result;
    for (int i = 0; i < str1.len(); i++)
        result.push_back(str1[i]);
    for (int i = 0; i < str2.len(); i++)
        result.push_back(str2[i]);
    return result;
}

bool isalpha(char c) {
    return 
    c == '-' || c == '+' ||
    (c >= '0' && c <= '9') ||
    (c >= 'a' && c <= 'z') ||
    (c >= 'A' && c <= 'Z');
}

int stoi(const String& str, size_t pos = 0, int base = 10) {
    String s;
    int i = pos;
    while (isalpha(str[i])) {
        s.push_back(str[i]);
        i++;
    }
    s = s.reverse();
    int result = 0;
    int sign;
    switch (s[-1]) {
        case '-':
            sign = -1;
            s.pop();
            break;
        case '+':
            sign = +1;
            s.pop();
            break;
        default:
            sign = +1;
    }

    while (s.len()) {
        int digit;
        char c = s.pop();
        if (c >= '0' && c <= '9') digit = c - '0';
        if (c >= 'a' && c <= 'z') digit = c - 'a' + 10;
        if (c >= 'A' && c <= 'Z') digit = c - 'A' + 10;
        result = result * base + digit;
    }
    return result * sign;
}

#define PRINT(expr) cout << #expr << " = " << (expr) << endl;

int main() {
    {
        cout << "Default constructor:" << endl;
        String s;
        PRINT(s);
        cout << endl;
    }
    {
        cout << "Filling constructor (10 * 'x'):" << endl;
        String s(10, 'x');
        PRINT(s);
        cout << endl;
    }
    {
        cout << "Filling constructor (0 * 'y'):" << endl;
        String s(0, 'y');
        PRINT(s);
        cout << "Push 't':" << endl;
        s.push_back('t');
        PRINT(s);
        cout << endl;
    }
    {
        cout << "Constructor from char 'z':" << endl;
        String s('z');
        PRINT(s);
        cout << endl;
    }
    {
        cout << "Constructor from other String: (10 * 'x')" << endl;
        String s1(10, 'x');
        String s(s1);
        PRINT(s);
        cout << endl;
    }
    {
        cout << "Constructor from C-style string:" << endl;
        String s("c-style string");
        PRINT(s);
        cout << endl;
    }
    {
        cout << "push_back:" << endl;
        String s("-string-");
        PRINT(s);
        s.push_back('!');
        PRINT(s);
        cout << endl;
    }
    {
        cout << "push_back:" << endl;
        String s("1234567");
        PRINT(s);
        s.push_back('8');
        PRINT(s);
        cout << endl;
    }
    {
        cout << "pop:" << endl;
        String s("string");
        PRINT(s);
        cout << s.pop() << endl;
        PRINT(s);
        cout << endl;
    }
    {
        cout << "operator= :" << endl;
        String s1("first string");
        String s2("second string");
        PRINT(s1);
        PRINT(s2);
        PRINT(s1 = s2);
        PRINT(s1);
        PRINT(s2);
        cout << endl;
    }
    {
        cout << "operator > < != ==" << endl;
        String s1 = "1";
        String s2 = "2";
        String s3 = "3";
        String s4 = "11";
        PRINT(s1 < s2);
        PRINT(s3 < s2);
        PRINT(s4 < s1);
        PRINT(s2 == s3);
        cout << endl;
    }
    {
        cout << "operator +=" << endl;
        String s1("first string");
        String s2("second string");
        PRINT(s1);
        PRINT(s2);
        PRINT(s1 += s2);
        PRINT(s1);
        PRINT(s2);
        cout << endl;
    }
    {
        cout << "operator []" << endl;
        String s("abcdef");
        PRINT(s);
        PRINT(s[0]);
        PRINT(s[1]);
        PRINT(s[2]);
        PRINT(s[3]);
        PRINT(s[4]);
        PRINT(s[5]);
        PRINT(s[-1]);
        PRINT(s[-2]);
        PRINT(s[-3]);
        PRINT(s[-4]);
        PRINT(s[-5]);
        PRINT(s[-6]);
        cout << endl;
    }
    {
        cout << "append:" << endl;
        String s1("first string");
        String s2("second string");
        PRINT(s1);
        PRINT(s2);
        s1.append(s2);
        PRINT(s1);
        PRINT(s2);
        cout << endl;
    }
    {
        cout << "resize:" << endl;
        String s("string");
        PRINT(s);
        s.resize(20);
        PRINT(s);
        s.resize(5);
        PRINT(s);
        s.resize(10);
        PRINT(s);
        s.resize(0);
        PRINT(s);
        cout << endl;
    }
    {
        cout << "insert:" << endl;
        String s1("STRINGSTRING");
        String s2("str");
        PRINT(s1);
        PRINT(s2);
        s1.insert(3, s2);
        PRINT(s1);
        PRINT(s2);
        cout << endl;
    }
    {
        cout << "shrink_to_fit:" << endl;
        String s("long long string ---");
        PRINT(s);
        s.resize(10);
        PRINT(s);
        s.resize(30);
        PRINT(s);
        s.shrink_to_fit();
        PRINT(s);
        cout << endl;
    }
    {
        cout << "clear:" << endl;
        String s("string");
        PRINT(s);
        s.clear();
        PRINT(s);
        cout << endl;
    }
    {
        cout << "len:" << endl;
        String s("string with len = 20");
        PRINT(s);
        PRINT(s.len());
        cout << endl;
    }
    {
        cout << "slice:" << endl;
        String s("abcdef");
        PRINT(s);
        PRINT(s.slice(0,4));
        PRINT(s.slice(2,5));

    }
    {
        cout << "reverse:" << endl;
        String s("12345");
        PRINT(s);
        PRINT(s.reverse());
        cout << endl;
    }
    // {
    //     cout << "Enter the string:" << endl;
    //     String s;
    //     cin >> s;
    //     PRINT(s);
    //     cout << endl;
    // }
    {
        cout << "s1 + s2" << endl;
        String s1("s1");
        String s2("s2");
        PRINT(s1);
        PRINT(s2);
        PRINT(s1 + s2);
        cout << endl;
    }
    {
        cout << "stoi:" << endl;
        PRINT(stoi(String("+123"), 0, 10));
        PRINT(stoi(String("-123"), 0, 10));
        PRINT(stoi(String("===+123==="), 3, 10));
        PRINT(stoi(String("FfFf"), 0, 16));
        cout << endl;
    }
}