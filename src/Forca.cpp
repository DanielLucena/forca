#include <iostream>
#include "Game.h"
//#include "WordsList.h"
#include "Round.h"
#include "Visual.h"

using namespace std;

int main(int argc, char *argv[]){
    //WordsList WordsList(argv[1]);
    //WordsList.SpitWords();
    //cout << WordsList.random_word() << endl;
    Game game(argv[1]);
    //Game.write_score();
    //Round round1;
    //cout << round1.remove_duplicates("olamacaco") << endl;
    //Visual visual;
    //visual.print_forca();

    game.initialaze_game();

    return 0;
}