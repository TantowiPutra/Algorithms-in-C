#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main() {
    // Creating object rectangle in the heap (part of memory used to dynamically allocate memory)
    Rectangle *r = new Rectangle({10, 20});
    
    cout << r->length << " " << r->breadth << endl;

    return 0;
}