# Práctica pre-parcial — Listas enlazadas en C++

## Red de sensores distribuidos

Una red de sensores de temperatura está conectada en cadena a un nodo central. El nodo central guarda los sensores en una **lista simple enlazada** y, periódicamente, recolecta sus lecturas, vigila la calidad de la señal, descuenta batería y da de baja los sensores agotados.

El estado inicial de la red está grabado en el archivo binario **`sensores.dat`** (se entrega junto con este enunciado). Cada registro del archivo es un `struct Sensor`, exactamente con esta forma y en este orden:

```cpp
struct Sensor
{
    char  nombre[16];     // identificador del sensor, terminado en '\0'
    int   bateria;        // 0 a 100 (%)
    int   senial;         // 0 a 100 (%)
    float temperatura;    // última lectura, en grados
    bool  habilitado;
};
```

Los registros están uno a continuación del otro, sin encabezado. No se sabe cuántos son. Todos están grabados con `habilitado` en `true`.

El archivo se puede leer tanto con las herramientas vistas en C (`fopen`, `fread`) como con las nativas de C++ (`ifstream`).

Un sensor está **activo** cuando está habilitado **y** tiene batería mayor que 0.

---

## Se pide

- `struct Sensor`: el de arriba, tal cual.
- Clase `Nodo`: sus atributos deben ser privados.
- Clase `Lista`, con las operaciones de la tabla.

La lista se mantiene **ordenada en forma ascendente por batería**: los sensores con menos carga, que son los que requieren atención, quedan al principio. Si dos sensores tienen la misma batería, el que se inserta después queda **después** del que ya estaba.

| # | Método de `Lista` | Qué hace |
|---|---|---|
| 1 | `insertarOrdenado(Sensor)` | Inserta el sensor en la posición que le corresponde según la batería. Es la **única** forma de agregar nodos a la lista. |
| 2 | `cargarDesdeArchivo(const char*)` | Abre el archivo binario, lee los `Sensor` de a uno hasta el final del archivo e inserta cada uno con `insertarOrdenado`. Devuelve la cantidad cargada, o `-1` si no pudo abrir el archivo (informar el error). |
| 3 | `recorrerLista()` | Imprime todos los sensores, uno por línea, en el orden de la lista: nombre, batería, señal, temperatura y si está activo o no. |
| 4 | `buscarNodo(const char*)` | Devuelve el puntero al nodo cuyo sensor tiene ese nombre, o `nullptr` si no existe. |
| 5 | `habilitar(const char*)` | Habilita el sensor con ese nombre. Si no existe, informa el error y no hace nada más. |
| 6 | `verificarSenial(int umbral)` | Pone `habilitado` en `false` a todos los sensores cuya señal sea **menor** que el umbral. Devuelve cuántos deshabilitó. |
| 7 | `promedioActivos()` | Devuelve el promedio de temperatura de los sensores **activos**. Si no hay ninguno, informa el error y devuelve 0. |
| 8 | `contarSobrecalentados(float limite)` | Cantidad de sensores activos con temperatura **estrictamente mayor** que el límite. |
| 9 | `consumirBateria(int consumo)` | Todos los sensores encendidos (batería mayor que 0) restan esa cantidad, estén habilitados o no. La batería **nunca queda por debajo de 0**. |
| 10 | `purgarAgotados()` | **Elimina de la lista y libera** todos los nodos cuyo sensor tiene batería igual a 0. Devuelve cuántos eliminó. Tiene que funcionar aunque los agotados sean varios seguidos, estén al principio o al final de la lista, o no haya ninguno. |

Restricciones:

- Sin `break`, sin `this`, sin pasaje por referencia. Prototipos en el `.h`, definiciones en el `.cpp`.
- Atributos de las clases con prefijo `m_`.
- Al terminar el programa no debe quedar memoria sin liberar.

---

## Programa principal

Escribir un `main` **sin menú** que ejecute exactamente este escenario y muestre lo que se indica.

1. Cargar `sensores.dat`. Si no se pudo abrir el archivo, terminar el programa. Mostrar cuántos sensores se cargaron y recorrer la lista.
2. Verificar la señal con umbral 15. Mostrar cuántos se deshabilitaron y recorrer la lista.
3. Pedir por teclado el nombre de uno de los sensores deshabilitados en el paso anterior y habilitarlo. Pedir un segundo nombre, que no exista, e intentar habilitarlo.
4. Mostrar el promedio de temperatura de los activos y cuántos están sobrecalentados (límite 25).
5. Aplicar un consumo de 10 % y recorrer la lista.
6. Purgar los agotados. Mostrar cuántos se eliminaron y recorrer la lista.
7. Dar de alta dos sensores nuevos, con `insertarOrdenado`: `NUEVO-1` (batería 50, señal 99, temperatura 21.5, habilitado) y `NUEVO-2` (batería 100, señal 99, temperatura 20, habilitado). Recorrer la lista.
8. Mostrar nuevamente el promedio de los activos y terminar.
