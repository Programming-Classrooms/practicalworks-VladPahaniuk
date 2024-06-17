#include "src/Train/Train.hpp"
int main()
{
	std::vector<Train> trains;
	std::ifstream fileInput("src/files/Trains.txt");
	checkFile(fileInput);

	fillVector(fileInput, trains);

	printSortTrainsByDepartureTime(trains);

	printTrainsInTimeRange(trains);

	printTrainsToDestination(trains);

	printExpressTrainsToDestination(trains);

	findFastestTrainToDestination(trains);

	return 0;
}
