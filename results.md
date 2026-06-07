# 1BRC versions results and comparison work

### Version 1

<details>
<summary> Basic implementation using mmap, unordered_set </summary>

```bash
sah@rsa-sha:~/code/1brc$  /usr/bin/time -v ./bin/main
City: Abidjan | Min -> -99.9 | Max -> 99.9 | Avg -> -0.02652
City: Accra | Min -> -99.9 | Max -> 99.9 | Avg -> -0.00621065
City: Addis Ababa | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0147879
City: Adelaide | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0265327
City: Aden | Min -> -99.9 | Max -> 99.9 | Avg -> 0.00739486
City: Ahmedabad | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0536113
City: Albuquerque | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0018824
City: Alexandria | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0145811
City: Algiers | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0101931
City: Alice Springs | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0225729
City: Almaty | Min -> -99.9 | Max -> 99.9 | Avg -> 0.00138126
City: Amsterdam | Min -> -99.9 | Max -> 99.9 | Avg -> -0.000650209
City: Anadyr | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0285088
City: Anchorage | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0106604
City: Ankara | Min -> -99.9 | Max -> 99.9 | Avg -> -0.00545568
City: Antananarivo | Min -> -99.9 | Max -> 99.9 | Avg -> 0.00552332
City: Asuncion | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0137548
City: Athens | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0290195
City: Atlanta | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0253193
City: Auckland | Min -> -99.9 | Max -> 99.9 | Avg -> 0.00444124
City: Austin | Min -> -99.9 | Max -> 99.9 | Avg -> 0.00704705
City: Baghdad | Min -> -99.9 | Max -> 99.9 | Avg -> 0.00695547
City: Baku | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0113714
City: Bangkok | Min -> -99.9 | Max -> 99.9 | Avg -> -0.00571093
City: Barcelona | Min -> -99.9 | Max -> 99.9 | Avg -> -0.010364
City: Beijing | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0147347
City: Beirut | Min -> -99.9 | Max -> 99.9 | Avg -> -0.00316793
City: Belgrade | Min -> -99.9 | Max -> 99.9 | Avg -> -0.00465011
City: Berlin | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0101153
City: Bishkek | Min -> -99.9 | Max -> 99.9 | Avg -> -0.043866
City: Bogota | Min -> -99.9 | Max -> 99.9 | Avg -> 0.00816133
City: Brussels | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0115012
City: Bucharest | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0155587
City: Budapest | Min -> -99.9 | Max -> 99.9 | Avg -> 0.00111906
City: Buenos Aires | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0543955
City: Cairo | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0109943
City: Calgary | Min -> -99.9 | Max -> 99.9 | Avg -> -0.00260026
City: Cape Town | Min -> -99.9 | Max -> 99.9 | Avg -> 0.00267197
City: Caracas | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0255599
City: Casablanca | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0161497
City: Chicago | Min -> -99.9 | Max -> 99.9 | Avg -> 0.00911315
City: Colombo | Min -> -99.9 | Max -> 99.9 | Avg -> 0.00560481
City: Copenhagen | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0139269
City: Dallas | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0049363
City: Dhaka | Min -> -99.9 | Max -> 99.9 | Avg -> 0.00360725
City: Dubai | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0095774
City: Dublin | Min -> -99.9 | Max -> 99.9 | Avg -> 0.00615057
City: Dushanbe | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0226321
City: Frankfurt | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0172343
City: Hanoi | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0118763
City: Helsinki | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0164402
City: Ho Chi Minh City | Min -> -99.9 | Max -> 99.9 | Avg -> 0.00861937
City: Hong Kong | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0307292
City: Honolulu | Min -> -99.9 | Max -> 99.9 | Avg -> 0.00834067
City: Istanbul | Min -> -99.9 | Max -> 99.9 | Avg -> 0.00570723
City: Jakarta | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0135277
City: Johannesburg | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0504163
City: Kabul | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0125863
City: Karachi | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0183407
City: Kathmandu | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0112663
City: Khartoum | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0174527
City: Kiev | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0149616
City: Kinshasa | Min -> -99.9 | Max -> 99.9 | Avg -> 0.00697513
City: Kolkata | Min -> -99.9 | Max -> 99.9 | Avg -> -9.45416e-05
City: Kuala Lumpur | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0186854
City: Kuwait City | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0188907
City: Lagos | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0161174
City: Lahore | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0291571
City: Lima | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0196318
City: Lisbon | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0360909
City: London | Min -> -99.9 | Max -> 99.9 | Avg -> -0.00566256
City: Los Angeles | Min -> -99.9 | Max -> 99.9 | Avg -> 0.00203105
City: Luanda | Min -> -99.9 | Max -> 99.9 | Avg -> 0.017699
City: Madrid | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0235297
City: Manila | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0203164
City: Melbourne | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0178008
City: Mexico City | Min -> -99.9 | Max -> 99.9 | Avg -> -0.00772601
City: Miami | Min -> -99.9 | Max -> 99.9 | Avg -> -0.000448983
City: Milan | Min -> -99.9 | Max -> 99.9 | Avg -> -0.00699929
City: Minsk | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0552925
City: Montevideo | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0111481
City: Montreal | Min -> -99.9 | Max -> 99.9 | Avg -> 0.00321761
City: Moscow | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0467476
City: Mumbai | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0344357
City: Nairobi | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0132357
City: New York | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0128156
City: Nicosia | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0124254
City: Oslo | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0238775
City: Ottawa | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0174615
City: Panama City | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0638636
City: Paris | Min -> -99.9 | Max -> 99.9 | Avg -> -0.00444427
City: Perth | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0101636
City: Prague | Min -> -99.9 | Max -> 99.9 | Avg -> -0.00104465
City: Pyongyang | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0261032
City: Quito | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0206385
City: Reykjavik | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0307326
City: Riyadh | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0016564
City: Rome | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0248763
City: Santiago | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0323911
City: Seoul | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0273577
City: Shanghai | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0249298
City: Singapore | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0101059
City: Sofia | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0137736
City: Stockholm | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0237798
City: Sydney | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0445585
City: Taipei | Min -> -99.9 | Max -> 99.9 | Avg -> -0.000530691
City: Tashkent | Min -> -99.9 | Max -> 99.9 | Avg -> -0.00534888
City: Tehran | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0229757
City: Tokyo | Min -> -99.9 | Max -> 99.9 | Avg -> -0.01849
City: Toronto | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0137597
City: Tunis | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0161423
City: Ulaanbaatar | Min -> -99.9 | Max -> 99.9 | Avg -> -0.00336241
City: Vienna | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0411671
City: Warsaw | Min -> -99.9 | Max -> 99.9 | Avg -> 0.000715304
City: Washington D.C. | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0099278
City: Wellington | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0190328
City: Yangon | Min -> -99.9 | Max -> 99.9 | Avg -> -0.0129107
City: Zagreb | Min -> -99.9 | Max -> 99.9 | Avg -> -0.027098
City: Zurich | Min -> -99.9 | Max -> 99.9 | Avg -> 0.0310208
        Command being timed: "./bin/main"
        User time (seconds): 124.52
        System time (seconds): 1.20
        Percent of CPU this job got: 98%
        Elapsed (wall clock) time (h:mm:ss or m:ss): 2:07.20
        Average shared text size (kbytes): 0
        Average unshared data size (kbytes): 0
        Average stack size (kbytes): 0
        Average total size (kbytes): 0
        Maximum resident set size (kbytes): 13452232
        Average resident set size (kbytes): 0
        Major (requiring I/O) page faults: 27
        Minor (reclaiming a frame) page faults: 211036
        Voluntary context switches: 267
        Involuntary context switches: 2377
        Swaps: 0
        File system inputs: 4454656
        File system outputs: 0
        Socket messages sent: 0
        Socket messages received: 0
        Signals delivered: 0
        Page size (bytes): 4096
        Exit status: 0
```

</details>

#### Issues found using perf
- `std::unordered_map` operations accounted for `~50%` of the total runtime
    - Reserving some amount of memory space like `~1K` to prevent rehashing as number of keys is bounded
    - Test the performance of `map.find(city)` instead of `map[city]` as it could be faster
---

### Version 2

Substituted `operator []` in `unordered_map`:
```cpp
    _data[city].tot += temp;
    _data[city].min = _data[city].min > temp ? temp : _data[city].min;
    _data[city].max = _data[city].max < temp ? temp : _data[city].max;
    _data[city].count++;
```
with iterator and calling `find`:
```cpp
    auto it = _data.find(city);
    if (it == _data.end()) {
        auto [newItr, inserted] = _data.emplace(city, LocationData{temp, temp, temp, 1});
        it = newItr;
    }
    it->second.update(temp);
```

Results are updated in [benchmark.md](./benchmark.md)
