set term pdf 
set output '2.pdf' 
set ylabel " V (mv) "     
 set xlabel " T (ms) "  
 plot "plot.txt" with lines, "plot2.txt" with lines