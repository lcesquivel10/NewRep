cuerda.pdf: cuerdaonda.dat Plots_cuerdayTambor.py
	python Plots_cuerdayTambor.py


a.out: EsquivelLaura_CuerdaTambor.cpp
	g++ a.out EsquivelLaura_CuerdaTambor.cpp


cuerdaonda.dat : a.out 
	./a.out


