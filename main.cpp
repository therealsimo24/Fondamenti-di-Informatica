/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 6 dicembre 2022, 10:01
 */

#include <iostream>

using namespace std;

struct record{
    int id;
    bool accensione;
    float livello;
};

typedef record domotica;

void verifica_dimensione(long int&);
void inserimento_caratteristiche(domotica*, long int);
void stampa(domotica *, long int);
void media_ill(domotica *, long int, float&);
void nuovovet(domotica *, long int, int &);


int main() {

    long int dim;
    domotica *illuminazione;
    float media = 0;
    int occ = 0;
    
    verifica_dimensione(dim);
    
    illuminazione = new (nothrow) domotica[dim];
    
    if (!illuminazione){
        
        cout << "Memoria non disponibile."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
    }
    
    inserimento_caratteristiche(illuminazione, dim);
    
    cout << "Ecco i punti di illuminazione inseriti:"<<endl;
    
    stampa(illuminazione, dim);
    
    media_ill(illuminazione, dim, media);
    
    stampa(illuminazione, dim);
    
    nuovovet(illuminazione, dim, occ);
    
    return 0;
}

void verifica_dimensione(long int &dim){
    
    do{
        
    cout << "Inserire il numero di punti di illuminazione presenti in casa: ";
    cin >> dim;
    
    if (dim <= 0){
        
        cout << "Errore! Il numero di punti di illuminazione deve essere maggiore di zero."<<endl;
        cout << "Riprovare l'inserimento..."<<endl;
        cout << endl;
    }
    
    }while(dim <=0);
    
}

void inserimento_caratteristiche(domotica* illuminazione, long int dim){
    
    cout << "Inserire le caratteristiche dei "<<dim<<" punti di illuminazione. (N.B. Accensione 0 = OFF, 1 = ON)"<<endl;
    
    for (int i = 0; i < dim; i++){
    
        cout << "Punto "<< i+1 <<":"<<endl;
        cout << "Id: ";
        cin >> (illuminazione + i)->id;
        cout << "Accensione: ";
        cin >> (illuminazione + i)->accensione;
        cout << "Livello: ";
        cin >> (illuminazione + i)->livello;
    
        cout << endl;
        
    }
    
}

void stampa(domotica * illuminazione, long int dim){
   
     cout << "Id:\tAccensione:\tLivello:"<<endl;
    for (int i = 0; i < dim; i ++){
        
        cout << (illuminazione + i)->id <<"\t     ";
        
        if ((illuminazione + i)->accensione == true){
            
            cout << "ON      ";
        }else{
            cout << "OFF";
            }
        
        cout <<"\t   "<<(illuminazione + i)->livello<<endl;
        
    }
}

void media_ill(domotica *illuminazione, long int dim, float& media){
    
    float sommatot = 0;

    for (int i = 0; i < dim; i++){
        
        sommatot = sommatot + (illuminazione + i)->livello;    
    
    }
    
    media = sommatot / (float)dim;
    
    cout << endl;
    
    cout << "Elenco dei punti di illuminazione accesi avente livello superiore o uguale alla media:"<<endl;
    
    for (int i = 0; i < dim; i ++){
        
        if ((illuminazione + i)->livello >= media && (illuminazione + i)->accensione == true){
            
            cout << (illuminazione +i)->id<<endl;
        }
    }
    
    cout << endl;
    
    cout << "Elenco aggiornato dopo lo spegnimento dei punti di illuminazione:"<<endl;
    
    for (int i = 0; i < dim; i ++){
        
        if ((illuminazione + i)->livello >= media && (illuminazione + i)->accensione == true){
            
            (illuminazione + i)->accensione = false;
            (illuminazione + i)->livello = 0;
            
        }
    }
    
}

void nuovovet(domotica * illuminazione, long int dim, int &occ){
    
    domotica * nuovovettore;
    
    for (int i = 0; i < dim; i ++){
        
        if ((illuminazione + i)->livello != 0 && (illuminazione + i)->accensione == false){
            
            occ++;
            
        }
    }
    
    nuovovettore = new domotica [occ];
    
    int k = 0;
    
    for (int i = 0; i < dim; i ++){
            
        if ((illuminazione + i)->livello != 0 && (illuminazione + i)->accensione == false){
            
           *(nuovovettore + k) = *(illuminazione + i);
           
           k++;
        }
        
    }
    
    cout << endl;
    
    cout << "Elenco materiali che necessitano riparazione: "<<endl;
    
    stampa(nuovovettore, occ);
    
}
