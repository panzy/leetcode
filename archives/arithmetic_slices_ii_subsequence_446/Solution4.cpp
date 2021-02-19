/*
446. Arithmetic Slices II - Subsequence
https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

DP approach.

This version was modified from the previous one, and it finally becomes identical to the LeetCode official DP solution.

--
Zhiyong, 2021-02-18
*/
#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

class Solution {
public:

    int numberOfArithmeticSlices(const vector<int>& A) {
        int n = A.size();

		// dp[i][delta] = number of subsequences ending with A[i] and has that particular delta.
		//
		// Notice that the minimal length here is 2, not 3.
		//
		// This doesn't affect the program's correctness because this array is not supposed to contain
		// the final answer directly. Instead, it helps to build the answer.
		//
		// This is necessary because, for example, [1, 1, 2, 3], when appending 3, the final answer is correct only
		// if both [1, 2] have been counted.
		vector<map<LL, int>> dp;

		dp.resize(n);
        fill(dp.begin(), dp.end(), map<LL, int>{});

        ULL ans = 0;

		for (int i = 0; i + 1 < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				// Try to append A[j] to a sequence ending with A[i].
				LL delta = (LL)A[j] - A[i];

				// If A[i] has its own "i", then we've found some subsequences with A[i] and A[j] being
				// its last two elements.
				if (dp[i].find(delta) != dp[i].end()) {
					// How many such subsequences?
					// For each subseqnce ending at A[i], appending A[j] to it results in a new one,
					// besides, A[i] itself can make a new subsequence with A[j], hence +1.
					int m = dp[i][delta] + 1;
					dp[j][delta] += m;
					ans += m - 1; // -1 because the last subsequence, which has a length of 2, should be excluded.
				}
				else {
					// Count this A[i], but add nothing to the answer.
					dp[j][delta]++;
				}
			}
		}

        return ans;
    }
};

int main() {
    {
		vector<int> nums = { 1,2,3,1,2,3 };
        int res = Solution().numberOfArithmeticSlices(nums);
		_ASSERT(4 == res);
    }
    {
		vector<int> nums = { 2,4,6,8,10 };
        int res = Solution().numberOfArithmeticSlices(nums);
        _ASSERT(7 == res);
    }
    {
		vector<int> nums = { 79,20,64,28,67,81,60,58,97,85,92,96,82,89,46,50,15,2,36,44,54,2,90,37,7,79,26,40,34,67,64,28,60,89,46,31,9,95,43,19,47,64,48,95,80,31,47,19,72,99,28,46,13,9,64,4,68,74,50,28,69,94,93,3,80,78,23,80,43,49,77,18,68,28,13,61,34,44,80,70,55,85,0,37,93,40,47,47,45,23,26,74,45,67,34,20,33,71,48,96 };
        int res = Solution().numberOfArithmeticSlices(nums);
		_ASSERT(1030 == res);
    }
    { // combination overflow
		vector<int> nums = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
        int res = Solution().numberOfArithmeticSlices(nums);
		_ASSERT(2147483151 == res);
    }
    { // combination overflow
		vector<int> nums = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
        int res = Solution().numberOfArithmeticSlices(nums);
		_ASSERT(1073741358 == res);
    }
    { // combination overflow
		vector<int> nums = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
        int res = Solution().numberOfArithmeticSlices(nums);
        _ASSERT(4194050 == res);
    }
    {
		vector<int> nums = { 1,1,1,1,1 };
        int res = Solution().numberOfArithmeticSlices(nums);
        _ASSERT(16 == res);
    }
    {
		vector<int> nums = { 1,1,1,1 };
        int res = Solution().numberOfArithmeticSlices(nums);
        _ASSERT(5 == res);
    }
    { // overflow
		vector<int> nums = { -2147483648,0,-2147483648 };
        int res = Solution().numberOfArithmeticSlices(nums);
        _ASSERT(0 == res);
    }
    { // overflow
		vector<int> nums = { 0,2000000000,-294967296 };
        int res = Solution().numberOfArithmeticSlices(nums);
        _ASSERT(0 == res);
    }
    {
		vector<int> nums = { 2,2,3,4 };
        int res = Solution().numberOfArithmeticSlices(nums);
        _ASSERT(2 == res);
    }
    {
		vector<int> nums = { 0,1,1,1,2 };
        int res = Solution().numberOfArithmeticSlices(nums);
        _ASSERT(4 == res);
    }
    {
		vector<int> nums = { 0,1,1,2,2 };
        int res = Solution().numberOfArithmeticSlices(nums);
        _ASSERT(4 == res);
    }
    {
		vector<int> nums = { 0,1,2,2,2 };
        int res = Solution().numberOfArithmeticSlices(nums);
        _ASSERT(4 == res);
    }
    {
		vector<int> nums = { 0,1,2,2,2,1 };
        int res = Solution().numberOfArithmeticSlices(nums);
        _ASSERT(4 == res);
    }
    {
		vector<int> nums = { 2,4,9,16,6,8,10 };
        int res = Solution().numberOfArithmeticSlices(nums);
        //_ASSERT(8 == res);
    }
    {
		vector<int> nums = { 2,4,9,16,6,8,10,4 };
        int res = Solution().numberOfArithmeticSlices(nums);
        _ASSERT(9 == res);
    }
    { // large N
		vector<int> nums = { -2112443623, -2110566581, 1531074861, -1814395437,
		998898095, -2069406966, 1046221686, 799211444, -239785597, 1200221196,
		2059529693, -993085273, 1610954050, -745202026, -1544185274,
		1013781098, -123243018, -1750395439, 366572076, 276645862, 672312529,
		714066201, -1344684670, 653748801, 80187270, 329348606, 67493923,
		2106706759, 1691694374, -243009757, -561945945, -1385124949,
		-556867154, -581239724, 1699256772, -1651341792, -1522374202,
		1426164423, 1096461250, 357040673, -848961108, -1523019317,
		-1428831189, -1741574985, -1872845039, 1126092477, 1937977174,
		-1043965735, 2037929581, 1053971031, -1741277038, -1332042033,
		-1774944501, -1559153908, -1972903726, 18811489, -2009712577,
		1273463831, 907239492, -2094361718, 147860931, 1513921774, -1135879813,
		-1398459584, -155519393, 799587763, 611338797, -98440426, -1040339857,
		-1165232833, -1383562697, 86661847, -641531221, -1976052481,
		1140933728, 302753044, 1196827424, -79216791, -1858438477, -1332064108,
		-772206931, -1086930570, 2111447301, 339803116, -808522138, 467612130,
		-610851937, 802486349, 756232562, -177060238, 1051079822, -960378914,
		-96781385, -10469647, -1460714334, 1064103443, -106664808, 995618737,
		435833493, -1562365976, 615359766, 2122357057, 2081458247, -520108145,
		-1888912935, 1858080659, 1691862431, 15030685, -456583357, -1611221838,
		1418733124, 816464260, 137941132, -1616151163, -1746471534, 134916438,
		-590746673, 1225388232, -805713008, 916269845, 1781394483, -454881283,
		948916134, 1197061616, -1031177035, -1853605240, 1971320116, 505415078,
		-276618001, 3868968, 1716920731, 34379726, 704740899, 419697821,
		-1784278504, -1836443506, 191990799, -426603275, -1831075082,
		1186461922, 1363958500, -490360586, -2087259291, 473275628, 1135464830,
		-1158077973, -281562425, 1232059834, 1284819370, -1444866664,
		-2142136682, 1793231253, 2027654613, 1591415580, 1268743887,
		-2100421612, 593806967, 542719862, -1388671510, -567989610, 1239331491,
		-723668720, -2025100144, 2074201634, -798918719, -141830905, 424025676,
		-1670577498, -1077023289, 980131740, -1948005639, -1015089555,
		1118967404, 1004850711, -502025746, 400556732, 842809856, -409086596,
		1822648989, 227413837, 1327171826, -793610528, -1310511634,
		-1910098151, 191048850, -1181554393, 942186387, 1780497640, 222618569,
		-1191789005, -1292063753, -2071801521, 957978939, -52249410,
		-1803271320, 73362527, 90900715, -1901543733, -733780954, 99906928,
		-786708804, -1107172937, -1096797453, -1650238938, -1636061644,
		693338117, 680853195, 1104801364, -1123296140, 942791080, 972050149,
		-1589518395, 1452556564, 32393986, -261192743, -1870656542, 1397367994,
		-433259278, 1967232113, -1379413347, -1348560825, 393426855,
		-900743674, -289977280, 2136091292, 1865489930, 1484946735, -782153542,
		1819676701, 2117302337, -154639412, 1872837433, 1459042491, -712368004,
		-521240857, 633176678, 833124583, 1149698000, -1515765140, 457370488,
		1150678483, -576695446, 674407478, 1792016551, -1366407366, 811489618,
		-1000233065, 572097273, 1248964262, -136361935, 1683319820, 1932772046,
		-988611225, -1551854314, 2123336456, 1432772243, -953554998, 872058614,
		-1318413521, 457518688, 358958195, -447346315, 561155599, 1963696601,
		-1889363609, -314407090, -825342032, -894952621, -1205368283,
		-1639739573, -1099269752, 1804772321, -51447484, 1420354084,
		1528822068, -2053321269, -1073639812, 1190612853, -751777490,
		1359945200, -387906097, 1441858503, 475716473, 124360151, -1476407049,
		512196328, 498390809, -1637416049, 247416419, -1699419480, 1866366090,
		1334348259, -1494212529, 1377120426, -1444847454, -274503468,
		-1813691731, 41224858, 1448328265, 236026091, 1169035059, -93779396,
		-286108794, 1826194377, -1714836118, 252737240, -1663367875, 6161323,
		-1106006822, -886342445, -1391208088, -1331971617, 949339575,
		-852470426, -650780050, -1132280419, 137683478, 1169249520, -953734766,
		-11407041, -1837837379, -1660996312, 1838095301, -1072871722, 47904788,
		539551056, 1027252881, 488452193, 750615541, 410584137, -2112764337,
		-1582879851, -1365046912, 1071170160, -595245522, -221340303,
		976372098, 295745388, 289189824, -180388336, 1032076162, -1991978388,
		-1201985275, 976364106, 1141930260, -1708332024, 560509838, -621852118,
		1027073040, -1503485306, 1675197789, 976123681, 482731030, -594358405,
		-273211688, 1738227814, -766335728, 2078976234, 698922441, -1443654382,
		-922518634, 374816118, -1842749517, 902974915, -1136045567,
		-1853954740, 1147613813, 606938541, -1513645813, 129396187, 616074068,
		-2055422852, -2013005181, 1378408648, 2111672116, -1736366039,
		674529400, 736563557, 1254553015, 969717892, 2046645134, 333190964,
		643543950, 309688482, 521571464, 1079633443, -152244824, 1419432384,
		980671627, -1534935627, 954710451, 971604860, 1941827337, -830619043,
		-1333378453, -1335134691, 704170211, 1490193965, 1283068399,
		-678684470, -1520134054, -1636697807, -1935093905, -1303838735,
		740224993, 2044840734, 885094261, 245563783, -1178808838, -752076174,
		1258443132, -1142939946, -41330522, -1790787736, 875276036, 2027420589,
		-1096747774, 1462147563, 1718867575, -1739627075, 23892822, -714904537,
		166644936, -2124766995, -175493685, 785702360, 428889589, -1475392602,
		-1135559207, -2034002134, -1323505558, 1807308610, -353312130,
		1641836935, 1863435863, -1613993910, -1286317881, -216874147,
		-1504353793, -1489093582, 1860991692, -1385119069, 734242610,
		987105941, 297887931, 1937621184, 1135034275, 1533879815, 1790093055,
		-497691901, 795970231, -2048916668, 1737282335, 447237336, 1574862270,
		-1840785756, 1679505143, -170263803, -2042725054, 182277435,
		-243187010, -1897667265, -1015009618, -183241945, -226029182,
		-1116746718, 660200645, 319833402, -789884135, -647964409, -1747162774,
		-298605115, -2013722094, 2026576584, 2128820340, -1248435580,
		1123012042, 1855374993, 509973982, -2081512499, 1125448391, -227758261,
		1209696371, -546884621, 861951983, -2008053328, 676710377, 168206588,
		1782787464, 1930527972, -1677185990, -129467086, -697001553,
		-1957770203, 2008342475, -1486530372, -1756471700, 2075612723,
		1147777324, 385975487, 727628246, 1582693963, 614404650, 792634772,
		686885317, -302668779, -505077399, 849908728, 1620360072, 1945834741,
		-298115690, -1744841505, -1989132449, 1813250031, -192818517,
		1398874365, -1617754096, 940018329, -1323167731, 832921244,
		-1542573101, -473175900, 1919843945, -1223577583, -209901125,
		-1892632244, 1883467263, 98559897, -331987385, -1336611901, 492450440,
		1746585236, -1293200938, -1552033257, 1670110770, 1072653254,
		-628484251, 1349262281, -1034684723, 1552848241, 466006558, 340699925,
		-1608299437, 1206497771, -1354944188, 616273257, -822903680,
		-1134665976, 81915902, -1317495835, 819352235, -2081418938, -320385864,
		1582995808, 944649256, 403956205, 1446817460, -968097657, -23071406,
		1988332496, 146890864, -608616516, 1246408938, 375273243, 1726111184,
		-1524464422, 627441755, -1250606395, -37919226, -591138745,
		-1313298446, 1550735741, -1632705154, -1786082339, 1528425291,
		-959022654, 1809336588, -895406239, -318555886, -1632344467,
		1670804317, -1166655477, 903437078, -1282490255, 230568801, 750881895,
		1209226227, -910461186, -1635250057, 32365740, -1697822852, 490363476,
		258900142, -314112316, -126386166, 2138194826, -519543897, 2130818267,
		-172905244, -843170004, -1438498386, 730287200, 722715569, 1701255771,
		-1000710783, 1818594942, 732112760, 1551432292, -228723139, -726103372,
		-1673736559, -1833975850, 1128809679, 2113140723, -464957662,
		1307439939, -1761590137, 1539973260, 767629182, -265103157, 1580316830,
		-1310319681, -523010294, 184121647, 888553109, 1538281055, 97604347,
		-29619338, 884937845, -941744276, 1685914894, 838065674, 415573337,
		-2141131952, 2142070232, -1547401660, 1553161196, 648028602,
		1111907736, -414494157, 1517763683, -1230710640, -905301515,
		1287999594, -1148491271, -974207929, 1029759201, -2027329281,
		-1769974508, -238736937, -184202920, 164022062, -1921668834,
		1827126801, 1143991006, -197934300, 969108310, 2012371148, -1694870172,
		1495802106, -2082921598, 1993280516, -1404998191, 692600285,
		1240203428, -1508165596, -1756829857, 1125389821, -809590770,
		-1962817428, -542238542, -1142080944, 1752593860, 1503558618,
		-1023194499, -441353512, -938355422, -687971572, 314002319, 1512593783,
		644638813, 1087546745, 2104149225, -1587444144, 263940729, 283142353,
		1132918141, -1364692214, 1739890543, -726503877, 663153539,
		-1497539239, -1466712411, -189029471, 1200395931, -697435360,
		-407856222, -2125955741, -1789409754, -680419585, -1132458003,
		810715631, -1498147792, -624094576, -694938393, 1981184271, -43775147,
		54599199, -11855109, -1086234932, 1556064298, 262761804, 651877251,
		-624841726, -1979347110, -469059923, 1803923060, 548023867,
		-1274121018, 174521349, -263507145, 637996289, -414090477, -1733846865,
		-1221347033, 1248511920, 1935252679, 1675995957, 1865199370,
		-826076012, 1398262410, 449608831, 1169555589, 1255560500, 1859224614,
		-2060127338, 1746168216, -1218930661, 1277735063, 570410498,
		1882348909, 884863111, 2046655111, 1620758168, 1070476717, -116628681,
		957445575, -1805941876, -610755126, 1700253848, -1293223149,
		-1628377243, 1555670927, 2019317927, -590314165, 549509202, 1644698776,
		39888819, 337050464, 1337783190, -1479591209, -1442634755, -1030938283,
		1997357697, -1196958099, -227605194, -1536148841, 562438856, -74544027,
		-1965708812, -1842103901, 650530557, -506185495, 461263923,
		-1902644891, -1948604793, 833205400, 630386565, -1450463322, 127769731,
		1319341206, -1177958677, 527209227, -1719180370, 796157798, 1337296495,
		19316927, -435572952, 486859127, -615447946, 432216246, 1061687600,
		2097514399, -183990051, -468227361, 406761504, -39796482, -577521133,
		-1144418271, 719221950, 1731055324, 1183021669, 903601051, 452463820,
		-487076884, 41566687, 27484865, -1989099583, -459496746, 233909519,
		-1434100451, 1828472297, -1092012006, 1537996119, -1986894566,
		-1888345698, -616762564, -2019639016, -1535522551, 468438305,
		-1394945026, 1008007265, 1201313444, 763965133, 576580294, -1997369063,
		1058030317, 624263689, -1822225012, 580693832, 79250919, 1979561120,
		663108285, -718201949, -1503886031, 1899743805, -1876345081,
		-1324824019, -719026950, -1484575305, 910754706, -1687482199,
		1319030042, 1593742442, 1683215875, 367565751, 575111316, 945290501,
		-374707626, 1656731724, -1131372079, 1900792381, -1645830531, 9153454,
		1077510212, 28702606, 1807994120, -532654029, 1682012449, -409623995,
		-1424065301, -756463258, 1128623371, 1357317539, -214294633, 688700274,
		-1390609329, -1904864867, 481523864, -1902181626, 700888761,
		1011804747, 638660260, 2031769888, 2084978682, 230366923, -694950408,
		1606181603, -366325706, 1429273105, 1650358321, 82797254, -2127957319,
		1212681984, 1154839389, -504822217, -542713466, 2109290838,
		-2059664927, -2043924076, -908082066, -1514823008, -1900930198,
		-1309594305, -1948720989, 741540523, -2022945771, 1684689007,
		436943745, -1504709989, 874802860, -1779761179, 1041722795, -521587682,
		185125021, 246016613, 155666918, 1564552825, 1872041932, 2026054053,
		2134701393, 125728457, 46647072, -1346167373, 739133482, -1892071356,
		1950394554, -1110082248, -910899110, -288977198, 1842650639, 612935426,
		-417083740, -337280516, 908155077, 347673972, 1230965661, -1509182322,
		-2004701887, -2108576166, 1644133061, -329175897, -997924372,
		-1094554423, -1220720066, 763112267, -173630340, -1634782194,
		222040007, -1998939416, 1709163971, -1115897026, 1327222566,
		-866893241, 406158508, 1272025159, 1452735229, 1632673457, 1773403557,
		-1266751271, 2088509251, -794149483, 1063036610, -1178681360, 47322074,
		-348633448, -187263307, -1222972903, -1039760105, 1890791164,
		1114091089, -539805326, -643175751, -207015362, -33139105, -1033404645,
		-1541755706, 277401643, 1314226672, 452282091, 399219872, -595832286,
		-1874668962, -1864843982, -51113277, 1549942810, 1715306731,
		-1799144277, -563573179, -493589855, 491554406, -1791751830,
		-1567303709, -1825052690, -1887246312, -574662933, -402798211,
		495302094, -681648870, -947876281, 673479319, 1683280359, 1385033837,
		142820870, -1606924557, 494514374, -558712635, -1944548785,
		-1450692693, 2142978228

		};
        int res = Solution().numberOfArithmeticSlices(nums);
        _ASSERT(1 == res);
    }
    return 0;
}
