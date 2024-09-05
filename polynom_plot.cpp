#include "polynom_plot.h"
#include <stdexcept>

void plot() {
    FILE *gp = popen("gnuplot","w"); 
    if (!gp) {
        throw std::runtime_error("Error opening pipe to GNU plot");
    }
    std::fprintf(gp, "set terminal png\n");  
    std::fprintf(gp, "set xlabel 'x'\n");
    std::fprintf(gp, "set ylabel 'y'\n");
    std::fprintf(gp, "set output 'problem.png'\n");
    std::fprintf(gp, "set label 'y = -2.14*(x^2) + 0.44*x - 4' at -4.5, -250.0\n");
    std::fprintf(gp, "set label 'Число узлов: 100' at -4.5, -270.0\n");
    std::fprintf(gp, "set label 'Степени: 2, 3' at -4.5, -290.0\n");
    std::fprintf(gp, "plot 'points.txt' index 0 with linespoints pt 7 lt rgb 'red' title 'exact','points.txt' index 1 with linespoints pt 7 lt rgb 'yellow' title 'polynom1','points.txt' index 1 with linespoints pt 7 lt rgb 'green' title 'polynom2'\n"); 
    pclose(gp); 
}
