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
    if (words.size() == 1 && words[0].size() == 0){
        return vector<string>();
    }
    return words;
}

bool intento_valido(const string & intento, const string & palabra_secreta, const vector<string> &listado){
    if(intento.size() != palabra_secreta.size()){
        return false;
    }
    for(int i = 0; i < listado.size(); i++){
        if(intento == listado[i]){
            return true;
        }
    }
    return false;
}

vector<EstadoLetra> evaluar_intento(const string & intento, const string & palabra_secreta){
    vector<EstadoLetra> res;
    for(int i = 0; i < palabra_secreta.size(); i++){
        if(intento[i] == palabra_secreta[i]){
            res.push_back(EstadoLetra::LugarCorrecto);
        }
        else{
            bool found = false;
            for(int j = 0; j < palabra_secreta.size(); j++){
                if(intento[i] == palabra_secreta[j]){
                    found = true;          
                }
            }
            if(found){
                res.push_back(EstadoLetra::LugarIncorrecto);
            }
            else{
                res.push_back(EstadoLetra::NoPresente);
            }
        }
    }

    return res;
}

string respuesta_en_string(const vector<EstadoLetra> & respuesta){
    string str;
    for(int i = 0; i < respuesta.size(); i++){
        if(respuesta[i] == EstadoLetra::LugarCorrecto){
            str.append("+");
        }
        else if(respuesta[i] == EstadoLetra::LugarIncorrecto){
            str.append("-");
        }
        else{
            str.append("X");
        }
    }

    return str;
}
