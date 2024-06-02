#include <iostream>
using namespace std;

class Rectangle {
    private:
        int length;
        int breadth;

    public:
        Rectangle(int l, int b) :  length(l), breadth(b){}

        int area() {
            return length * breadth;            
        }

        int perimeter() {
            return 2 * (length + breadth);
        }
};

int main() {
    Rectangle r = {1, 3};

    cout << r.area() << " " << r.perimeter() << endl;

    return 0;
}