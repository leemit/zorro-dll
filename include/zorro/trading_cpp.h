
#pragma once

#include "types.h"
#include "bitfield.h"

#if ZORRO_CPP >= 11
#define ZORRO_ENUM_OPEN(name) typedef enum class name {
#define ZORRO_ENUM_CLOSE(name) } name;
#else
#define ZORRO_ENUM_OPEN(name) namespace N##name { enum name {
#define ZORRO_ENUM_CLOSE(name) }; } typedef N##name::name name;
#endif

const var PI  = 3.14159265359;
const var NIL = 3e38;

const int NAMESIZE    = 16;
const int NAMESIZE2   = 40;
const int NUM_SKILLS  = 8;
const int NUM_RESULTS = 20;
const int MAX_PARAMS  = 16;
const int MAX_STEPS   = 1000;

const char* const ALL    = "*";
const int         NOW    = -999999;
const int         UPDATE = (1<<5);

const int SCRIPT_VERSION = 255;

#pragma push_macro("IGNORE")
#undef IGNORE

ZORRO_ENUM_OPEN(ETradeFlag)
	SHORT       = (1<<0),  // short position
	BID         = (1<<0),
	OPEN        = (1<<1),  // position is open
	NOTFOUND    = (1<<2),  // trade disappeared from the broker list
	EXPIRED     = (1<<3),  // option or future expired
	WAITSELL    = (1<<4),  // close position at the next tick
	WAITBUY     = (1<<5),  // open position at the next tick
	DETREND     = (1<<6),  // detrend the trade result
	SUSPEND     = (1<<7),  // suspend trade function
	EVENT       = (1<<8),  // trade function was called by enter/exit event
	IGNORE      = (1<<9),  // don't automatically enter/exit
	MISSEDENTRY = (1<<10), // missed the entry limit or stop, or sell price in the last bar
	MISSEDEXIT  = (1<<11), // missed the exit for some reason
	NOSIZE      = (1<<12), // Trade not executed, not enough lots or balance
	RECYCLE     = (1<<13), // Trade struct can be reused
	NONET       = (1<<14), // Don't open a net trade yet
	NET         = (1<<15), // Pool trade
	PHANTOM     = (1<<16), // Phantom trade 
	EXERCISE    = (1<<17), // exercise an option contract
	STOPPED     = (1<<18), // closed due to stop loss in the last bar, or a margin call
	PROFIT      = (1<<19), // closed due to profit target in the last bar
	TIME        = (1<<20), // closed due to timeout in the last bar
	SOLD        = (1<<21), // closed due to exit at market in the last bar
	CANCELLED   = (1<<22), // removed from trade list
	MISSEDOPEN  = (1<<23), // could not be opened by the broker
	ACCOUNT     = (1<<24), // trade with the main account
	ENTRYSTOP   = (1<<25), // entry stop, rather than limit
	ENTER       = (1<<26), // entered by TMF return value
	EXIT        = (1<<27), // exit by TMF return value
	REMOVED     = (1<<28), // removed from the online trade list (f.i. margin call or manually closed)
	BAR         = (1<<29), // run TMF on any bar only, not any tick
	REVERSED    = (1<<30), // indicate exit by reversal (shared with TR_EXIT)
	NEW         = (1<<31), // just created in a TMF 
ZORRO_ENUM_CLOSE(ETradeFlag)
ZORRO_BUILD_ENUM_BIT_OPERATORS(ETradeFlag)
typedef CBitfield<ETradeFlag, int> TTradeBitfield;

#pragma pop_macro("IGNORE")

ZORRO_ENUM_OPEN(EZorroFlag)
	SKIP1        = (1<<0),  // skip 1st of every 3 weeks
	SKIP2        = (1<<1),  // skip 2nd of every 3 weeks
	SKIP3        = (1<<2),  // skip 3rd of every 3 weeks
	BINARY       = (1<<3),  // trade binary options - also for optionVal
	PRELOAD      = (1<<4),  // load prices from historical data
	PLOTNOW      = (1<<5),  // create a chart automatically after test
	PLOTLONG     = (1<<7),  // moved to PlotMode
	LOGFILE      = (1<<8),  // store log file - also for assetHistory
	LOGMSG       = (1<<9),  // moved to Verbose
	LEAN         = (1<<10), // don't use historical volume & spread data
	EXE          = (1<<11), // generate EXE (Zorro S)
	RULES        = (1<<12), // generate/use advise rules
	FACTORS      = (1<<13), // generate reinvestment factors
	PARAMETERS   = (1<<14), // generate/use strategy parameters
	OPENEND      = (1<<15), // ignore open trades at the end of the test
	PEEK         = (1<<16), // allow peeking into the future
	RISKLIMIT    = (1<<17), // don't trade when trade risk > 2*Risk
	MARGINLIMIT  = (1<<18), // don't trade when real margin > 2*calculated margin, or when total margin left < 1000
	ACCUMULATE   = (1<<19), // accumulate Margin for skipped trades
	TESTNOW      = (1<<20), // run a test automatically after training
	RECALCULATE  = (1<<21), // recreate series after parameter loading
	NOLOCK       = (1<<23), // don't sychronize API access
	FAST         = (1<<24), // ticks in FAST mode - also for advise()
	NFA          = (1<<25), // NFA compliant account: no "hard" stop loss, no hedging, no position closing
	SCREENSAVER  = (1<<26), // don't suspend power management 
	TICKS        = (1<<27), // simulate trades every tick (slow)
	BALANCE      = (1<<28), // store and display balance rather than equity curves
	STEPWISE     = (1<<29), // stepwise debugging (Zorro S)
	ALLCYCLES    = (1<<30), // sum up statistics over all sample cycles
ZORRO_ENUM_CLOSE(EZorroFlag)
ZORRO_BUILD_ENUM_BIT_OPERATORS(EZorroFlag)
typedef CBitfield<EZorroFlag, int> TZorroBitfield;

ZORRO_ENUM_OPEN(EStatusFlag)
	TRADING      = (1<<0),  // trades have been opened
	CHANGED      = (1<<1),  // script or asset was changed -> init strategy sliders
	INITRUN      = (1<<2),  // init run before the first bar, for initialization
	EXITRUN      = (1<<3),  // last bar, all trades are closed, for result calculation
	TESTMODE     = (1<<4),  // [Test] mode
	TRAINMODE    = (1<<5),  // [Train] mode, for optimizing
	TRADEMODE    = (1<<6),  // [Trade] mode
	DEMO         = (1<<7),  // Running on demo account
	LOOKBACK     = (1<<8),  // Lookback period, no trading
	FIRSTRUN     = (1<<9),  // First run with valid price data, usually on bar 1
	COMMAND      = (1<<10), // Zorro started from the command line
	EXE          = (1<<11), // see above, script is executable (*.x)
	RULES        = (1<<12), // generate/use advise rules
	FACTORS      = (1<<13), // generate reinvestment factors
	PARAMETERS   = (1<<14), // generate/use strategy parameters
	CONTRACTS    = (1<<15), // contracts are traded
	PORTFOLIO    = (1<<16), // assetList() or loop() function called
	ASSETS       = (1<<17), // asset() function called
	SELECTED     = (1<<18), // asset is same as [Asset] Scrollbox (not in loops)
	PLOTSTATS    = (1<<19), // plot histogram rather than price chart
	AFFIRMED     = (1<<20), // [Ok] clicked on nonmodal message box
	SPECIALBAR   = (1<<21), // user-defined bar length
	MARGINCALL   = (1<<22), // Margin + Loss exceeds Capital
	NEWDAY       = (1<<23), // Day change after last bar 
	PROCESS      = (1<<24), // ReTrain or ReTest
	SPONSORED    = (1<<25), // Zorro S version
	RUNNING      = (1<<26), // Simulation is running
	FIRSTINITRUN = (1<<27), // Really first run
	SHORTING     = (1<<28), // Short trades have been opened
ZORRO_ENUM_CLOSE(EStatusFlag)
ZORRO_BUILD_ENUM_BIT_OPERATORS(EStatusFlag)
typedef CBitfield<EStatusFlag, int> TStatusBitfield;

ZORRO_ENUM_OPEN(EOrderFillMode)
	NAIVE        = 0,
	ATCLOSE      = 1,
	DELAYED      = 3,
	HFT          = 8,
ZORRO_ENUM_CLOSE(EOrderFillMode)

ZORRO_ENUM_OPEN(EVerbosity)
	LEVEL_0      = 0,
	LEVEL_1      = 1,
	LEVEL_2      = 2,
	LEVEL_3      = 3,
	LEVEL_7      = 7,
	DIAG         = (1<<3),
	ALERT        = (1<<4),
	LOGMSG       = static_cast<int>(EZorroFlag::LOGMSG), // show log in message window
ZORRO_ENUM_CLOSE(EVerbosity)
ZORRO_BUILD_ENUM_BIT_OPERATORS(EVerbosity)
typedef CBitfield<EVerbosity, int> TVerbosityBitfield;

ZORRO_ENUM_OPEN(EAdviseMode)
	PREVIOUS     = 0,       // use the method and signals of the last advise call
	PATTERNS_2   = 2,       // number of pattern groups
	PATTERNS_3   = 3,
	PATTERNS_4   = 4,
	PATTERNS_5   = 5,
	PATTERNS_6   = 6,
	NEURAL       = (1<<20), // use external AI
	DTREE        = (1<<21), // use a decision tree
	PERCEPTRON   = (1<<22), // use a perceptron
	PATTERN      = (1<<23), // use pattern match
	FAST         = (1<<24), // match fast
	FUZZY        = (1<<25), // match fuzzy
	SIGNALS      = (1<<26), // export signals + objective to .csv
	BALANCED     = (1<<28), // balance positive and negative results
ZORRO_ENUM_CLOSE(EAdviseMode)
ZORRO_BUILD_ENUM_BIT_OPERATORS(EAdviseMode)
typedef CBitfield<EAdviseMode, int> TAdviseModeBitfield;

ZORRO_ENUM_OPEN(ENeuralMode)
	NEURAL_INIT    = (1<<20),
	NEURAL_EXIT    = (2<<20),
	NEURAL_LEARN   = (4<<20),
	NEURAL_TRAIN   = (5<<20),
	NEURAL_PREDICT = (8<<20),
	NEURAL_SAVE    = (16<<20),
	NEURAL_LOAD    = (17<<20),
ZORRO_ENUM_CLOSE(ENeuralMode)
ZORRO_BUILD_ENUM_BIT_OPERATORS(ENeuralMode)
typedef CBitfield<ENeuralMode, int> TNeuralModeBitfield;

ZORRO_ENUM_OPEN(EPredictionType)
	CROSSOVER  = (1<<21),
	PEAK       = (1<<22),
	VALLEY     = (1<<23),
	PARABOLIC  = (1<<20),
ZORRO_ENUM_CLOSE(EPredictionType)
ZORRO_BUILD_ENUM_BIT_OPERATORS(EPredictionType)
typedef CBitfield<EPredictionType, int> TPredictionTypeBitfield;

ZORRO_ENUM_OPEN(EHistoryMode)
	UNADJUSTED_BROKER_T1 = 0,
	UNADJUSTED_BROKER_M1 = 1,
	UNADJUSTED  = (1<<9),
	FOR_ASSET   = (1<<10),
	IMMEDIATE   = (1<<11),
	FROM_YAHOO  = (1<<12),
	FROM_QUANDL = (1<<13),
	FROM_GOOGLE = (1<<14),
	FROM_AV     = (1<<15),
	FROM_STOOQ  = (1<<16),
	FROM_QTABLE = (1<<17),
ZORRO_ENUM_CLOSE(EHistoryMode)
ZORRO_BUILD_ENUM_BIT_OPERATORS(EHistoryMode)
typedef CBitfield<EHistoryMode, int> THistoryModeBitfield;

ZORRO_ENUM_OPEN(EAssetType)
	FOREX     = 1,
	INDEX     = 2,
	CMDTY     = 3,
	STOCK     = 4,
	BOND      = 5,
ZORRO_ENUM_CLOSE(EAssetType)

ZORRO_ENUM_OPEN(EDetrendMode)
	TRADES    = (1<<0),
	PRICES    = (1<<1),
	CURVE     = (1<<2),
	INVERT    = (1<<3),
	NOPRICE   = (1<<4),
	SHUFFLE   = (1<<5),
ZORRO_ENUM_CLOSE(EDetrendMode)
ZORRO_BUILD_ENUM_BIT_OPERATORS(EDetrendMode)
typedef CBitfield<EDetrendMode, int> TDetrendModeBitfield;

ZORRO_ENUM_OPEN(ERandomizeMode)
	DETREND   = (1<<2),
	BOOTSTRAP = (1<<6),
ZORRO_ENUM_CLOSE(ERandomizeMode)
ZORRO_BUILD_ENUM_BIT_OPERATORS(ERandomizeMode)
typedef CBitfield<ERandomizeMode, int> TRandomizeModeBitfield;

ZORRO_ENUM_OPEN(EOptimizeMode)
	LUCKY     = (1<<8),
	PHANTOM   = (1<<16),
	PEAK      = (1<<22),
ZORRO_ENUM_CLOSE(EOptimizeMode)
ZORRO_BUILD_ENUM_BIT_OPERATORS(EOptimizeMode)
typedef CBitfield<EOptimizeMode, int> TOptimizeModeBitfield;

ZORRO_ENUM_OPEN(ETimeZone)
	UTC       = 24, // Coordinated Universal Time
	WET       =  0, // Western European Time (London)
	CET       =  1, // European time zone (Frankfurt)
	ET        = -5, // Eastern Time (New York)
	JST       =  9, // Japan Standard Time (Tokyo)
	AEST      = 10, // Australian Eastern Standard Time (Sydney)
ZORRO_ENUM_CLOSE(ETimeZone)

ZORRO_ENUM_OPEN(EWeekday)
	MONDAY    = 1,
	TUESDAY   = 2,
	WEDNESDAY = 3,
	THURSDAY  = 4,
	FRIDAY    = 5,
	SATURDAY  = 6,
	SUNDAY    = 7,
ZORRO_ENUM_CLOSE(EWeekday)

ZORRO_ENUM_OPEN(EPlotType)
	REGULAR   = 0,
	NEW       = (1<<0),  // begin new chart
	BARS      = (1<<1),  // bars instead of curves
	BAND1     = (1<<2),  // upper band
	BAND2     = (BAND1+1), // lower band
	MAIN      = (1<<3),  // print in main window
	STATS     = (1<<4),  // print histogram
	AXIS2     = (1<<5),  // plot on 2nd axis
	SUM       = (1<<6),  // add values; fill skipped bars
	AVG       = (1<<7),  // calculate average
	LOG       = (1<<8),  // use logarithmic scale
	DEV       = (1<<9),  // calculate standard deviation
	NRM       = (1<<10), // normalize to 1
	MINV      = (1<<12), // plot the bar minimum
	MAXV      = (1<<13), // plot the bar maximum
	DEL       = (1<<14), // delete the previous plot and start over
	LBL2      = (1<<15), // label only even bars
	GRAPH     = (1<<16), // plot line/dot graph
	LINE      = (1<<17), // plot a straight line
	END       = (1<<18), // line end point
	DOT       = (1<<19), // plot a colored dot
	SQUARE    = (DOT+(1<<20)),
	DIAMOND   = (DOT+(2<<20)),
	TRIANGLE  = (DOT+(3<<20)),
	TRIANGLE2 = (DOT+(4<<20)),
	TRIANGLE3 = (DOT+(5<<20)),
	TRIANGLE4 = (DOT+(6<<20)),
	CROSS     = (DOT+(8<<20)),
	CROSS2    = (DOT+(9<<20)),
ZORRO_ENUM_CLOSE(EPlotType)
ZORRO_BUILD_ENUM_BIT_OPERATORS(EPlotType)
typedef CBitfield<EPlotType, int> TPlotTypeBitfield;

ZORRO_ENUM_OPEN(EPlotMode)
	PL_ALL    = (1<<6),
	PL_LONG   = (1<<7),
	PL_FINE   = (1<<8),
ZORRO_ENUM_CLOSE(EPlotMode)
ZORRO_BUILD_ENUM_BIT_OPERATORS(EPlotMode)
typedef CBitfield<EPlotMode, int> TPlotModeBitfield;

const color_t RED       = 0xff0000;
const color_t GREEN     = 0x00ff00;
const color_t BLUE      = 0x0000ff;
const color_t CYAN      = 0x00ffff;
const color_t DARKBLUE  = 0x0000a0;
const color_t LIGHTBLUE = 0xadd8e6;
const color_t PURPLE    = 0x800080;
const color_t YELLOW    = 0xffff00;
const color_t MAGENTA   = 0xff00ff;
const color_t ORANGE    = 0xffa500;
const color_t DARKGREEN = 0x008000;
const color_t OLIVE     = 0x808000;
const color_t MAROON    = 0x800000;
const color_t SILVER    = 0xc0c0c0;
const color_t GREY      = 0x808080;
const color_t BLACK     = 0x010101;
const color_t LIGHT     = 0x606060;
const color_t TRANSP    = 0x80000000;

ZORRO_ENUM_OPEN(EPrintMode)
	TO_WINDOW =  1,
	TO_LOG    =  2,
	TO_DIAG   =  3,
	TO_REPORT =  4,
	TO_HTML   =  5,
	TO_FILE   =  6,
	TO_CSV    = 10,
	TO_CSVHDR = 11,
	TO_ALERT  = 13,
	TO_TITLE  = 16,
	TO_INFO   = 17,
	TO_PANEL  = 18,
	TRAINMODE = static_cast<int>(EStatusFlag::TRAINMODE),
	TO_ANY    = (TO_WINDOW + TRAINMODE),
ZORRO_ENUM_CLOSE(EPrintMode)

ZORRO_ENUM_OPEN(ESaveMode)
	TRADES    = (1<<0),
	SLIDERS   = (1<<1),
	ALGOVARS  = (1<<2),
	BACKUP    = (1<<8),
	HTML      = (1<<9),
ZORRO_ENUM_CLOSE(ESaveMode)
ZORRO_BUILD_ENUM_BIT_OPERATORS(ESaveMode)
typedef CBitfield<ESaveMode, int> TSaveModeBitfield;

ZORRO_ENUM_OPEN(EBrokerCmd)
	GET_TIME           =  5,  // brokerCommand, last incoming tick time
	GET_DIGITS         = 12, // Count of digits after decimal point 
	GET_STOPLEVEL      = 14, // Stop level in points.
	GET_STARTING       = 20, // Market starting date (usually used for futures).
	GET_EXPIRATION     = 21, // Market expiration date (usually used for futures).
	GET_TRADEALLOWED   = 22, // Trade is allowed for the symbol.
	GET_MINLOT         = 23, // Minimum permitted amount of a lot.
	GET_LOTSTEP        = 24, // Step for changing lots.
	GET_MAXLOT         = 25, // Maximum permitted amount of a lot.
	GET_MARGININIT     = 29, // Initial margin requirements for 1 lot.
	GET_MARGINMAINTAIN = 30, // Margin to maintain open positions calculated for 1 lot.
	GET_MARGINHEDGED   = 31, // Hedged margin calculated for 1 lot.
	GET_MARGINREQUIRED = 32, // Free margin required to open 1 lot for buying.
	GET_DELAY          = 41,
	GET_WAIT           = 42,
	GET_TYPE           = 50, // Asset type. 
	GET_COMPLIANCE     = 51, // NFA compliance.
	GET_NTRADES        = 52, // Number of open trades
	GET_POSITION       = 53, // Open net lots per asset 
	GET_ACCOUNT        = 54, // Account number (string)
	GET_BOOKASKS       = 60, // Ask volume in the order book
	GET_BOOKBIDS       = 61, // Bid volume in the order book
	GET_BOOKPRICE      = 62, // Price quote per price rank
	GET_BOOKVOL        = 63, // Volume per price rank
	GET_OPTIONS        = 64, // Option chain
	GET_FUTURES        = 65,
	GET_FOP            = 66,
	GET_UNDERLYING     = 67,

	SET_PATCH          = 128, // Work around broker API bugs
	SET_SLIPPAGE       = 129, // Max adverse slippage for orders
	SET_MAGIC          = 130, // Magic number for trades
	SET_ORDERTEXT      = 131, // Order comment for trades
	SET_SYMBOL         = 132, // set asset symbol for subsequent commands
	SET_MULTIPLIER     = 133, // set option/future multiplier filter
	SET_CLASS          = 134, // set trading class filter
	SET_LIMIT          = 135, // set limit price for entry limit orders
	SET_HISTORY        = 136, // set file name for direct history download
	SET_COMBO_LEGS     = 137, // declare the next n trades as an option combo
	SET_DIAGNOSTICS    = 138, // activate plugin diagnostics output
	SET_DELAY          = 169,
	SET_WAIT           = 170,
	SET_LOCK           = 171,
	SET_COMMENT        = 180, // Comment on the chart
	DO_EXERCISE        = 300, // exercise option

	PLOT_STRING        = 188, // send a string to a plot object
	PLOT_REMOVE        = 260,
	PLOT_REMOVEALL     = 261,
	PLOT_HLINE         = 280, // plot to the MT4 chart window
	PLOT_TEXT          = 281,
	PLOT_MOVE          = 282,
ZORRO_ENUM_CLOSE(EBrokerCmd)

ZORRO_ENUM_OPEN(EContractType)
	CALL      = (1<<0),
	PUT       = (1<<1),
	EUROPEAN  = (1<<2),
	BINARY    = (1<<3),
	FUTURE    = (1<<5),
	ONLYMATCH = (1<<6), // select only contracts that exactly match the parameters 
	ONLYW3    = (1<<7), // select only contracts in 3rd week
	OPTION    = (CALL | PUT | EUROPEAN),
ZORRO_ENUM_CLOSE(EContractType)
ZORRO_BUILD_ENUM_BIT_OPERATORS(EContractType)
typedef CBitfield<EContractType, int> TContractTypeBitfield;

ZORRO_ENUM_OPEN(EMovingAverageType)
	SMA       = 0,
	EMA       = 1,
	WMA       = 2,
	DEMA      = 3,
	TEMA      = 4,
	TRIMA     = 5,
	KAMA      = 6,
	MAMA      = 7,
	T3        = 8,
ZORRO_ENUM_CLOSE(EMovingAverageType)

#define NO_DEFINES
#include "trading.h"
#undef NO_DEFINES

inline var me(mat M, int row, int col)
{
	return *(M->dat + row*M->cols + col);
}

inline var ve(mat M, int n)
{
	return *(M->dat + n);
}

#undef ZORRO_ENUM_OPEN
#undef ZORRO_ENUM_CLOSE
