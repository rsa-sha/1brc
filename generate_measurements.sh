#!/usr/bin/env bash
# Usage: ./generate.sh <num_rows> [output_file]
# Example: ./generate.sh 1000000 measurements.txt
#          ./generate.sh 1000000000 measurements.txt

set -euo pipefail

N=${1:?Usage: $0 <num_rows> [output_file]}
OUT=${2:-measurements.txt}

echo "Generating $N rows -> $OUT ..."

awk -v n="$N" 'BEGIN {
    srand()

    split("Abidjan|Accra|Addis Ababa|Adelaide|Aden|Ahmedabad|Albuquerque|\
Alexandria|Algiers|Alice Springs|Almaty|Amsterdam|Anadyr|Anchorage|\
Ankara|Antananarivo|Asuncion|Athens|Atlanta|Auckland|Austin|\
Baghdad|Baku|Bangkok|Barcelona|Beijing|Beirut|Belgrade|Berlin|\
Bishkek|Bogota|Brussels|Bucharest|Budapest|Buenos Aires|Cairo|\
Calgary|Cape Town|Caracas|Casablanca|Chicago|Colombo|Copenhagen|\
Dallas|Dhaka|Dubai|Dublin|Dushanbe|Frankfurt|Hanoi|Helsinki|\
Ho Chi Minh City|Hong Kong|Honolulu|Istanbul|Jakarta|Johannesburg|\
Kabul|Karachi|Kathmandu|Khartoum|Kiev|Kinshasa|Kolkata|Kuala Lumpur|\
Kuwait City|Lagos|Lahore|Lima|Lisbon|London|Los Angeles|Luanda|\
Madrid|Manila|Melbourne|Mexico City|Miami|Milan|Minsk|Montevideo|\
Montreal|Moscow|Mumbai|Nairobi|New York|Nicosia|Oslo|Ottawa|\
Panama City|Paris|Perth|Prague|Pyongyang|Quito|Reykjavik|Riyadh|\
Rome|Santiago|Seoul|Shanghai|Singapore|Sofia|Stockholm|Sydney|\
Taipei|Tashkent|Tehran|Tokyo|Toronto|Tunis|Ulaanbaatar|Vienna|\
Warsaw|Washington D.C.|Wellington|Yangon|Zagreb|Zurich", stations, "|")

    ns = length(stations)

    for (i = 0; i < n; i++) {
        s = stations[int(rand() * ns) + 1]

        # Random temp in [-99.9, 99.9] with one decimal
        raw = int(rand() * 1998) - 999   # integer in [-999, 999] representing tenths
        if (raw < 0) {
            printf "%s;-%d.%d\n", s, int(-raw / 10), (-raw % 10)
        } else {
            printf "%s;%d.%d\n", s, int(raw / 10), (raw % 10)
        }
    }
}' /dev/null > "$OUT"

echo "Done. $(wc -l < "$OUT") rows written to $OUT."
