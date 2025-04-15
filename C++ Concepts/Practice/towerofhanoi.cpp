#include <iostream>
using namespace std;

int cntMove = 0;
void TOH(char tA, char tB, char tC, int disks) {

    if(disks <= 0)
        return;

    TOH(tA, tC, tB, disks - 1);
    cntMove += 1;
    cout << "Move Disk From " << tA << " to " << tC << endl;
    TOH(tB, tC, tA, disks - 1);
}

int main() {
    char tA = 'A', tB = 'B', tC = 'C';
    int disks = 5;

    TOH(tA, tB, tC, disks);
    cout << cntMove << endl;

    return 0;
}