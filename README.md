# Laberinto Maestro

## Descripción
Este proyecto genera y resuelve laberintos aleatorios en consola. El laberinto se crea garantizando un camino válido desde la entrada hasta la salida, y luego se resuelve automáticamente mostrando el recorrido.

---

## Generación del laberinto
Se utiliza un algoritmo recursivo de **Backtracking** para construir el laberinto.  
El algoritmo comienza con una matriz llena de muros (`#`) y va abriendo caminos aleatorios, asegurando que la entrada (esquina superior izquierda marcada como `E`) y la salida (esquina inferior derecha marcada como `S`) estén conectadas.

---

## Resolución automática
Para resolver el laberinto se implementa un algoritmo de **Backtracking** que explora caminos desde la entrada, marcando el recorrido con `.`. Si el camino no conduce a la salida, el algoritmo retrocede (desmarca) y prueba otras rutas hasta encontrar la solución.

---

## Medición de tiempos y mejoras
- La generación del laberinto es eficiente incluso para tamaños grandes.
- La resolución con backtracking puede volverse lenta para laberintos muy grandes debido a la exploración exhaustiva.
- Para optimizar, en futuras versiones se podría implementar un algoritmo de búsqueda como **BFS** para encontrar la ruta más corta más rápido y evitar exploraciones innecesarias.

---

## Cómo ejecutar
1. Compila el programa con un compilador compatible con C++.
2. Ejecuta el programa e ingresa un tamaño impar para generar el laberinto.
3. Observa cómo se genera y resuelve el laberinto paso a paso en la consola.

---

## Estructura del proyecto
- `main.cpp`: Código principal con generación, visualización y resolución.
- Funciones separadas para:
  - Crear matriz dinámica.
  - Generar laberinto.
  - Resolver laberinto.
  - Imprimir laberinto.

