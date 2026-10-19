#include <iostream>
#include <cstring>
#include "lista.h"

int main ()
{
    Lista red;
    char nombre[16];
    Sensor s;

    int n = red.cargarDesdeArchivo ("sensores.dat");
    if (n<0)
        return 1;

    std::cout << "1) Cargados " << n << "  sensores: " << "\n";
    red.recorrerLista ();
    std::cout << "\n\n";
    std::cout << "2) Senial baja (<15%): " << red.verificarSenial (15) << " deshabilitados" << "\n";
    red.recorrerLista ();
    std::cout << "\n\n";

    // ---- Lo que sigue no esta en el video ----

    // 3) habilitar uno de los deshabilitados y despues uno que no existe
    std::cout << "3) Nombre de un sensor deshabilitado a habilitar: ";
    std::cin >> nombre;
    red.habilitar (nombre);
    std::cout << "   Nombre de un sensor que no existe: ";
    std::cin >> nombre;
    red.habilitar (nombre);
    std::cout << "\n\n";

    // 4) promedio de los activos y sobrecalentados (> 25)
    std::cout << "4) Promedio activos: " << red.promedioActivos ()
              << "  sobrecalentados (>25): " << red.contarSobrecalentados (25) << "\n";
    std::cout << "\n\n";

    // 5) consumo de 10 %
    std::cout << "5) Consumo de 10%:" << "\n";
    red.consumirBateria (10);
    red.recorrerLista ();
    std::cout << "\n\n";

    // 6) purgar los agotados
    std::cout << "6) Purga: " << red.purgarAgotados () << " eliminados" << "\n";
    red.recorrerLista ();
    std::cout << "\n\n";

    // 7) alta de dos sensores nuevos, siempre con insertarOrdenado
    std::cout << "7) Alta de NUEVO-1 (50%) y NUEVO-2 (100%):" << "\n";
    std::strcpy (s.nombre, "NUEVO-1"); s.bateria = 50;  s.senial = 99; s.temperatura = 21.5; s.habilitado = true;
    red.insertarOrdenado (s);
    std::strcpy (s.nombre, "NUEVO-2"); s.bateria = 100; s.senial = 99; s.temperatura = 20;   s.habilitado = true;
    red.insertarOrdenado (s);
    red.recorrerLista ();
    std::cout << "\n\n";

    // 8) promedio final
    std::cout << "8) Promedio activos: " << red.promedioActivos () << "\n";

    return 0;                                // el destructor libera lo que quedo
}
