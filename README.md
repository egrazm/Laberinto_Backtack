# Laberinto_Backtack
Laberinto Maestro - Proyecto
Cómo generé el laberinto
El laberinto se genera con un algoritmo recursivo basado en Backtracking.
Partiendo de una matriz llena de muros ('#'), se va abriendo camino aleatoriamente en celdas adyacentes, asegurando que el laberinto siempre tenga un camino válido entre la entrada (arriba izquierda) y la salida (abajo derecha).

Algoritmo para resolverlo
Para resolver el laberinto uso otro algoritmo de Backtracking que explora todas las posibles rutas desde la entrada hasta encontrar la salida.
Marca el camino correcto con '.' y retrocede cuando encuentra un callejón sin salida, limpiando la marca para probar otras rutas.

Resultados y aprendizajes sobre tiempos
Al medir tiempos con laberintos de distintos tamaños, noté que la generación es rápida, pero la resolución con backtracking puede ser lenta para laberintos muy grandes, ya que explora muchas opciones.
Para mejorar, podría implementar un algoritmo como BFS para encontrar la ruta más corta de forma más eficiente y evitar exploraciones innecesarias.
