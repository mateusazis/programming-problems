#include <iostream>

static int n;
static std::string cards[100];
static int currentIndex = 0;

static void reset()
{
    for (int i = 0; i < n; i++)
    {
        cards[i] = "";
    }
    currentIndex = 0;
}

static void advanceCurrentIndexToNextEmptyPosition()
{
    do
    {
        currentIndex = (currentIndex + 1) % n;
    } while (cards[currentIndex] != "");
}

static void printResult()
{
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            std::cout << " ";
        }
        std::cout << cards[i];
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    std::cin >> n;
    std::string card, name;

    while (n)
    {
        reset();
        for (int i = 0; i < n; i++)
        {
            std::cin >> card >> name;

            for (int increment = 0; increment < name.size() - 1; increment++)
            {
                // The currentIndex always starts pointing at an empty slot; advance length-1 times.
                advanceCurrentIndexToNextEmptyPosition();
            }
            cards[currentIndex] = card;
            // If there is any available slot (not the last card), move the cursor to the next empty one.
            if (i < n - 1)
            {
                advanceCurrentIndexToNextEmptyPosition();
            }
        }
        printResult();

        std::cin >> n;
    }

    return 0;
}