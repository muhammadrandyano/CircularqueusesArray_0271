/**
* @mainpage Documentation Circular queues
*
* @section Introduction 
* Project ini merupakan project struktur data menggunakan struktur data queue dengan pendekatan circular arrays
* @section Project
* Project ini memiliki beberapa operasi antara lain
* 1.Insert 
* 2.Delete
* 3.Display
*
* @section Cara penggunaan 
* Berikut beberapa menu yang bisa digunakan :
* 1. en queue
* 2. de queue
* 3. display
* 4. exit
*
* @author Profil
* - Nama : Muhammad Randyano
* - Nim : 20240140271
* - Kelas : F
*
* @brief
* @version
* @date 2025-06-24
*
* @copyright m.randyano.ft24@mail.umy.ac.id (c) 2025
*
*/


#include <iostream>
using namespace std;
/**
 * @class Queue
 * @brief class ini untuk operasi lengkap queues
 * 
 */


class Queues{
    int FRONT;///< variabel private front untuk menyimpan posisi depan antrian
    int REAR;///< variabel private rear untuk menyimpan posisi belakang antrian
    int max = 5;///< variabel private max untuk menyimpan ukuran maximum antrian 
    int queue_array[5];///< variabel private queue_array untuk menyimpan elemen antrian

    public:
    /**
     * @brief Construct a new Queue object
     * set default queues null
     * with front = -1 and rear = -1
     */
    Queues(){
        FRONT = -1;
        REAR  = -1;
    }

    /**
     * @brief method untuk memasukkan data dalam antrian 
     * data dimasukkan dalam variabel queue_array
     */

    void insert(){
        int num;///< variabel num unntuk menyimpan nilai
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        //Cek apakah antrian penuh
        if((FRONT == 0 && REAR == max -1)||(FRONT == REAR + 1)){
            cout << "\nQueue overflow\n";
            return;
        }
        
        //cek apakah antrian kosong
        if (FRONT == -1) {
            FRONT = 0;
            REAR = 0;     
        }
        else{
            // jika rear berada di posisi terakhir array, kembali ke awal array
            if (REAR == max-1)
            REAR = 0;
            else
            REAR = REAR +1;
        }
        queue_array[REAR] = num;
    }
    /**
     * @brief method untuk menghapus data dalam antrian
     * data dihapuskan dari dalam variabel queue_array
     */

    void remove(){
        //cek apakah antrian kosong
        if (FRONT == -1){
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is: "<< queue_array[FRONT]<< endl;

        // cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR){
            FRONT = -1;
            REAR = -1;
        }
        else{
            //jika element yang dihapus berada diposisi terakhir array, kembali ke awal array
            if (FRONT == max -1)
            FRONT=0;
            else FRONT = FRONT +1;
        }
    }

    /**
     * @brief method untuk menampilkan data dalam antrian
     * data ditampilkan yang berada dalam variasi queue_array
     */

    void display(){
        int FRONT_position = FRONT;///< variabel front_position untuk menandakan posisi element pertama pad variabel front
        int REAR_position = REAR;///< variabel rear_position untuk menandakan posisi element terakhir pada variabel rear

        //cek apakah antrian kosong 
        if (FRONT == -1){
            cout << "Queue is Empty\n";
            return;
        }

        cout << "\nElement in the queue are...\n";

        // jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR
        if(FRONT_position <= REAR_position){
            while(FRONT_position <= REAR_position){
                cout << queue_array[FRONT_position]<< " ";
                FRONT_position++;
            }
            cout << endl;
        }
        else {
            // jika FRONT_position > REAR_position, iterasi dari FRONT hingga akhir REAR
            while (FRONT_position <= max -1){
                cout << queue_array[FRONT_position]<< " ";
                FRONT_position++;
            }
             FRONT_position = 0;

             //Iterasi dari awal array hingga REAR
            while(FRONT_position <= REAR_position){
                cout << queue_array[FRONT_position]<< " ";
                FRONT_position++;
            }
            cout << endl;
        } 
    }
};

/**
 * @brief method untuk menjalankan program
 * 
 * @return int  
 */

int main (){
    Queues q;///< objek untuk menggunakan member yang ada pada class queues
    char ch;///< variabel ch untuk menyimpan pilihan pada menu yang diberikan

    while (true){
        try {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit "<<endl;
            cout << "Enter your Choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch){
                case '1': {
                    q.insert();
                    break;
                }
                case '2': {
                    q.remove();
                    break;
                }
                case '3': {
                    q.display();
                    break;
                }
                case '4': {
                    return 0;
                }
                default: {
                    cout << "invalid option!!" << endl;
                    break;
                }
            }
        }
        catch (exception& e) {
            cout << "Check for the values entered." << endl;
        }
    }
}