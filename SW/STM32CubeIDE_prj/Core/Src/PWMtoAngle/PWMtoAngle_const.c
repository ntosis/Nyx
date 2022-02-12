/*
 * File: PWMtoAngle_const.c
 *
 * Code generated for Simulink model 'ConvertPWMtoAngle'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov  2 10:54:19 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtwtypes.h"
#include "ConvertPWMtoAngle_types.h"

/* Exported data definition */

/* Const memory section */
/* Definition for custom storage class: Const */
const int16_T Angle_T[4096] = { 0, 2, 3, 5, 6, 8, 9, 11, 13, 14, 16, 17, 19, 20,
  22, 24, 25, 27, 28, 30, 31, 33, 35, 36, 38, 39, 41, 42, 44, 46, 47, 49, 50, 52,
  53, 55, 57, 58, 60, 61, 63, 64, 66, 68, 69, 71, 72, 74, 75, 77, 78, 80, 82, 83,
  85, 86, 88, 89, 91, 93, 94, 96, 97, 99, 100, 102, 104, 105, 107, 108, 110, 111,
  113, 115, 116, 118, 119, 121, 122, 124, 126, 127, 129, 130, 132, 133, 135, 137,
  138, 140, 141, 143, 144, 146, 148, 149, 151, 152, 154, 155, 157, 159, 160, 162,
  163, 165, 166, 168, 170, 171, 173, 174, 176, 177, 179, 181, 182, 184, 185, 187,
  188, 190, 192, 193, 195, 196, 198, 199, 201, 203, 204, 206, 207, 209, 210, 212,
  213, 215, 217, 218, 220, 221, 223, 224, 226, 228, 229, 231, 232, 234, 235, 237,
  239, 240, 242, 243, 245, 246, 248, 250, 251, 253, 254, 256, 257, 259, 261, 262,
  264, 265, 267, 268, 270, 272, 273, 275, 276, 278, 279, 281, 283, 284, 286, 287,
  289, 290, 292, 294, 295, 297, 298, 300, 301, 303, 305, 306, 308, 309, 311, 312,
  314, 316, 317, 319, 320, 322, 323, 325, 327, 328, 330, 331, 333, 334, 336, 338,
  339, 341, 342, 344, 345, 347, 348, 350, 352, 353, 355, 356, 358, 359, 361, 363,
  364, 366, 367, 369, 370, 372, 374, 375, 377, 378, 380, 381, 383, 385, 386, 388,
  389, 391, 392, 394, 396, 397, 399, 400, 402, 403, 405, 407, 408, 410, 411, 413,
  414, 416, 418, 419, 421, 422, 424, 425, 427, 429, 430, 432, 433, 435, 436, 438,
  440, 441, 443, 444, 446, 447, 449, 451, 452, 454, 455, 457, 458, 460, 462, 463,
  465, 466, 468, 469, 471, 473, 474, 476, 477, 479, 480, 482, 483, 485, 487, 488,
  490, 491, 493, 494, 496, 498, 499, 501, 502, 504, 505, 507, 509, 510, 512, 513,
  515, 516, 518, 520, 521, 523, 524, 526, 527, 529, 531, 532, 534, 535, 537, 538,
  540, 542, 543, 545, 546, 548, 549, 551, 553, 554, 556, 557, 559, 560, 562, 564,
  565, 567, 568, 570, 571, 573, 575, 576, 578, 579, 581, 582, 584, 586, 587, 589,
  590, 592, 593, 595, 597, 598, 600, 601, 603, 604, 606, 608, 609, 611, 612, 614,
  615, 617, 618, 620, 622, 623, 625, 626, 628, 629, 631, 633, 634, 636, 637, 639,
  640, 642, 644, 645, 647, 648, 650, 651, 653, 655, 656, 658, 659, 661, 662, 664,
  666, 667, 669, 670, 672, 673, 675, 677, 678, 680, 681, 683, 684, 686, 688, 689,
  691, 692, 694, 695, 697, 699, 700, 702, 703, 705, 706, 708, 710, 711, 713, 714,
  716, 717, 719, 721, 722, 724, 725, 727, 728, 730, 732, 733, 735, 736, 738, 739,
  741, 743, 744, 746, 747, 749, 750, 752, 754, 755, 757, 758, 760, 761, 763, 764,
  766, 768, 769, 771, 772, 774, 775, 777, 779, 780, 782, 783, 785, 786, 788, 790,
  791, 793, 794, 796, 797, 799, 801, 802, 804, 805, 807, 808, 810, 812, 813, 815,
  816, 818, 819, 821, 823, 824, 826, 827, 829, 830, 832, 834, 835, 837, 838, 840,
  841, 843, 845, 846, 848, 849, 851, 852, 854, 856, 857, 859, 860, 862, 863, 865,
  867, 868, 870, 871, 873, 874, 876, 878, 879, 881, 882, 884, 885, 887, 889, 890,
  892, 893, 895, 896, 898, 899, 901, 903, 904, 906, 907, 909, 910, 912, 914, 915,
  917, 918, 920, 921, 923, 925, 926, 928, 929, 931, 932, 934, 936, 937, 939, 940,
  942, 943, 945, 947, 948, 950, 951, 953, 954, 956, 958, 959, 961, 962, 964, 965,
  967, 969, 970, 972, 973, 975, 976, 978, 980, 981, 983, 984, 986, 987, 989, 991,
  992, 994, 995, 997, 998, 1000, 1002, 1003, 1005, 1006, 1008, 1009, 1011, 1013,
  1014, 1016, 1017, 1019, 1020, 1022, 1024, 1025, 1027, 1028, 1030, 1031, 1033,
  1034, 1036, 1038, 1039, 1041, 1042, 1044, 1045, 1047, 1049, 1050, 1052, 1053,
  1055, 1056, 1058, 1060, 1061, 1063, 1064, 1066, 1067, 1069, 1071, 1072, 1074,
  1075, 1077, 1078, 1080, 1082, 1083, 1085, 1086, 1088, 1089, 1091, 1093, 1094,
  1096, 1097, 1099, 1100, 1102, 1104, 1105, 1107, 1108, 1110, 1111, 1113, 1115,
  1116, 1118, 1119, 1121, 1122, 1124, 1126, 1127, 1129, 1130, 1132, 1133, 1135,
  1137, 1138, 1140, 1141, 1143, 1144, 1146, 1148, 1149, 1151, 1152, 1154, 1155,
  1157, 1159, 1160, 1162, 1163, 1165, 1166, 1168, 1169, 1171, 1173, 1174, 1176,
  1177, 1179, 1180, 1182, 1184, 1185, 1187, 1188, 1190, 1191, 1193, 1195, 1196,
  1198, 1199, 1201, 1202, 1204, 1206, 1207, 1209, 1210, 1212, 1213, 1215, 1217,
  1218, 1220, 1221, 1223, 1224, 1226, 1228, 1229, 1231, 1232, 1234, 1235, 1237,
  1239, 1240, 1242, 1243, 1245, 1246, 1248, 1250, 1251, 1253, 1254, 1256, 1257,
  1259, 1261, 1262, 1264, 1265, 1267, 1268, 1270, 1272, 1273, 1275, 1276, 1278,
  1279, 1281, 1283, 1284, 1286, 1287, 1289, 1290, 1292, 1294, 1295, 1297, 1298,
  1300, 1301, 1303, 1304, 1306, 1308, 1309, 1311, 1312, 1314, 1315, 1317, 1319,
  1320, 1322, 1323, 1325, 1326, 1328, 1330, 1331, 1333, 1334, 1336, 1337, 1339,
  1341, 1342, 1344, 1345, 1347, 1348, 1350, 1352, 1353, 1355, 1356, 1358, 1359,
  1361, 1363, 1364, 1366, 1367, 1369, 1370, 1372, 1374, 1375, 1377, 1378, 1380,
  1381, 1383, 1385, 1386, 1388, 1389, 1391, 1392, 1394, 1396, 1397, 1399, 1400,
  1402, 1403, 1405, 1407, 1408, 1410, 1411, 1413, 1414, 1416, 1418, 1419, 1421,
  1422, 1424, 1425, 1427, 1429, 1430, 1432, 1433, 1435, 1436, 1438, 1439, 1441,
  1443, 1444, 1446, 1447, 1449, 1450, 1452, 1454, 1455, 1457, 1458, 1460, 1461,
  1463, 1465, 1466, 1468, 1469, 1471, 1472, 1474, 1476, 1477, 1479, 1480, 1482,
  1483, 1485, 1487, 1488, 1490, 1491, 1493, 1494, 1496, 1498, 1499, 1501, 1502,
  1504, 1505, 1507, 1509, 1510, 1512, 1513, 1515, 1516, 1518, 1520, 1521, 1523,
  1524, 1526, 1527, 1529, 1531, 1532, 1534, 1535, 1537, 1538, 1540, 1542, 1543,
  1545, 1546, 1548, 1549, 1551, 1553, 1554, 1556, 1557, 1559, 1560, 1562, 1564,
  1565, 1567, 1568, 1570, 1571, 1573, 1575, 1576, 1578, 1579, 1581, 1582, 1584,
  1585, 1587, 1589, 1590, 1592, 1593, 1595, 1596, 1598, 1600, 1601, 1603, 1604,
  1606, 1607, 1609, 1611, 1612, 1614, 1615, 1617, 1618, 1620, 1622, 1623, 1625,
  1626, 1628, 1629, 1631, 1633, 1634, 1636, 1637, 1639, 1640, 1642, 1644, 1645,
  1647, 1648, 1650, 1651, 1653, 1655, 1656, 1658, 1659, 1661, 1662, 1664, 1666,
  1667, 1669, 1670, 1672, 1673, 1675, 1677, 1678, 1680, 1681, 1683, 1684, 1686,
  1688, 1689, 1691, 1692, 1694, 1695, 1697, 1699, 1700, 1702, 1703, 1705, 1706,
  1708, 1710, 1711, 1713, 1714, 1716, 1717, 1719, 1720, 1722, 1724, 1725, 1727,
  1728, 1730, 1731, 1733, 1735, 1736, 1738, 1739, 1741, 1742, 1744, 1746, 1747,
  1749, 1750, 1752, 1753, 1755, 1757, 1758, 1760, 1761, 1763, 1764, 1766, 1768,
  1769, 1771, 1772, 1774, 1775, 1777, 1779, 1780, 1782, 1783, 1785, 1786, 1788,
  1790, 1791, 1793, 1794, 1796, 1797, 1799, 1801, 1802, 1804, 1805, 1807, 1808,
  1810, 1812, 1813, 1815, 1816, 1818, 1819, 1821, 1823, 1824, 1826, 1827, 1829,
  1830, 1832, 1834, 1835, 1837, 1838, 1840, 1841, 1843, 1845, 1846, 1848, 1849,
  1851, 1852, 1854, 1855, 1857, 1859, 1860, 1862, 1863, 1865, 1866, 1868, 1870,
  1871, 1873, 1874, 1876, 1877, 1879, 1881, 1882, 1884, 1885, 1887, 1888, 1890,
  1892, 1893, 1895, 1896, 1898, 1899, 1901, 1903, 1904, 1906, 1907, 1909, 1910,
  1912, 1914, 1915, 1917, 1918, 1920, 1921, 1923, 1925, 1926, 1928, 1929, 1931,
  1932, 1934, 1936, 1937, 1939, 1940, 1942, 1943, 1945, 1947, 1948, 1950, 1951,
  1953, 1954, 1956, 1958, 1959, 1961, 1962, 1964, 1965, 1967, 1969, 1970, 1972,
  1973, 1975, 1976, 1978, 1980, 1981, 1983, 1984, 1986, 1987, 1989, 1990, 1992,
  1994, 1995, 1997, 1998, 2000, 2001, 2003, 2005, 2006, 2008, 2009, 2011, 2012,
  2014, 2016, 2017, 2019, 2020, 2022, 2023, 2025, 2027, 2028, 2030, 2031, 2033,
  2034, 2036, 2038, 2039, 2041, 2042, 2044, 2045, 2047, 2049, 2050, 2052, 2053,
  2055, 2056, 2058, 2060, 2061, 2063, 2064, 2066, 2067, 2069, 2071, 2072, 2074,
  2075, 2077, 2078, 2080, 2082, 2083, 2085, 2086, 2088, 2089, 2091, 2093, 2094,
  2096, 2097, 2099, 2100, 2102, 2104, 2105, 2107, 2108, 2110, 2111, 2113, 2115,
  2116, 2118, 2119, 2121, 2122, 2124, 2125, 2127, 2129, 2130, 2132, 2133, 2135,
  2136, 2138, 2140, 2141, 2143, 2144, 2146, 2147, 2149, 2151, 2152, 2154, 2155,
  2157, 2158, 2160, 2162, 2163, 2165, 2166, 2168, 2169, 2171, 2173, 2174, 2176,
  2177, 2179, 2180, 2182, 2184, 2185, 2187, 2188, 2190, 2191, 2193, 2195, 2196,
  2198, 2199, 2201, 2202, 2204, 2206, 2207, 2209, 2210, 2212, 2213, 2215, 2217,
  2218, 2220, 2221, 2223, 2224, 2226, 2228, 2229, 2231, 2232, 2234, 2235, 2237,
  2239, 2240, 2242, 2243, 2245, 2246, 2248, 2250, 2251, 2253, 2254, 2256, 2257,
  2259, 2261, 2262, 2264, 2265, 2267, 2268, 2270, 2271, 2273, 2275, 2276, 2278,
  2279, 2281, 2282, 2284, 2286, 2287, 2289, 2290, 2292, 2293, 2295, 2297, 2298,
  2300, 2301, 2303, 2304, 2306, 2308, 2309, 2311, 2312, 2314, 2315, 2317, 2319,
  2320, 2322, 2323, 2325, 2326, 2328, 2330, 2331, 2333, 2334, 2336, 2337, 2339,
  2341, 2342, 2344, 2345, 2347, 2348, 2350, 2352, 2353, 2355, 2356, 2358, 2359,
  2361, 2363, 2364, 2366, 2367, 2369, 2370, 2372, 2374, 2375, 2377, 2378, 2380,
  2381, 2383, 2385, 2386, 2388, 2389, 2391, 2392, 2394, 2396, 2397, 2399, 2400,
  2402, 2403, 2405, 2406, 2408, 2410, 2411, 2413, 2414, 2416, 2417, 2419, 2421,
  2422, 2424, 2425, 2427, 2428, 2430, 2432, 2433, 2435, 2436, 2438, 2439, 2441,
  2443, 2444, 2446, 2447, 2449, 2450, 2452, 2454, 2455, 2457, 2458, 2460, 2461,
  2463, 2465, 2466, 2468, 2469, 2471, 2472, 2474, 2476, 2477, 2479, 2480, 2482,
  2483, 2485, 2487, 2488, 2490, 2491, 2493, 2494, 2496, 2498, 2499, 2501, 2502,
  2504, 2505, 2507, 2509, 2510, 2512, 2513, 2515, 2516, 2518, 2520, 2521, 2523,
  2524, 2526, 2527, 2529, 2531, 2532, 2534, 2535, 2537, 2538, 2540, 2541, 2543,
  2545, 2546, 2548, 2549, 2551, 2552, 2554, 2556, 2557, 2559, 2560, 2562, 2563,
  2565, 2567, 2568, 2570, 2571, 2573, 2574, 2576, 2578, 2579, 2581, 2582, 2584,
  2585, 2587, 2589, 2590, 2592, 2593, 2595, 2596, 2598, 2600, 2601, 2603, 2604,
  2606, 2607, 2609, 2611, 2612, 2614, 2615, 2617, 2618, 2620, 2622, 2623, 2625,
  2626, 2628, 2629, 2631, 2633, 2634, 2636, 2637, 2639, 2640, 2642, 2644, 2645,
  2647, 2648, 2650, 2651, 2653, 2655, 2656, 2658, 2659, 2661, 2662, 2664, 2666,
  2667, 2669, 2670, 2672, 2673, 2675, 2676, 2678, 2680, 2681, 2683, 2684, 2686,
  2687, 2689, 2691, 2692, 2694, 2695, 2697, 2698, 2700, 2702, 2703, 2705, 2706,
  2708, 2709, 2711, 2713, 2714, 2716, 2717, 2719, 2720, 2722, 2724, 2725, 2727,
  2728, 2730, 2731, 2733, 2735, 2736, 2738, 2739, 2741, 2742, 2744, 2746, 2747,
  2749, 2750, 2752, 2753, 2755, 2757, 2758, 2760, 2761, 2763, 2764, 2766, 2768,
  2769, 2771, 2772, 2774, 2775, 2777, 2779, 2780, 2782, 2783, 2785, 2786, 2788,
  2790, 2791, 2793, 2794, 2796, 2797, 2799, 2801, 2802, 2804, 2805, 2807, 2808,
  2810, 2811, 2813, 2815, 2816, 2818, 2819, 2821, 2822, 2824, 2826, 2827, 2829,
  2830, 2832, 2833, 2835, 2837, 2838, 2840, 2841, 2843, 2844, 2846, 2848, 2849,
  2851, 2852, 2854, 2855, 2857, 2859, 2860, 2862, 2863, 2865, 2866, 2868, 2870,
  2871, 2873, 2874, 2876, 2877, 2879, 2881, 2882, 2884, 2885, 2887, 2888, 2890,
  2892, 2893, 2895, 2896, 2898, 2899, 2901, 2903, 2904, 2906, 2907, 2909, 2910,
  2912, 2914, 2915, 2917, 2918, 2920, 2921, 2923, 2925, 2926, 2928, 2929, 2931,
  2932, 2934, 2936, 2937, 2939, 2940, 2942, 2943, 2945, 2946, 2948, 2950, 2951,
  2953, 2954, 2956, 2957, 2959, 2961, 2962, 2964, 2965, 2967, 2968, 2970, 2972,
  2973, 2975, 2976, 2978, 2979, 2981, 2983, 2984, 2986, 2987, 2989, 2990, 2992,
  2994, 2995, 2997, 2998, 3000, 3001, 3003, 3005, 3006, 3008, 3009, 3011, 3012,
  3014, 3016, 3017, 3019, 3020, 3022, 3023, 3025, 3027, 3028, 3030, 3031, 3033,
  3034, 3036, 3038, 3039, 3041, 3042, 3044, 3045, 3047, 3049, 3050, 3052, 3053,
  3055, 3056, 3058, 3060, 3061, 3063, 3064, 3066, 3067, 3069, 3071, 3072, 3074,
  3075, 3077, 3078, 3080, 3082, 3083, 3085, 3086, 3088, 3089, 3091, 3092, 3094,
  3096, 3097, 3099, 3100, 3102, 3103, 3105, 3107, 3108, 3110, 3111, 3113, 3114,
  3116, 3118, 3119, 3121, 3122, 3124, 3125, 3127, 3129, 3130, 3132, 3133, 3135,
  3136, 3138, 3140, 3141, 3143, 3144, 3146, 3147, 3149, 3151, 3152, 3154, 3155,
  3157, 3158, 3160, 3162, 3163, 3165, 3166, 3168, 3169, 3171, 3173, 3174, 3176,
  3177, 3179, 3180, 3182, 3184, 3185, 3187, 3188, 3190, 3191, 3193, 3195, 3196,
  3198, 3199, 3201, 3202, 3204, 3206, 3207, 3209, 3210, 3212, 3213, 3215, 3217,
  3218, 3220, 3221, 3223, 3224, 3226, 3227, 3229, 3231, 3232, 3234, 3235, 3237,
  3238, 3240, 3242, 3243, 3245, 3246, 3248, 3249, 3251, 3253, 3254, 3256, 3257,
  3259, 3260, 3262, 3264, 3265, 3267, 3268, 3270, 3271, 3273, 3275, 3276, 3278,
  3279, 3281, 3282, 3284, 3286, 3287, 3289, 3290, 3292, 3293, 3295, 3297, 3298,
  3300, 3301, 3303, 3304, 3306, 3308, 3309, 3311, 3312, 3314, 3315, 3317, 3319,
  3320, 3322, 3323, 3325, 3326, 3328, 3330, 3331, 3333, 3334, 3336, 3337, 3339,
  3341, 3342, 3344, 3345, 3347, 3348, 3350, 3352, 3353, 3355, 3356, 3358, 3359,
  3361, 3362, 3364, 3366, 3367, 3369, 3370, 3372, 3373, 3375, 3377, 3378, 3380,
  3381, 3383, 3384, 3386, 3388, 3389, 3391, 3392, 3394, 3395, 3397, 3399, 3400,
  3402, 3403, 3405, 3406, 3408, 3410, 3411, 3413, 3414, 3416, 3417, 3419, 3421,
  3422, 3424, 3425, 3427, 3428, 3430, 3432, 3433, 3435, 3436, 3438, 3439, 3441,
  3443, 3444, 3446, 3447, 3449, 3450, 3452, 3454, 3455, 3457, 3458, 3460, 3461,
  3463, 3465, 3466, 3468, 3469, 3471, 3472, 3474, 3476, 3477, 3479, 3480, 3482,
  3483, 3485, 3487, 3488, 3490, 3491, 3493, 3494, 3496, 3497, 3499, 3501, 3502,
  3504, 3505, 3507, 3508, 3510, 3512, 3513, 3515, 3516, 3518, 3519, 3521, 3523,
  3524, 3526, 3527, 3529, 3530, 3532, 3534, 3535, 3537, 3538, 3540, 3541, 3543,
  3545, 3546, 3548, 3549, 3551, 3552, 3554, 3556, 3557, 3559, 3560, 3562, 3563,
  3565, 3567, 3568, 3570, 3571, 3573, 3574, 3576, 3578, 3579, 3581, 3582, 3584,
  3585, 3587, 3589, 3590, 3592, 3593, 3595, 3596, 3598, 3600, 3601, 3603, 3604,
  3606, 3607, 3609, 3611, 3612, 3614, 3615, 3617, 3618, 3620, 3622, 3623, 3625,
  3626, 3628, 3629, 3631, 3632, 3634, 3636, 3637, 3639, 3640, 3642, 3643, 3645,
  3647, 3648, 3650, 3651, 3653, 3654, 3656, 3658, 3659, 3661, 3662, 3664, 3665,
  3667, 3669, 3670, 3672, 3673, 3675, 3676, 3678, 3680, 3681, 3683, 3684, 3686,
  3687, 3689, 3691, 3692, 3694, 3695, 3697, 3698, 3700, 3702, 3703, 3705, 3706,
  3708, 3709, 3711, 3713, 3714, 3716, 3717, 3719, 3720, 3722, 3724, 3725, 3727,
  3728, 3730, 3731, 3733, 3735, 3736, 3738, 3739, 3741, 3742, 3744, 3746, 3747,
  3749, 3750, 3752, 3753, 3755, 3757, 3758, 3760, 3761, 3763, 3764, 3766, 3768,
  3769, 3771, 3772, 3774, 3775, 3777, 3778, 3780, 3782, 3783, 3785, 3786, 3788,
  3789, 3791, 3793, 3794, 3796, 3797, 3799, 3800, 3802, 3804, 3805, 3807, 3808,
  3810, 3811, 3813, 3815, 3816, 3818, 3819, 3821, 3822, 3824, 3826, 3827, 3829,
  3830, 3832, 3833, 3835, 3837, 3838, 3840, 3841, 3843, 3844, 3846, 3848, 3849,
  3851, 3852, 3854, 3855, 3857, 3859, 3860, 3862, 3863, 3865, 3866, 3868, 3870,
  3871, 3873, 3874, 3876, 3877, 3879, 3881, 3882, 3884, 3885, 3887, 3888, 3890,
  3892, 3893, 3895, 3896, 3898, 3899, 3901, 3903, 3904, 3906, 3907, 3909, 3910,
  3912, 3913, 3915, 3917, 3918, 3920, 3921, 3923, 3924, 3926, 3928, 3929, 3931,
  3932, 3934, 3935, 3937, 3939, 3940, 3942, 3943, 3945, 3946, 3948, 3950, 3951,
  3953, 3954, 3956, 3957, 3959, 3961, 3962, 3964, 3965, 3967, 3968, 3970, 3972,
  3973, 3975, 3976, 3978, 3979, 3981, 3983, 3984, 3986, 3987, 3989, 3990, 3992,
  3994, 3995, 3997, 3998, 4000, 4001, 4003, 4005, 4006, 4008, 4009, 4011, 4012,
  4014, 4016, 4017, 4019, 4020, 4022, 4023, 4025, 4027, 4028, 4030, 4031, 4033,
  4034, 4036, 4038, 4039, 4041, 4042, 4044, 4045, 4047, 4048, 4050, 4052, 4053,
  4055, 4056, 4058, 4059, 4061, 4063, 4064, 4066, 4067, 4069, 4070, 4072, 4074,
  4075, 4077, 4078, 4080, 4081, 4083, 4085, 4086, 4088, 4089, 4091, 4092, 4094,
  4096, 4097, 4099, 4100, 4102, 4103, 4105, 4107, 4108, 4110, 4111, 4113, 4114,
  4116, 4118, 4119, 4121, 4122, 4124, 4125, 4127, 4129, 4130, 4132, 4133, 4135,
  4136, 4138, 4140, 4141, 4143, 4144, 4146, 4147, 4149, 4151, 4152, 4154, 4155,
  4157, 4158, 4160, 4162, 4163, 4165, 4166, 4168, 4169, 4171, 4173, 4174, 4176,
  4177, 4179, 4180, 4182, 4183, 4185, 4187, 4188, 4190, 4191, 4193, 4194, 4196,
  4198, 4199, 4201, 4202, 4204, 4205, 4207, 4209, 4210, 4212, 4213, 4215, 4216,
  4218, 4220, 4221, 4223, 4224, 4226, 4227, 4229, 4231, 4232, 4234, 4235, 4237,
  4238, 4240, 4242, 4243, 4245, 4246, 4248, 4249, 4251, 4253, 4254, 4256, 4257,
  4259, 4260, 4262, 4264, 4265, 4267, 4268, 4270, 4271, 4273, 4275, 4276, 4278,
  4279, 4281, 4282, 4284, 4286, 4287, 4289, 4290, 4292, 4293, 4295, 4297, 4298,
  4300, 4301, 4303, 4304, 4306, 4308, 4309, 4311, 4312, 4314, 4315, 4317, 4318,
  4320, 4322, 4323, 4325, 4326, 4328, 4329, 4331, 4333, 4334, 4336, 4337, 4339,
  4340, 4342, 4344, 4345, 4347, 4348, 4350, 4351, 4353, 4355, 4356, 4358, 4359,
  4361, 4362, 4364, 4366, 4367, 4369, 4370, 4372, 4373, 4375, 4377, 4378, 4380,
  4381, 4383, 4384, 4386, 4388, 4389, 4391, 4392, 4394, 4395, 4397, 4399, 4400,
  4402, 4403, 4405, 4406, 4408, 4410, 4411, 4413, 4414, 4416, 4417, 4419, 4421,
  4422, 4424, 4425, 4427, 4428, 4430, 4432, 4433, 4435, 4436, 4438, 4439, 4441,
  4443, 4444, 4446, 4447, 4449, 4450, 4452, 4453, 4455, 4457, 4458, 4460, 4461,
  4463, 4464, 4466, 4468, 4469, 4471, 4472, 4474, 4475, 4477, 4479, 4480, 4482,
  4483, 4485, 4486, 4488, 4490, 4491, 4493, 4494, 4496, 4497, 4499, 4501, 4502,
  4504, 4505, 4507, 4508, 4510, 4512, 4513, 4515, 4516, 4518, 4519, 4521, 4523,
  4524, 4526, 4527, 4529, 4530, 4532, 4534, 4535, 4537, 4538, 4540, 4541, 4543,
  4545, 4546, 4548, 4549, 4551, 4552, 4554, 4556, 4557, 4559, 4560, 4562, 4563,
  4565, 4567, 4568, 4570, 4571, 4573, 4574, 4576, 4578, 4579, 4581, 4582, 4584,
  4585, 4587, 4589, 4590, 4592, 4593, 4595, 4596, 4598, 4599, 4601, 4603, 4604,
  4606, 4607, 4609, 4610, 4612, 4614, 4615, 4617, 4618, 4620, 4621, 4623, 4625,
  4626, 4628, 4629, 4631, 4632, 4634, 4636, 4637, 4639, 4640, 4642, 4643, 4645,
  4647, 4648, 4650, 4651, 4653, 4654, 4656, 4658, 4659, 4661, 4662, 4664, 4665,
  4667, 4669, 4670, 4672, 4673, 4675, 4676, 4678, 4680, 4681, 4683, 4684, 4686,
  4687, 4689, 4691, 4692, 4694, 4695, 4697, 4698, 4700, 4702, 4703, 4705, 4706,
  4708, 4709, 4711, 4713, 4714, 4716, 4717, 4719, 4720, 4722, 4724, 4725, 4727,
  4728, 4730, 4731, 4733, 4734, 4736, 4738, 4739, 4741, 4742, 4744, 4745, 4747,
  4749, 4750, 4752, 4753, 4755, 4756, 4758, 4760, 4761, 4763, 4764, 4766, 4767,
  4769, 4771, 4772, 4774, 4775, 4777, 4778, 4780, 4782, 4783, 4785, 4786, 4788,
  4789, 4791, 4793, 4794, 4796, 4797, 4799, 4800, 4802, 4804, 4805, 4807, 4808,
  4810, 4811, 4813, 4815, 4816, 4818, 4819, 4821, 4822, 4824, 4826, 4827, 4829,
  4830, 4832, 4833, 4835, 4837, 4838, 4840, 4841, 4843, 4844, 4846, 4848, 4849,
  4851, 4852, 4854, 4855, 4857, 4859, 4860, 4862, 4863, 4865, 4866, 4868, 4869,
  4871, 4873, 4874, 4876, 4877, 4879, 4880, 4882, 4884, 4885, 4887, 4888, 4890,
  4891, 4893, 4895, 4896, 4898, 4899, 4901, 4902, 4904, 4906, 4907, 4909, 4910,
  4912, 4913, 4915, 4917, 4918, 4920, 4921, 4923, 4924, 4926, 4928, 4929, 4931,
  4932, 4934, 4935, 4937, 4939, 4940, 4942, 4943, 4945, 4946, 4948, 4950, 4951,
  4953, 4954, 4956, 4957, 4959, 4961, 4962, 4964, 4965, 4967, 4968, 4970, 4972,
  4973, 4975, 4976, 4978, 4979, 4981, 4983, 4984, 4986, 4987, 4989, 4990, 4992,
  4994, 4995, 4997, 4998, 5000, 5001, 5003, 5004, 5006, 5008, 5009, 5011, 5012,
  5014, 5015, 5017, 5019, 5020, 5022, 5023, 5025, 5026, 5028, 5030, 5031, 5033,
  5034, 5036, 5037, 5039, 5041, 5042, 5044, 5045, 5047, 5048, 5050, 5052, 5053,
  5055, 5056, 5058, 5059, 5061, 5063, 5064, 5066, 5067, 5069, 5070, 5072, 5074,
  5075, 5077, 5078, 5080, 5081, 5083, 5085, 5086, 5088, 5089, 5091, 5092, 5094,
  5096, 5097, 5099, 5100, 5102, 5103, 5105, 5107, 5108, 5110, 5111, 5113, 5114,
  5116, 5118, 5119, 5121, 5122, 5124, 5125, 5127, 5129, 5130, 5132, 5133, 5135,
  5136, 5138, 5139, 5141, 5143, 5144, 5146, 5147, 5149, 5150, 5152, 5154, 5155,
  5157, 5158, 5160, 5161, 5163, 5165, 5166, 5168, 5169, 5171, 5172, 5174, 5176,
  5177, 5179, 5180, 5182, 5183, 5185, 5187, 5188, 5190, 5191, 5193, 5194, 5196,
  5198, 5199, 5201, 5202, 5204, 5205, 5207, 5209, 5210, 5212, 5213, 5215, 5216,
  5218, 5220, 5221, 5223, 5224, 5226, 5227, 5229, 5231, 5232, 5234, 5235, 5237,
  5238, 5240, 5242, 5243, 5245, 5246, 5248, 5249, 5251, 5253, 5254, 5256, 5257,
  5259, 5260, 5262, 5264, 5265, 5267, 5268, 5270, 5271, 5273, 5275, 5276, 5278,
  5279, 5281, 5282, 5284, 5285, 5287, 5289, 5290, 5292, 5293, 5295, 5296, 5298,
  5300, 5301, 5303, 5304, 5306, 5307, 5309, 5311, 5312, 5314, 5315, 5317, 5318,
  5320, 5322, 5323, 5325, 5326, 5328, 5329, 5331, 5333, 5334, 5336, 5337, 5339,
  5340, 5342, 5344, 5345, 5347, 5348, 5350, 5351, 5353, 5355, 5356, 5358, 5359,
  5361, 5362, 5364, 5366, 5367, 5369, 5370, 5372, 5373, 5375, 5377, 5378, 5380,
  5381, 5383, 5384, 5386, 5388, 5389, 5391, 5392, 5394, 5395, 5397, 5399, 5400,
  5402, 5403, 5405, 5406, 5408, 5410, 5411, 5413, 5414, 5416, 5417, 5419, 5420,
  5422, 5424, 5425, 5427, 5428, 5430, 5431, 5433, 5435, 5436, 5438, 5439, 5441,
  5442, 5444, 5446, 5447, 5449, 5450, 5452, 5453, 5455, 5457, 5458, 5460, 5461,
  5463, 5464, 5466, 5468, 5469, 5471, 5472, 5474, 5475, 5477, 5479, 5480, 5482,
  5483, 5485, 5486, 5488, 5490, 5491, 5493, 5494, 5496, 5497, 5499, 5501, 5502,
  5504, 5505, 5507, 5508, 5510, 5512, 5513, 5515, 5516, 5518, 5519, 5521, 5523,
  5524, 5526, 5527, 5529, 5530, 5532, 5534, 5535, 5537, 5538, 5540, 5541, 5543,
  5545, 5546, 5548, 5549, 5551, 5552, 5554, 5555, 5557, 5559, 5560, 5562, 5563,
  5565, 5566, 5568, 5570, 5571, 5573, 5574, 5576, 5577, 5579, 5581, 5582, 5584,
  5585, 5587, 5588, 5590, 5592, 5593, 5595, 5596, 5598, 5599, 5601, 5603, 5604,
  5606, 5607, 5609, 5610, 5612, 5614, 5615, 5617, 5618, 5620, 5621, 5623, 5625,
  5626, 5628, 5629, 5631, 5632, 5634, 5636, 5637, 5639, 5640, 5642, 5643, 5645,
  5647, 5648, 5650, 5651, 5653, 5654, 5656, 5658, 5659, 5661, 5662, 5664, 5665,
  5667, 5669, 5670, 5672, 5673, 5675, 5676, 5678, 5680, 5681, 5683, 5684, 5686,
  5687, 5689, 5690, 5692, 5694, 5695, 5697, 5698, 5700, 5701, 5703, 5705, 5706,
  5708, 5709, 5711, 5712, 5714, 5716, 5717, 5719, 5720, 5722, 5723, 5725, 5727,
  5728, 5730, 5731, 5733, 5734, 5736, 5738, 5739, 5741, 5742, 5744, 5745, 5747,
  5749, 5750, 5752, 5753, 5755, 5756, 5758, 5760, 5761, 5763, 5764, 5766, 5767,
  5769, 5771, 5772, 5774, 5775, 5777, 5778, 5780, 5782, 5783, 5785, 5786, 5788,
  5789, 5791, 5793, 5794, 5796, 5797, 5799, 5800, 5802, 5804, 5805, 5807, 5808,
  5810, 5811, 5813, 5815, 5816, 5818, 5819, 5821, 5822, 5824, 5825, 5827, 5829,
  5830, 5832, 5833, 5835, 5836, 5838, 5840, 5841, 5843, 5844, 5846, 5847, 5849,
  5851, 5852, 5854, 5855, 5857, 5858, 5860, 5862, 5863, 5865, 5866, 5868, 5869,
  5871, 5873, 5874, 5876, 5877, 5879, 5880, 5882, 5884, 5885, 5887, 5888, 5890,
  5891, 5893, 5895, 5896, 5898, 5899, 5901, 5902, 5904, 5906, 5907, 5909, 5910,
  5912, 5913, 5915, 5917, 5918, 5920, 5921, 5923, 5924, 5926, 5928, 5929, 5931,
  5932, 5934, 5935, 5937, 5939, 5940, 5942, 5943, 5945, 5946, 5948, 5950, 5951,
  5953, 5954, 5956, 5957, 5959, 5961, 5962, 5964, 5965, 5967, 5968, 5970, 5971,
  5973, 5975, 5976, 5978, 5979, 5981, 5982, 5984, 5986, 5987, 5989, 5990, 5992,
  5993, 5995, 5997, 5998, 6000, 6001, 6003, 6004, 6006, 6008, 6009, 6011, 6012,
  6014, 6015, 6017, 6019, 6020, 6022, 6023, 6025, 6026, 6028, 6030, 6031, 6033,
  6034, 6036, 6037, 6039, 6041, 6042, 6044, 6045, 6047, 6048, 6050, 6052, 6053,
  6055, 6056, 6058, 6059, 6061, 6063, 6064, 6066, 6067, 6069, 6070, 6072, 6074,
  6075, 6077, 6078, 6080, 6081, 6083, 6085, 6086, 6088, 6089, 6091, 6092, 6094,
  6096, 6097, 6099, 6100, 6102, 6103, 6105, 6106, 6108, 6110, 6111, 6113, 6114,
  6116, 6117, 6119, 6121, 6122, 6124, 6125, 6127, 6128, 6130, 6132, 6133, 6135,
  6136, 6138, 6139, 6141, 6143, 6144, 6146, 6147, 6149, 6150, 6152, 6154, 6155,
  6157, 6158, 6160, 6161, 6163, 6165, 6166, 6168, 6169, 6171, 6172, 6174, 6176,
  6177, 6179, 6180, 6182, 6183, 6185, 6187, 6188, 6190, 6191, 6193, 6194, 6196,
  6198, 6199, 6201, 6202, 6204, 6205, 6207, 6209, 6210, 6212, 6213, 6215, 6216,
  6218, 6220, 6221, 6223, 6224, 6226, 6227, 6229, 6231, 6232, 6234, 6235, 6237,
  6238, 6240, 6241, 6243, 6245, 6246, 6248, 6249, 6251, 6252, 6254, 6256, 6257,
  6259, 6260, 6262, 6263, 6265, 6267, 6268, 6270, 6271, 6273, 6274, 6276, 6278,
  6279, 6281, 6282, 6284, 6285, 6287, 6289, 6290, 6292, 6293, 6295, 6296, 6298,
  6300, 6301, 6303, 6304, 6306, 6307, 6309, 6311, 6312, 6314, 6315, 6317, 6318,
  6320, 6322, 6323, 6325, 6326, 6328, 6329, 6331, 6333, 6334, 6336, 6337, 6339,
  6340, 6342, 6344, 6345, 6347, 6348, 6350, 6351, 6353, 6355, 6356, 6358, 6359,
  6361, 6362, 6364, 6366, 6367, 6369, 6370, 6372, 6373, 6375, 6376, 6378, 6380,
  6381, 6383, 6384, 6386, 6387, 6389, 6391, 6392, 6394, 6395, 6397, 6398, 6400,
  6402, 6403, 6405, 6406, 6408, 6409, 6411, 6413, 6414, 6416, 6417, 6419, 6420,
  6422, 6424, 6425, 6427, 6428 } ;
                         /* Referenced by: '<Root>/Direct Lookup Table (n-D)' */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
