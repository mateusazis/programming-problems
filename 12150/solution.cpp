#include <iostream>

static int cars[100000];

int main(int argc, char **argv)
{
    int numberOfCars;
    std::cin >> numberOfCars;

    while (numberOfCars)
    {
        bool validGrid = true;

        for (int i = 0; i < numberOfCars; i++)
        {
            cars[i] = 0;
        }

        for (int i = 0; i < numberOfCars; i++)
        {
            int car, positionDiff;
            std::cin >> car >> positionDiff;

            int newPos = i + positionDiff;
            if (newPos < 0 || newPos >= numberOfCars)
            {
                validGrid = false;
                continue;
            }

            if (cars[i + positionDiff])
            {
                validGrid = false;
            }

            cars[i + positionDiff] = car;
        }

        if (validGrid)
        {
            for (int i = 0; i < numberOfCars; i++)
            {
                if (i > 0)
                {
                    std::cout << " ";
                }
                std::cout << cars[i];
            }
            std::cout << std::endl;
        }
        else
        {
            std::cout << -1 << std::endl;
        }

        std::cin >> numberOfCars;
    }
    return 0;
}