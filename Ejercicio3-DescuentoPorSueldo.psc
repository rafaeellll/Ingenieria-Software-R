Proceso DescuentoPorSueldo
	Definir sueldo, descuento, porcentaje, sueldoNeto Como Real
	Escribir '=== Calculo de Descuento por Sueldo ==='
	Escribir 'Ingrese el sueldo del trabajador: '
	Leer sueldo
	Si sueldo<=1000 Entonces
		porcentaje <- 0.10
	SiNo
		Si sueldo<=2000 Entonces
			porcentaje <- 0.05
		SiNo
			porcentaje <- 0.03
		FinSi
	FinSi
	descuento <- sueldo*porcentaje
	sueldoNeto <- sueldo-descuento
	Escribir 'Porcentaje de descuento aplicado: ', porcentaje*100, '%'
	Escribir 'Descuento: ', descuento
	Escribir 'Sueldo neto: ', sueldoNeto
FinProceso
