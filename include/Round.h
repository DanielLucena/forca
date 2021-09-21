#ifndef Round_h
#define Round_h
#include <iostream>
#include <vector>
#include <string>

class Round{
    private:
        int tries; //<! guarda a quatidade de tentativas ja gastas
        int localScore; //<! guarda o score da rodada atual
        std::string word; //<! guarda a palavra da rodada autal
        std::string unicChars; // apagar
        
    public:
        /**
        * @brief construtor padrão
        * @param word palavra que sera ultilizada na rodada
        **/
        Round(std::string word);

        /**
        * @brief destrutor padrão
        **/
        ~Round();

        /**
        * @brief get do tries
        * @return int das tentativas gastas
        */
        int getTries();

        /**
        * @brief get do localScore
        * @return int do score local
        **/
        int getLocalScore();

        /**
        * @brief get do word
        * @return string com a palavra da rodada
        **/
        std::string getWord();

        /**
        * @brief função para calcular o estado atual da rodada
        * @return 1: jogo perdido; 2: jogo em andamento; 3: jogo ganho;
        **/
        int roundState();

        /**
        * @brief verifica se a letra passada esta na palavra sorteada
        * @param c letra da tantativa
        * @return retorna o score apenas da rodada
        **/
        int guess(char c);

        /**
        * @brief função para calcular o estado atual da rodada
        * @return 1: jogo perdido; 2: jogo em andamento; 3: jogo ganho;
        **/
        std::string discovered();
    
    public:
        std::string remove_duplicates(std::string word); //apagar

        
};

#endif //Round_h