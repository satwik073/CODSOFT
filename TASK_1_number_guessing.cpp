#include <iostream>
#include <random>
int main()
{
    std::random_device rd;
    std::uniform_int_distribution<int> distribution(1, 100);
    int random_number = distribution(rd);
    int user_num;
    while (user_num != random_number)
    {

        std::cin >> user_num;
        if (user_num > random_number)
        {
            std::cout << "Number provided by you is GREATER than generated number" << std::endl;
        }
        else if (user_num < random_number)
        {
            std::cout << "Number provided by you is SMALLER than generated number" << std::endl;
        }
        else
        {
            std::cout << "Number SuccessfulLy Guessed !";
        }
    }

    return 0;
}
