#include "WordsList.h"

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

//using namespace std;

WordsList::WordsList(std::string filepath){
    SaveData(filepath);
    wordLength = words.size();
}


void WordsList::SaveData(std::string filepath){
    std::ifstream s(filepath);
    std::string line;
    if(s.is_open()){
        while(std::getline(s, line)){
            words.push_back(line);
        }
    }
}

std::string WordsList::random_word(){
    /* initialize random seed: */
    srand (time(NULL));
    int i = rand() % wordLength;
    std::string word = words[i];
    words.erase(words.begin()+i);
    return word;
}


//test functions
void WordsList::SpitWords(){
    for(int i=0;i<wordLength;i++){
        std::cout << words[i] << std::endl;
    }
}
