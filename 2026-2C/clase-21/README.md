# Clase 21

**Tema:** **Referencias en C++.** Clase grabada: el video y el PDF están en el campus. Categorías de valor (lvalue / rvalue), referencias lvalue y `const`, transferencia por referencia frente a transferencia por dirección, punteros por referencia y `return` por referencia.

## Cómo compilarlos

Un solo archivo por carpeta: `g++ -Wall -Wextra -std=c++17 main.cpp -o programa && ./programa`.

Las líneas marcadas `// ERROR:` están comentadas a propósito: no compilan, y el comentario dice qué mensaje da `g++`. Descomentarlas para verlo.

## Categorías de valor

* **[ej01](ej01_lvalue_rvalue/)** — `x` y `d` son lvalues (tienen identidad y persisten); `5`, `1.2`, `return5()` y `x + 1` son rvalues (temporales, mueren en la expresión). A la izquierda del `=` va un lvalue modificable; `&` necesita un lvalue.
* **[ej02](ej02_funcion_devuelve_lvalue/)** — `setValue()` devuelve por valor: un rvalue, no se le puede asignar. `setGlobal()` devuelve `int&`: un lvalue, y `setGlobal() = 400` modifica `global`.

## Referencias

* **[ej03](ej03_referencia_alias/)** — `int& refX {vX}`: un segundo nombre para `vX`. Modificar `refX` modifica `vX`. Las referencias se inicializan siempre y solo a un lvalue modificable del mismo tipo: no a un `const`, no a un literal, no a un `double`.
* **[ej04](ej04_referencia_no_se_recoloca/)** — `refX = vY` no hace que `refX` apunte a `vY`: es `vX = vY`. Una referencia no se recoloca.
* **[ej05](ej05_alcance_referencia/)** — la referencia declarada en un bloque muere al cerrarlo; `vX` sigue viva. El alcance de la referencia y el del objeto son independientes.
* **[ej06](ej06_referencia_const/)** — `const int&` se enlaza a un `const`, a un no-`const` (solo lectura) y a un literal: `const int& refC {14}` crea un temporal que vive lo que vive `refC`.

## Transferencia por referencia y por dirección

* **[ej07](ej07_swap/)** — `swap (int& a, int& b)`: la función trabaja sobre las variables del `main`. Se llama `swap (x, y)`, igual que por valor.
* **[ej08](ej08_transferencia_por_direccion/)** — `incrementByPointer (int* ptr)`: se pasa `&vX`, se escribe con `*ptr`, y hay que verificar `nullptr`.
* **[ej09](ej09_transferencia_por_referencia/)** — `incrementByReference (int& ref)`: mismo efecto, sin `*` ni verificación. La llamada es idéntica a una por valor.
* **[ej10](ej10_puntero_por_valor/)** — `cambiarPtr (int* ptr)` hace `ptr = nullptr` sobre su copia del puntero: el `ptr` del `main` sigue apuntando a `x` e imprime `12`. `g++ -Wall -Wextra` avisa `parameter 'ptr' set but not used`: es exactamente lo que pasa.
* **[ej11](ej11_puntero_por_referencia/)** — `cambiarPuntero (int*& ptr)`: el puntero se recibe por referencia y la función lo hace apuntar a otro lado. `nuevoValor` es `static` para que exista después del `return`.

## Return por referencia

* **[ej12](ej12_return_por_referencia/)** — `int& funcion (int vX, int& rY)` devuelve una referencia a su `static aux`; el mismo resultado se guarda en una referencia, en un puntero y en una copia. `rY++` modifica el `vX` del `main`; el `vX` recibido por valor no.
* **[ej13](ej13_return_referencia_vector/)** — `obtenerElemento (miVec, 2)` devuelve `int&` a un elemento del vector del `main`: `obtenerElemento (miVec, 2) = 100` es `miVec[2] = 100`.
* **[ej14](ej14_punto_referencias/)** — `class Punto` con tres formas de devolver el atributo: `copiaX ()` por valor (una copia, no se le puede asignar), `refX ()` por referencia (`p.refX () = 100` modifica el atributo `private` desde afuera) y `refConstX ()` por referencia `const` (un alias de solo lectura, sin copia). Modificar se hace con `setX ()`.
* **[ej15](ej15_sumar_sobrecargas/)** — cuatro `sumar` sobrecargadas: el resultado sale por el `return` (por valor), se escribe en un `int*` (por dirección) o en un `int&` (por referencia). La cuarta devuelve `float&` a una `static`: dos llamadas seguidas devuelven alias de la misma variable, y la segunda pisa a la primera.

## Errores frecuentes

* Declarar una referencia sin inicializar.
* Enlazar `int&` a un `const`, a un literal o a una variable de otro tipo. Para eso es `const int&`.
* Devolver una referencia a una variable local: muere al salir de la función (referencia colgante). `g++ -Wall` avisa `reference to local variable returned`.
* Poner `static` para que compile: hay una sola variable para todas las llamadas. El resultado de una operación es un objeto nuevo y se devuelve por valor.
* Devolver `int&` a un atributo `private`: el que llama lo modifica como si fuera público.
