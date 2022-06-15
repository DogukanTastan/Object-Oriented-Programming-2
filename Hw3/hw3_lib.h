#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>   
#include <ctime>
#include <fstream>
using namespace std;

class cell;  //Definition of inner class
enum class cell_type { wall, empty, peg };

vector<vector<int>> board1 =
{
	{0,0,1,1,1,0,0,0,0,0,0},	//These parts are used when transforming the first 6 boards into cell type and are for information purposes. 
	{0,1,1,1,1,1,0,0,0,0,0},	// There is no other use. The game will be played over the cell type.
	{1,1,1,2,1,1,1,0,0,0,0},
	{1,1,1,1,1,1,1,0,0,0,0},
	{1,1,1,1,1,1,1,0,0,0,0},
	{0,1,1,1,1,1,0,0,0,0,0},
	{0,0,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},   //I completed it to 11 to be square
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
};

vector<vector<int>> board2 =
{
	{0,0,0,1,1,1,0,0,0,0,0},
	{0,0,0,1,1,1,0,0,0,0,0},
	{0,0,0,1,1,1,0,0,0,0,0},
	{1,1,1,1,1,1,1,1,1,0,0},
	{1,1,1,1,2,1,1,1,1,0,0},
	{1,1,1,1,1,1,1,1,1,0,0},
	{0,0,0,1,1,1,0,0,0,0,0},
	{0,0,0,1,1,1,0,0,0,0,0},
	{0,0,0,1,1,1,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
};

vector<vector<int>> board3 =
{
	{0,0,1,1,1,0,0,0,0,0,0},
	{0,0,1,1,1,0,0,0,0,0,0},
	{0,0,1,1,1,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1,0,0,0},
	{1,1,1,2,1,1,1,1,0,0,0},
	{1,1,1,1,1,1,1,1,0,0,0},
	{0,0,1,1,1,0,0,0,0,0,0},
	{0,0,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
};

vector<vector<int>> board4 =
{
	{0,0,1,1,1,0,0,0,0,0,0},
	{0,0,1,1,1,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,0,0,0,0},
	{1,1,1,2,1,1,1,0,0,0,0},
	{1,1,1,1,1,1,1,0,0,0,0},
	{0,0,1,1,1,0,0,0,0,0,0},
	{0,0,1,1,1,0,0,0,0,0,0},
	{0,0,0,1,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
};

vector<vector<int>> board5 =
{
	{0,0,0,0,1,0,0,0,0,0,0},
	{0,0,0,1,1,1,0,0,0,0,0},
	{0,0,1,1,1,1,1,0,0,0,0},
	{0,1,1,1,1,1,1,1,0,0,0},
	{1,1,1,1,2,1,1,1,1,0,0},
	{0,1,1,1,1,1,1,1,0,0,0},
	{0,0,1,1,1,1,1,0,0,0,0},
	{0,0,0,1,1,1,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
};

vector<vector<int>> board6 =
{
	{0,0,0,0,2,0,0,0,0,0,0},
	{0,0,0,1,0,1,0,0,0,0,0},
	{0,0,1,0,1,0,1,0,0,0,0},
	{0,1,0,1,0,1,0,1,0,0,0},
	{1,0,1,0,1,0,1,0,1,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
};

vector<vector<vector<int>>> boards = { board1,board2,board3,board4,board5,board6 };

class PegSolitaire {
	static int num;
public:
	int boardstyle,boardmodel;
	
	PegSolitaire(int boardtype) {		//constructor
		boardstyle = boardtype;
	}
	PegSolitaire();						//consructor

	class cell {
	public:
		int x, y, z;
		cell(int c, int d) {		// inner class consructor
			x = c;
			y = d;
		}
		void set(enum cell_type k) {			// inner class set function
			if (k == cell_type::wall)
				z = 0;
			else if (k == cell_type::peg)
				z = 1;
			else if (k == cell_type::empty)
				z = 2;
		}
	};
	vector<vector<PegSolitaire::cell>>map;

	vector<vector<PegSolitaire::cell>> map_maker(int boardtype, vector<vector<int>> loaded_board)  //This function creates cell objects
	{
		vector<PegSolitaire::cell> storemap;	
		vector<vector<PegSolitaire::cell>>storemap2;

		if (boardtype > 0) {

			for (int i = 0; i < 11; i++) {		//I completed the ready maps to 11 so that the maps are square
				for (int j = 0; j < 11; j++) {
					cell obj(i, j);
					if (boards[boardtype - 1][i][j] == 0)
						obj.set(cell_type::wall);
					else if (boards[boardtype - 1][i][j] == 1)
						obj.set(cell_type::peg);
					else if (boards[boardtype - 1][i][j] == 2)
						obj.set(cell_type::empty);

					storemap.push_back(obj);
					if (j == 10) {
						storemap2.push_back(storemap);
						storemap.clear();
					}
				}
			}
		}
		else if (boardtype == 0) {
			for (int i = 0; i < loaded_board.size(); i++) {		
				for (int j = 0; j < loaded_board.size(); j++) {
					cell obj(i, j);
					if (loaded_board[i][j] == 0)
						obj.set(cell_type::wall);
					else if (loaded_board[i][j] == 1)
						obj.set(cell_type::peg);
					else if (loaded_board[i][j] == 2)
						obj.set(cell_type::empty);

					storemap.push_back(obj);
					if (j == loaded_board.size() - 1) {
						storemap2.push_back(storemap);
						storemap.clear();
					}
				}
			}
		}
		map = storemap2;  //I'm storing the map in the class
		return storemap2;
	}
	void print_board(const int boardtype, vector<vector<vector<PegSolitaire::cell>>>& all_boards) { // print function

		if (boardtype != 0) {
			for (int i = 0; i < 11; i++) {
				for (int j = 0; j < 11; j++) {
					if (all_boards[boardtype][i][j].z == 0)
						cout << " ";
					else if (all_boards[boardtype][i][j].z == 1)
						cout << "P";
					else if (all_boards[boardtype][i][j].z == 2)
						cout << ".";
				}
				cout << "\n";
			}
		}
		else if (boardtype == 0) {
			for (int i = 0; i < all_boards[boardtype].size(); i++) {
				for (int j = 0; j < all_boards[boardtype].size(); j++) {
					if (all_boards[boardtype][i][j].z == 0)
						cout << " ";
					else if (all_boards[boardtype][i][j].z == 1)
						cout << "P";
					else if (all_boards[boardtype][i][j].z == 2)
						cout << ".";
				}
				cout << "\n";
			}
		}
	}

	void save_map(vector<vector<PegSolitaire::cell>>& board, fstream& f) { // save function
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {

				if (board[i][j].z == 0)
					f << 'w';
				else if (board[i][j].z == 1)
					f << 'p';
				else if (board[i][j].z == 2)
					f << 'e';
			}
			f << "\n";
		}
	}
	
	vector<vector<int>> load_game(fstream& f, int& gametype, int& boardtype) { // load function

		vector<vector<int>> board;
		int boardinfo, gameinfo;
		f >> boardinfo;
		f >> gameinfo;
		gametype = gameinfo;
		boardtype = boardinfo;
		string line;
		vector<int> lineV;

		while (f.peek() != EOF) {
			f >> line;
			for (int i = 0; i < line.length(); i++)
				if (line.at(i) == 'w')
					lineV.push_back(0);
				else if (line.at(i) == 'p')
					lineV.push_back(1);
				else if (line.at(i) == 'e')
					lineV.push_back(2);

			board.push_back(lineV);
			lineV.clear();
		}
		return board;
	}

	int move_control2(int b, int a, char m, vector<vector<vector<PegSolitaire::cell>>>& board, int boardmodel) {  //this function checks the validity of moves according to the rules

		if (boardmodel == 1) {						// This function returns 1 or 0 depending on the suitability of moves.

			if (m == 'L' || m == 'l') {

				if (a > 1) {
					if (board[boardmodel][b][a - 2].z != 2 || board[boardmodel][b][a - 1].z != 1 || board[boardmodel][b][a - 2].z == 0)
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
					if (board[boardmodel][b][a + 2].z != 2 || board[boardmodel][b][a + 1].z != 1 || board[boardmodel][b][a + 2].z == 0)
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
					if (board[boardmodel][b - 2][a].z != 2 || board[boardmodel][b - 1][a].z != 1 || board[boardmodel][b - 2][a].z == 0)
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

					if (board[boardmodel][b + 2][a].z != 2 || board[boardmodel][b + 1][a].z != 1 || board[boardmodel][b + 2][a].z == 0)
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
					if (board[boardmodel][b][a - 2].z != 2 || board[boardmodel][b][a - 1].z != 1 || board[boardmodel][b][a - 2].z == 0)
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
					if (board[boardmodel][b][a + 2].z != 2 || board[boardmodel][b][a + 1].z != 1 || board[boardmodel][b][a + 2].z == 0)
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
					if (board[boardmodel][b - 2][a].z != 2 || board[boardmodel][b - 1][a].z != 1 || board[boardmodel][b - 2][a].z == 0)
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

					if (board[boardmodel][b + 2][a].z != 2 || board[boardmodel][b + 1][a].z != 1 || board[boardmodel][b + 2][a].z == 0)
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
					if (board[boardmodel][b][a - 2].z != 2 || board[boardmodel][b][a - 1].z != 1 || board[boardmodel][b][a - 2].z == 0)
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
					if (board[boardmodel][b][a + 2].z != 2 || board[boardmodel][b][a + 1].z != 1 || board[boardmodel][b][a + 2].z == 0)
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
					if (board[boardmodel][b - 2][a].z != 2 || board[boardmodel][b - 1][a].z != 1 || board[boardmodel][b - 2][a].z == 0)
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

					if (board[boardmodel][b + 2][a].z != 2 || board[boardmodel][b + 1][a].z != 1 || board[boardmodel][b + 2][a].z == 0)
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
					if (board[boardmodel][b][a - 2].z != 2 || board[boardmodel][b][a - 1].z != 1 || board[boardmodel][b][a - 2].z == 0)
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
					if (board[boardmodel][b][a + 2].z != 2 || board[boardmodel][b][a + 1].z != 1 || board[boardmodel][b][a + 2].z == 0)
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
					if (board[boardmodel][b - 2][a].z != 2 || board[boardmodel][b - 1][a].z != 1 || board[boardmodel][b - 2][a].z == 0)
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

					if (board[boardmodel][b + 2][a].z != 2 || board[boardmodel][b + 1][a].z != 1 || board[boardmodel][b + 2][a].z == 0)
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
					if (board[boardmodel][b][a - 2].z != 2 || board[boardmodel][b][a - 1].z != 1 || board[boardmodel][b][a - 2].z == 0)
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
					if (board[boardmodel][b][a + 2].z != 2 || board[boardmodel][b][a + 1].z != 1 || board[boardmodel][b][a + 2].z == 0)
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
					if (board[boardmodel][b - 2][a].z != 2 || board[boardmodel][b - 1][a].z != 1 || board[boardmodel][b - 2][a].z == 0)
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

					if (board[boardmodel][b + 2][a].z != 2 || board[boardmodel][b + 1][a].z != 1 || board[boardmodel][b + 2][a].z == 0)
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
					if (board[boardmodel][b][a - 4].z != 2 || board[boardmodel][b][a - 2].z != 1)
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
					if (board[boardmodel][b][a + 4].z != 2 || board[boardmodel][b][a + 2].z != 1)
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
						if (board[boardmodel][b - 2][a + 2].z != 2 || board[boardmodel][b - 1][a + 1].z != 1)
							return 0;
						else {
							return 1;
						}
					}

					if (a > 1) {
						if (board[boardmodel][b - 2][a - 2].z != 2 || board[boardmodel][b - 1][a - 1].z != 1)
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
						if (board[boardmodel][b + 2][a + 2].z != 2 || board[boardmodel][b + 1][a + 1].z != 1)
							return 0;
						else {
							return 1;
						}
					}

					if (a > 1) {
						if (board[boardmodel][b + 2][a - 2].z != 2 || board[boardmodel][b + 1][a - 1].z != 1)
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
					if (board[boardmodel][b][a - 2].z != 2 || board[boardmodel][b][a - 1].z != 1 || board[boardmodel][b][a - 2].z == 0)
						return 0;
					else {
						return 1;
					}
				}
				else
					return 0;
			}

			else if (m == 'R' || m == 'r') {

				if (a < board[boardmodel][0].size() - 2) {
					if (board[boardmodel][b][a + 2].z != 2 || board[boardmodel][b][a + 1].z != 1 || board[boardmodel][b][a + 2].z == 0)
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
					if (board[boardmodel][b - 2][a].z != 2 || board[boardmodel][b - 1][a].z != 1 || board[boardmodel][b - 2][a].z == 0)
						return 0;
					else {
						return 1;
					}
				}
				else
					return 0;
			}
			else if (m == 'D' || m == 'd') {

				if (b < board[boardmodel].size() - 2) {

					if (board[boardmodel][b + 2][a].z != 2 || board[boardmodel][b + 1][a].z != 1 || board[boardmodel][b + 2][a].z == 0)
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

	int is_the_game_over(vector<vector<vector<PegSolitaire::cell>>>& board, int boardmodel) {  //checks if the game is over

		int status = 0;
		for (int i = 0; i < board[boardmodel].size(); i++) {
			for (int j = 0; j < board[boardmodel].size(); j++) {

				if (board[boardmodel][i][j].z == 1) {

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
		return 0;
	}
	int counter(vector<vector<PegSolitaire::cell>>& board) {  // peg counter

		int counter = 0;

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board.size(); j++) {
				if (board[i][j].z == 0)
					counter++;
			}
		}
		return counter;
	}

	bool who_has_a_lot_of_peg(PegSolitaire obj,PegSolitaire obj2) {  // peg compare function

		int result, result2;				//The class will have a function that takes another object PegSolitaire as parameter and
		result = counter(obj.map);      // compares the Peg Solitaire games.It returns true is the first game has more pegs, otherwise it returns false.
		result2 = counter(obj2.map);

		if (result2 > result)
			return true;
		else
			return false;
	}
	
	int* numberof_peg_cell_empty(PegSolitaire obj) { //The class will have functions to return the number of pegs, number of empty cells, and number of pegs taken out from the board

		int* result;

		int counter0, counter1, counter2;

		for (int i = 0; i < obj.map.size(); i++) {
			for (int j = 0; j < obj.map.size(); j++) {
				if (obj.map[i][j].z == 0)
					counter0++;
				else if (obj.map[i][j].z == 1)
					counter1++;
				else if (obj.map[i][j].z == 2)
					counter2++;
			}
		}
		result[0] = counter0;
		result[1] = counter1;
		result[2] = counter2;
		
		return result;
	}


	void board_updater(int b, int a, char directory, vector<vector<vector<PegSolitaire::cell>>>& board, int boardmodel) { // update function

		if (board[boardmodel][b][a].z == 1)
			board[boardmodel][b][a].z = 2;							// This function applies the approved move to the board.

		if (boardmodel == 6) {							// Since there are special moves on board6, I evaluated them separately.

			if (directory == 'L') {

				board[boardmodel][b][a - 2].z = 2;
				board[boardmodel][b][a - 4].z = 1;

			}
			else if (directory == 'R') {

				board[boardmodel][b][a + 2].z = 2;
				board[boardmodel][b][a + 4].z = 1;

			}
			else if (directory == 'U') {

				if (b > 1)
				{
					if (board[boardmodel][b - 1][a + 1].z != 0 && board[boardmodel][b - 2][a + 2].z != 0) {

						board[boardmodel][b - 1][a + 1].z = 2;
						board[boardmodel][b - 2][a + 2].z = 1;
					}
					else if (board[boardmodel][b - 1][a - 1].z != 0 && board[boardmodel][b - 2][a - 2].z != 0) {

						board[boardmodel][b - 1][a - 1].z = 2;
						board[boardmodel][b - 2][a - 2].z = 1;
					}
				}

			}
			else if (directory == 'D') {

				if (board[boardmodel][b + 1][a + 1].z != 0 && board[boardmodel][b + 2][a + 2].z != 0) {

					board[boardmodel][b + 1][a + 1].z = 2;
					board[boardmodel][b + 2][a + 2].z = 1;
				}
				else if (board[boardmodel][b + 1][a - 1].z != 0 && board[boardmodel][b + 2][a - 2].z != 0) {

					board[boardmodel][b + 1][a - 1].z = 2;
					board[boardmodel][b + 2][a - 2].z = 1;
				}

			}
			print_board(boardmodel, board);    // Printing is started after the board[boardmodel] changes accordingly
		}
		else {

			if (directory == 'L') {

				if (board[boardmodel][b][a - 1].z != 0 && board[boardmodel][b][a - 2].z != 0) {

					board[boardmodel][b][a - 1].z = 2;
					board[boardmodel][b][a - 2].z = 1;
				}
			}
			else if (directory == 'R') {

				if (board[boardmodel][b][a + 1].z != 0 && board[boardmodel][b][a + 2].z != 0) {

					board[boardmodel][b][a + 1].z = 2;
					board[boardmodel][b][a + 2].z = 1;
				}
			}
			else if (directory == 'U') {

				if (board[boardmodel][b - 1][a].z != 0 && board[boardmodel][b - 2][a].z != 0) {

					board[boardmodel][b - 1][a].z = 2;
					board[boardmodel][b - 2][a].z = 1;
				}
			}
			else if (directory == 'D') {

				if (board[boardmodel][b + 1][a].z != 0 && board[boardmodel][b + 2][a].z != 0) {

					board[boardmodel][b + 1][a].z = 2;
					board[boardmodel][b + 2][a].z = 1;
				}
			}
			print_board(boardmodel, board);    // Printing is started after the board changes accordingly
		}
	}


	int move_control(string move, vector<vector<vector<PegSolitaire::cell>>>& board, int boardmodel) {

		int a = move[0] - 65; //letter					// The difference of this function from the other control function is that it activates the updater.
		int b = move[1] - 49; //number

		if (boardmodel == 1) {

			if (move[3] == 'L' || move[3] == 'l') {

				if (a > 1) {
					if (board[boardmodel][b][a - 2].z != 2 || board[boardmodel][b][a - 1].z != 1)
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
					if (board[boardmodel][b][a + 2].z != 2 || board[boardmodel][b][a + 1].z != 1)
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
					if (board[boardmodel][b - 2][a].z != 2 || board[boardmodel][b - 1][a].z != 1)
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

					if (board[boardmodel][b + 2][a].z != 2 || board[boardmodel][b + 1][a].z != 1)
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
					if (board[boardmodel][b][a - 2].z != 2 || board[boardmodel][b][a - 1].z != 1)
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
					if (board[boardmodel][b][a + 2].z != 2 || board[boardmodel][b][a + 1].z != 1)
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
					if (board[boardmodel][b - 2][a].z != 2 || board[boardmodel][b - 1][a].z != 1)
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

					if (board[boardmodel][b + 2][a].z != 2 || board[boardmodel][b + 1][a].z != 1)
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
					if (board[boardmodel][b][a - 2].z != 2 || board[boardmodel][b][a - 1].z != 1)
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
					if (board[boardmodel][b][a + 2].z != 2 || board[boardmodel][b][a + 1].z != 1)
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
					if (board[boardmodel][b - 2][a].z != 2 || board[boardmodel][b - 1][a].z != 1)
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

					if (board[boardmodel][b + 2][a].z != 2 || board[boardmodel][b + 1][a].z != 1)
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
					if (board[boardmodel][b][a - 2].z != 2 || board[boardmodel][b][a - 1].z != 1)
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
					if (board[boardmodel][b][a + 2].z != 2 || board[boardmodel][b][a + 1].z != 1)
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
					if (board[boardmodel][b - 2][a].z != 2 || board[boardmodel][b - 1][a].z != 1)
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

					if (board[boardmodel][b + 2][a].z != 2 || board[boardmodel][b + 1][a].z != 1)
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
					if (board[boardmodel][b][a - 2].z != 2 || board[boardmodel][b][a - 1].z != 1)
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
					if (board[boardmodel][b][a + 2].z != 2 || board[boardmodel][b][a + 1].z != 1)
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
					if (board[boardmodel][b - 2][a].z != 2 || board[boardmodel][b - 1][a].z != 1)
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

					if (board[boardmodel][b + 2][a].z != 2 || board[boardmodel][b + 1][a].z != 1)
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
					if (board[boardmodel][b][a - 4].z != 2 || board[boardmodel][b][a - 2].z != 1)
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
					if (board[boardmodel][b][a + 4].z != 2 || board[boardmodel][b][a + 2].z != 1)
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
						if (board[boardmodel][b - 2][a + 2].z != 2 || board[boardmodel][b - 1][a + 1].z != 1)
							return 0;
						else {
							board_updater(b, a, 'U', board, boardmodel);
							return 1;
						}
					}

					if (a > 1) {
						if (board[boardmodel][b - 2][a - 2].z != 2 || board[boardmodel][b - 1][a - 1].z != 1)
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
						if (board[boardmodel][b + 2][a + 2].z != 2 || board[boardmodel][b + 1][a + 1].z != 1)
							return 0;
						else {
							board_updater(b, a, 'D', board, boardmodel);
							return 1;
						}
					}

					if (a > 1) {
						if (board[boardmodel][b + 2][a - 2].z != 2 || board[boardmodel][b + 1][a - 1].z != 1)
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
					if (board[boardmodel][b][a - 2].z != 2 || board[boardmodel][b][a - 1].z != 1)
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

				if (a < board[0].size() - 2) {
					if (board[0][b][a + 2].z != 2 || board[boardmodel][b][a + 1].z != 1)
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
					if (board[boardmodel][b - 2][a].z != 2 || board[boardmodel][b - 1][a].z != 1)
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

				if (b < board[boardmodel].size() - 2) {

					if (board[boardmodel][b + 2][a].z != 2 || board[boardmodel][b + 1][a].z != 1)
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

	string rand_move(int boardtype, vector<vector<vector<PegSolitaire::cell>>> board) {   //generates random moves

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

			int size = board[0].size();

			if (size < 9) {
				letter = rand() % size + 65;
				number = rand() % size + 49;
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

	vector<vector<int>> instant_load(fstream& f, int& gametype, int& boardtype) {  //this function mediates read operations from file

		vector<vector<int>> v9;
		v9 = load_game(f, gametype, boardtype);
		return v9;
	}

	int score_counter(vector<vector<vector<PegSolitaire::cell>>>& board, int boardmodel) {

		int score = 0;		//After it is understood that there are no moves to be played, this function is called and the score is determined.

		for (int i = 0; i < board[boardmodel].size(); i++) {
			for (int j = 0; j < board[boardmodel][0].size(); j++) {
				if (board[boardmodel][i][j].z == 1)
					score++;
			}
		}
		return score++;
	}


	vector<vector<vector<PegSolitaire::cell>>> my_push_first_function(vector<vector<PegSolitaire::cell>>& board0, vector<vector<PegSolitaire::cell>>& board1, vector<vector<PegSolitaire::cell>>& board2,
		vector<vector<PegSolitaire::cell>>& board3, vector<vector<PegSolitaire::cell>>& board4, vector<vector<PegSolitaire::cell>>& board5, vector<vector<PegSolitaire::cell>>& board6) {

		vector<vector<vector<PegSolitaire::cell>>> new_boards = { board0,board1,board2,board3,board4,board5,board6 };  //To prepend board0 after updating

		return new_boards;
	}
	
	void playGame(int board_model,int gametype,string filename,fstream& save, fstream& load,vector<vector<vector<PegSolitaire::cell>>>& all_boards, vector<vector<PegSolitaire::cell>> board0, vector<vector<int>> v9) {

		auto control = 0, control3 = 1;								// this function plays to computer
		decltype(control) control2 = 1, score = 0;
		
		
		print_board(board_model, all_boards);

		cout << "\n";

		int choice;

		while (1) {

			cout << ("Continuation of the Game:1 Save:9 Load:0\n");
			cin >> choice;
			if (choice == 9) {
				save_map(all_boards[board_model], save);
				cout << "Save Succesfull";
				break;
			}
			else if (choice == 0) {
				load.close();
				cout << "Enter the file name for loading operations Example:(load1.txt)\n";
				cin >> filename;
				load.open(filename, ios::in);

				v9 = instant_load(load, gametype, board_model);
				board_model = board_model;
				gametype = gametype;
				board0.clear();
				board0 = map_maker(0, v9);
				cout << "************************************************************\n";
				cout << "New Map Loading....\n";
				print_board(0, all_boards);
				continue;
			}
			else if (choice == 1) {
				string computer_move;
				control = 0;
				while (control == 0) {
					computer_move = rand_move(board_model, all_boards);
					control = move_control(computer_move, all_boards, board_model);
				}
				if (control == 1) {
					cout << "Computer move made:" << computer_move << "  new map is as above\n\n";
				}
				control2 = is_the_game_over(all_boards, board_model);
				if (control2 == 0) {
					score = score_counter(all_boards, board_model);
					break;
				}
			}
		}
		cout << "\nGAME OVER SCORE:" << score << "\n";
		save << score;
		save.close();
	}

	int my_main() {			//section where general information is obtained and managed

		vector<vector<int>> temp;
		vector<vector<PegSolitaire::cell>> board0, board01, board02, board03, board04, board05, board06;
		vector<vector<vector<PegSolitaire::cell>>> all_boards = { board0,board01,board02,board03,board04,board05,board06 };

		for (int i = 1; i < 7; i++) {
			all_boards[i] = map_maker(i, temp);
			temp.clear();
		}

		srand(time(NULL));		// Required to generate random value

		int board_model, game_type;
		auto control = 0, control3 = 1;
		decltype(control) control2 = 1, score = 0;

		string move, filename;
		int gametype, boardtype;

		vector<vector<int>> v9;

		fstream save, load;
		save.open("save.txt", ios::out);
		
		cout << "\nMENU\nPlease select the board model(1-6)" << "\n"<< "Enter 0 to load map  " << "\n";		// Required inputs are received
		cin >> board_model;
		save << board_model << "\n";

		if (board_model < 0 || board_model>6) {
			cerr << "\nwrong choice ! Try Again\n";
			return 0;
		}

		if (board_model == 0) {
			cout << "Enter the file name for loading operations Example:(load1.txt)\n";
			cin >> filename;
			load.open(filename, ios::in);

			v9 = instant_load(load, gametype, boardtype);
			board_model = 0;
			game_type = gametype;
			board0 = map_maker(0, v9);  // board7 is laoded board 
			all_boards.clear();
			all_boards = my_push_first_function(board0, board01, board02, board03, board04, board05, board06);
		}

		if (board_model != 0) {
			cout << "Enter the game type(Human:1 Computer:2)\n";
			cin >> game_type;
			save << game_type << "\n";
		}

		if (game_type == 1) {

			print_board(board_model, all_boards);
			cout << "\n";
			int ch;
			while (1) {

				if (control3 == 0)
					cout << "Invalid move try again!\n";

				cout << "Enter 1 for move input\nEnter 9 for Save End exit\nEnter 0 Load Game\nEnter 5 to continue with another object\n\n";				//Checking for faulty states 
				cin >> ch;

				if (ch == 5)
					return 0;

				if (ch == 9) {
					save_map(all_boards[board_model], save);
					break;
				}
				else if (ch == 0) {
					load.close();
					cout << "Enter the file name for loading operations Example:(load1.txt)\n";
					cin >> filename;
					load.open(filename, ios::in);

					v9 = instant_load(load, gametype, boardtype);
					board_model = boardtype;
					game_type = gametype;
					board0.clear();
					board0 = map_maker(0, v9);
					cout << "************************************************************\n";
					cout << "New Map Loading....\n";
					all_boards = my_push_first_function(board0, board01, board02, board03, board04, board05, board06);
					print_board(0, all_boards);
					continue;
				}
				else if (ch == 1) {
					string move;
					cout << "Enter move (Example Type: B4-R)\n";
					cin >> move;
					if (move[2] != '-') {
						cout << "Invalid type!\n";
						continue;
					}
					control3 = move_control(move, all_boards, board_model);  // Firstly move is checked.
					if (control3 == 0)
						continue;
					control2 = is_the_game_over(all_boards, board_model);  // game progress is checked
					if (control2 == 0) {
						score = score_counter(all_boards, board_model);  // The score is printd according to the control value
						break;
					}
				}
			}
			cout << "GAME OVER SCORE:" << score << "\n";
		}
		else if (game_type == 2) {

			playGame(board_model, game_type, filename, save, load, all_boards, board0, v9);
		}
		else
			cerr << "\nwrong choice ! Try Again\n";
		return 0;
	}
	
};
// Dogukan Tastan 1901042627
