#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int main (){
    //variables
    string ident, apoyo, ncv, x0, x1, x2, x3;
    string nombre, sede, licenciatura, nivel, estado;
    string recargos, eca, depo, ajustado, pago, saldo, saldo_vencido, a0, b0, c0, d0, porcentaje0, b1, a1, p1, s1, porcentaje1, b2, a2, p2, s2, porcentaje2, b3, a3, p3, s3, porcentaje3;
    vector<int>idunid;
    vector<string>alumno;
    vector<string>prog_unid;
    vector<double>saldo_atrasado_pesos;
    vector<int>colegiaturas_vencidas;
    vector<bool>check;


    string miarchivo;
    cout<<"Ingrese el nombre del archivo para analizar: ";
    cin >> miarchivo;

    int i = 0;
    int deuda = 0;

    ifstream read(miarchivo);
    if (read.is_open()) {
        string line;
        getline(read, line);

        while (!read.eof()) {
            getline(read, ident,',');
            idunid.push_back(stoi(ident));
            getline(read, nombre, ',');
            alumno.emplace_back(nombre);
            getline(read, sede, ',');
            getline(read, licenciatura, ',');
            prog_unid.emplace_back(licenciatura);
            getline(read, nivel, ',');
            getline(read, estado, ',');
            getline(read, apoyo, ',');
            getline(read, recargos, ',');
            getline(read, eca, ',');
            getline(read, depo, ',');
            getline(read, ajustado, ',');
            getline(read, pago, ',');
            getline(read, saldo, ',');
            getline(read, saldo_vencido, ',');
            saldo_atrasado_pesos.push_back(stod(saldo_vencido));
            if (stoi(saldo_vencido) > 0) {
                check.emplace_back(true);
                deuda += 1; //mostrar cuantos deben
            } else check.emplace_back(false);
            getline(read, ncv, ',');
            colegiaturas_vencidas.push_back(stoi(ncv));
            getline(read, x0, ',');
            getline(read, b0, ',');
            getline(read, a0, ',');
            getline(read, c0, ',');
            getline(read, d0, ',');
            getline(read, porcentaje0, ',');
            getline(read, x1, ',');
            getline(read, b1, ',');
            getline(read, a1, ',');
            getline(read, p1, ',');
            getline(read, s1, ',');
            getline(read, porcentaje1, ',');
            getline(read, x2, ',');
            getline(read, b2, ',');
            getline(read, a2, ',');
            getline(read, p1, ',');
            getline(read, s1, ',');
            getline(read, porcentaje3, ',');

            i += 1;
        }

    read.close();

        cout<<"Numero de entradas: "<<i<<endl;



    }
    else cout <<"No se puede abrir el archivo"<<endl;


    cout << "¿Que operación desea realizar?" << endl;
    cout
            << "1)Contar cuantos deudores hay. 2)Buscar ID de alumno. 3)Ver por programa academico. 4)Ver todos los deudores. 5)Salir"
            << endl;
    cout << "Numero de opcion: ";
    int numero;
    cin >> numero;

    switch(numero) {
        case 1:
            cout << "Numero de deudores: " << deuda << endl;
            break;
        case 2: {
            cout << "Ingrese el id del alumno: ";
            int id_buscar;
            cin >> id_buscar;
            cout << "ID" << "\t" << "Nombre" << "\t" << "programa" << "\t" << "saldo vencido" << endl;
            for (int j = 0; j < i; j++) {
                if (idunid[j] == id_buscar)
                    cout << idunid[j] << "\t" << alumno[j] << "\t" << prog_unid[j] << "\t"
                         << saldo_atrasado_pesos[j]
                         << "\t" << check[j] << endl;
            }
        }
            break;
        case 3: {
            cout << "Ingrese la clave del programa: ";
            string buscar_programa;
            cin >> buscar_programa;
            cout << "ID" << "\t" << "Nombre" << "\t" << "programa" << "\t" << "saldo vencido" << endl;
            for (int j = 0; j < i; j++) {
                if (prog_unid[j].compare(buscar_programa) == 0)
                    cout << idunid[j] << "\t" << alumno[j] << "\t" << prog_unid[j] << "\t"
                         << saldo_atrasado_pesos[j]
                         << "\t" << check[j] << endl;
            }
        }
            break;
        case 4: {
            for (int j = 0; j < i; j++) {
                cout << "ID" << "\t" << "Nombre" << "\t" << "programa" << "\t" << "saldo vencido" << endl;
                if (saldo_atrasado_pesos[j] > 0)
                    cout << idunid[j] << "\t" << alumno[j] << "\t" << prog_unid[j] << "\t"
                         << saldo_atrasado_pesos[j] << "\t" << check[j] << endl;
            }

        }
        case 5:
        {
            return 0;
        }
    }


}

