#include <iostream>
#include <thread>
#include <cstdlib>
#include <unistd.h>
#include <semaphore.h> 
using namespace std;

sem_t mutex_var, empty, full;
int buffer_in = 0, buffer_out = 0;
int *buffer;

void *User_function(int buff_size) {
    /*
    ********** K Srikanth 17ETCS002124 **********
    This Function is to create random user process 
    for the printer spooler so it can execute it one after one 
    */
    for (int i = 0; i < buff_size ; i++) {
	    int process = 1 + (rand() % 1000000);
        // Entry Lock Code 
        sem_wait(&empty);
        sem_wait(&mutex_var);
        
        //  Critical Region Code 
        buffer[buffer_in] = process;
        cout << endl;
        cout << "User Process : PID-" <<process << endl;
        buffer_in = (buffer_in + 1);

        // Exit Lock Code 
        sem_post(&mutex_var);
        sem_post(&full);
    }
    cout << endl;
}

void *Printer_function(int buff_size) {
     /*
    ********** K Srikanth 17ETCS002124 **********
    This Function is to print the user process from the  
    printer spooler and complete the process one by one 
    */
     
    for (int i = 0; i < buff_size; i++) {
        int process;
        // Entry Lock Code 
        sem_wait(&full);
        sem_wait(&mutex_var);

        //  Critical Region Code 
         process = buffer[buffer_out];
         buffer_out = (buffer_out + 1) ;
         cout << endl;
         cout<< "Printed the Process :  PID-" << process << endl;
        
        // Exit Lock Code 
    	sem_post(&mutex_var);
        sem_post(&empty);
}
}

int main() {
    int buff_size;
    cout << "********** K Srikanth 17ETCS002124 **********" << endl;
    cout << endl;
    cout << "Enter the Printer Spooler Size : " <<;
    cin >> buff_size;
    buffer = new int[buff_size];
    sem_init(&mutex_var, 0, 1); 
    sem_init(&empty, 0, buff_size);
    sem_init(&full, 0, 0);
    cout << "********** User Printing Queue **********" << endl;
    thread t1(User_function,buff_size);
    sleep(1);
    cout<<"********** Now Printing **********" <<endl;
    thread t2(Printer_function,buff_size);
    sleep(1);
    t1.join();
    t2.join();
    return 0;
}


