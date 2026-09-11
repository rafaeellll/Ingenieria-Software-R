Proceso OperacionesConDosNumeros
	Definir n1, n2, resultado Como Real

	Escribir "=== Operaciones con Dos Numeros ==="
	Escribir "Ingrese el primer numero: "
	Leer n1
	Escribir "Ingrese el segundo numero: "
	Leer n2

	Si n1 = n2 Entonces
		resultado <- n1 * n2
		Escribir "Los numeros son iguales. Multiplicacion: ", resultado
	SiNo
		Si n1 > n2 Entonces
			resultado <- n1 - n2
			Escribir "El primer numero es mayor. Resta: ", resultado
		SiNo
			resultado <- n1 + n2
			Escribir "El segundo numero es mayor. Suma: ", resultado
		FinSi
	FinSi
FinProceso
