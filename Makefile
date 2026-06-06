CXX      := g++
CXXFLAGS_COMMON := -std=c++23 -Wall -Wextra

# Build-type flags
CXXFLAGS_RELEASE := $(CXXFLAGS_COMMON) -O3 -march=native -DNDEBUG
CXXFLAGS_DEBUG   := $(CXXFLAGS_COMMON) -O0 -g3 -fsanitize=address,undefined -DDEBUG
CXXFLAGS_BENCH   := $(CXXFLAGS_COMMON) -O3 -march=native -pg -DNDEBUG

OUTDIR := bin
$(shell mkdir -p $(OUTDIR))

# ── Targets ───────────────────────────────────────────────────────────────────

.PHONY: all release debug bench clean run-generate help

all: release

## release: build main + generate, fully optimised (default)
release: $(OUTDIR)/main $(OUTDIR)/generate

## debug: build main + generate with ASan/UBSan and debug symbols
debug: $(OUTDIR)/main_debug $(OUTDIR)/generate_debug

## bench: build main + generate with gprof instrumentation
bench: $(OUTDIR)/main_bench $(OUTDIR)/generate_bench

# ── main ──────────────────────────────────────────────────────────────────────

$(OUTDIR)/main: main.cpp
	$(CXX) $(CXXFLAGS_RELEASE) $< -o $@

$(OUTDIR)/main_debug: main.cpp
	$(CXX) $(CXXFLAGS_DEBUG) $< -o $@

$(OUTDIR)/main_bench: main.cpp
	$(CXX) $(CXXFLAGS_BENCH) $< -o $@

# ── generate ──────────────────────────────────────────────────────────────────

$(OUTDIR)/generate: generate.cpp
	$(CXX) $(CXXFLAGS_RELEASE) $< -o $@

$(OUTDIR)/generate_debug: generate.cpp
	$(CXX) $(CXXFLAGS_DEBUG) $< -o $@

$(OUTDIR)/generate_bench: generate.cpp
	$(CXX) $(CXXFLAGS_BENCH) $< -o $@

# ── helpers ───────────────────────────────────────────────────────────────────

ROWS     ?= 1000000
DATAFILE ?= measurements.txt

## run-generate: build + run generator  (ROWS=N DATAFILE=path)
run-generate: $(OUTDIR)/generate
	$(OUTDIR)/generate $(ROWS) $(DATAFILE)

## run: build + run main against DATAFILE
run: $(OUTDIR)/main
	$(OUTDIR)/main $(DATAFILE)

## benchmark: time main against DATAFILE using hyperfine if available
benchmark: $(OUTDIR)/main
	@if command -v hyperfine > /dev/null 2>&1; then \
		hyperfine --warmup 1 '$(OUTDIR)/main $(DATAFILE)'; \
	else \
		echo "hyperfine not found, falling back to time:"; \
		time $(OUTDIR)/main $(DATAFILE); \
	fi

## profile: run gprof build then generate gprof report
profile: $(OUTDIR)/main_bench
	$(OUTDIR)/main_bench $(DATAFILE)
	gprof $(OUTDIR)/main_bench gmon.out > profile_report.txt
	@echo "Report written to profile_report.txt"

## clean: remove bin/ and generated artefacts
clean:
	rm -rf $(OUTDIR) gmon.out profile_report.txt

## help: print this message
help:
	@grep -E '^##' Makefile | sed 's/^## /  /'
