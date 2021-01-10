#include <iostream>

int main(int argc, char **argv)
{
    int n;
    std::cin >> n;
    std::string card, name;

    std::string cards[100];

    while (n)
    {

        for (int i = 0; i < n; i++)
        {
            cards[i] = "";
        }

        int currentIndex = 0;
        for (int i = 0; i < n; i++)
        {
            std::cin >> card >> name;

            for (int increment = 0; increment < name.size() - 1; increment++)
            {
                while (cards[currentIndex] != "")
                {
                    currentIndex = (currentIndex + 1) % n;
                }
                currentIndex = (currentIndex + 1) % n;
            }
            while (cards[currentIndex] != "")
            {
                currentIndex = (currentIndex + 1) % n;
            }
            cards[currentIndex] = card;
            currentIndex = (currentIndex + 1) % n;
        }

        for (int i = 0; i < n; i++)
        {
            if (i > 0)
            {
                std::cout << " ";
            }
            std::cout << cards[i];
        }
        std::cout << std::endl;
        std::cin >> n;
    }

    return 0;
}