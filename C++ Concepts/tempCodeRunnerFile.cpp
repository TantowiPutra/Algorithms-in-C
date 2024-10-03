#include <iostream>
using namespace std;

void tailRecursion(int n) 
{
    // TAIL RECURSION IS A TYPE OF RECURSION WHERE THE FUNCTION CALL IS LOCATED AT THE LAST
    if(n > 0)
    {
        cout << n << endl;
        tailRecursion(n - 1);
    }
}

void headRecursion(int n)
{
    if(n > 0)
    {
        headRecursion(n - 1);
        cout << n << endl;
    }
}

int main() {
    cout << "Tail Recursion: " << endl;
    tailRecursion(3);
    cout << "=============================" << endl;
    cout << "Head Recursion: " << endl;
    headRecursion(3);
    return 0;
}