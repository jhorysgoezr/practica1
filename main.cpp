#include <iostream>

//Practica Jhorys Osnaider Goez Renteria

using namespace std;

bool EsVocal(char caracter);
bool esPrimo(int numero);
int Potencia(int base, int exponente);

int main()
{
    int opcion=1;
    cout<<endl;
    cout<<"***Bienvednido a la practica 1***"<<endl;
    while (opcion!=0){
        cout<<"seleccione una opcion"<<endl;
        cout<<"1) identificador vocal o consonante"<<endl;
        cout<<"2) Contador de monedas y billetes"<<endl;
        cout<<"3) Lector mes - dia"<<endl;
        cout<<"4) Lector de horas"<<endl;
        cout<<"5) Patron de *"<<endl;
        cout<<"6) Aproximado de e"<<endl;
        cout<<"7) Suma de pares Fibonacci"<<endl;
        cout<<"8) Suma de multiplos"<<endl;
        cout<<"9) Numero elevado a si mismo"<<endl;
        cout<<"10) Enesimo numero primo"<<endl;
        cout<<"11) Calculadora MCM"<<endl;
        cout<<"12) Maximo factor Primo"<<endl;
        cout<<"13) Suma de numeros primos menores"<<endl;
        cout<<"14) Numero palindromo mas grande de multiplicacion 3 cifras"<<endl;
        cout<<"15) Suma espiran NxN"<<endl;
        cout<<"16) Serie Collatz"<<endl;
        cout<<"17) Numeros triangulares"<<endl;
        cin>>opcion;
        switch(opcion){
        case 1:
        {
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
        }
        break;
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
        break;
        case 3:
        {
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
                    cout<<dia<<"/"<<mes<<" es una fecha invalida"<<endl;
                }

                if (mes == 2 && dia == 29){
                    cout<<dia<<"/"<<mes<<" es valida en bisiesto."<<endl;
                }

                if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia>30){
                    cout<<dia<<"/"<<mes<<" es una fecha invalida"<<endl;
                }

                if (mes ==1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
                cout<<dia<<"/"<<mes<<" es una fecha valida"<<endl;       
        }
        break;
        case 4:
        {
            int hora, tiempo;
            cout<<"Ingrese porfavor un numero entero "<<endl;
            cin>>hora;

            if ((hora<0)||(hora > 2359)){
                cout<<"La hora ingresada es invalida"<<endl;
                return 1;
            }

            cout<<"Ingrese un segundo numero entero: "<<endl;
            cin>>tiempo;

            if ((tiempo<0)||(tiempo>2359)){
                cout<<"la hora ingresada es invalida"<<endl;
                return 1;
            }

            int hora_1 = hora / 100;
            int minutos_1 = hora % 100;
            int hora_2 = tiempo / 100;
            int minutos_2 = tiempo % 100;

            int hora_total = hora_1 + hora_2;
            int minutos_total = minutos_1 + minutos_2;

            if (minutos_total >= 60){
                hora_total += 1;
                minutos_total -= 60;
            }

            hora_total = hora_total % 24;
            cout<<"La hora es: "<< hora_total << minutos_total<<endl;
        }
        break;
        case 5:
        {
            int num;
            cout<<"Ingrese un numero impar: "<<endl;
            cin>>num;
            if (num % 2 == 0){
                cout<<"El numero ingresado no es impar "<< endl;
                return 1;
            }

            for (int i= 1; i<= num; i += 2){
                int espacios = (num-i)/2;

                for (int j=0; j<espacios; j++){
                    cout<< " ";
                }

                for (int k=0; k<i; k++){
                    cout<<"*";
                }

                cout<<endl;
            }

            for (int i = num -2; i>0; i -=2){
               int espacios = (num-i)/2;

                for (int j=0; j<espacios; j++){
                    cout<< " ";
                }

                for (int k=0; k<i; k++){
                    cout<<"*";
                }

                cout<<endl;
            }
        }
        break;
        case 6:
        {
            int num;
            double e = 0, factorial = 1;

            cout << "Ingrese un valor para aproximar e: ";
            cin>>num;

            for(int i=0; i<num; ++i){
                if (i>0){
                    factorial *= i;
                }
                e += 1 /factorial;
            }

            cout<<"e es aproximadamente: "<<e<<endl;
        }
        break;
        case 7:
        {
            int num, suma=0, suma_total=0, a=1, b=1;
            cout<<"ingrese un numero"<<endl;
            cin>>num;

            while (suma<num){
                suma = a + b;
                if (suma % 2 == 0 && suma<num){
                    suma_total += suma;
                }
                a=b;
                b=suma;
            }

            cout<<"el resultado de la suma es:  "<<suma_total<<endl;

        }
        break;
        case 8:
        {
            int suma = 0, a, b, c;
            cout<<"Ingrese un numero A: "<<endl;
            cin>>a;
            cout<<"Ingrese un numero B: "<<endl;
            cin>>b;
            cout<<"Ingrese un numero C: "<<endl;
            cin>>c;

            cout<<"Para a="<<a<< ", b= "<<b<<" y c"<< c << ", se sumarian: ";

            bool primero = true;
            for (int i = 1; i<c; i++){
                if (i % a == 0|| i % b == 0){
                    if (!primero){
                        cout<<"+";
                    }
                    cout<<i;
                    suma +=i;
                    primero = false;
                }
            }
            cout<<" = "<< suma<< endl;
        }
        break;
        case 9:
        {
            int suma = 0,digito=0, num=0;
            cout<<"Ingrese un numero entero N: "<<endl;
            cin>>num;
            int num_temp = num;
            while (num_temp != 0){
                digito= num_temp % 10;
                suma += Potencia(digito, digito);
                num_temp /= 10;
            }


            cout<<"El resultado de la suma es:  "<<suma<<endl;
        }
        break;
        case 10:
        {
            int num, num1=2, contador=0;
            cout<<"Ingrese el valor de N: "<<endl;
            cin>>num;

            while (true){
                if (esPrimo(num1)){
                    contador++;
                    if (contador == num){
                        cout << "El primo numero "<<num<<" es: " << num1<<endl;
                        break;
                    }
                }
                num1++;
            }
        }
        break;
        case 11:
        {
            int num, mcm = 1;
            cout<<"Ingrese un numero: ";
            cin>>num;

            for (int i=2; i<=num; ++i ){
                int a = mcm, b=i;
                while(b != 0){
                    int temp = b;
                    b = a % b;
                    a = temp;
                }
                mcm = (mcm * i) / a;
            }

            cout<<"El minimo comun multiplico es: "<<mcm<<endl;
        }
        break;
        case 12:
        {
            int num;
            cout<<"Ingrese un numero: ";
            cin>>num;

            int factoPrimo= 2;
            int mayorfactor = 0;
            int numero_inicial = num;

            while (num > 1){
                if (num % factoPrimo == 0){
                    mayorfactor = factoPrimo;
                    num /= factoPrimo;
                }
                else{
                    factoPrimo ++;
                }
            }
            cout<<"el mayor primo de "<< numero_inicial<< " es: "<<mayorfactor<<endl;
        }
        break;
        case 13:
        {
            int suma = 0, num=0;

            cout<<"Ingrese un numero: ";
            cin>>num;

            for(int i=0;i<=num; i++ ){
                if (esPrimo(i)){
                    suma += i;
                }

            }
            cout<<"El resultado de la suma es "<<suma<<endl;
        }
        break;
        case 14:
        {
            int num_palindro = 0,num=0, num1=0;

            for(int i=100; i<1000; i++){
                for(int j=100; j<1000; j++){
                    int producto = i *j;
                    int original= producto;
                    int reverso = 0;

                    while (producto>0){
                        reverso = reverso * 10 + producto %10;
                        producto /= 10;
                    }

                    if (original == reverso && original >num_palindro){
                        num_palindro = original;
                        num=i;
                        num1=j;
                    }
                }
            }
            cout<<num<<"*"<<num1<<"="<<num_palindro<<endl;
        }
        break;
        case 15:
        {
            int n,num=1,suma=1;
            cout<<"Ingrese un numero impar para la espiral NxN: ";
            cin>>n;

            if(n % 2 == 0){
                cout <<"el numero debe ser impar"<<endl;
                return 1;
            }

            for(int i=2; i<=n; i+=2){
                for (int j=0; j<4; ++j){
                    num += i;
                    suma += num;
                }
            }

            cout<<"La suma de los numeros en la diagonal de la espiral de "<<n<<"x"<<n<<"es: "<<suma<<endl;
        }
        break;
        case 16:
        {
            int k, longitud_max= 0, semilla_max=0;
            cout<<"Ingrese el numero K:";
            cin>>k;

            for (int j=2; j<k; ++j){
                int n= j;
                int longitud =1;

                while(n != 1){
                    if(n % 2 == 0){
                        n = n/2;
                    }
                    else{
                        n = 3 * n + 1;
                    }
                    longitud++;
                }

                if (longitud>longitud_max){
                    longitud_max = longitud;
                    semilla_max = j;
                }
            }
            cout<<"la serie mas larga es con la semilla "<<semilla_max<<" teniendo "<<longitud_max<<" terminos"<<endl;
        }
        break;
        case 17:
        {
            int k, n=1,triangular = 0, contador = 0;
            cout<<"Ingrese el numero de divisores deseados: ";
            cin>>k;

            while (true){
                triangular = n * (n+1) /2;
                contador =0;

                for (int i=1; i<=triangular; ++i ){
                    if (triangular % i == 0){
                        ++contador;
                    }
                }

                if (contador>k){
                    break;
                }
                n++;
            }
            cout<<"el numero es: "<<triangular<<" que tiene "<<contador<<" divisores"<<endl;
        }
        break;
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

bool esPrimo(int numero) {
    if (numero <= 1) {
        return false;
    }
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return false;
        }
    }
    return true;
}

int Potencia(int base, int exponente)
{
    int x=1;
    for(int i=0; i<exponente;i++)
        x*= base;
    return x;
}
