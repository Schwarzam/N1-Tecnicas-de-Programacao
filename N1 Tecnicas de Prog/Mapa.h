//
//  Mapa.h
//  N1 Tecnicas de Prog
//
//  Created by oliveira on 22/10/20.
//

#ifndef Mapa_h
#define Mapa_h
using namespace std;

const char PAREDE = 'P';
const char VAZIO = '-';
const char QUEIJO = 'Q';

struct Mapa{
    char cenario[5][5] = {
        VAZIO, PAREDE,  VAZIO, VAZIO,  VAZIO,
        VAZIO, PAREDE,  PAREDE, VAZIO,  VAZIO,
        VAZIO, VAZIO,   VAZIO,  PAREDE,  QUEIJO,
        VAZIO, VAZIO,   VAZIO,  VAZIO,  VAZIO,
        VAZIO, VAZIO,   VAZIO,  VAZIO,  VAZIO
    };
};


Mapa alterarMapa(Mapa mapa, int PosX, int PosY, const char Acao){
    
    mapa.cenario[PosX][PosY] = Acao;
    return mapa;
}

void mostrarMapa(Mapa umMapa){
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cout <<umMapa.cenario[i][j] << "\t";
        }
        cout << endl;
    }
}

#endif /* Mapa_h */
