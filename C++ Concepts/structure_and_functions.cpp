#include <iostream>
using namespace std;

struct Rectangle {
    int length, width;
};

void intitialize(Rectangle &r, int length, int width) {
    r.length = length;
    r.width = width;
}

int area(Rectangle &r) {
    return r.length * r.width;
}

int main() {
    Rectangle r;
    intitialize(r, 20, 10);

    cout << area(r) << endl;

    return 0;
}