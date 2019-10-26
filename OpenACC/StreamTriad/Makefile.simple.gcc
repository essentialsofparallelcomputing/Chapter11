default:	StreamTriad StreamTriad_par1 StreamTriad_par2 StreamTriad_par3 StreamTriad_par4 \
   	StreamTriad_kern1 StreamTriad_kern2 StreamTriad_kern3
all:	StreamTriad StreamTriad_par1 StreamTriad_par2 StreamTriad_par3 StreamTriad_par4 \
   	StreamTriad_kern1 StreamTriad_kern2 StreamTriad_kern3

# may need -foffload=-lm for math functions inside of kernels
CFLAGS:= -g -O3 -std=gnu99 -fstrict-aliasing -fopenacc -fopt-info-optimized-omp

%.o: %.c
	${CC} ${CFLAGS} -c $^

StreamTriad: StreamTriad.o timer.o
	${CC} ${CFLAGS} $^ -o StreamTriad

StreamTriad_par1: StreamTriad_par1.o timer.o
	${CC} ${CFLAGS} $^ -o StreamTriad_par1

StreamTriad_par2: StreamTriad_par2.o timer.o
	${CC} ${CFLAGS} $^ -o StreamTriad_par2

StreamTriad_par3: StreamTriad_par3.o timer.o
	${CC} ${CFLAGS} $^ -o StreamTriad_par3

StreamTriad_par4: StreamTriad_par4.o timer.o
	${CC} ${CFLAGS} $^ -o StreamTriad_par4

StreamTriad_kern1: StreamTriad_kern1.o timer.o
	${CC} ${CFLAGS} $^ -o StreamTriad_kern1

StreamTriad_kern2: StreamTriad_kern2.o timer.o
	${CC} ${CFLAGS} $^ -o StreamTriad_kern2

StreamTriad_kern3: StreamTriad_kern3.o timer.o
	${CC} ${CFLAGS} $^ -o StreamTriad_kern3

clean:
	rm -f StreamTriad StreamTriad.o
	rm -f StreamTriad_par1 StreamTriad_par1.o
	rm -f StreamTriad_par2 StreamTriad_par2.o
	rm -f StreamTriad_par3 StreamTriad_par3.o
	rm -f StreamTriad_par4 StreamTriad_par4.o
	rm -f StreamTriad_kern1 StreamTriad_kern1.o
	rm -f StreamTriad_kern2 StreamTriad_kern2.o
	rm -f StreamTriad_kern3 StreamTriad_kern3.o
	rm -f timer.o

distclean:
	rm -f Makefile
