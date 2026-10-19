# Clase 19

**Tema:** **Listas simplemente enlazadas (parte 2), lista ordenada y lista doblemente enlazada.** Insertar en cualquier posición, buscar y borrar; la lista que se mantiene ordenada al insertar; nodos con dos enlaces.

## Cómo compilarlos

Todos son `src/` + `include/` + `Makefile` (el de la clase 16): `make` compila, `make run` compila y ejecuta, `make clean` borra. Si tocan un `.h`: `make clean && make`.

## Regla para los errores

Un método que no puede hacer lo que le piden (la lista está vacía, el valor no está) **avisa por `std::cerr` y vuelve** con `return`; un método que devuelve un puntero devuelve `nullptr`. `cerr` es como `cout`, pero para mensajes de error: va por otro canal, y el programa sigue.

## Listas simplemente enlazadas (parte 2)

La numeración continúa la de la clase 18. Cada carpeta es el programa con el que se abre el editor en clase.

* **[ej05](ej05_lista/)** — La lista simple completa. Sobre la `Lista` de la clase 18 se agregan, en este orden:
  * `insertarAntes (dato, objetivo)`: dos punteros, `anterior` y `actual`, avanzan juntos hasta encontrar el objetivo; el nuevo apunta a `actual` y `anterior` apunta al nuevo. Casos aparte: lista vacía (aviso), objetivo no encontrado (aviso), objetivo es el primero (llama a `insertarPrimero`).
  * `buscarNodo (objetivo)`: el `for` de `recorrerLista` con un `return` adentro. Devuelve la dirección del nodo, o `nullptr`.
  * `insertarDespues (dato, objetivo)`: usa `buscarNodo`; el nuevo apunta a donde apuntaba el objetivo y el objetivo apunta al nuevo. Después del último no es un caso especial.
  * `borrarNodo (objetivo)`: mismo recorrido con `anterior`/`actual`; desenganchar (si era el primero, cambia `m_inicio`) y liberar con `delete`. Borra la primera ocurrencia.
  * El `main` recorre los casos: en el medio, el primero, el último, uno que no está, lista vacía.
* **[ej06](ej06_borrar_ocurrencias/)** — `borrarOcurrencias (objetivo)`: el `while` ya no termina al encontrar, termina al llegar al final. Como el nodo borrado no se puede usar más, se guarda en `aEliminar`, se avanza `actual` y recién después se hace `delete`. El `main` cubre: único nodo, primero, último, consecutivos, no consecutivos, no está, lista vacía.

## Lista ordenada

* **[ej07](ej07_lista_ordenada/)** — `class ListaOrd`: una clase nueva que copia de `Lista` lo que sirve (constructor, destructor, `recorrerLista`, `getUltimo`, `buscarNodo`, `borrarNodo`, `borrarOcurrencias`) y agrega `insertarOrdenado (dato)`: crear el nodo; si la lista está vacía o el dato va primero, resolverlo ahí; si no, avanzar `anterior` y `p` mientras `dato > p->getDato ()`, y enganchar el nuevo entre `anterior` y el que le sigue. Los valores se ingresan en cualquier orden y salen ordenados.

## Lista doblemente enlazada

* **[ej08](ej08_lista_doble/)** — `class NodoDoble` (dato, `m_sig`, `m_ant`) y `class ListaDoble`: `insertarPrimero`, `buscarPorPosicion` (el primer nodo es el 0; devuelve `nullptr` si no existe), `insertarDespues (NodoDoble*, dato)`, `recorrerLista` (idéntico al de `Lista`: hacia adelante no se usa `m_ant`) y `eliminarNodo (NodoDoble*)`. Cada inserción y cada borrado mantienen los **dos** enlaces; los casos borde son el primero (no tiene anterior) y el último (no tiene siguiente).

## Errores frecuentes

* Hacer `anterior->setSig (...)` cuando el objetivo era el primero: `anterior` es `nullptr` y el programa crashea. Por eso `insertarAntes` lo trata aparte y `borrarNodo` pregunta `actual == m_inicio`.
* Olvidar el `delete` al borrar: el nodo queda vivo en el heap y nadie lo apunta.
* En `borrarOcurrencias`, avanzar `actual` **después** del `delete`: el puntero ya está colgante.
* En la lista doble, actualizar un solo enlace: la lista queda bien hacia un lado y rota hacia el otro.
* Usar el puntero que devuelve `buscarNodo` o `buscarPorPosicion` sin verificar que no sea `nullptr`.
