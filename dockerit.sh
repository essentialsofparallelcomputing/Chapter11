#!/bin/sh
docker build -t chapter11 .
docker run -it --entrypoint /bin/bash chapter11
