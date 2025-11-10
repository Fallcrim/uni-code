#include "../include/meine_funktionen.hpp"
#include <iostream>
#include <string>

int main() {
    // Hier Sinus, Kosius, usw für einige Werte ausrechnen
    double sin = sinus(22.3, 1e-12);
    double cos = kosinus(22.3);
    double tan = tangens(22.3, 1e-10);
    double cotan = kotangens(22.3);
    // und Ergebnisse ausdrucken
    std::cout << "Sinus von 22.3 mit Toleranz 1e-12: " << std::to_string(sin) << std::endl;
    std::cout << "Kosinus von 22.3 mit Standard-Toleranz: " << std::to_string(cos) << std::endl;
    std::cout << "Tangens von 22.3 mit Toleranz 1e-12: " << std::to_string(tan) << std::endl;
    std::cout << "Kotangens von 22.3 mit Standard-Toleranz: " << std::to_string(cotan) << std::endl;
}
