//
// Created by Maikol Guzman  on 2019-08-08.
//

#include <iostream>
#include "CalculoPrestamo.h"

alculoPrestamo::CalculoPrestamo(){
    monto=0;
}
CalculoPrestamo::CalculoPrestamo(int64_t monto) : monto(monto) {
}

void CalculoPrestamo::setMonto(float monto) {
    this-> monto = monto;
}

float CalculoPrestamo::getMonto() const {
    return monto;
}

float CalculoPrestamo::obtenerPorcentaje(std::string porcentajeTXT) {//find(8.50%),substrg(0,4),std::stof("8,50)
    float porcentaje = 0;
    int busca = porcentajeTXT.find("%");
    if (busca > 0) {
        porcentaje = std::stof(porcentajeTXT.substr(0, busca));
        if (porcentaje > 0) {
            porcentaje = porcentaje / 100;
        }
    }
    return porcentaje;
}

int CalculoPrestamo::calcularTiempoEnMeses(std::string tiempoTXT) {
    int ano = 0;
    int meses = 0;
    int buscarA = tiempoTXT.find("A");
    int buscarM = tiempoTXT.find("M");
    if (buscarA > 0) {
        ano = stoi(tiempoTXT.substr(0, buscarA));
        meses = ano * 12;
        if (buscarM > 0)
            meses = stoi(tiempoTXT.substr(0, buscarM));
    }
    return meses;
}

float CalculoPrestamo::calcularInteresMensual(float balance, float tasaAnual) {
    float pormes = tasaAnual / 12;
    float interes = (pormes * balance);
    return interes;
}

std::string CalculoPrestamo::reporteCalculoPrestamo(std::string tiempoTXT, std::string porcentajeTXT) {
    std::string reporte = " ";
    int mes = calcularTiempoEnMeses(tiempoTXT);
    float porcentaje = obtenerPorcentaje(porcentajeTXT);
    float balance = getMonto();
    float nuevo = getMonto();
    for (int i = 1; i < mes; i++) {
        float interes = calcularInteresMensual(nuevo, porcentaje);
        balance = nuevo;
        nuevo = balance + interes;
        reporte = reporte + "tasa [" + porcentajeTXT + "], Mes" + "[" + std::to_string(i) + "] ,balance inicial  [" + std::to_string(getMonto()) + "], interes [" + std::to_string(interes) + "] ,balance nuevo [" + std::to_string(nuevo) + "]\n";
    }
    return reporte;
}