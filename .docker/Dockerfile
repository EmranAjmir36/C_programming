FROM debian:bookworm-slim

RUN apt-get update \
    && apt-get install -y --no-install-recommends build-essential gdb \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /work
