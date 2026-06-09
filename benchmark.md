# 1BRC Benchmark Results

| Timestamp | Wall Time | User | Sys | CPU | Max RSS (KB) | Minor PF | Major PF | Version |
|------------|------------|------|------|------|-------------|----------|----------|----------|
| 2026-06-07 22:10:04 | 2:47.07 | 164.75 | 0.37 | 98% | 13500348 | 211035 | 0 | v0 (`mmap` + `unordered_map`)|
| 2026-06-07 22:11:37 | 1:08.17 | 67.78 | 0.38 | 99% | 13500596 | 211034 | 0 | v0.1 (substitute `operator []` in map with iterator and `.find()`)|
| 2026-06-09 23:26:58 | 0:54.78 | 54.41 | 0.31 | 99% | 13500320 | 211033 | 0 | v 0.2 custom float parser instead of `std::from_chars`|
| 2026-06-09 23:35:50 | 0:53.86 | 53.51 | 0.31 | 99% | 13500336 | 211035 | 0 | v 0.2 custom float parser instead of `std::from_chars` but using ints all the way|
