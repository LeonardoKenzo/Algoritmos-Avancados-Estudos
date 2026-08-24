#include <iostream>
#include <map>
#include <vector>
using namespace std;

void pintar(int posicao, int nCores, int &contador, bool coresUsadas[], vector<int> &pinturaAtual, vector<int> &melhorPintura, bool parProibido[12][12], bool &encontrouMelhor){

    // Se a posicao é a quantidade de cores, acabou a pintura
    if(posicao == nCores){
        contador++;
        
        // Verificar se é favorita
        if(!encontrouMelhor || pinturaAtual < melhorPintura){
            melhorPintura = pinturaAtual;
            encontrouMelhor = true;
        }
        return;
    }
    
    for(int i = 0; i < nCores; i++){

        // Verifica se pode usar a cor
        if(coresUsadas[i] == true)
            continue;
        if(posicao != 0 && parProibido[pinturaAtual[posicao - 1]][i] == true){
            continue;
        }

        // Pinta a cor
        pinturaAtual.push_back(i);
        coresUsadas[i]= true;
        
        // Realiza a recursão
        pintar(posicao + 1, nCores, contador, coresUsadas, pinturaAtual, melhorPintura, parProibido, encontrouMelhor);

        pinturaAtual.pop_back();
        coresUsadas[i] = false;
    }
}

int main(){
    int nTestes;
    cin >> nTestes;
    if(nTestes < 1 || nTestes > 5)
        return 0;
    
    for(int i = 0; i < nTestes; i++){

        // le as cores usadas
        int nCores;
        cin >> nCores;
        if(nCores < 3 || nCores > 12)
            return 0;
        
        // cada cor recebe um valor de preferencia 0 é a cor mais preferida
        map<string, int> cores;
        vector<string> coresString;
        
        for(int preferencia = 0; preferencia < nCores; preferencia++){
            string cor;
            cin >> cor;
            cores.insert({cor, preferencia});
            coresString.push_back(cor);
        }

        // le os pares proibidos
        int nPar;
        cin >> nPar;
        if(nPar > (nCores * (nCores - 1)) / 2)
            return 0;
        
        bool parProibido[12][12] = {};

        for(int j = 0; j < nPar; j++){
            string parCor1, parCor2;
            cin >> parCor1;
            cin >> parCor2;
            auto indexCor1 = cores.find(parCor1);
            auto indexCor2 = cores.find(parCor2);

            if(indexCor1 != cores.end() && indexCor2 != cores.end()){
                parProibido[indexCor1->second][indexCor2->second] = true;
                parProibido[indexCor2->second][indexCor1->second] = true;
            }
        }

        // Pintar da melhor maneira
        vector<int> pinturaAtual;
        vector<int> melhorPintura;
        int quantidadePinturas = 0;
        bool encontrouMelhor = false;
        bool corFoiUsada[12] = {};

        pintar(0, nCores, quantidadePinturas, corFoiUsada, pinturaAtual, melhorPintura, parProibido, encontrouMelhor);

        cout << quantidadePinturas << endl;
        for(int j = 0; j < nCores; j++){
            cout << coresString[melhorPintura[j]] << " "; 
        }
        cout << endl;
    }

    return 0;
}