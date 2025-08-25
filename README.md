# Push_Swap (42) — Ordenación de pilas en C

**Efficient stack sorting program in C using a limited set of operations.**

---

## 📌 Resumen

* **Lenguaje:** C (C99)  
* **Funcionalidad:** Ordena un conjunto de enteros usando **dos pilas** (`a` y `b`) con un conjunto limitado de operaciones (`sa`, `pb`, `ra`, etc.).  
* **Objetivo:** Practicar **estructuras de datos**, **gestión de memoria**, **algoritmos de ordenación** y **recursividad**.  
* **Restricciones:** Solo se permite usar operaciones de pila; no se pueden usar funciones de ordenación estándar.

---

## 🧠 ¿Por qué este proyecto?

Este proyecto de 42 enseña a:

* Gestionar múltiples **pilas dinámicas** y estructuras de datos complejas.  
* Implementar un algoritmo de **ordenación optimizado**, basado en **quicksort** y casos especiales (`len <= 3`).  
* Controlar la **entrada del usuario**, detectar errores y manejar **valores duplicados**.  
* Trabajar con memoria dinámica y punteros sin errores, liberando correctamente los recursos.  

👉 Elegí este proyecto porque combina **optimización de algoritmos** con **gestión de memoria y estructuras**, esenciales para proyectos complejos.

---

## ⚙️ Funcionamiento de Push_Swap

1. Se recibe un **array de enteros** por línea de comandos o cadena única.  
2. Los valores se almacenan en la **pila A** y se inicializa la **pila B** vacía.  
3. Se valida la entrada:
   * Todos los elementos son números enteros válidos.  
   * No hay duplicados.  
4. Se aplica un **algoritmo de ordenación**:
   * Para 2-3 números: casos especiales de ordenación.  
   * Para más de 3 números: **quicksort adaptado a pilas** usando pivotes y operaciones de movimiento.  
5. El programa imprime la **secuencia mínima de instrucciones** (`sa`, `pb`, `ra`, `rra`, ...) para ordenar la pila A de menor a mayor.  

---

## 🚀 Uso

### Compilación

```bash
make
```

### Ejemplo

```bash
./push_swap 3 2 5 1 4
# Salida:
pb
pb
sa
pa
pa
ra
ra
```

### Con una sola cadena de números

```bash
./push_swap "3 2 5 1 4"
```

---

## 🗂️ Estructura del proyecto

```
push_swap/
├─ push_swap.c           # Lógica principal: manejo de pilas y entrada
├─ push_swap_utils.c     # Funciones auxiliares (atoi seguro, split, free)
├─ operations.c          # Operaciones de pila (swap, push, rotate)
├─ quicksort.c           # Algoritmo de ordenación adaptado a pilas
├─ push_swap.h           # Prototipos, estructura t_piles, constantes
├─ Makefile              # Reglas estándar (all, clean, fclean, re)
└─ README.md
```

---

## 🗂️ Explicación del código

### 📌 `push_swap.c` y `push_swap_utils.c`

* **Entrada:** Validación de argumentos y conversión segura a enteros (`push_swap_atoi`).  
* **Detección de errores:** Duplicados, valores no numéricos, overflow.  
* **Liberación de memoria:** `free_split` y limpieza de pilas en caso de error.  

### 📌 `operations.c`

Contiene todas las operaciones permitidas por el proyecto:

* **Swap:** `sa`, `sb`, `ss`  
* **Push:** `pa`, `pb`  
* **Rotate:** `ra`, `rb`, `rr`  
* **Reverse rotate:** `rra`, `rrb`, `rrr`  

Estas operaciones modifican directamente las pilas y **imprimen la instrucción correspondiente**.

### 📌 `quicksort.c`

* Implementa un **quicksort adaptado a dos pilas**:  
  * Divide la pila en subpilares usando un **pivote**.  
  * Envía números a la otra pila según el pivote (`push_b` o `push_a`).  
  * Ordena recursivamente hasta que cada pila esté ordenada.  
* Casos especiales: 2-3 elementos se ordenan con operaciones mínimas (`swap`, `rotate`).

📌 **Decisión clave:** Este enfoque minimiza el número de movimientos y se ajusta a las restricciones del proyecto.

---

## 🧵 Posibles mejoras

* Implementar un **algoritmo más eficiente** para grandes conjuntos (reduciendo pasos totales).  
* Añadir un modo de **verificación visual** para depurar la secuencia de operaciones.  
* Manejar múltiples **pila de entrada** desde stdin en tiempo real.  

