//  main.cpp
//
//  Created by Сергей Сергеев on 07/10/2019.
//  Copyright © 2019 Сергей Сергеев. All rights reserved.


#include <iostream>
#include <fstream>
using namespace std;

string f1(int a) {
    string str;
    if (a == 1) {str = "один";}
    if (a == 2) {str = "два";}
    if (a == 3) {str = "три";}
    if (a == 4) {str = "четыре";}
    if (a == 5) {str = "пять";}
    if (a == 6) {str = "шесть";}
    if (a == 7) {str = "семь";}
    if (a == 8) {str = "восемь";}
    if (a == 9) {str = "девять";}
    if (a == 0) {str = " ";}
    return str;
}

string f10(int a) {
    string str;
    if (a == 2) {str = "двадцать";}
    if (a == 3) {str = "тридцать";}
    if (a == 4) {str = "сорок";}
    if (a == 5) {str = "пятьдесят";}
    if (a == 6) {str = "шестьдесят";}
    if (a == 7) {str = "семьдесят";}
    if (a == 8) {str = "восемьдесят";}
    if (a == 9) {str = "девяносто";}
    if (a == 0) {str = " ";}
    return str;
}

string ff(int a) {
    string str;
    if (a == 0) {str = " ";}
    if (a == 1) {str = "одна";}
    if (a == 2) {str = "две";}
    if (a == 3) {str = "три";}
    if (a == 4) {str = "четыре";}
    if (a == 5) {str = "пять";}
    if (a == 6) {str = "шесть";}
    if (a == 7) {str = "семь";}
    if (a == 8) {str = "восемь";}
    if (a == 9) {str = "девять";}
    if (a == 10) {str = "десять";}
    if (a == 11) {str = "одиннадцать";}
    if (a == 12) {str = "двенадцать";}
    if (a == 13) {str = "тринадцать";}
    if (a == 14) {str = "четырнадцать";}
    if (a == 15) {str = "пятнадцать";}
    if (a == 16) {str = "шестнадцать";}
    if (a == 17) {str = "семнадцать";}
    if (a == 18) {str = "восемнадцать";}
    if (a == 19) {str = "девятнадцать";}
    return str;
}

string ff1(int a) {
    string str;
    if (a == 0) {str = " ";}
    if (a == 1) {str = "один";}
    if (a == 2) {str = "два";}
    if (a == 3) {str = "три";}
    if (a == 4) {str = "четыре";}
    if (a == 5) {str = "пять";}
    if (a == 6) {str = "шесть";}
    if (a == 7) {str = "семь";}
    if (a == 8) {str = "восемь";}
    if (a == 9) {str = "девять";}
    if (a == 10) {str = "десять";}
    if (a == 11) {str = "одиннадцать";}
    if (a == 12) {str = "двенадцать";}
    if (a == 13) {str = "тринадцать";}
    if (a == 14) {str = "четырнадцать";}
    if (a == 15) {str = "пятнадцать";}
    if (a == 16) {str = "шестнадцать";}
    if (a == 17) {str = "семнадцать";}
    if (a == 18) {str = "восемнадцать";}
    if (a == 19) {str = "девятнадцать";}
    return str;
}

string f100(int a) {
    string str;
    if (a == 1) {str = "сто";}   // сто
    if (a == 2) {str = "двести";}
    if (a == 3) {str = "триста";}
    if (a == 4) {str = "четыреста";}
    if (a == 5) {str = "пятьсот";}
    if (a == 6) {str = "шестьсот";}
    if (a == 7) {str = "семьсот";}
    if (a == 8) {str = "восемьсот";}
    if (a == 9) {str = "девятьсот";}
    if (a == 0) {str = " ";}    // /////////////
    return str;
}

int main(int argc, const char * argv[]) {
    int n = 0;
    string outStr="";
    string choise, choiseIn, fn;


    cout<<"Откуда ввести результат [ф/э]?\n>";
    cin>>choiseIn;
    if(choiseIn=="ф"){
        cout<<"Введите имя файла\n>";
        cin>>fn;
        ifstream in(fn);
        in>>n;
    }
    if(choiseIn=="э"){
        cout<<"Введите число\n>";
        cin >> n;
    }
    cout<<"Куда вывести результат [ф/э]?\n>";
    cin>>choise;
    
if (n >= 10000000) {outStr += "!!!!!!!!WARNING!!!!!!!!\nВаше число превышает допустимые значения!!!!\n";}
else
    {
    

    if (n == 0) {outStr += "ноль";}
    int x = n / 1000000 % 10;
    if (x == 0) {}
    else if (x == 1) {outStr += f1(x) + " миллион ";}
    else if (x > 1 && x < 5) {outStr += f1(x) + " миллиона ";}
    else {outStr += f1(x) + " миллионов ";}
    
    x = n / 100000 % 10;
    if (x == 0) {}
    else {outStr += f100(x) + ' ';}
    
    x = n / 1000 % 100;
    if (x == 0){}
    else if (x >= 20) {
        outStr += f10(x / 10) + ' ' + ff(x % 10);
        if (x % 10 == 1) {outStr += " тысяча ";}
        else if (x % 10 > 1 && x % 10 < 5) {outStr += " тысячи ";}
        else {outStr += " тысяч ";}
    }
    else if (x < 20) {
        outStr += ff(x);
    if (x == 1) {outStr += " тысяча ";}
        else if (x > 1 && x < 5){outStr += " тысячи ";}
        else {outStr += " тысяч ";}
    }
    
    x = n / 100 % 10;  // проверям сотни и вызываем функцию f100
    if (x == 0) {}
    else {outStr += f100(x) + ' ';}
    
    x = n % 100;
    if (x == 0) {}
    else if (x >= 20) {outStr += f10(x / 10) + ' ' + ff1(x % 10);}
    else if (x < 20) {outStr += ff1(x);}
    outStr += "\n";
    }

    if(choise=="ф"){
        cout<<"Введите имя файла\n>";
        cin>>fn;
        ofstream file(fn);
        file<<outStr;
        cout<<"Ваше число записано в файл "<<fn<<"\n";
    }else
    if(choise=="э"){
        cout<<"Вы ввели число: "<<outStr;
    }else{
        cout<<"Вы выбрали несуществующую опцию\n";
    }

    return 0;
}

