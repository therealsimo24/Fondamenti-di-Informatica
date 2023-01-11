
/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 13 dicembre 2022, 16:06
 */

#include <iostream>
#include <fstream>

using namespace std;

#define L 16

typedef char stringa[L];

struct record{
    stringa nome;
    float prezzo;
    int pagine;
    int copie;
};

typedef record libreria;

libreria *letturadafile(long int &, short int&);
void stampa(libreria *, long int );
void carrellolibri(libreria * , long int );
void ricerca(libreria *, long int );

int main() {
    
    long int dim;
    short int esito = 0;
    libreria *vettore;

    vettore = letturadafile(dim, esito);
    
    if (esito == 1){
        
        cout << "Errore! File non trovato."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
        
    }
    
    if (esito == 2){
        
        cout << "Errore! Il magazzino deve contenere almeno un libro."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
        
    }
    
    if (esito == 3){
        
        cout << "Errore! Memoria non disponibile."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
        
    }
    
    cout << "Elenco dei libri presenti in magazzino: "<<endl;
    
    stampa(vettore, dim);
    
    carrellolibri(vettore, dim);
    
    ricerca(vettore, dim);
    
    return 0;
}

libreria *letturadafile(long int &dim, short int&esito){
    
    fstream file;
    libreria *vett;
    
    file.open("copie.txt", ios::in);
    
    if(!file){
        
        esito = 1;
        
        return vett;
    }
    
    file >> dim;
    
    if(dim <= 0){
        
        esito = 2;
        
        return vett;
    }
    
    vett = new (nothrow) libreria[dim];
    
    if(!vett){
        
        esito = 3;
        
        return vett;
        
    }
    
    for(int i = 0; i < dim; i++){
        
        file >>(vett + i)->nome;
        file >>(vett + i)->prezzo;
        file >>(vett + i)->pagine;
        file >>(vett + i)->copie;
        
    }
    
    
    file.close();
    return vett;
}

void stampa(libreria *vettore, long int dim){
    
    cout << "  Titolo:    Prezzo:  Pagine:  Copie:"<<endl;
    
    for (int i = 0; i < dim; i ++){
        
        cout << "  "<<(vettore + i)->nome<<"  \t"<<(vettore + i)->prezzo<<"€"<<"\t"<< (vettore + i)->pagine<<"\t"<< (vettore + i)->copie<<endl;
        
    }
}

void carrellolibri(libreria * vettore, long int dim){
    
    libreria *carrello;
    int occ = 0;
    int k = 0;
    float sommatot = 0;
    
    for (int i = 0; i < dim; i++){
        
        if((vettore + i)->copie == 0){
            
            occ++;
        }
    }
    
    carrello = new libreria [occ];
    
    for (int i = 0; i < dim; i++){
        
        if((vettore + i)->copie == 0){
            
            *(carrello + k) = *(vettore + i);
            
            k++;
        }
    }
    
    cout << endl;
    
    cout << "Elenco dei libri non disponibili presenti nel carrello: "<<endl;
    
    stampa(carrello, occ);
    
    for (int i = 0; i < dim; i++){
        
        sommatot = sommatot + ((carrello + i)->prezzo * 2);
        
    }
    
    cout << endl;
    
    cout << "La somma complessiva del carrello, acquistando due copie per libro, è "<< sommatot <<"."<<endl;
    
    cout << endl;
}

void ricerca(libreria *vettore, long int dim){
    
    libreria *ordine;
    char lettera;
    int occ = 0;
    int k = 0;
    
    cout << "Inserire l'iniziare di un libro da ricercare: ";
    
    cin >> lettera;
    
    
    for (int i = 0; i < dim; i ++){
        
        if ((vettore + i)->nome[0] == lettera){
            
            occ++;
            
        }
    }
    
    if(occ == 0){
        
        cout << endl;
        
        cout << "Non è presente nessun libro con l'iniziale cercata."<<endl;
        
    }else{
        
    ordine = new libreria [occ];
    
    for (int i = 0; i < dim; i ++){
        
        if ((vettore + i)->nome[0] == lettera){
            
            *(ordine + k) = *(vettore + i);
            
            k++;
            
        }
    }
    
    cout << endl;
    
    cout << "Elenco dei libri che iniziano con "<< lettera <<":"<<endl;
    
    stampa(ordine, occ);

    
    } 
}
