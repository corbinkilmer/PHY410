from read_plot import read_plot
import numpy
import numpy.polynomial.polynomial as poly

x,y = read_plot("fft_co2_student.data")
linear = poly.polyfit(x, y, 1, 0)
print(linear)
#lp = numpy.poly1d(linear)
