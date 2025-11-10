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

double cosinus (double x) {
    double cosinus = 0;
    double summand = 1;
    double zaehler_helfer = 0;
    double klein = 1e-8; // Genauigkeit; stoppt wenn Summand zu klein wird

    while (summand > klein || -summand  > klein) {
        cosinus += summand;
        summand = -(summand * x * x) / ((zaehler_helfer + 1) * (zaehler_helfer + 2)); // Taylorreihe cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ...
        zaehler_helfer += 2;
    }
    return cosinus;
}

double tangens(double x) {
    double cos = cosinus(x);
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
    return cosinus(x) / sin;
}

double wurzel_approx(double x) {
    if (x < 0) {
        std::cout << "FEHLER: x darf nicht kleiner als 0 sein" << std::endl;
        return NAN;
    }
    double t = x;
    double abstand = std::fabs(t * t - x) / x;
    while (abstand > 0.001) {
        t = 0.5 * (t + x / t);
        abstand = std::fabs(t * t - x) / x;
    }
    return t;
}

int main() {
//     std::cout << std::to_string(wurzel_approx(2)) << std::endl;
}