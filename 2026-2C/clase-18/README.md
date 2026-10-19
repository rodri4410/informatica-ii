# Clase 18

**Tema:** **Listas simplemente enlazadas (parte 1).** La primera estructura de datos dinámica: nodos en el heap encadenados por punteros.

## Cómo compilarlos

Todos son `src/` + `include/` + `Makefile` (el de la clase 16): `make` compila, `make run` compila y ejecuta, `make clean` borra. Si tocan un `.h`: `make clean && make`.

## Listas simplemente enlazadas

Cada carpeta es el programa con el que se abre el editor en clase; adentro se van agregando los métodos en el orden indicado. Los que leen de teclado terminan el ingreso con `-1`. La numeración arranca en `ej02`: sigue la del material de clase.

* **[ej02](ej02_crear_recorrer/)** — Crear y recorrer.
  * `class Nodo` (un dato y un puntero al siguiente) y `class Lista` con un solo atributo: `Nodo* m_inicio`. En `nullptr`, la lista está vacía.
  * `crearLista ()`: cada valor ingresado crea un nodo **al comienzo** con `m_inicio = new Nodo (x, m_inicio)`.
  * `recorrerLista ()`: un `for` que arranca en `m_inicio`, avanza con `getSig ()` y termina en `nullptr`. `m_sig` y `m_dato` son privados: por eso los getters de `Nodo`. Los valores salen en orden inverso al de ingreso.
  * Todavía no se libera la memoria: los nodos quedan en el heap cuando termina el `main`. Es el punto de partida del ejercicio del destructor.
* **[ej03](ej03_destructor/)** — `~Lista ()`: libera nodo por nodo. Hay que guardar `p->getSig ()` **antes** del `delete p`.
* **[ej04](ej04_insertar/)** — Insertar al principio y al final.
  * `insertarPrimero ()` en tres pasos: crear el nodo, hacer que apunte al primero (`setSig`), y que `m_inicio` apunte al nuevo. Hace lo mismo que la línea de `crearLista`, de a un nodo.
  * `getUltimo ()` recorre hasta el último nodo y devuelve su dirección, o `nullptr` si la lista está vacía.
  * `insertarUltimo ()` usa `getUltimo ()` para enganchar el nodo nuevo; si la lista está vacía, llama a `insertarPrimero`.

## Errores frecuentes

* Perder `m_inicio`: es el único puntero a la lista. Por eso `crearLista ()` se llama una sola vez, sobre la lista recién creada.
* Leer `p->getSig ()` después de `delete p`: `p` ya es un puntero colgante.
* Usar el puntero que devuelve `getUltimo ()` sin verificar que no sea `nullptr`.
* Un nodo se libera con `delete`, sin corchetes: es un objeto, no un vector.

## Trabajo práctico

TP Matriz, parte 1: el enunciado está en la organización de GitHub de la materia.
