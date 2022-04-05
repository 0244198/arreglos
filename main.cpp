#include <iostream>

struct List{
    int *Arreglo;
    int Len;
};

using namespace std;



void Ingresar_Arreglo(List **ptr, int &num){
    int num_datos;
    List *list = new List;
    cout << "Cuantos datos ingresaras: \n";
    cin >> num_datos;
    int *arr = new int[num_datos];
    for(int i = 0; i < num_datos;i++){
            cout << "Ingresa tu dato: " << i+1 << "\n";
        cin >> arr[i];
    }
    list->Arreglo = arr;
    list->Len = num_datos;
    (*(ptr+num)) = list;
    num += 1;
}

void Print(List **ptr, int num){
    List *ptr2;
    for(int i = 0; i < num; i++){
        ptr2 = (*(ptr+i));
        cout << "[";
        for(int i = 0; i < ptr2->Len; i++){
           if(i != (ptr2->Len-1)){
               std::cout <<  ptr2->Arreglo[i] << ",";
           }
            else{
                std::cout <<  ptr2->Arreglo[i];
            }
        }
        cout << "]\n";  
    }
}

int main() {
    List list;
    bool run = true;
    int opcion;
    int num_arreglos = 0;
    List *arr[3];
    List **ptr = arr;

    while(run){
        cout << "Ingresa tu opcion \n";
        cout << "(1) Ingresar arreglos \n";
        cout << "(2) Ver datos \n";
        cout << "(3) Salir \n";
        cin >> opcion;
        switch(opcion){
            case 1:
                for(int i = 0; i < 3; i++){
                    cout << "Arreglo " << i+1 << "\n";
            Ingresar_Arreglo(ptr,num_arreglos);
                }
                break;
            case 2:
                cout << "Tus arreglos son: \n";
                Print(arr, num_arreglos);
                break;
            case 3:
                cout << "Salir";
                run = false;
                break;
        }
    }
}
