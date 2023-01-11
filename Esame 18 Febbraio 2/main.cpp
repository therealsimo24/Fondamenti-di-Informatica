
/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 15 dicembre 2022, 18:21
 */

#include <iostream>

using namespace std;

#define MAX 100

struct record{
    int energia;
    char ruolo;
};

typedef record pg;

void verifica(long int& );
void inserimento(pg [][MAX], long int );
void stampa(pg [][MAX], long int );
void energia(pg [][MAX], long int );
void trasformazione(pg [][MAX], long int );

int main () {
    
    long int dim;
    int vita;
    
    pg matrice[MAX][MAX];
    
    //INSERIMENTO E STAMPA DEI DATI DELLA MATRICE
    verifica(dim);
    
    inserimento(matrice, dim);
    
    cout << endl;
    
    cout << "Matrice inserita: "<<endl;
    
    stampa(matrice, dim);
    
    //VALUTAZIONE DELL'ENERGIA PER TIPOLOGIA
    
    energia(matrice, dim);
  
    //TRASFORMAZIONE IN FANTASMI DEI PERSONAGGI A ENERGIE MINIME
    
    cout << "\nMatrice dopo la trasformazione in fantasmi dei personaggi a energie minime."<<endl;
    
    trasformazione(matrice, dim);
    
    
    return 0;
}

void verifica(long int&dim){
    
    do{
        
        cout << "Inserire dimensione della scacchiera: ";
        
        cin >> dim;
        
        if(dim < 3 || dim > 100){
            
            cout << "\nErrore! La dimensione della scacchiera deve essere compresa nell'intervallo [3, "<< MAX <<"]"<<endl;
        
            cout << "Riprovare l'inserimento.\n"<<endl;
        
        }
        
    }while(dim < 3 || dim > 100);
    
}

void inserimento(pg matrice[][MAX], long int dim){
    
    cout << endl;
    
    for(int i = 0; i < dim; i++){
        
        for (int j = 0; j < dim; j++){
            
            cout << "Inserire elemento della scacchiera di indice "<< i <<" "<< j<<": "<<endl;
            cout << "Tipologia ( \"G\" = GUERRIERO, \"F\" = FANTASMA, \"D\" = DRAGO): ";
            cin >> matrice[i][j].ruolo;
            cout << "Energia (HP): ";
            cin >> matrice[i][j].energia;
            
        }
    }

}

void stampa(pg matrice[][MAX], long int dim){
    
    
    for(int i = 0; i < dim; i++){
        
        cout << endl;
        cout << endl;
        
        for(int j = 0; j < dim; j++){
            
            
            cout << matrice[i][j].ruolo<<"\t";
            
            
        }
    }
    
    
    cout << endl;
    cout << endl;
}

void energia(pg matrice[][MAX], long int dim){
    
    pg v[3];
    pg temp;
    int min = INT_MAX;
    int pos;
    
    v[0].ruolo = 'G';
    v[1].ruolo = 'D';
    v[2].ruolo = 'F';
    
    for (int i = 0; i < dim; i ++){
        
        for (int j = 0; j < dim; j++){
            
            if (matrice[i][j].ruolo == 'G'){
                
               v[0].energia = v[0].energia + matrice[i][j].energia;
               
            }
            
            
            if (matrice[i][j].ruolo == 'D'){
                
                v[1].energia = v[1].energia + matrice[i][j].energia;
                
            }
            
            
            if (matrice[i][j].ruolo == 'F'){
                
                v[2].energia = v[2].energia + matrice[i][j].energia;
                
            }
            
        }
        
    }
    
    
    for (int i = 0; i < dim - 1; i++){
        
        min = v[i].energia;
        
        pos = i;
        
        for(int j = i + 1; j < dim; j ++){
            
            if(v[i].energia < min){
                
                min = v[i].energia;
                
                pos = j;
            }
        }
        
        if(i != pos){
            
            temp = v[i];
            
            v[i] = v[pos];
            
            v[pos] = temp;
               
        }
        
    }
    
    cout << endl;
    
    cout << "La tipologia di personaggio a energia complessiva minima è ";
    
    if(v[0].ruolo == 'G'){
        
        cout <<"GUERRIERO.";
    }
    
    if(v[0].ruolo == 'D'){
        
        cout <<"DRAGO.";
    }
    
    if(v[0].ruolo == 'F'){
        
        cout <<"FANTASMA.";
    }
    
}

void trasformazione(pg matrice [][MAX], long int dim){
    
   float media;
   float sommatot;
   pg temp;
   
   for (int i = 0; i < dim; i++){
   
       for (int j = 0; j < dim; j++){

           sommatot = sommatot + matrice[i][j].energia;
           
       }
       
   }

   media = ((float)sommatot)/((float) dim*dim);
   
   for (int i = 0; i < dim; i++){
   
       for (int j = 0; j < dim; j++){

           if(matrice[i][j].energia < media){
               
              matrice[i][j].ruolo = 'F';
               
           }
           
       }
       
   }
   
   
   stampa(matrice, dim);
   
}

