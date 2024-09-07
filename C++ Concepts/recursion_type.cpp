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

int main() {
    tailRecursion(3);
    cout << "=============================" << endl;
    return 0;
}