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
    
    cout << "Mapa inicial:" << endl;
    mostrarMapa(mapa);
    
    cout << endl;
    rato.posX = 0;
    rato.posY = 0;
    rato.temQueijo = false;
    alterarMapa(mapa, rato.posX, rato.posY, "R");
    
    EncontrarCaminho(mapa, rato);
    mostrarMapa(mapa);
    
    cout << endl;
    EncontrarSaida(mapa, rato);
    mostrarMapa(mapa);
    return 0;
}
