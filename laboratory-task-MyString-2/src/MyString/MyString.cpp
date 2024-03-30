#include "MyString.hpp"

/* =========================================================================== */
/* ============================== Конструкторы =============================== */
/* =========================================================================== */

// Конструктор по умолчанию
MyString::MyString()
{
    str = new char[1]; 
    str[0] = '\0';     
    length = 0;
}

// Конструктор c параметрами
MyString::MyString(const char* str)
{
   
    length = strlen(str);
    this->str = new char[length + 1]; // для 0-терминатора используем +1;

    for (size_t i = 0; i < length; i++)
    {
        this->str[i] = str[i];
    }

    this->str[length] = '\0'; // закрытие строки 0-терм.
}

// Конструктор копирования. 
MyString::MyString(const MyString& other)
{
    length = strlen(other.str);
    this->str = new char[length + 1];

    for (size_t i = 0; i < length; i++)
    {
        this->str[i] = other.str[i];
    }

    this->str[length] = '\0';
}



// Деструктор
MyString::~MyString()
{
    delete[] this->str;
}

/* =========================================================================== */

/* =========================================================================== */
/* ============================ Геттеры ====================================== */
/* =========================================================================== */

// Получение строки
char* MyString::getString() const
{
    char* res = new char[this->length + 1]; 
    strcpy(res, this->str);
    return res;
}

// Получение длины строки
size_t MyString::getLength() const
{
    return length;
}

/* =========================================================================== */

/* =========================================================================== */
/* ============== Перегрузки бинарных арифметических операторов ============== */
/* =========================================================================== */

// Бинарное сложение (конкатенация строк)
MyString MyString::operator+(const MyString& other)
{
    MyString newStr;
    size_t thisLength = strlen(this->str);
    size_t otherLength = strlen(other.str);
    newStr.length = thisLength + otherLength;
    newStr.str = new char[thisLength + otherLength + 1];
    size_t i = 0;
    for (; i < thisLength; i++)
    {
        newStr.str[i] = this->str[i];
    }
    for (size_t j = 0; j < otherLength; j++, i++)
    {
        newStr.str[i] = other.str[j];
    }
    newStr.str[thisLength + otherLength] = '\0';
    return newStr;
}

/* ======================================================================== */

/* =========================================================================== */
/* =================== Перегрузки операторов присваивания ==================== */
/* =========================================================================== */

// Дефолтный оператор присваивания
MyString& MyString::operator=(const MyString& other)
{
    if (this->str != nullptr)
    {
        delete[] str;
    }

    length = strlen(other.str);
    this->str = new char[length + 1];

    for (size_t i = 0; i < length; i++)
    {
        this->str[i] = other.str[i];
    }

    this->str[length] = '\0';
    return *this;
}

// Оператор присваивания сложения
MyString& MyString::operator+=(const MyString& other)
{
    MyString newStr;
    newStr = newStr + other.str;
    return newStr;
}

/* =========================================================================== */

/* =========================================================================== */
/* ===================== Перегрузки операторов сравнения ===================== */
/* =========================================================================== */

// Оператор "равно"
bool MyString::operator==(const MyString& other) const
{
    if (this->length != other.length)
    {
        return false;
    }
    for (size_t i = 0; i < this->length; i++)
    {
        if (this->str[i] != other.str[i])
        {
            return false;
        }
    }
    return true;
}


// Оператор "неравно"
bool MyString::operator!=(const MyString& other) const
{
    return !(this->operator==(other));
}

// Оператор "меньше"
bool MyString::operator<(const MyString& other) const
{
    return strcmp(str, other.str) < 0;
}

// Оператор "больше"
bool MyString::operator>(const MyString& other) const
{
    return *this != other && !(*this < other);
}

 
std::ostream& MyString::Print(std::ostream& os) const
{
    return os << str;
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
    return str.Print(os);
}

std::istream& operator>>(std::istream& input, MyString& s)
{
    const int bufferSize = 1000;
    char buffer[bufferSize];
    input.getline(buffer, bufferSize);
    // Проверка на переполнение строки
    size_t inputLength = strlen(buffer);
    if (inputLength > 0 && buffer[inputLength - 1] == '\n')
    {
        buffer[inputLength - 1] = '\0'; // Убираем символ новой строки
        inputLength--;                  // Уменьшаем длину на 1
    }
    s.length = inputLength;
    delete[] s.str;                    // Освобождаем старую память
    s.str = new char[inputLength + 1]; // +1 для символа нуль-терминатора
    strcpy(s.str, buffer);
    return input;
}

char& MyString::operator[](size_t index)
{
    return this->str[index];
}