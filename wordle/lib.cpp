#include "lib.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

vector<string> cargar_listado(const string & nombre_archivo){
    ifstream infile(nombre_archivo);                                            //
    if (infile.good() == false) {                                               //
        cout << "No se pudo abrir el archivo " << nombre_archivo << endl;       //
        exit(1);                                                                //
    }                                                                           //
    string line;                                                                //
    vector<string> words;
    while(!infile.eof()) {                                                      //
        getline(infile, line);                                                  //
        words.push_back(line);
    }
    infile.close();                                                             //
    return words;
}

bool intento_valido(const string & intento, const string & palabra_secreta, const vector<string> &listado){
    // completar

    return false;
}

vector<EstadoLetra> evaluar_intento(const string & intento, const string & palabra_secreta){
    // completar

    return vector<EstadoLetra>();
}

string respuesta_en_string(const vector<EstadoLetra> & respuesta){
    // completar

    return "";
}
