

/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 13 dicembre 2022, 14:25
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
void ordinamento(magazzino *, long int);
void verifica(magazzino *, long int , float &);
void decrescente(magazzino *, long int );

int main() {

    long int dim;
    magazzino *elettro;
    short int esito = 0;
    float prezzo = 0;
    
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
    
    cout <<"Inserire il prezzo da ricercare: ";
    
    verifica(elettro, dim, prezzo);
    
    cout << endl;
    
    cout << "Valore totale per ogni tipologia, ordinati in senso decrescente: "<<endl;
    
    decrescente(elettro, dim);
    
    
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
    
    string min;
    int pos = 0;
    magazzino temp;
    int k;
    
    for (int i = 0; i < dim -1; i++){
        
        min = (elettro + i)->marca;
        
        pos = i;
        
        for (int j = i + 1; j < dim; j++){
            
            k = 0;
            
            while((elettro + j)->marca[k] == min[k] && k < L){
                
                k++;
                
            }
            
            if ((elettro + j)->marca[k] < min[k]){
                
                min = (elettro + j)->marca;
                
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

void verifica(magazzino *elettro, long int dim, float &prezzo){
    
    int occ = 0;
    int k = 0;
    magazzino *vettore;
    
    cin >> prezzo;
    
    for(int i = 0; i < dim; i++){
        
        if ((elettro + i)->prezzo == prezzo){
            
            occ++;
            
        }
       
    }
    
    vettore = new magazzino [occ];
    
    if (occ == 0){
        
        cout << endl;
        
        cout << "Non sono presenti in magazzino elettrodomestici con questo prezzo."<<endl;
        
    }else{
        
    for (int i = 0; i < dim; i++){
        
        if ((elettro + i)->prezzo == prezzo){
            
            *(vettore + k)= *(elettro + i);
            
            k++;
        }
    }  
    
    cout << endl;
    
    cout << "Ecco gli elettrodomestici aventi il prezzo ricercato."<<endl;
    
    stampa(vettore, occ);
    
    cout << endl;
        
    cout << "Ecco gli elettrodomestici ordinati in ordine alfabetico."<<endl;
    
    ordinamento(vettore, occ);
        
    stampa(vettore, occ);
        

    }
  
}

void decrescente(magazzino *elettro, long int dim){
    
    magazzino vet[4];
    
    float sommatot = 0;
    
    for(int i = 0; i < dim; i++){
        
        if ((elettro + i)->tipologia == 1){
            
            sommatot = sommatot + (elettro + i)->prezzo;
            
        }
        
    }
    
    vet[0].prezzo = sommatot;
    vet[0].tipologia = 1;
    
    sommatot = 0;
    
    for(int i = 0; i < dim; i++){
        
        if ((elettro + i)->tipologia == 2){
            
            sommatot = sommatot + (elettro + i)->prezzo;
            
        }
        
    }
    
    vet[1].prezzo = sommatot;
    vet[1].tipologia = 2;
    
    sommatot = 0;
    
    for(int i = 0; i < dim; i++){
        
        if ((elettro + i)->tipologia == 3){
            
            sommatot = sommatot + (elettro + i)->prezzo;
            
        }
        
    }
    
    vet[2].prezzo = sommatot;
    vet[2].tipologia = 3;
   
    sommatot = 0;
    
    for(int i = 0; i < dim; i++){
        
        if ((elettro + i)->tipologia == 4){
            
            sommatot = sommatot + (elettro + i)->prezzo;
            
        }
        
    }
    
    vet[3].prezzo = sommatot;
    vet[3].tipologia = 4;
    
    float max;
    int pos = 0;
    magazzino temp;
    
    for (int i = 0; i < dim -1; i++){
        
        max = vet[i].prezzo;
        
        pos = i;
        
        for (int j = i + 1; j < dim; j++){
            
            if (vet[j].prezzo > max){
                
                max = vet[j].prezzo;
                
                pos = j;
                
            }
        }
        
        if (i != pos){
            
            temp = vet[i];
            
            vet[i]= vet[pos];
            
            vet[pos] = temp;
            
        }
        
    }
    
    for (int i = 0; i < 4; i++){
        
         switch(vet[i].tipologia){
            
            case 1:
                cout << "Lavastoviglie:\t"<<vet[i].prezzo<<endl;
                break;
                
            case 2:
                cout << "Lavasciuga:\t"<<vet[i].prezzo<<endl;
                break;
                
            case 3:
                cout << "Lavatrice:\t"<<vet[i].prezzo<<endl;
                break;
                
            case 4:
                cout << "Asciugatrice\t"<<vet[i].prezzo<<endl;
                break;
           
        }
    }
    
    
}
