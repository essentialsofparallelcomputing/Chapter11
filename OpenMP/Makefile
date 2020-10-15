All: StreamTriad Stencil
.PHONY: StreamTriad Stencil

StreamTriad: StreamTriad/build/StreamTriad

StreamTriad/build/StreamTriad:
	cd StreamTriad; mkdir build; cd build; cmake ..; make; ../run.sh

Stencil: Stencil/build/Stencil

Stencil/build/Stencil:
	cd Stencil; mkdir build; cd build; cmake ..; make; ../run.sh

clean:
	cd StreamTriad; rm -rf build
	cd mass_sum; rm -rf build
	cd Stencil; rm -rf build
