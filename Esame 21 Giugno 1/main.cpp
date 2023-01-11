
/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 12 dicembre 2022, 10:24
 */

#include <iostream>
#include <fstream>

using namespace std;

struct record{
    float latox;
    float latoy;
    long int byte;
};

typedef record immagine;

immagine * letturadafile(long int &, short int &);
void stampa(immagine * , long int );
void ricercaimm(immagine *, long int , float );
void nuovovettore(immagine *, long int );

int main() {

    immagine * galleria;
    long int dim;
    short int esito = 0;
    float ricerca;
    
    
    galleria = letturadafile(dim, esito);
    
    if(esito == 1){
        
        cout << "Errore! File non trovato."<<endl;
        cout <<"Programma Terminato."<<endl;
        return -1;
        
    }
    
    if(esito == 2){
        
        cout << "Errore! Il vettore deve contenere almeno un elemento."<<endl;
        cout <<"Programma Terminato."<<endl;
        return -1;
        
    }
    
    if(esito == 3){
        
        cout << "Errore! Memoria non disponibile."<<endl;
        cout <<"Programma Terminato."<<endl;
        return -1;
        
    }
    
    cout << "Elenco delle immagini presenti in galleria: "<<endl;
    
    stampa(galleria, dim);
    
    cout << endl;
    
    cout << "Inserire la dimensione del Lato X da ricercare: ";
    
    cin >> ricerca;
    
    ricercaimm(galleria, dim, ricerca);
    
    cout << endl;
    
    cout << endl;
    
    cout << "Elenco delle immagini con densità sotto la media: "<<endl;
    
    nuovovettore(galleria, dim);
    
    
            
    return 0;
}

immagine * letturadafile(long int &dim, short int &esito){
    
    fstream file;
    immagine * vettore;
    
    
    file.open("immagini.txt", ios::in);
    
    if(!file){
        
        esito = 1;
        
        return vettore;
        
    }
    
    file >> dim;
    
    if(dim <= 0){
        
        esito = 2;
        
        return vettore;
        
    }
    
    vettore = new (nothrow) immagine [dim];
    
    if(!vettore){
        
        esito = 3;
        
        return vettore;
        
    }
    
    for (int i = 0; i < dim; i++){
        
        file >> (vettore + i)->latox;
        file >> (vettore + i)->latoy;
        file >> (vettore + i)->byte;
        
    }
    
    file.close();
    return vettore;
}

void stampa(immagine * galleria, long int dim){
    
    cout << "   X:   Y:   Byte: "<<endl;
    
    for (int i = 0; i < dim; i ++){
        
        cout << i + 1 <<": "<<(galleria + i)->latox<<"    "<<(galleria + i)->latoy <<"     "<<(galleria + i)->byte<<endl;
        
    }
}

void ricercaimm(immagine *galleria, long int dim, float ricerca){
    
    int counter = 0; 
    int k = 0;
    short int esito = 0;
    
    for (int i = 0; i < dim; i ++){
        
        if (ricerca == (galleria + i)->latox){
            
            esito = 1;
            
            counter++;
        }
    }
    
    if (esito == 0){
        
        cout << endl;
        
        cout << "Non sono presenti immagini aventi la dimensione X inserita."<<endl;
        
        
    }else{
        
        cout << endl;
        
        cout <<"Il numero di immagini avente la dimensione X inserita è "<< counter <<"."<<endl;
        
        if (counter == 1){
            
            cout <<"La posizione dell'immagine è: ";
            
        }else{
            
             cout <<"La posizione delle prime due immagini è: ";
             
        }
        
        
        for (int i = 0; i < dim; i ++){
            
            if (k < 2 && ricerca == (galleria + i)->latox){
                
                cout << i + 1 << "   ";
                
                k++;
                  
            }
        }
    }
    
}

void nuovovettore(immagine *galleria, long int dim){
    
    immagine *vettore;
    float media = 0;
    float sommatot = 0;
    float dens = 0;
    int occ = 0;
    int k = 0;
    
    for (int i = 0; i < dim; i ++){
        
        sommatot = sommatot + (((galleria + i)->byte) / ((galleria + i)->latox)*(((galleria + i)->latoy)));
       
    }
    
    media = sommatot / dim;
    
    for (int i = 0; i < dim; i ++){
        
        dens = ((galleria + i)->byte) / (((galleria + i)->latox)*(((galleria + i)->latoy)));
        
        if ( dens <= media){
            
            occ++;
                    
        }
    }
    
    vettore = new immagine [occ];
    
    for (int i = 0; i < dim; i ++){
        
        dens = ((galleria + i)->byte) / (((galleria + i)->latox)*(((galleria + i)->latoy)));
        
        if ( dens <= media){
            
            *(vettore + k) = *(galleria + i);
            
            k++;
                    
        }
    }
    
    stampa(vettore, occ);

}