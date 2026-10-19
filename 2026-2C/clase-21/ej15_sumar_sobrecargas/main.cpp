// sumar: una misma operacion, cuatro firmas. El compilador elige por los argumentos.
//
//   int    sumar (int, int)         -> el resultado SALE por el return (una copia)
//   void   sumar (int, int, int*)   -> el resultado se ESCRIBE en una direccion   (C)
//   void   sumar (int, int, int&)   -> el resultado se ESCRIBE en una referencia  (C++)
//   float& sumar (float, float)     -> devuelve una referencia a una static: LA TRAMPA
//
// Compilar:  g++ -Wall -Wextra -std=c++17 -o sumar main.cpp
#include <iostream>

int    sumar (int, int);
void   sumar (int, int, int*);
void   sumar (int, int, int&);
float& sumar (float, float);

int main (void)
{
    int a {10};
    int b {20};
    int resultado {0};

    // ---- 1) por valor ----------------------------------------------------
    resultado = sumar (a, b);
    std::cout << "por valor:      " << resultado << "\n";

    // ---- 2) por direccion (C) --------------------------------------------
    resultado = 0;
    sumar (a, b, &resultado);         // le paso DONDE escribir
    std::cout << "por direccion:  " << resultado << "\n";

    // ---- 3) por referencia (C++) -----------------------------------------
    resultado = 0;
    sumar (a, b, resultado);          // se llama IGUAL que por valor (slide 33)
    std::cout << "por referencia: " << resultado << "\n";

    // ---- 4) return por referencia a una static: la trampa ----------------
    float& r1 = sumar (1.5f, 2.5f);   // r1 es un alias de la static de adentro
    std::cout << "r1 = " << r1 << "\n";

    float& r2 = sumar (10.0f, 20.0f); // r2 es un alias de LA MISMA static
    std::cout << "r2 = " << r2 << "\n";
    std::cout << "r1 = " << r1 << "   (ya no es 4)\n";
    std::cout << "&r1 = " << &r1 << "   &r2 = " << &r2 << "   (misma direccion)\n";

    // 1.5 sin sufijo es double, y double convierte a int o a float por igual:
    // float& r3 = sumar (1.5, 2.5); // ERROR: call of overloaded 'sumar(double, double)' is ambiguous

    return 0;
}

// 1) Por valor: el return copia el resultado. Es la funcion de siempre.
int sumar (int a, int b)
{
    return a + b;
}

// 2) Por direccion: recibo un puntero y escribo ahi. Hay que desreferenciar
//    y hay que chequear nullptr (slide 31).
void sumar (int a, int b, int* resultado)
{
    if (resultado != nullptr)
    {
        *resultado = a + b;
    }
}

// 3) Por referencia: recibo un alias y escribo ahi. Ni *, ni chequeo:
//    una referencia siempre apunta a algo (slide 15).
void sumar (int a, int b, int& resultado)
{
    resultado = a + b;
}

// 4) Return por referencia: para devolver un alias, lo referenciado tiene que
//    seguir vivo despues del return. Con una local automatica es referencia
//    colgante (slide 47); con static "anda"... pero hay UNA SOLA variable para
//    todas las llamadas. Es un parche, no una solucion.
float& sumar (float a, float b)
{
    static float resultado;
    resultado = a + b;
    return resultado;
}
