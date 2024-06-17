#include <stdexcept>
#include <gtest/gtest.h>
#include "src/Train/Train.hpp"

TEST(TrainTest, ConstructorAndGetters) {
    Train train(123, "New York", TrainType::EXPRESS, "12:00", "2:30");
    EXPECT_EQ(train.getNumber(), 123);
    EXPECT_EQ(train.getDestination(), "New York");
    EXPECT_EQ(train.getType(), TrainType::EXPRESS);
    EXPECT_EQ(train.getDepartureTime(), "12:00");
    EXPECT_EQ(train.getTravelTime(), "2:30");
}

TEST(CheckFileTest, FileDoesNotExist) {
    std::ifstream file("nonexistent_file.txt");
    EXPECT_THROW(checkFile(file), std::invalid_argument);
}

TEST(CheckFileTest, FileIsEmpty) {
    std::ofstream outfile("empty_file.txt");
    outfile.close();
    std::ifstream file("empty_file.txt");
    EXPECT_THROW(checkFile(file), std::runtime_error);
    std::remove("empty_file.txt");
}

TEST(FillVectorTest, FillCorrectly) {
    std::ofstream outfile("trains.txt");
    outfile << "123 New_York Passenger 12:00 2:30\n";
    outfile << "456 Boston Express 13:00 3:15\n";
    outfile.close();

    std::vector<Train> trains;
    std::ifstream infile("trains.txt");
    fillVector(infile, trains);
    infile.close();

    ASSERT_EQ(trains.size(), 2);
    EXPECT_EQ(trains[0].getNumber(), 123);
    EXPECT_EQ(trains[0].getDestination(), "New_York");
    EXPECT_EQ(trains[0].getType(), TrainType::PASSENGER);
    EXPECT_EQ(trains[0].getDepartureTime(), "12:00");
    EXPECT_EQ(trains[0].getTravelTime(), "2:30");
    
    EXPECT_EQ(trains[1].getNumber(), 456);
    EXPECT_EQ(trains[1].getDestination(), "Boston");
    EXPECT_EQ(trains[1].getType(), TrainType::EXPRESS);
    EXPECT_EQ(trains[1].getDepartureTime(), "13:00");
    EXPECT_EQ(trains[1].getTravelTime(), "3:15");

    std::remove("trains.txt");
}

TEST(CompareByDepartureTimeTest, CompareCorrectly) {
    Train train1(123, "New_York", TrainType::PASSENGER, "12:00", "2:30");
    Train train2(456, "Boston", TrainType::EXPRESS, "13:00", "3:15");
    EXPECT_TRUE(compareByDepartureTime(train1, train2));
}

TEST(PrintSortTrainsByDepartureTimeTest, SortCorrectly) {
    std::vector<Train> trains = {
        Train(456, "Boston", TrainType::EXPRESS, "13:00", "3:15"),
        Train(123, "New_York", TrainType::PASSENGER, "12:00", "2:30")
    };

    testing::internal::CaptureStdout();
    printSortTrainsByDepartureTime(trains);
    std::string output = testing::internal::GetCapturedStdout();

    std::string expectedOutput = "Train number: 123, Destination: New_York, Type: Passenger, Departure Time: 12:00, Travel Time: 2:30\n"
                                 "Train number: 456, Destination: Boston, Type: Express, Departure Time: 13:00, Travel Time: 3:15\n";

    EXPECT_EQ(output, expectedOutput);
}

