#include <iostream>

using namespace std;

bool EsVocal(char caracter);

int main()
{
    int opcion=1;
    cout<<endl;
    cout<<"Bienvednido a la practica 1"<<endl;
    while (opcion!=0){
        cout<<"seleccione una opcion"<<endl;
        cout<<"1) identificador vocal o consonante"<<endl;
        cout<<"2) Contador de monedas y billetes"<<endl;
        cout<<"3) Lector mes - dia"<<endl;
        cout<<"0 para salir"<<endl;
        cin>>opcion;
        switch(opcion){
        case 1:{
            char caracter;
            cout<<"Se esta ejecutando el problema 1"<<endl;
            cout<<"ingrese un caracter"<<endl;
            cin>>caracter;
            if((caracter>=65 && caracter<=90)||(caracter >=97&& caracter <=122 )){
                if(EsVocal(caracter))
                    cout<<caracter<<" es una vocal"<<endl;
                else
                    cout<<caracter<<" es una consonate"<<endl;
            }
            break;
        }
        case 2:{
            int billetes[] = {500000, 20000, 10000, 5000, 2000, 1000};
            int monedas[] = {500, 200, 100, 50};
            int con_billetes[]= {0,0,0,0,0,0};
            int con_monedas[]={0,0,0,0};
            int cantidad;

            cout<<"Ingrese una cantidad de dinero"<<endl;
            cin>>cantidad;

            for (int i=0; i<6; i++){
                while(cantidad>=billetes[i]){
                    cantidad -= billetes[i];
                    con_billetes[i] +=1;
                }
            }

            for (int i=0; i<4; i++){
                while(cantidad>=monedas[i]){
                    cantidad -= monedas[i];
                    con_monedas[i] +=1;
                }
            }

            for (int i = 0; i < 6; i++) {
                if (con_billetes[i] >= 0) {
                    cout << billetes[i] << ": " << con_billetes[i] << endl;
                }
            }

            for (int i = 0; i < 4; i++) {
                if (con_monedas[i] >= 0) {
                    cout << monedas[i] << ": " << con_monedas[i] << endl;
                }
            }
            cout<<"faltante: "<<cantidad<<endl;
        }
        case 3:{
            int mes, dia;
                cout<<"Porfavor ingrese un mes (1-12)"<<endl;
                cin>>mes;

                if ((mes<1)||(mes>12)){
                    cout<<mes<<" es un mes es invalido"<<endl;
                    return 1;
                }

                cout<<"ingrese un dia del mes: "<<endl;
                cin>>dia;

                if ((dia<1)||(dia>31)){
                    cout<<dia<<"/"<<mes<<"es una fecha invalida"<<endl;
                }

                if (mes == 2 && dia == 29){
                    cout<<dia<<"/"<<mes<<" es valida en bisiesto."<<endl;
                }

                if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia>30){
                    cout<<dia<<"/"<<mes<<"es una fecha invalida"<<endl;
                }

                cout<<dia<<"/"<<mes<<" es una fecha valida"<<endl;

                break;
        }
        default:
            if (opcion!=0)
                cout<<"opcion no valida"<<endl;
            break;
        }

    }
    return 0;
}

bool EsVocal(char caracter){
    if (caracter>=97)
        caracter -= 32;

    if (caracter =='A'||caracter =='E'||caracter =='I'||caracter == 'O'||caracter == 'O'||caracter == 'U')
        return true;
    else
        return false;

}
