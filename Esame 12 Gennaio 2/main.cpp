
/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 14 dicembre 2022, 11:12
 */

#include <iostream>

using namespace std;

#define MAX 100

struct record{
    int id;
    int nap;
    int cap;
    float costo;
};

typedef record macchina;

void verifica_dimensione(macchina [], int &);
void inserimento(macchina [], int );
void stampa(macchina [], int );
void ordinamento(macchina [], int );
void inserimento(macchina [], int &, macchina );

int main() {

    macchina parcheggio[MAX];
    int dim;
    macchina pn;
    
    verifica_dimensione(parcheggio, dim);
    
    cout << "Inserire i vari campi dei parcheggi presenti: "<<endl;
    
    inserimento(parcheggio, dim);
    
    cout << endl;
    
    cout << "Elenco dei parcheggi inseriti: "<<endl;
    
    stampa(parcheggio, dim);
    
    ordinamento(parcheggio, dim);
    
    cout << endl;
    
    cout << "Elenco dei parcheggi per ricavo: "<<endl;
    
    stampa(parcheggio, dim);
    

    cout << "\nInserire i dati nel nuovo parcheggio: ";
    
    cout << "Inserire l'identificativo: ";
    cin >> pn.id;
    cout << "Inserire il numero di autovetture parcheggiate: ";
    cin >> pn.nap;
    cout << "Inserire la capacità massima: ";
    cin >> pn.cap;
    cout << "Inserire il costo orario per autovettura: ";
    cin >> pn.costo;
    
    inserimento(parcheggio, dim, pn);
    
    cout << endl;
    
    cout << "Elenco dei parcheggi dopo l'aggiunta: "<<endl;
    
    stampa(parcheggio, dim);
    
    return 0;
}

void verifica_dimensione(macchina parcheggio[], int &dim){
    
    do{
        
        cout << "Inserire il numero di auto presenti nel parcheggio: ";
        
        cin >> dim;
        
        if(dim < 1 || dim > 99){
            
            cout << endl;
            
            cout << "Errore! Il numero di auto deve essere compreso nell'intervallo [1, 99]"<<endl;
            
            cout << "Riprovare inserimento..."<<endl;
            
            cout << endl;
        } 
        
    }while(dim < 1 || dim > 99);
    
}

void inserimento(macchina parcheggio[], int dim){
    
    for (int i = 0; i < dim; i ++){
        
        cout << "Inserire l'identificativo del parcheggio numero "<<i+1<<": ";
        cin >> parcheggio[i].id;
        cout << "Inserire il numero di autovetture parcheggiate: ";
        cin >> parcheggio[i].nap;
        cout << "Inserire la capacità massima: ";
        cin >> parcheggio[i].cap;
        cout << "Inserire il costo orario per autovettura: ";
        cin >> parcheggio[i].costo;
        
    }
    
}

void stampa(macchina parcheggio[], int dim){
    
     cout << "ID:  N. Auto:   Capacità M.:   Costo Orario:"<<endl;
    
    for(int i = 0; i < dim; i++){
        
        cout << parcheggio[i].id <<"\t"<<parcheggio[i].nap<<"\t    "<<parcheggio[i].cap<<"\t\t     "<<parcheggio[i].costo<<endl;
        
    }
}

void ordinamento(macchina parcheggio[], int dim){
    
    float min;
    int pos = 0;
    float ricavo;
    macchina temp;
    
    for(int i = 0; i < dim; i++){
        
        ricavo = parcheggio[i].nap * parcheggio[i].costo;
        
        min = ricavo;
        
        pos = i;
        
        for(int j = i + 1; j < dim; j++){
            
            ricavo = parcheggio[j].nap * parcheggio[j].costo;
            
            if( ricavo < min){
                
                min = ricavo;
                
                pos = j;
            }
        }
        
        if(i != pos){
            
            temp = parcheggio[i];
            
            parcheggio[i] = parcheggio[pos];
            
            parcheggio[pos] = temp;
           
            
        }
        
    }
    
}

void inserimento(macchina parcheggio[], int &dim, macchina pn){
    
    float min = 999;
    int pos = 0;
    
    for (int i = 1; i < dim; i++){
        
        if (parcheggio[i].cap < min){
            
            min = parcheggio[i].cap;
            
            pos = i;
            
        }
        
    }
    
    dim ++;
    
    for(int i = dim - 1; i > pos + 1; i --){
        
        parcheggio[i] = parcheggio[i - 1];
        
    }
    
    parcheggio[pos + 1] = pn;
    
}


