
/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 9 dicembre 2022, 16:52
 */

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

#define L 16
#define MAX 30

typedef char stringa[L];

struct record{
    float longitudine;
    float latitudine;
    bool polarizzazione;
    stringa operatore;
};

typedef record ripetitori;

ripetitori * letturadafile(ripetitori *, int &, short int &);
void stampa(ripetitori* , int );
void distanza(ripetitori* , int );
ripetitori * eliminazione(ripetitori *, int, int&);


int main() {

    int dim;
    short int esito = 0;
    ripetitori *tv;
    int occ = 0;
    
    tv = letturadafile(tv, dim, esito);
    
    if(esito == 1){
        
        cout << "Errore! File non trovato."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
        
    }
    
    if(esito == 2){
        
        cout << "Errore! La dimensione del vettore deve essere compresa nell'intervallo [1, "<< MAX <<"]"<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
        
    }
  
    cout << "Elenco dei ripetitori tv:"<<endl;
    
    stampa(tv, dim);
    
    distanza(tv, dim);
    
    tv = eliminazione(tv, dim, occ);
    
    cout << endl;
    
    cout << "Elenco dei ripetitori con polarizzazione verticale:"<<endl;
    
    stampa(tv, occ);
    
    return 0;
}

ripetitori * letturadafile(ripetitori * tv, int &dim, short int &esito){
    
    fstream file;
    ripetitori *vettore;
    
    file.open("ripetitori.txt", ios::in);
    
    if(!file){
        
        esito = 1;
        
        return vettore;
        
    }
    
    file >> dim;
    
    if (dim <= 0 || dim > MAX){
        
        esito = 2;
        
        return vettore;
        
    }
    
    vettore = new ripetitori [dim];
    
    for (int i = 0; i < dim; i ++){
        
        file >> (vettore + i)->latitudine;
        file >> (vettore + i)->longitudine;
        file >> (vettore + i)->polarizzazione;
        file >> (vettore + i)->operatore;
        
    }
    
    file.close();
    
    return vettore;
}

void stampa(ripetitori* tv, int dim){
    
    cout << "Latitudine:  Longitudine:  Polarizzazione:   Operatore:"<<endl;
    
    for (int i = 0; i < dim; i++){
        
        cout <<"  "<<(tv + i)->longitudine <<"\t\t"<< (tv + i)->latitudine <<"\t    ";
        
        if ((tv + i)->polarizzazione == 1){
            
            cout << "Verticale";
            
        }else{
            
            cout << "Orizzontale";
            
        }
     
        cout<<"\t\t"<< (tv + i)->operatore <<endl;
        
    }
    
    cout << endl;
}

void distanza(ripetitori* tv, int dim){
    
    float latitudine = 0;
    float longitudine = 0;
    stringa operatore = "";
    double dist = 0;
    double distmin = 9999;
    int pos = -1;
    
    
    cout << "Inserire la propria posizione e il nome dell'operatore da ricercare: "<<endl;
    cout << "Latitudine: ";
    cin >> latitudine;
    cout << "Longitudine: ";
    cin >> longitudine;
    cout << "Operatore: ";
    cin >> operatore;
    
   
    for (int i = 0; i < dim; i++){
        
        if (strcmp(operatore, (tv + i)->operatore) == 0){
            
            dist = sqrt(pow(latitudine - ((tv + i)->latitudine), 2) + pow(longitudine - ((tv + i)->longitudine), 2));
            
            if (dist < distmin){
                
                distmin = dist;
                
                pos = i;
                
            }
            
        }
        
    }
    
    if (pos == -1){
        
        cout << endl;
        cout << "Nessun ripetitore nelle vicinanze trovato per "<< operatore <<"."<<endl;
    
    }else{
        
    cout << endl;
    
    cout << "Il ripetitore più vicino di "<< operatore << " è: "<<endl;
    
    cout << "Latitudine:  Longitudine:  Polarizzazione:   Operatore:"<<endl;
   
        cout <<"  "<<(tv + pos)->longitudine <<"\t\t"<< (tv + pos)->latitudine <<"\t    ";
        
        if ((tv + pos)->polarizzazione == 1){
            
            cout << "Verticale";
            
        }else{
            
            cout << "Orizzontale";
            
        }
     
        cout<<"\t\t"<< (tv + pos)->operatore <<endl;
        
    }
    
}

ripetitori * eliminazione(ripetitori *tv, int dim, int &occ){
    
    ripetitori * vettore;
    int k = 0;
    
    for (int i = 0; i < dim; i ++){
        
        if ((tv + i)->polarizzazione == 1){
            
            occ++;
            
        }
        
    }
    
    vettore = new ripetitori [occ];
    
    for (int i = 0; i < dim; i ++){
        
        if ((tv + i)->polarizzazione == 1){
            
            *(vettore + k) = *(tv + i);
            
            k++;
            
        }
        
    }
    
    delete []tv;
    
    return vettore;
   
}

