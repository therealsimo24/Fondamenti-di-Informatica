/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 11 dicembre 2022, 14:46
 */

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

#define L 16

typedef char stringa[L];

struct record{
    stringa titolo;
    float prezzo;
    int pagine;
};

typedef record libri;

libri *letturadafile(long int& , short int&);
void stampa(libri *, long int );
void verifica(libri *, long int , stringa &, short int&);
void ricerca(libri *, long int , stringa );
void nuovo(libri *, long int );
    
int main() {

    long int dim;
    short int esito = 0;
    libri *libreria;
    stringa nome = "";
    short int esito1 = 0;
    
    libreria = letturadafile(dim, esito);
    
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
    
    cout << "Elenco dei libri presenti in libreria: "<<endl;
    
    stampa(libreria, dim);
    
    cout << endl;
    
    cout << "Inserire il titolo del libro da ricercare: ";
    
    verifica(libreria, dim, nome, esito1);
    
    cout << endl;
    
    if(esito1 == 0){
        
        cout << "In libreria non è presente nessun libro con il titolo '"<<nome<<"'."<<endl;
        
    }else{
    
    ricerca(libreria, dim, nome);
    
    }
    
    nuovo(libreria, dim);
    
    return 0;
}

libri *letturadafile(long int& dim, short int&esito){
    
    fstream file;
    libri *vettore;
    
    file.open("copie.txt", ios::in);
    
    if(!file){
        
        esito = 1;
        
        return vettore;
        
    }
    
    file >> dim;
    
    if(dim <= 0){
        
        esito = 2;
        
        return vettore;
        
    }
    
    vettore = new (nothrow) libri [dim];
    
    if(!vettore){
        
        esito = 3;
        
        return vettore;
        
    }
    
    for (int i = 0; i < dim; i ++){
        
        file >> (vettore + i)->titolo;
        file >> (vettore + i)->prezzo;
        file >> (vettore + i)->pagine;
        
    }
    
    file.close();
    
    return vettore;     
}

void stampa(libri *libreria, long int dim){
    
    cout << "  Titolo:    Prezzo:  Pagine:"<<endl;
    
    for (int i = 0; i < dim; i ++){
        
        cout << "  "<<(libreria + i)->titolo<<"  \t"<<(libreria + i)->prezzo<<"€"<<"\t"<< (libreria + i)->pagine<<endl;
        
    }
}

void verifica(libri *libreria, long int dim, stringa &nome, short int&esito1){
    
    cin >> nome;
    
    for (int i = 0; i < dim; i ++){
        
    if (strcmp((libreria + i)->titolo, nome) == 0){
        
        esito1 = 1;
        
    }
    
    }
    
}

void ricerca(libri *libreria, long int dim, stringa nome){
    
    float min = 99999.9999;
    int occ = 0;
    
    for (int i = 0; i < dim; i ++){
        
        if (strcmp((libreria + i)->titolo, nome) == 0 && (libreria + i)->prezzo < min){
            
            min = (libreria + i)->prezzo;
            
        }
    }
    
    for (int i = 0; i < dim; i ++){
        
        if (strcmp((libreria + i)->titolo, nome) == 0 && (libreria + i)->prezzo == min){
            
            occ++;
            
        }
    }
    
    cout << endl;
    cout <<"Il numero delle copie a prezzo minimo per il titolo cercato è "<< occ <<"."<<endl;
    cout << "Il prezzo minimo della copia è "<< min <<"."<<endl;
    
}

void nuovo(libri *libreria, long int dim){
    
    libri *carrello;
    float sommatot = 0;
    int occ = 0;
    int k = 0;
    
    
    while(sommatot <= 100 && occ < dim){
        
        sommatot = sommatot + (libreria + occ)->prezzo;
        
        occ++;
        
        if (sommatot > 100){
            
            occ--;
            
        }
        
    }
    
    
    carrello = new libri[occ];
    
    for (int i = 0; i < occ; i ++){
        
        *(carrello + k) = *(libreria + i);
        
        k++;
        
    }
       
    cout << endl;
    
    cout << "Elenco dei libri presenti nel carrello: "<<endl;
    
    stampa(carrello, occ);
    
}
