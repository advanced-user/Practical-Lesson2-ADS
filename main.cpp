#include <iostream>
using namespace std;

int F(int n)
{
    if(n == 0)
        return 3;
    else if(n > 0)
        return 4 * F(n - 1) + 2 * F(n / 2) + 7;
}

int Prod(int a, int b)
{
    if(b == 0)
        return 0;

    if(b < 0)
    {
        b = -b;
        a = -a;
    }

    return a + Prod(a, b-1);
}


int main() {
    cout << F(3) << endl;
    cout << Prod(-26, 25) << endl;

    return 0;
}
