# Práctica pre-parcial — Listas enlazadas

Práctica previa al 2º parcial: una red de sensores guardada en una **lista simple enlazada ordenada por batería**, cargada desde un archivo binario. El enunciado completo está en [`listas-sensores/ENUNCIADO.md`](listas-sensores/ENUNCIADO.md).

## Qué hay

* **En el video:** `struct Sensor`, `Nodo`, `Lista` con constructor y destructor, `insertarOrdenado`, `cargarDesdeArchivo`, `recorrerLista` y `verificarSenial`; el `main` hasta el paso 2.
* **En el código, con comentarios:** `buscarNodo`, `habilitar`, `promedioActivos`, `contarSobrecalentados`, `consumirBateria`, `purgarAgotados` y los pasos 3 a 8 del `main`. Están marcados con `---- Lo que sigue no esta en el video ----`.

## Cómo compilar

`src/` + `include/` + el Makefile de la clase 16: `make` compila, `make run` compila y ejecuta, `make clean` borra. Correr desde `listas-sensores/`, que es donde está `sensores.dat`. El paso 3 pide dos nombres por teclado: uno de los deshabilitados en el paso 2 y uno que no exista.

## Errores frecuentes

* `purgarAgotados` que trata «el primero» una sola vez: los agotados pueden ser varios seguidos al principio de la lista.
* `delete` y después `getSig ()` sobre el mismo puntero: guardar el siguiente **antes** de liberar.
* «Activo» mirando solo `habilitado`: también hace falta `bateria > 0`.
* Comparar nombres con `==`: son `char[]`, se comparan con `strcmp`.
