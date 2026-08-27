#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int nTestes;
    cin >> nTestes;

    for(int i = 0; i < nTestes; i++){
        // Leitura das entradas
        int nOvos, maxOvos, maxPeso;

        cin >> nOvos;
        cin >> maxOvos;
        cin >> maxPeso;
        if(nOvos < 1 || nOvos > 30 || maxOvos < 1 || maxOvos > 30 || maxPeso < 1 || maxPeso > 30)
            return 1;

        vector<int> pesoOvos;
        for(int j = 0; j < nOvos; j++){
            int pesoOvo;
            cin >> pesoOvo;

            pesoOvos.push_back(pesoOvo);
        }

        sort(pesoOvos.begin(), pesoOvos.end());
        
        int pesoTotalOvos = 0;
        int ovosFervendo;
        for(ovosFervendo = 0; ovosFervendo < nOvos; ovosFervendo++){
            if(pesoTotalOvos + pesoOvos[ovosFervendo] > maxPeso || ovosFervendo >= maxOvos)
                break;
            pesoTotalOvos += pesoOvos[ovosFervendo];
        }

        cout << "Caso " << i + 1 << ": " << ovosFervendo << endl;
    }

    return 0;
}