#include <bits/stdc++.h>

class Diagonal {
    private:
        int n;
        int *A;
    
    public:
        static void WhoAmI() {
            std::cout << "Hi I'm a Diagonal Matrix Class!" << std::endl;
        }

        Diagonal(int n) {
            this->n = n;
            this->A = new int[n] {0, 0, 0, 0, 0};
        }

        void Display() {
            for(int i = 0; i < this->n; i++) {
                for(int j = 0; j < this->n; j++) {
                    if(i == j)
                        std::cout << this->A[i] << " ";
                    else 
                        std::cout << '0' << " ";
                }

                std::cout << std::endl;
            }
        }

        void Set(int val, int i, int j) {
            if(i == j) {
                A[i] = val;
            }
        }

        int Get(int i, int j) {
            if(i == j) {
                return A[i];
            }
        }
};

int main() {
    Diagonal *d = new Diagonal(5);
    d->Set(10, 0, 0);
    std::cout << d->Get(0, 0) << std::endl;
    Diagonal::WhoAmI();

    std::cout << std::endl;
    d->Display();

    return 0;
}