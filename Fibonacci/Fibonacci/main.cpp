#include <iostream>

using namespace std;

long int FibRecur(long int n);
long int FibArray(long int n);

int main()
{
    cout << FibArray(20) << endl;
}

long int FibRecur(long int n)
{
   if (n <= 1) {
       return n;
   } else {
       return FibRecur(n - 1) + FibRecur(n - 2);
   }
}

long int FibArray(long int n)
{
    long int F[n+1];
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i < n + 1; i++) {
        F[i] = F[i - 1] + F[i - 2];
    }

    return F[n];
}
