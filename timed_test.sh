#!/usr/bin/env bash
set -euo pipefail

BIN="./bin/main"
OUT="res"
MD="benchmark.md"

tmp=$(mktemp)

# Run benchmark
/usr/bin/time -v "$BIN" > "$OUT" 2> "$tmp"

wall=$(grep "Elapsed (wall clock) time" "$tmp" | sed 's/.*: //')
user=$(grep "User time (seconds)" "$tmp" | awk '{print $NF}')
sys=$(grep "System time (seconds)" "$tmp" | awk '{print $NF}')
cpu=$(grep "Percent of CPU this job got" "$tmp" | awk '{print $NF}')
rss=$(grep "Maximum resident set size" "$tmp" | awk '{print $NF}')
minor=$(grep "Minor (reclaiming a frame) page faults" "$tmp" | awk '{print $NF}')
major=$(grep "Major (requiring I/O) page faults" "$tmp" | awk '{print $NF}')

timestamp=$(date "+%Y-%m-%d %H:%M:%S")

# Create markdown table if needed
if [ ! -f "$MD" ]; then
    cat > "$MD" <<EOF
# 1BRC Benchmark Results

| Timestamp | Wall Time | User | Sys | CPU | Max RSS (KB) | Minor PF | Major PF | Version |
|------------|------------|------|------|------|-------------|----------|----------|----------|
EOF
fi

echo "| $timestamp | $wall | $user | $sys | $cpu | $rss | $minor | $major | |" >> "$MD"

rm -f "$tmp" "$OUT"

echo "Benchmark appended to $MD"


#### This file has been generaed using AI tool
