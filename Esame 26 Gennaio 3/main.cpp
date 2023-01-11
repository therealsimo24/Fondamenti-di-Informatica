
/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 8 dicembre 2022, 14:53
 */

#include <iostream>
#include <fstream>

using namespace std;

struct record{
    int vX;
    int vY;
};

typedef record motori;

#define MAX 30

motori * verifica(int &, short int& );
void stampa(motori *, int );
bool palindromi(motori *, int);
void vmax (motori *, int );

int main() {

    int dim;
    short int esito = 0;
    motori *vettore;
    bool esito1;
    
    vettore = verifica(dim, esito);
    
    if (esito == 1){
        
        cout << "Errore! La dimensione deve essere compresa nell'intervallo [1, "<<MAX<<"]."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
        
    }else if(esito == 2){
        
        cout << "Errore! File non trovato."<<endl;
        cout << "Programma Terminato."<<endl;
        return -1;
    }
    
    cout << "Elenco dei motori coassiali inseriti: "<<endl;
    
    stampa(vettore, dim);
    
    esito1 = palindromi(vettore, dim);
    
    cout << endl;
    
    if (esito1 == true){
        
        cout << "Gli elementi del vettore sono palindromi."<<endl;
        
    }else{
        
        cout << "Gli elementi del vettore non sono palindromi."<<endl;
    }
    
    vmax(vettore, dim);
    
    cout << endl;
    
    cout << "Vettore dopo lo scambio degli elementi a VXmax con gli elementi a VXmin."<<endl;
   
    stampa(vettore, dim);
            
    return 0;
}

motori * verifica(int &dim, short int& esito){
    
    fstream file;
    motori *vet;
    
    file.open("motori.txt", ios::in);
    
    if(!file){
     
        esito = 2;
        
        return vet;
        
    }
    
    file >> dim;
    
    if (dim <= 0 || dim > MAX){
        
        esito = 1;
        
        return vet;
    }
        
    vet = new motori[dim];
        
    for (int i = 0; i < dim; i++){
            
        file >> (vet + i)->vX;
        file >> (vet + i)->vY;
    
    }
       
    file.close();
    
    return vet;
    
}

void stampa(motori *vettore, int dim){
    
    cout <<"  VX:\tVY: "<<endl;
    
    for (int i = 0; i < dim; i ++){
        
        cout << i + 1 <<": "<<(vettore + i)->vX <<"\t"<< (vettore + i)->vY<<endl;
        
    }
}

bool palindromi(motori *vettore, int dim){
   
   
    for (int i = 0; i < dim/2 ; i++){
        
            
        if ((vettore + i)->vX != (vettore + (dim-1-i))->vX || (vettore + i)->vY != (vettore + (dim-1-i))->vY){
            
            return false;
            
        }else{
            
            return true;
            
        }
            
            
        }
        
}

void vmax (motori *vettore, int dim){
    
    float max = (vettore)->vX;
    float min = (vettore)->vX;
    motori temp;
    short int pos1 = 0;
    short int pos2 = 0;
    
    
    for (int i = 1; i < dim; i ++){
        
        if ((vettore + i)->vX > max){
            
            max = (vettore + i)->vX;
            pos1 = i;
        }
    }
    
    
    for (int i = 1; i < dim; i ++){
        
        if ((vettore + i)->vX < min){
            
            min = (vettore + i)->vX;
            pos2 = i;
            
        }
    }
    
    temp = *(vettore + pos1);
    
    *(vettore + pos1) = *(vettore + pos2);
    
    *(vettore + pos2) = temp;
    
    
}