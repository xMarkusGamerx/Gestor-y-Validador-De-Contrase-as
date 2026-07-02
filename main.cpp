#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib> 
#include <ctime>

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
    std::string pass = "Prueba123!";
    std::cout << "Validando contraseña de prueba '" << pass << "': " << evaluarFortaleza(pass) << "\n";
    return 0;
}

std::string generarContrasenia(int longitud) {
    if (longitud < 4) longitud = 8; 

    const std::string minusculas = "abcdefghijklmnopqrstuvwxyz";
    const std::string mayusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string numeros = "0123456789";
    const std::string especiales = "!@#$%^&*()-_=+[{]};:',<.>/?";
    const std::string todo = minusculas + mayusculas + numeros + especiales;

    std::string contrasenia = "";

    contrasenia += minusculas[rand() % minusculas.length()];
    contrasenia += mayusculas[rand() % mayusculas.length()];
    contrasenia += numeros[rand() % numeros.length()];
    contrasenia += especiales[rand() % especiales.length()];

    for (int i = 4; i < longitud; ++i) {
        contrasenia += todo[rand() % todo.length()];
    }

    for (int i = 0; i < longitud; ++i) {
        int r = rand() % longitud;
        std::swap(contrasenia[i], contrasenia[r]);
    }

    return contrasenia;
}

int main() {
    srand(time(0));
    std::string generada = generarContrasenia(10);
    std::cout << "Contraseña generada de prueba: " << generada << "\n";
    std::cout << "Fortaleza de la generada: " << evaluarFortaleza(generada) << "\n";
    return 0;
}

void mostrarMenu() {
    std::cout << "\n=========================================\n";
    std::cout << "  GENERADOR Y VALIDADOR DE CONTRASE\241AS  \n";
    std::cout << "=========================================\n";
    std::cout << "1. Validar la fortaleza de una contrase\241a\n";
    std::cout << "2. Generar una contrase\241a segura\n";
    std::cout << "3. Salir\n";
    std::cout << "Seleccione una opci\243n: ";
}

int main() {
    srand(time(0));
    int opcion;

    do {
        mostrarMenu();
        if (!(std::cin >> opcion)) {
            std::cout << "Por favor, ingrese un n\243mero v\241lido.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        std::cin.ignore(); 

        if (opcion == 1) {
            std::string pass;
            std::cout << "Ingrese la contrase\241a a evaluar: ";
            std::getline(std::cin, pass);
            std::cout << "Resultado del diagn\243stico: " << evaluarFortaleza(pass) << "\n";
        } 
        else if (opcion == 2) {
            int longitud;
            std::cout << "\250De qu\202 longitud desea la contrase\241a?: ";
            std::cin >> longitud;
            if(longitud <= 0) {
                std::cout << "Longitud no v\241lida.\n";
            } else {
                std::cout << "Contrase\241a sugerida: " << generarContrasenia(longitud) << "\n";
            }
        } 
        else if (opcion != 3) {
            std::cout << "Opci\243n inv\241lida. Intente de nuevo.\n";
        }

    } while (opcion != 3);

    std::cout << "Saliendo del programa. \241Cuide sus datos!\n";
    return 0;
}