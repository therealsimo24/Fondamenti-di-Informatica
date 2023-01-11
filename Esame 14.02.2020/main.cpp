/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 28 novembre 2022, 22:22
 */

#include <iostream>
#include <string.h>

using namespace std;

#define L 16

typedef char stringa[L];

struct record{
    float prezzo;
    stringa nome;
};

typedef record pietanze;


void verifa_dimensioni(long int &);
void inserimento_pietanze(pietanze *, long int);
void stampa_menu(pietanze *, long int);
void verifica_stringa(stringa &);
void verifica_presenza(stringa &, pietanze *, long int);
int evidenziazione(pietanze *, long int, int&);
void maiuscolo(pietanze *, int);

int main() {

    pietanze *menu;
    long int dim;
    stringa nome = "";
    int pos = 0;
    int i = 0;
   
    
    
    verifa_dimensioni(dim);
    
    menu = new (nothrow) pietanze [dim];
    
    if(!menu){
        cout <<"Memoria non disponibile."<<endl;
        cout<<"Programma terminato.";
        return -1;
    }
    
    inserimento_pietanze(menu, dim);
    
    cout << endl;
    cout << "Ecco la lista di pietanze inserite nel menù:"<<endl;
    cout << "     Prezzo:     Nome:"<<endl;
    
    stampa_menu(menu, dim);
    
    verifica_stringa(nome);
    
    verifica_presenza(nome, menu, dim);
    
    i = evidenziazione(menu, dim, pos);
    
    maiuscolo(menu, i);
    
    cout << "Evidenziando la prima pietanza del menù con il prezzo massimo si ottiene:"<<endl;
    
    stampa_menu(menu, dim);
    
   
    
    return 0;
}

void verifa_dimensioni(long int &dim){
    
    do{
    
    cout<< "Inserire il numero di pietanze presenti nel menù: ";
    cin >> dim;
    
    if (dim <=0){
        
        cout << "Errore! Il numero di pientanze presenti del menù deve esser almeno maggiore di zero."<<endl;
        cout << "Riprovare l'inserimento..."<<endl;
        
    }
    
    cout << endl;
    }while (dim <=0);
    
}

void inserimento_pietanze(pietanze *menu, long int dim){
    
    cout << "Inserire le "<< dim <<" pietanze presenti nel menù. "<<endl;
    
    cout << endl;
    
    for (int i = 0; i < dim; i++){
        cout << "Inserire la pientanza di indice "<< i <<":"<<endl;
        cout << "Nome: ";
        cin >> menu->nome;
        cout << "Prezzo: ";
        cin >> menu->prezzo;
        
        menu++;
    }
}

void stampa_menu(pietanze *menu, long int dim){
    
      for (int i = 0; i < dim; i++){
        cout << i <<": \t"<< menu->prezzo <<"€\t"<< menu->nome<<endl;
        menu++;
        
    }
    
}

void verifica_stringa(stringa &nome){
    
    do{
        cout << "Inserire stringa di ricerca di lunghezza 3: ";
        cin >> nome;
        
        
        
        if(strlen(nome)!=3){
            cout << "Errore! La lunghezza della stringa di ricerca deve essere ESATTAMENTE DI 3 lettere."<<endl;
            cout << "Riprovare l'inserimento..."<<endl;
        }
            
    }while(strlen(nome)!=3);
}

void verifica_presenza(stringa &nome, pietanze *menu, long int dim){
   
    float prezzosomma = 0;
    
    for (int i = 0; i < dim; i++){
        
         if(strncmp((menu)->nome, nome, 3) == 0){
             prezzosomma = prezzosomma + menu->prezzo;
             
         }
         menu++;
    }
    
    if (prezzosomma != 0){
        cout << endl;
        cout << "Il prezzo totale delle pietanze che iniziano per "<< nome <<" è "<< prezzosomma << "€"<<endl;
    }else{
        cout << endl;
        cout << "Nel menù non sono presenti pietanze che inizano per "<< nome <<"."<<endl;
    }
   
}

int evidenziazione(pietanze *menu, long int dim, int& pos){
    
    float max = menu->prezzo;
    
    for (int i = 0; i < dim; i++){
        
        if (max < (menu+i)->prezzo){
            
            max = (menu+i)->prezzo;
            pos = i;
            
        }
        
    }
    
    return pos;
}

void maiuscolo(pietanze *menu, int i){
    
    int lunghezza = strlen((menu+i)->nome);
        
    for (int j = 0; j< lunghezza ; j ++){
        (menu+i)->nome[j] = toupper((menu+i)->nome[j]);
    }
    
}
   