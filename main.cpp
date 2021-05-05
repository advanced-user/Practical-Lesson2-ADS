#include <iostream>
using namespace std;

int F(int n)
{
    if(n == 0)
        return 3;

    return 4 * F(n - 1) + 2 * F(n / 2) + 7;
}


int main() {
    cout << F(3);


    return 0;
}
