FROM nvcr.io/hpc/pgi-compilers:ce
WORKDIR /project
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get -qq update && \
    apt-get -qq install -y cmake git vim gcc g++ gfortran software-properties-common python3 \
            nvidia-visual-profiler nvidia-nsight && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Installing latest GCC compiler (version 8)
RUN add-apt-repository ppa:ubuntu-toolchain-r/test
RUN apt-get -qq update && \
    apt-get -qq install -y gcc-8 g++-8 gfortran-8 \
                          gcc-9 g++-9 gfortran-9 \
                          gcc-10 g++-10 gfortran-10 && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# We can use the update-alternatives to switch between compiler versions
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-8 90\
                        --slave /usr/bin/g++ g++ /usr/bin/g++-8\
                        --slave /usr/bin/gfortran gfortran /usr/bin/gfortran-8\
                        --slave /usr/bin/gcov gcov /usr/bin/gcov-8

RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-9 80\
                        --slave /usr/bin/g++ g++ /usr/bin/g++-9\
                        --slave /usr/bin/gfortran gfortran /usr/bin/gfortran-9\
                        --slave /usr/bin/gcov gcov /usr/bin/gcov-9

RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-10 80\
                        --slave /usr/bin/g++ g++ /usr/bin/g++-10\
                        --slave /usr/bin/gfortran gfortran /usr/bin/gfortran-10\
                        --slave /usr/bin/gcov gcov /usr/bin/gcov-10

RUN chmod u+s /usr/bin/update-alternatives

SHELL ["/bin/bash", "-c"]

RUN groupadd -r chapter11 && useradd -r -s /bin/false -g chapter11 chapter11

WORKDIR /chapter11
RUN chown -R chapter11:chapter11 /chapter11
USER chapter11

RUN git clone --recursive https://github.com/essentialsofparallelcomputing/Chapter11.git

ENTRYPOINT ["bash"]
