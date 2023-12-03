#include <iostream>
using namespace std;

int main()
{
    int64_t num, temp, count = 0;
    bool check = 0;
    cout << "Input number:\n";
    cin >> num;
    if (num <= 0)
    {
        cout << "Not a natural.";
    }
    else
    {
        for (size_t i = 0; i <= 9; i++)
        {
            temp = num;
            count = 0;
            while (temp != 0)
            {
                if (temp % 10 == i)
                {
                    count++;
                }
                temp /= 10;
            }
            if (count >= 2)
            {
                check = 1;
                break;
            }
        }
        if (check == 1)
        {
            cout << "There are duplicates.";
        }
        else
        {
            cout << "There are no duplicates.";
        }
        return 0;
    }
}