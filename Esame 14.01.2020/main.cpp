
/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 25 novembre 2022, 20:39
 */

#include <iostream>

using namespace std;

struct record{
    int id;
    float dimX;
    float dimY;
    long int bytes;
};

typedef record immagine;

void inserimento_immagini(int &);
void inserimento_caratteristiche(immagine [], int);
void stampa_caratteristiche(immagine [], int);
void rotazione_immagine(immagine [], int);
void duplicazione_immagini(immagine [], immagine [], int);

#define MAXDIM 20

int main() {

    immagine vet[MAXDIM];
    immagine vetc[MAXDIM*2];
    int maxpng;
    
    inserimento_immagini(maxpng);
    inserimento_caratteristiche(vet, maxpng);
    stampa_caratteristiche(vet, maxpng);
    rotazione_immagine(vet, maxpng);
    duplicazione_immagini(vet, vetc, maxpng);
    
    return 0;
}

//INSERIMENTO NUMERO IMMAGINI PRESENTI SUL DISCO
void inserimento_immagini(int &maxpng){
    
    do{
       cout<< "Inserire il numero di immagini presenti sul disco: ";
       cin >> maxpng;
       cout << endl;
    
    if (maxpng < 1 || maxpng > 20){
        cout << "Errore!"<<endl;
        cout << "Il numero di immagini da memorizzare deve essere compreso nell'intervallo [1,"<< MAXDIM <<"] "<<endl;
        cout << endl;
    }
    
    }while (maxpng < 1 || maxpng > 20);
    
}

//INSERIMENTO DELLE CARATTERISTICHE DELL'IMMAGINE 
void inserimento_caratteristiche(immagine vet[], int maxpng){
    
    for (int i = 0; i < maxpng; i++){
        cout <<"Inserire l'id dell'immagine di posizione "<< char(65+i)<<": ";
        cin >> vet[i].id;
        cout <<"Inserire la dimensione X dell'immagine di posizione "<< char(65+i)<<": ";
        cin >> vet[i].dimX;
        cout <<"Inserire la dimensione Y dell'immagine di posizione "<< char(65+i)<<": ";
        cin >> vet[i].dimY;
        cout <<"Inserire il numero di bytes dell'immagine di posizione "<< char(65+i)<<": ";
        cin >> vet[i].bytes;
        
        cout<<endl;
    }
}

//STAMPA DELLE CARATTERISTICHE DELLL'IMMAGINE
void stampa_caratteristiche(immagine vet[], int maxpng){
    
    cout << "Le immagini memorizzate nel disco sono: "<<endl;
    
    for (int i = 0; i < maxpng; i++){
        
        cout << char(65+i) <<" = ("<<vet[i].id<<", "<<vet[i].dimX<<", "<<vet[i].dimY<<", "<<vet[i].bytes<<") "<<endl;
         
    }
}

//RICERCA DELLA DIMENSIONE MASSIMA NELL'ARRAY
//ROTAZIONE DELL'IMMAGINE DI DIMENSIONI MAGGIORI
void rotazione_immagine(immagine vet[], int maxpng){
    int pos = 0;
    float vtemp;
    float dmax = 0;
    
    //ALGORITMO DI RICERCA DEL MASSIMO IN UN ARRAY
    dmax = vet[0].bytes;
    for (int i = 0; i < maxpng; i++){
        
        if (vet[i].bytes > dmax ){
            dmax = vet[i].bytes;
            pos = i;
        }
    }
    
    //SCAMBIO DEI VALORI 
    vtemp = vet[pos].dimX;
    vet[pos].dimX = vet[pos].dimY;
    vet[pos].dimY = vtemp;
    
    //STAMPA DEL NUOVO STATO DELLA MEMORIA
    cout << "Ruotando l'immagine di posizione "<< char(65+pos) <<" si ottiene la seguente configurazione:"<<endl;
    for (int i = 0; i < maxpng; i++){
        
        cout << char(65+i) <<" = ("<<vet[i].id<<", "<<vet[i].dimX<<", "<<vet[i].dimY<<", "<<vet[i].bytes<<") "<<endl;
         
    }
   
}

void duplicazione_immagini(immagine vet[], immagine vetc[], int maxpng){
    
    for (int i = 0; i < maxpng; i++){
        vetc[i] = vet[i];
    }
    
    for (int i = 0; i < maxpng*2; i++){
        vetc[maxpng +i]= vet[i];
    }
    
    cout << "Dopo la duplicazione ecco il nuovo vettore ottenuto: "<<endl;
     for (int i = 0; i < maxpng*2; i++){
        
        cout << char(65+i) <<" = ("<<vetc[i].id<<", "<<vetc[i].dimX<<", "<<vetc[i].dimY<<", "<<vetc[i].bytes<<") "<<endl;
         
    }
}