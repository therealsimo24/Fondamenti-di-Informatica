
/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 12 dicembre 2022, 16:02
 */

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

typedef char stringa[11];

struct record{
    stringa nome;
    float prezzo;
};

typedef record menu;

menu* letturadafile(menu* , long int&, short int&);
void stampa(menu *, long int );
void ricerca(menu *, long int , stringa &);
void evidenziazione(menu * , long int );

int main() {

    menu * pietanze;
    long int dim;
    short int esito = 0;
    stringa nome = "";
    
    pietanze = letturadafile(pietanze, dim, esito);
    
    if(esito == 1){
        
        cout << "Errore! File non trovato."<<endl;
        cout <<"Programma Terminato."<<endl;
        return -1;
        
    }
    
    if(esito == 2){
        
        cout << "Errore! Il vettore deve contenere almeno un elemento."<<endl;
        cout <<"Programma Terminato."<<endl;
        return -1;
        
    }
    
    if(esito == 3){
        
        cout << "Errore! Memoria non disponibile."<<endl;
        cout <<"Programma Terminato."<<endl;
        return -1;
        
    }
    
    cout << "L'elenco delle pietanze nel menù è: "<<endl;
    
    stampa(pietanze, dim);
    
    cout << endl;
    
    cout << "Inserire il nome di una pietanza da ricercare nel menù: ";
    
    cin >> nome;
    
    ricerca(pietanze, dim, nome);
    
    evidenziazione(pietanze, dim);
    
    cout << endl;
    
    cout << "L'elenco delle pietanze dopo l'evidenziazione: "<<endl;
    
    stampa(pietanze, dim);
    
    return 0;
}

menu* letturadafile(menu* pietanze, long int&dim, short int& esito){
    
    fstream file;
    menu * vettore;
    
    file.open("pietanze.txt", ios::in);
    
    if(!file){
        
        esito = 1;
        
        return vettore;
    }
    
    file >> dim;
    
    if(dim <= 0){
        
        esito = 2;
        
        return vettore;
        
    }
    
    vettore = new (nothrow) menu[dim];
    
    if(!vettore){
        
        esito = 3;
        
        return vettore;
        
    }
    
    for (int i = 0; i < dim; i++){
        
        file >> (vettore + i)->nome;
        file >> (vettore + i)->prezzo;
        
    }
    
    file.close();
    
    return vettore;
}

void stampa(menu *pietanze, long int dim){
    
    cout << "Nome:\t  Prezzo: "<<endl;
    
    for(int i = 0; i < dim; i ++){
        
        cout <<(pietanze + i)->nome <<"\t  "<< (pietanze + i)->prezzo<<endl;
        
    }
    
}

void ricerca(menu *pietanze, long int dim, stringa &nome){
    
    int occ = 0;
    bool presenza = false;
    
    for (int i = 0; i < dim; i++){
        
        if (((strcmp(nome, (pietanze + i)->nome)) == 0) && occ < 2){
            
            presenza = true;
            
            occ++;
        }
    }
    
    if(presenza == 0){
        
        cout << endl;
        
        cout << "Non è stata trovata nessuna pietanza corrispondente al nome inserito."<<endl;
        
    }else{
        
        if (occ == 1){
            
        cout << endl;
        
        cout << "È stata trovata solamente una pietanze nel menu che corrisponde alla ricerca."<<endl;
          
        }else{
            
        cout << "Le prime due pietanze corrispondenti alla ricerca sono: "<<endl;
              
        }
    
        occ = 0;
        
    cout << "Nome:\t  Prezzo: "<<endl;
    
    for (int i = 0; i < dim; i++){
        
        if (((strcmp(nome, (pietanze + i)->nome)) == 0) && occ < 2){
            
            cout <<(pietanze + i)->nome <<"\t  "<< (pietanze + i)->prezzo<<endl;
            
            occ++;
        }
    }
        
    }
    
}

void evidenziazione(menu * pietanze, long int dim){
    
    float sommatot = 0;
    float media = 0;
    
    for (int i = 0; i < dim; i ++){
        
        sommatot = sommatot + (pietanze + i)->prezzo;
       
    }
    
    media = sommatot / dim;
    
    for (int i = 0; i < dim; i ++){
       
        
        if ( (pietanze + i)->prezzo > media){
            
            (pietanze + i)->nome[0] = toupper((pietanze + i)->nome[0]);
                    
        }
    }
}

