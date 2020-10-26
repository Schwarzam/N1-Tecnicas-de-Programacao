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

int EncontrarCaminho(Mapa &mapa, Rato &rato){
    std::string d;
    
    std::string DIREITA;
    std::string ESQUERDA;
    std::string CIMA;
    std::string BAIXO;
    
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
        alterarMapa(mapa, rato.posX, rato.posY, ">");
        rato.posY = rato.posY + 1;
        alterarMapa(mapa, rato.posX, rato.posY, "R");
    }else if (CIMA != "P" and CIMA != ""){
        alterarMapa(mapa, rato.posX, rato.posY, ">");
        rato.posX = rato.posX - 1;
        alterarMapa(mapa, rato.posX, rato.posY, "R");
    }else if (DIREITA != "P" and DIREITA != ""){
        alterarMapa(mapa, rato.posX, rato.posY, ">");
        rato.posY = rato.posY - 1;
        alterarMapa(mapa, rato.posX, rato.posY, "R");
    }else if (BAIXO != "P" and BAIXO != ""){
        alterarMapa(mapa, rato.posX, rato.posY, ">");
        rato.posX = rato.posX + 1;
        alterarMapa(mapa, rato.posX, rato.posY, "R");
    }
    
    if (CIMA == "Q" or BAIXO == "Q" or ESQUERDA == "Q" or DIREITA == "Q")
        rato.temQueijo = true;
    
    return EncontrarCaminho(mapa, rato);
};

#endif /* EncontrarCaminho_h */
