#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"

using namespace std;

/**
 * @brief Проверяет, является ли строка допустимым текстом для шифрования.
 *
 * Строка считается допустимой, если все символы - буквы в верхнем регистре.
 *
 * @param s Строка для проверки.
 * @return true, если строка допустима, в противном случае - false.
 */
bool isValid(const wstring& s)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    for(auto c: s)
        if (!isalpha(c, loc) || !isupper(c, loc))
            return false;
    return true;
}

/**
 * @brief Основная функция программы для шифрования и дешифрования текста.
 *
 * Программа запрашивает у пользователя ключ и текст, затем выполняет
 * шифрование или дешифрование в зависимости от выбранной операции.
 *
 * @param argc Количество аргументов командной строки.
 * @param argv Массив аргументов командной строки.
 * @return Код возврата программы.
 */
int main(int argc, char **argv)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);

    wstring key;
    wstring text;
    unsigned op;

    wcout << "Cipher ready. Input key: ";
    wcin >> key;

    if (!isValid(key)) {
        cerr << "key not valid\n";
        return 1;
    }

    wcout << "Key loaded\n";
    modAlphaCipher cipher(key);

    do {
        wcout << "Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
        wcin >> op;

        if (op > 2) {
            wcout << "Illegal operation\n";
        } else if (op > 0) {
            wcout << "Cipher ready. Input text: ";
            wcin >> text;

            if (isValid(text)) {
                if (op == 1) {
                    wcout << "Encrypted text: " << cipher.encrypt(text) << endl;
                } else {
                    wcout << "Decrypted text: " << cipher.decrypt(text) << endl;
                }
            } else {
                wcout << "Operation aborted: invalid text\n";
            }
        }
    } while (op != 0);

    return 0;
}
