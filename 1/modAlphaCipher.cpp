#include "modAlphaCipher.h"

/**
 * @brief Конструктор класса modAlphaCipher.
 *
 * @param skey Ключ шифрования.
 */
modAlphaCipher::modAlphaCipher(const std::wstring& skey)
{
    for (unsigned i = 0; i < numAlpha.size(); i++) {
        alphaNum[numAlpha[i]] = i;
    }
    key = convert(skey);
}

/**
 * @brief Метод шифрования текста.
 *
 * @param open_text Открытый текст для шифрования.
 * @return Зашифрованный текст.
 */
std::wstring modAlphaCipher::encrypt(const std::wstring& open_text)
{
    std::vector<int> work = convert(open_text);
    for (unsigned i = 0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}

/**
 * @brief Метод дешифрования текста.
 *
 * @param cipher_text Зашифрованный текст для дешифрования.
 * @return Расшифрованный текст.
 */
std::wstring modAlphaCipher::decrypt(const std::wstring& cipher_text)
{
    std::vector<int> work = convert(cipher_text);
    for (unsigned i = 0; i < work.size(); i++) {
        work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}

/**
 * @brief Преобразование строки в вектор чисел.
 *
 * @param s Строка для преобразования.
 * @return Вектор чисел.
 */
inline std::vector<int> modAlphaCipher::convert(const std::wstring& s)
{
    std::vector<int> result;
    for (auto c : s) {
        result.push_back(alphaNum[c]);
    }
    return result;
}

/**
 * @brief Преобразование вектора чисел в строку.
 *
 * @param v Вектор чисел для преобразования.
 * @return Строка.
 */
inline std::wstring modAlphaCipher::convert(const std::vector<int>& v)
{
    std::wstring result;
    for (auto i : v) {
        result.push_back(numAlpha[i]);
    }
    return result;
}
