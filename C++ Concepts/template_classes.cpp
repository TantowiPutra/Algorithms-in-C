#include <iostream>
using namespace std;

template <typename T>
class Arithmetic {
    private:
        T a;
        T b;

    public:
        Arithmetic(T a, T b) : a(a), b(b) {}

        T add() {
            T c;
            c = a + b;
            return c;        
        }

        T sub() {
            return a - b;
        }
};

template <typename T>
class Shape {
    private:
        T a;
        T b;

    public:
        Shape(T a, T b) : a(a), b(b) {}

        T add();
        T sub();
};

template <typename T>
T Shape<T>::add() {
    return a + b;
}

template <typename T>
T Shape<T>::sub() {
    return a - b;
}

int main() {
    Arithmetic<int> ar(10, 5);

    cout << ar.add() << endl;
    cout << ar.sub() << endl;

    return 0;
}