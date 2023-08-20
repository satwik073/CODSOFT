#include <iostream>
#include <vector>

void displayBoard(const std::vector<std::vector<char>> &board)
{
    for (const auto &row : board)
    {
        for (char cell : row)
        {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

bool checkWin(const std::vector<std::vector<char>> &board, char player)
{
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

int main()
{
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';

    std::cout << "Tic-Tac-Toe Game" << std::endl;

    bool gameEnded = false;

    while (!gameEnded)
    {
        displayBoard(board);

        int row, col;
        std::cout << "Player " << currentPlayer << ", enter row (0-2): ";
        std::cin >> row;
        std::cout << "Player " << currentPlayer << ", enter column (0-2): ";
        std::cin >> col;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
        {
            board[row][col] = currentPlayer;

            if (checkWin(board, currentPlayer))
            {
                displayBoard(board);
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                gameEnded = true;
            }
            else
            {
                bool boardFull = true;
                for (const auto &row : board)
                {
                    for (char cell : row)
                    {
                        if (cell == ' ')
                        {
                            boardFull = false;
                            break;
                        }
                    }
                    if (!boardFull)
                        break;
                }
                if (boardFull)
                {
                    displayBoard(board);
                    std::cout << "It's a draw!" << std::endl;
                    gameEnded = true;
                }
                else
                {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            }
        }
        else
        {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }

    return 0;
}
