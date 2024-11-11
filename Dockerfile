# Use a base image with a newer GLIBC version (Ubuntu 22.04 or newer)
FROM ubuntu:22.04

# Install necessary packages, including make and gcc
RUN apt-get update && apt-get install -y make gcc

# Set working directory
WORKDIR /usr/src/app

# Copy the entire project into the container
COPY . /usr/src/app
COPY ./bin/tdq /usr/local/bin/tdq

# Compile tdq binary inside the container
RUN make -f Makefile

# Set the permissions for the binary
RUN chmod +x /usr/local/bin/tdq

# Default command to run tdq when no args are passed
ENTRYPOINT ["/usr/local/bin/tdq"]
CMD []
