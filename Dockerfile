FROM ubuntu:18.04 AS builder
WORKDIR /project
RUN apt-get update && \
    apt-get install -y bash cmake git vim gcc wget python3 xterm openssh-server nvidia-visual-profiler nvidia-nsight imagemagick && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN wget -q https://github.com/GPUOpen-Tools/CodeXL/releases/download/v2.6/codexl_2.6-302_amd64.deb
RUN dpkg -i codexl_2.6-302_amd64.deb

SHELL ["/bin/bash", "-c"]
ENV PATH /opt/CodeXL_2.6-302:$PATH

RUN groupadd -r chapter11 && useradd -r -s /bin/false -g chapter11 chapter11

WORKDIR /chapter11
RUN chown -R chapter11:chapter11 /chapter11
USER chapter11

RUN git clone --recursive https://github.com/essentialsofparallelcomputing/Chapter11.git

ENTRYPOINT ["bash"]
