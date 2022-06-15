#include "hw5_lib.h"
//###########################################################################################################################################################################
using namespace games;

int main() {
   
    srand(time(NULL));
    
    vector<BoardGame2D*> objects;
     
    BoardGame2D* p1 = new PegSolitaire();     // makes 2 objects of each class, puts them in a vector and calls playVector.
    BoardGame2D* p2 = new PegSolitaire();
    BoardGame2D* p3 = new EightPuzzle();
    BoardGame2D* p4 = new EightPuzzle();
    BoardGame2D* p5= new Klotski();
    BoardGame2D* p6= new Klotski();

    objects.push_back(p1);
    objects.push_back(p2);
    objects.push_back(p3);
    objects.push_back(p4);
    objects.push_back(p5);
    objects.push_back(p6);
    
    BoardGame2D::playVector(objects);


    BoardGame2D* obj2 = new EightPuzzle();
    obj2->playUser();
    BoardGame2D* obj3 = new Klotski();
    obj3->playUser();
    BoardGame2D* obj = new PegSolitaire();
    obj->playUser();
	return 0;
}


// Dogukan Tastan 1901042627