#include "WordsList.h"

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

//using namespace std;

WordsList::WordsList(){
    
}

WordsList::WordsList(std::string filepath){
    SaveData(filepath);
}


void WordsList::SaveData(std::string filepath){
    std::ifstream file(filepath);
    std::string line;
    if(file.is_open()){
        while(std::getline(file, line)){
            line.pop_back();
            words.push_back(line);
        }
    }
    file.close();
}

std::string WordsList::random_word(){
    /* initialize random seed: */
    srand (time(NULL));
    int i = rand() % words.size();
    std::string word = words[i];
    words.erase(words.begin()+i);
    return word;
}

bool WordsList::hasWords(){
    if(words.size() > 0){
        return true;
    }
    return false;
}

//test functions
void WordsList::SpitWords(){
    for(int i=0;i<words.size();i++){
        std::cout << words[i] << std::endl;
    }
}
