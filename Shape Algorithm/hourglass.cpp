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

/* Second Approach */
void SecondPrintHourGlass(int rowCount)
{
    for(int i = 0; i < rowCount * 2; i++)
    {
        if(i < (rowCount * 2) / 2) {
            for(int j = 0; j < rowCount; j++) {
                if(j < i) cout << " ";
                else cout << "* ";
            }
        } else {
            for(int j = 0 ; j < rowCount; j++) {
                int tempDiff = ((rowCount - 1) - (i - rowCount));

                if(j < tempDiff) cout << " ";
                else cout << "* ";
            }
        }

        cout << endl;
    }

}

int main() {
    int number = 4;
    PrintHourGlass(number);
    cout << "\n" << endl;
    SecondPrintHourGlass(number);

    return 0;
}