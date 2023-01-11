
/* 
 * File:   main.cpp
 * Author: therealsimo24
 *
 * Created on 6 dicembre 2022, 19:39
 */

#include <iostream>

using namespace std;

struct record{
    int id;
    float speed;
    float temperatura;
};

typedef record braccio;

void verifica(long int&);
void inserimento(braccio *, long int);
void stampa(braccio *, long int);
void modifiche(braccio *, long int , float &);
void ricerca(braccio *, long int, float);

int main() {
    
    long int dim;
    braccio * robot;
    float max = 0;
    
    verifica(dim);
       
    robot = new (nothrow) braccio[dim];
    
    if(!robot){
        
        cout <<"Errore! Memoria non disponibile."<<endl;
        cout <<"Terminazione del programma."<<endl;
        return -1;
        
    }
    
    inserimento(robot, dim);
    
    cout << endl;
    
    cout << "Elenco dei bracci robotoci inseriti: "<<endl;
    
    stampa(robot, dim);
    
    modifiche(robot, dim, max);
    
    cout << endl;
    
    ricerca(robot, dim, max);
   
    
   
}

void verifica(long int &dim){
    
    do{
        
        cout << "Inserire il numero di robot della linea di produzione: ";
        cin >> dim;
        
    if (dim <= 0){
        
        cout << "Errore! Il vettore deve essere composto da almeno un elemento."<<endl;
        cout << "Riprovare inserimento..."<<endl;
        cout << endl;
    }
    
    }while(dim <= 0);
    
}

void inserimento(braccio *robot, long int dim){
    
    cout << "Inserire le caratteristiche dei "<< dim <<" robot presenti."<<endl;
    
    for (int i = 0; i < dim; i++){
        
        cout << "Robot "<< i + 1<<": "<<endl;
        cout << "Id: ";
        cin >> (robot + i)->id;
        cout << "Velocità: ";
        cin >> (robot + i)->speed;
        cout << "Temperatura: ";
        cin >> (robot + i)->temperatura;
        
    }
    
}

void stampa(braccio *robot, long int dim){
    
    cout << "Id:\tVelocità:  Temperatura:"<<endl;
    
    for (int i = 0; i < dim; i++){
        
        cout << (robot + i)->id << "\t    " << (robot + i)->speed << "\t\t" << (robot + i)->temperatura<<endl;
        
    }
}

void modifiche(braccio *robot, long int dim, float &max){
   
    for (int i = 0; i < dim; i++){
        
        if ((robot + i)->temperatura > max){
            
            max = (robot + i)->temperatura;
            
        }
          
    }
                
    for (int i = 0; i < dim; i++){
        
        if ((robot + i)->temperatura == max){
            
            (robot + i)->speed = 0;
            
        }else{
            
            (robot + i)->speed = max;
            
        }
          
    }
    
    cout << endl;
    
    cout << "Elenco del vettore dopo l'ottimizzazione della linea di produzione: "<<endl;
    
    stampa (robot, dim);
    
}

void ricerca(braccio *robot, long int dim, float max){
    
    float velox;
    float temp;
    bool esito = false;
    
    cout << "Inserire velocità e temperatura del robot da ricercare: "<<endl;
    cout << "Velocità: ";
    cin >> velox;
    cout << "Temperatura: ";
    cin >> temp;
    
    cout << endl;
    
    for (int i = 0; i < dim; i++){
        
        if ((robot + i)->speed == velox && (robot + i)->temperatura == temp){
            
            cout << "Il robot che soddisfa tali valori è: "<<endl;
            cout << (robot + i)->id << "\t    " << (robot + i)->speed << "\t\t" << (robot + i)->temperatura<<endl;
            esito = true;
            
        }  
           
    }
    
    if (esito == false){
        
        cout << "Non è stato trovato nessun robot avente le caratteristiche cercate."<<endl;
        
    }
        
}
   
    

