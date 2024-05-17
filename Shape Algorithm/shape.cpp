#include <iostream>
using namespace std;

// Right half Pyramid
void PrintRightHalfPyramid(int &number) {
    for(int i = 0; i < number ; i++) {
        for(int j = 0; j < number ; j++) {
            if(j <= i) cout << "* ";
            else cout <<  " ";
        }

        cout << "\n";
    }
}

// Left half Pyramid
void PrintLeftHalfPyramid(int &number) {
    for(int i = 0; i < number ; i++) {
        for(int j = 0; j < 2 * (number - i) - 2 ; j++) {
            cout <<  " ";        
        }

        for(int k = 0; k <= i ; k++) {
            cout << "* ";   
        }

        cout << "\n";
    }
}

// PrintFullPyramid
void PrintFullPyramid(int &number) {  
    // first loop to print all rows 
    for (int i = 0; i < number; i++) { 
        // multiply it by 2, in case of the number of rows is odd
        for (int j = 0; j < 2 * (number - i) - 1; j++) { 
            cout << " ";
        } 

        for (int k = 0; k < 2 * i + 1; k++) { 
            cout <<  "* ";
        } 
        cout << "\n"; 
    } 
}

// Inverted Right Half Pyramid
void PrintInvertedRightHalfPyramid(int &number) {
    for(int i = 0; i < number; i++) { 
        for(int j = 0; j < number - i ; j++) {
            cout <<  "* ";
        }
        cout << "\n";
    }
}

// Inverted Left Half Pyramid
void PrintInvertedLeftHalfPyramid(int &number) {
    for(int i = 0; i < number; i++) {
        for(int j = 0; j < i * 2; j++) {
            cout <<  " ";
        }

        for(int k = number - i; k > 0; k--) {
            cout <<  "* ";
        }

        cout << "\n";
    }
}

// Inverted Full Pyramid
void PrintInvertedFullPyramid(int &number) {
    for(int i = 0; i < number; i++) {
        for(int j = 0; j < i; j++) {
            cout << " ";
        }

        for(int k = number - i; k > 0; k--) {
            cout << "* ";
        }

        cout << "\n";
    }
}

// Rhombus Pattern
void PrintRhombusPattern(int &number) {
    for(int i = 0; i < number; i++) {
        for(int j = 0; j < i; j++) {
            cout << " ";
        }

        for(int j = 0; j < number; j++) {
            cout << "* ";
        }

        cout << "\n";
    }
}

// Diamond Pattern 1
void PrintDiamondPattern1(int &number) {
    // Print First Half
    for(int i = 0; i < number; i++) {
        for(int j = 0; j < 2 * (number - i) - 1 ; j++) {
            cout <<  " ";
        }

        for(int k =0; k < i * 2 + 1; k++) {
            cout << "* ";
        }
        cout << "\n";
    }

    // Print Second Half
    for(int i = 0; i < number - 1; i++) {
        for(int j = 0; j <= (i + 1) * 2; j++) {
            cout << " ";
        }

        for(int k = 0; k < (number * 2 - 1) - (2 * (i + 1)); k++) {
            cout << "* ";
        }

        cout << "\n";
    }
}

void PrintDiamondPattern2(int &number) {
    // First Half
    /*
            *
           * *
          * * *
           * *
            *
    */

    for(int i = 0; i < number; i++) {
        for(int j = 0; j < number - i - 1; j++)  {
            cout << " ";
        }

        for(int k = 0; k <= i; k++) {
            cout << "* ";
        }

        cout << "\n";
    }

    // Second Half
    for(int i = 0; i < number - 1; i++) {
        for(int j = 0; j <= i; j++) {
            cout << " ";
        }

        for(int k = 0; k < number - i - 1; k++) {
            cout << "* ";
        }

        cout << "\n";
    }
}

int main() {
    int number = 5;

    PrintRightHalfPyramid(number);
    cout << "\n";
    PrintLeftHalfPyramid(number);
    cout << "\n";
    PrintFullPyramid(number);
    cout << "\n";
    PrintInvertedRightHalfPyramid(number);
    cout << "\n";
    PrintInvertedLeftHalfPyramid(number);
    cout << "\n";
    PrintInvertedFullPyramid(number);
    cout << "\n";
    PrintRhombusPattern(number);
    cout << "\n";
    PrintDiamondPattern1(number);
    cout << "\n";
    PrintDiamondPattern2(number);
    cout << "\n";
}