Proceso NotasDeEstudiante
	Definir n, i, nota Como Entero
	Definir aprobadas, desaprobadas Como Entero
	Definir sumaTotal, sumaAprobadas, sumaDesaprobadas Como Real
	Definir promedioGeneral, promedioAprobadas, promedioDesaprobadas Como Real
	aprobadas <- 0
	desaprobadas <- 0
	sumaTotal <- 0
	sumaAprobadas <- 0
	sumaDesaprobadas <- 0
	Escribir '=== Notas de un Estudiante ==='
	Escribir '¿Cuantas notas desea ingresar?: '
	Leer n
	i <- 1
	Mientras i<=n Hacer
		Escribir 'Ingrese la nota #', i, ': '
		Leer nota
		sumaTotal <- sumaTotal+nota
		Si nota>=6 Entonces
			aprobadas <- aprobadas+1
			sumaAprobadas <- sumaAprobadas+nota
		SiNo
			desaprobadas <- desaprobadas+1
			sumaDesaprobadas <- sumaDesaprobadas+nota
		FinSi
		i <- i+1
	FinMientras
	promedioGeneral <- sumaTotal/n
	Escribir 'Notas aprobadas: ', aprobadas
	Escribir 'Notas desaprobadas: ', desaprobadas
	Escribir 'Promedio general: ', promedioGeneral
	Si aprobadas>0 Entonces
		promedioAprobadas <- sumaAprobadas/aprobadas
		Escribir 'Promedio de aprobadas: ', promedioAprobadas
	SiNo
		Escribir 'No hay notas aprobadas.'
	FinSi
	Si desaprobadas>0 Entonces
		promedioDesaprobadas <- sumaDesaprobadas/desaprobadas
		Escribir 'Promedio de desaprobadas: ', promedioDesaprobadas
	SiNo
		Escribir 'No hay notas desaprobadas.'
	FinSi
FinProceso
