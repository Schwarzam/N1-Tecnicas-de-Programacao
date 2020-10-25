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
    
//    std::cout << rato.posX << endl;
//    std::cout << rato.posY << endl;
//    std::cout << BAIXO << endl;
//    std::cout << DIREITA << endl;
//    std::cout << ESQUERDA << endl;
//    std::cout << CIMA << endl;
    
    mostrarMapa(mapa);
    
    if (BAIXO != "P" and BAIXO != "" and BAIXO != "C"){
        alterarMapa(mapa, rato.posX, rato.posY, "C");
        rato.posX = rato.posX + 1;
        alterarMapa(mapa, rato.posX, rato.posY, "R");
    }else if (DIREITA != "P" and DIREITA != "" and DIREITA != "C"){
        alterarMapa(mapa, rato.posX, rato.posY, "C");
        rato.posY = rato.posY - 1;
        alterarMapa(mapa, rato.posX, rato.posY, "R");
    }else if (ESQUERDA != "P" and ESQUERDA != "" and ESQUERDA != "C"){
        alterarMapa(mapa, rato.posX, rato.posY, "C");
        rato.posY = rato.posY + 1;
        alterarMapa(mapa, rato.posX, rato.posY, "R");
    }else if (CIMA != "P" and CIMA != "" and CIMA != "C"){
        alterarMapa(mapa, rato.posX, rato.posY, "C");
        rato.posX = rato.posX - 1;
        alterarMapa(mapa, rato.posX, rato.posY, "R");
    }
        
    return EncontrarCaminho(mapa, rato);
};

#endif /* EncontrarCaminho_h */
