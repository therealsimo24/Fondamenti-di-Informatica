
/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 11 dicembre 2022, 20:52
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
void classificazione (triangolo *, long int );
void ordinamento(triangolo *, long int );    

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
    
    classificazione (vettore, dim);
    
    ordinamento(vettore, dim);
    
    cout << endl;
    
    cout << "Il vettore ordinato per perimetro crescente è: "<<endl;

    stampa(vettore, dim);
    
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

void classificazione (triangolo *vettore, long int dim){
    
    int equilatero = 0;
    int isoscele = 0;
    int rettangolo = 0;
    int scaleno = 0;
    int rettangoloiso = 0;
    float l1, l2, l3 = 0;
    
    for (int i = 0; i < dim; i ++){
        
        l1 = (vettore + i)->a;
        l2 = (vettore + i)->b;
        l3 = (vettore + i)->c;
        
        if (l1 == l2 && l2 == l3 && l3 == l1){
            
            equilatero++;
            
        }
        
        if (l1 != l2 && l2 != l3 && l3 != l1){
            
            scaleno++;
            
        }
        
        if (((pow(l1, 2) + pow (l2, 2)) == pow(l3, 2) || (pow(l2, 2) + pow (l3, 2)) == pow(l1, 2) || (pow(l3, 2) + pow (l1, 2)) == pow(l2, 2))){
            
            rettangolo++;
            
        }
        
        if ((l1 == l2 && l1 != l3) || (l2 == l3 && l3 != l1) || (l1 == l3 && l1 != l2)){
            
            isoscele++;
            
        }
        
        if (((l1 == l2 && l1 != l3) || (l2 == l3 && l3 != l1) || (l1 == l3 && l1 != l2)) && ((pow(l1, 2) + pow (l2, 2)) == pow(l3, 2) || (pow(l2, 2) + pow (l3, 2)) == pow(l1, 2) || (pow(l3, 2) + pow (l1, 2)) == pow(l2, 2))){
            
            rettangoloiso++;
            
        }
 
    }
    
    cout << endl;
    cout << "Il numero di triangoli EQUILATERI è \t"<< equilatero <<"."<<endl;
    cout << "Il numero di triangoli SCALENI è \t"<< scaleno <<"."<<endl;
    cout << "Il numero di triangoli RETTANGOLI è \t"<< rettangolo <<"."<<endl;
    cout << "Il numero di triangoli ISOSCELI è \t"<< isoscele <<"."<<endl;
    cout << "Il numero di triangoli R-ISOSCELI è \t"<< rettangoloiso <<"."<<endl;

}

void ordinamento(triangolo *vettore, long int dim){
    
    float perimetro1 = 0;
    float perimetro2 = 0;
    float min;
    int pos;
    triangolo temp;
    
    
    for (int i = 0; i < dim; i ++){
        
        perimetro1 = (vettore + i)->a + (vettore + i)->b + (vettore + i)->c;

        min = perimetro1;
        
        pos = i;
        
        for (int j = i + 1; j < dim; j++){
            
            perimetro2 = (vettore + j)->a + (vettore + j)->b + (vettore + j)->c;
            
            if (perimetro2 < min){
                
                min = perimetro2;
                
                pos = j;
            }
            
        }
        
        
        if (i != pos){
            
            temp = *(vettore + i);
            
            *(vettore + i) = *(vettore + pos);
            
            *(vettore + pos) = temp;
            
        }
             
    }
    
    
}