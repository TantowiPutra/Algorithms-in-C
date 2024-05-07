#include <iostream>
using namespace std;

void PrintHourGlass(int rowCount)
{
    // Top-Half
    for (int i = 0; i < rowCount; i++)
    {
        for(int j = 0; j < i; j++) cout << " ";
        for(int j = i; j < rowCount; j++) cout << j << " ";
        cout << endl;
    }

    // Bottom-Half
    for (int i = rowCount - 2; i >= 0; i--) { 
        for(int j = 0; j < i; j++) cout << " ";
        for(int j = i; j < rowCount; j++) cout << j << " ";

        cout << endl;
    } 
}
int main() {
    int number = 4;
    PrintHourGlass(number);

    return 0;
}