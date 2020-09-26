# UDPipe Wrapper for Julia

![CI Status](https://api.travis-ci.org/peter-grajcar/UDPipe_Julia_Wrapper.svg)

## Compile

You will need both [udpipe](https://github.com/ufal/udpipe) and UDPipe_Julia_Wrapper repositories placed in
the same directory.

```txt
.
├── UDPipe_Julia_Wrapper
├── udpipe
```

You will also need to build [libcxxwrap-julia]( https://github.com/JuliaInterop/libcxxwrap-julia) (instructions are inside libcxxwrap-julia repository).

Set CxxWrap directory (for CMake). 

```sh
export JlCxx_DIR=/path/to/compiled/cxxwrap-julia
```

Move to UDPipe Julia Wrapper directory and build:

```sh
mkdir build
cd build
cmake ..
make 
```

This will compile both udpipe and UDPipe Julia Wrapper sources.

