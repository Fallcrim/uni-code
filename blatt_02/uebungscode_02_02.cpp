// Zur Blatt 02 Aufgabe 03

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

// Druckt einen Text aus
void drucke_text(const std::string& text);

// Druckt eine Ganzzahl aus
void drucke_ganzzahl(int ganzzahl);

// Druckt eine Kommazahl aus
void drucke_kommazahl(double gleitkommazahl);

// Liest ein Wort von der Konsole ein
std::string lies_wort();

// Liest eine Ganzzahl von der Konsole ein
int lies_ganzzahl();

// Liest eine Gleitkommazahl von der Konsole ein
double lies_gleitkommazahl();


void ablauf_diagramm_1(){
  drucke_text("Gib eine Zahl ein:");
  double x = lies_gleitkommazahl();
  x = x*x;
  drucke_kommazahl(x);
  
}

void ablauf_diagramm_2(){
  drucke_text("Gib eine Zahl größer Null ein:");
  int x = lies_ganzzahl();
  if (x <= 0) {
    drucke_text("Die Zahl muss größer als 0 sein.");
    return;
  }
  while (x > 1) {
    x = x - 2;
  }
  drucke_ganzzahl(x);
}

void programm_1() {
  drucke_text("Gib eine natürliche Zahl ein:");
  int x = lies_ganzzahl();
  if (x <= 0) {
    drucke_text("Die eingegebene Zahl muss natürlich sein.");
    return;
  }
  int y = x;
  y = y + 17;
  y = y*3;
  y = y % 2;
  drucke_ganzzahl(y);
}


void programm_2() {
  drucke_text("Gib einen Text ein:");
  std::string text = lies_wort();
  int n = text.size();
  int s = 0;
  for (int i = 0; i < n; i = i + 1) {
    if (text[i] == '!' or text[i] == '.' or text[i] == '?') {
      s = s + 1;
    }
  }
  drucke_ganzzahl(s);
}


void programm_3() {
  std::vector<int> zahlen = {42, 69, 420, 99, -444, 9014};
  int n = zahlen.size();
  int s = 0;
  for (int i = 0; i < n; i++) {
    s = s + zahlen[i];
  }
  double m = s/(n);
  drucke_kommazahl(m);
}


void programm_4() {
  int x = lies_ganzzahl();
  x = pow(x, 218);
  drucke_ganzzahl(x);
}


int main() {
  // ablauf_diagramm_1();
  // ablauf_diagramm_2();
  // programm_1();
  // programm_2();
  // programm_3();
  // programm_4();
}


/************************************/
/*                                  */
/*   MAGIE   MAGIE   MAGIE  MAGIE   */
/*                                  */
/************************************/

void drucke_text(const std::string& text) {
  std::cout << text << std::endl;
}

void drucke_ganzzahl(int ganzzahl) {
  std::cout << std::to_string(ganzzahl) << std::endl;
}

void drucke_kommazahl(double gleitkommazahl) {
  std::cout << std::to_string(gleitkommazahl) << std::endl;
}

std::string lies_wort() {
  std::string wort;
  std::cin >> wort;
  return wort;
}

int lies_ganzzahl() {
  std::string wort;
  std::cin >> wort;
  int ganzzahl = 0;
  try {
    ganzzahl = std::stoi(wort);
  } catch (const std::invalid_argument& e) {
    ganzzahl = -1000;
  }
  return ganzzahl;
}

double lies_gleitkommazahl() {
  std::string wort;
  std::cin >> wort;
  double lies_gleitkommazahl = 0.0;
  try {
    lies_gleitkommazahl = std::stod(wort);
  } catch (const std::invalid_argument& e) {
    lies_gleitkommazahl = NAN; // See https://en.cppreference.com/w/cpp/numeric/math/NAN
  }
  return lies_gleitkommazahl;
}
