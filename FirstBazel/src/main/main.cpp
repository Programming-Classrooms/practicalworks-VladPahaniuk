#include "../Function/Function.hpp"

int main()
{
  
  MyString str("Test");
  MyString str2("Hello");
  MyString str3;
  //str = str2;
  //std::cout << str;
  MyString result;
  result = str + str2;

  std::cout << result <<'\n';
  /*std::cout << str.Length() << '\n';
  std::cout << str2.Length() << '\n';
  std::cout << result.Length() <<'\n';
  
  bool equal = str == str2;
  if (equal != 0)
  {
    std::cout << "str == str2\n";
  }
  else
  {
    std::cout << "str != str2\n";
  }
  std::cout << (str != str2) << '\n';*/

  /*str[0] = 'P';
  std::cout << str[0]<<'\n';
  std::cout << str << '\n';*/
  std::cout << "InputSrting: ";
  //std::cin >> str3;
  std::cout << "You enter: "<< str3;
  return 0;
}
