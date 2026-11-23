FROM fedora:latest

RUN dnf install -y \
    gcc-c++ \
    make \
    && dnf clean all

WORKDIR /app