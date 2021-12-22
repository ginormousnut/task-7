//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>


using namespace std;

string encode(string str, string alpha) //функция для зашифровки слова
{

    int i;
    int n = size(str); //количество символов в строке
    for (i = 0; i < n; i++) 
    {
        char z = str[i]; //некоторую символьную переменную присваиваем букве слова
        int x = z - 'a'; //ищем номер буквы в обычном латинском алфавите(в данном случае только маленькие буквы)
        str[i] = alpha[x]; //присваиваем нашей букве букву нового алфавита alpha, которая стоит на той же i-той позиции
    }
    return str; //возвращаемся к слову
}

string decode(string str, string alpha) //функция для расшифровки слова, используется обратный принцип функции encode
{

    int i;
    int n = size(str);
    string alphabet = "abcdefghijklmnopqrstuvwxyz"; //задаем обычный латинский алфавит
    for (i = 0; i < n; i++)
    {
        char z = str[i];
        int x;
        x = alpha.find(z); //с помощью функции find ищем среди нового алфавита alpha позицию зашифрованной буквы("z")
        str[i] = alphabet[x]; //с помощью обычного латинского алфавита расставляем буквы по своим местам(то есть получаем оригинальное слово)
    }
    return str;
}


int main()
{
    setlocale(LC_ALL, "");
    int q = 1;
    while (q == 1)
    {
        cout << "Введите 1 для запуска, 0 для завершения программы>";
        cin >> q;
        switch (q)
        {
        case(0):
        {
            cout << "Программа завершена";
            break;
        }
        case(1):
        {
            ifstream file;
            string s, a, s1, a1;
            file.open("1.txt"); //открываем файл
            getline(file, s); //считываем слово из файла
            getline(file, a);//считываем алфавит из файла
            file.close(); //закрываем файл
            cout << s << endl << a << endl; //выводим слово и алфавит
            string str1 = encode(s, a); //функция зашифровки некоторого слова "s" с помощью нового алфавита "a"
            cout << str1 << endl; //выводим ее результат
            string str2 = decode(str1, a); //декодирование(расшифровка) выше зашифрованного слова "str1"
            cout << str2 << endl; //вывод расшифрованного слова
            cout << "Введите слово-> " << endl; 
            cin >> s1; //т.к. в условии к программме написано, что пользователь должен привести свой пример слова, введите ваш пример
            cout << "Введите алфавит-> " << endl;
            cin >> a1; //также пример вашего алфавита
            string str3 = encode(s1, a1); //ниже всё аналогично уже заданному примеру(тому, что написано выше)
            cout << str3 << endl;
            string str4 = decode(str3, a1);
            cout << str4;
        }
        default: //если вы ввели не 0 или 1, а другое число в начале программы
        {
            cout << endl;
            q = 1;
            continue;
        }
        }
    }

}

