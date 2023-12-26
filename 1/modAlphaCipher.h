#pragma once

#include <vector>
#include <string>
#include <map>

/** @brief Шифрование методом Гронсфельда
 * @details Ключ устанавливается в конструкторе.
 * Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt.
 * @warning Реализация только для русского языка
 */

class modAlphaCipher
{
private:
    std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; ///< Русский алфавит
    std::map <char,int> alphaNum; ///< Соответствие символов алфавита и их числовых представлений
    std::vector <int> key; ///< Ключ для шифрования/дешифрования

    /**
     * @brief Конвертирует строку символов в вектор числовых представлений согласно алфавиту.
     * @param s Строка символов для конвертации.
     * @return Вектор числовых представлений символов.
     */
    std::vector<int> convert(const std::wstring& s);

    /**
     * @brief Конвертирует вектор числовых представлений в строку символов согласно алфавиту.
     * @param v Вектор числовых представлений для конвертации.
     * @return Строка символов.
     */
    std::wstring convert(const std::vector<int>& v);

public:
    /**
     * @brief Конструктор класса modAlphaCipher.
     * @param skey Ключ для шифрования/дешифрования.
     */
    modAlphaCipher(const std::wstring& skey);

    /**
     * @brief Шифрует открытый текст.
     * @param open_text Открытый текст для шифрования. Не должен быть пустой строкой.
     *                  Строчные символы автоматически преобразуются к прописным.
     * @return Зашифрованный текст.
     */
    std::wstring encrypt(const std::wstring& open_text);

    /**
     * @brief Дешифрует зашифрованный текст.
     * @param cipher_text Зашифрованный текст для дешифрования. Не должен быть пустой строкой.
     *                    Строчные символы автоматически преобразуются к прописным.
     * @return Открытый текст.
     */
    std::wstring decrypt(const std::wstring& cipher_text);
};
