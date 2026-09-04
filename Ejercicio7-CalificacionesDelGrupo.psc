Proceso CalificacionesDelGrupo
	Definir p1, p2, p3, promedioAlumno Como Real
	Definir sumaGrupo, promedioGrupo Como Real
	Definir cantidadAlumnos Como Entero
	Definir continuar Como Cadena
	sumaGrupo <- 0
	cantidadAlumnos <- 0
	continuar <- 's'
	Escribir '=== Calificaciones del Grupo ==='
	Mientras continuar='s' O continuar='S' Hacer
		Escribir '--- Alumno ', cantidadAlumnos+1, ' ---'
		Escribir 'Ingrese la calificacion del parcial 1: '
		Leer p1
		Escribir 'Ingrese la calificacion del parcial 2: '
		Leer p2
		Escribir 'Ingrese la calificacion del parcial 3: '
		Leer p3
		promedioAlumno <- (p1+p2+p3)/3
		Escribir 'Promedio del alumno: ', promedioAlumno
		sumaGrupo <- sumaGrupo+promedioAlumno
		cantidadAlumnos <- cantidadAlumnos+1
		Escribir '¿Desea capturar otro alumno? (S/N): '
		Leer continuar
	FinMientras
	Si cantidadAlumnos>0 Entonces
		promedioGrupo <- sumaGrupo/cantidadAlumnos
		Escribir '=== Promedio general del grupo: ', promedioGrupo, ' ==='
	FinSi
FinProceso
