default:	StreamTriad StreamTriad_par1 StreamTriad_par2
all:	StreamTriad StreamTriad_par1 StreamTriad_par2

CFLAGS:=-qthreaded -g -O3 -std=gnu99 -fstrict-aliasing \
	-fopenmp -foffload=nvptx-none -foffload=-lm -fopt-info-omp

%.o: %.c
	${CC} ${CFLAGS} -c $^

StreamTriad: StreamTriad.o timer.o
	${CC} ${CFLAGS} $^ -o StreamTriad

StreamTriad_par1: StreamTriad_par1.o timer.o
	${CC} ${CFLAGS} $^ -o StreamTriad_par1

StreamTriad_par2: StreamTriad_par2.o timer.o
	${CC} ${CFLAGS} $^ -o StreamTriad_par2

clean:
	rm -f StreamTriad StreamTriad.o
	rm -f StreamTriad_par1 StreamTriad_par1.o
	rm -f StreamTriad_par2 StreamTriad_par2.o

distclean:
	rm -f Makefile
