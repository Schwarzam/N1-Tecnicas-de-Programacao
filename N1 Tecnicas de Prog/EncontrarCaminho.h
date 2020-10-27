//
//  EncontrarCaminho.h
//  N1 Tecnicas de Prog
//
//  Created by oliveira on 22/10/20.
//

#ifndef EncontrarCaminho_h
#define EncontrarCaminho_h
#include "Mapa.h"
#include "Rato.h"
#include <chrono>
#include <thread>
#include <stdlib.h>

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;

std::string d;
std::string DIREITA;
std::string ESQUERDA;
std::string CIMA;
std::string BAIXO;

int EncontrarCaminho(Mapa &mapa, Rato &rato){
    if (rato.temQueijo == true){
        std::cout << "O rato achou o queijo!" << endl;
        return 0;
    }
    
    DIREITA = PegarValorPosicao(mapa, rato.posX, rato.posY - 1);
    ESQUERDA = PegarValorPosicao(mapa, rato.posX, rato.posY + 1);
    CIMA = PegarValorPosicao(mapa, rato.posX - 1, rato.posY);
    BAIXO = PegarValorPosicao(mapa, rato.posX + 1, rato.posY);

    if (BAIXO != "P" and BAIXO != "" and BAIXO != ">"){
        alterarMapa(mapa, rato.posX, rato.posY, ">");
        rato.posX = rato.posX + 1;
        alterarMapa(mapa, rato.posX, rato.posY, "R");
    }else if (DIREITA != "P" and DIREITA != "" and DIREITA != ">"){
        alterarMapa(mapa, rato.posX, rato.posY, ">");
        rato.posY = rato.posY - 1;
        alterarMapa(mapa, rato.posX, rato.posY, "R");
    }else if (CIMA != "P" and CIMA != "" and CIMA != ">"){
        alterarMapa(mapa, rato.posX, rato.posY, ">");
        rato.posX = rato.posX - 1;
        alterarMapa(mapa, rato.posX, rato.posY, "R");
    }else if (ESQUERDA != "P" and ESQUERDA != "" and ESQUERDA != ">"){
        alterarMapa(mapa, rato.posX, rato.posY, ">");
        rato.posY = rato.posY + 1;
        alterarMapa(mapa, rato.posX, rato.posY, "R");
    }else if (ESQUERDA != "P" and ESQUERDA != ""){
        alterarMapa(mapa, rato.posX, rato.posY, "> ");
        rato.posY = rato.posY + 1;
        alterarMapa(mapa, rato.posX, rato.posY, "R");
    }else if (CIMA != "P" and CIMA != ""){
        alterarMapa(mapa, rato.posX, rato.posY, "> ");
        rato.posX = rato.posX - 1;
        alterarMapa(mapa, rato.posX, rato.posY, "R");
    }else if (DIREITA != "P" and DIREITA != ""){
        alterarMapa(mapa, rato.posX, rato.posY, "> ");
        rato.posY = rato.posY - 1;
        alterarMapa(mapa, rato.posX, rato.posY, "R");
    }else if (BAIXO != "P" and BAIXO != ""){
        alterarMapa(mapa, rato.posX, rato.posY, "> ");
        rato.posX = rato.posX + 1;
        alterarMapa(mapa, rato.posX, rato.posY, "R");
    }else{
        cout << "Impossivel" <<endl;
        return 0;
    }
    
    if (CIMA == "Q" or BAIXO == "Q" or ESQUERDA == "Q" or DIREITA == "Q")
        rato.temQueijo = true;
    
//    sleep_for(nanoseconds(10));
//    sleep_until(system_clock::now() + seconds(1));
//    mostrarMapa(mapa);
    alterarMapa(mapa, 0, 0, "E");
    return EncontrarCaminho(mapa, rato);
};

int EncontrarSaida(Mapa &mapa, Rato &rato){
    DIREITA = PegarValorPosicaoSaida(mapa, rato.posX, rato.posY - 1);
    ESQUERDA = PegarValorPosicaoSaida(mapa, rato.posX, rato.posY + 1);
    CIMA = PegarValorPosicaoSaida(mapa, rato.posX - 1, rato.posY);
    BAIXO = PegarValorPosicaoSaida(mapa, rato.posX + 1, rato.posY);

    if (BAIXO == ">"){
        alterarMapa(mapa, rato.posX, rato.posY, "<");
        rato.posX = rato.posX + 1;
        alterarMapa(mapa, rato.posX, rato.posY, "R");
    }else if (DIREITA == ">"){
        alterarMapa(mapa, rato.posX, rato.posY, "<");
        rato.posY = rato.posY - 1;
        alterarMapa(mapa, rato.posX, rato.posY, "R");
    }else if (CIMA == ">"){
        alterarMapa(mapa, rato.posX, rato.posY, "<");
        rato.posX = rato.posX - 1;
        alterarMapa(mapa, rato.posX, rato.posY, "R");
    }else if (ESQUERDA == ">"){
        alterarMapa(mapa, rato.posX, rato.posY, "<");
        rato.posY = rato.posY + 1;
        alterarMapa(mapa, rato.posX, rato.posY, "R");
    }
    
    if (CIMA == "E" or BAIXO == "E" or ESQUERDA == "E" or DIREITA == "E"){
        std::cout << "O rato saiu!" << endl;
        alterarMapa(mapa, rato.posX, rato.posY, "<");
        alterarMapa(mapa, 0, 0, "R");
        return 0;
    }
    
//    sleep_for(nanoseconds(10));
//    sleep_until(system_clock::now() + seconds(1));
//    mostrarMapa(mapa);
    return EncontrarSaida(mapa, rato);
}


#endif /* EncontrarCaminho_h */
