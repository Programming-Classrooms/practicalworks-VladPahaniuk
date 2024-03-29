#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <iostream>
#include <numeric>

class Exception {
public:
    Exception(const char* message) : message(message) {}
    const char* getMessage() const { return message; }

private:
    const char* message;
};

class Fraction {
private:
    int64_t numerator;
    int64_t denominator;
    void reduce();

public:
    Fraction(); // Конструктор по умолчанию
    Fraction(int64_t, int64_t); // Конструктор с параметрами
    Fraction(const Fraction&); // Конструктор копирования
    ~Fraction(); // Деструктор

    int64_t getNumerator()const;// Получение числителя
    int64_t getDenuminator()const;// Получение знаменателя

    void setNumerator(int64_t);// Установка числителя
    void setDenuminator(int64_t);// Установка знаменателя


    Fraction& operator=(const Fraction&); // Оператор присваивания

    Fraction operator+(const Fraction&) const; // Оператор сложения
    Fraction& operator+=(const Fraction&);
    Fraction operator-(const Fraction&) const; // Оператор вычитания
    Fraction& operator-=(const Fraction&);
    Fraction operator*(const Fraction&) const; // Оператор умножения
    Fraction& operator*=(const Fraction&);
    Fraction operator/(const Fraction&) const; // Оператор деления
    Fraction& operator/=(const Fraction&);

    bool operator==(const Fraction&) const; // Оператор равенства
    bool operator!=(const Fraction&) const; // Оператор неравенства
    bool operator<(const Fraction&) const; // Оператор меньше
    bool operator>(const Fraction&) const; // Оператор больше
    bool operator<=(const Fraction&) const; // Оператор меньше или равно
    bool operator>=(const Fraction&) const; // Оператор больше или равно

    Fraction& operator++(); // Префиксный инкремент
    Fraction operator++(int); // Постфиксный инкремент
    Fraction& operator--(); // Префиксный декремент
    Fraction operator--(int); // Постфиксный декремент
    Fraction operator-() const; // Унарный минус
    Fraction operator!() const; // Оператор отрицания (обратная дробь)

    friend std::istream& operator>>(std::istream&, Fraction&); // Ввод из потока
    friend std::ostream& operator<<(std::ostream&, const Fraction&); // Вывод в поток

    operator double() const; // Приведение к вещественному типу
};
#endif
