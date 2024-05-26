#include <set>
#include <string>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include "../funcs/funcs.hpp"


int main()
{
	try
	{
		std::unordered_map<std::string, int> wordCounts;
		std::set<std::string> uniqueWords;

		countWordOccurrences("src/files/file.txt", wordCounts, uniqueWords);
		printUniqueWords(uniqueWords);
		printWordCounts(wordCounts);
		
		return 0;
	}
	catch (const std::runtime_error &error)
	{
		std::cerr << error.what() << '\n';
	}
	catch (const std::invalid_argument &error)
	{
		std::cerr << error.what() << '\n';
	}
	catch (const std::ios_base::failure &error)
	{
		std::cerr << error.what() << '\n';
	}
}
