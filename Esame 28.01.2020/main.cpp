
/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 27 novembre 2022, 19:33
 */

#include <iostream>
#include <stddef.h>


using namespace std;

struct record{
    float base;
    float altezza;
};

typedef record rettangolo;

void verifica_dimensioni_array (long int &);
void inserimento_rettangoli (long int &, rettangolo *);
void stampa_rettangoli_inseriti (long int, rettangolo *);
void dimensione_vettore_pivot (long int, long int &, rettangolo *, double &, double &);
bool vettore_pivot(long int, long int, rettangolo *, rettangolo *, double &);
bool verifica_ordinamento (rettangolo *, int);


int main() {
    
    long int numr;
    float base = 0;
    float altezza = 0;
    rettangolo *arrayr;
    rettangolo *pivot;
    long int numrp = 0;
    double areap = 0;
    double area = 0;
    bool esito;
    bool crescente;
    
    verifica_dimensioni_array (numr);
    
    arrayr = new (nothrow) rettangolo [numr]; 
    
    if (!arrayr){
        cout << "Memoria non disponibile."<<endl;
        cout << "Programma terminato.";
        return -1;
    }
    
    inserimento_rettangoli (numr, arrayr);
    
    cout << "Segue la lista dei rettangoli memorizzati: "<<endl;
    
    stampa_rettangoli_inseriti (numr, arrayr);
    
    dimensione_vettore_pivot (numr, numrp, arrayr, areap, area);
    
    pivot = new (nothrow) rettangolo [numrp]; 
    
    esito = vettore_pivot(numr, numrp, arrayr, pivot, areap);
    
    if(esito == 1){
        return -1;
    }else{
       
     if (numrp != 0){
        cout << "Ecco i rettangoli con area inferiore a quella inserita: "<<endl;
        stampa_rettangoli_inseriti (numrp, pivot);
    }
    
    crescente= verifica_ordinamento (arrayr, numr);
    if (crescente == true){
        cout << "Il vettore iniziale è ordinato in ordine crescente";
    }else{
        cout << "Il vettore iniziale non è ordinato in ordine crescente";
    }
    
    }
    
    
    return 0;
}

void verifica_dimensioni_array (long int &numr){
    //VERIFICA DELLE DIMENSIONI DELL'ARRAY
    do{
        cout << "Inserire il numero di rettangoli del vettore: ";
        cin >> numr;
        
        cout<<endl;
        if(numr <= 0){
            cout << "Errore! Il numero di rettangoli deve essere almeno maggiore di 0.";
            cout << "\nRiprovare l'inserimento..."<<endl;
        }
        
    }while(numr <= 0);
    
}

void inserimento_rettangoli (long int &numr, rettangolo *arrayr){
        
        cout << "Inserire le dimensioni dei "<< numr <<" rettangoli. "<<endl;
        for ( int i = 0; i < numr; i++){
            
        
        cout << "Inserire le dimensioni del rettangolo numero "<< i+1 <<": "<<endl;
        cout << "Base: ";
        cin >> (arrayr+i)->base;
        cout << "Altezza: ";
        cin >> (arrayr+i)->altezza;
        cout << endl;
        }
}

void stampa_rettangoli_inseriti (long int numr, rettangolo *arrayr){
    
    for (int i = 0; i < numr; i++){
        cout << "Rettangolo "<< i+1 <<": [B = "<<(arrayr+i)->base<<", H = "<< (arrayr + i)->altezza<<"]"<<endl;
    }
}


void dimensione_vettore_pivot (long int numr, long int &numrp, rettangolo *arrayr, double &areap, double &area){
    
    do{
   
    cout << "Inserire il valore di un'area pivot: ";
    cin >> areap;
    
    if (areap <= 0){
        
        cout << "Errore! Il valore dell'area deve essere almeno maggiore di 0.";
        cout << "\nRiprovare l'inserimento..."<<endl;
    }
    
    }while (areap <= 0);
    
    for (int i = 0; i < numr; i++){
        area = (arrayr+i)->base * (arrayr+i)->altezza;
        
        if (area < areap){
            numrp++;
        }
    }
    
}

bool vettore_pivot(long int numr, long int numrp, rettangolo *arrayr, rettangolo *pivot, double &areap){
  
    double area;
    
     if (numrp != 0){  
        
        for (int i = 0; i < numr; i++){
            
        area = (arrayr->base)*(arrayr->altezza);
        
        if (area < areap){
            
            pivot->base = arrayr->base;
            pivot->altezza = arrayr->altezza;
         
            pivot++;
        }
        
        arrayr++;
        
        }
       
        return 0;
    }else{
       cout<<"Non è presente nessun rettangolo avente area minore all'area pivot inserita.";
       return -1;
    }
}



bool verifica_ordinamento (rettangolo *arrayr, int numr){
    
    double base1 = arrayr->base; 
    double base2 = (arrayr+1)->base;
    
    
    cout << base1<<endl;
    cout << base2<<endl;
    
    for (int i = 0; i < numr; i++){
        
    if ((base1+i) < (base2+i)){
        return true;
    }else{
        return false;
    }
    
    }
    
}


    













