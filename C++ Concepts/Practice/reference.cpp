#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int &r = a;

    /*
        variable that hold another variable's reference can't be reinitialized
        to hold another value's refernce. In this example r was declared and initialized to reference a. Changing r to hold c's reference will make r hold c's value instead of it's reference
    */
    int c = 20;
    r = c;
    c = 100;

    cout << r << endl;

    return 0;
}