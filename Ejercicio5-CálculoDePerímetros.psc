Proceso CalculoDePerimetros
	Definir opcion Como Entero
	Definir lado, perimetro, radio Como Real
	Escribir '=== Calculo de Perimetros ==='
	Escribir 'Seleccione una figura:'
	Escribir '1. Cuadrado'
	Escribir '2. Triangulo equilatero'
	Escribir '3. Circulo'
	Leer opcion
	Según opcion Hacer
		1:
			Escribir 'Ingrese el lado del cuadrado: '
			Leer lado
			perimetro <- lado*4
			Escribir 'El perimetro del cuadrado es: ', perimetro
		2:
			Escribir 'Ingrese el lado del triangulo equilatero: '
			Leer lado
			perimetro <- lado*3
			Escribir 'El perimetro del triangulo es: ', perimetro
		3:
			Escribir 'Ingrese el radio del circulo: '
			Leer radio
			perimetro <- 2*3.1416*radio
			Escribir 'El perimetro (circunferencia) del circulo es: ', perimetro
		De Otro Modo:
			Escribir 'error'
	FinSegún
FinProceso
