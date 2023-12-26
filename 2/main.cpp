/**
 * @file main.cpp
 * @brief Основной файл программы для взаимодействия с классом Cipher
 */

#include "cipher.h"

int main() {
    int key;
    std::cout << "Введите ключ: ";
    std::cin >> key;

    // Создание объекта класса Cipher с использованием введенного ключа
    Cipher cipher(key);

    std::string text;
    std::cout << "Введите текст: ";
    std::cin >> text;

    int sw;
    std::cout << "Для шифрования введите - 1 \nДля расшифровки введите - 2 -->";
    std::cin >> sw;

    // Выбор между шифрованием и расшифровкой в зависимости от введенного значения sw
    if (sw == 1){
        std::cout << "Зашифрованный текст: " << cipher.encrypt(text) << std::endl;
    }
    else if (sw == 2){
        std::cout << "Расшифрованный текст: " << cipher.decrypt(text) << std::endl;
    }
    else {
        std::cout << "Введено некорректное значение для операции." << std::endl;
    }

    return 0;
}
