/*
 * File: ConstParams.c
 *
 * Code generated for Simulink model 'MotorControlLibNEWFixedP_FULL19b'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Mon Jan 18 11:43:29 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtwtypes.h"
#include "MotorControlLibNEWFixedP_FULL19b_types.h"

/* Exported data definition */

/* Const memory section */
/* Definition for custom storage class: Const */
const int16_T ADC_RES = 16384;

/* fixdt(1,16,2^-2,0) */ //-10.39 | 10.39
const int16_T BrkPoints[3] = { -2660, 0, 2660 } ;

/* fixdt(1,16,2^-8,0) */
const int16_T ComparatorBrkPnt[3] = { 0, 6758, 13517  } ;

/* fixdt(1,16,2^-4,0) */
const int8_T DRV_GAIN = 20;

/* fixdt(1,8,2^-1,0) */
const int16_T DRV_SHUNTR_OHM = 229; //7 mOhm  33; //1 mOhm

/* fixdt(1,16,2^-15,0) */
const int8_T DRV_V_REF = 106;

/* fixdt(1,8,2^-5,0) */
const int32_T EMFobsLdGain = 42;
const int32_T  Ld = 42;

/* fixdt(1,32,2^-22,0) */
const int16_T EMFobsRS = 179;
const int32_T  Rs = 2933;

/* fixdt(1,16,2^-8,0) */
const int8_T MaxBckEMFVol_sat_neg = -24;

/* fixdt(1,8,2^-1,0) */
const int8_T MaxBckEMFVol_sat_pos = 24;

/* fixdt(1,8,2^-1,0) */
const int16_T TqToIqConst = 11378;

/* fixdt(1,16,2^-8,0) */
const int16_T VoltageOut[3] = { 2458, 0, -2458  } ;

/* fixdt(1,16,2^-10,0) */
const int8_T dSoll = 0;

/* int8 */
const int16_T d_q_Voltage_Limiter_sat_neg = -166;

/* fixdt(1,16,2^-4,0) */
const int16_T d_q_Voltage_Limiter_sat_pos = 166;

/* fixdt(1,16,2^-4,0) */
const int16_T RShunt_table_data_out[4097] = { 2458, 2456, 2455, 2454, 2453, 2452,
  2450, 2449, 2448, 2447, 2446, 2444, 2443, 2442, 2441, 2440, 2438, 2437, 2436,
  2435, 2434, 2432, 2431, 2430, 2429, 2428, 2426, 2425, 2424, 2423, 2422, 2420,
  2419, 2418, 2417, 2416, 2414, 2413, 2412, 2411, 2410, 2408, 2407, 2406, 2405,
  2404, 2402, 2401, 2400, 2399, 2398, 2396, 2395, 2394, 2393, 2392, 2390, 2389,
  2388, 2387, 2386, 2384, 2383, 2382, 2381, 2380, 2378, 2377, 2376, 2375, 2374,
  2372, 2371, 2370, 2369, 2368, 2366, 2365, 2364, 2363, 2362, 2360, 2359, 2358,
  2357, 2356, 2354, 2353, 2352, 2351, 2350, 2348, 2347, 2346, 2345, 2344, 2342,
  2341, 2340, 2339, 2338, 2336, 2335, 2334, 2333, 2332, 2330, 2329, 2328, 2327,
  2326, 2324, 2323, 2322, 2321, 2320, 2318, 2317, 2316, 2315, 2314, 2312, 2311,
  2310, 2309, 2308, 2306, 2305, 2304, 2303, 2302, 2300, 2299, 2298, 2297, 2296,
  2294, 2293, 2292, 2291, 2290, 2288, 2287, 2286, 2285, 2284, 2282, 2281, 2280,
  2279, 2278, 2276, 2275, 2274, 2273, 2272, 2270, 2269, 2268, 2267, 2266, 2264,
  2263, 2262, 2261, 2260, 2258, 2257, 2256, 2255, 2254, 2252, 2251, 2250, 2249,
  2248, 2246, 2245, 2244, 2243, 2242, 2240, 2239, 2238, 2237, 2236, 2234, 2233,
  2232, 2231, 2230, 2228, 2227, 2226, 2225, 2224, 2222, 2221, 2220, 2219, 2218,
  2216, 2215, 2214, 2213, 2212, 2210, 2209, 2208, 2207, 2206, 2204, 2203, 2202,
  2201, 2200, 2198, 2197, 2196, 2195, 2194, 2192, 2191, 2190, 2189, 2188, 2186,
  2185, 2184, 2183, 2182, 2180, 2179, 2178, 2177, 2176, 2174, 2173, 2172, 2171,
  2170, 2168, 2167, 2166, 2165, 2164, 2162, 2161, 2160, 2159, 2158, 2156, 2155,
  2154, 2153, 2152, 2150, 2149, 2148, 2147, 2146, 2144, 2143, 2142, 2141, 2140,
  2138, 2137, 2136, 2135, 2134, 2132, 2131, 2130, 2129, 2128, 2126, 2125, 2124,
  2123, 2122, 2120, 2119, 2118, 2117, 2116, 2114, 2113, 2112, 2111, 2110, 2108,
  2107, 2106, 2105, 2104, 2102, 2101, 2100, 2099, 2098, 2096, 2095, 2094, 2093,
  2092, 2090, 2089, 2088, 2087, 2086, 2084, 2083, 2082, 2081, 2080, 2078, 2077,
  2076, 2075, 2074, 2072, 2071, 2070, 2069, 2068, 2066, 2065, 2064, 2063, 2062,
  2060, 2059, 2058, 2057, 2056, 2054, 2053, 2052, 2051, 2050, 2048, 2047, 2046,
  2045, 2044, 2042, 2041, 2040, 2039, 2038, 2036, 2035, 2034, 2033, 2032, 2030,
  2029, 2028, 2027, 2026, 2024, 2023, 2022, 2021, 2020, 2018, 2017, 2016, 2015,
  2014, 2012, 2011, 2010, 2009, 2008, 2006, 2005, 2004, 2003, 2002, 2000, 1999,
  1998, 1997, 1996, 1994, 1993, 1992, 1991, 1990, 1988, 1987, 1986, 1985, 1984,
  1982, 1981, 1980, 1979, 1978, 1976, 1975, 1974, 1973, 1972, 1970, 1969, 1968,
  1967, 1966, 1964, 1963, 1962, 1961, 1960, 1958, 1957, 1956, 1955, 1954, 1952,
  1951, 1950, 1949, 1948, 1946, 1945, 1944, 1943, 1942, 1940, 1939, 1938, 1937,
  1936, 1934, 1933, 1932, 1931, 1930, 1928, 1927, 1926, 1925, 1924, 1922, 1921,
  1920, 1919, 1918, 1916, 1915, 1914, 1913, 1912, 1910, 1909, 1908, 1907, 1906,
  1904, 1903, 1902, 1901, 1900, 1898, 1897, 1896, 1895, 1894, 1892, 1891, 1890,
  1889, 1888, 1886, 1885, 1884, 1883, 1882, 1880, 1879, 1878, 1877, 1876, 1874,
  1873, 1872, 1871, 1870, 1868, 1867, 1866, 1865, 1864, 1862, 1861, 1860, 1859,
  1858, 1856, 1855, 1854, 1853, 1852, 1850, 1849, 1848, 1847, 1846, 1844, 1843,
  1842, 1841, 1840, 1838, 1837, 1836, 1835, 1834, 1832, 1831, 1830, 1829, 1828,
  1826, 1825, 1824, 1823, 1822, 1820, 1819, 1818, 1817, 1816, 1814, 1813, 1812,
  1811, 1810, 1808, 1807, 1806, 1805, 1804, 1802, 1801, 1800, 1799, 1798, 1796,
  1795, 1794, 1793, 1792, 1790, 1789, 1788, 1787, 1786, 1784, 1783, 1782, 1781,
  1780, 1778, 1777, 1776, 1775, 1774, 1772, 1771, 1770, 1769, 1768, 1766, 1765,
  1764, 1763, 1762, 1760, 1759, 1758, 1757, 1756, 1754, 1753, 1752, 1751, 1750,
  1748, 1747, 1746, 1745, 1744, 1742, 1741, 1740, 1739, 1738, 1736, 1735, 1734,
  1733, 1732, 1730, 1729, 1728, 1727, 1726, 1724, 1723, 1722, 1721, 1720, 1718,
  1717, 1716, 1715, 1714, 1712, 1711, 1710, 1709, 1708, 1706, 1705, 1704, 1703,
  1702, 1700, 1699, 1698, 1697, 1696, 1694, 1693, 1692, 1691, 1690, 1688, 1687,
  1686, 1685, 1684, 1682, 1681, 1680, 1679, 1678, 1676, 1675, 1674, 1673, 1672,
  1670, 1669, 1668, 1667, 1666, 1664, 1663, 1662, 1661, 1660, 1658, 1657, 1656,
  1655, 1654, 1652, 1651, 1650, 1649, 1648, 1646, 1645, 1644, 1643, 1642, 1640,
  1639, 1638, 1637, 1636, 1634, 1633, 1632, 1631, 1630, 1628, 1627, 1626, 1625,
  1624, 1622, 1621, 1620, 1619, 1618, 1616, 1615, 1614, 1613, 1612, 1610, 1609,
  1608, 1607, 1606, 1604, 1603, 1602, 1601, 1600, 1598, 1597, 1596, 1595, 1594,
  1592, 1591, 1590, 1589, 1588, 1586, 1585, 1584, 1583, 1582, 1580, 1579, 1578,
  1577, 1576, 1574, 1573, 1572, 1571, 1570, 1568, 1567, 1566, 1565, 1564, 1562,
  1561, 1560, 1559, 1558, 1556, 1555, 1554, 1553, 1552, 1550, 1549, 1548, 1547,
  1546, 1544, 1543, 1542, 1541, 1540, 1538, 1537, 1536, 1535, 1534, 1532, 1531,
  1530, 1529, 1528, 1526, 1525, 1524, 1523, 1522, 1520, 1519, 1518, 1517, 1516,
  1514, 1513, 1512, 1511, 1510, 1508, 1507, 1506, 1505, 1504, 1502, 1501, 1500,
  1499, 1498, 1496, 1495, 1494, 1493, 1492, 1490, 1489, 1488, 1487, 1486, 1484,
  1483, 1482, 1481, 1480, 1478, 1477, 1476, 1475, 1474, 1472, 1471, 1470, 1469,
  1468, 1466, 1465, 1464, 1463, 1462, 1460, 1459, 1458, 1457, 1456, 1454, 1453,
  1452, 1451, 1450, 1448, 1447, 1446, 1445, 1444, 1442, 1441, 1440, 1439, 1438,
  1436, 1435, 1434, 1433, 1432, 1430, 1429, 1428, 1427, 1426, 1424, 1423, 1422,
  1421, 1420, 1418, 1417, 1416, 1415, 1414, 1412, 1411, 1410, 1409, 1408, 1406,
  1405, 1404, 1403, 1402, 1400, 1399, 1398, 1397, 1396, 1394, 1393, 1392, 1391,
  1390, 1388, 1387, 1386, 1385, 1384, 1382, 1381, 1380, 1379, 1378, 1376, 1375,
  1374, 1373, 1372, 1370, 1369, 1368, 1367, 1366, 1364, 1363, 1362, 1361, 1360,
  1358, 1357, 1356, 1355, 1354, 1352, 1351, 1350, 1349, 1348, 1346, 1345, 1344,
  1343, 1342, 1340, 1339, 1338, 1337, 1336, 1334, 1333, 1332, 1331, 1330, 1328,
  1327, 1326, 1325, 1324, 1322, 1321, 1320, 1319, 1318, 1316, 1315, 1314, 1313,
  1312, 1310, 1309, 1308, 1307, 1306, 1304, 1303, 1302, 1301, 1300, 1298, 1297,
  1296, 1295, 1294, 1292, 1291, 1290, 1289, 1288, 1286, 1285, 1284, 1283, 1282,
  1280, 1279, 1278, 1277, 1276, 1274, 1273, 1272, 1271, 1270, 1268, 1267, 1266,
  1265, 1264, 1262, 1261, 1260, 1259, 1258, 1256, 1255, 1254, 1253, 1252, 1250,
  1249, 1248, 1247, 1246, 1244, 1243, 1242, 1241, 1240, 1238, 1237, 1236, 1235,
  1234, 1232, 1231, 1230, 1229, 1228, 1226, 1225, 1224, 1223, 1222, 1220, 1219,
  1218, 1217, 1216, 1214, 1213, 1212, 1211, 1210, 1208, 1207, 1206, 1205, 1204,
  1202, 1201, 1200, 1199, 1198, 1196, 1195, 1194, 1193, 1192, 1190, 1189, 1188,
  1187, 1186, 1184, 1183, 1182, 1181, 1180, 1178, 1177, 1176, 1175, 1174, 1172,
  1171, 1170, 1169, 1168, 1166, 1165, 1164, 1163, 1162, 1160, 1159, 1158, 1157,
  1156, 1154, 1153, 1152, 1151, 1150, 1148, 1147, 1146, 1145, 1144, 1142, 1141,
  1140, 1139, 1138, 1136, 1135, 1134, 1133, 1132, 1130, 1129, 1128, 1127, 1126,
  1124, 1123, 1122, 1121, 1120, 1118, 1117, 1116, 1115, 1114, 1112, 1111, 1110,
  1109, 1108, 1106, 1105, 1104, 1103, 1102, 1100, 1099, 1098, 1097, 1096, 1094,
  1093, 1092, 1091, 1090, 1088, 1087, 1086, 1085, 1084, 1082, 1081, 1080, 1079,
  1078, 1076, 1075, 1074, 1073, 1072, 1070, 1069, 1068, 1067, 1066, 1064, 1063,
  1062, 1061, 1060, 1058, 1057, 1056, 1055, 1054, 1052, 1051, 1050, 1049, 1048,
  1046, 1045, 1044, 1043, 1042, 1040, 1039, 1038, 1037, 1036, 1034, 1033, 1032,
  1031, 1030, 1028, 1027, 1026, 1025, 1024, 1022, 1021, 1020, 1019, 1018, 1016,
  1015, 1014, 1013, 1012, 1010, 1009, 1008, 1007, 1006, 1004, 1003, 1002, 1001,
  1000, 998, 997, 996, 995, 994, 992, 991, 990, 989, 988, 986, 985, 984, 983,
  982, 980, 979, 978, 977, 976, 974, 973, 972, 971, 970, 968, 967, 966, 965, 964,
  962, 961, 960, 959, 958, 956, 955, 954, 953, 952, 950, 949, 948, 947, 946, 944,
  943, 942, 941, 940, 938, 937, 936, 935, 934, 932, 931, 930, 929, 928, 926, 925,
  924, 923, 922, 920, 919, 918, 917, 916, 914, 913, 912, 911, 910, 908, 907, 906,
  905, 904, 902, 901, 900, 899, 898, 896, 895, 894, 893, 892, 890, 889, 888, 887,
  886, 884, 883, 882, 881, 880, 878, 877, 876, 875, 874, 872, 871, 870, 869, 868,
  866, 865, 864, 863, 862, 860, 859, 858, 857, 856, 854, 853, 852, 851, 850, 848,
  847, 846, 845, 844, 842, 841, 840, 839, 838, 836, 835, 834, 833, 832, 830, 829,
  828, 827, 826, 824, 823, 822, 821, 820, 818, 817, 816, 815, 814, 812, 811, 810,
  809, 808, 806, 805, 804, 803, 802, 800, 799, 798, 797, 796, 794, 793, 792, 791,
  790, 788, 787, 786, 785, 784, 782, 781, 780, 779, 778, 776, 775, 774, 773, 772,
  770, 769, 768, 767, 766, 764, 763, 762, 761, 760, 758, 757, 756, 755, 754, 752,
  751, 750, 749, 748, 746, 745, 744, 743, 742, 740, 739, 738, 737, 736, 734, 733,
  732, 731, 730, 728, 727, 726, 725, 724, 722, 721, 720, 719, 718, 716, 715, 714,
  713, 712, 710, 709, 708, 707, 706, 704, 703, 702, 701, 700, 698, 697, 696, 695,
  694, 692, 691, 690, 689, 688, 686, 685, 684, 683, 682, 680, 679, 678, 677, 676,
  674, 673, 672, 671, 670, 668, 667, 666, 665, 664, 662, 661, 660, 659, 658, 656,
  655, 654, 653, 652, 650, 649, 648, 647, 646, 644, 643, 642, 641, 640, 638, 637,
  636, 635, 634, 632, 631, 630, 629, 628, 626, 625, 624, 623, 622, 620, 619, 618,
  617, 616, 614, 613, 612, 611, 610, 608, 607, 606, 605, 604, 602, 601, 600, 599,
  598, 596, 595, 594, 593, 592, 590, 589, 588, 587, 586, 584, 583, 582, 581, 580,
  578, 577, 576, 575, 574, 572, 571, 570, 569, 568, 566, 565, 564, 563, 562, 560,
  559, 558, 557, 556, 554, 553, 552, 551, 550, 548, 547, 546, 545, 544, 542, 541,
  540, 539, 538, 536, 535, 534, 533, 532, 530, 529, 528, 527, 526, 524, 523, 522,
  521, 520, 518, 517, 516, 515, 514, 512, 511, 510, 509, 508, 506, 505, 504, 503,
  502, 500, 499, 498, 497, 496, 494, 493, 492, 491, 490, 488, 487, 486, 485, 484,
  482, 481, 480, 479, 478, 476, 475, 474, 473, 472, 470, 469, 468, 467, 466, 464,
  463, 462, 461, 460, 458, 457, 456, 455, 454, 452, 451, 450, 449, 448, 446, 445,
  444, 443, 442, 440, 439, 438, 437, 436, 434, 433, 432, 431, 430, 428, 427, 426,
  425, 424, 422, 421, 420, 419, 418, 416, 415, 414, 413, 412, 410, 409, 408, 407,
  406, 404, 403, 402, 401, 400, 398, 397, 396, 395, 394, 392, 391, 390, 389, 388,
  386, 385, 384, 383, 382, 380, 379, 378, 377, 376, 374, 373, 372, 371, 370, 368,
  367, 366, 365, 364, 362, 361, 360, 359, 358, 356, 355, 354, 353, 352, 350, 349,
  348, 347, 346, 344, 343, 342, 341, 340, 338, 337, 336, 335, 334, 332, 331, 330,
  329, 328, 326, 325, 324, 323, 322, 320, 319, 318, 317, 316, 314, 313, 312, 311,
  310, 308, 307, 306, 305, 304, 302, 301, 300, 299, 298, 296, 295, 294, 293, 292,
  290, 289, 288, 287, 286, 284, 283, 282, 281, 280, 278, 277, 276, 275, 274, 272,
  271, 270, 269, 268, 266, 265, 264, 263, 262, 260, 259, 258, 257, 256, 254, 253,
  252, 251, 250, 248, 247, 246, 245, 244, 242, 241, 240, 239, 238, 236, 235, 234,
  233, 232, 230, 229, 228, 227, 226, 224, 223, 222, 221, 220, 218, 217, 216, 215,
  214, 212, 211, 210, 209, 208, 206, 205, 204, 203, 202, 200, 199, 198, 197, 196,
  194, 193, 192, 191, 190, 188, 187, 186, 185, 184, 182, 181, 180, 179, 178, 176,
  175, 174, 173, 172, 170, 169, 168, 167, 166, 164, 163, 162, 161, 160, 158, 157,
  156, 155, 154, 152, 151, 150, 149, 148, 146, 145, 144, 143, 142, 140, 139, 138,
  137, 136, 134, 133, 132, 131, 130, 128, 127, 126, 125, 124, 122, 121, 120, 119,
  118, 116, 115, 114, 113, 112, 110, 109, 108, 107, 106, 104, 103, 102, 101, 100,
  98, 97, 96, 95, 94, 92, 91, 90, 89, 88, 86, 85, 84, 83, 82, 80, 79, 78, 77, 76,
  74, 73, 72, 71, 70, 68, 67, 66, 65, 64, 62, 61, 60, 59, 58, 56, 55, 54, 53, 52,
  50, 49, 48, 47, 46, 44, 43, 42, 41, 40, 38, 37, 36, 35, 34, 32, 31, 30, 29, 28,
  26, 25, 24, 23, 22, 20, 19, 18, 17, 16, 14, 13, 12, 11, 10, 8, 7, 6, 5, 4, 2,
  1, 0, -1, -2, -4, -5, -6, -7, -8, -10, -11, -12, -13, -14, -16, -17, -18, -19,
  -20, -22, -23, -24, -25, -26, -28, -29, -30, -31, -32, -34, -35, -36, -37, -38,
  -40, -41, -42, -43, -44, -46, -47, -48, -49, -50, -52, -53, -54, -55, -56, -58,
  -59, -60, -61, -62, -64, -65, -66, -67, -68, -70, -71, -72, -73, -74, -76, -77,
  -78, -79, -80, -82, -83, -84, -85, -86, -88, -89, -90, -91, -92, -94, -95, -96,
  -97, -98, -100, -101, -102, -103, -104, -106, -107, -108, -109, -110, -112,
  -113, -114, -115, -116, -118, -119, -120, -121, -122, -124, -125, -126, -127,
  -128, -130, -131, -132, -133, -134, -136, -137, -138, -139, -140, -142, -143,
  -144, -145, -146, -148, -149, -150, -151, -152, -154, -155, -156, -157, -158,
  -160, -161, -162, -163, -164, -166, -167, -168, -169, -170, -172, -173, -174,
  -175, -176, -178, -179, -180, -181, -182, -184, -185, -186, -187, -188, -190,
  -191, -192, -193, -194, -196, -197, -198, -199, -200, -202, -203, -204, -205,
  -206, -208, -209, -210, -211, -212, -214, -215, -216, -217, -218, -220, -221,
  -222, -223, -224, -226, -227, -228, -229, -230, -232, -233, -234, -235, -236,
  -238, -239, -240, -241, -242, -244, -245, -246, -247, -248, -250, -251, -252,
  -253, -254, -256, -257, -258, -259, -260, -262, -263, -264, -265, -266, -268,
  -269, -270, -271, -272, -274, -275, -276, -277, -278, -280, -281, -282, -283,
  -284, -286, -287, -288, -289, -290, -292, -293, -294, -295, -296, -298, -299,
  -300, -301, -302, -304, -305, -306, -307, -308, -310, -311, -312, -313, -314,
  -316, -317, -318, -319, -320, -322, -323, -324, -325, -326, -328, -329, -330,
  -331, -332, -334, -335, -336, -337, -338, -340, -341, -342, -343, -344, -346,
  -347, -348, -349, -350, -352, -353, -354, -355, -356, -358, -359, -360, -361,
  -362, -364, -365, -366, -367, -368, -370, -371, -372, -373, -374, -376, -377,
  -378, -379, -380, -382, -383, -384, -385, -386, -388, -389, -390, -391, -392,
  -394, -395, -396, -397, -398, -400, -401, -402, -403, -404, -406, -407, -408,
  -409, -410, -412, -413, -414, -415, -416, -418, -419, -420, -421, -422, -424,
  -425, -426, -427, -428, -430, -431, -432, -433, -434, -436, -437, -438, -439,
  -440, -442, -443, -444, -445, -446, -448, -449, -450, -451, -452, -454, -455,
  -456, -457, -458, -460, -461, -462, -463, -464, -466, -467, -468, -469, -470,
  -472, -473, -474, -475, -476, -478, -479, -480, -481, -482, -484, -485, -486,
  -487, -488, -490, -491, -492, -493, -494, -496, -497, -498, -499, -500, -502,
  -503, -504, -505, -506, -508, -509, -510, -511, -512, -514, -515, -516, -517,
  -518, -520, -521, -522, -523, -524, -526, -527, -528, -529, -530, -532, -533,
  -534, -535, -536, -538, -539, -540, -541, -542, -544, -545, -546, -547, -548,
  -550, -551, -552, -553, -554, -556, -557, -558, -559, -560, -562, -563, -564,
  -565, -566, -568, -569, -570, -571, -572, -574, -575, -576, -577, -578, -580,
  -581, -582, -583, -584, -586, -587, -588, -589, -590, -592, -593, -594, -595,
  -596, -598, -599, -600, -601, -602, -604, -605, -606, -607, -608, -610, -611,
  -612, -613, -614, -616, -617, -618, -619, -620, -622, -623, -624, -625, -626,
  -628, -629, -630, -631, -632, -634, -635, -636, -637, -638, -640, -641, -642,
  -643, -644, -646, -647, -648, -649, -650, -652, -653, -654, -655, -656, -658,
  -659, -660, -661, -662, -664, -665, -666, -667, -668, -670, -671, -672, -673,
  -674, -676, -677, -678, -679, -680, -682, -683, -684, -685, -686, -688, -689,
  -690, -691, -692, -694, -695, -696, -697, -698, -700, -701, -702, -703, -704,
  -706, -707, -708, -709, -710, -712, -713, -714, -715, -716, -718, -719, -720,
  -721, -722, -724, -725, -726, -727, -728, -730, -731, -732, -733, -734, -736,
  -737, -738, -739, -740, -742, -743, -744, -745, -746, -748, -749, -750, -751,
  -752, -754, -755, -756, -757, -758, -760, -761, -762, -763, -764, -766, -767,
  -768, -769, -770, -772, -773, -774, -775, -776, -778, -779, -780, -781, -782,
  -784, -785, -786, -787, -788, -790, -791, -792, -793, -794, -796, -797, -798,
  -799, -800, -802, -803, -804, -805, -806, -808, -809, -810, -811, -812, -814,
  -815, -816, -817, -818, -820, -821, -822, -823, -824, -826, -827, -828, -829,
  -830, -832, -833, -834, -835, -836, -838, -839, -840, -841, -842, -844, -845,
  -846, -847, -848, -850, -851, -852, -853, -854, -856, -857, -858, -859, -860,
  -862, -863, -864, -865, -866, -868, -869, -870, -871, -872, -874, -875, -876,
  -877, -878, -880, -881, -882, -883, -884, -886, -887, -888, -889, -890, -892,
  -893, -894, -895, -896, -898, -899, -900, -901, -902, -904, -905, -906, -907,
  -908, -910, -911, -912, -913, -914, -916, -917, -918, -919, -920, -922, -923,
  -924, -925, -926, -928, -929, -930, -931, -932, -934, -935, -936, -937, -938,
  -940, -941, -942, -943, -944, -946, -947, -948, -949, -950, -952, -953, -954,
  -955, -956, -958, -959, -960, -961, -962, -964, -965, -966, -967, -968, -970,
  -971, -972, -973, -974, -976, -977, -978, -979, -980, -982, -983, -984, -985,
  -986, -988, -989, -990, -991, -992, -994, -995, -996, -997, -998, -1000, -1001,
  -1002, -1003, -1004, -1006, -1007, -1008, -1009, -1010, -1012, -1013, -1014,
  -1015, -1016, -1018, -1019, -1020, -1021, -1022, -1024, -1025, -1026, -1027,
  -1028, -1030, -1031, -1032, -1033, -1034, -1036, -1037, -1038, -1039, -1040,
  -1042, -1043, -1044, -1045, -1046, -1048, -1049, -1050, -1051, -1052, -1054,
  -1055, -1056, -1057, -1058, -1060, -1061, -1062, -1063, -1064, -1066, -1067,
  -1068, -1069, -1070, -1072, -1073, -1074, -1075, -1076, -1078, -1079, -1080,
  -1081, -1082, -1084, -1085, -1086, -1087, -1088, -1090, -1091, -1092, -1093,
  -1094, -1096, -1097, -1098, -1099, -1100, -1102, -1103, -1104, -1105, -1106,
  -1108, -1109, -1110, -1111, -1112, -1114, -1115, -1116, -1117, -1118, -1120,
  -1121, -1122, -1123, -1124, -1126, -1127, -1128, -1129, -1130, -1132, -1133,
  -1134, -1135, -1136, -1138, -1139, -1140, -1141, -1142, -1144, -1145, -1146,
  -1147, -1148, -1150, -1151, -1152, -1153, -1154, -1156, -1157, -1158, -1159,
  -1160, -1162, -1163, -1164, -1165, -1166, -1168, -1169, -1170, -1171, -1172,
  -1174, -1175, -1176, -1177, -1178, -1180, -1181, -1182, -1183, -1184, -1186,
  -1187, -1188, -1189, -1190, -1192, -1193, -1194, -1195, -1196, -1198, -1199,
  -1200, -1201, -1202, -1204, -1205, -1206, -1207, -1208, -1210, -1211, -1212,
  -1213, -1214, -1216, -1217, -1218, -1219, -1220, -1222, -1223, -1224, -1225,
  -1226, -1228, -1229, -1230, -1231, -1232, -1234, -1235, -1236, -1237, -1238,
  -1240, -1241, -1242, -1243, -1244, -1246, -1247, -1248, -1249, -1250, -1252,
  -1253, -1254, -1255, -1256, -1258, -1259, -1260, -1261, -1262, -1264, -1265,
  -1266, -1267, -1268, -1270, -1271, -1272, -1273, -1274, -1276, -1277, -1278,
  -1279, -1280, -1282, -1283, -1284, -1285, -1286, -1288, -1289, -1290, -1291,
  -1292, -1294, -1295, -1296, -1297, -1298, -1300, -1301, -1302, -1303, -1304,
  -1306, -1307, -1308, -1309, -1310, -1312, -1313, -1314, -1315, -1316, -1318,
  -1319, -1320, -1321, -1322, -1324, -1325, -1326, -1327, -1328, -1330, -1331,
  -1332, -1333, -1334, -1336, -1337, -1338, -1339, -1340, -1342, -1343, -1344,
  -1345, -1346, -1348, -1349, -1350, -1351, -1352, -1354, -1355, -1356, -1357,
  -1358, -1360, -1361, -1362, -1363, -1364, -1366, -1367, -1368, -1369, -1370,
  -1372, -1373, -1374, -1375, -1376, -1378, -1379, -1380, -1381, -1382, -1384,
  -1385, -1386, -1387, -1388, -1390, -1391, -1392, -1393, -1394, -1396, -1397,
  -1398, -1399, -1400, -1402, -1403, -1404, -1405, -1406, -1408, -1409, -1410,
  -1411, -1412, -1414, -1415, -1416, -1417, -1418, -1420, -1421, -1422, -1423,
  -1424, -1426, -1427, -1428, -1429, -1430, -1432, -1433, -1434, -1435, -1436,
  -1438, -1439, -1440, -1441, -1442, -1444, -1445, -1446, -1447, -1448, -1450,
  -1451, -1452, -1453, -1454, -1456, -1457, -1458, -1459, -1460, -1462, -1463,
  -1464, -1465, -1466, -1468, -1469, -1470, -1471, -1472, -1474, -1475, -1476,
  -1477, -1478, -1480, -1481, -1482, -1483, -1484, -1486, -1487, -1488, -1489,
  -1490, -1492, -1493, -1494, -1495, -1496, -1498, -1499, -1500, -1501, -1502,
  -1504, -1505, -1506, -1507, -1508, -1510, -1511, -1512, -1513, -1514, -1516,
  -1517, -1518, -1519, -1520, -1522, -1523, -1524, -1525, -1526, -1528, -1529,
  -1530, -1531, -1532, -1534, -1535, -1536, -1537, -1538, -1540, -1541, -1542,
  -1543, -1544, -1546, -1547, -1548, -1549, -1550, -1552, -1553, -1554, -1555,
  -1556, -1558, -1559, -1560, -1561, -1562, -1564, -1565, -1566, -1567, -1568,
  -1570, -1571, -1572, -1573, -1574, -1576, -1577, -1578, -1579, -1580, -1582,
  -1583, -1584, -1585, -1586, -1588, -1589, -1590, -1591, -1592, -1594, -1595,
  -1596, -1597, -1598, -1600, -1601, -1602, -1603, -1604, -1606, -1607, -1608,
  -1609, -1610, -1612, -1613, -1614, -1615, -1616, -1618, -1619, -1620, -1621,
  -1622, -1624, -1625, -1626, -1627, -1628, -1630, -1631, -1632, -1633, -1634,
  -1636, -1637, -1638, -1639, -1640, -1642, -1643, -1644, -1645, -1646, -1648,
  -1649, -1650, -1651, -1652, -1654, -1655, -1656, -1657, -1658, -1660, -1661,
  -1662, -1663, -1664, -1666, -1667, -1668, -1669, -1670, -1672, -1673, -1674,
  -1675, -1676, -1678, -1679, -1680, -1681, -1682, -1684, -1685, -1686, -1687,
  -1688, -1690, -1691, -1692, -1693, -1694, -1696, -1697, -1698, -1699, -1700,
  -1702, -1703, -1704, -1705, -1706, -1708, -1709, -1710, -1711, -1712, -1714,
  -1715, -1716, -1717, -1718, -1720, -1721, -1722, -1723, -1724, -1726, -1727,
  -1728, -1729, -1730, -1732, -1733, -1734, -1735, -1736, -1738, -1739, -1740,
  -1741, -1742, -1744, -1745, -1746, -1747, -1748, -1750, -1751, -1752, -1753,
  -1754, -1756, -1757, -1758, -1759, -1760, -1762, -1763, -1764, -1765, -1766,
  -1768, -1769, -1770, -1771, -1772, -1774, -1775, -1776, -1777, -1778, -1780,
  -1781, -1782, -1783, -1784, -1786, -1787, -1788, -1789, -1790, -1792, -1793,
  -1794, -1795, -1796, -1798, -1799, -1800, -1801, -1802, -1804, -1805, -1806,
  -1807, -1808, -1810, -1811, -1812, -1813, -1814, -1816, -1817, -1818, -1819,
  -1820, -1822, -1823, -1824, -1825, -1826, -1828, -1829, -1830, -1831, -1832,
  -1834, -1835, -1836, -1837, -1838, -1840, -1841, -1842, -1843, -1844, -1846,
  -1847, -1848, -1849, -1850, -1852, -1853, -1854, -1855, -1856, -1858, -1859,
  -1860, -1861, -1862, -1864, -1865, -1866, -1867, -1868, -1870, -1871, -1872,
  -1873, -1874, -1876, -1877, -1878, -1879, -1880, -1882, -1883, -1884, -1885,
  -1886, -1888, -1889, -1890, -1891, -1892, -1894, -1895, -1896, -1897, -1898,
  -1900, -1901, -1902, -1903, -1904, -1906, -1907, -1908, -1909, -1910, -1912,
  -1913, -1914, -1915, -1916, -1918, -1919, -1920, -1921, -1922, -1924, -1925,
  -1926, -1927, -1928, -1930, -1931, -1932, -1933, -1934, -1936, -1937, -1938,
  -1939, -1940, -1942, -1943, -1944, -1945, -1946, -1948, -1949, -1950, -1951,
  -1952, -1954, -1955, -1956, -1957, -1958, -1960, -1961, -1962, -1963, -1964,
  -1966, -1967, -1968, -1969, -1970, -1972, -1973, -1974, -1975, -1976, -1978,
  -1979, -1980, -1981, -1982, -1984, -1985, -1986, -1987, -1988, -1990, -1991,
  -1992, -1993, -1994, -1996, -1997, -1998, -1999, -2000, -2002, -2003, -2004,
  -2005, -2006, -2008, -2009, -2010, -2011, -2012, -2014, -2015, -2016, -2017,
  -2018, -2020, -2021, -2022, -2023, -2024, -2026, -2027, -2028, -2029, -2030,
  -2032, -2033, -2034, -2035, -2036, -2038, -2039, -2040, -2041, -2042, -2044,
  -2045, -2046, -2047, -2048, -2050, -2051, -2052, -2053, -2054, -2056, -2057,
  -2058, -2059, -2060, -2062, -2063, -2064, -2065, -2066, -2068, -2069, -2070,
  -2071, -2072, -2074, -2075, -2076, -2077, -2078, -2080, -2081, -2082, -2083,
  -2084, -2086, -2087, -2088, -2089, -2090, -2092, -2093, -2094, -2095, -2096,
  -2098, -2099, -2100, -2101, -2102, -2104, -2105, -2106, -2107, -2108, -2110,
  -2111, -2112, -2113, -2114, -2116, -2117, -2118, -2119, -2120, -2122, -2123,
  -2124, -2125, -2126, -2128, -2129, -2130, -2131, -2132, -2134, -2135, -2136,
  -2137, -2138, -2140, -2141, -2142, -2143, -2144, -2146, -2147, -2148, -2149,
  -2150, -2152, -2153, -2154, -2155, -2156, -2158, -2159, -2160, -2161, -2162,
  -2164, -2165, -2166, -2167, -2168, -2170, -2171, -2172, -2173, -2174, -2176,
  -2177, -2178, -2179, -2180, -2182, -2183, -2184, -2185, -2186, -2188, -2189,
  -2190, -2191, -2192, -2194, -2195, -2196, -2197, -2198, -2200, -2201, -2202,
  -2203, -2204, -2206, -2207, -2208, -2209, -2210, -2212, -2213, -2214, -2215,
  -2216, -2218, -2219, -2220, -2221, -2222, -2224, -2225, -2226, -2227, -2228,
  -2230, -2231, -2232, -2233, -2234, -2236, -2237, -2238, -2239, -2240, -2242,
  -2243, -2244, -2245, -2246, -2248, -2249, -2250, -2251, -2252, -2254, -2255,
  -2256, -2257, -2258, -2260, -2261, -2262, -2263, -2264, -2266, -2267, -2268,
  -2269, -2270, -2272, -2273, -2274, -2275, -2276, -2278, -2279, -2280, -2281,
  -2282, -2284, -2285, -2286, -2287, -2288, -2290, -2291, -2292, -2293, -2294,
  -2296, -2297, -2298, -2299, -2300, -2302, -2303, -2304, -2305, -2306, -2308,
  -2309, -2310, -2311, -2312, -2314, -2315, -2316, -2317, -2318, -2320, -2321,
  -2322, -2323, -2324, -2326, -2327, -2328, -2329, -2330, -2332, -2333, -2334,
  -2335, -2336, -2338, -2339, -2340, -2341, -2342, -2344, -2345, -2346, -2347,
  -2348, -2350, -2351, -2352, -2353, -2354, -2356, -2357, -2358, -2359, -2360,
  -2362, -2363, -2364, -2365, -2366, -2368, -2369, -2370, -2371, -2372, -2374,
  -2375, -2376, -2377, -2378, -2380, -2381, -2382, -2383, -2384, -2386, -2387,
  -2388, -2389, -2390, -2392, -2393, -2394, -2395, -2396, -2398, -2399, -2400,
  -2401, -2402, -2404, -2405, -2406, -2407, -2408, -2410, -2411, -2412, -2413,
  -2414, -2416, -2417, -2418, -2419, -2420, -2422, -2423, -2424, -2425, -2426,
  -2428, -2429, -2430, -2431, -2432, -2434, -2435, -2436, -2437, -2438, -2440,
  -2441, -2442, -2443, -2444, -2446, -2447, -2448, -2449, -2450, -2452, -2453,
  -2454, -2455, -2456, -2458 } ;

/* fixdt(1,16,2^-13,0) */
/*
 * File trailer for generated code.
 *
 * [EOF]
 */
