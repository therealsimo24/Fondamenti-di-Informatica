/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 29 novembre 2022, 18:00
 */

#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

#define NUM 30

struct record1{
    int xPos = 0;
    int yPos = 0;
    int punteggio = 0;
};

typedef record1 navicella;

struct record2{
    int xMis = 0;
    int yMis = 0;
};

typedef record2 bomba;

int verifica_dimensione(int &, short int &, navicella []);
void stampaspazio(navicella [], int );
int conteggio_navicelle_colpite(navicella [], int, bomba, float &);
bool ricerca_navicella_bonus(navicella [], int&);
        
int main() {

    short int es = 0;
    int esito = 0;
    int dim = 0;
    bomba missile;
    int esito2 = 0;
    float sommatotale = 0;
    int esito3 = 0;
    navicella spazio[NUM];
    
    esito =verifica_dimensione(dim, es, spazio);
    
    if (es == 1){
        
        cout << "ERRORE! File non trovato."<<endl;
        cout << "Programma terminato.";
        return -1;
    }
    
    if (es == 2){
        
        cout << "ERRORE! Il numero di navicelle deve essere maggiore di 0 e minore di 30."<<endl;
        cout << "Programma terminato.";
        return -1;
    }
    
    if (esito == -1)
        return -1;
    
    
   
    cout << "Le navicelle inserite sono:"<<endl;
    
    stampaspazio(spazio, dim);
    
    //RICHIESTA LANCIO MISSILE
    
    cout << "Dove lanciare il missile? Inserire le coordinate dello schermo: "<<endl;
    cout << "Posizione X: ";
    cin >> missile.xMis;
    cout << "Posizione Y: ";
    cin >> missile.yMis;
   
    
    //CONTEGGIO NAVICELLE COLPITE E PUNTI OTTENUTI
    
    esito2 = conteggio_navicelle_colpite(spazio, dim, missile, sommatotale);
    
    if (esito2 != 0){
        cout << "Il numero di navicelle colpite è "<<esito2<<"."<<endl;
        cout << "Il punteggio ottenuto è "<< sommatotale<<"."<<endl;
    }else{
        cout << "Non hai colpito nessuna navicella."<<endl;
    }
    
    //RICERCA NAVICELLA BONUS
   
   if (ricerca_navicella_bonus(spazio, dim)){
  
   cout << "Navicella Bonus Presente!"<<endl;
   cout << "Ecco il vettore dopo aver eliminato la Navicella Bonus."<<endl;
   
   stampaspazio(spazio, dim);
        
   }else{
       cout << "Navicella Bonus Non Presente a Video";
   }
   
   
    return 0;
}

int verifica_dimensione(int &dim, short int &es, navicella spazio[]){
    
    fstream file;
  
    file.open ("navicelle.txt", ios::in);
    
    if(!file){
        
        es = 1;
        
        return -1;
    }
    
    file >> dim;
    
    if ( dim <= 0 || dim > 30){
        
        es = 2;
        
        return -1;
        
    }
   
    
    for (int i = 0; i < dim; i++){
        file >> spazio[i].xPos;
        file >> spazio[i].yPos;
        file >> spazio[i].punteggio;
    }
    
    
    file.close();
    
    return 0;
    
}
    

void stampaspazio(navicella spazio[], int dim){
   
   for (int i = 0; i < dim; i++){
       
        cout << "X: "<< spazio[i].xPos << "\tY: "<< spazio[i].yPos << "\tV: "<<spazio[i].punteggio<<endl;
        
    }
}

int conteggio_navicelle_colpite(navicella spazio[], int dim, bomba missile, float &sommatotale){
    
    int counter = 0;
    float distanza = 0;
    
    
    for (int i = 0; i < dim; i++){
        
        distanza = sqrt(pow(spazio[i].xPos-missile.xMis,2) + pow((spazio[i].yPos-missile.yMis),2));
        
        //qui ci andrebbe un valore assoluto di 10
        if (distanza <= 10 ){
            
            counter++;
            sommatotale = sommatotale + spazio[i].punteggio;
        }
         
    }
    
    return counter;
}

bool ricerca_navicella_bonus(navicella spazio[], int &dim){
    
    //RICERCA ED ELIMINAZIONE DELLA NAVICELLA BONUS
    
    for (int i = 0; i < dim; i++){
        
        if(spazio[i].punteggio >= 1000){
            
            dim--;
            
            for (int j = i; j < dim; j++){
                spazio[j]= spazio[j+1];
            }
            return true;
        }
    }
    
    return false;
}

