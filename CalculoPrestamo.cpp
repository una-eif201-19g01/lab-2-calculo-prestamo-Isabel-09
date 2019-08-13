//
// Created by Maikol Guzman  on 2019-08-08.
//

#include <iostream>
#include "CalculoPrestamo.h"

CalculoPrestamo::CalculoPrestamo(){
    monto=0;
}
CalculoPrestamo::CalculoPrestamo(int64_t monto){
    this->monto= monto;
}
void CalculoPrestamo::setMonto(float monto){
    this-> monto=monto;
}
float CalculoPrestamo::getMonto(float monto){
    return monto;
}
float CalculoPrestamo::obtenerPorcentaje(std::string porcentajeTXT){//find(8.50%),substrg(0,4),std::stof("8,50){
    int num = find(porcentajeTXT);
    std::string str =" ";
     std::string cadena=str.substr(0,num);       
    float porcentaje= stof(cadena);
    return porcentaje;
}
int CalculoPrestamo::calcularTiempoEnMeses(std::string tiempoTXT){
    int num = find(tiempoTXT);
    std::string str =" ";
     std::string cadena=str.substr(0,num);  
     if(cadena=="A"){
       int tiempo= stof(cadena); 
     
     return (tiempo *12);
}
}
float CalculoPrestamo::calcularInteresMensual(float balance, float tasaAnual){
    return (balance*tasaAnual)/12;
}
std::string CalculoPrestamo::reporteCalculoPrestamo(std::string tiempoTXT, std::string porcentajeTXT){
    int lar=calcularTiempoEnMeses(tiempoTXT);
    float por=obtenerPorcentaje(porcentajeTXT);
    float nuevo=calcularInteresMensual(monto,por)+monto;
    for(int i=1;i<lar;i++){
  "tasa"+ "[" + porcentajeTXT +"]"+"Mes"+"["+std::to_string(i)+"]"+"balance inicial" +"[" +std::to_string(getMonto())+"]"+"interes"+calcularInteresMensual(monto,por)+"balance nuevo"+nuevo;
}
}