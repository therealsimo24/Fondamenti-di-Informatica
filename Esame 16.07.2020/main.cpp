
/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 30 novembre 2022, 22:13
 */

#include <iostream>

using namespace std;

#define L 16
#define MaxLibri 20

typedef char stringa[L];

struct record{
    float prezzo;
    stringa titolo;
};

typedef record libro;

void verifica_dimensione(long int &);
void riempimento_vettore(libro *, long int);
void stampa_vettore(libro *, long int);
bool verifica_valore_inversione(int &, long int);
void inverisone(libro *, libro *, long int, int);
float ricerca_max(libro *, long int, int &);
int ricerca_pos(libro *, long int, float);
libro *rimozione_elemento(libro *, long int &, int);

int main() {

    long int dim;
    libro* scaffale;
    libro* scaffalec;
    int inversione;
    bool esito;
    float max;
    int counter = 0;
    int posizione;
   
    
    //VERIFICA DIMENSIONE
    
    verifica_dimensione(dim);
    
    scaffale = new (nothrow) libro[dim];
    
    if (!scaffale){
        cout << "Errore! Memoria non disponibile."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
    }
    
    scaffalec = new (nothrow) libro[dim];
    
    
    //INSERIMENTO DEI VALORI DEL VETTORE
    
    cout << "Inserire le caratteristiche dei "<< dim <<" libri presenti sullo scaffale."<<endl;
    
    riempimento_vettore(scaffale, dim);
    
    //STAMPA DEI VALORI DEL VETTORE
    
    cout << "I libri presenti sullo scaffale sono: "<<endl;
    
    stampa_vettore(scaffale, dim);
    
    //INVERSIONE VETTORE DA UN INDICE DI INPUT
    
    cout << "Inserire l’indice oltre il quale invertire la posizione dei libri: ";
    
    cin >> inversione;
    
    esito = verifica_valore_inversione(inversione, dim);
    
    if(esito == true){
        
        inverisone(scaffale, scaffalec, dim, inversione);
        
        cout << "Dopo l’inversione le copie sullo scaffale sono ordinate come segue: "<<endl;
        
        stampa_vettore(scaffalec, dim);
        
    }
    
    //RICERCA PREZZO MAX
    
    max = ricerca_max(scaffale, dim, counter);
    
    //RICERCA ED ELIMINAZIONE LIBRI DI PREZZO MAX
    
    for (int i = 0; i < counter; i ++){
        
        posizione = ricerca_pos(scaffale, dim, max);
    
        scaffale = rimozione_elemento(scaffale, dim, posizione);
        
    }
      
    cout << "Rimuovendo le copie a prezzo massimo dallo scaffale si ottiene: "<<endl;
    
    stampa_vettore(scaffale, dim);
    
    
    return 0;
}

void verifica_dimensione(long int &dim){
    
    do{
        cout << "Inserire il numero di libri presente sullo scaffale: ";
        cin >> dim;
        
        if (dim <= 0 || dim > 20){
            cout << "Errore! Il numero di libri prenseti sullo scaffale deve essere compreso tra 1 e "<< MaxLibri<<"."<<endl;
            cout << endl;
        }
        
    }while(dim <= 0 || dim > 20);
    
    //non faccio altri controlli perchè c'è anche una dimensione max del vettore
}

void riempimento_vettore(libro *scaffale, long int dim){
    
    for (int i = 0; i < dim; i++){
        
    cout <<"Libro in posizione "<< i+1<<endl;
    cout << "Titolo: ";
    cin >> (scaffale + i)->titolo;
    cout << "Prezzo: ";
    cin >> (scaffale + i)->prezzo;
    
    }
    
}

void stampa_vettore(libro *scaffale, long int dim){
    
    for (int i = 0; i < dim; i ++){
        
        cout << (scaffale + i)->titolo<<"     \t"<<(scaffale + i)->prezzo<<"€"<<endl;
        
    }
    
}

bool verifica_valore_inversione(int &inversione, long int dim){
    
    if (inversione >= dim){
        cout << "Errore! La posizione inserita non è valida."<<endl;
        return false;
    }
    
    return true;
}

void inverisone(libro *scaffale, libro *scaffalec, long int dim, int inversione){
    
    int j = dim;
    
    
    for (int i = 0; i < dim; i ++){
        
        if(i < inversione){
            *(scaffalec + i) = *(scaffale + i);
        }else{
            *(scaffalec + i) = *(scaffale + (--j));
        }
        
    }
    
    
}

float ricerca_max(libro *scaffale, long int dim, int &counter){
    
    float max = scaffale->prezzo;
    
    for ( int i = 0; i < dim; i ++){
        
        if ((scaffale + i)->prezzo > max){
            
            max = (scaffale + i)->prezzo;
        }
    }
    
    for (int i = 0; i < dim; i++){
        
        if ((scaffale + i)->prezzo == max){
            
            counter++;
            
        }
    }
    
    return max;
}

int ricerca_pos(libro *scaffale, long int dim, float max){
    
    bool trovato = false;
    int pos = 0;
    
    while(!trovato && pos < dim){
        
        if ((scaffale + pos)->prezzo == max){
            
            trovato = true;
            
        }else{
            pos++;
        }
    }
    
    return pos;
}

libro * rimozione_elemento(libro *scaffale, long int &dim, int pos){
    
        
        libro *scaffalem;
        
        scaffalem = new (nothrow) libro[dim-1];
        
        for (int i = 0; i < pos; i++){
            *(scaffalem + i) = *(scaffale + i);
        }
        
        for (int i = pos + 1; i < dim; i++){
            *(scaffalem + i -1) = *(scaffale + i);
        }
        
        dim--;
        
        delete[] scaffale;
        
        return scaffalem;
        
 
}





