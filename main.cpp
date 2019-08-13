#include <iostream>
#include "string.h"
#include "CalculoPrestamo.h"

int main() {
    CalculoPrestamo Prestamo(30000.000);
    Prestamo.reporteCalculoPrestamo("2A","8,4%");
    return 0;
}