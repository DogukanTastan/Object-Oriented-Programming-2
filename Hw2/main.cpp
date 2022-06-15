#include "hw2_lib.h"
//###########################################################################################################################################################################

int main() {

	srand(time(NULL));		// Required to generate random value

	int board_model, game_type;
	auto control = 0, control3 = 1;	//auto statement and one declrtype statement.
	decltype(control) control2 = 1, score = 0;

	string move, filename;

	vector<vector<class_type>>v1 = board1;     //I transferred my vector type variables to boards
	vector<vector<class_type>>v2 = board2;
	vector<vector<class_type>>v3 = board3;
	vector<vector<class_type>>v4 = board4;
	vector<vector<class_type>>v5 = board5;
	vector<vector<class_type>>v6 = board6;

	int gametype, boardtype;

	vector<vector<class_type>> v8;
	vector<vector<class_type>> v9;

	fstream save, load;
	save.open("save.txt", ios::out);
	cout << "Please select the board model(1-6) Enter 0 to load map : " << "\n";		// Required inputs are received
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
		v8 = v9;
	}

	if (board_model != 0) {
		cout << "Enter the game type(Human:1 Computer:2)\n";
		cin >> game_type;
		save << game_type << "\n";
	}

	if (game_type == 1) {

		if (board_model == 0)
			print_board(board_model, v8);
		else
			print_board(board_model);

		while (1) {

			if (control3 == 0)
				cout << "Invalid move try again!\n";

			cout << "Enter move(Example:B4-R)--(Save End exit:9)--(Load Game Enter:0)\n";				//Checking for faulty states
			cin >> move;
			if (move == "9") {
				if (board_model == 1)
					save_map(v1, save);
				else if (board_model == 2)
					save_map(v2, save);
				else if (board_model == 3)
					save_map(v3, save);
				else if (board_model == 4)
					save_map(v4, save);
				else if (board_model == 5)
					save_map(v5, save);
				else if (board_model == 6)
					save_map(v6, save);
				else if (board_model == 0)
					save_map(v8, save);
				return 0;
			}
			else if (move == "0") {
				load.close();
				cout << "Enter the file name for loading operations Example:(load1.txt)\n";
				cin >> filename;
				load.open(filename, ios::in);

				v9 = instant_load(load, gametype, boardtype);
				board_model = 0;
				game_type = gametype;
				v8 = v9;
				cout << "************************************************************\n";
				cout << "New Map Loading....\n";
				print_board(board_model, v8);
				continue;
			}

			if (move[2] != '-') {
				cout << "Invalid type!\n";
				continue;
			}

			if (board_model == 1) {
				control3 = move_control(move, v1, board_model);  // Firstly move is checked.
				control2 = control_of_all_situations(v1, board_model);  // game progress is checked
				if (control2 == 0) {
					score = score_counter(v1, board_model);  // The score is printd according to the control value
					break;
				}
			}
			else if (board_model == 2) {
				control3 = move_control(move, v2, board_model);
				control2 = control_of_all_situations(v2, board_model);
				if (control2 == 0) {
					score = score_counter(v2, board_model);
					break;
				}
			}
			else if (board_model == 3) {
				control3 = move_control(move, v3, board_model);
				control2 = control_of_all_situations(v3, board_model);
				if (control2 == 0) {
					score = score_counter(v3, board_model);
					break;
				}
			}
			else if (board_model == 4) {
				control3 = move_control(move, v4, board_model);
				control2 = control_of_all_situations(v4, board_model);
				if (control2 == 0) {
					score = score_counter(v4, board_model);
					break;
				}
			}
			else if (board_model == 5) {
				control3 = move_control(move, v5, board_model);
				control2 = control_of_all_situations(v5, board_model);
				if (control2 == 0) {
					score = score_counter(v5, board_model);
					break;
				}
			}
			else if (board_model == 6) {
				control3 = move_control(move, v6, board_model);
				control2 = control_of_all_situations(v6, board_model);
				if (control2 == 0) {
					score = score_counter(v6, board_model);
					break;
				}
			}
			else if (board_model == 0) {
				control3 = move_control(move, v8, 0);
				control2 = control_of_all_situations(v8, 0);
				if (control2 == 0) {
					score = score_counter(v8, 0);
					break;
				}
			}
		}
		cout << "GAME OVER SCORE:" << score << "\n";
		save<< score;
	}
	else if (game_type == 2) {

		if (board_model == 0)
			print_board(board_model, v8);
		else
			print_board(board_model);
		cout << "\n";

		int choice;

		while (1) {

			cout << ("Continuation of the Game:1 Save:9 Load:0\n");
			cin >> choice;
			if (choice == 9) {

				if (board_model == 1)
					save_map(v1, save);
				else if (board_model == 2)
					save_map(v2, save);
				else if (board_model == 3)
					save_map(v3, save);
				else if (board_model == 4)
					save_map(v4, save);
				else if (board_model == 5)
					save_map(v5, save);
				else if (board_model == 6)
					save_map(v6, save);
				else if (board_model == 0)
					save_map(v8, save);
				cout << "Save Succesfull";
				break;
			}
			else if (choice == 0) {
				load.close();
				cout << "Enter the file name for loading operations Example:(load1.txt)\n";
				cin >> filename;
				load.open(filename, ios::in);

				v9 = instant_load(load, gametype, boardtype);
				board_model = boardtype;
				game_type = gametype;
				v8 = v9;
				cout << "************************************************************\n";
				cout << "New Map Loading....\n";
				print_board(board_model, v8);
				continue;
			}
			else if (choice == 1) {
				string computer_move;
				if (board_model == 1) {
					control = 0;
					while (control == 0) {
						computer_move = rand_move(board_model, v1);
						control = move_control(computer_move, v1, board_model);
					}
					if (control == 1) {
						cout << "Computer move made:" << computer_move << "  new map is as above\n\n";
					}
					control2 = control_of_all_situations(v1, board_model);
					if (control2 == 0) {
						score = score_counter(v1, board_model);
						break;
					}
				}
				else if (board_model == 2) {
					control = 0;
					while (control == 0) {
						computer_move = rand_move(board_model, v2);
						control = move_control(computer_move, v2, board_model);
					}
					control2 = control_of_all_situations(v2, board_model);
					if (control == 1) {
						cout << "Computer move made:" << computer_move << "  new map is as above\n\n";
					}
					if (control2 == 0) {
						score = score_counter(v2, board_model);
						break;
					}
				}
				else if (board_model == 3) {
					control = 0;
					while (control == 0) {
						computer_move = rand_move(board_model, v3);
						control = move_control(computer_move, v3, board_model);
					}
					control2 = control_of_all_situations(v3, board_model);
					if (control == 1) {
						cout << "Computer move made:" << computer_move << "  new map is as above\n\n";
					}
					if (control2 == 0) {
						score = score_counter(v3, board_model);
						break;
					}
				}
				else if (board_model == 4) {
					control = 0;
					while (control == 0) {
						computer_move = rand_move(board_model, v4);
						control = move_control(computer_move, v4, board_model);
					}
					control2 = control_of_all_situations(v4, board_model);
					if (control == 1) {
						cout << "Computer move made:" << computer_move << "  new map is as above\n\n";
					}
					if (control2 == 0) {
						score = score_counter(v4, board_model);
						break;
					}
				}
				else if (board_model == 5) {
					control = 0;
					while (control == 0) {
						computer_move = rand_move(board_model, v5);
						control = move_control(computer_move, v5, board_model);
					}
					control2 = control_of_all_situations(v5, board_model);
					if (control == 1) {
						cout << "Computer move made:" << computer_move << "  new map is as above\n\n";
					}
					if (control2 == 0) {
						score = score_counter(v5, board_model);
						break;
					}
				}
				else if (board_model == 6) {
					control = 0;
					while (control == 0) {
						computer_move = rand_move(board_model, v6);
						control = move_control(computer_move, v6, board_model);
					}
					control2 = control_of_all_situations(v6, board_model);
					if (control == 1) {
						cout << "Computer move made:" << computer_move << "  new map is as above\n\n";
					}
					if (control2 == 0) {
						score = score_counter(v6, board_model);
						break;
					}
				}
				else if (board_model == 0) {
					control = 0;
					while (control == 0) {
						computer_move = rand_move(board_model, v8);
						control = move_control(computer_move, v8, board_model);
					}
					control2 = control_of_all_situations(v8, board_model);
					if (control == 1) {
						cout << "Computer move made:" << computer_move << "  new map is as above\n\n";
					}
					if (control2 == 0) {
						score = score_counter(v8, board_model);
						break;
					}
				}
			}
		}
		cout << "\nGAME OVER SCORE:" << score << "\n";
		save << score;
		save.close();
	}
	else
		cerr << "\nwrong choice ! Try Again\n";
}
