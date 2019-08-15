#include <iostream>
#include "string.h"
#include "CalculoPrestamo.h"

int main() {
    CalculoPrestamo Prestamo(30000);

    std::string reporte;

    reporte = Prestamo.reporteCalculoPrestamo("1A", "8.40%");

    std::cout << "Calculo Prestamo es :" << std::endl;
    std::cout << reporte << std::endl;
    return 0;
}