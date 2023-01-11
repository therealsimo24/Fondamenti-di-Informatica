
/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 9 dicembre 2022, 10:24
 */

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

#define L 16

typedef char stringa[L];

struct record{
    float prezzo;
    stringa nome;
};

typedef record pietanze;

pietanze * letturadafile(pietanze *, long int &, short int&);
void stampa(pietanze *, long int );
void nuovivettori(pietanze* , long int );
pietanze * ordinamento(pietanze * , long int );

int main() {
    
    long int dim;
    pietanze * menu;
    short int esito = 0;
    
    menu = letturadafile(menu, dim, esito);
    
    if (esito == 1){
        
        cout << "Errore! File non trovato."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
        
    }
    
    if(esito == 2){
        
        cout << "Errore! Il menù deve contenere almeno un elemento."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
        
    }
    
    if(esito == 3){
        
        cout << "Errore! Memoria non disponibile."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
        
    }
    
    cout << "Elenco delle pietanze inserite:"<<endl;
    
    stampa(menu, dim);
    
    nuovivettori(menu, dim);
    
    menu = ordinamento(menu, dim);
    
    cout << endl;
    
    cout << "Menù ordinato in ordine alfabetico."<<endl;
    
    stampa(menu, dim);
    
    return 0;
}

pietanze * letturadafile(pietanze *menu, long int &dim, short int&esito){
    
    fstream file;
    pietanze * vettore;
    
    file.open("menu.txt", ios::in);
    
    if(!file){
        
        esito = 1;
        
        return vettore;
        
    }
    
    file >> dim;
    
    if( dim <= 0){
        
        esito = 2;
        
        return vettore;
        
    }
    
    vettore = new (nothrow) pietanze[dim];
    
    if(!vettore){
        
        esito = 3;
        
        return vettore;
    }
    
    for (int i = 0; i < dim; i ++){
        
        file >> (vettore + i)->prezzo;
        file >> (vettore + i)->nome;
        
    }
    
    file.close();
    return vettore;
}

void stampa(pietanze *menu, long int dim){
    
    cout << "      Prezzo:\tNome:"<<endl;
    
    for(int i = 0; i < dim; i++){
        
        cout << i + 1<< ":\t" << (menu + i)->prezzo <<"€\t"<< (menu + i)->nome<<endl;
        
    }
    
}

void nuovivettori(pietanze* menu, long int dim){
    
    pietanze * v1;
    pietanze * v2;
    int occ1 = 0;
    int occ2 = 0;
    int k = 0;
    int j = 0;
    
    
    for (int i = 0; i < dim; i++){
        
        if ((menu + i)->nome[0] >= 'a' && (menu + i)->nome[0] <= 'd'){
            
            occ1++;
            
        }
    }
    
    v1 = new pietanze [occ1];
    
    for (int i = 0; i < dim; i++){
        
        if ((menu + i)->nome[0] >= 'a' && (menu + i)->nome[0] <= 'd'){
            
            *(v1 + k) = *(menu + i);
            
            (v1 + k)->nome[0] = toupper((menu + i)->nome[0]);
            
            k++;
            
        }
    }
    
    for (int i = 0; i < dim; i++){
        
        if ((menu + i)->nome[0] >= 'm' && (menu + i)->nome[0] <= 'p'){
            
            occ2++;
            
        }
    }
    
    v2 = new pietanze [occ2];
    
    for (int i = 0; i < dim; i++){
        
        if ((menu + i)->nome[0] >= 'm' && (menu + i)->nome[0] <= 'p'){
            
            *(v2 + j) = *(menu + i);
            
            (v2 + j)->nome[0] = toupper((menu + i)->nome[0]);
            
            j++;
            
        }
    }
    
    cout << endl;
    
    cout << "Elenco dei vettori appartenti all'intervallo [a,d]: "<<endl;
    
    stampa(v1, occ1);
    
    cout << endl;
    
    cout << "Elenco dei vettori appartenti all'intervallo [m,p]: "<<endl;
    
    stampa(v2, occ2);
    
}

pietanze * ordinamento(pietanze * menu, long int dim){
    
    string min;
    int pos;
    int k = 0;
    pietanze temp;
    
    for (int i = 0; i < dim - 1; i ++){
        
        min = (menu + i)->nome;
        
        pos = i;
        
        for (int j = i + 1; j < dim; j++){
            
            k = 0;
            
            while((menu + j)->nome[k] == min[k] && k < L){
                
                k++;
                
            }
       
            if((menu + j)->nome[k] < min[k]){
                
                min = (menu + j)->nome;
                
                pos = j;
            }
        }
        
        if (i != pos){
            
            temp = *(menu + i);
            
            *(menu + i) = *(menu + pos);
            
            *(menu + pos) = temp;
        }
  
  
    }
    
    return menu;
}