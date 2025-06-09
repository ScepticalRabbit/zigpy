# Zig to Python: CFFI and CTypes

## CFFI
- Best example of using cffi is numpy-cffi-example using row reduction in C uses `cffi.from_buffer` in two different ways one where the array is copied and passed in, the other where the array is created in the C layer and passed back.

```python
import numpy as np
import cffi
ffi = cffi.FFI()

a = np.zeros(42)
data = a.__array_interface__['data'][0]
cptr = ffi.cast ( "double*" , data )
```

```pyton
array = np.zeros(16, dtype=np.float32)
pointer = ffi.from_buffer("float[]", array)
```