#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>    // Libraries I added for probability calculation
#include <ctime>
#include <fstream>
using namespace std;

enum class class_type { wall, empty, peg };

vector<vector<class_type>> board1 =
{
	{class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},    // I created the maps using strong enum as stated in the pdf
	{class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::peg,class_type::peg,class_type::peg,class_type::empty,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
};

vector<vector<class_type>> board2 =
{
	{class_type::wall,class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall},
	{class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::empty,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall},
	{class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
};

vector<vector<class_type>> board3 =
{
	{class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall},
	{class_type::peg,class_type::peg,class_type::peg,class_type::empty,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall},
	{class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},

};

vector<vector<class_type>> board4 =
{
	{class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::peg,class_type::peg,class_type::peg,class_type::empty,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::wall,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
};

vector<vector<class_type>> board5 =
{
	{class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall},
	{class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::empty,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall},
	{class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},

};


vector<vector<class_type>> board6 =
{
	{class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::empty,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::wall,class_type::peg,class_type::wall,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::peg,class_type::wall,class_type::peg,class_type::wall,class_type::peg,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::peg,class_type::wall,class_type::peg,class_type::wall,class_type::peg,class_type::wall,class_type::peg,class_type::wall,class_type::wall,class_type::wall},
	{class_type::peg,class_type::wall,class_type::peg,class_type::wall,class_type::peg,class_type::wall,class_type::peg,class_type::wall,class_type::peg,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
	{class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall,class_type::wall},
};

void print_board(int board_model) {

	if (board_model == 1) {									// This function is used for first print only

		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 7; j++) {
				if (board1[i][j] == class_type::wall)
					cout << " ";
				else if (board1[i][j] == class_type::peg)
					cout << "P";
				else if (board1[i][j] == class_type::empty)
					cout << ".";
			}
			cout << "\n";
		}
	}
	else if (board_model == 2) {

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board2[i][j] == class_type::wall)
					cout << " ";
				else if (board2[i][j] == class_type::peg)
					cout << "P";
				else if (board2[i][j] == class_type::empty)
					cout << ".";
			}
			cout << "\n";
		}
	}
	else if (board_model == 3) {

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board3[i][j] == class_type::wall)
					cout << " ";
				else if (board3[i][j] == class_type::peg)
					cout << "P";
				else if (board3[i][j] == class_type::empty)
					cout << ".";
			}
			cout << "\n";
		}
	}
	else if (board_model == 4) {

		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 7; j++) {
				if (board4[i][j] == class_type::wall)
					cout << " ";
				else if (board4[i][j] == class_type::peg)
					cout << "P";
				else if (board4[i][j] == class_type::empty)
					cout << ".";
			}
			cout << "\n";
		}
	}
	else if (board_model == 5) {

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board5[i][j] == class_type::wall)
					cout << " ";
				else if (board5[i][j] == class_type::peg)
					cout << "P";
				else if (board5[i][j] == class_type::empty)
					cout << ".";
			}
			cout << "\n";
		}
	}
	else if (board_model == 6) {

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {
				if (board6[i][j] == class_type::wall)
					cout << " ";
				else if (board6[i][j] == class_type::peg)
					cout << "P";
				else if (board6[i][j] == class_type::empty)
					cout << ".";
			}
			cout << "\n";
		}
	}

}

void print_board(int board_model, vector<vector<class_type>>& board) {  // Funtion Overloading
	if (board_model == 0) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == class_type::wall)
					cout << " ";
				else if (board[i][j] == class_type::peg)
					cout << "P";
				else if (board[i][j] == class_type::empty)
					cout << ".";
			}
			cout << "\n";
		}
	}
}

void print_board2(int board_model, vector<vector<class_type>>& board) {

	if (board_model == 0) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == class_type::wall)				// It prints the corresponding correspondence according to the type of cells
					cout << " ";
				else if (board[i][j] == class_type::peg)
					cout << "P";
				else if (board[i][j] == class_type::empty)
					cout << ".";
			}
			cout << "\n";
		}
	}
	else {

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 11; j++) {
				if (board[i][j] == class_type::wall)				// It prints the corresponding correspondence according to the type of cells
					cout << " ";
				else if (board[i][j] == class_type::peg)
					cout << "P";
				else if (board[i][j] == class_type::empty)
					cout << ".";
			}
			cout << "\n";
		}
	}
}

void save_map(vector<vector<class_type>>& board, fstream& f) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {

			if (board[i][j] == class_type::wall)
				f << 'w';
			else if (board[i][j] == class_type::peg)
				f << 'p';
			else if (board[i][j] == class_type::empty)
				f << 'e';
		}
		f << "\n";
	}
}

vector<vector<class_type>> load_game(fstream& f, int& gametype, int& boardtype) {

	vector<vector<class_type>> board;		// this function reads game from text document
	int boardinfo, gameinfo;
	f >> boardinfo;
	f >> gameinfo;
	gametype = gameinfo;
	boardtype = boardinfo;
	string line;
	vector<class_type> lineV;

	while (f.peek() != EOF) {
		f >> line;
		for (int i = 0; i < line.length(); i++)
			if (line.at(i) == 'w')
				lineV.push_back(class_type::wall);
			else if (line.at(i) == 'p')
				lineV.push_back(class_type::peg);
			else if (line.at(i) == 'e')
				lineV.push_back(class_type::empty);

		board.push_back(lineV);
		lineV.clear();
	}
	return board;
}

void board_updater(int b, int a, char directory, vector<vector<class_type>>& board, int boardmodel) {

	if (board[b][a] == class_type::peg)
		board[b][a] = class_type::empty;							// This function applies the approved move to the board.

	if (boardmodel == 6) {							// Since there are special moves on board6, I evaluated them separately.

		if (directory == 'L') {

			board[b][a - 2] = class_type::empty;
			board[b][a - 4] = class_type::peg;

		}
		else if (directory == 'R') {

			board[b][a + 2] = class_type::empty;
			board[b][a + 4] = class_type::peg;

		}
		else if (directory == 'U') {

			if (b > 1)
			{
				if (board[b - 1][a + 1] != class_type::wall && board[b - 2][a + 2] != class_type::wall) {

					board[b - 1][a + 1] = class_type::empty;
					board[b - 2][a + 2] = class_type::peg;
				}
				else if (board[b - 1][a - 1] != class_type::wall && board[b - 2][a - 2] != class_type::wall) {

					board[b - 1][a - 1] = class_type::empty;
					board[b - 2][a - 2] = class_type::peg;
				}
			}

		}
		else if (directory == 'D') {

			if (board[b + 1][a + 1] != class_type::wall && board[b + 2][a + 2] != class_type::wall) {

				board[b + 1][a + 1] = class_type::empty;
				board[b + 2][a + 2] = class_type::peg;
			}
			else if (board[b + 1][a - 1] != class_type::wall && board[b + 2][a - 2] != class_type::wall) {

				board[b + 1][a - 1] = class_type::empty;
				board[b + 2][a - 2] = class_type::peg;
			}

		}
		print_board2(boardmodel, board);     // Printing is started after the board changes accordingly
	}
	else {

		if (directory == 'L') {

			if (board[b][a - 1] != class_type::wall && board[b][a - 2] != class_type::wall) {

				board[b][a - 1] = class_type::empty;
				board[b][a - 2] = class_type::peg;
			}
		}
		else if (directory == 'R') {

			if (board[b][a + 1] != class_type::wall && board[b][a + 2] != class_type::wall) {

				board[b][a + 1] = class_type::empty;
				board[b][a + 2] = class_type::peg;
			}
		}
		else if (directory == 'U') {

			if (board[b - 1][a] != class_type::wall && board[b - 2][a] != class_type::wall) {

				board[b - 1][a] = class_type::empty;
				board[b - 2][a] = class_type::peg;
			}
		}
		else if (directory == 'D') {

			if (board[b + 1][a] != class_type::wall && board[b + 2][a] != class_type::wall) {

				board[b + 1][a] = class_type::empty;
				board[b + 2][a] = class_type::peg;
			}
		}
		print_board2(boardmodel, board);    // Printing is started after the board changes accordingly
	}
}

//###########################################################################################################################################################################

int move_control2(int b, int a, char m, vector<vector<class_type>>& board, int boardmodel) {

	if (boardmodel == 1) {						// This function returns 1 or 0 depending on the suitability of moves.

		if (m == 'L' || m == 'l') {

			if (a > 1) {
				if (board[b][a - 2] != class_type::empty || board[b][a - 1] != class_type::peg || board[b][a - 2] == class_type::wall)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}

		else if (m == 'R' || m == 'r') {

			if (a < 5) {
				if (board[b][a + 2] != class_type::empty || board[b][a + 1] != class_type::peg || board[b][a + 2] == class_type::wall)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}

		else if (m == 'U' || m == 'u') {

			if (b >= 2) {
				if (board[b - 2][a] != class_type::empty || board[b - 1][a] != class_type::peg || board[b - 2][a] == class_type::wall)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}

		else if (m == 'D' || m == 'd') {

			if (b < 5) {

				if (board[b + 2][a] != class_type::empty || board[b + 1][a] != class_type::peg || board[b + 2][a] == class_type::wall)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}
	}

	else if (boardmodel == 2) {

		if (m == 'L' || m == 'l') {

			if (a > 1) {
				if (board[b][a - 2] != class_type::empty || board[b][a - 1] != class_type::peg || board[b][a - 2] == class_type::wall)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}

		else if (m == 'R' || m == 'r') {

			if (a < 7) {
				if (board[b][a + 2] != class_type::empty || board[b][a + 1] != class_type::peg || board[b][a + 2] == class_type::wall)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}

		else if (m == 'U' || m == 'u') {

			if (b >= 2) {
				if (board[b - 2][a] != class_type::empty || board[b - 1][a] != class_type::peg || board[b - 2][a] == class_type::wall)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}

		else if (m == 'D' || m == 'd') {

			if (b < 7) {

				if (board[b + 2][a] != class_type::empty || board[b + 1][a] != class_type::peg || board[b + 2][a] == class_type::wall)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}
	}
	else if (boardmodel == 3) {

		if (m == 'L' || m == 'l') {

			if (a > 1) {
				if (board[b][a - 2] != class_type::empty || board[b][a - 1] != class_type::peg || board[b][a - 2] == class_type::wall)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}

		else if (m == 'R' || m == 'r') {

			if (a < 6) {
				if (board[b][a + 2] != class_type::empty || board[b][a + 1] != class_type::peg || board[b][a + 2] == class_type::wall)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}

		else if (m == 'U' || m == 'u') {

			if (b >= 2) {
				if (board[b - 2][a] != class_type::empty || board[b - 1][a] != class_type::peg || board[b - 2][a] == class_type::wall)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}
		else if (m == 'D' || m == 'd') {

			if (b < 6) {

				if (board[b + 2][a] != class_type::empty || board[b + 1][a] != class_type::peg || board[b + 2][a] == class_type::wall)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}
	}
	else if (boardmodel == 4) {

		if (m == 'L' || m == 'l') {

			if (a > 1) {
				if (board[b][a - 2] != class_type::empty || board[b][a - 1] != class_type::peg || board[b][a - 2] == class_type::wall)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}

		else if (m == 'R' || m == 'r') {

			if (a < 5) {
				if (board[b][a + 2] != class_type::empty || board[b][a + 1] != class_type::peg || board[b][a + 2] == class_type::wall)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}

		else if (m == 'U' || m == 'u') {

			if (b >= 2) {
				if (board[b - 2][a] != class_type::empty || board[b - 1][a] != class_type::peg || board[b - 2][a] == class_type::wall)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}

		else if (m == 'D' || m == 'd') {

			if (b < 5) {

				if (board[b + 2][a] != class_type::empty || board[b + 1][a] != class_type::peg || board[b + 2][a] == class_type::wall)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}
	}
	else if (boardmodel == 5) {

		if (m == 'L' || m == 'l') {

			if (a > 1) {
				if (board[b][a - 2] != class_type::empty || board[b][a - 1] != class_type::peg || board[b][a - 2] == class_type::wall)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}
		else if (m == 'R' || m == 'r') {

			if (a < 7) {
				if (board[b][a + 2] != class_type::empty || board[b][a + 1] != class_type::peg || board[b][a + 2] == class_type::wall)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}

		else if (m == 'U' || m == 'u') {

			if (b >= 2) {
				if (board[b - 2][a] != class_type::empty || board[b - 1][a] != class_type::peg || board[b - 2][a] == class_type::wall)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}

		else if (m == 'D' || m == 'd') {

			if (b < 7) {

				if (board[b + 2][a] != class_type::empty || board[b + 1][a] != class_type::peg || board[b + 2][a] == class_type::wall)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}
	}
	else if (boardmodel == 6) {

		if (m == 'L' || m == 'l') {

			if (a > 3) {
				if (board[b][a - 4] != class_type::empty || board[b][a - 2] != class_type::peg)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}

		else if (m == 'R' || m == 'r') {

			if (a < 5) {
				if (board[b][a + 4] != class_type::empty || board[b][a + 2] != class_type::peg)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}

		else if (m == 'U' || m == 'u') {

			if (b >= 2) {
				if (a < 7) {
					if (board[b - 2][a + 2] != class_type::empty || board[b - 1][a + 1] != class_type::peg)
						return 0;
					else {
						return 1;
					}
				}

				if (a > 1) {
					if (board[b - 2][a - 2] != class_type::empty || board[b - 1][a - 1] != class_type::peg)
						return 0;
					else {
						return 1;
					}
				}
			}
			else
				return 0;
		}

		else if (m == 'D' || m == 'd') {

			if (b < 3) {
				if (a < 7) {
					if (board[b + 2][a + 2] != class_type::empty || board[b + 1][a + 1] != class_type::peg)
						return 0;
					else {
						return 1;
					}
				}

				if (a > 1) {
					if (board[b + 2][a - 2] != class_type::empty || board[b + 1][a - 1] != class_type::peg)
						return 0;
					else {
						return 1;
					}
				}
			}
			else
				return 0;
		}
	}
	else if (boardmodel == 0) {

		if (m == 'L' || m == 'l') {

			if (a > 1) {
				if (board[b][a - 2] != class_type::empty || board[b][a - 1] != class_type::peg || board[b][a - 2] == class_type::wall)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}

		else if (m == 'R' || m == 'r') {

			if (a < board[0].size() - 2) {
				if (board[b][a + 2] != class_type::empty || board[b][a + 1] != class_type::peg || board[b][a + 2] == class_type::wall)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}

		else if (m == 'U' || m == 'u') {

			if (b >= 2) {
				if (board[b - 2][a] != class_type::empty || board[b - 1][a] != class_type::peg || board[b - 2][a] == class_type::wall)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}
		else if (m == 'D' || m == 'd') {

			if (b < board.size() - 2) {

				if (board[b + 2][a] != class_type::empty || board[b + 1][a] != class_type::peg || board[b + 2][a] == class_type::wall)
					return 0;
				else {
					return 1;
				}
			}
			else
				return 0;
		}
	}
	return 0;
}

//###########################################################################################################################################################################

int control_of_all_situations(vector<vector<class_type>>& board, int boardmodel) {

	int status = 0;
	if (boardmodel == 1 || boardmodel == 4) {			// This function checks all statuses and inquires whether the game can continue.

		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 7; j++) {

				if (board[i][j] == class_type::peg) {

					status = move_control2(i, j, 'L', board, boardmodel);
					if (status == 1)
						return 1;

					status = move_control2(i, j, 'R', board, boardmodel);
					if (status == 1)
						return 1;

					status = move_control2(i, j, 'D', board, boardmodel);
					if (status == 1)
						return 1;

					status = move_control2(i, j, 'U', board, boardmodel);
					if (status == 1)
						return 1;
				}
			}
		}
	}
	else if (boardmodel == 2 || boardmodel == 5) {

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {

				if (board[i][j] == class_type::peg) {

					status = move_control2(i, j, 'L', board, boardmodel);
					if (status == 1)
						return 1;

					status = move_control2(i, j, 'R', board, boardmodel);
					if (status == 1)
						return 1;

					status = move_control2(i, j, 'D', board, boardmodel);
					if (status == 1)
						return 1;

					status = move_control2(i, j, 'U', board, boardmodel);
					if (status == 1)
						return 1;
				}
			}
		}
	}
	else if (boardmodel == 3) {

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {

				if (board[i][j] == class_type::peg) {

					status = move_control2(i, j, 'L', board, boardmodel);
					if (status == 1)
						return 1;

					status = move_control2(i, j, 'R', board, boardmodel);
					if (status == 1)
						return 1;

					status = move_control2(i, j, 'D', board, boardmodel);
					if (status == 1)
						return 1;

					status = move_control2(i, j, 'U', board, boardmodel);
					if (status == 1)
						return 1;
				}
			}
		}
	}
	else if (boardmodel == 6) {

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {

				if (board[i][j] == class_type::peg) {

					status = move_control2(i, j, 'L', board, boardmodel);
					if (status == 1)
						return 1;

					status = move_control2(i, j, 'R', board, boardmodel);
					if (status == 1)
						return 1;

					status = move_control2(i, j, 'D', board, boardmodel);
					if (status == 1)
						return 1;

					status = move_control2(i, j, 'U', board, boardmodel);
					if (status == 1)
						return 1;
				}
			}
		}
	}
	else if (boardmodel == 0) {

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {

				if (board[i][j] == class_type::peg) {

					status = move_control2(i, j, 'L', board, boardmodel);
					if (status == 1)
						return 1;

					status = move_control2(i, j, 'R', board, boardmodel);
					if (status == 1)
						return 1;

					status = move_control2(i, j, 'D', board, boardmodel);
					if (status == 1)
						return 1;

					status = move_control2(i, j, 'U', board, boardmodel);
					if (status == 1)
						return 1;
				}
			}
		}
	}
	return 0;
}

//###########################################################################################################################################################################

int move_control(string move, vector<vector<class_type>>& board, int boardmodel) {

	int a = move[0] - 65; //letter					// The difference of this function from the other control function is that it activates the updater.
	int b = move[1] - 49; //number
	
	if (boardmodel == 1) {

		if (move[3] == 'L' || move[3] == 'l') {

			if (a > 1) {
				if (board[b][a - 2] != class_type::empty || board[b][a - 1] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'L', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}

		else if (move[3] == 'R' || move[3] == 'r') {

			if (a < 5) {
				if (board[b][a + 2] != class_type::empty || board[b][a + 1] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'R', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}

		else if (move[3] == 'U' || move[3] == 'u') {

			if (b >= 2) {
				if (board[b - 2][a] != class_type::empty || board[b - 1][a] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'U', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}

		else if (move[3] == 'D' || move[3] == 'd') {

			if (b < 5) {

				if (board[b + 2][a] != class_type::empty || board[b + 1][a] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'D', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}
	}

	else if (boardmodel == 2) {

		if (move[3] == 'L' || move[3] == 'l') {

			if (a > 1) {
				if (board[b][a - 2] != class_type::empty || board[b][a - 1] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'L', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}

		else if (move[3] == 'R' || move[3] == 'r') {

			if (a < 7) {
				if (board[b][a + 2] != class_type::empty || board[b][a + 1] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'R', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}

		else if (move[3] == 'U' || move[3] == 'u') {

			if (b >= 2) {
				if (board[b - 2][a] != class_type::empty || board[b - 1][a] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'U', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}

		else if (move[3] == 'D' || move[3] == 'd') {

			if (b < 7) {

				if (board[b + 2][a] != class_type::empty || board[b + 1][a] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'D', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}

	}

	else if (boardmodel == 3) {

		if (move[3] == 'L' || move[3] == 'l') {

			if (a > 1) {
				if (board[b][a - 2] != class_type::empty || board[b][a - 1] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'L', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}

		else if (move[3] == 'R' || move[3] == 'r') {

			if (a < 6) {
				if (board[b][a + 2] != class_type::empty || board[b][a + 1] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'R', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}

		else if (move[3] == 'U' || move[3] == 'u') {

			if (b >= 2) {
				if (board[b - 2][a] != class_type::empty || board[b - 1][a] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'U', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}

		else if (move[3] == 'D' || move[3] == 'd') {

			if (b < 6) {

				if (board[b + 2][a] != class_type::empty || board[b + 1][a] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'D', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}
	}

	else if (boardmodel == 4) {

		if (move[3] == 'L' || move[3] == 'l') {

			if (a > 1) {
				if (board[b][a - 2] != class_type::empty || board[b][a - 1] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'L', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}

		else if (move[3] == 'R' || move[3] == 'r') {

			if (a < 5) {
				if (board[b][a + 2] != class_type::empty || board[b][a + 1] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'R', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}

		else if (move[3] == 'U' || move[3] == 'u') {

			if (b >= 2) {
				if (board[b - 2][a] != class_type::empty || board[b - 1][a] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'U', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}

		else if (move[3] == 'D' || move[3] == 'd') {

			if (b < 5) {

				if (board[b + 2][a] != class_type::empty || board[b + 1][a] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'D', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}
	}

	else if (boardmodel == 5) {

		if (move[3] == 'L' || move[3] == 'l') {

			if (a > 1) {
				if (board[b][a - 2] != class_type::empty || board[b][a - 1] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'L', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}
		else if (move[3] == 'R' || move[3] == 'r') {

			if (a < 7) {
				if (board[b][a + 2] != class_type::empty || board[b][a + 1] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'R', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}

		else if (move[3] == 'U' || move[3] == 'u') {

			if (b >= 2) {
				if (board[b - 2][a] != class_type::empty || board[b - 1][a] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'U', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}

		else if (move[3] == 'D' || move[3] == 'd') {

			if (b < 7) {

				if (board[b + 2][a] != class_type::empty || board[b + 1][a] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'D', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}
	}

	else if (boardmodel == 6) {

		if (move[3] == 'L' || move[3] == 'l') {

			if (a > 3) {
				if (board[b][a - 4] != class_type::empty || board[b][a - 2] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'L', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}

		else if (move[3] == 'R' || move[3] == 'r') {

			if (a < 5) {
				if (board[b][a + 4] != class_type::empty || board[b][a + 2] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'R', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}

		else if (move[3] == 'U' || move[3] == 'u') {

			if (b >= 2) {
				if (a < 7) {
					if (board[b - 2][a + 2] != class_type::empty || board[b - 1][a + 1] != class_type::peg)
						return 0;
					else {
						board_updater(b, a, 'U', board, boardmodel);
						return 1;
					}
				}

				if (a > 1) {
					if (board[b - 2][a - 2] != class_type::empty || board[b - 1][a - 1] != class_type::peg)
						return 0;
					else {
						board_updater(b, a, 'U', board, boardmodel);
						return 1;
					}
				}
			}
			else
				return 0;
		}

		else if (move[3] == 'D' || move[3] == 'd') {

			if (b < 3) {
				if (a < 7) {
					if (board[b + 2][a + 2] != class_type::empty || board[b + 1][a + 1] != class_type::peg)
						return 0;
					else {
						board_updater(b, a, 'D', board, boardmodel);
						return 1;
					}
				}

				if (a > 1) {
					if (board[b + 2][a - 2] != class_type::empty || board[b + 1][a - 1] != class_type::peg)
						return 0;
					else {
						board_updater(b, a, 'U', board, boardmodel);
						return 1;
					}
				}
			}
			else
				return 0;
		}
	}
	else if (boardmodel == 0) {

		if (move[3] == 'L' || move[3] == 'l') {

			if (a > 1) {
				if (board[b][a - 2] != class_type::empty || board[b][a - 1] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'L', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}
		else if (move[3] == 'R' || move[3] == 'r') {

			if (a < board.size() - 2) {
				if (board[b][a + 2] != class_type::empty || board[b][a + 1] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'R', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}

		else if (move[3] == 'U' || move[3] == 'u') {

			if (b >= 2) {
				if (board[b - 2][a] != class_type::empty || board[b - 1][a] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'U', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}

		else if (move[3] == 'D' || move[3] == 'd') {

			if (b < board.size() - 2) {

				if (board[b + 2][a] != class_type::empty || board[b + 1][a] != class_type::peg)
					return 0;
				else {
					board_updater(b, a, 'D', board, boardmodel);
					return 1;
				}
			}
			else
				return 0;
		}
	}
	return 0;
}

//###########################################################################################################################################################################

int score_counter(vector<vector<class_type>>& board, int boardmodel=0) {  // function that uses default arguments

	int score = 0;		//After it is understood that there are no moves to be played, this function is called and the score is determined.

	if (boardmodel == 1 || boardmodel == 4) {

		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 7; j++) {
				if (board[i][j] == class_type::peg)
					score++;
			}
		}
	}
	else if (boardmodel == 2 || boardmodel == 5) {

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {

				if (board[i][j] == class_type::peg)
					score++;
			}
		}
	}
	else if (boardmodel == 3) {

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {

				if (board[i][j] == class_type::peg)
					score++;
			}
		}
	}
	else if (boardmodel == 6) {

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {

				if (board[i][j] == class_type::peg)
					score++;
			}
		}
	}
	else if (boardmodel == 0) {

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == class_type::peg)
					score++;
			}
		}
	}
	return score++;
}

//###########################################################################################################################################################################

string rand_move(int boardtype, vector<vector<class_type>>& v8) {

	int direction_type;
	char letter, number, direction;		// This function generates moves for computer selection
	string move = "     ";

	if (boardtype == 1 || boardtype == 4) {

		letter = rand() % 7 + 65;
		number = rand() % 7 + 49;			// ascii table values
		direction_type = rand() % 4 + 1;
		if (direction_type == 1)
			direction = 'L';
		else if (direction_type == 2)
			direction = 'R';
		else if (direction_type == 3)
			direction = 'U';
		else if (direction_type == 4)
			direction = 'D';

		move[0] = letter;
		move[1] = number;
		move[2] = '-';
		move[3] = direction;
		move[4] = '\0';

		return move;
	}
	else if (boardtype == 2 || boardtype == 5) {

		letter = rand() % 9 + 65;
		number = rand() % 9 + 49;
		direction_type = rand() % 4 + 1;
		if (direction_type == 1)
			direction = 'L';
		else if (direction_type == 2)
			direction = 'R';
		else if (direction_type == 3)
			direction = 'U';
		else if (direction_type == 4)
			direction = 'D';

		move[0] = letter;
		move[1] = number;
		move[2] = '-';
		move[3] = direction;
		move[4] = '\0';

		return move;
	}
	else if (boardtype == 3) {

		letter = rand() % 8 + 65;
		number = rand() % 8 + 49;
		direction_type = rand() % 4 + 1;
		if (direction_type == 1)
			direction = 'L';
		else if (direction_type == 2)
			direction = 'R';
		else if (direction_type == 3)
			direction = 'U';
		else if (direction_type == 4)
			direction = 'D';

		move[0] = letter;
		move[1] = number;
		move[2] = '-';
		move[3] = direction;
		move[4] = '\0';

		return move;
	}
	else if (boardtype == 6) {

		letter = rand() % 9 + 65;
		number = rand() % 5 + 49;
		direction_type = rand() % 4 + 1;
		if (direction_type == 1)
			direction = 'L';
		else if (direction_type == 2)
			direction = 'R';
		else if (direction_type == 3)
			direction = 'U';
		else if (direction_type == 4)
			direction = 'D';

		move[0] = letter;
		move[1] = number;
		move[2] = '-';
		move[3] = direction;
		move[4] = '\0';

		return move;
	}
	else if (boardtype == 0) {

		int size = v8.size();
		int size2 = v8[0].size();

		if (size < 9) {
			letter = rand() % size + 65;
			number = rand() % size2 + 49;
		}
		else {

			letter = rand() % size + 65;
			number = rand() % 8 + 49;
		}

		direction_type = rand() % 4 + 1;

		if (direction_type == 1)
			direction = 'L';
		else if (direction_type == 2)
			direction = 'R';
		else if (direction_type == 3)
			direction = 'U';
		else if (direction_type == 4)
			direction = 'D';

		move[0] = letter;
		move[1] = number;
		move[2] = '-';
		move[3] = direction;
		move[4] = '\0';

		return move;
	}
	return 0;
}
vector<vector<class_type>> instant_load(fstream& f, int& gametype, int& boardtype) {

	vector<vector<class_type>> v9;
	v9 = load_game(f, gametype, boardtype);
	return v9;
}
