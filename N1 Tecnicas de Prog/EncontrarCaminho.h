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
    int direcao;
    direcao =  1 + (std::rand() % 3);
    std::cout << direcao << endl;
    
    if (rato.temQueijo == true)
        return 0;
    
    if (mapa.cenario[rato.posX][rato.posY] == 'Q')
        rato.temQueijo = true;
    
    if (direcao == 1){
        if (mapa.cenario[rato.posX + 1][rato.posY] == '-'){
            alterarMapa(mapa, rato.posX, rato.posY, 'C');
            rato.posX = rato.posX + 1;
        }
    };
    if (direcao == 2){
        if (mapa.cenario[rato.posX - 1][rato.posY] == '-'){
            alterarMapa(mapa, rato.posX, rato.posY, 'C');
            rato.posX = rato.posX - 1;
        }
    };
    if (direcao == 3){
        if (mapa.cenario[rato.posX][rato.posY + 1] == '-'){
            alterarMapa(mapa, rato.posX, rato.posY, 'C');
            rato.posY = rato.posY + 1;
        }
    };
    if (direcao == 4){
        if (mapa.cenario[rato.posX][rato.posY - 1] == '-'){
            alterarMapa(mapa, rato.posX, rato.posY, 'C');
            rato.posY = rato.posY - 1;
        }
    };
    
    mostrarMapa(mapa);
    return EncontrarCaminho(mapa, rato);
};

#endif /* EncontrarCaminho_h */
