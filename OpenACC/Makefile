All: StreamTriad mass_sum Stencil
.PHONY: StreamTriad mass_sum

StreamTriad: StreamTriad/build/StreamTriad

StreamTriad/build/StreamTriad:
	cd StreamTriad; mkdir build; cd build; cmake ..; make; ../run.sh

mass_sum: mass_sum/build/mass_sum

mass_sum/build/mass_sum:
	cd mass_sum; mkdir build; cd build; cmake ..; make; ./mass_sum

Stencil: Stencil/build/Stencil

Stencil/build/Stencil:
	cd Stencil; mkdir build; cd build; cmake ..; make; ../run.sh

clean:
	cd StreamTriad; rm -rf build
	cd mass_sum; rm -rf build
	cd Stencil; rm -rf build
