#include <iostream>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <string>
#include <vector>
#include <semaphore.h>

using namespace std;

int condivisa = 0;
mutex mtx;
sem_t sPari;
sem_t sDispari;

void taskPari(){
    for(int i = 0; i < 1000 ; i++){
        sem_wait(&sPari);
        condivisa++;
        if(condivisa % 2 == 0){
            cout<<"Sono nel task pari"<<endl;
        };
        sem_post(&sDispari);
    };

}
void taskDispari(){
    for(int i = 0; i < 1000 ; i++){
        sem_wait(&sDispari);
        condivisa++;
        if(condivisa % 2 == 1){
            cout<<"Sono nel task dispari"<<endl;
        };
        sem_post(&sPari);
    };
}

int main(){
    sem_init(&sPari,0,0);
    sem_init(&sDispari,0,1);
    thread tPari(taskPari);
    thread tDispari(taskDispari);
    tPari.join();
    tDispari.join();
    
    

    return 0;
}