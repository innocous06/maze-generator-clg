# Feature Spec: refactor: flat buffer memory allocation for grid

## Summary
Replaced `int**` allocation with continuous 1D buffer to avoid pointer indirection.

## Benchmarks
25% speedup on generation.
