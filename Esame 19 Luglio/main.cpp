
/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 12 dicembre 2022, 17:06
 */

#include <iostream>
#include <fstream>

using namespace std;

struct record{
    int id;
    float kwh;
    bool funzione;
};

typedef record traliccio;

traliccio *letturadafile(long int& , short int&);
void stampa (traliccio * , long int );
void maxmintralicci(traliccio *, long int );
void tralicciattivi(traliccio * , traliccio *, long int );


int main() {

    long int dim;
    short int esito;
    traliccio * vettore;
    int occ = 0;
    float max = 0;
    int pos = 0;
    traliccio *attivi;
     
    vettore = letturadafile(dim, esito);
    
    cout << "Elenco dei tralicci presenti nel vettore: "<<endl;
    
    stampa (vettore, dim);
    
    maxmintralicci(vettore, dim);
  
    tralicciattivi(vettore, attivi, dim);
            
    return 0;
}

traliccio *letturadafile(long int& dim, short int&esito){
    
    fstream file;
    traliccio *vett;
    
    file.open("tralicci.txt", ios::in);
    
    if(!file){
        
        esito = 1;
        
        return vett;
        
    }
    
    file >> dim;
    
    if(dim <= 0){
        
        esito = 2;
        
        return vett;
        
    }
    
    vett = new (nothrow) traliccio [dim];
    
    if(!vett){
        
        esito = 3;
        
        return vett;
        
    }
    
    for (int i = 0; i < dim; i ++){
        
        file >> (vett + i)->id;
        file >> (vett + i)->kwh;
        file >> (vett + i)->funzione;
        
    }
    
    file.close();
    
    return vett;     
}

void stampa (traliccio * vettore, long int dim){
    
    cout << "ID:\tKWH:\tFUNZIONE:"<<endl;
    
    for (int i = 0; i < dim; i++){
       
        cout <<(vettore + i)->id <<"\t"<< (vettore + i)->kwh <<" kwh\t   ";
        
        if ((vettore + i)->funzione == 0){
            
            cout <<"OFF"<<endl;
            
        }else{
            
            cout <<"ON"<<endl;
            
        }
            
    }
}

void maxmintralicci(traliccio *vettore, long int dim){
    
    float sommatot = 0;
    float media = 0;
    traliccio *maxtralicci;
    traliccio *mintralicci;
    int occ = 0;
    int occ1 = 0;
    int occ2 = 0;
    int k = 0;
    
    
    for(int i = 0; i < dim; i++){
        
        if((vettore + i)->funzione == 1){
            
            sommatot = sommatot + (vettore + i)->kwh;
            occ++;
            
        }
    }
    
    if(occ == 0){
        
        cout << endl;
        
        cout <<"Nessun traliccio è funzionante, impossibile fare la media."<<endl;
        
    }else if(occ == 1){
    
        cout << endl;
        
        cout << "Solo un traliccio è funzionante."<<endl;
        
        cout <<"Impossibile generare i vettori."<<endl;
        
    }else{
    
    media = sommatot / occ;
    
    for(int i = 0; i < dim; i++){
        
        if(((vettore + i)->kwh > media) && (vettore + i)->funzione == 1){
            
            occ1++;
            
        }
    }
    
    for(int i = 0; i < dim; i++){
        
        if(((vettore + i)->kwh < media) && (vettore + i)->funzione == 1){
            
            occ2++;
            
        }
    }
    
    maxtralicci = new traliccio [occ1];
    
    mintralicci = new traliccio [occ2];
    
    for(int i = 0; i < dim; i++){
        
        if(((vettore + i)->kwh > media) && (vettore + i)->funzione == 1){
            
            *(maxtralicci + k) = *(vettore + i);
            
            k++;
            
        }
    }
    
    k = 0;
    
    for(int i = 0; i < dim; i++){
        
        if(((vettore + i)->kwh < media) && (vettore + i)->funzione == 1){
            
            *(mintralicci + k) = *(vettore + i);
            
            k++;
            
        }
    }
    
    cout << endl;
    
    cout << "Tralicci con consumo sopra la media: "<<endl;
    
    stampa(maxtralicci, occ1);
    
    cout << endl;
    
    cout << "Tralicci con consumo sotto la media: "<<endl;
    
    stampa(mintralicci, occ2);
    
    }
    
}

void tralicciattivi(traliccio * vettore, traliccio *attivi, long int dim){
   
    int occ = 0;
    
    for(int i = 0; i < dim; i++){
        
        if((vettore + i)->funzione == 1){
            
            occ++;
            
        }
    }
    
    switch(occ){
        
        case 0:
            cout << endl;
            cout <<"Non ci sono tralicci funzionanti."<<endl;
            break;
        
        case 1:
            cout << endl;
            cout <<"C'è un solo traliccio funzionante: "<<endl;
            
            for(int i = 0; i < dim; i++){
                
                if((vettore + i)->funzione == 1){
            
                    cout << "ID:\tKWH:\tFUNZIONE:"<<endl;

                    cout <<(vettore + i)->id <<"\t"<< (vettore + i)->kwh <<" kwh\t   ";
            
                    cout <<"ON"<<endl;
            
                }
            
            }
            
            break;
            
        case 2:
            cout << endl;
            
            cout << "Ci sono due tralicci funzionanti: "<<endl;
            
            cout << "ID:\tKWH:\tFUNZIONE:"<<endl;
            
            for(int i = 0; i < dim; i++){
                
                if((vettore + i)->funzione == 1){

                    cout <<(vettore + i)->id <<"\t"<< (vettore + i)->kwh <<" kwh\t   ";
            
                    cout <<"ON"<<endl;
            
                }
            
            }
            
            break;
            
        case 3:
            cout << endl;
            
            cout <<"Ci sono tre tralicci funzionanti: "<<endl;
            
            cout << "ID:\tKWH:\tFUNZIONE:"<<endl;
            
            for(int i = 0; i < dim; i++){
                
                if((vettore + i)->funzione == 1){

                    cout <<(vettore + i)->id <<"\t"<< (vettore + i)->kwh <<" kwh\t   ";
            
                    cout <<"ON"<<endl;
            
                }
            
            }
            
            break;
            
        default:
            
            cout << endl;
            
            cout << "Primi 3 tralicci funzionanti che consumano di più: "<<endl;
            
            attivi = new traliccio[occ];
            
            occ = 0;
            
            for(int i = 0; i < dim; i++){
                
                if((vettore + i)->funzione == 1){
            
                    *(attivi + occ) = *(vettore + i);
                    
                    occ++;
                    
                }
            
            }
            
            
           float max;
           traliccio temp;
           int pos;
           
           for(int i = 0; i < dim; i++){
               
               max = (attivi + i)->kwh;
               
               pos = i;
               
               for(int j = i + 1; j < dim; j++){
                   
                   if((attivi + j)->kwh > max){
                       
                   max = (attivi + j)->kwh;
                   
                   pos = j;
                   
                   }
               }
               
               if(i != pos){
                   
                   temp = *(attivi + i);
                   
                   *(attivi + i) = *(attivi + pos);
                   
                   *(attivi + pos) = temp;
                   
               }
               
           }
           
           stampa(attivi, 3);
           
           break;
            
    }
}


