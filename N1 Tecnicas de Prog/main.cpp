//
//  main.cpp
//  N1 Tecnicas de Prog
//
//  Created by oliveira on 22/10/20.
//

#include <iostream>
#include "Rato.h"
#include "Mapa.h"
using namespace std;

int main(int argc, const char * argv[]) {
    Mapa novo_mapa;
    
    novo_mapa = alterarMapa(novo_mapa, 0, 0, 'X');
    
    mostrarMapa(novo_mapa);
    return 0;
}
