#include <iostream>
#include <cmath>
using namespace std;
void l(double a, double b, double c)
{
double d, x1, x2;
d = b * b - 4 * a * c;
if (d < 0)
{
cout << "Нет корней";
}
if (d==0)
{
x1 = (-b) / 2 * a;
cout << x1;
}
if (d > 0)
{
x1 = ((-b+sqrt(d) )/ 2 * a);
x2 = ((-b-sqrt(d) )/ 2 * a);
cout << x1 << endl << x2;
}
}
int main()
{
double m, n, d;
cin >> m >> n >> d;
}
