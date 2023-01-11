
/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 12 dicembre 2022, 21:37
 */

#include <iostream>
#include <fstream>

using namespace std;

#define L 17

typedef char stringa[L];

struct record{
    stringa nome;
    float megabyte;
    int datac;
    int datam;
};

typedef record documenti;

documenti *letturadafile(long int& , short int&);
void stampa(documenti *, long int);
void ordinamento_dimensione(documenti *, long int);
void ordinamento_nome(documenti *, long int);
void scelta_utente(documenti *, long int , short int);
documenti* cancellazione(documenti *, long int, int&);

int main() {

    documenti *cartella;
    long int dim;
    short int esito = 0;
    short int scelta = 0;
    int occ = 0;
   
    cartella = letturadafile(dim, esito);
    
    if (esito == 1){
        
        cout << "Errore! File non trovato."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
        
    }
    
    if (esito == 2){
        
        cout << "Errore! La libreria deve contenere almeno un libro."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
        
    }
    
    if (esito == 3){
        
        cout << "Errore! Memoria non disponibile."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
        
    }
    
    cout << "Elenco delle cartelle presenti nel vettore: "<<endl;
    
    stampa(cartella, dim);
    
    cout << endl;
    
    cout << "Scegliere il tipo di ordinamento del documento. "<<endl;
    cout << "Ordinamento per dimensioni => 0;"<<endl;
    cout << "Ordinamento per nome => 1;"<<endl;
    cout << "Inserire l'ordinamento: ";
    
    cin >> scelta;
    
    scelta_utente(cartella, dim, scelta);
       
    cartella = cancellazione(cartella, dim, occ);
    
    cout << endl;
    
    cout << "Ecco il vettore dopo la cancellazione delle immagini a data di creazione più vecchia:"<<endl;
    
    stampa(cartella, dim - occ);
    
    return 0;
}

documenti *letturadafile(long int& dim, short int&esito){
    
    fstream file;
    documenti *vettore;
    
    file.open("cartella.txt", ios::in);
    
    if(!file){
        
        esito = 1;
        
        return vettore;
        
    }
    
    file >> dim;
    
    if(dim <= 0){
        
        esito = 2;
        
        return vettore;
        
    }
    
    vettore = new (nothrow) documenti [dim];
    
    if(!vettore){
        
        esito = 3;
        
        return vettore;
        
    }
    
    for (int i = 0; i < dim; i ++){
        
       file >> (vettore + i)->nome;
       file >> (vettore + i)->megabyte;
       file >> (vettore + i)->datac;
       file >> (vettore + i)->datam;
       
    }
    
    file.close();
    
    return vettore;     
}

void stampa(documenti *cartella, long int dim){
    
    cout << "Nome:\t      Megabyte: DataC:  DataUM:"<<endl;
    
    for (int i = 0; i < dim; i ++){
        
        cout << (cartella + i)->nome<<"\t\t"<< (cartella + i)->megabyte <<"\t"<<(cartella + i)->datac << "\t"<<(cartella + i)->datam<<endl;
        
    }
}

void ordinamento_dimensione(documenti *cartella, long int dim){
    
    float min = 9999.9999;
    int pos = 0;
    documenti temp;
    
    for (int i = 0; i < dim; i++){
        
        min = (cartella + i)->megabyte;
        
        pos = i;
        
        for(int j = i + 1; j < dim; j++){
            
            if((cartella + j)->megabyte < min){
                
                min = (cartella + j)->megabyte;
                
                pos = j;
                
            }
        }
        
        
        if(i != pos){
            
            temp = *(cartella + i);
                    
            *(cartella + i) = *(cartella + pos);
            
            *(cartella + pos) = temp;
            
        }
        
    }
    
}

void ordinamento_nome(documenti *cartella, long int dim){
    
    string min;
    int pos = 0;
    documenti temp;
    int k;
    
    for (int i = 0; i < dim; i++){
        
        min = (cartella + i)->nome;
        
        pos = i;
        
        for(int j = i + 1; j < dim; j++){
            
            k = 0;
            
            while ((cartella + j)->nome[k] == min[k] && k < L){
                
                k++;
                        
            }
            
            if((cartella + j)->nome[k] < min[k]){
                
                min = (cartella + j)->nome;
                
                pos = j;
                
            }
        }
        
        
        if(i != pos){
            
            temp = *(cartella + i);
                    
            *(cartella + i) = *(cartella + pos);
            
            *(cartella + pos) = temp;
            
        }
        
    }
    
}

void scelta_utente(documenti *cartella, long int dim, short int scelta){
    
    switch (scelta){
        
        case 0:
            
            cout << endl;
            
            cout << "Ecco il vettore ordinato per dimensione: "<<endl;
            
            ordinamento_dimensione(cartella, dim);
            
            stampa(cartella, dim);
            
            break;
            
        case 1:
            
            ordinamento_nome(cartella, dim);
            
            cout << endl;
            
            cout << "Ecco il vettore ordinato per nome: "<<endl;
            
            stampa(cartella, dim);
            
            break;
        
        default:
            
            cout << endl;
            
            cout <<"Valore inserito non valido."<<endl;
            
            break;
        
    }
}

documenti* cancellazione(documenti *cartella, long int dim, int &occ){
    
    documenti *nuovovet;
    int min = 999999999;
    int k = 0;
    
    for (int i = 0; i < dim; i++){
        
        if ((cartella + i)->datac < min){
            
            min = (cartella + i)->datac;
            
        }
    }
    
    for(int i = 0; i < dim; i++){
        
        if ((cartella + i)->datac == min){
            
            occ++;
        }
    }
    
    nuovovet = new documenti [dim - occ];
    
    
    for (int i = 0; i < dim; i++){
        
        if ((cartella + i)->datac != min){
            
            *(nuovovet + k) = *(cartella + i);
            
            k++;
        }
    }   
    
    delete []cartella;
    
    return nuovovet;
    
}
