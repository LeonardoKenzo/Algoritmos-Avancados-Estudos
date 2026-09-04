#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int encontrarMenorDuracaoDia(int intervaloMenor, int intervaloMaior, const vector<int>& duracoes, int maxDias, int melhorResposta) {
    // O espaço de busca acabou
    if (intervaloMenor > intervaloMaior) {
        return melhorResposta;
    }

    // Calcula a menor duracao
    int duracaoIdeal = intervaloMenor + (intervaloMaior - intervaloMenor) / 2;
    int diasCounter = 1;
    int duracaoDia = 0;

    for (int duracao : duracoes) {
        if (duracaoDia + duracao > duracaoIdeal) {
            diasCounter++;
            duracaoDia = 0;
        }
        duracaoDia += duracao;
    }

    if (diasCounter <= maxDias)
        return encontrarMenorDuracaoDia(intervaloMenor, duracaoIdeal - 1, duracoes, maxDias, duracaoIdeal);
    else 
        return encontrarMenorDuracaoDia(duracaoIdeal + 1, intervaloMaior, duracoes, maxDias, melhorResposta);
}

int main(){
    int nTestes;
    cin >> nTestes;

    for(int i = 0; i < nTestes; i++){

        // Leitura das entradas
        int artistas, dias;
        cin >> artistas;
        cin >> dias;

        vector<int> duracoes;
        int intervaloMaior = 0;

        for(int j = 0; j < artistas; j++){
            int duracao;
            cin >> duracao;
            duracoes.push_back(duracao);
            intervaloMaior += duracao;
        }

        // Verifica o intervalo da resposta
        auto intervaloDuracao = max_element(duracoes.begin(), duracoes.end());
        int intervaloMenor = *intervaloDuracao;

        int duracaoIdeal = encontrarMenorDuracaoDia(intervaloMenor, intervaloMaior, duracoes, dias, intervaloMenor);

        cout << "Caso " << i + 1 << ": " << duracaoIdeal << endl; 
    }


    return 0;
}