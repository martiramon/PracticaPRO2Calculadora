# MAKEFILE: emplearemos esta utilidad para preparar ejecutables en los que 
# intervienen varias clases, de forma que con una unica instruccion 
# se compilan o linkan los ficheros estrictamente necesarios.
#
# Si en el directorio solo hay un proyecto y un makefile, para ejecutar este
# simplemente se escribe "make"
#
# Nuestros makefile se componen de una creaciÃ³n de variables seguida de
# una serie de instrucciones con la estructura:
#
#           fichero1":" lista de ficheros 
#           "tabulador" instrucciÃ³n de compilaciÃ³n o linkado	
#
#           fichero2":" lista de ficheros 
#           "tabulador" instrucciÃ³n de compilaciÃ³n o linkado	
#        
#           etc
#
# Esto significa: para obtener el fichero1 es necesario que existan todos
# los ficheros de su lista; si no existe o es mÃ¡s antiguo que alguno de
# ellos, se obtiene o actualiza con su instruccion; si no existe alguno de
# los ficheros de la lista, el proceso acaba con error; lo mismo para el
# fichero2, etc
# 
# Mediante este esquema, cada uno de nuestros makefile ha de contener todas
# las instrucciones que sean necesarias para obtener los .o y .exe del
# proyecto correspondiente.
#
# Ejemplos:
#
# La siguiente instruccion define una variable de entorno local, para compilar
# con las opciones habituales: 
#
OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x
#
# La siguiente instruccion significa:
# para obtener pro2_s8.exe es necesario que exista pro2_s8.o;
# si pro2_s8.exe no existe o es mas antiguo que pro2_s8.o,
# se obtiene con el g++ -o ... (el tabulador antes de g++ es necesario)
#
program.exe: program.o Avaluar.o Variables.o Operacions.o Resultat.o
	g++ -o program.exe program.o Avaluar.o Variables.o Operacions.o Resultat.o
#
# La siguiente instruccion significa:
# para obtener pro2_s8.o es necesario que exista pro2_s8.cc;
# si pro2_s8.o no existe o es mas antiguo que pro2_s8.cc,
# se obtiene con el g++ -c ... 
#

Resultat.o: Resultat.cc Resultat.hh
	g++ -c Resultat.cc $(OPCIONS)
Variables.o: Variables.cc Variables.hh
	g++ -c Variables.cc $(OPCIONS)
Operacions.o: Operacions.cc Operacions.hh
	g++ -c Operacions.cc $(OPCIONS)
Avaluar.o: Avaluar.cc Avaluar.hh
	g++ -c Avaluar.cc $(OPCIONS)
program.o: program.cc
	g++ -c program.cc $(OPCIONS)

#
# Realizad las modificaciones necesarias para gestionar las clases de la
# sesiÃ³n cuando os toque implementarlas a vosotros.
#
# Esta Ãºltima opciÃ³n sirve para limpiar el directorio de ficheros 
# innecesarios; se ejecuta mediante el comando "make clean"
#
clean:
	rm *.o
	rm *.exe
