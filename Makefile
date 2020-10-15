All: OpenACC OpenMP

.PHONY: OpenACC OpenMP

OpenACC:
	export CC=pgcc && cd OpenACC && make

OpenMP:
	export CC=gcc && cd OpenMP && make

clean:
	cd OpenACC && make clean
	cd OpenMP && make clean
