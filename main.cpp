#include "byblik.h"
using namespace std;
bool isValid(const string& s)
{
    for(auto c:s)
        if (!isalpha(c) || !isupper(c))
            return false;
    return true;
}

int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    bool isTrue = true;
    wcout << L"Добро пожаловать в программу для шифрования." << endl;
    int key;
    wstring text;
    wstring action;
    wcout<<L"Введите ключ: ";
    wcin>>key;
    if (!wcin.good()) {
        wcerr<<L"Ключ неверный!(ключ должен быть числовым значением)\n";
        return 1;
    }

    ByB cipher(key);
    do {
        wcout<<L"Укажите действие (exit-выход, 1-шифрование, 2-расшифрование): ";
        wcin>>action;
        if (action != L"1" && action != L"2" && action != L"exit") {
            wcout << L"Введите любую последовательность символов, чтобы продолжить.\n";
            wcin >> action;
        }

        if (action == L"1") {
            wcout << L"Введите строку:"<<endl;
            wcin>> text;
            wcout << L"Зашифрованная строка:"<<cipher.encrypt(text)<<endl;
        }
        if (action == L"2") {
            wcout << L"Введите строку:"<<endl;
            wcin>> text;
            wcout << L"Расшифрованная строка:"<<cipher.decrypt(text)<<endl;
        }
        if (action == L"exit") {
            wcout << L"Программа завершила работу." << endl;
            isTrue = false;
            break;
        }


    } while (isTrue != false);
    return 0;
}
