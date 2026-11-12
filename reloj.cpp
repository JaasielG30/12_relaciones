#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


class Display {
private:
    string tipo;

public:
    
    Display(string t = "digital") {
        tipo = t;
    }

 
    string getTipo() const {
        return tipo;
    }

    void setTipo(string t) {
        tipo = t;
    }
};


class Hora {
private:
    int hora;
    int minutos;
    int segundos;

public:
    
    Hora(int h, int m, int s) {
        hora = h;
        minutos = m;
        segundos = s;
    }


    int getHora() const { return hora; }
    int getMinutos() const { return minutos; }
    int getSegundos() const { return segundos; }
};


class Reloj {
private:
    Display* pDisplay;
    Hora* pHora;    

public:
 
    Reloj(int h, int m, int s) {
        pHora = new Hora(h, m, s);
        pDisplay = nullptr;
    }

    
    ~Reloj() {
        delete pHora;
    }

  
    void asignarDisplay(Display* pD) {
        pDisplay = pD;
    }

    
    void mostrarReloj() {
        if (pDisplay == nullptr || pHora == nullptr) return;

        string tipo = pDisplay->getTipo();
        
    
        string hStr = (pHora->getHora() < 10 ? "0" : "") + to_string(pHora->getHora());
        string mStr = (pHora->getMinutos() < 10 ? "0" : "") + to_string(pHora->getMinutos());
        string sStr = (pHora->getSegundos() < 10 ? "0" : "") + to_string(pHora->getSegundos());
        string horaFormateada = hStr + ":" + mStr + ":" + sStr;

       
        if (tipo == "digital") {
            cout << "[" << horaFormateada << "]" << endl;
        } else if (tipo == "analogico" || tipo == "analógico") {
            cout << "-->" << horaFormateada << "<--" << endl;
        }
    }
};


int main() {

    Display displayDigital("digital");
    Display displayAnalogico("analogico");


    Reloj reloj1(10, 15, 55);
    reloj1.asignarDisplay(&displayDigital);

    Reloj reloj2(10, 15, 55);
    reloj2.asignarDisplay(&displayAnalogico);

 	
    reloj1.mostrarReloj();
    reloj2.mostrarReloj();

    return 0;
}