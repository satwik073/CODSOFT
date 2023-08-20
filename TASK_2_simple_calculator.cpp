#include <iostream>

int main()
{
    double first_num, second_num;
    char arithmetic_opr;

    std::cout << "Enter Your First Number: ";
    std::cin >> first_num;

    std::cout << "Enter Your Second Number: ";
    std::cin >> second_num;

    std::cout << "arithmetic_oprs Available (+, -, *, /): ";
    std::cin >> arithmetic_opr;

    double calculation;

    switch (arithmetic_opr)
    {
    case '+':
        calculation = first_num + second_num;
        break;
    case '-':
        calculation = first_num - second_num;
        break;
    case '*':
        calculation = first_num * second_num;
        break;
    case '/':
        if (second_num != 0)
        {
            calculation = first_num / second_num;
        }
        else
        {
            std::cout << "Division by zero is not allowed." << std::endl;
            return 1;
        }
        break;
    default:
        std::cout << "Invalid arithmetic_opr." << std::endl;
        return 1;
    }

    std::cout << "calculation: " << calculation << std::endl;

    return 0;
}
