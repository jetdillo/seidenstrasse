set xlabel 'seconds'
set ylabel 'Acceleration in Gs'
set key autotitle columnhead
set output "flight3.png"
plot 'FLIGHT3.TXT' using 0:2 with lines , '' using 0:3 with lines, '' using 0:4 with lines
