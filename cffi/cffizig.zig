const std = @import("std");

pub export fn add(a: f64, b: f64) f64 {
    return a+b;
}

pub export fn add_vec(v0: [*c]const f64 , v1: [*c]const f64, v_out: [*c]f64, len: usize) void {

    // We can create slices from C arrays!
    const s0 = v0[0..len];
    const s1 = v1[0..len];
    const s_out = v_out[0..len];


    for (0..s_out.len) |ii| {
        s_out[ii] = s0[ii] + s1[ii];
    }
}