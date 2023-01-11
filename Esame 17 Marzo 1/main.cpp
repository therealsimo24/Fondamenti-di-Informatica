
/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 10 dicembre 2022, 11:39
 */

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

#define L 16

typedef char stringa[L];

struct record{
    
    float prezzo;
    short int tipologia;
    stringa marca;
    bool disponibilita;
    
};

typedef record magazzino;

magazzino * letturadafile(magazzino* , long int &, short int &);
void stampa(magazzino * , long int );
void ordinamento(magazzino *, long int );
void vettori(magazzino *, long int );
void evidenziazione(magazzino *, long int );

int main() {

    long int dim;
    magazzino *elettro;
    short int esito = 0;
    
    elettro = letturadafile(elettro, dim, esito);
    
    if(esito == 1){
        
        cout << "Errore! File non trovato."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
    }
    
    if(esito == 2){
        
        cout << "Errore! Il vettore deve contenere almeno un elemento."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
    }
    
    if(esito == 3){
        
        cout << "Errore! Memoria non disponibile."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
    }
    
    cout << "Elenco degli elettrodomestici presenti in magazzino: "<<endl;
    
    stampa(elettro, dim);
    
    cout << endl;
    
    vettori(elettro, dim);
    
    cout << endl;
    
    evidenziazione(elettro, dim);
    
    
    return 0;
}

magazzino * letturadafile(magazzino* elettro, long int &dim, short int &esito){
    
    fstream file;
    magazzino * vettore;
    
    file.open("magazzino.txt", ios::in);
    
    if(!file){
        
        esito = 1;
        
        return vettore;
        
    }
    
    file >> dim;
    
    if(dim <= 0){
        
        esito = 2;
        
        return vettore;
        
    }
    
    vettore = new (nothrow) magazzino [dim];
    
    if(!vettore){
        
        esito = 3;
        
        return vettore;
        
    }
    
    for (int i = 0; i < dim; i++){
        
        file >> (vettore + i)->prezzo;
        file >> (vettore + i)->tipologia;
        file >> (vettore + i)->marca;
        file >> (vettore + i)->disponibilita;
                
    }    
    
    file.close();
    return vettore;
}

void stampa(magazzino * elettro, long int dim){
    
    cout << "Prezzo: Tipologia:      Marca:    Disponibilità:"<<endl;
    
    for (int i = 0; i < dim; i ++){
        
        cout << (elettro + i)->prezzo <<"€\t";
        
        switch((elettro + i)->tipologia){
            
            case 1:
                cout << "lavastoviglie";
                break;
                
            case 2:
                cout << "lavasciuga";
                break;
                
            case 3:
                cout << "lavatrice";
                break;
                
            case 4:
                cout << "asciugatrice";
                break;
           
        }
       
        cout <<"\t"<< (elettro + i)->marca <<"\t      ";
        
        if ((elettro + i)->disponibilita == 0){
            
            cout << "NO"<<endl;
            
        }else{
            
            cout << "SI"<<endl;
            
        }
            
    }
}

void ordinamento(magazzino *elettro, long int dim){
    
    float min;
    int pos = 0;
    magazzino temp;
    
    for (int i = 0; i < dim -1; i++){
        
        min = (elettro + i)->prezzo;
        
        pos = i;
        
        for (int j = i + 1; j < dim; j++){
            
            if ((elettro + j)->prezzo < min){
                
                min = (elettro + j)->prezzo;
                
                pos = j;
                
            }
        }
        
        if (i != pos){
            
            temp = *(elettro + i);
            
            *(elettro + i) = *(elettro + pos);
            
            *(elettro + pos) = temp;
            
        }
    }
}


void vettori(magazzino *elettro, long int dim){
    
    long int occ1 = 0;
    long int occ2 = 0;
    magazzino * v1;
    magazzino * v2;
    int k = 0;
    int l = 0;
    
    for (int i = 0; i < dim; i ++){
        
        if ((elettro + i)->disponibilita == 0){
            
            occ1++;
            
        }else{
            
            occ2++;
            
        }
    }
    
    v1 = new magazzino [occ1];
    
    v2 = new magazzino [occ2];
    
    for (int i = 0; i < dim; i ++){
        
        if ((elettro + i)->disponibilita == 0){
            
            *(v1 + k) = *(elettro + i);
            
            k++;
            
        }else{
            
            *(v2 + l) = *(elettro + i);
            
            l++;
            
        }
    }
    
    cout << "Elettrodomestici disponibili in magazzino: "<<endl;
    
    ordinamento(v2, occ2);
    
    stampa (v2, occ2);
    
    cout << endl;
    
    cout << "Elettrodomestici non disponibili in magazzino: "<<endl;
    
    ordinamento(v1, occ1);
    
    stampa (v1, occ1);
    
}

void evidenziazione(magazzino *elettro, long int dim){
    
    short int tipo;
    float max = 0;
    
    cout <<"N.B. (1 = ‘lavastoviglie', 2 = ‘lavasciuga’, 3 = ‘lavatrice’, 4 = ‘asciugatrice’)"<<endl;
    cout <<"Inserire una tipologia di elettrodomestico: ";
    
    cin >> tipo;
    
    for (int i = 0; i < dim; i++){
        
        if ((elettro + i)->tipologia == tipo){
            
            if ((elettro + i)->prezzo > max){
                
                max = (elettro + i)->prezzo;
                
            }
            
        }
    }
    
    for (int i = 0; i < dim; i++){
        
        if ((elettro + i)->tipologia == tipo && (elettro + i)->prezzo == max){
            
            for (int j = 0; j < L; j++){
                
            (elettro + i)->marca[j] = toupper((elettro + i)->marca[j]);
            
            }
            
    }
    
    }
    
    stampa(elettro, dim);
    
}