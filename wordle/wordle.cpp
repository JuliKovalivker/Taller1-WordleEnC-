#include "lib.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    cout << "Ruta al listado de palabras: ";
    string filename;
    cin >> filename;

    vector<string> words = cargar_listado(filename);
    if(words.size() < 1){
        cout << "No hay listado de palabras" << endl;
        return 0;
    }
    srand(time(nullptr));
    string selected_word = words[rand() % (words.size())];
    //cout << selected_word << endl;

    cout << "La palabra secreta tiene 5 letras" << endl;
    int tries = 5;
    while(tries >= 0){
        if(tries == 0){
            cout << "Ultimo intento!" << endl;
        }
        else{
            cout << "Te quedan " << tries << " intentos" << endl;
        }
        string intento;
        cin >> intento;
        vector<EstadoLetra> vec;
        string str;
        if (intento_valido(intento, selected_word, words)){
            vec = evaluar_intento(intento, selected_word);
            str = respuesta_en_string(vec);
            cout << str << endl;
            tries--;
        }
        else{
            cout << "Intento invalido, probar una palabra valida de 5 letras" << endl;
        }
        if (str == "+++++"){
            cout << "Correcto!" << endl;
            return 0;
        }
    }
    cout << "Perdiste! La respuesta era: " << selected_word << endl;
    return 0;

}
