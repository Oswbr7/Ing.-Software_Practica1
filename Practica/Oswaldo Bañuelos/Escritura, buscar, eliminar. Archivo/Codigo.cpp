#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <cstring>

using namespace std;


class Archivo{
private:
    string Codigo, Nombre, ApePaterno, ApeMaterno, Correo, Carrera;
public:
    void Capturar();
    void Mostrar();
    void Buscar();
    void Modificar();
    void Eliminar();
    void Menu();
};

void Archivo::Capturar(){
    fstream Escritor;

    Escritor.open("Datos.txt", ios::out); //Abriendo Archivo

    if(Escritor.fail()){
        cout << "No fue posible abrir el archivo" << endl;
        exit(1);
    }

   for(int i = 0; i <= 2; i++){
       cout << "Dame el Codigo del Alumno: "; getline(cin, Codigo);
       cout << "Dame el Nombre del Alumno: "; getline(cin, Nombre);
       cout << "Dame el Apellido Paterno del Alumno: "; getline(cin, ApePaterno);
       cout << "Dame el Apellido Materno del Alumno: "; getline(cin, ApeMaterno);
       cout << "Dame el Correo del Alumno: "; getline(cin, Correo);
       cout << "Dame la Carrera del Alumno: "; getline(cin, Carrera);
       Escritor << Codigo << "#" << Nombre << "#" << ApePaterno << "#" << ApeMaterno << "#" << Correo << "#" << Carrera << "$";
   }

    Escritor.close();
}

void Archivo::Mostrar(){
    string Texto_2, CadenaRegistro, CadenaCampo;
    int NoRegistro=0, Pos_1, Pos_2, TamCampo;

    fstream Escritor;
    fstream Archivo_Aux;


	Escritor.open("Datos.txt", ios::in);

    if(Escritor.fail()){
        cout << "No se ha podido abrir el archivo" << endl;
        exit(1);
    }else{
    	getline(Escritor,Texto_2);

    	for(int i=0; i < Texto_2.length(); i++){
    		if(Texto_2[i] == '$'){
				NoRegistro++;
			}
    	}
    	for(int i=0; i<NoRegistro; i++){
            string CadAux;

            Pos_1 = Texto_2.find_first_of('$',0);
            CadenaRegistro = Texto_2.substr(0, Pos_1);
            CadAux = CadenaRegistro + "$";

            cout << CadAux << endl;
            cout << "Registro: " << CadenaRegistro << endl;

            Pos_2 = CadenaRegistro.find_first_of('#',0);
            CadenaCampo = CadenaRegistro.substr(0, Pos_2);

            cout << "Codigo Alumno: " << CadenaCampo << endl;

            Pos_1 = Pos_2+1;
            Pos_2 = CadenaRegistro.find_first_of('#', Pos_1);
            TamCampo = Pos_2 - Pos_1;
            CadenaCampo = CadenaRegistro.substr(Pos_1, TamCampo);

            cout << "Nombre del Alumno: " << CadenaCampo << endl;

            Pos_1 = Pos_2+1;
            Pos_2 = CadenaRegistro.find_first_of('#', Pos_1);
            TamCampo = Pos_2 - Pos_1;
            CadenaCampo = CadenaRegistro.substr(Pos_1, TamCampo);

            cout << "Apellido Paterno del Alumno: " << CadenaCampo << endl;

            Pos_1 = Pos_2+1;
            Pos_2 = CadenaRegistro.find_first_of('#', Pos_1);
            TamCampo = Pos_2 - Pos_1;
            CadenaCampo = CadenaRegistro.substr(Pos_1, TamCampo);

            cout << "Apellido Materno del Alumno: " << CadenaCampo << endl;

            Pos_1 = Pos_2+1;
            Pos_2 = CadenaRegistro.find_first_of('#', Pos_1);
            TamCampo = Pos_2 - Pos_1;
            CadenaCampo = CadenaRegistro.substr(Pos_1, TamCampo);

            cout << "Correo del Alumno: " << CadenaCampo << endl;
            
            Pos_1 = Pos_2 + 1;
            Pos_2 = CadAux.find('$', Pos_1);
            TamCampo = Pos_2 - Pos_1;
            CadenaCampo = CadenaRegistro.substr(Pos_1, Texto_2.length());

            cout << "Carrera del Alumno: " << CadenaCampo << endl;

            Pos_1 = Pos_2 + 1;
            Archivo_Aux.open("ArchivoAuxiliar.txt", ios::in | ios::out);
            for (int j=Pos_1; j<Texto_2.length();j++){
                Archivo_Aux << Texto_2[j];
            }

            Archivo_Aux.close();

            Texto_2 = "";
            Archivo_Aux.open("ArchivoAuxiliar.txt", ios::in);
            getline(Archivo_Aux, Texto_2);

            Archivo_Aux.close();
    	}
    }

    Escritor.close();
}

void Archivo::Buscar(){
    
    fstream Entrada;
    Entrada.open("Datos.txt", ios::in);

    fstream Archivo_Aux;


    int Pos_1, Pos_2, Pos_3 = 0, NoRegistros = 0, TamCampo;
    string Texto_2, CadenaRegistro, CadenaCampo, CadAux, CodigoBus;


    if(Entrada.fail()){
        cout << "No fue posible abrir el archivo, intente de nuevo" << endl;
    }else{
        getline(Entrada,Texto_2);
        
    	for(int i=0; i < Texto_2.length(); i++){
    		if(Texto_2[i] == '$'){
				NoRegistros++;
			}
    	}
        cout << "Dame el Codigo a buscar: "; getline(cin, CodigoBus);
        fflush(stdin);

        for (int i = 0; i < NoRegistros; i++){

            Pos_1 = Texto_2.find_first_of('$',Pos_3);
            CadenaRegistro = Texto_2.substr(Pos_3, Pos_1);
            CadAux = CadenaRegistro + "$";
            Pos_2 = Texto_2.find_first_of('#', Pos_3);
            CadenaCampo = CadenaRegistro.substr(Pos_3, Pos_2);

            if (CadenaCampo == CodigoBus){
                cout << "Se ha encontrado a la Persona\n" << endl;
                cout << "Codigo: " << CadenaCampo << endl;

                Pos_3 = Pos_2 + 1;
                Pos_2 = CadenaRegistro.find_first_of('#', Pos_3);
                TamCampo = Pos_2 - Pos_3;
                CadenaCampo = CadenaRegistro.substr(Pos_3, TamCampo);

                cout << "Nombre: " << CadenaCampo << endl;

                Pos_3 = Pos_2 + 1;
                Pos_2 = CadenaRegistro.find_first_of('#', Pos_3);
                TamCampo = Pos_2 - Pos_3;
                CadenaCampo = CadenaRegistro.substr(Pos_3, TamCampo);

                cout << "Apellido Paterno: " << CadenaCampo << endl;

                Pos_3 = Pos_2 + 1;
                Pos_2 = CadenaRegistro.find_first_of('#', Pos_3);
                TamCampo = Pos_2 - Pos_3;
                CadenaCampo = CadenaRegistro.substr(Pos_3, TamCampo);

                cout << "Apellido Materno: " << CadenaCampo << endl;

                Pos_3 = Pos_2 + 1;
                Pos_2 = CadenaRegistro.find_first_of('#', Pos_3);
                TamCampo = Pos_2 - Pos_3;
                CadenaCampo = CadenaRegistro.substr(Pos_3, TamCampo);

                cout << "Correo del Alumno: " << CadenaCampo << endl;

                Pos_3 = Pos_2 + 1;
                TamCampo = Pos_1 - Pos_3;
                CadenaCampo = CadenaRegistro.substr(Pos_3, Pos_1);

                cout << "Carrera del Alumno: " << CadenaCampo << endl;

                i = NoRegistros;

            }else{
                cout << "\nIntento de Encontrar a la Persona Fallido" << endl;
                cout << "Iniciando Nuevo Intento\n" << endl; 
            }
            Pos_1 = Pos_1 + 1;
            Archivo_Aux.open("ArchivoAuxiliar.txt", ios::out);
            for (int j=Pos_1; j<Texto_2.length();j++){
                Archivo_Aux << Texto_2[j];
            }
            Archivo_Aux.close();
            Texto_2 = "";
            Archivo_Aux.open("ArchivoAuxiliar.txt", ios::in);
            getline(Archivo_Aux, Texto_2);
            Archivo_Aux.close();
            
        }

        Entrada.close();
        remove("ArchivoAuxiliar.txt");
        
    }

}
/*
void Archivo::Eliminar(){
    string Temporal, TextoEntero, CadenaCampo, CadenaRegistro;
    int Pos_1, Pos_2, NoRegistros = 0, Pos_3 = 0;

    fstream Escritor;
    Escritor.open("Datos.txt", ios::in);

    fstream Entrada;
    Entrada.open("Temp.txt", ios::out);

    if(Escritor.fail()){
        cout << "No fue posible abrir el archivo" << endl;
    }else{
        cout << "Dame el codigo del Alumno a borrar: "; cin>>Temporal;
        getline(Escritor, TextoEntero);
        for(int i=0; i<TextoEntero.length(); i++){
            if(TextoEntero[i] == '$'){
                NoRegistros++;
            }
        }
        for(int i = 0; i < NoRegistros; i++){

            Pos_1 = TextoEntero.find_first_of('$', Pos_3);
            CadenaRegistro = TextoEntero.substr(Pos_3, Pos_1);
            Pos_2 = CadenaRegistro.find_first_of('#', Pos_3);
            CadenaCampo = CadenaRegistro.substr(Pos_3, Pos_2);
            if (CadenaCampo == Temporal){
                cout << "Se elimino el codigo" << endl;
            }else{
                Entrada << CadenaRegistro;
            }
            Pos_3 = Pos_1 + 1;
        }
            Entrada.close();
            Escritor.close();

            remove("Datos.txt");
            rename("Temp.txt", "Datos.txt");

    }

}
*/
void Archivo::Menu(){
    int Opcion;

    do
    {
        cout << "\n--------------Menu------------" << endl;
        cout << "\n1.- Capturar\n2.-Mostrar\n3.-Buscar\n4.-Modificar\n5.-Eliminar\n6.-Salir\n" << endl;
        cout << "Digite la Opcion que desea usar: " << endl; cin >> Opcion;
        fflush(stdin);
        switch (Opcion)
        {
        case 1:
            Archivo::Capturar();
            break;
        case 2:
            Archivo::Mostrar();
            break;
        case 3:
            Archivo::Buscar();
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            cout << "\nGracias por usar este programa" << endl;
            break;
        default:
            cout << "Opcion invalida, por favor digite de nuevo" << endl;
            break;
        }
    } while (Opcion != 6);

}

int main (){
    Archivo Arc;
    //Arc.Capturar();
    //Arc.Mostrar();
    Arc.Buscar();
    //Arc.Eliminar();
    //Arc.Menu();

}

