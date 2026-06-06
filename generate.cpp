// 1BRC data generator
// Usage: ./generate <num_rows> [output_file]
// Example: ./generate 1000000000 measurements.txt

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <ctime>

static const char* STATIONS[] = {
    "Abidjan", "Accra", "Addis Ababa", "Adelaide", "Aden", "Ahmedabad",
    "Albuquerque", "Alexandria", "Algiers", "Alice Springs", "Almaty",
    "Amsterdam", "Anadyr", "Anchorage", "Ankara", "Antananarivo", "Asuncion",
    "Athens", "Atlanta", "Auckland", "Austin", "Baghdad", "Baku", "Bangkok",
    "Barcelona", "Beijing", "Beirut", "Belgrade", "Berlin", "Bishkek",
    "Bogota", "Brussels", "Bucharest", "Budapest", "Buenos Aires", "Cairo",
    "Calgary", "Cape Town", "Caracas", "Casablanca", "Chicago", "Colombo",
    "Copenhagen", "Dallas", "Dhaka", "Dubai", "Dublin", "Dushanbe",
    "Frankfurt", "Hanoi", "Helsinki", "Ho Chi Minh City", "Hong Kong",
    "Honolulu", "Istanbul", "Jakarta", "Johannesburg", "Kabul", "Karachi",
    "Kathmandu", "Khartoum", "Kiev", "Kinshasa", "Kolkata", "Kuala Lumpur",
    "Kuwait City", "Lagos", "Lahore", "Lima", "Lisbon", "London",
    "Los Angeles", "Luanda", "Madrid", "Manila", "Melbourne", "Mexico City",
    "Miami", "Milan", "Minsk", "Montevideo", "Montreal", "Moscow", "Mumbai",
    "Nairobi", "New York", "Nicosia", "Oslo", "Ottawa", "Panama City",
    "Paris", "Perth", "Prague", "Pyongyang", "Quito", "Reykjavik", "Riyadh",
    "Rome", "Santiago", "Seoul", "Shanghai", "Singapore", "Sofia",
    "Stockholm", "Sydney", "Taipei", "Tashkent", "Tehran", "Tokyo",
    "Toronto", "Tunis", "Ulaanbaatar", "Vienna", "Warsaw", "Washington D.C.",
    "Wellington", "Yangon", "Zagreb", "Zurich",
};

static constexpr int NUM_STATIONS = sizeof(STATIONS) / sizeof(STATIONS[0]);

// Fast xorshift64 — much faster than rand(), good enough for data generation
static uint64_t rng_state;

inline uint64_t xorshift64() {
    rng_state ^= rng_state << 13;
    rng_state ^= rng_state >> 7;
    rng_state ^= rng_state << 17;
    return rng_state;
}

// Write an integer [0,99] as two chars without division — lookup table
static char tens_lut[100], ones_lut[100];

void init_lut() {
    for (int i = 0; i < 100; i++) {
        tens_lut[i] = '0' + i / 10;
        ones_lut[i] = '0' + i % 10;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <num_rows> [output_file]\n", argv[0]);
        return 1;
    }

    long long N = atoll(argv[1]);
    const char* outfile = (argc >= 3) ? argv[2] : "measurements.txt";

    if (N <= 0) {
        fprintf(stderr, "num_rows must be positive\n");
        return 1;
    }

    FILE* f = fopen(outfile, "wb");
    if (!f) {
        perror("fopen");
        return 1;
    }

    // Large write buffer — avoid flushing on every write
    static char wbuf[1 << 22]; // 4 MB
    setvbuf(f, wbuf, _IOFBF, sizeof(wbuf));

    rng_state = (uint64_t)time(nullptr) ^ 0xdeadbeefcafe1234ULL;
    init_lut();

    // Precompute station name lengths
    int slen[NUM_STATIONS];
    for (int i = 0; i < NUM_STATIONS; i++)
        slen[i] = (int)strlen(STATIONS[i]);

    // Local output buffer — batch writes
    static char buf[256];

    fprintf(stderr, "Generating %lld rows -> %s\n", N, outfile);

    for (long long i = 0; i < N; i++) {
        uint64_t r = xorshift64();

        // Pick station
        int sid = (int)(r % NUM_STATIONS);
        r = xorshift64();

        // Temperature: integer in [-999, 999] representing tenths of a degree
        int raw = (int)(r % 1999) - 999;  // [-999, 999]

        // Build line manually into buf
        char* p = buf;

        // Station name
        memcpy(p, STATIONS[sid], slen[sid]);
        p += slen[sid];
        *p++ = ';';

        // Temperature
        if (raw < 0) {
            *p++ = '-';
            raw = -raw;
        }
        int integer = raw / 10;
        int decimal = raw % 10;

        if (integer >= 10) {
            *p++ = tens_lut[integer];
            *p++ = ones_lut[integer];
        } else {
            *p++ = '0' + integer;
        }
        *p++ = '.';
        *p++ = '0' + decimal;
        *p++ = '\n';

        fwrite(buf, 1, p - buf, f);
    }

    fclose(f);
    fprintf(stderr, "Done.\n");
    return 0;
}
