Proceso PromedioYEstatus
	Definir p1, p2, p3, promedio Como Real
	Escribir '=== Promedio y Estatus del Alumno ==='
	Escribir 'Ingrese la calificacion del parcial 1: '
	Leer p1
	Escribir 'Ingrese la calificacion del parcial 2: '
	Leer p2
	Escribir 'Ingrese la calificacion del parcial 3: '
	Leer p3
	promedio <- (p1+p2+p3)/3
	Escribir 'El promedio es: ', promedio
	Si promedio>=6 Entonces
		Escribir 'APROBADO'
	SiNo
		Escribir 'REPROBADO'
	FinSi
FinProceso
