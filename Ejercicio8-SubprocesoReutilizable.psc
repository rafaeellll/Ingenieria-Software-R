Proceso SubprocesoReutilizable
	Definir a1p1, a1p2, a1p3 Como Real
	Definir a2p1, a2p2, a2p3 Como Real
	Definir promedio1, promedio2 Como Real
	Escribir '=== Calculo de Promedios con Subproceso ==='
	Escribir '--- Alumno 1 ---'
	Escribir 'Ingrese la calificacion del parcial 1: '
	Leer a1p1
	Escribir 'Ingrese la calificacion del parcial 2: '
	Leer a1p2
	Escribir 'Ingrese la calificacion del parcial 3: '
	Leer a1p3
	promedio1 <- CalcularPromedio(a1p1,a1p2,a1p3)
	Escribir 'Promedio del alumno 1: ', promedio1
	Escribir '--- Alumno 2 ---'
	Escribir 'Ingrese la calificacion del parcial 1: '
	Leer a2p1
	Escribir 'Ingrese la calificacion del parcial 2: '
	Leer a2p2
	Escribir 'Ingrese la calificacion del parcial 3: '
	Leer a2p3
	promedio2 <- CalcularPromedio(a2p1,a2p2,a2p3)
	Escribir 'Promedio del alumno 2: ', promedio2
FinProceso

SubAlgoritmo promedio <- CalcularPromedio(n1,n2,n3)
	promedio <- (n1+n2+n3)/3
FinSubAlgoritmo
