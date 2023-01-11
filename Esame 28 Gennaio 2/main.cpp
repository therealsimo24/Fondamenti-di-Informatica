
/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 14 dicembre 2022, 18:38
 */


#include <iostream>
#include <fstream>
#include <math.h>
#include <limits.h>

using namespace std;

struct record{
    int base;
    int altezza;
};

typedef record rettangolo;

rettangolo * letturadafile(rettangolo *, long int &, short int&);
void stampa(rettangolo *, long int );
void rotazione(rettangolo *, long int );
rettangolo* rettangoli_temporanei(rettangolo* , long int &, long int &);

int main() {

    rettangolo * vettore;
    long int dim;
    short int esito = 0;
    long int dim2;
    
    vettore = letturadafile(vettore, dim, esito);
    
    if(esito == 1){
        
        cout <<"Errore! File non trovato."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
        
    }
    
    if(esito == 2){
        
        cout <<"Errore! Il vettore deve contenere almeno un elemento."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
        
    }
    
    if(esito == 3){
        
        cout <<"Errore! Memoria non disponibile."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
        
    }
    
    cout <<"Elenco dei rettangoli presenti nel vettore:"<<endl;
    
    stampa(vettore, dim);
    
    cout << endl;
    
    rotazione(vettore, dim);
    
    vettore = rettangoli_temporanei(vettore, dim, dim2);
    
    cout << endl;
    
    cout << "Elenco del vettore dopo l'aggiunta di rettangoli temporanei: "<<endl;
    
    stampa(vettore, dim2);
    
    return 0;
}

rettangolo * letturadafile(rettangolo *vettore, long int &dim, short int&esito){
    
    fstream file;
    rettangolo *vet;
    
    file.open("rettangoli.txt", ios::in);
    
    if(!file){
        
        esito = 1;
        
        return vet;
        
    }
    
    file >> dim;
    
    if(dim <= 0 || dim > 30){
        
        esito = 2;
        
        return vet;
        
    }
    
    vet = new (nothrow) rettangolo [dim];
    
    if(!vet){
        
        esito = 3;
        
        return vet;
        
    }
    
    for(int i = 0; i < dim; i++){
        
        file >> (vet + i)->base;
        file >> (vet + i)->altezza;
        
    }
    
    file.close();
    return vet;
}

void stampa(rettangolo *vettore, long int dim){
    
    cout << "  Base:\t     Altezza:"<<endl;
    
    for (int i = 0; i < dim; i ++){
        
        cout << "   "<<(vettore + i)->base<<"\t\t"<<(vettore + i)->altezza <<endl;
        
    }
}

void rotazione(rettangolo *vettore, long int dim){
    
    float rapporto;
    float max = INT_MIN;
    int temp;
    int pos;
    
    
    
    for(int i = 0; i < dim; i ++){
        
        rapporto = (float)(vettore + i)->base / (float)(vettore + i)->altezza;
        
        if(rapporto > max){
            
            max = rapporto;
            
        }
    }
    
    cout << "Il massimo del rapporto è: "<<max<<endl;
    
    for(int i = 0; i < dim; i ++){
        
        rapporto = (float)(vettore + i)->base / (float)(vettore + i)->altezza;
        
        if(rapporto == max){
            
            pos = i;
            
        }
    }
    
    cout << endl;
    
    temp = (vettore + pos)->base;
    
    (vettore + pos)->base = (vettore + pos)->altezza;
    
    (vettore + pos)->altezza = temp;
    
    cout << "Elenco del vettore dopo lo scambio: "<<endl;
    
    stampa(vettore, dim);
    
}

rettangolo* rettangoli_temporanei(rettangolo* vettore, long int & dim, long int & dim2){
    
    int occ = 0;
    rettangolo *nuovovet;
    int k = 0;
    
    
    for (int i = 0; i < dim; i++){
        
        
        if((vettore + i)->base == (vettore + i)->altezza){
            
            occ++;
            
        }
    }
    
    dim2 = dim + occ;
    
    nuovovet = new rettangolo[dim2];
    
    for (int i = 0, k = 0; i < dim2; i++, k++){
        
        *(nuovovet + k) = *(vettore + i);
        
        if((vettore + i)->base == (vettore + i)->altezza){
            
        k++;
            
        (nuovovet + k)->base = -1;
            
        (nuovovet + k)->altezza = -1;
        
             
        }
          
    }
    
    delete[] vettore;
    
    return nuovovet;
    
}