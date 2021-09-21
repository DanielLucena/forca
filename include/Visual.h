#ifndef Visual_h
#define Visual_h
#include <iostream>
#include <vector>
#include <string>

class Visual{
    public:
        std::vector<std::string> stickMan = {"\n\n\n",
        " o\n\n\n",
        " o\n |\n\n",
        " o\n/|\n\n",
        " o\n/|\\\n\n",
        " o\n/|\\\n/ \n",
        " o\n/|\\\n/ \\\n"};

    Visual();
    
    //void print_forca(); // apagar

    void menu();

    void showScore();

    void wrongInput();

    void showRound(int score, int tries, std::string word);

    void youLost(std::string word);

    void keepPlaying();

    void askName();

    void noMoreWords();
    
    void clearScreen();
};
#endif //Visual_h