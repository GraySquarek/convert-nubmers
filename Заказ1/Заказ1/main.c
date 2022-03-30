#include <iostream>
using namespace std;
int main() {
int n;
cin » n;
if (n < 2) {
cout « n « " is less than 2";
return 0;
}
for (int i = 2; i*i <= n; ++i) {
if (n % i == 0) {
cout « n « " is a compound number"; //составное число
return 0;
}
}
cout « n « " is a prime number"; //простое число
return 0;
}
