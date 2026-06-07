# 1BRC Benchmark Results

| Timestamp | Wall Time | User | Sys | CPU | Max RSS (KB) | Minor PF | Major PF | Version |
|------------|------------|------|------|------|-------------|----------|----------|----------|
| 2026-06-07 22:10:04 | 2:47.07 | 164.75 | 0.37 | 98% | 13500348 | 211035 | 0 | v0 (`mmap` + `unordered_map`)|
| 2026-06-07 22:11:37 | 1:08.17 | 67.78 | 0.38 | 99% | 13500596 | 211034 | 0 | v0.1 (substitute `operator []` in map with iterator and `.find()`)|
