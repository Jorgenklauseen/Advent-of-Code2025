#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

int part1()
{
    std::ifstream file("input_directions.txt");

    if (!file.is_open()) {
        std::cout << "Could not open the file" << std::endl;
        return 1;
    }

    int dial = 50;
    int count_zero = 0;

    std::string line;
    while (std::getline(file, line))
    {
        char direction = line[0];
        int number = std::stoi(line.substr(1));

        if(direction == 'R')
        {
            dial = (dial + number) % 100;
        }
        else
        {
            dial = (dial - number) % 100;

            if (dial < 0 )
            {
                dial += 100;
            }
        }
        if (dial == 0)
        {
            count_zero ++;
        }
    }
    file.close();
    return count_zero;
}

int part2()
{
    std::ifstream file("input_directions.txt");

    if (!file.is_open()) {
        std::cout << "Could not open the file" << std::endl;
        return 1;
    }

    int dial = 50;
    int count_zero = 0;

    std::string line;
    while (std::getline(file, line))
    {
        char direction = line[0];
        int number = std::stoi(line.substr(1));

        if (direction == 'R')
        {
            for (int i = 0; i < number; i++)
            {
                dial = (dial + 1) % 100;
                if (dial == 0)
                {
                    count_zero++;
                }
            }
        }
        else
        {
            for (int i = 0; i < number; i++)
            {
                dial = (dial - 1) % 100;
                if (dial < 0) {
                    dial += 100;
                }
                if (dial == 0) {
                    count_zero++;
                }
            }
        }
    }
    file.close();
    return count_zero;
}

int main()
{
    std::cout << "Part 1:  " << part1() << std::endl;
    std::cout << "Part 2:  " << part2() << std::endl;
    return 0;
}
