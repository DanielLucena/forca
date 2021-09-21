#ifndef WordsList_h
#define WordsList_h
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class WordsList{
    private:
        std::vector<std::string> words; //<! Lista de palavras que podem ser sorteadas

    public:

    /**
    * @brief construtor padrão
    **/
    WordsList();

    WordsList(std::string filepath);

    void SaveData(std::string filepath);

    std::string random_word();

    bool hasWords();

    //test functions
    void SpitWords();

};


#endif //WordsList_h