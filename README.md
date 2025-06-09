# zigpy
Simple project for working out how to bind zig code to python focusing on numpy arrays. We will only be looking at large simulation functions that perform relatively heavy data processing so we can afford to use `cffi` or `ctypes` as the overhead of calling through these will be small compared to work the function itself performs. We will focus on benchmarking these for now to see which is best suited for this purpose.

Other options to investigate later:
- Cython: use `zig translate-c` and then write a cython wrapper to build everything.
- ziggy-pydust: supports buffer protocol for numpy arrays.
- pybind11: intended for C++ but can try linking with Zig.

