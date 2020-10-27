//
//  main.cpp
//  N1 Tecnicas de Prog
//
//  Created by oliveira on 22/10/20.
//

#include <iostream>
#include "Rato.h"
#include "Mapa.h"
#include "EncontrarCaminho.h"
using namespace std;

int main(int argc, const char * argv[]) {
    Mapa mapa;
    Rato rato;
    
    int PosInicialX = 0;
    int PosInicialY = 0;
    
    rato.posX = PosInicialX;
    rato.posY = PosInicialY;
    mapa.cenario[PosInicialX][PosInicialY] = ENTRADA;
    
    cout << "Mapa inicial:" << endl;
    mostrarMapa(mapa);
    
    cout << endl;
    EncontrarCaminho(mapa, rato);
    alterarMapa(mapa, PosInicialX, PosInicialY, "E");
    mostrarMapa(mapa);
    
    cout << endl;
    EncontrarSaida(mapa, rato);
    mostrarMapa(mapa);
    return 0;
}
