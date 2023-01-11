
/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 7 dicembre 2022, 11:07
 */

#include <iostream>
#include <fstream>

using namespace std;

struct record{
    int ampiezza;
    int frequenza;
};

typedef record segnali;

#define MAX 30

segnali * verifica(long int &, bool &, bool &);
void stampa(segnali *, long int );
void vettore1(segnali *, long int);
void vettore2(segnali *, long int );
void ordinamento (segnali* , long int);


int main() {
    
    long int dim;
    segnali *oscilloscopio;
    bool esito1 = true;
    bool esito2 = true;
    
    oscilloscopio = verifica(dim, esito1, esito2);
    
    if (esito1 == false)
        return -1;
    
    if (esito2 == false)
        return -1;
    
    cout << "Ecco le caratteristiche dei segnali memorizzati nel file:"<<endl;
    
    stampa(oscilloscopio, dim);
    
    cout << endl;
        
    vettore1(oscilloscopio, dim);
    
    cout << endl;
    
    vettore2(oscilloscopio, dim);
    
    ordinamento(oscilloscopio, dim);
    
    cout << endl;
    
    cout << "Ecco i segnali ordinati in ordine crescente di frequenza:"<<endl;
    
    stampa(oscilloscopio, dim);
  
    return 0;
}

segnali * verifica(long int &dim, bool &esito1, bool &esito2){
    
    fstream file;
    segnali *vettore;
    
    file.open("segnali.txt", ios::in);
    
    if(!file){
       
        cout << "Errore! File non trovato."<<endl;
        cout << "Programma Terminato."<<endl;
        esito1 = false;
        
    }else{
    
    file >> dim;
   
    if (dim <= 0 || dim > 30){
        
        cout << "Errore! Il numero di segnali contenuti nel file deve essere compreso nell'intervallo [1, "<< MAX <<"]."<<endl;
        cout << "Programma Terminato."<<endl;
        esito2 = false;
       
    }
    
    vettore = new segnali[dim];
    
    for (int i = 0; i < dim; i ++){
        
        file >> (vettore + i)->ampiezza;
        file >> (vettore + i)->frequenza;
        
    }
   
    }
    
    file.close();
    
    return vettore;
   
}

void stampa(segnali *oscilloscopio, long int dim){
    
    cout << "Ampiezza: Frequenza:"<<endl;
    
    for (int i = 0; i < dim; i++){
        
        cout << "   " <<(oscilloscopio + i)->ampiezza << "\t       " <<(oscilloscopio + i)->frequenza<<endl;
        
    }
    
}

void vettore1(segnali *oscilloscopio, long int dim){
    
    float max = (oscilloscopio)->ampiezza;
    int counter = 0;
    segnali *v1;
    int k = 0;
    
    for (int i = 1; i < dim; i ++){
        
        if ((oscilloscopio + i)->ampiezza > max){
            
            max = (oscilloscopio + i)->ampiezza;
            
        }
        
    }
    
    for (int i = 0; i < dim; i ++){
        
        if ((oscilloscopio + i)->ampiezza == max){
            
            counter++;
            
        }
        
    }
    
    v1 = new segnali [counter];
    
    for (int i = 0; i < dim; i ++){
        
        if ((oscilloscopio + i)->ampiezza == max){
            
            *(v1 + k) = *(oscilloscopio + i);
            
            k++;
            
        }
        
    }
    
  
    
    cout << "Ecco i segnali a massima ampiezza: "<<endl;
    
    stampa(v1, counter);
    
}

void vettore2(segnali *oscilloscopio, long int dim){
    
    float max = (oscilloscopio)->frequenza;
    int counter = 0;
    segnali *v2;
    int k = 0;
    
    for (int i = 1; i < dim; i ++){
        
        if ((oscilloscopio + i)->frequenza > max){
            
            max = (oscilloscopio + i)->frequenza;
            
        }
        
    }
    
    for (int i = 0; i < dim; i ++){
        
        if ((oscilloscopio + i)->frequenza == max){
            
            counter++;
            
        }
        
    }
    
    v2 = new segnali [counter];
    
    for (int i = 0; i < dim; i ++){
        
        if ((oscilloscopio + i)->frequenza == max){
            
            *(v2 + k) = *(oscilloscopio + i);
            
            k++;
            
        }
        
    }
    
  
    
    cout << "Ecco i segnali a massima frequenza: "<<endl;
    
    stampa(v2, counter);
    
}

void ordinamento (segnali* oscilloscopio, long int dim){
    
    float min;
    int pos = 0;
    segnali temp;
    
    for (int i = 0; i < dim - 1; i++ ){
        
        min = (oscilloscopio + i)->frequenza;
     
        pos = i;
        
        for (int j = i + 1; j < dim - 1; j++){
            
            if ((oscilloscopio + j)->frequenza < min){
                
                min = (oscilloscopio + j)->frequenza;
                
                pos = j;
                
            }
        }
        
        if (i != pos){
            
            temp = *(oscilloscopio + i);
            
            *(oscilloscopio + i) = *(oscilloscopio + pos);
            
            *(oscilloscopio + pos) = temp;
        }
                    
    }
    
}