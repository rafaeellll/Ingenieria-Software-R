Algoritmo SistemaAlumnos
	Definir opcion Como Entero
	Definir alumno1_nombre, alumno2_nombre, alumno3_nombre Como Cadena
	Definir alumno1_p1, alumno1_p2, alumno1_p3 Como Real
	Definir alumno2_p1, alumno2_p2, alumno2_p3 Como Real
	Definir alumno3_p1, alumno3_p2, alumno3_p3 Como Real
	Definir prom1, prom2, prom3 Como Real

	Repetir
		Escribir ""
		Escribir "========================"
		Escribir " 1. Capturar datos"
		Escribir " 2. Mostrar promedios"
		Escribir " 3. Mostrar mejor promedio"
		Escribir " 4. Salir"
		Escribir "========================"
		Escribir "Elige una opcion: "
		Leer opcion

		Segun opcion Hacer
			1:
				Escribir "--- Datos del Alumno 1 ---"
				Escribir "Nombre: "
				Leer alumno1_nombre
				Escribir "Calificacion parcial 1: "
				Leer alumno1_p1
				Escribir "Calificacion parcial 2: "
				Leer alumno1_p2
				Escribir "Calificacion parcial 3: "
				Leer alumno1_p3

				Escribir "--- Datos del Alumno 2 ---"
				Escribir "Nombre: "
				Leer alumno2_nombre
				Escribir "Calificacion parcial 1: "
				Leer alumno2_p1
				Escribir "Calificacion parcial 2: "
				Leer alumno2_p2
				Escribir "Calificacion parcial 3: "
				Leer alumno2_p3

				Escribir "--- Datos del Alumno 3 ---"
				Escribir "Nombre: "
				Leer alumno3_nombre
				Escribir "Calificacion parcial 1: "
				Leer alumno3_p1
				Escribir "Calificacion parcial 2: "
				Leer alumno3_p2
				Escribir "Calificacion parcial 3: "
				Leer alumno3_p3

			2:
				prom1 <- CalcularPromedio(alumno1_p1, alumno1_p2, alumno1_p3)
				prom2 <- CalcularPromedio(alumno2_p1, alumno2_p2, alumno2_p3)
				prom3 <- CalcularPromedio(alumno3_p1, alumno3_p2, alumno3_p3)

				Escribir ""
				Escribir alumno1_nombre, " - Promedio: ", prom1
				Escribir alumno2_nombre, " - Promedio: ", prom2
				Escribir alumno3_nombre, " - Promedio: ", prom3

			3:
				prom1 <- CalcularPromedio(alumno1_p1, alumno1_p2, alumno1_p3)
				prom2 <- CalcularPromedio(alumno2_p1, alumno2_p2, alumno2_p3)
				prom3 <- CalcularPromedio(alumno3_p1, alumno3_p2, alumno3_p3)

				Si prom1 >= prom2 Y prom1 >= prom3 Entonces
					Escribir "El mejor promedio es de ", alumno1_nombre, " con ", prom1
				SiNo
					Si prom2 >= prom1 Y prom2 >= prom3 Entonces
						Escribir "El mejor promedio es de ", alumno2_nombre, " con ", prom2
					SiNo
						Escribir "El mejor promedio es de ", alumno3_nombre, " con ", prom3
					FinSi
				FinSi

			4:
				Escribir "Saliendo del programa..."

			De Otro Modo:
				Escribir "Opcion invalida, intenta de nuevo."
		FinSegun

	Hasta Que opcion = 4
FinAlgoritmo

SubProceso promedio <- CalcularPromedio(p1, p2, p3)
	Definir promedio Como Real
	promedio <- (p1 + p2 + p3) / 3
FinSubProceso
