FROM gcc:latest

RUN apt-get update && apt-get install -y \
    g++ \
    gdb \
    make

WORKDIR /workspace
