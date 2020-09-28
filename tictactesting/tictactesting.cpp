#include <iostream>
#include <string>
#include <vector>

std::vector <char> board = { '1','2','3','4','5','6','7','8','9' };
bool player = true;
int value;

bool changetox(std::vector <char>& board_copy1) {
		if (board_copy1.at(value - 1) == 'X' or board_copy1.at(value - 1) == 'O') {
			std::cout << "illegal input";
			return false;
			}
		else { board_copy1.at(value - 1) = 'X';
		return true;
		}
		}

bool changetoo(std::vector <char>& board_copy2) {
	if (board_copy2.at(value - 1) == 'X' or board_copy2.at(value - 1) == 'O') {
		std::cout << "illegal input";
		return false;
	}
	else { board_copy2.at(value - 1) = 'O'; 
	return true;
	}
}
// these are here to draw the x and the o on the board


/*
bool draw(std::vector <char>& board_copy1) {
	if (board_copy1.at(0) == 'X' || board_copy1.at(0) == 'O' && board_copy1.at(1) == 'X' || board_copy1.at(1) == 'O' && board_copy1.at(2) == 'X' || board_copy1.at(2) == 'O' && board_copy1.at(3) == 'X' || board_copy1.at(3) == 'O' && board_copy1.at(4) == 'X' || board_copy1.at(4) == 'O' && board_copy1.at(5) == 'X' || board_copy1.at(5) == 'O' && board_copy1.at(6) == 'X' || board_copy1.at(6) == 'O' && board_copy1.at(7) == 'X' || board_copy1.at(7) == 'O' && board_copy1.at(8) == 'X' || board_copy1.at(8) == 'O')
	{
		return true;
	}
	else {
		return false;
	}
}
*/ // didnt get this to work

	bool wincondition() {
	for (int i = 0; i < board.size(); i++) {
		if (i % 3 == 0) {
			if (board[i] == board[i + 1] && board[i + 1] == board[i + 2]) {
				return true;
			}
			else if (board[i + 3] == board[i + 4] && board[i + 4] == board[i + 5]) {
				return true;
			}
			else if (board[i + 6] == board[i + 7] && board[i + 7] == board[i + 8]) {
				return true;
			}
			else if (board[i] == board[i + 3] && board[i + 3] == board[i + 6]) {
				return true;
			}
			else if (board[i + 1] == board[i + 4] && board[i + 4] == board[i + 7]) {
				return true;
			}
			else if (board[i + 2] == board[i + 5] && board[i + 5] == board[i + 8]) {
				return true;
			}
			else if (board[i] == board[i + 4] && board[i + 4] == board[i + 8]) {
				return true;
			}
			else if (board[i + 2] == board[i + 4] && board[i + 4] == board[i + 6]) {
				return true;
			}
			else { return false; }
		}
	}
}

	//this is here to check for the wincondition


void drawboard() {
	for (int i = 0; i < board.size(); i++) {
		if (i % 3 == 0) {
			std::cout << "\n";
		}
		std::cout << "|_";
		std::cout << board[i];
		std::cout << "_|";
	}
}
//this draws the board

int main() {

	do
	{
		drawboard(); //draws the board every loop
		if (player == true) //player 1
		{
			std::cout << "\nPlayer X turn: ";
			std::cin >> value;
			if (changetox(board)) 
			player = false;  //changes it to player 2
			if (wincondition()) {
				system("cls");   
				drawboard();
				std::cout << "\nplayer X wins" << std::endl;
				break;
			}
		}
		else
		{
			std::cout << "\nPlayer O turn: ";
			std::cin >> value;
			if (changetoo(board))
			player = true;
			if (wincondition())
			{
				system("cls");
				drawboard();
				std::cout << "\nPlayer O wins" << std::endl;
				break;
			}
		}

		system("cls");
	} while (true);

	return 0;
}