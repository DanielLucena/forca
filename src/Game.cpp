#include "Game.h"
#include "Visual.h"
#include "WordsList.h"
#include "Round.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

Game::Game(std::string filepath){
    WordsList wordsList(filepath);
    this->wordsList = wordsList;
    Visual visual;
    this->visual = visual;
    score = 0;
}

void Game::write_score(){
    std::string words;
    std::ofstream file ("data/scores.txt", std::ios::app);

    file << playerName << "; ";
    for(int i=0; i<wordsScore.size();i++){
        words.append(wordsScore[i] + ", ");
    }
    if(words.size()>1){
        words.erase(words.end()-2, words.end());
        file << words << "; ";
    }

    file << score << std::endl;
    
    file.close();
}

bool Game::run(){
    if(wordsList.hasWords()){
        int localScore = 0;
        Round round(wordsList.random_word());
        //wordsList.SpitWords();
        char charGuess;
        std::cout << round.roundState() << std::endl;
        std::cout << round.discovered() << std::endl;
        while (round.roundState() == 3){
            visual.showRound(this->score + localScore,round.getTries(),round.discovered());
            std::cin >> charGuess;
            localScore = round.guess(charGuess);
        }
        this->score += localScore;
        visual.showRound(this->score,round.getTries(),round.discovered());
        
        if(round.roundState() == 1){
            visual.youLost(round.getWord());
            return false;
        }
        //if(round.roundState() == 2){
            this->wordsScore.push_back(round.getWord());
            return true;
        //}
    }
    return false;
}

void Game::endGame(){
    visual.askName();
    std::cin >> playerName;
    write_score();
}

void Game::initialaze_game(){
    

    char menuResponse = 'a';
    visual.menu();
    std::cin >> menuResponse;
    while (menuResponse != 'i' && menuResponse != 's'){
        visual.wrongInput();
        std::cin >> menuResponse;
    }
    if(menuResponse == 's'){
        visual.showScore();
    }
    else{
        bool runAgain = true;
        while(runAgain){
            bool won;
            won = run();
            if(won){
                visual.keepPlaying();
                std::cin >> menuResponse;
                while (menuResponse != 'n' && menuResponse != 's'){
                    visual.wrongInput();
                    visual.keepPlaying();
                    std::cin >> menuResponse;
                }
                if(menuResponse == 'n'){
                    endGame();
                    runAgain = false;
                }
                if(menuResponse == 's'){
                    runAgain = true;
                }
            }
            else{
                if(!wordsList.hasWords()){
                    visual.noMoreWords();
                }
                endGame();
                runAgain = false;
            }
        }
        
    }
    
}