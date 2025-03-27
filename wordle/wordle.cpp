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

    /// CARGA LISTADO DE PALABRAS ///
    vector<string> words = cargar_listado(filename);
    srand(time(nullptr));
    string selected_word = words[rand() % (words.size())];

    /// COMIENZA EL JUEGO ///
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
        /// SI EL INTENTO ES VALIDO ES EVALUADO Y NOS DA EL RESULTADO ///
        if (intento_valido(intento, selected_word, words)){
            vec = evaluar_intento(intento, selected_word);
            str = respuesta_en_string(vec);
            /// SI ADIVINA LA PALABRA TERMINA EL JUEGO ///
            if (str == "+++++"){
                cout << "Correcto!" << endl;
                return 0;
            }
            /// SINO CONTINUA ///
            else{
                cout << str << endl;
                tries--;
            }
        }
        /// SI EL INTENTO NO ES VALIDO SE PUEDE VOLVER A INTENTAR ////
        else{
            cout << "Intento invalido, probar una palabra valida de 5 letras" << endl;
        }
    }
    /// NO HAY MAS INTENTOS ///
    cout << "Perdiste! La respuesta era: " << selected_word << endl;
    return 0;

}
