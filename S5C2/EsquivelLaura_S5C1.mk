S5C1PLOT.pdf: resultados.tex S5C1PLOT.pdf
S5C1PLOT.pdf: plotsS5C1.py       data.dat
        python plotsS5C1.py
data.dat:a.out
        ./a.out>>data.dat
a.out: S5C1Deriv.cpp.cpp
        g++ S5C1Deriv.cpp.cpp

