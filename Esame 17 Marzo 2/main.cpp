
/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 11 dicembre 2022, 11:56
 */

#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

#define L 16

typedef char stringa[L];

struct record{
    float prezzo;
    short int tipologia;
    stringa marca;
    bool dispo;
};

typedef record magazzino;

magazzino *letturadafile(long int &, short int&);
void stampa(magazzino *, long int );
void ordinamento(magazzino *, long int );
void vettori(magazzino *, long int );
void verificastringa(stringa &);
void ricerca(magazzino *, long int , stringa );

int main() {

    long int dim;
    short int esito = 0;
    magazzino * elettro;
    stringa nome = "";
    
    elettro = letturadafile(dim, esito);
    
    if (esito == 1){
        
        cout << "Errore! File non trovato."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
        
    }
    
    if (esito == 2){
        
        cout << "Errore! Nell'elenco deve essere presente almeno un elemento."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
        
    }
    
    if (esito == 3){
        
        cout << "Errore! Memoria non disponibile."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
        
    }
    
    cout << "Elenco dei prodotti presenti in magazzino: "<<endl;
    
    stampa(elettro, dim);
    
    vettori(elettro, dim);
    
    verificastringa(nome);
    
    ricerca(elettro, dim, nome);
    
    cout << endl;
   
    stampa(elettro, dim);
    
    
    
    return 0;
}

magazzino *letturadafile(long int &dim, short int&esito){
    
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
    
    vettore = new (nothrow) magazzino[dim];
    
    if(!vettore){
        
        esito = 3;
        
        return vettore;
        
    }
    
    for (int i = 0; i < dim; i++){
        
        file >> (vettore + i)->prezzo;
        file >> (vettore + i)->tipologia;
        file >> (vettore + i)->marca;
        file >> (vettore + i)->dispo;
        
    }
    
    file.close();
    return vettore;
    
}

void stampa(magazzino *elettro, long int dim){
    
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
                
            case 5:
                cout << "LAVASTOVIGLIE";
                break;
                
            case 6:
                cout << "LAVASCIUGA";
                break;
                
            case 7:
                cout << "LAVATRICE";
                break;
                
            case 8:
                cout << "ASCIUGATRICE";
                break;
           
        }
       
        cout <<"\t"<< (elettro + i)->marca <<"\t      ";
        
        if ((elettro + i)->dispo == 0){
            
            cout << "NO"<<endl;
            
        }else{
            
            cout << "SI"<<endl;
            
        }
            
    }
     
}

void ordinamento(magazzino *elettro, long int dim){
    
    string min;
    int pos = 0;
    int k = 0;
    magazzino temp;
    
    for (int i = 0; i < dim -1; i++){
        
        min = (elettro + i)->marca;
        
        pos = i;
        
        for (int j = i + i; j < dim; j++){
            
            k = 0;
            
            while ((elettro + j)->marca[k] == min[k] && k < L){
                
                k++;
                
            }
            
            if ((elettro + j)->marca[k] < min[k]){
            
            min = (elettro + j)->marca;
            
            pos = j;
            
            }
            
        }
        
        if (i != pos){
            
           temp =  *(elettro + i);
           
           *(elettro + i) = *(elettro + pos);
           
           *(elettro + pos) = temp;
            
        }
        
    }
}


void vettori(magazzino *elettro, long int dim){
    
    magazzino *lavastoviglie;
    magazzino *lavasciuga;
    magazzino *lavatrice;
    magazzino *asciugatrice;
    int occ1 = 0;
    int occ2 = 0;
    int occ3 = 0;
    int occ4 = 0;
    int k = 0;
    
    //PRIMO VETTORE
    for (int i = 0; i < dim; i ++){
        
        if ((elettro + i)->tipologia == 1){
            
            occ1++;
            
        }
    }
    
    lavastoviglie = new magazzino [occ1];
    
    for (int i = 0; i < dim; i ++){
        
        if ((elettro + i)->tipologia == 1){
            
            *(lavastoviglie + k) = *(elettro + i) ;
            
            k++;
        }
    }
    

    //SECONDO VETTORE
    k = 0;
    
    for (int i = 0; i < dim; i ++){
        
        if ((elettro + i)->tipologia == 2){
            
            occ2++;
            
        }
    }
    
    lavasciuga = new magazzino [occ2];
    
    for (int i = 0; i < dim; i ++){
        
        if ((elettro + i)->tipologia == 2){
            
            *(lavasciuga + k) = *(elettro + i) ;
            
            k++;
        }
    }
    
    //TERZO VETTORE
    k = 0;
    
    for (int i = 0; i < dim; i ++){
        
        if ((elettro + i)->tipologia == 3){
            
            occ3++;
            
        }
    }
    
    lavatrice = new magazzino [occ3];
    
    for (int i = 0; i < dim; i ++){
        
        if ((elettro + i)->tipologia == 3){
            
            *(lavatrice + k) = *(elettro + i) ;
            
            k++;
        }
    }
    
    //QUARTO VETTORE
    k = 0;
    
    for (int i = 0; i < dim; i ++){
        
        if ((elettro + i)->tipologia == 4){
            
            occ4++;
            
        }
    }
    
    asciugatrice = new magazzino [occ4];
    
    for (int i = 0; i < dim; i ++){
        
        if ((elettro + i)->tipologia == 4){
            
            *(asciugatrice + k) = *(elettro + i) ;
            
            k++;
        }
    }
    

    ordinamento(lavastoviglie, occ1);
    ordinamento(lavasciuga, occ2);
    ordinamento(lavatrice, occ3);
    ordinamento(asciugatrice, occ4);
    
    cout << endl;
    
    cout << "Vettore di lavastoviglie: "<<endl;
    
    stampa(lavastoviglie, occ1);
    
    cout << endl;
    
    cout << "Vettore di lavasciuga: "<<endl;
    
    stampa(lavasciuga, occ2);
    
    cout << endl;
    
    cout << "Vettore di lavatrici: "<<endl;
    
    stampa(lavatrice, occ3);
    
    cout << endl;
    
    cout << "Vettore di asciugatrici: "<<endl;
    
    stampa(asciugatrice, occ4);
    
}

void verificastringa(stringa &nome){
    
    do {
        
    cout << endl;
    cout << "Inserire le prime tre lettere della marca di elettrodomestici da ricercare: ";
    cin >> nome;
        
    if ((strlen(nome) != 3)){
        
        cout << "Errore! Le lettere da inserire per la ricerca devono essere ESATTAMENTE 3."<<endl;
        cout << "Riprovare inserimento..."<<endl;
        
    }
    
    }while((strlen(nome) != 3));
    
}

void ricerca(magazzino *elettro, long int dim, stringa nome){
    
    float min = 9999.9999;
    
    for (int i = 0; i < dim; i++){
        
        if ((elettro + i)->prezzo < min && strncmp((elettro + i)->marca, nome, 3) == 0){
            
            min = (elettro + i)->prezzo;
            
        }
    }
    
    for (int i = 0; i < dim; i++){
        
        if ((elettro + i)->prezzo == min && strncmp((elettro + i)->marca, nome, 3) == 0 && (elettro + i)->dispo == 1){
            
            switch((elettro + i)->tipologia){
            
            case 1:
                (elettro + i)->tipologia = 5;
                break;
                
            case 2:
                (elettro + i)->tipologia = 6;
                break;
                
            case 3:
                (elettro + i)->tipologia = 7;
                break;
                
            case 4:
                (elettro + i)->tipologia = 8;
                break;
              
        }
    }
    
}
    
}

