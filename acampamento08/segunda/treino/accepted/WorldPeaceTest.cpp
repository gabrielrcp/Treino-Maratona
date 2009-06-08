#define TEST

#include "WorldPeace.cpp"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <stdio.h>
#include <time.h>
using namespace std;



class WorldPeaceTest {

	public: static bool passed;
	
	    
    static void assertEquals(int testCase, const long long& expected, const long long& actual) {
        if (expected == actual) {
        	passed = true;
            cout << "Test case " << testCase << " PASSED!";
        } else {
        	passed = false;
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>';
        }
    }


    WorldPeace solution;
    
    

void testCase0 () {
int var0 = 2;

int _var1[] = {1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 5000000000LL;

assertEquals(0, ret, solution.numGroups(var0, var1));
}

void testCase1 () {
int var0 = 2;

int _var1[] = {1,2,3,4,5,10000};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 15LL;

assertEquals(1, ret, solution.numGroups(var0, var1));
}

void testCase2 () {
int var0 = 4;

int _var1[] = {4,4,4,4,4};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 5LL;

assertEquals(2, ret, solution.numGroups(var0, var1));
}

void testCase3 () {
int var0 = 5;

int _var1[] = {1,2,3,4,5,6};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 3LL;

assertEquals(3, ret, solution.numGroups(var0, var1));
}

void testCase4 () {
int var0 = 2;

int _var1[] = {1000000000,1000000000,1000000000,1000000000,1000000000,1000000000};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 3000000000LL;

assertEquals(4, ret, solution.numGroups(var0, var1));
}

void testCase5 () {
int var0 = 7;

int _var1[] = {96,17,32,138,112,50,7,19,412,23,14,50,47,343,427,22,39};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 166LL;

assertEquals(5, ret, solution.numGroups(var0, var1));
}

void testCase6 () {
int var0 = 4;

int _var1[] = {11,7,19,20};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 7LL;

assertEquals(6, ret, solution.numGroups(var0, var1));
}

void testCase7 () {
int var0 = 4;

int _var1[] = {10,11,12,13,14,15};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 18LL;

assertEquals(7, ret, solution.numGroups(var0, var1));
}

void testCase8 () {
int var0 = 20;

int _var1[] = {779627264,93189506,613466388,134427144,828724020,544708317,42347176,37421484,74484324,520323545,234449936,196844102,912238837,551556697,817814869,747734358,269911175,567298611,306200728,395940546,21525713,579409252,410141724,72210874,326985688,879159886,742795969,705906481,765095838,229899691,463828983,862019855,174654779,65742820,968052250,650219887,447544129,761736194,70263040,10935236,128093184,627882505,263709203,211025620,564598826,397556360,536827919,140380264,531732785,630266277};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 1095445512LL;

assertEquals(8, ret, solution.numGroups(var0, var1));
}

void testCase9 () {
int var0 = 20;

int _var1[] = {921385133,790821665,696669406,629378824,414868114,119982058,37118381,187335494,170960800,355358559,336049477,714056927,884157521,677542714,175746499,78642955,108047781,136658582,432930531,800141367,841531080,602333054,137043306,60072120,93197385,525060743,695383137,377557617,291335284,295615380,911638059,687324348,345506765,29197955,928461497,991504508,885353733,672301705,210088033,718080603,703278098,432812568,947587990,411980479,709864060,667653099,817211438,409243463,774387240,527316494};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 1268388701LL;

assertEquals(9, ret, solution.numGroups(var0, var1));
}

void testCase10 () {
int var0 = 20;

int _var1[] = {851373528,700343230,667482447,852927139,292184590,275666245,949018142,49002282,689030432,864309560,51452024,913879220,174559276,126774957,997419305,699811244,807533640,42801203,160031249,996024117,106357046,447489713,225338308,380565035,413686851,412043300,48638853,170563977,530396191,439851648,409790936,15566846,136249554,254321295,767411134,524889291,875007969,291761655,987820971,597478355,623281503,880803148,681828276,631558678,385298266,489237224,220906956,331379031,459860611,349832303};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 1212541937LL;

assertEquals(10, ret, solution.numGroups(var0, var1));
}

void testCase11 () {
int var0 = 20;

int _var1[] = {724065689,399663895,11110909,238593518,307672214,6913631,941330709,172098483,672726710,562486539,11848830,314955144,667554291,977434362,487235259,444091954,808612951,305352366,188309458,903504601,868090233,375044037,731093358,101247755,544188329,787589579,901690442,249873919,918473591,440446187,571174429,232186216,874393463,562497525,289922196,186085456,902040002,96508662,717427486,645455850,746466149,149231738,341483139,848448473,170336890,144446887,519721539,130184838,696424647,260511833};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 1207412318LL;

assertEquals(11, ret, solution.numGroups(var0, var1));
}

void testCase12 () {
int var0 = 20;

int _var1[] = {736854234,153817364,571434187,711532836,112553317,102047734,349869625,440058352,617768922,850617954,435131784,829236387,161378428,575953033,634761420,113664934,694414704,211048275,287720323,270704751,745722392,656858411,803828350,307811838,350742550,680859614,518951537,26486857,164227676,990119561,614262981,539727447,658040687,53124777,473874164,47408321,696793007,862778964,262361918,632803537,456928501,982399019,692191811,133503748,608961249,897200945,920765947,461271007,917927373,905680577};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 1296209166LL;

assertEquals(12, ret, solution.numGroups(var0, var1));
}

void testCase13 () {
int var0 = 2;

int _var1[] = {1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 25000000000LL;

assertEquals(13, ret, solution.numGroups(var0, var1));
}

void testCase14 () {
int var0 = 13;

int _var1[] = {664200243,892452227,673566186,693683287,728264260,674789880,933016497,787976560,706644330,867748883,849252185,705566904,693093026,824641596,921736452,968187934,738736894,693362287,872488647,690194575,679681728,759530598,898318214,757029994,926439271,843573627,669627346,809224259,995314429,822608511,722522963,795950531,710720233,774940456,921057041,820367893,618716102,634444311,758992084,919682818,825892821,994050701,825566953,906064628,814055948,812011322,977316227,640253278,779987387,651570564};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 3049624237LL;

assertEquals(14, ret, solution.numGroups(var0, var1));
}

void testCase15 () {
int var0 = 10;

int _var1[] = {638074479,717901019,910893151,924124222,991874870,919392444,729973192,607898881,838529741,907090878,632877562,678638852,749258866,949661738,784641190,815740520,689809286,711327114,658017649,636727234,871088534,964608547,867960437,964911023,642411618,868318236,793328473,849540177,960039699,998262224,775720601,634685437,743766982,826321850,846671921,712570181,676890302,814283264,958273130,899003369,909973864,921987721,978601888,633027021,896400011,725078407,662183572,629843174,617774786,695823011};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 3983180234LL;

assertEquals(15, ret, solution.numGroups(var0, var1));
}

void testCase16 () {
int var0 = 20;

int _var1[] = {24555,10027,113879318,4,348589382,14824189,147761,214483647,475906539,212566,361,2789,2134625,144730,18,537787,18228647,76570565,862764,108634017,6014,189886689,521242,434753491,518,1718,65932,21145,111591972,46,670,300359704,81705,25,18740,38136,20,28829193,22669310,598,22498619,50316556,59,558231,8420544,214748647,10546,828395,12,59357};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 3145548LL;

assertEquals(16, ret, solution.numGroups(var0, var1));
}

void testCase17 () {
int var0 = 20;

int _var1[] = {143,26167551,42881,7850070,518948905,126693,87,1236406,11809,15414,949446851,945078080,9028,47234125,32350,281,615909512,247483647,2,54606,12,96755454,88048592,778513924,46381829,199204,1201,9,233420733,168872,9437,104,27428,23152,102,1503,3,190173,2498,112092,246663585,142844,16973,21948,13655,578763,604499,572603,53979301,940};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 745327LL;

assertEquals(17, ret, solution.numGroups(var0, var1));
}

void testCase18 () {
int var0 = 20;

int _var1[] = {4898850,2688,178,174,81,520507,6197,547102,15624,4560,15531,11,2,194616562,10357,24080,72833078,21,14,244543813,667678639,43354221,86623,241738,373024,49822,1936,5069,4,958,24623630,15509617,14781263,2109109,5,534338464,117808,285903811,126234987,163491,29820,58670477,15157,537602839,327989544,2272,214789,815,40985,2362094};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 830481LL;

assertEquals(18, ret, solution.numGroups(var0, var1));
}

void testCase19 () {
int var0 = 20;

int _var1[] = {1126,327315894,730211407,336889,6339,592356681,1866913,100,214748347,12931516,593128246,158,2275159,18,17876191,66,4871,206942,8,10,747483647,14,2066708,3383,16,847483647,3,214463647,17546,6,11,2745,5853,70006228,2,657654619,1284,3356,11312,225727,1181538,3,636842341,117133210,783289527,3,41,161194987,473504183,722615792};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 4109075LL;

assertEquals(19, ret, solution.numGroups(var0, var1));
}

void testCase20 () {
int var0 = 6;

int _var1[] = {10923,48723,13,100,782,1092,99990};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 113LL;

assertEquals(20, ret, solution.numGroups(var0, var1));
}

void testCase21 () {
int var0 = 11;

int _var1[] = {1230498,39482,57,1237,348972,890,123468,3475923,2384765,87542,34281};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 57LL;

assertEquals(21, ret, solution.numGroups(var0, var1));
}

void testCase22 () {
int var0 = 7;

int _var1[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 5LL;

assertEquals(22, ret, solution.numGroups(var0, var1));
}

void testCase23 () {
int var0 = 7;

int _var1[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 6LL;

assertEquals(23, ret, solution.numGroups(var0, var1));
}

void testCase24 () {
int var0 = 4;

int _var1[] = {1000,100,10,5,1};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 6LL;

assertEquals(24, ret, solution.numGroups(var0, var1));
}

void testCase25 () {
int var0 = 7;

int _var1[] = {842,6,2360319,565,6864,14,3489,2,21723};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 22LL;

assertEquals(25, ret, solution.numGroups(var0, var1));
}

void testCase26 () {
int var0 = 14;

int _var1[] = {32761689,2804845,249467,1474245,170277,126220346,3,20744334,3,5958688,775,791,147907115,8,102973,62268205,92425,2287089,16875493,102652,40};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 149835LL;

assertEquals(26, ret, solution.numGroups(var0, var1));
}

void testCase27 () {
int var0 = 10;

int _var1[] = {158086265,293395644,199838070,129404,21112,6,43,4,317618267,704,42362,45561146,75672,68,395751475,236172945,45758684,396946,3,26042214,2461594,301267235,436820240,4,84702299,212,8854,109,54992,6,23494,5748663,3942,129372};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 105580954LL;

assertEquals(27, ret, solution.numGroups(var0, var1));
}

void testCase28 () {
int var0 = 6;

int _var1[] = {362,5,25,17,1072913,3844,11652522,4,366655597,8625,7835709,3,141,218541918,262,6042250,2024470,2944,1730,5681077,22,3,10223486,426,13750043,1085,186145018,745,1334176,87162819,1283833,30514555,14865212,11,93466,1457054,61406345,41,3,8,250006596,30138,40597,53019451,2563,441,153328804,20,137};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 216329135LL;

assertEquals(28, ret, solution.numGroups(var0, var1));
}

void testCase29 () {
int var0 = 20;

int _var1[] = {34107563,30308835,3189323,18777,131210,74102,587481,114,47,6,1027,4754,23135369,27617137,8220,136,2012,4,4,1439,47864,1343864,38805176,696762,31821135,340874935,35929162,20351204,32018420,268032,5834,329,252,107818107,95179,5,91828312,232379802,36202031,50965};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 355156LL;

assertEquals(29, ret, solution.numGroups(var0, var1));
}

void testCase30 () {
int var0 = 16;

int _var1[] = {785,2468,408462733,7713,9,22939874,18,198990,340,51,69737,16731,39302,23152,41,74,348194297,3427,350485,459304,18614,3036117,136827,112962239,2634,367168,247767,9895,31,6993728};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 41761LL;

assertEquals(30, ret, solution.numGroups(var0, var1));
}

void testCase31 () {
int var0 = 12;

int _var1[] = {263295,55,637600,164536319,29550,16794400,79515,2010157,1570,5319604,103,2140918,42,712628,31515,13,114193614,23070,27283,18181,572,2307905,11951,193621962,47683,518848,45864436,115540,7181,188,70642,861887,9986,7636172,12575,11695,1820995,5,22,100483716,116055402,174,10,1971,109102813,504,7};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 5698480LL;

assertEquals(31, ret, solution.numGroups(var0, var1));
}

void testCase32 () {
int var0 = 16;

int _var1[] = {22593,81,12,1958,44936987,7659246,22072,3014526,25935041,387746,715050,194,120641,42275,642488,183859559,2742427,83861,3,77522,431110288,578525,50,40049234,83274,19,315,121,447268379,27823};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 160938LL;

assertEquals(32, ret, solution.numGroups(var0, var1));
}

void testCase33 () {
int var0 = 4;

int _var1[] = {3251,14288,79585086,179760452,64,66773,27119,968,397581,1581,5721,116677,570,24,187515588,5};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 634622LL;

assertEquals(33, ret, solution.numGroups(var0, var1));
}

void testCase34 () {
int var0 = 8;

int _var1[] = {387871,55,250,72,9,50238,29,490456,32,992975,49518,1118,98701,64,941,2310098};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 2570LL;

assertEquals(34, ret, solution.numGroups(var0, var1));
}

void testCase35 () {
int var0 = 14;

int _var1[] = {2924,140139,80613166,82873,74041,792,8705840,44,151,6376,158,867,71455,13033,4,31056780,247321809,245118847,46124,667,4181,5858572,105112,2028285,401,103767,98,144522493,575,215767087,17710,15,15042829,56120013,230,9432,17,9,681,61815257,2502,132998,3140,1038};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 410777LL;

assertEquals(35, ret, solution.numGroups(var0, var1));
}

void testCase36 () {
int var0 = 9;

int _var1[] = {11,13,86869026,19005815,2228,29520,1623249,112588578,456,179506201,1630,94815,197201845,9486229,38,24566128,357,2371};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 131439LL;

assertEquals(36, ret, solution.numGroups(var0, var1));
}

void testCase37 () {
int var0 = 10;

int _var1[] = {12017,214544,18198461,43,887,331733,277503912,60290438,197962,20,71426,188527,69,2973117,26411,868159,17766,2771,100258,1304013,3422844,31,1982293,19,135886,4,10214408,41,2801,71,237761678,443066,30,27825,68529,263112941,16842887,3,31545404,3,28207,173845646,1073,62,5,893812,50,379,3,8751};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 11769959LL;

assertEquals(37, ret, solution.numGroups(var0, var1));
}

void testCase38 () {
int var0 = 20;

int _var1[] = {252526585,153,1008129,17051546,98643374,40055593,2129337,2441,4400,843750,38147,516095,88449183,14743352,32208113,12,2990,71632636,230284533,10840,221113,1016,23456,4,1091629,45911,12,1290,329774078,2,39,74684434,74376,1709420,69925,3931806,278236,318859,423539,314583,1207,15894,305,77,14,271,8};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 788405LL;

assertEquals(38, ret, solution.numGroups(var0, var1));
}

void testCase39 () {
int var0 = 13;

int _var1[] = {353000,91,104,10,55,465634801,741080,903124,916309,483769365,12553991,196004506,9,6176,459,150556370,340,101487,93};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 580LL;

assertEquals(39, ret, solution.numGroups(var0, var1));
}

void testCase40 () {
int var0 = 10;

int _var1[] = {1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 1100000000LL;

assertEquals(40, ret, solution.numGroups(var0, var1));
}

void testCase41 () {
int var0 = 8;

int _var1[] = {8,8,8,8,8,8,8,8,8};
vector <int> var1 (_var1, _var1 + (sizeof(_var1) / sizeof(_var1[0])));

long long ret = 9LL;

assertEquals(41, ret, solution.numGroups(var0, var1));
}
	
    public: void runTest(int testCase) {
		double tempo;
		clock_t Begin, End;
		   
		Begin = clock();    
		switch (testCase) {
			
		case(0): testCase0(); break;
		case(1): testCase1(); break;
		case(2): testCase2(); break;
		case(3): testCase3(); break;
		case(4): testCase4(); break;
		case(5): testCase5(); break;
		case(6): testCase6(); break;
		case(7): testCase7(); break;
		case(8): testCase8(); break;
		case(9): testCase9(); break;
		case(10): testCase10(); break;
		case(11): testCase11(); break;
		case(12): testCase12(); break;
		case(13): testCase13(); break;
		case(14): testCase14(); break;
		case(15): testCase15(); break;
		case(16): testCase16(); break;
		case(17): testCase17(); break;
		case(18): testCase18(); break;
		case(19): testCase19(); break;
		case(20): testCase20(); break;
		case(21): testCase21(); break;
		case(22): testCase22(); break;
		case(23): testCase23(); break;
		case(24): testCase24(); break;
		case(25): testCase25(); break;
		case(26): testCase26(); break;
		case(27): testCase27(); break;
		case(28): testCase28(); break;
		case(29): testCase29(); break;
		case(30): testCase30(); break;
		case(31): testCase31(); break;
		case(32): testCase32(); break;
		case(33): testCase33(); break;
		case(34): testCase34(); break;
		case(35): testCase35(); break;
		case(36): testCase36(); break;
		case(37): testCase37(); break;
		case(38): testCase38(); break;
		case(39): testCase39(); break;
		case(40): testCase40(); break;
		case(41): testCase41(); break;
			default: cerr << "No such test case: " << testCase << endl; exit (1);
		}
		End = clock();
		tempo = (double) (End - Begin) / CLOCKS_PER_SEC;
		
		printf (" in %.4lfs\n", tempo);
	}

};

bool WorldPeaceTest::passed;

int main(int argc, char *argv[]) {
	int cnt = 0, cntAc = 0, caso = -1;
	bool passedAll = true;
	
	if (argc > 1) {
		caso = atoi (argv[1]);
		if (caso == 42)
			return 100;
	}
	
    for (int i = 0; i < 42; i++) {
    	if (caso != -1 && caso != i) continue;
    	
		cnt++;
		WorldPeaceTest *test = new WorldPeaceTest ();
		test->runTest(i);
		passedAll &= WorldPeaceTest::passed;
		if (WorldPeaceTest::passed) cntAc++;
    }
    if (caso == -1) {
		if (passedAll) {
    		cout << "You've got AC! (" << cnt << "/" << cntAc << ")" << endl;
    	} else {
 	   		cout << "You've got WA! (" << cnt << "/" << cntAc << ")" << endl;
    	}
    }
    return 0;	
}
