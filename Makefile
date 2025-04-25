objects = main.o CuWindow.o Panel.o Button.o Tester.o RGB.o
libs = -std=c++11 -lX11

a1: $(objects)
	g++ -o a1 $(objects) $(libs) -I /opt/X11/include -L /opt/X11/lib

main.o: main.cc 
	g++ -c main.cc -I /opt/X11/include

RGB.o: RGB.h RGB.cc
	g++ -c RGB.cc -I /opt/X11/include

Panel.o: Panel.h Panel.cc
	g++ -c Panel.cc -I /opt/X11/include

Button.o: Button.h Button.cc
	g++ -c Button.cc -I /opt/X11/include

CuWindow.o: CuWindow.h CuWindow.cc
	g++ -c CuWindow.cc -I /opt/X11/include

Tester.o: Tester.h Tester.cc
	g++ -c Tester.cc -I /opt/X11/include

clean:
	rm a1 *.o