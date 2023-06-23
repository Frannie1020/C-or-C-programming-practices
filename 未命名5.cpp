#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int i = 1, sign = 1;
    double t = 1, pi = 0;
    while (fabs(t) >= 1e-7) {
        pi = pi + t;
        i = i + 2;
        sign = -sign;
        t = sign*1.0 / i;
    }
    cout << "pi= " << 4 * pi << endl;
    return 0;
}
