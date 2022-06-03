#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <queue>

using namespace std;

void usingVector();
void usingSet();
void usingMap();

void f1();
void f2();
void f3(int n, void(*f1)(), void(*f2)());

int compare(const void* left, const void* right);

struct absValue {
    float operator()(float f) {
        return (f > 0) ? f : -f;
    }
};

int main()
{
    cout << "--- vector ---" << endl;
    usingVector();

    cout << "\n--- set ---" << endl;
    usingSet();

    cout << "\n--- map ---" << endl;
    usingMap();

    cout << "\n--- function pointer ---" << endl;
    f3(0, f1, f2);
    f3(5, f1, f2);
    void (*tf)();
    tf = f1;
    tf();

    cout << "\n--- using qsort ---" << endl;
    int i;
    int arr[10];
    for (i = 0; i < 10; i++) // arr init
        arr[i] = 10 - i;
    for (i = 0; i < 10; i++) // arr print
        cout << arr[i] << " ";
    cout << endl;
    // void qsort(void* base, size_t numOfElem, size_t sizeOfElem, int (*compare) (const void*, const void*))
    qsort(arr, sizeof(arr)/sizeof(arr[0]), sizeof(int), compare); // arr sort
    for (i = 0; i < 10; i++) // sorted arr print
        cout << arr[i] << " ";
    cout << endl;

    cout << "\n--- using functor ---" << endl;
    float f = -123.456;
    absValue aObj; // functor
    float abs_f = aObj(f); // aObj.operator()(f)
    cout << "f: " << f << ", abs_f: " << abs_f << endl;

    return 0;
}

void usingVector() {
    vector<int> v1;

    cout << "v1.size() = " << v1.size() << endl;
    cout << "v1.max_size() = " << v1.max_size() << endl;
    cout << "v1.empty() = " << v1.empty() << endl;
    //cout << "v1[0] = " << v1[0] << endl;
}

void usingSet() {
    set<int> s1;
    set<int>::iterator it;

    for (int i = 1; i <= 5; i++)
        s1.insert(i * 10);

    it = s1.find(20);
    s1.erase(it);
    s1.erase(s1.find(40));

    cout << "set containers" << endl;
    it = s1.find(1);
    cout << "s1.find(1): " << &it << endl;
    //s1.erase(s1.find(5));
}

void usingMap() {
    map<char, string> m1;

    m1['a'] = "apple";
    m1['b'] = "banana";
    m1['c'] = m1['b'];

    cout << "m1['a']: " << m1['a'] << endl;
    cout << "m1['b']: " << m1['b'] << endl;
    cout << "m1['c']: " << m1['c'] << endl;
    cout << "m1['d']: " << m1['d'] << endl; // m1['d'] is created with empty value

    for (map<char, string>::iterator it = m1.begin(); it != m1.end(); it++)
        cout << it->first << " -> " << it->second << endl; // first = key, second = value

    cout << "m1 size: " << m1.size() << endl;
}

void f1() {
    cout << "f1" << endl;
}

void f2() {
    cout << "f2" << endl;
}

void f3(int n, void(*f1)(), void(*f2)()) {
    if (n > 0) f1();
    else f2();
}

int compare(const void* left, const void* right) {
    return *(int*)left - *(int*)right;
}