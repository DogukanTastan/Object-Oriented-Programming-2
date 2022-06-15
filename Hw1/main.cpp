#include "hw1_lib.h"
//###########################################################################################################################################################################

int main() {

	srand(time(NULL));		// Required to generate random value

	int board_model, game_type, control = 1;
	int control2 = 1, score;
	string move;

	cout << "Please select the board model(1-6): " << "\n";		// Required inputs are received
	cin >> board_model;

	cout << "Enter the game type(Human:1 Computer:2)\n";
	cin >> game_type;
	vector<vector<class_type>>v1 = board1;     //I transferred my vector type variables to boards
	vector<vector<class_type>>v2 = board2;
	vector<vector<class_type>>v3 = board3;
	vector<vector<class_type>>v4 = board4;
	vector<vector<class_type>>v5 = board5;
	vector<vector<class_type>>v6 = board6;

	if (game_type == 1) {

		print_board(board_model);

		while (1) {
			if (control == 0)
				cout << "Invalid move try again!\n";

			cout << "Enter move(Example:B4-R)\n";				//Checking for faulty states
			cin >> move;
			
			if (move[2] != '-') {
				cout << "Invalid type!\n";
				continue;
			}
				
			if (board_model == 1) {
				control = move_control(move, v1, board_model);  // Firstly move is checked.
				control2 = control_of_all_situations(v1, board_model);  // game progress is checked
				if (control2 == 0) {
					score = score_counter(v1, board_model);  // The score is printed according to the control value
					break;
				}
			}
			else if (board_model == 2) {
				control = move_control(move, v2, board_model);
				control2 = control_of_all_situations(v2, board_model);
				if (control2 == 0) {
					score = score_counter(v2, board_model);
					break;
				}
			}
			else if (board_model == 3) {
				control = move_control(move, v3, board_model);
				control2 = control_of_all_situations(v3, board_model);
				if (control2 == 0) {
					score = score_counter(v3, board_model);
					break;
				}
			}
			else if (board_model == 4) {
				control = move_control(move, v4, board_model);
				control2 = control_of_all_situations(v4, board_model);
				if (control2 == 0) {
					score = score_counter(v4, board_model);
					break;
				}
			}
			else if (board_model == 5) {
				control = move_control(move, v5, board_model);
				control2 = control_of_all_situations(v5, board_model);
				if (control2 == 0) {
					score = score_counter(v5, board_model);
					break;
				}
			}
			else if (board_model == 6) {
				control = move_control(move, v6, board_model);
				control2 = control_of_all_situations(v6, board_model);
				if (control2 == 0) {
					score = score_counter(v6, board_model);
					break;
				}
			}
		}
		cout << "GAME OVER SCORE:" << score << "\n";
	}
	else if (game_type == 2) {	//Artificial intelligence game model :), this model also plays the computer itself

		print_board(board_model);	// The steps here are similar to the first model, in addition, moves are created
		cout << "\n";
		while (1) {

			if (board_model == 1) {
				string computer_move = rand_move(board_model);
				control = move_control(computer_move, v1, board_model);
				if (control == 1)
					cout << "Computer move made:" << computer_move << "  new map is as above\n\n";
				control2 = control_of_all_situations(v1, board_model);
				if (control2 == 0) {
					score = score_counter(v1, board_model);
					break;
				}
			}
			else if (board_model == 2) {
				string computer_move = rand_move(board_model);
				control = move_control(computer_move, v2, board_model);
				control2 = control_of_all_situations(v2, board_model);
				if (control == 1)
					cout << "Computer move made:" << computer_move << "  new map is as above\n\n";
				if (control2 == 0) {
					score = score_counter(v2, board_model);
					break;
				}
			}
			else if (board_model == 3) {
				string computer_move = rand_move(board_model);
				control = move_control(computer_move, v3, board_model);
				control2 = control_of_all_situations(v3, board_model);
				if (control == 1)
					cout << "Computer move made:" << computer_move << "  new map is as above\n\n";
				if (control2 == 0) {
					score = score_counter(v3, board_model);
					break;
				}
			}
			else if (board_model == 4) {
				string computer_move = rand_move(board_model);
				control = move_control(computer_move, v4, board_model);
				control2 = control_of_all_situations(v4, board_model);
				if (control == 1)
					cout << "Computer move made:" << computer_move << "  new map is as above\n\n";
				if (control2 == 0) {
					score = score_counter(v4, board_model);
					break;
				}
			}
			else if (board_model == 5) {
				string computer_move = rand_move(board_model);
				control = move_control(computer_move, v5, board_model);
				control2 = control_of_all_situations(v5, board_model);
				if (control == 1)
					cout << "Computer move made:" << computer_move << "  new map is as above\n\n";
				if (control2 == 0) {
					score = score_counter(v5, board_model);
					break;
				}
			}
			else if (board_model == 6) {
				string computer_move = rand_move(board_model);
				control = move_control(computer_move, v6, board_model);
				control2 = control_of_all_situations(v6, board_model);
				if (control == 1)
					cout << "Computer move made:" << computer_move << "  new map is as above\n\n";
				if (control2 == 0) {
					score = score_counter(v6, board_model);
					break;
				}
			}
		}
		cout << "\nGAME OVER SCORE:" << score << "\n";
	}
	else
		cout << "\nwrong choice ! Try Again\n";
}
