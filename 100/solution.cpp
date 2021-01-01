#include <algorithm>
#include <iostream>

static int getCycleLength(int n)
{
    int cycleLength = 1;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = 3 * n + 1;
        }
        cycleLength++;
    }
    return cycleLength;
}

int main(int argc, char **argv)
{
    int i;
    int j;

    while (std::cin >> i >> j)
    {
        int start = std::min(i, j);
        int end = std::max(i, j);

        int maxCycleLength = 0;
        for (int k = start; k <= end; k++)
        {
            int newCycleLength = getCycleLength(k);
            if (newCycleLength > maxCycleLength)
            {
                maxCycleLength = newCycleLength;
            }
        }
        std::cout << i << " " << j << " " << maxCycleLength << std::endl;
    }
    return 0;
}