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

void treeRecursion(int n)
{
    if(n > 0)
    {
        cout << n << endl;
        treeRecursion(n - 1);
        treeRecursion(n - 1);
    }
}

// INDIRECT RECURSIOIN
void funcB(int n);

void funcA(int n)
{
    if(n > 0)
    {
        cout << n << endl;
        funcB(n - 1);
    }
}

void funcB(int n)
{
    if(n > 1)
    {
        cout << n << endl;
        funcA(n / 2);
    }
}

void funcHalf(int n)
{
    if(n > 0)
    {
        cout << n << endl;
        funcHalf(n / 2);
    }
}

int funcNested(int n)
{
    if(n > 100)
        return n -10;
    else 
        return funcNested(funcNested(n + 11));
}

int main() {
    cout << "Tail Recursion: " << endl;
    tailRecursion(3);
    cout << "=============================" << endl;
    cout << "Head Recursion: " << endl;
    headRecursion(3);
    cout << "Tree Recursion: " << endl;
    treeRecursion(3);
    cout << "Indirect Recursion: " << endl;
    funcA(20);
    cout << "Nested Function: " << endl;
    funcNested(95);
    return 0;
}