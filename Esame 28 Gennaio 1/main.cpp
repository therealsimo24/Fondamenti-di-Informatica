
/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 14 dicembre 2022, 15:51
 */

#include <iostream>
#include <fstream>
#include <limits.h>

using namespace std;

struct record{
    int temperatura;
    int pressione;
};

typedef record segnali;

segnali *letturadafile(long int&, short int&);
void stampa(segnali *, long int );
void ricerca_pressione(segnali *, long int , int &);
void nuovovett(segnali *, long int );

int main() {

    long int dim;
    short int esito = 0;
    segnali *oscillo;
    int pressione;
 
    
    oscillo = letturadafile(dim, esito);
    
    if (esito == 1){
        
        cout << "Errore! File non trovato."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
        
    }
    
    if (esito == 2){
        
        cout << "Errore! La libreria deve contenere almeno un libro."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
        
    }
    
    if (esito == 3){
        
        cout << "Errore! Memoria non disponibile."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
        
    }
    
    cout << "Elenco dei segnali misurati dall'oscilloscopio: "<<endl;
    
    stampa(oscillo, dim);
    
    cout << endl;
    
    cout << "Inserire il valore della pressione da ricercare: ";
    
    ricerca_pressione(oscillo, dim, pressione);
    
    nuovovett(oscillo, dim);
    
    return 0;
}

segnali *letturadafile(long int& dim, short int&esito){
    
    fstream file;
    segnali *vettore;
    
    file.open("segnali.txt", ios::in);
    
    if(!file){
        
        esito = 1;
        
        return vettore;
        
    }
    
    file >> dim;
    
    if(dim <= 0){
        
        esito = 2;
        
        return vettore;
        
    }
    
    vettore = new (nothrow) segnali [dim];
    
    if(!vettore){
        
        esito = 3;
        
        return vettore;
        
    }
    
    for (int i = 0; i < dim; i ++){
        
        file >> (vettore + i)->temperatura;
        file >> (vettore + i)->pressione; 
        
    }

    file.close();
    
    return vettore;     
}

void stampa(segnali *oscillo, long int dim){
    
    cout << "Temperatura:    Pressione:"<<endl;
    
    for (int i = 0; i < dim; i ++){
        
        cout << "    "<<(oscillo + i)->temperatura<<"°\t\t  "<<(oscillo + i)->pressione<<"Pa"<<endl;
        
    }
}

void ricerca_pressione(segnali *oscillo, long int dim, int &pressione){
    
    cin >> pressione;
    int occ = 0;
    int pos;
    
    for(int i = 0; i < dim; i ++){
        
        if ((oscillo + i)->pressione == pressione){
            
            occ++;
            
        }
    }
    
    if(occ == 0){
        
        cout << endl;
        
        cout << "Non è stato trovato nessun valore corrispondente."<<endl;
        
    }else{
        
    for(int i = 0; i < dim; i ++){
        
        if ((oscillo + i)->pressione == pressione){
            
            pos = i;
            
        }
        
    }
    
    cout << endl;
    
    cout << "Il primo segnale che soddisfa tale ricerca è il segnale di posizione "<<pos + 1<<"."<<endl;
    
    cout << "Temperatura:    Pressione:"<<endl;
    
    cout << "    "<<(oscillo + pos)->temperatura<<"°\t\t  "<<(oscillo + pos)->pressione<<"Pa"<<endl;
        
        
    }
    
}

void nuovovett(segnali *oscillo, long int dim){
    
    float min = INT_MAX;
    float resa;
    int occ = 0;
    segnali * segnali_minimo_rapporto;
    int k = 0;
    
    for(int i = 0; i < dim; i++){
      
        resa = (float)(oscillo + i)->temperatura / (float)(oscillo + i)->pressione;
        
        if (resa < min){
            
            min = resa;
            
        }
        
    }
    
    
   for(int i = 0; i < dim; i++){
      
        resa = (float)(oscillo + i)->temperatura / (float)(oscillo + i)->pressione;
        
        if (resa == min){
            
            occ++;
            
        }
        
    }
    
    segnali_minimo_rapporto = new segnali [occ];
    
    for(int i = 0; i < dim; i++){
      
        resa = (float)(oscillo + i)->temperatura / (float)(oscillo + i)->pressione;
        
        if (resa == min){
            
            *(segnali_minimo_rapporto + k) = *(oscillo + i);
            
            k++;
            
        }
        
    }
    
    cout << endl;
    
    cout << "Elenco del vettore contente i segnali a minimo rapporto: "<<endl;
    
    stampa(segnali_minimo_rapporto, occ);
    
    
}
