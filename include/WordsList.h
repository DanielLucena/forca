#ifndef WordsList_h
#define WordsList_h
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class WordsList{
    public:
        std::vector<std::string> words; //<! Lista de palavras que podem ser sorteadas

        int wordLength;

    public:

    WordsList(std::string filepath);

    void SaveData(std::string filepath);

    std::string random_word();

    //test functions
    void SpitWords();
};


#endif //WordsList_h