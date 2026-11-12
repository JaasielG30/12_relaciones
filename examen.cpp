#include <iostream>
#include <string>

using namespace std;


class Fecha {
private:
    int dia;
    int mes;
    int anio;

public:

    Fecha(int d, int m, int a) {
        dia = d;
        mes = m;
        anio = a;
    }


    int getDia() const { return dia; }
    int getMes() const { return mes; }
    int getAnio() const { return anio; }


    string mostrarFecha() const {
        string dStr = (dia < 10 ? "0" : "") + to_string(dia);
        string mStr = (mes < 10 ? "0" : "") + to_string(mes);
        return dStr + "/" + mStr + "/" + to_string(anio);
    }
};


class Hora {
private:
    int hora;
    int minuto;

public:

    Hora(int h, int m) {
        hora = h;
        minuto = m;
    }


    int getHora() const { return hora; }
    int getMinuto() const { return minuto; }


    string mostrarHora() const {
        string hStr = (hora < 10 ? "0" : "") + to_string(hora);
        string mStr = (minuto < 10 ? "0" : "") + to_string(minuto);
        return hStr + ":" + mStr;
    }
};


class Examen {
private:
    string nombreAsignatura;
    int ciclo;
    Fecha fechaExamen; 
    Hora horaExamen; 

public:

    Examen(string asignatura, int cic, int d, int m, int a, int h, int min)
        : nombreAsignatura(asignatura), ciclo(cic), fechaExamen(d, m, a), horaExamen(h, min) {}

    void mostrarExamen() const {
        cout << "Asignatura: " << nombreAsignatura << endl;
        cout << "Ciclo: " << ciclo << endl;
        cout << "Fecha: " << fechaExamen.mostrarFecha() << endl;
        cout << "Hora: " << horaExamen.mostrarHora() << endl;
        cout << "-----------------------------------" << endl;
    }
};


int main() {

    Examen examen1("Programacion Orientada a Objetos", 3, 15, 11, 2026, 14, 30);
    
  
    examen1.mostrarExamen();

    return 0;
}