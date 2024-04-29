#include <iostream>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void displayBoard() {
    cout << "  |  |  " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        if (i < 2) {
            cout << "-----+-----+-----" << endl;
        }
    }
    cout << "  |  |  " << endl;
}

int getPlayerChoice(char player) {
    int choice;
    while (true) {
        cout << player << ", enter your move (1-9): ";
        cin >> choice;
        if (choice >= 1 && choice <= 9) {
            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;
            if (board[row][col] == ' ') {
                return choice;
            } else {
                cout << "Invalid move. Please choose an empty space." << endl;
            }
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 9." << endl;
        }
    }
}

void placeMove(int choice, char player) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    board[row][col] = player;
}

bool checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

bool isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char currentPlayer = 'X';
    bool playAgain = true;

    while (playAgain) {
        // Reset the board
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }

        while (true) {
            displayBoard();
            int choice = getPlayerChoice(currentPlayer);
            placeMove(choice, currentPlayer);

            if (checkWin(currentPlayer)) {
                displayBoard();
                cout << currentPlayer << " wins!" << endl;
                break;
            }

            if (isBoardFull()) {
                displayBoard();
                cout << "It's a draw!" << endl;
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        char playAgainInput;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgainInput;

        if (!(playAgainInput == 'y' || playAgainInput == 'Y')) {
            playAgain = false;
        }
    }

    return 0;
}
