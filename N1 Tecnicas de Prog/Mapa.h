//
//  Mapa.h
//  N1 Tecnicas de Prog
//
//  Created by oliveira on 22/10/20.
//

#ifndef Mapa_h
#define Mapa_h
using namespace std;

std::string PAREDE = "P";
std::string VAZIO = ".";
std::string QUEIJO = "Q";

struct Mapa{
    std::string cenario[5][5] = {
        VAZIO, VAZIO,  VAZIO, VAZIO,  VAZIO,
        VAZIO, PAREDE,  VAZIO, PAREDE,  QUEIJO,
        VAZIO, VAZIO,   VAZIO,  PAREDE,  PAREDE,
        VAZIO, VAZIO,   VAZIO,  VAZIO, VAZIO,
        VAZIO, VAZIO,   VAZIO,  PAREDE,  VAZIO,
    };
};

std::string PegarValorPosicao(Mapa &mapa, int PosX, int PosY){
    std::string valor;
    
    if (PosX > 4 or PosX < 0 or PosY > 4 or PosY < 0)
        valor = "";
    else
        valor = mapa.cenario[PosX][PosY];
    
    if (valor != "Q" and valor != "P" and valor != "." and valor != ">")
        valor = "";
    
    return valor;
}

Mapa alterarMapa(Mapa &mapa, int PosX, int PosY, std::string Acao){
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
