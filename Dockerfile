FROM gcc:latest

RUN apt-get update && \
    apt-get install -y cmake libgtest-dev && \
    cd /usr/src/gtest && \
    cmake CMakeLists.txt && \
    make  
RUN cp /usr/src/gtest/lib/*.a /usr/lib 

COPY . /usr/src/App
RUN ls /usr/src/App
WORKDIR /usr/src/App

RUN rm -f build && mkdir build && cd build && cmake -B . .. && make
    
CMD ["./build/App"]
# /usr/src/App/build