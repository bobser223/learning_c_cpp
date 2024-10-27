//
// Created by Volodymyr Avvakumov on 27.10.2024.
//
#include "../HashDict.h"
#include <iostream>
#include <gtest/gtest.h>

// Тест для додавання елементів
TEST(HashDictTest, AddElement) {
HashDict<int, std::string> dict;
dict.add(1, "first");
dict.add(2, "second");

EXPECT_TRUE(dict.is_in(1));
EXPECT_TRUE(dict.is_in(2));
EXPECT_FALSE(dict.is_in(3));
}

// Тест для видалення елементів
TEST(HashDictTest, RemoveElement) {
HashDict<int, std::string> dict;
dict.add(1, "first");
dict.add(2, "second");

dict.pop(1);

EXPECT_FALSE(dict.is_in(1));
EXPECT_TRUE(dict.is_in(2));

// Перевірка, чи виникає виняток при видаленні неіснуючого ключа
EXPECT_THROW(dict.pop(3), std::logic_error);
}

// Тест для перевірки заповнюваності
TEST(HashDictTest, Occupancy) {
HashDict<int, std::string> dict;

for (int i = 0; i < 4; ++i) {
dict.add(i, "value");
}

// Перевірка, чи заповнюваність не перевищує 75%
EXPECT_LE(dict.get_occupancy(), 75);
}

// Тест для обробки випадків, коли хеш-таблиця перевантажена
TEST(HashDictTest, ResizeAndRehash) {
HashDict<int, std::string> dict;

// Додаємо більше елементів для перевищення порогу в 75%
for (int i = 0; i < 10; ++i) {
dict.add(i, "value" + std::to_string(i));
}

// Очікуємо, що заповнюваність менша або дорівнює 75%, оскільки таблиця повинна була збільшитися
EXPECT_LE(dict.get_occupancy(), 75);
}

// Тест для перевірки методу копіювання (переміщення елементів при ресайзі)
TEST(HashDictTest, CopyListDuringResize) {
HashDict<int, std::string> dict;

dict.add(1, "one");
dict.add(2, "two");

// Форсуємо ресайз
for (int i = 3; i < 10; ++i) {
dict.add(i, "value" + std::to_string(i));
}

// Перевірка збереження старих елементів
EXPECT_TRUE(dict.is_in(1));
EXPECT_TRUE(dict.is_in(2));
}

// Тест на виведення всього словника
TEST(HashDictTest, PrintDictionary) {
HashDict<int, std::string> dict;
dict.add(1, "one");
dict.add(2, "two");

std::ostringstream oss;
oss << dict;

EXPECT_FALSE(oss.str().empty());
}

// Тест для перевірки різних типів ключів
TEST(HashDictTest, DifferentKeyTypes) {
HashDict<std::string, int> dict;
dict.add("first", 1);
dict.add("second", 2);

EXPECT_TRUE(dict.is_in("first"));
EXPECT_TRUE(dict.is_in("second"));
EXPECT_FALSE(dict.is_in("third"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


//
//int main(){
//    HashDict<int, int> dict;
//    dict.add(1, 2);
//    std::cout << dict << std::endl;
//    std::cout << dict.is_in(1) << std::endl;
//    std::cout << dict.is_in(2) << std::endl;
//    dict.pop(1);
//    std::cout << dict << std::endl;
//    return 0;
//}