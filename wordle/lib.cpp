#include "lib.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

vector<string> cargar_listado(const string & nombre_archivo){
    /// CARGA EL ARCHIVO ///
    ifstream infile(nombre_archivo);    
    /// SI NO SE CARGO DE FORMA CORRECTA ///                                        
    if (infile.good() == false) {                                               
        cout << "No se pudo abrir el archivo " << nombre_archivo << endl;       
        exit(1);                                                                
    }                                                                   
    string line;               /// LINEAS DEL ARCHIVO                                                            
    vector<string> words;      /// VECTOR DE PALABRAS
    /// POR CADA LINEA DEL ARCHIVO ///
    while(!infile.eof()) {
            /// AGARRA LA LINEA Y SI NO ES VACIA LA AGREGA A WORDS ///
            getline(infile, line);  
            if(line.size() >0){                     
                words.push_back(line);
            }                       
    }
    infile.close();      
    return words;
}

bool intento_valido(const string & intento, const string & palabra_secreta, const vector<string> &listado){
    /// SI LA LONGITUD DE LA PALABRA INGRESADA NO ES CORRECTA ///
    if(intento.size() != palabra_secreta.size()){
        return false;
    }
    /// RECORRE EL VECTOR DE PALABRAS ///
    for(int i = 0; i < listado.size(); i++){
        /// SI SE ENCUENTRA LA PALABRA INGRESADA, ES VALIDA ///
        if(intento == listado[i]){
            return true;
        }
    }
    return false;
}

vector<EstadoLetra> evaluar_intento(const string & intento, const string & palabra_secreta){
    vector<EstadoLetra> res;
    for(int i = 0; i < palabra_secreta.size(); i++){
        /// SI LA LETRA ESTA EN LA POSICION CORRECTA ///
        if(intento[i] == palabra_secreta[i]){
            res.push_back(EstadoLetra::LugarCorrecto);
        }
        else{
            bool found = false;
            /// BUSCO LA LETRA EN EL RESTO DE LA PALABRA ///
            for(int j = 0; j < palabra_secreta.size(); j++){
                if(intento[i] == palabra_secreta[j]){
                    found = true;          
                }
            }
            /// SI LA ENCONTRE, ESTA EN LA POSICION INCORRECTA ///
            if(found){
                res.push_back(EstadoLetra::LugarIncorrecto);
            }
            /// SI NO LA ENCONTRE, NO ESTA PRESENTE ///
            else{
                res.push_back(EstadoLetra::NoPresente);
            }
        }
    }
    return res;
}

string respuesta_en_string(const vector<EstadoLetra> & respuesta){
    string str;
    /// RECORRO EL VECTOR DE ESTADOS ///
    for(int i = 0; i < respuesta.size(); i++){
        /// SI LA LETRA ESTA EN EL LUGAR CORRECTO, AGREGO '+' AL LA RESPUESTA ///
        if(respuesta[i] == EstadoLetra::LugarCorrecto){
            str.append("+");
        }
        /// SI LA LETRA ESTA EN EL LUGAR INCORRECTO, AGREGO '-' AL LA RESPUESTA ///
        else if(respuesta[i] == EstadoLetra::LugarIncorrecto){
            str.append("-");
        }
        /// SI LA LETRA NO ESTA PRESENTE, AGREGO 'X' AL LA RESPUESTA ///
        else{
            str.append("X");
        }
    }

    return str;
}
