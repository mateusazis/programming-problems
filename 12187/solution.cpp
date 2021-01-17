#include <iostream>

static int board[101][101];
static int auxBoard[101][101];

const int OFFSETS[4][2] = {
    {0, -1},
    {0, 1},
    {-1, 0},
    {1, 0}};

static const int* runBatles(int *boardPtr, int *auxBoardPtr, int k, int r, int c, int n)
{

    for (int battle = 0; battle < k; battle++)
    {

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                auxBoardPtr[i * 101 + j] = boardPtr[i * 101 + j];
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                for (int offsetIndex = 0; offsetIndex < 4; offsetIndex++)
                {
                    int neighborRow = i + OFFSETS[offsetIndex][0];
                    int neighborCol = j + OFFSETS[offsetIndex][1];
                    if (neighborRow >= 0 &&
                        neighborRow < r &&
                        neighborCol >= 0 &&
                        neighborCol < c)
                    {
                        int currHeir = boardPtr[i * 101 + j];
                        int neighborHeir = boardPtr[neighborRow * 101 + neighborCol];
                        if (currHeir == ((neighborHeir + 1) % n))
                        {
                            auxBoardPtr[i * 101 + j] = neighborHeir;
                        }
                    }
                }
            }
        }

        std::swap(boardPtr, auxBoardPtr);
    }
    return boardPtr;
}

int main(int argc, char **argv)
{
    int n, r, c, k;
    std::cin >> n >> r >> c >> k;
    while (n | r | c | k)
    {
        // read board
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                std::cin >> board[i][j];
            }
        }

        const int* finalBoard = runBatles(&board[0][0], &auxBoard[0][0], k, r, c, n);

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (j > 0)
                {
                    std::cout << " ";
                }
                std::cout << finalBoard[i * 101 + j];
            }
            std::cout << std::endl;
        }

        std::cin >> n >> r >> c >> k;
    }
    return 0;
}