All: OpenACC OpenMP

.PHONY: OpenACC OpenMP

OpenACC:
	cd OpenACC; make

clean:
	cd OpenACC; make clean
