# Zig Translate-C

## Zig to C:
```shell
zig build-lib -femit-h hello.zig
```

## Converting Zig to C Helper
From here: https://ziggit.dev/t/ziguanic-way-of-converting-c-types-to-zig-types/3193 
```zig
const clib = @cImport({
    @cInclude("clib.h");
});

pub fn sliceFromAnyopaque(c_ptr: ?*anyopaque, comptime child_type: type) [:0]child_type {
    const slc: [*c]child_type = @as([*c]child_type, @alignCast(@ptrCast(c_ptr.?)));
    const sp = std.mem.span(slc);
    return (sp);
}

pub fn anyopaqueFromSlice(slice: anytype) ?*anyopaque {
    return (@as(?*anyopaque, @alignCast(@ptrCast(slice.ptr))));
}

test "heap_allocator : test1" {
    const heap: *HeapAllocator = clib.heap_init();
    defer _ = clib.heap_deinit(heap);
    const ptr = sliceFromAnyopaque(heap.alloc.?(heap, 32), u8);
    defer _ = heap.dealloc.?(heap, anyopaqueFromSlice(ptr));
}
```

