#include <iostream>
#include <string>
#include <cctype>

std::string evaluarFortaleza(const std::string& contrasenia) {
    if (contrasenia.empty()) return "La contraseña no puede estar vacía.";

    int longitud = contrasenia.length();
    bool tieneMayuscula = false;
    bool tieneMinuscula = false;
    bool tieneNumero = false;
    bool tieneEspecial = false;

    for (char c : contrasenia) {
        if (isupper(c)) tieneMayuscula = true;
        else if (islower(c)) tieneMinuscula = true;
        else if (isdigit(c)) tieneNumero = true;
        else if (ispunct(c)) tieneEspecial = true;
    }

    int criteriosCumplidos = 0;
    if (longitud >= 8) criteriosCumplidos++;
    if (tieneMayuscula && tieneMinuscula) criteriosCumplidos++;
    if (tieneNumero) criteriosCumplidos++;
    if (tieneEspecial) criteriosCumplidos++;

    if (longitud < 6) {
        return "Muy Débil (Demasiado corta)";
    }

    switch (criteriosCumplidos) {
        case 4: return "Excelente / Muy Segura";
        case 3: return "Fuerte / Segura";
        case 2: return "Moderada (Mejorable)";
        default: return "Débil";
    }
}

int main() {
    // Estructura base temporal para probar el validador
    std::string pass = "Prueba123!";
    std::cout << "Validando contraseña de prueba '" << pass << "': " << evaluarFortaleza(pass) << "\n";
    return 0;
}