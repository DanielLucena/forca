#include "Visual.h"


#include <vector>
#include <string>
#include <fstream>

//void clearScreen();

Visual::Visual(){

}

// void Visual::print_forca(){
//     for(auto s : stickMan){
//         std::cout << s;
//     }
// }

void Visual::menu(){
    //clearScreen();
    std::cout << "\033[2J";
    std::cout << "JOGO DA FORCA" << std::endl;
    std::cout << "\033[32m";
    std::cout << stickMan[6];
    std::cout << "\033[39m";
    std::cout << "Digite \'i\' para iniciar o jogo ou \'s\' para ver a lista de pontuação" << std::endl;
}

void Visual::showScore(){
    std::ifstream file ("data/scores.txt");
//    clearScreen();
    std::cout << "\033[2J";
    std::string line;
    //std::cout << file;
    while (getline(file, line)){
        std::cout << line << std::endl;
    }
    
    file.close();
}

void Visual::wrongInput(){
    std::cout << "Entrada invalida! digite uma entrada valida" << std::endl;
}

void Visual::showRound(int score, int tries, std::string word){
//    clearScreen();
    std::cout << "\033[2J";

    std::cout << std::endl << "Pontos: " << score << std::endl;
    std::cout << "\033[32m";
    std::cout << stickMan[tries];
    std::cout << "\033[39m";
    //std::cout << word << std::endl;
    for(int i=0; i<word.size();i++){
        std::cout << word[i] << " ";
        // if(word[i] <= 122 && word[i] >=  97){
        //     std::cout << "_" << " ";
        // }
        // else{
        //    std::cout << word[i] << " ";
        // }
    }
    std::cout << std::endl;
}

void Visual::youLost(std::string word){
    std::cout << "você perdeu a palavra era ";
    for(int i=0; i<word.size();i++){
        if(word[i] <= 122 && word[i] >=  97){
            std::cout << char(word[i]-32);
        }
        else{
           std::cout << word[i];
        }
    }
    std::cout << "!" << std::endl;   
}

void Visual::keepPlaying(){
    std::cout << "Você acertou a palavra!" << std::endl;
    std::cout << "Deseja continuar? (Digite s ou n)" << std::endl;
}

void Visual::askName(){
    std::cout << "Digite seu nome: " << std::endl;
}

void Visual::noMoreWords(){
    std::cout << "Parabéns voce completou todas as palavras!" << std::endl;
}

/**
 * @brief função auxiliar para limpar o terminal
 */
void Visual::clearScreen(){
//some C++ voodoo here ;D
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}