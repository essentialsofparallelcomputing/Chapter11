All: OpenACC OpenMP

.PHONY: OpenACC OpenMP

OpenACC:
	CC=pgcc && cd OpenACC && make

OpenMP:
	CC=gcc && cd OpenMP && make

clean:
	cd OpenACC && make clean
	cd OpenMP && make clean
