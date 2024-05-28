#include <iostream>
using namespace std;

struct Grade {
    int grades[5];
};

// Example pass by pointer
void InsertValue(Grade *grade) {
    grade->grades[0] = 1;
    grade->grades[1] = 2;
    grade->grades[2] = 3;
    grade->grades[3] = 4;
    grade->grades[4] = 5;
}
 
int main() {
    Grade *grade = new Grade();
    InsertValue(grade);

    for(int i = 0; i < 5; i++) {
        cout << grade->grades[i] << " "; 
    }
}