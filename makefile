CC = g++
CFLAGS = -I$(IDIR) -fPIC
IDIR = ./include

_DEPS = aptx100.h defs.h libaptx100.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

ODIR = obj

_OBJ = aptx100.o libaptx100.o mmx.o qmf.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: src/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/libaptx100.so: $(OBJ)
	$(CC) -shared -o $@ $^ $(CFLAGS)

clean: 
	rm -f $(ODIR)/*.o
	rm -f $(ODIR)/*.so

install:
	sudo cp $(ODIR)/libaptx100.so /usr/local/lib/libaptx100.so
	sudo ldconfig

uninstall:
	sudo rm /usr/local/lib/libaptx100.so
	sudo ldconfig