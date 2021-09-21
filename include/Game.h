#ifndef Game_h
#define Game_h
#include <iostream>
#include <vector>
#include <string>
#include "WordsList.h"
#include "Visual.h"

class Game{
    public:
    int score; //<! guarda o score do jogador que sera incrementado a cada rodada
    std::vector<std::string> wordsScore; //<! vetor das palavras acertadas pelo jogador
    std::string playerName; //<! nome do jogar que sera guardada no score
    WordsList wordsList; //<! obejeto unico da classe WordsList que sera ultilizado no objeto game
    Visual visual; //<! obejeto unico da classe Visual que sera ultilizado no objeto game
    public:

    /**
    * @brief construtor padrão
    * @param filepath caminho do arquivo de plavras para serem sorteadas
    **/
    Game(std::string filepath);

    public:

    /**
    * @brief Função principal do jogo nela sera chamado todos os outros metodos
    */
    void initialaze_game();

    /**
    * @brief escreve o score final no arquivo de scores
    */
    void write_score();

    /**
    * @brief executa as ações de uma rodada
    * @return true se o jogador venceu a rodada, ou false se perdeu
    */
    bool run();

    /**
    * @brief executa as ações da finalização do jogo
    */
    void endGame();
};

#endif //Game_h