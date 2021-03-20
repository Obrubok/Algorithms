#include <iostream>
#include <cassert>

using namespace std;

class Fibonacci
{
    public:
        static int get(int n)
        {
            assert(n >= 0);
            int Fib[n+1];
            Fib[0] = 0;
            Fib[1] = 1;
            for(int i = 2; i <= n; i++) {
                Fib[i] = Fib[i - 1] + Fib[i - 2];
            }
            n = Fib[n];

            return n;
        }
};

int main(void)
{
    int n;
    cin >> n;
    cout << Fibonacci::get(n) <<endl;
    return 0;
}
