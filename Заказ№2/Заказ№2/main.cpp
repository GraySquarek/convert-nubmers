#include<iostream>
#include <algorithm>
using namespace std;

int main()
{
    int min, max, i=0;
    cout << "Enter min: " ; cin >> min;
    cout << "Enter max: " ; cin >> max;
    int *arr = new int[(max-min+1) * sizeof (int)];
    int cur=min;
    for(int i=0; i<=max-min; i++) //Заполнение массива
    arr[i] = -32+rand()%27;
    for(int i=0; i<=max-min; i++) //Вывод массива
    sort(arr, arr+i);
    cout << arr[i] << ' ';
    //for(int i = max-min - 1; i >= 0; i--)
      //  cout << arr[i] << endl;
    cin >> cur; //Чтобы окно программы не закрылось
  return 0;
}


 



//#include <iostream>
//#include <algorithm> // для std::sort()
//using namespace std;
//
//int main()
//{
//    const int length = 5;
//    int array[length] = { 30, 50, 20, 10, 40 };
//
//    std::sort(array, array+length);
//
//    for (int i=0; i < length; ++i)
//        cout << array[i] << ' ';
//
//    return 0;
//}
//
