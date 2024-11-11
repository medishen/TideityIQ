FROM ubuntu:latest
RUN apt-get update && \
    apt-get install -y \
    gcc \
    make \
    build-essential \
    wget \
    curl \
    ca-certificates \
    git \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /usr/src/app
COPY ./src /usr/src/app/src
COPY ./include /usr/src/app/include
COPY ./Makefile /usr/src/app/Makefile
COPY ./bin/tdq /usr/local/bin/tdq
RUN chmod +x /usr/local/bin/tdq
RUN app-get install -y nodejs npm
ENTRYPOINT ["/usr/local/bin/tdq"]
CMD ["tdq"]
