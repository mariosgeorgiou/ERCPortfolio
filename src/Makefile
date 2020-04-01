IDIR = ../include
CC = g++
CPPFLAGS = -I. -I/usr/local/include/eigen3/ -I../include


_DEPS = Ercsolver.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

ODIR = obj

_OBJ = main.o Ercsolver.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(OBJ): $(ODIR)/%.o: %.cpp $(DEPS)
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CPPFLAGS)

ercsolver: $(OBJ)
	$(CC) -o $@ $^ $(CPPFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
