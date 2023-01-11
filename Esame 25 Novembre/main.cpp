/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 14 dicembre 2022, 17:23
 */

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

struct record{
    float a;
    float b;
    float c;
    
};

typedef record triangolo;

triangolo * letturadafile(triangolo *, long int &, short int&);
void stampa(triangolo *, long int );
void occorrenze (triangolo *, long int );
void nuovovett(triangolo *, long int );    

int main() {

    triangolo * vettore;
    long int dim;
    short int esito = 0;
    
    vettore = letturadafile(vettore, dim, esito);
    
    if(esito == 1){
        
        cout <<"Errore! File non trovato."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
        
    }
    
    if(esito == 2){
        
        cout <<"Errore! Il vettore deve contenere almeno un elemento."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
        
    }
    
    if(esito == 3){
        
        cout <<"Errore! Memoria non disponibile."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
        
    }
    
    cout <<"Elenco dei triangoli presenti nel vettore:"<<endl;
    
    stampa(vettore, dim);
    
    occorrenze (vettore, dim);
    
    nuovovett(vettore, dim);
    
    cout << endl;
    
    return 0;
}

triangolo * letturadafile(triangolo *vettore, long int &dim, short int&esito){
    
    fstream file;
    triangolo *vet;
    
    file.open("triangoli.txt", ios::in);
    
    if(!file){
        
        esito = 1;
        
        return vet;
        
    }
    
    file >> dim;
    
    if(dim <= 0){
        
        esito = 2;
        
        return vet;
        
    }
    
    vet = new (nothrow) triangolo [dim];
    
    if(!vet){
        
        esito = 3;
        
        return vet;
        
    }
    
    for(int i = 0; i < dim; i++){
        
        file >> (vet + i)->a;
        file >> (vet + i)->b;
        file >> (vet + i)->c;
        
    }
    
    file.close();
    return vet;
}

void stampa(triangolo *vettore, long int dim){
    
    cout << "Lato A:\t     Lato B:\t     Lato C:"<<endl;
    
    for (int i = 0; i < dim; i ++){
        
        cout << "   "<<(vettore + i)->a<<"\t\t"<<(vettore + i)->b <<"\t\t"<<(vettore + i)->c<<endl;
        
    }
}

void occorrenze (triangolo *vettore, long int dim){
    
    int rettangolo = 0;
    float l1, l2, l3 = 0;
    
    for (int i = 0; i < dim; i ++){
        
        l1 = (vettore + i)->a;
        l2 = (vettore + i)->b;
        l3 = (vettore + i)->c;
        
        if (((pow(l1, 2) + pow (l2, 2)) == pow(l3, 2) || (pow(l2, 2) + pow (l3, 2)) == pow(l1, 2) || (pow(l3, 2) + pow (l1, 2)) == pow(l2, 2))){
            
            rettangolo++;
            
        }
       
 
    }
    
    cout << endl;
    cout << "Il numero di triangoli RETTANGOLI è "<< rettangolo <<"."<<endl;
    

}

void nuovovett(triangolo *vettore, long int dim){
    
    float perimetro;
    int occ = 0;
    int k = 0;
    float media;
    float sommatot;
    triangolo *newvett;
    
    for(int i = 0; i < dim; i++){
        
        perimetro = (vettore + i)->a + (vettore + i)->b + (vettore + i)->c;
        
        sommatot = sommatot + (perimetro);
        
    }
    
    media = sommatot / dim;
    
    
    for(int i = 0; i < dim; i++){
        
        perimetro = (vettore + i)->a + (vettore + i)->b + (vettore + i)->c;
        
        if(perimetro < media){
            
            occ++;
            
        }
        
    }
    
    newvett = new triangolo [occ];
    
    for(int i = 0; i < dim; i++){
        
        perimetro = (vettore + i)->a + (vettore + i)->b + (vettore + i)->c;
        
        if(perimetro < media){
            
            *(newvett + k) = *(vettore + i);
            
            k++;
            
        }
        
    }
    
    cout << endl;
    
    cout << "Elenco dei triangoli a perimetro minore della media: "<<endl;
    
    stampa(newvett, occ);
    
    
}
