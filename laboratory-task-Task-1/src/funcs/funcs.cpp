#include "../funcs/funcs.hpp"

Employee::~Employee()
{}


bool checkFile(std::ifstream& file)
{
  if (!file.good())
  {
    throw std::invalid_argument("File not found...");
  }

  if (!file)
  {
    throw std::ios_base::failure("Error reading file... ");
  }

  if (file.peek() == EOF)
  {
    throw std::runtime_error("File is empty...");
  }

  return true;
}

std::string readFromFile(std::string path)
{

  std::ifstream fin(path);
	std::string line, text;

	if (checkFile(fin)) {
		std::getline(fin, line);
		while (std::getline(fin, line)) {
			text.append(line);
			text.append(" ");
		}
		fin.close();
		text[text.size() - 1] = '\0';
		return text;
	}
  
}

bool isDigit(std::string word)
{
  size_t size = word.size();
  if (word[0] == '-' || isdigit(word[0])) {
    for (size_t i = 1; i < size; ++i) {
      if (!isdigit(word[i])) {
        return false;
      }
    }
    return true;
  }
  return false;

}

void fillArrayOfDigit(int32_t* arr, std::string text, std::string delims)
{
  	
	std::string word;
	size_t begin = 0;
	size_t end = 0;
	size_t i = 0;
	begin = text.find_first_not_of(delims, end);
	end = text.find_first_of(delims, begin);
	bool textHaveNumbers = false;
	while (begin < end) {
		word = text.substr(begin, (end - begin));
		if (isDigit(word)) {
			textHaveNumbers = true;
			arr[i++] = std::stoi(word);
		}
		begin = text.find_first_not_of(delims, end);
		end = text.find_first_of(delims, begin);
	}

}

void printArrayofDigit(int32_t* arr, size_t size)
{
  for (size_t i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void copySortEvenOddArrays(int32_t* mainArr, int32_t* sortArr, size_t size)
{
  size_t j = 0;
  for (size_t i = 0; i < size; ++i)
  {
    if (mainArr[i] % 2 == 0) {
      sortArr[j++] = mainArr[i];
    }
  }
  for (size_t i = 0; i < size; ++i)
  {
    if (mainArr[i] % 2 != 0) {
      sortArr[j++] = mainArr[i];
    }
  }
}

std::string getDelimiters(std::string path) 
{
  std::ifstream fin(path);
  std::string delimiters{};

  if (checkFile(fin)) {
    std::getline(fin, delimiters);
    if (delimiters.size() == 0) {
      throw std::invalid_argument("Delimiters must be\n");
    }
    return delimiters;
  }
}

bool isWord(std::string word)
{
  size_t size = word.size();
  if (isupper(word[0])) {
    for (size_t i = 1; i < size; ++i) {
      if (!isalpha(word[i])) {
        return false;
      }
    }
    return true;
  }
  return false;
}

size_t getSizeForArrNumbers(std::string text, std::string delimiters)
{
  std::string word;
  size_t begin = 0;
  size_t end = 0;
  size_t size = 0;

  begin = text.find_first_not_of(delimiters, end);
  end = text.find_first_of(delimiters, begin);
  while (begin < end) {
    word = text.substr(begin, (end - begin));
    if (isDigit(word)) {
      ++size;
    }
    begin = text.find_first_not_of(delimiters, end);
    end = text.find_first_of(delimiters, begin);
  }
  return size;
  
}

size_t getSizeForArrSurenames(std::string text, std::string delimiters)
{
  std::string word;
  size_t begin = 0;
  size_t end = 0;
  size_t size = 0;
  begin = text.find_first_not_of(delimiters, end);
  end = text.find_first_of(delimiters, begin);
  while (begin < end) {
    word = text.substr(begin, (end - begin));
    if (isWord(word)) {
      ++size;
    }
    begin = text.find_first_not_of(delimiters, end);
    end = text.find_first_of(delimiters, begin);
  }
  return size;
}

void fillArraySurnames(std::string* arr, std::string text, std::string delims)
{
  std::string word;
  size_t begin = 0;
  size_t end = 0;
  size_t i = 0;

  begin = text.find_first_not_of(delims, end);
  end = text.find_first_of(delims, begin);
  while (begin < end) {
    word = text.substr(begin, (end - begin));
    if (isWord(word)) {
      arr[i++] = word;
    }
    begin = text.find_first_not_of(delims, end);
    end = text.find_first_of(delims, begin);
  }

  
}

void printArrayOfSurnames(std::string* arr, size_t size)
{
  for (size_t i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void cleanupArrayOfSurnames(std::string*& arr)
{
  delete[] arr;
}

std::string toUpper(std::string word)
{
  for (size_t i = 0; i < word.size(); ++i) {
    word[i] = std::toupper(word[i]);
  }
  return word;
}
bool compStrings(std::string wordFirst, std::string wordSecond)
{
  wordFirst = toUpper(wordFirst);
  wordSecond = toUpper(wordSecond);
  return (wordFirst < wordSecond);
}

void qsortString(std::string* arr, size_t left, size_t right)
{
  size_t begin = left;
  size_t end = right;
  size_t mid = (left + right) / 2;


  while (end > begin) {
    while (compStrings(arr[begin], arr[mid])) {
      ++begin;
    }
    while (compStrings(arr[mid], arr[end])) {
      --end;
    }
    if (begin < end) {
      std::swap(arr[end], arr[begin]);
      --end;
      ++begin;
    }
  }

  if (end < right) {
    qsortString(arr, right, end);
  }
  if (begin > left) {
    qsortString(arr, begin, left);
  }
}

template<typename T>
void universalQsort(T* arr, size_t left, size_t right, bool comp(T, T))
{
  size_t begin = left;
  size_t end = right;
  size_t mid = (left + right) / 2;

  while (end > begin) {
    while (comp(arr[begin], arr[mid])) {  
      ++begin;
    }
    while (comp(arr[mid], arr[end])) { 
      --end;
    }
    if (begin < end) {
      std::swap(arr[end], arr[begin]);
      --end;
      ++begin;
    }
  }

  if (end < right) {
    universalQsort(arr, right, end, comp);
  }
  if (begin > left) {
    universalQsort(arr, begin, left, comp);
  }
}
size_t inputChildren(std::string message)
{
  size_t count = 0;
  bool validInput = false;

  while (!validInput) {
    std::cout << "Please enter a count of children for >>" << message << std::endl;
    std::cin >> count;

    if (count <= 9) {
      validInput = true;
    } else {
      std::cout << "Invalid input! Count of children must be 9 or less." << std::endl;
   
      std::cin.clear();

      while (std::cin.get() != '\n')
        continue;
    }
  }
  return count;
}

void fillingArrOfStruct(Employee* arrOfSttuct, int32_t* arrOfChildren, std::string* arrOfSurenames,
  size_t sizeOfSurenames, size_t sizeOfChildren
)
{
  bool isNumer;
  size_t j = 0;
  for (size_t i = 0; i < sizeOfSurenames; ++i)
  {
    isNumer = false;
    arrOfSttuct[i].surename = arrOfSurenames[i];
    for (; j < sizeOfChildren; ++j) {
      if (arrOfChildren[j] < 10 && arrOfChildren[j] >= 0) {
        isNumer = true;
        arrOfSttuct[i].children = arrOfChildren[j];
        ++j;
        break;
      }
    }
    if (!isNumer) {
      arrOfSttuct[i].children = inputChildren(arrOfSttuct[i].surename);
    }
  }
}

void printArrayOfStruct(Employee* arr, size_t size)
{
  for (size_t i = 0; i < size; ++i) {
    std::cout << arr[i].surename << ' ' << arr[i].children << std::endl;
  }
}

bool compForStructToLower(Employee firstPerson, Employee secondPerson)
{
  if (toUpper(firstPerson.surename) == toUpper(secondPerson.surename)) {
    return firstPerson.children > secondPerson.children;
  }
  return toUpper(firstPerson.surename) > toUpper(secondPerson.surename);
}

bool compForStructToUpper(Employee firstPerson, Employee secondPerson)
{
  if (toUpper(firstPerson.surename) == toUpper(secondPerson.surename)) {
    return firstPerson.children < secondPerson.children;
  }
  return toUpper(firstPerson.surename) < toUpper(secondPerson.surename);
}
void writeArrOfStruct(std::string path, Employee* arr, size_t size)
{
  std::ofstream fout(path);
  if (fout.is_open()) {
    for (size_t i = 0; i < size; ++i) {
      fout << arr[i].surename << " " << arr[i].children << std::endl;
    }
    std::cout << "File save.";
    fout.close();
  }
}

void writeArrOfStructToBin(std::string path, Employee* arr, size_t size)
{
  std::ofstream fout(path, std::ios::binary);
  if (fout.is_open()) {
    for (size_t i = 0; i < size; ++i) {
      fout.write(reinterpret_cast<char*>(&arr[i]), sizeof(Employee));
    }
    std::cout << "\nBin file is save!!!";
    fout.close();
  }
}

void variantOfSort(Employee* employees, size_t size)
{
    bool (*funckOfSort[2])(Employee firstPerson, Employee secondPerson) = { compForStructToLower, compForStructToUpper };
    size_t variant = 0;

    std::cout << "Method of sort 1) for descending or 2) for ascending: ";
    std::cin >> variant;

    while (variant < 1 || variant > 2) {
        std::cout << "Invalid option. Please enter 1 for descending or 2 for ascending: ";
        std::cin >> variant;
    }

    switch (variant) {
        case 1:
            universalQsort(employees, 0, size - 1, funckOfSort[0]);
            break;
        case 2:
            universalQsort(employees, 0, size - 1, funckOfSort[1]);
            break;
    }
}

size_t getPoiterLast(std::ifstream& fin, struct Employee& employeeLast, struct Employee& employeeFirst)
{
  size_t pointerToLast = 0;

  fin.read(reinterpret_cast<char*>(&employeeFirst), sizeof(Employee));
  while (fin.read(reinterpret_cast<char*>(&employeeLast), sizeof(Employee))) {
    pointerToLast = fin.tellg();
  }

  return pointerToLast;
}

void swapLinesInBinareFile(std::ofstream& fout, size_t pointerToLast, struct Employee employeeLast, struct Employee employeeFirst)
{
  fout.seekp(0);
  fout.write(reinterpret_cast<char*>(&employeeLast), sizeof(employeeLast));
  fout.seekp(pointerToLast - sizeof(employeeLast));
  fout.write(reinterpret_cast<char*>(&employeeFirst), sizeof(employeeFirst));
}