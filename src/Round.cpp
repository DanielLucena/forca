#include "Round.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

Round::Round(std::string word){
    this->word = word;
    tries = 0;
    localScore = 0;
}

Round::~Round(){
    // delete tries;
    // int localScore;
    // std::string word;
    // std::string unicChars;
}

int Round::getTries(){
    return this->tries;
}
int Round::getLocalScore(){
    return this->localScore;
}
std::string Round::getWord(){
    return this->word;
}

std::string Round::remove_duplicates(std::string word){
    int wordSize = word.size();
    char c;
    sort(word.begin(), word.end());
    auto res = unique(word.begin(), word.end());
    // for(int i=0;i<wordSize;i++){
    //     if(word[i] != c){
    //         c = word[i];
    //     }
    //     else{
    //         std::cout << "remove" << std::endl;
    //         word.erase (1);
    //     }
    // }
    //word.erase(std::unique(word.begin(), word.end()), word.end());
    //word.pop_back();
    return std::string(word.begin(), res);
}

int Round::guess(char c){
    if(c <= 90 && c >= 65){
        c += 32;
    }

    bool anyLowercase = false;
    int count = 0;
    for(int i=0; i<word.size();i++){
        if(word[i] == c){
            word[i] -= 32;
            count++;
            localScore++;
        }
        if(word[i] <= 122 && word[i] >=  97){
            anyLowercase = true;
        }
    }
    if(anyLowercase == false){
        localScore +=2;
        if(tries == 0){
            localScore++;
        }
    }

    if(count == 0){
        tries++;
        localScore--;
    }
    
    return localScore;
}

std::string Round::discovered(){
    std::string str;
    for(auto c : word){
        if(c <= 90 && c >= 65){
            str.push_back(c); 
        }
        else{
            str.push_back('_');
        }
    }
    return str;
}

int Round::roundState(){
    //std::cout << word << std::endl;
    if(tries >= 6){ // retorna 1 se as vidas ja acabaram
        return 1;
    }
    for(int i=0; i<word.size();i++){
        if(word[i] <= 122 && word[i] >=  97){ // retorna 3 se ainda existem letras para serem descobertas
            return 3;
        }
    }
    return 2; // retorna 2 se todas as letras ja foram descobertas;
}