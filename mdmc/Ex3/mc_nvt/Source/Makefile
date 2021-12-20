CC          = gcc
CLINKER     = gcc
EXECS       = mc_nvt
CFLAGS      =  -g 
LIBS        = -lm
DEPEND= makedepend

SRC     = adjust.c energy.c lattice.c mc_nvt.c mc_move.c readdat.c sample.c writepdb.c ran_uniform.c system.c
OBJS    = adjust.o energy.o lattice.o mc_nvt.o mc_move.o readdat.o sample.o writepdb.o ran_uniform.o system.o

default: mc_nvt

all: $(EXECS)

mc_nvt:$(OBJS)
	$(CLINKER) $(OPTFLAGS) -o mc_nvt $(OBJS) $(LIBS)

clean:
	/bin/rm -f *.o *~ $(EXECS)

.c.o:
	$(CC) $(CFLAGS) -c $*.c

adjust.o: system.h
energy.o: system.h
lattice.o: system.h
readdat.o: system.h
mc_move.o: system.h ran_uniform.h
mc_nvt.o: system.h ran_uniform.h
readdat.o: system.h ran_uniform.h
system.o: system.h
writepdb.o: system.h
