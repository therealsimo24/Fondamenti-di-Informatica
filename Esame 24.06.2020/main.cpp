
/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 30 novembre 2022, 14:19
 */

#include <iostream>
#include <string.h>

using namespace std;

#define L 6

typedef char stringa[L];

struct record{
    stringa comando;
    long int input;
    long int output;
};

typedef record codici;

void verifica_dimensioni(long int &);
void inserimento_valori(codici *, long int);
void stampa_valori(codici *, long int);
int ricerca_valori_minimo(codici *,long int);
int ricerca_valori_massimo(codici *, long int);
void conta_occorrenze(codici *, int *, long int);


int main() {
    
    long int dim;
    codici *assembly;
    int posmin;
    int posmax;
   
    
    
    //VERIFICA DIMENSIONE DELL'ARRAY
    
    verifica_dimensioni(dim);
    
    //CREAZIONE DELL'ARRAY DIMANICO
    
    assembly = new (nothrow) codici [dim];
    
    if(!assembly){
        cout << "Errore! Memoria non disponibile."<<endl;
        cout << "Programma Terminato.";
        return -1;
    }
    
    
    //INSERIMENTO DEI VALORI NELL'ARRAY
    
    cout << "Inserire i vari parametri dei codici operativi:"<< endl;
    
    inserimento_valori(assembly, dim);
    
    //STAMPA DEI VALORI DELL'ARRAY
    
    cout << "Ecco i parametri dei codici operativi inseriti:"<<endl;
    
    stampa_valori(assembly, dim);
    
    //RICERCA VALORE MINIMO
    
    posmin = ricerca_valori_minimo(assembly, dim);
    
    cout << "Il valore che accede alla minima locazione di output è '" << (assembly+posmin)->comando << "'"<<endl;
    
    //RICERCA VALORE MASSIMO
    
    posmax = ricerca_valori_massimo(assembly, dim);
    
    cout << "Il valore che accede alla massima locazione di output è '" << (assembly+posmax)->comando << "'"<<endl;
    
    //VALUTAZIONE OCCORRENZE
    
    int *occorrenze;
    
    occorrenze = new (nothrow) int [dim];
    
    conta_occorrenze(assembly, occorrenze, dim);
    
    for (int i = 0; i < dim; i++){
        
    cout << "Il numero di occorrenze di '"<< (assembly+i)->comando << "' è "<< *(occorrenze + i)<<"."<<endl;
    
    }
    
    return 0;
}

void verifica_dimensioni(long int &dim){
    
    do{
        
    cout << "Inserire il numero di codici operativi memorizzati: ";
    cin >> dim;
    
    if( dim <= 0){
        
        cout << "Errore! Il numero di codici operativi deve essere almeno maggiore di zero."<<endl;
        cout << "Riprovare l'inserimento..."<<endl;
        cout << endl;
        
    }
    
    }while( dim <= 0);
    
}

void inserimento_valori(codici *assembly, long int dim){
    
    for (int i = 0; i < dim; i++){
        cout << "Inserire parametri del codice numero "<< i + 1<<":"<< endl;
        cout << "Comando: ";
        cin >> (assembly + i)->comando;
        cout << "Input: ";
        cin >> (assembly + i)->input;
        cout << "Output: ";
        cin >> (assembly + i)->output;
    }
    
}

void stampa_valori(codici *assembly, long int dim){
    
    for (int i = 0; i < dim; i++){
       
    cout << "Comando: "<< (assembly + i)->comando <<"\tInput: "<< (assembly + i)->input <<"\tOutput: "<< (assembly + i)->output << endl;
            
    }
}

int ricerca_valori_minimo(codici *assembly, long int dim){
    
    int min = assembly->output;
    int pos = 0;
    
    for (int i = 0; i < dim; i++){
        
        if (min > (assembly + i)->output){
            
            min = (assembly + i)->output;
            pos = i;
        }
        
    }
    
    return pos;
}

int ricerca_valori_massimo(codici *assembly, long int dim){
    
    int max = assembly->output;
    int pos = 0;
    
    for (int i = 0; i < dim; i++){
        
        if (max < (assembly + i)->output){
            
            max = (assembly + i)->output;
            pos = i;
        }
        
    }
    
    return pos;
}

void conta_occorrenze(codici *assembly, int *occorrenze, long int dim){
    
    int counter;
    
    for (int i = 0; i < dim; i++){
        
        counter = 0;
        
        for (int j = 0; j < dim; j++){
            
            if (strcmp((assembly+i)->comando, (assembly+j)->comando) == 0){
            
            counter++;
            
        }
            
            *(occorrenze+i) = counter;
            
        } 
        
            
    }
    
}
