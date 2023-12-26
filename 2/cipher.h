#pragma once
#include <iostream>
#include <string>
#include <algorithm>

/** @brief Шифрование методом маршрутной перестановки
 * @details Ключ устанавливается в конструкторе.
 * Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt.
 * @warning Реализация только для английского языка
 */

class Cipher {
public:
    /**
     * @brief Конструктор класса Cipher.
     * @param key Количество позиций для сдвига в алфавите.
     */
    Cipher(int key);

    /**
     * @brief Шифрует текст.
     * @param text Исходный текст для шифрования.
     * @return Зашифрованный текст.
     */
    std::string encrypt(std::string text);

    /**
     * @brief Дешифрует текст.
     * @param text Зашифрованный текст для дешифрования.
     * @return Расшифрованный текст.
     */
    std::string decrypt(std::string text);

private:
    int key_; ///< Количество позиций для сдвига в алфавите.
};
