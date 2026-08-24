#include <iostream>
#include <list>
using namespace std;

struct COMAND {
    string text;
    int repeat = -1;
};

int main(){
    int nTestsCase;
    cin >> nTestsCase;
    
    for (int i = 0; i < nTestsCase; i++){
        list<COMAND> instructions;
        int nInstructions;
        cin >> nInstructions;
        int xAxis = 0;

        for(int j = 0; j < nInstructions; j++){
            COMAND Comand;  
            cin >> Comand.text;

            
            if(Comand.text == "ESQUERDA"){
                instructions.push_back(Comand);
                xAxis--;
            }
            else if(Comand.text == "DIREITA"){
                instructions.push_back(Comand); 
                xAxis++;
            }
            
            else {
                cin >> Comand.repeat;
                instructions.push_back(Comand);
                COMAND comandRepeat = Comand;
                do{
                    auto instructionsList = instructions.begin();
                    advance(instructionsList, comandRepeat.repeat);
                    comandRepeat = *instructionsList;

                    if(comandRepeat.text == "ESQUERDA"){
                        xAxis--;
                        break;
                    }
                    else if(comandRepeat.text == "DIREITA"){
                        xAxis++;
                        break;
                    }
                }while(comandRepeat.text == "REPETE");
            }
        }

        cout << xAxis << endl;
    }

    return 0;
}