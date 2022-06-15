#include<iostream>
#include<vector>
#include <string> 
#include <cstdlib>   
#include <fstream>
#include <ctime>    // rand librar
#include <chrono>  // sleep library
#include <thread>
#define N 3           
using namespace std;

namespace games{

    enum {
        UP, DOWN, RIGHT, LEFT    /* I have defined an enum that indicates the directions of motion for EightPuzzle */
    };

    enum class class_type { wall, empty, peg };

    vector<vector<class_type>> board2 =
    {
        {class_type::wall,class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall},
        {class_type::wall,class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall},
        {class_type::wall,class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall},
        {class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg},
        {class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::empty,class_type::peg,class_type::peg,class_type::peg,class_type::peg},
        {class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg,class_type::peg},
        {class_type::wall,class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall},
        {class_type::wall,class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall},
        {class_type::wall,class_type::wall,class_type::wall,class_type::peg,class_type::peg,class_type::peg,class_type::wall,class_type::wall,class_type::wall},
    };

    vector<vector<string>> klotski_Map =
    {
        {"X","X","X","X","X","X","X","X"},
        {"X","X","X","X","X","X","X","X"},
        {"X","X","B","A","A","C","X","X"},
        {"X","X","B","A","A","C","X","X"},
        {"X","X","D","E","E","H","X","X"},
        {"X","X","D","F","G","H","X","X"},
        {"X","X","K"," "," ","I","X","X"},
        {"X","X","X","X","X","X","X","X"}, 
        {"X","X","X","X","X","X","X","X"},
    };


    class BoardGame2D {
    public:
       
        static int playVector(const vector<BoardGame2D*> objects) {

            for (int i = 0; i < objects.size(); i++)
                objects[i]->playAutoAll();
            return 0;
        }
       
        virtual bool endGame() = 0;
        virtual void initialize() = 0;
        virtual void print() = 0;
        virtual int boardScore() = 0;
        virtual int playAuto()=0;
        virtual void playUser(string parameter) = 0;
        virtual void playUser() final;
        virtual int playAutoAll() final;     

    };

     void BoardGame2D::playUser() {
         bool check = 0;
         string move;

         print();
         while (check == 0) {
             cout << "Enter move suitable type: PegSolitaire:(A3-R),EightPuzzle: (010 x-y-direction= Up=0, Down=1, Right=2, Left=3), Klotski(AD D for Down)\n";
             cin >> move;
             playUser(move);
             check = endGame();
         }
    }

     int BoardGame2D::playAutoAll() {

         int x = 0, y = 0, command = 0;
         string parameter;

         print();   /* And printing the map */
         cout << "\n";

         while (true) {

             int check = endGame();
             if (check == 1)        /*We check the unwinding status of the puzzle. If it is solved, the value coming will be 1 and the loop will break */
                 break;

             playAuto();
         }
         cout << "Congratulations! Solved the puzzle \n";  /* If the loop is exited, the puzzle is solved, congratulations message is printed. */
         return 0;
     }





    class PegSolitaire : public BoardGame2D {
    public:
        vector<vector<class_type>>v2 = board2;

        void initialize();
        void playUser(string move);
        void board_updater(int b, int a, char directory);
        int move_control(string move);
        int move_control2(int b, int a, char m);
        string rand_move();
        int playAuto();
        void print();
        int boardScore();
        bool endGame();
    };

    void PegSolitaire::initialize() {
       
        vector<vector<class_type>>v2 = board2;
    }

    void PegSolitaire::playUser(string move) {
        
        int control = 0;
        int control2 = 1;

        print();

        control2 = endGame();

        if (control2 == 0) {
            boardScore();
        }

        control = move_control(move);
    }

    void PegSolitaire::board_updater(int b, int a, char directory) {

        if (v2[b][a] == class_type::peg)
            v2[b][a] = class_type::empty;                           // This function applies the approved move to the board.

        if (directory == 'L') {

            if (v2[b][a - 1] != class_type::wall && v2[b][a - 2] != class_type::wall) {

                v2[b][a - 1] = class_type::empty;
                v2[b][a - 2] = class_type::peg;
            }
        }
        else if (directory == 'R') {

            if (v2[b][a + 1] != class_type::wall && v2[b][a + 2] != class_type::wall) {

                v2[b][a + 1] = class_type::empty;
                v2[b][a + 2] = class_type::peg;
            }
        }
        else if (directory == 'U') {

            if (v2[b - 1][a] != class_type::wall && v2[b - 2][a] != class_type::wall) {

                v2[b - 1][a] = class_type::empty;
                v2[b - 2][a] = class_type::peg;
            }
        }
        else if (directory == 'D') {

            if (v2[b + 1][a] != class_type::wall && v2[b + 2][a] != class_type::wall) {

                v2[b + 1][a] = class_type::empty;
                v2[b + 2][a] = class_type::peg;
            }
        }
        print();    // Printing is started after the board changes accordingly
    }

    int PegSolitaire::move_control(string move) {
        int a = move[0] - 65; //letter                  // The difference of this function from the other control function is that it activates the updater.
        int b = move[1] - 49; //number

        if (v2[b][a] != class_type::peg)
            return 0;

        if (move[3] == 'L' || move[3] == 'l') {

            if (a > 1) {
                if (v2[b][a - 2] != class_type::empty || v2[b][a - 1] != class_type::peg)
                    return 0;
                else {
                    board_updater(b, a, 'L');
                    return 1;
                }
            }
            else
                return 0;
        }

        else if (move[3] == 'R' || move[3] == 'r') {

            if (a < 7) {
                if (v2[b][a + 2] != class_type::empty || v2[b][a + 1] != class_type::peg)
                    return 0;
                else {
                    board_updater(b, a, 'R');
                    return 1;
                }
            }
            else
                return 0;
        }

        else if (move[3] == 'U' || move[3] == 'u') {

            if (b >= 2) {
                if (v2[b - 2][a] != class_type::empty || v2[b - 1][a] != class_type::peg)
                    return 0;
                else {
                    board_updater(b, a, 'U');
                    return 1;
                }
            }
            else
                return 0;
        }

        else if (move[3] == 'D' || move[3] == 'd') {

            if (b < 7) {

                if (v2[b + 2][a] != class_type::empty || v2[b + 1][a] != class_type::peg)
                    return 0;
                else {
                    board_updater(b, a, 'D');
                    return 1;
                }
            }
            else
                return 0;
        }
        return 0;
    }

    int PegSolitaire::move_control2(int b, int a, char m) {
        if (v2[b][a] != class_type::peg)
            return 0;

        if (m == 'L' || m == 'l') {

            if (a > 1) {
                if (v2[b][a - 2] != class_type::empty || v2[b][a - 1] != class_type::peg || v2[b][a - 2] == class_type::wall)
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
                if (v2[b][a + 2] != class_type::empty || v2[b][a + 1] != class_type::peg || v2[b][a + 2] == class_type::wall)
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
                if (v2[b - 2][a] != class_type::empty || v2[b - 1][a] != class_type::peg || v2[b - 2][a] == class_type::wall)
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

                if (v2[b + 2][a] != class_type::empty || v2[b + 1][a] != class_type::peg || v2[b + 2][a] == class_type::wall)
                    return 0;
                else {
                    return 1;
                }
            }
            else
                return 0;
        }
        return 0;
    }

    string PegSolitaire::rand_move() {
       
        int direction_type;
        char letter, number, direction;     // This function generates moves for computer selection
        string move = "     ";
        int test;

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

    int PegSolitaire::playAuto() {
        int test = 0, a, b, control = 0;
        int control2 = 1;
        char m;
        string move = rand_move();
        a = move[0] - 65;
        b = move[1] - 49;
        m = move[3];
        test = move_control2(a, b, m);

        while (test == 0) {
            string move = rand_move();
            a = move[0] - 65;
            b = move[1] - 49;
            m = move[3];
            test = move_control2(a, b, m);    // continues until the right move comes
        }

        control2 = endGame();

        if (control2 == 1) {
            boardScore();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));   // waiting 1000 ms
        }

        control = move_control(move);

        return 0;
    }

    void PegSolitaire::print() {
        cout << "\n";
        cout << "\x1b[2J";
        cout << "\033[0;0H"; // move cursor  0
        cout << endl << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(400));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (v2[i][j] == class_type::wall) {
                    cout << " ";
                }

                else if (v2[i][j] == class_type::peg) {
                    cout << "P";
                }

                else if (v2[i][j] == class_type::empty) {
                    cout << ".";
                }
            }
            cout << "\n";
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }

    int PegSolitaire::boardScore() {     // The boardScore function returns the number of epgs left.
        int score = 1;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (v2[i][j] == class_type::peg)
                    score++;
            }
        }

        cout << "GAME OVER SCORE: " << score << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        return 0;
    }

    bool PegSolitaire::endGame() {
        int status = 0;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 8; j++) {

                if (v2[i][j] == class_type::peg) {

                    status = move_control2(i, j, 'L');
                    if (status == 1)
                        return false;

                    status = move_control2(i, j, 'R');
                    if (status == 1)
                        return false;

                    status = move_control2(i, j, 'D');
                    if (status == 1)
                        return false;

                    status = move_control2(i, j, 'U');
                    if (status == 1)
                        return false;
                }
            }
        }
        boardScore();
        return true;
    }

    //***************************************************************************************************

    class EightPuzzle : public BoardGame2D {
    public:
        int map[3][3];
        int boardscore=0;
        string test = "   ";
        
       EightPuzzle();
       string random();
       int playAuto();
       void move(int x, int y, int move);
       int moveCheck(int x, int y, int move);
       void initialize();
       void print();
       void playUser(string parameter);
       bool endGame();
       int boardScore();
    };

    EightPuzzle::EightPuzzle() {
        initialize();
    }

    string EightPuzzle::random() {

        int x, y, command, check = 0;
        string parameter = "    ";

        while (check == 0) {

            x = rand() % 3;
            y = rand() % 3;
            command = rand() % 4;

            if ((command == 0 && test[2] == 1 + '0'))
                continue;
            if ((command == 1 && test[2] == 0 + '0'))
                continue;
            if ((command == 2 && test[2] == 3 + '0'))
                continue;
            if ((command == 3 && test[2] == 2 + '0'))
                continue;
            if (y == 0 && command == 0)
                continue;
            if (x == 0 && command == 3)
                continue;
            if (x == 2 && command == 2)
                continue;
            if (y == 2 && command == 1)
                continue;

            parameter[0] = x + '0';
            parameter[1] = y + '0';
            parameter[2] = command + '0';
            parameter[3] = '\0';

            check = moveCheck(x, y, command);
            if (check == 1)
                test = parameter;
        }
        return parameter;
    }

    int EightPuzzle::playAuto() {
       
        int x = 0, y = 0, command = 0;
        string parameter;

        print();   /* And printing the map */

        parameter = random();

        x = parameter[0] - '0';
        y = parameter[1] - '0';
        command = parameter[2] - '0';
        move(x, y, command);

        return 0;
    }

    void EightPuzzle::move(int x, int y, int move) {
        if (move == UP) {

            if (y > 0) {
                if (map[y - 1][x] == 9) {

                    map[y - 1][x] = map[y][x];
                    map[y][x] = 9;
                }
                else
                    cout << "Invalid command ! \n\n";
            }
            else
                cout << "Invalid command ! \n\n";

        }
        else if (move == DOWN) {

            if (map[y + 1][x] == 9) {

                map[y + 1][x] = map[y][x];
                map[y][x] = 9;
            }
            else
                cout << "Invalid command ! \n\n";
        }
        else if (move == RIGHT) {

            if (map[y][x + 1] == 9) {

                map[y][x + 1] = map[y][x];
                map[y][x] = 9;
            }
            else
                cout << "Invalid command ! \n\n";
        }
        else if (move == LEFT) {

            if (x > 0) {
                if (map[y][x - 1] == 9) {

                    map[y][x - 1] = map[y][x];
                    map[y][x] = 9;
                }
                else
                    cout << "Invalid command ! \n\n";
            }
            else
                cout << "Invalid command ! \n\n";
        }
    }

    int EightPuzzle::moveCheck(int x, int y, int move) {
        if (move == UP && y > 0) {

            if (map[y - 1][x] == 9) {

                return 1;
            }
            else
                return 0;
        }
        else if (move == DOWN) {

            if (map[y + 1][x] == 9) {

                return 1;
            }
            else
                return 0;
        }
        else if (move == RIGHT) {

            if (map[y][x + 1] == 9) {

                return 1;
            }
            else
                return 0;
        }
        else if (move == LEFT && x > 0) {

            if (map[y][x - 1] == 9) {

                return 1;
            }
            else
                return 0;
        }
        return 0;
    }

    void EightPuzzle::initialize() {
        int i, random;
        int x = N - 1, y = N - 1;

        for (i = 0; i < N * N; i++)
            map[i / N][i % N] = (i / N) * N + i % N + 1;  /*  Here, we fill the arrays up to N * N with the formula I developed. */

        for (i = 0; i < 3; i++) {  /*  we manually mix.I chose to shuffle 4 times */
            random = rand() % 4;  /* we select the order of the operation with the rand function. However,the values of this function do not change without turning off the computer. */
            if (random == UP) {
                if (y - 1 >= 0) {
                    move(x, y - 1, DOWN);
                    y--;
                }
            }
            else if (random == DOWN) {
                if (y + 1 < N) {
                    move(x, y + 1, UP);                   /* we ship to functions according to different directions for mixing */
                    y++;
                }
            }
            else if (random == RIGHT) {
                if (x + 1 < N) {
                    move(x + 1, y, LEFT);
                    x++;
                }
            }
            else if (random == LEFT) {
                if (x - 1 >= 0) {
                    move(x - 1, y, RIGHT);
                    x--;
                }
            }
        }
    }

    void EightPuzzle::print() {
        int i, j;

        cout << "\n";
        cout << "\x1b[2J";
        cout << "\033[0;0H"; // move cursor to 0,0
        cout << endl << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        cout << "\n";
        for (i = 0; i < N; i++) {
            for (j = 0; j < 6 * N + 1; j++) cout << "*";   /*  we print * s based on N for our table shape */
            cout << "\n*";
            for (j = 0; j < N; j++) {
                if (map[i][j] == N * N)    /* we check the gap value */
                    cout << "x    *";
                else
                    cout << map[i][j] << "    *";  /* We print the elements of the map */
            }
            cout << "\n*";
        }
        for (j = 0; j < 6 * N + 1; j++) cout << "*";   /* we print * s based on N for our table shape */
        cout << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

    }

    void EightPuzzle::playUser(string parameter) {
        int  x, y, command;  /* defined variables */

        x = parameter[0] - '0';
        y = parameter[1] - '0';
        command = parameter[2] - '0';

        move(x, y, command);
        print();
        cout << "\n";
    }

    bool EightPuzzle::endGame() {
       
        int i;
        int counter = 0;


        for (i = 0; i < N * N; i++) {
            if (map[i / N][i % N] == (i / N) * N + i % N + 1)
                counter++;                    /* If the order of the values does not match in this function that I have shortened, the value to return will be 0. */
        }
        if (counter == N * N) {
            print();
            return true;
        }

        else
            return false;
    }

    int EightPuzzle::boardScore() {
        return boardscore;
    }

    //***************************************************************************************************

    class Klotski : public BoardGame2D {
    public:
        vector<vector<string>>klo= klotski_Map;
        int boardscore=0;
       
        void initialize();
        void print();
        bool endGame();
        int boardScore();
        int mapControl(string parameter);
        string randMove();
        void playUser(string parameter);
        int mapUpdate(string parameter);
        int playAuto();
    };

    void Klotski::initialize() {
        klo = klotski_Map;
    }
    void Klotski::print() {
        cout << "\n";
        cout << "\x1b[2J";
        cout << "\033[0;0H"; // move cursor to 0,0
        cout << endl << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 8; j++) {
                if (klo[i][j] != "X")
                    cout << klo[i][j] << " ";

            }
            cout << "\n";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    bool Klotski::endGame(){
        if (klo[6][3] == "A" && klo[6][4] == "A" && klo[5][3] == "A" && klo[5][4] == "A") {   // check 

            return true;
        }

        else
            return false;
    }
    int Klotski::boardScore() {
        return boardscore;

    }
    int Klotski::mapControl(string parameter) {

        int flag = 1;

        if (parameter[1] == 'U') {
            if (parameter[0] == 'B' || parameter[0] == 'C' || parameter[0] == 'H' || parameter[0] == 'D') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0])) {

                            if (klo[i - 1][j] == " ") {
                                flag = 0;
                                return 1;
                            }
                            else
                                return 0;
                            break;
                        }
                    }
                }
            }
            else if (parameter[0] == 'F' || parameter[0] == 'G' || parameter[0] == 'K' || parameter[0] == 'I') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0])) {

                            if (klo[i - 1][j] == " ") {
                                flag = 0;
                                return 1;
                            }
                            else
                                return 0;
                            break;
                        }
                    }
                }
            }
            else if (parameter[0] == 'A') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0])) {

                            if (klo[i - 1][j] == " " && klo[i - 1][j + 1] == " ") {

                                flag = 0;
                                return 1;
                            }
                            else
                                return 0;
                            break;
                        }
                    }
                }
            }
            else if (parameter[0] == 'E') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0])) {

                            if (klo[i - 1][j] == " " && klo[i - 1][j + 1] == " ") {

                                flag = 0;
                                return 1;
                            }
                            else
                                return 0;
                            break;
                        }
                    }
                }
            }
        }
        else  if (parameter[1] == 'D') {
            if (parameter[0] == 'B' || parameter[0] == 'C' || parameter[0] == 'H' || parameter[0] == 'D') {

                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0])) {

                            if (klo[i + 2][j] == " ") {

                                flag = 0;
                                return 1;
                            }
                            else
                                return 0;
                            break;
                        }
                    }
                }
            }
            else if (parameter[0] == 'F' || parameter[0] == 'G' || parameter[0] == 'K' || parameter[0] == 'I') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0])) {

                            if (klo[i + 1][j] == " ") {

                                flag = 0;
                                return 1;
                            }
                            else
                                return 0;
                            break;
                        }
                    }
                }
            }
            else if (parameter[0] == 'A') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0])) {

                            if (klo[i + 2][j] == " " && klo[i + 2][j + 1] == " ") {


                                flag = 0;
                                return 1;
                            }
                            else
                                return 0;
                            break;
                        }
                    }
                }
            }
            else if (parameter[0] == 'E') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0])) {

                            if (klo[i + 1][j] == " " && klo[i + 1][j + 1] == " ") {


                                flag = 0;
                                return 1;
                            }
                            else
                                return 0;
                            break;
                        }
                    }
                }
            }
        }
        else  if (parameter[1] == 'R') {
            if (parameter[0] == 'B' || parameter[0] == 'C' || parameter[0] == 'H' || parameter[0] == 'D') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0])) {

                            if (klo[i][j + 1] == " " && klo[i + 1][j + 1] == " ") {


                                flag = 0;
                                return 1;
                            }
                            else
                                return 0;
                            break;
                        }
                    }
                }
            }
            else if (parameter[0] == 'F' || parameter[0] == 'G' || parameter[0] == 'K' || parameter[0] == 'I') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0])) {

                            if (klo[i][j + 1] == " ") {

                                flag = 0;
                                return 1;
                            }
                            else
                                return 0;
                            break;
                        }
                    }
                }
            }
            else if (parameter[0] == 'A') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0])) {

                            if (klo[i][j + 2] == " " && klo[i + 1][j + 2] == " ") {


                                flag = 0;
                                return 1;
                            }
                            else
                                return 0;
                            break;
                        }
                    }
                }
            }
            else if (parameter[0] == 'E') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0])) {

                            if (klo[i][j + 2] == " ") {


                                flag = 0;
                                return 1;
                            }
                            else
                                return 0;
                            break;
                        }
                    }
                }
            }
        }
        else  if (parameter[1] == 'L') {
            if (parameter[0] == 'B' || parameter[0] == 'C' || parameter[0] == 'H' || parameter[0] == 'D') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0])) {

                            if (klo[i][j - 1] == " " && klo[i + 1][j - 1] == " ") {


                                flag = 0;
                                return 1;
                            }
                            else
                                return 0;
                            break;
                        }
                    }
                }
            }
            else if (parameter[0] == 'F' || parameter[0] == 'G' || parameter[0] == 'K' || parameter[0] == 'I') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0])) {

                            if (klo[i][j - 1] == " ") {

                                flag = 0;
                                return 1;
                            }
                            else
                                return 0;
                            break;
                        }
                    }
                }
            }
            else if (parameter[0] == 'A') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0])) {

                            if (klo[i][j - 1] == " " && klo[i + 1][j - 1] == " ") {


                                flag = 0;
                                return 1;
                            }
                            else
                                return 0;
                            break;
                        }
                    }
                }
            }
            else if (parameter[0] == 'E') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0])) {

                            if (klo[i][j - 1] == " ") {

                                flag = 0;
                                return 1;
                            }
                            else
                                return 0;
                            break;
                        }
                    }
                }
            }
        }
        return 0;
    }
    string Klotski::randMove() {
       
        string move = "  ";
        int check = 0;

        while (1) {                         // continues until the right move comes
            int object = rand() % 10 + 1;

            if (object == 1)
                move[0] = 'A';
            else  if (object == 2)
                move[0] = 'B';
            else  if (object == 3)
                move[0] = 'C';
            else  if (object == 4)
                move[0] = 'D';
            else  if (object == 5)
                move[0] = 'E';
            else  if (object == 6)
                move[0] = 'F';
            else  if (object == 7)
                move[0] = 'G';
            else  if (object == 8)
                move[0] = 'H';
            else  if (object == 9)
                move[0] = 'I';
            else  if (object == 10)
                move[0] = 'K';

            int direction = rand() % 4 + 1;

            if (direction == 1)
                move[1] = 'U';
            else if (direction == 2)
                move[1] = 'D';
            else if (direction == 3)
                move[1] = 'R';
            else if (direction == 4)
                move[1] = 'L';

            check = mapControl(move);
            if (check == 1)
                break;
        }

        return move;
    }
    void Klotski::playUser(string parameter) {
        mapUpdate(parameter);
        print();
    }
    int Klotski::mapUpdate(string parameter) {


        int flag = 1;

        if (parameter[1] == 'U') {
            if (parameter[0] == 'B' || parameter[0] == 'C' || parameter[0] == 'H' || parameter[0] == 'D') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0]) && i > 0) {

                            if (klo[i - 1][j] == " ") {

                                klo[i - 1][j] = parameter[0];
                                klo[i + 1][j] = " ";
                                flag = 0;
                                return 1;
                            }
                            break;
                        }
                    }
                }
            }
            else if (parameter[0] == 'F' || parameter[0] == 'G' || parameter[0] == 'K' || parameter[0] == 'I') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0]) && i > 0) {

                            if (klo[i - 1][j] == " ") {

                                klo[i - 1][j] = parameter[0];
                                klo[i][j] = " ";
                                flag = 0;
                                return 1;
                            }
                            break;
                        }
                    }
                }
            }
            else if (parameter[0] == 'A') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0]) && i > 0) {

                            if (klo[i - 1][j] == " " && klo[i - 1][j + 1] == " ") {

                                klo[i - 1][j] = parameter[0];
                                klo[i - 1][j + 1] = parameter[0];
                                klo[i + 1][j] = " ";
                                klo[i + 1][j + 1] = " ";
                                flag = 0;
                                return 1;
                            }
                            break;
                        }
                    }
                }
            }
            else if (parameter[0] == 'E') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0]) && i > 0) {

                            if (klo[i - 1][j] == " " && klo[i - 1][j + 1] == " ") {

                                klo[i - 1][j] = parameter[0];
                                klo[i - 1][j + 1] = parameter[0];
                                klo[i][j] = " ";
                                klo[i][j + 1] = " ";
                                flag = 0;
                                return 1;
                            }
                            break;
                        }
                    }
                }
            }
        }
        else  if (parameter[1] == 'D') {
            if (parameter[0] == 'B' || parameter[0] == 'C' || parameter[0] == 'H' || parameter[0] == 'D') {

                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0])) {

                            if (klo[i + 2][j] == " ") {

                                klo[i + 2][j] = parameter[0];
                                klo[i][j] = " ";
                                flag = 0;
                                return 1;
                            }
                            break;
                        }
                    }
                }
            }
            else if (parameter[0] == 'F' || parameter[0] == 'G' || parameter[0] == 'K' || parameter[0] == 'I') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0])) {

                            if (klo[i + 1][j] == " ") {

                                klo[i + 1][j] = parameter[0];
                                klo[i][j] = " ";
                                flag = 0;
                                return 1;
                            }
                            break;
                        }
                    }
                }
            }
            else if (parameter[0] == 'A') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0])) {

                            if (klo[i + 2][j] == " " && klo[i + 2][j + 1] == " ") {

                                klo[i + 2][j] = parameter[0];
                                klo[i + 2][j + 1] = parameter[0];
                                klo[i][j] = " ";
                                klo[i][j + 1] = " ";
                                flag = 0;
                                return 1;
                            }
                            break;
                        }
                    }
                }
            }
            else if (parameter[0] == 'E') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0])) {

                            if (klo[i + 1][j] == " " && klo[i + 1][j + 1] == " ") {

                                klo[i + 1][j] = parameter[0];
                                klo[i + 1][j + 1] = parameter[0];
                                klo[i][j] = " ";
                                klo[i][j + 1] = " ";
                                flag = 0;
                                return 1;
                            }
                            break;
                        }
                    }
                }
            }
        }
        else  if (parameter[1] == 'R') {
            if (parameter[0] == 'B' || parameter[0] == 'C' || parameter[0] == 'H' || parameter[0] == 'D') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0])) {

                            if (klo[i][j + 1] == " " && klo[i + 1][j + 1] == " ") {

                                klo[i][j + 1] = parameter[0];
                                klo[i + 1][j + 1] = parameter[0];
                                klo[i][j] = " ";
                                klo[i + 1][j] = " ";
                                flag = 0;
                                return 1;
                            }
                            break;
                        }
                    }
                }
            }
            else if (parameter[0] == 'F' || parameter[0] == 'G' || parameter[0] == 'K' || parameter[0] == 'I') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0])) {

                            if (klo[i][j + 1] == " ") {

                                klo[i][j + 1] = parameter[0];
                                klo[i][j] = " ";
                                flag = 0;
                                return 1;
                            }
                            break;
                        }
                    }
                }
            }
            else if (parameter[0] == 'A') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0])) {

                            if (klo[i][j + 2] == " " && klo[i + 1][j + 2] == " ") {

                                klo[i][j + 2] = parameter[0];
                                klo[i + 1][j + 2] = parameter[0];
                                klo[i][j] = " ";
                                klo[i + 1][j] = " ";
                                flag = 0;
                                return 1;
                            }
                            break;
                        }
                    }
                }
            }
            else if (parameter[0] == 'E') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0])) {

                            if (klo[i][j + 2] == " ") {

                                klo[i][j + 2] = parameter[0];
                                klo[i][j] = " ";
                                flag = 0;
                                return 1;
                            }
                            break;
                        }
                    }
                }
            }
        }
        else  if (parameter[1] == 'L') {
            if (parameter[0] == 'B' || parameter[0] == 'C' || parameter[0] == 'H' || parameter[0] == 'D') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0]) && j > 0) {

                            if (klo[i][j - 1] == " " && klo[i + 1][j - 1] == " ") {

                                klo[i][j - 1] = parameter[0];
                                klo[i + 1][j - 1] = parameter[0];
                                klo[i][j] = " ";
                                klo[i + 1][j] = " ";
                                flag = 0;
                                return 1;
                            }
                            break;
                        }
                    }
                }
            }
            else if (parameter[0] == 'F' || parameter[0] == 'G' || parameter[0] == 'K' || parameter[0] == 'I') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0]) && j > 0) {

                            if (klo[i][j - 1] == " ") {

                                klo[i][j - 1] = parameter[0];
                                klo[i][j] = " ";
                                flag = 0;
                                return 1;
                            }
                            break;
                        }
                    }
                }
            }
            else if (parameter[0] == 'A') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0]) && j > 0) {

                            if (klo[i][j - 1] == " " && klo[i + 1][j - 1] == " ") {

                                klo[i][j - 1] = parameter[0];
                                klo[i + 1][j - 1] = parameter[0];
                                klo[i][j + 1] = " ";
                                klo[i + 1][j + 1] = " ";
                                flag = 0;
                                return 1;
                            }
                            break;
                        }
                    }
                }
            }
            else if (parameter[0] == 'E') {
                for (int i = 0; i < 9; i++) {
                    if (flag == 0)
                        break;
                    for (int j = 0; j < 8; j++) {
                        if ((klo[i][j][0] == parameter[0]) && j > 0) {

                            if (klo[i][j - 1] == " ") {

                                klo[i][j - 1] = parameter[0];
                                klo[i][j + 1] = " ";
                                flag = 0;
                                return 1;
                            }
                            break;
                        }
                    }
                }
            }
        }
        print();
        return 0;
    }
    int Klotski::playAuto() {
        string move;

        move = randMove();

        mapUpdate(move);
        print();

        return 0;
    }
}
//******************************************************************************************************************************************************************************************************