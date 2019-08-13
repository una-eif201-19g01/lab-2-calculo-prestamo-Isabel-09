//
// Created by Maikol Guzman  on 2019-08-08.
//

#ifndef CALCULOPRESTAMO_CALCULOPRESTAMO_H
#define CALCULOPRESTAMO_CALCULOPRESTAMO_H
#include <cstdint>
#include <string>

class CalculoPrestamo {
private:
    float monto;
    float obtenerPorcentaje(std::string porcentajeTXT); //find(%)=1,substrg(0,4),std::stof("8,50)string a entero
    int calcularTiempoEnMeses(std::string tiempoTXT);
    float calcularInteresMensual(float balance, float tasaAnual);
public:

    CalculoPrestamo();

    ~CalculoPrestamo();

    CalculoPrestamo(int64_t monto);

    std::string reporteCalculoPrestamo(std::string tiempoTXT, std::string porcentajeTXT);//\n separar linea

    void setMonto(float monto) {
        this->monto = monto;
    }

    float getMonto() const {
        return monto;
    }
};






#endif //CALCULOPRESTAMO_CALCULOPRESTAMO_H
