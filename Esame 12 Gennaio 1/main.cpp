

/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 13 dicembre 2022, 19:56
 */

#include <iostream>

using namespace std;

#define MAX 100

struct record{
    int id;
    int np;
    int nmp;
    float costo; 
};

typedef record spa;

void verifica_dimensioni(int &);
void riempimento(spa [], int );
void stampa(spa [], int );
void massimo(spa [], int );
void cancellazione(spa [], int &);    

int main() {

    spa furgoni[MAX];
    int dim;
    
    verifica_dimensioni(dim);
    
    riempimento(furgoni, dim);
    
    stampa(furgoni, dim);
    
    cout << endl;
    
    cout << "Elenco dei furgoni a massima efficienza: "<<endl;
    
    massimo(furgoni, dim);
    
    cout << endl;
    
    cout << "Elenco dei furgoni dopo la cancellazione dei furgoni che hanno terminato le consegne:"<<endl;
        
    cancellazione(furgoni, dim);
    
    stampa(furgoni, dim);
    
    return 0;
}

void verifica_dimensioni(int &dim){
    
    do {
        
        cout << "Inserire il numero di furgono attivi: ";
        
        cin >> dim;
        
        if(dim <= 0 || dim > MAX){
            
            cout << "Errore! Il numero di furgoni deve essere compreso nell'intervallo [1,"<<MAX<<"]."<<endl;
            cout << "Riprovare inserimento..."<<endl;
            cout << endl;
        }
        
    }while(dim <= 0 || dim > MAX);
        
}

void riempimento(spa furgoni[], int dim){
    
    for (int i = 0; i < dim; i ++){
        
        cout <<"Inserire l'id del furgone numero"<<i+1<<": ";
        cin >> furgoni[i].id;
        cout <<"Inserire il numero di pacchi da consegnare: ";
        cin >> furgoni[i].np;
        cout <<"Inserire il numero massimo di pacchi del furgone: ";
        cin >> furgoni[i].nmp;
        cout <<"Inserire il valore totale dei pacchi del furgone: ";
        cin >> furgoni[i].costo;
        
    }
}

void stampa(spa furgoni[], int dim){
    
    cout << "ID:  N. Pacchi:   N. M. Pacchi:   C. T. Pacchi:"<<endl;
    
    for(int i = 0; i < dim; i++){
        
        cout << furgoni[i].id <<"\t"<<furgoni[i].np<<"\t\t"<<furgoni[i].nmp<<"\t\t"<<furgoni[i].costo<<endl;
        
    }
    
}

void massimo(spa furgoni[], int dim){
    
    float max = 0;
    float differenza;
    
    for (int i = 0; i < dim; i ++){
        
        differenza = furgoni[i].nmp - furgoni[i].np;
        
        if(differenza > max){
            
            max = differenza;
            
        }
        
    }
    
    cout << "ID:  N. Pacchi:   N. M. Pacchi:   C. T. Pacchi:"<<endl;
    
    for (int i = 0; i < dim; i ++){
        
        differenza = furgoni[i].nmp - furgoni[i].np;
        
        if(differenza == max){
            
            cout << furgoni[i].id <<"\t"<<furgoni[i].np<<"\t\t"<<furgoni[i].nmp<<"\t\t"<<furgoni[i].costo<<endl;
            
        }
        
    }
    
}

void cancellazione(spa furgoni[], int &dim){
    
    for(int i = 0; i < dim; i++){
        
        if (furgoni[i].np == 0){
            
            dim--;
            
            for(int j = i; j < dim; j++){
                
                furgoni[j] = furgoni[j+1];
                
            }
            
            i--;
            
        }
    }
    
}
