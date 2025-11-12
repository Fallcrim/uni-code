#include "../include/meine_funktionen.hpp"
#include <iostream>
#include <cmath>


double sinus(double x) {
    double sinus = 0;
    double summand = x;
    double zaehler_helfer = 1;
    double klein = 1e-8;

    while (summand > klein || -summand > klein) {
        sinus += summand;
        summand = -(summand * x * x) / ((zaehler_helfer + 1) * (zaehler_helfer + 2));
        zaehler_helfer += 2;
    }
    return sinus;
}

double kosinus (double x) {
    double kosinus = 0;
    double summand = 1;
    double zaehler_helfer = 0;
    double klein = 1e-8; // Genauigkeit; stoppt wenn Summand zu klein wird

    while (summand > klein || -summand  > klein) {
        kosinus += summand;
        summand = -(summand * x * x) / ((zaehler_helfer + 1) * (zaehler_helfer + 2)); // Taylorreihe cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ...
        zaehler_helfer += 2;
    }
    return kosinus;
}

double sinus(double x, double toleranzwert) { // Kopie von sinus(double x) mit manuell setzbarem Parameter toleranzwert
    double sinus = 0;
    double summand = x;
    double zaehler_helfer = 1;

    while (summand > toleranzwert || -summand > toleranzwert) {
        sinus += summand;
        summand = -(summand * x * x) / ((zaehler_helfer + 1) * (zaehler_helfer + 2));
        zaehler_helfer += 2;
    }
    return sinus;
}

double kosinus (double x, double toleranzwert) { // Kopie von kosinus(double x) mit manuell setzbarem Parameter toleranzwert
    double kosinus = 0;
    double summand = 1;
    double zaehler_helfer = 0;

    while (summand > toleranzwert || -summand  > toleranzwert) {
        kosinus += summand;
        summand = -(summand * x * x) / ((zaehler_helfer + 1) * (zaehler_helfer + 2)); // Taylorreihe cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ...
        zaehler_helfer += 2;
    }
    return kosinus;
}

double tangens(double x) {
    double cos = kosinus(x);
    if (cos == 0) { // Verhindert Division durch 0
        std::cout << "FEHLER: Tangens nicht definiert für " + std::to_string(x) << std::endl;
        return NAN;
    }
    return sinus(x) / cos;
}

double kotangens(double x) {
    double sin = sinus(x);
    if (sin == 0) { // Verhindert Division durch 0
        std::cout << "FEHLER: Kotangens nicht definiert für " + std::to_string(x) << std::endl;
        return NAN;
    }
    return kosinus(x) / sin;
}

double tangens(double x, double toleranzwert) { // Kopie von tangens(double x) mit manuell setzbarem Parameter toleranzwert
    double cos = kosinus(x, toleranzwert);
    if (cos == 0) { // Verhindert Division durch 0
        std::cout << "FEHLER: Tangens nicht definiert für " + std::to_string(x) << std::endl;
        return NAN;
    }
    return sinus(x) / cos;
}

double kotangens(double x, double toleranzwert) { // Kopie von kotangens(double x) mit manuell setzbarem Parameter toleranzwert
    double sin = sinus(x, toleranzwert);
    if (sin == 0) { // Verhindert Division durch 0
        std::cout << "FEHLER: Kotangens nicht definiert für " + std::to_string(x) << std::endl;
        return NAN;
    }
    return kosinus(x) / sin;
}