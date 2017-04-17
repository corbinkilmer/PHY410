import matplotlib.pyplot as plt

from numpy.fft import fft,ifft
from numpy import array
import math

plotfirst = False

if plotfirst == True : 
    # make some fake data :

    N = 1024
    f = 10.0

    x = array([ float(i) for i in xrange(N) ] )
    y = array([ math.sin(-2*math.pi*f* xi / float(N))  for xi in x ])
    #y = array([ xi for xi in x ])
    Y = fft(y)

    Yre = [math.sqrt(Y[i].real**2 + Y[i].imag**2) for i in xrange(N)]

    s1 = plt.subplot(2, 1, 1)
    plt.plot( x, y )

    s2 = plt.subplot(2, 1, 2)
    s2.set_autoscalex_on(False)
    plt.plot( x, Yre )
    plt.xlim([0,20])

    plt.show()


else : 
    # data downloaded from ftp://ftp.cmdl.noaa.gov/ccg/co2/trends/co2_mm_mlo.txt
    print ' C02 Data from Mauna Loa'
    data_file_name = 'co2_mm_mlo.txt'
    file = open(data_file_name, 'r')
    lines = file.readlines()
    file.close()
    print ' read', len(lines), 'lines from', data_file_name
    window = True
    yinput = []
    xinput = []

    for line in lines :
        if line[0] != '#' :
            try:
                words = line.split()
                xval = float(words[2])
                yval = float( words[4] )
                yinput.append( yval )
                xinput.append( xval )
            except ValueError :
                print 'bad data:',line

N = len(yinput)
log2N = math.log(N, 2)
if log2N - int(log2N) > 0.0 :
    print 'Padding with zeros!'
    pads = [300.0] * (pow(2, int(log2N)+1) - N)
    yinput = yinput + pads
    N = len(yinput)
    print 'Padded : '
    print len(yinput)
    # Apply a window to reduce ringing from the 2^n cutoff
    if window : 
        for iy in xrange(len(yinput)) :
            yinput[iy] = yinput[iy] * (0.5 - 0.5 * math.cos(2*math.pi*iy/float(N-1)))





    y = array( yinput[0:(N-1)] ) 
    x = array([ float(i) for i in xrange(len(y)) ] )
    Y = fft(y)    

    Yre = [math.sqrt(Y[i].real**2+Y[i].imag**2) for i in xrange(len(Y))]


    plt.subplot(2, 1, 1)
    plt.plot( x, y )

    plt.subplot(2, 1, 2)
    plt.plot( x, Yre )
    plt.yscale('log')


    plt.show()
