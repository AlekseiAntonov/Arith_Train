//
// Created by user on 31.01.2020.
//
#include "main.h"
#include <ctime>
#include <random>

random_device rd;
mt19937 generator(rd());

static double RND(int a, double b){
    uniform_real_distribution<double> dis(a, b);
    return dis(generator);
}

pair<int, pair<int,int>> CreateEquation(){
    int x = (int)RND(2, 10);
    int y = (int)RND(2, 10);
    return {x * y, {x, y}};
}
int resultCheck(int answer, int rightAnswer){
    return 0;
}

int StrToInt(char *s)
{
    int temp = 0; // число
    int i = 0;
    int sign = 0; // знак числа 0- положительное, 1 - отрицательное
    if (s[i] == '-')
    {
        sign = 1;
        i++;
    }
    while (s[i] >= 0x30 && s[i] <= 0x39)
    {
        temp = temp + (s[i] & 0x0F);
        temp = temp * 10;
        i++;
    }
    temp = temp / 10;
    if (sign == 1)
        temp = -temp;
    return(temp);
}
// Функция преобразования числа в строку
char* IntToStr(int n)
{
    char s[40], t, *temp;
    int i, k;
    int sign = 0;
    i = 0;
    k = n;
    if (k<0)
    {
        sign = 1;
        k = -k;
    }
    do {
        t = k % 10;
        k = k / 10;
        s[i] = t | 0x30;
        i++;
    } while (k>0);
    if (sign == 1)
    {
        s[i] = '-';
        i++;
    }
    temp = new char[i];
    k = 0;
    i--;
    while (i >= 0) {
        temp[k] = s[i];
        i--; k++;
    }
    temp[k] = '\0';
    return(temp);
}


