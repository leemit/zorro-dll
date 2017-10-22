//////////////////////////////////////////////////////////////////////
// Zorro-specific variables & functions
// for use by lite-C scripts & Zorro program
// (c) oP group 2013, 2017
//////////////////////////////////////////////////////////////////////
#ifndef trading_h
#define trading_h

#include "trading_types.h"

#define SCRIPT_VERSION	255

#define and &&
#define or  ||
#define not !
#define as_int(x) *((int*)&(x))
#define PI  3.14159265359
#define NIL 3e38

#define me(pMatrix,row,col) *(pMatrix->dat + row*pMatrix->cols + col)
#define ve(pMatrix,n)       *(pMatrix->dat+n)

#define TR_SHORT       (1<<0)  // short position
#define TR_BID         (1<<0)
#define TR_OPEN        (1<<1)  // position is open
#define TR_NOTFOUND    (1<<2)  // trade disappeared from the broker list
#define TR_EXPIRED     (1<<3)  // option or future expired
#define TR_WAITSELL    (1<<4)  // close position at the next tick
#define TR_WAITBUY     (1<<5)  // open position at the next tick
#define TR_DETREND     (1<<6)  // detrend the trade result
#define TR_SUSPEND     (1<<7)  // suspend trade function
#define TR_EVENT       (1<<8)  // trade function was called by enter/exit event
#define TR_IGNORE      (1<<9)  // don't automatically enter/exit
#define TR_MISSEDENTRY (1<<10) // missed the entry limit or stop, or sell price in the last bar
#define TR_MISSEDEXIT  (1<<11) // missed the exit for some reason
#define TR_NOSIZE      (1<<12) // Trade not executed, not enough lots or balance
#define TR_RECYCLE     (1<<13) // Trade struct can be reused
#define TR_NONET       (1<<14) // Don't open a net trade yet
#define TR_NET         (1<<15) // Pool trade
#define TR_PHANTOM     (1<<16) // Phantom trade 
#define TR_EXERCISE    (1<<17) // exercise an option contract
#define TR_STOPPED     (1<<18) // closed due to stop loss in the last bar, or a margin call
#define TR_PROFIT      (1<<19) // closed due to profit target in the last bar
#define TR_TIME        (1<<20) // closed due to timeout in the last bar
#define TR_SOLD        (1<<21) // closed due to exit at market in the last bar
#define TR_CANCELLED   (1<<22) // removed from trade list
#define TR_MISSEDOPEN  (1<<23) // could not be opened by the broker
#define TR_ACCOUNT     (1<<24) // trade with the main account
#define TR_ENTRYSTOP   (1<<25) // entry stop, rather than limit
#define TR_ENTER       (1<<26) // entered by TMF return value
#define TR_EXIT        (1<<27) // exit by TMF return value
#define TR_REMOVED     (1<<28) // removed from the online trade list (f.i. margin call or manually closed)
#define TR_BAR         (1<<29) // run TMF on any bar only, not any tick
#define TR_REVERSED    (1<<30) // indicate exit by reversal (shared with TR_EXIT)
#define TR_NEW         (1<<31) // just created in a TMF 

// mode switches
#define SKIP1        (1<<0)  // skip 1st of every 3 weeks
#define SKIP2        (1<<1)  // skip 2nd of every 3 weeks
#define SKIP3        (1<<2)  // skip 3rd of every 3 weeks
#define BINARY       (1<<3)  // trade binary options - also for optionVal
#define PRELOAD      (1<<4)  // load prices from historical data
#define PLOTNOW      (1<<5)  // create a chart automatically after test
//#define EXTRADATA  (1<<6)  // unused
#define PLOTLONG     (1<<7)  // moved to PlotMode
#define LOGFILE      (1<<8)  // store log file - also for assetHistory
//#define LOGMSG     (1<<9)  // moved to Verbose
#define LEAN         (1<<10) // don't use historical volume & spread data
#define EXE          (1<<11) // generate EXE (Zorro S)
#define RULES        (1<<12) // generate/use advise rules
#define FACTORS      (1<<13) // generate reinvestment factors
#define PARAMETERS   (1<<14) // generate/use strategy parameters
#define OPENEND      (1<<15) // ignore open trades at the end of the test
#define PEEK         (1<<16) // allow peeking into the future
#define RISKLIMIT    (1<<17) // don't trade when trade risk > 2*Risk
#define MARGINLIMIT  (1<<18) // don't trade when real margin > 2*calculated margin, or when total margin left < 1000
#define ACCUMULATE   (1<<19) // accumulate Margin for skipped trades
#define TESTNOW      (1<<20) // run a test automatically after training
#define RECALCULATE  (1<<21) // recreate series after parameter loading
//#define UNUSED     (1<<22) // 
#define NOLOCK       (1<<23) // don't sychronize API access
#define FAST         (1<<24) // ticks in FAST mode - also for advise()
#define NFA          (1<<25) // NFA compliant account: no "hard" stop loss, no hedging, no position closing
#define SCREENSAVER  (1<<26) // don't suspend power management 
#define TICKS        (1<<27) // simulate trades every tick (slow)
#define BALANCE      (1<<28) // store and display balance rather than equity curves
#define STEPWISE     (1<<29) // stepwise debugging (Zorro S)
#define ALLCYCLES    (1<<30) // sum up statistics over all sample cycles

// status flags
#define TRADING      (1<<0) // trades have been opened
#define CHANGED      (1<<1) // script or asset was changed -> init strategy sliders
#define INITRUN      (1<<2) // init run before the first bar, for initialization
#define EXITRUN      (1<<3) // last bar, all trades are closed, for result calculation
#define TESTMODE     (1<<4) // [Test] mode
#define TRAINMODE    (1<<5) // [Train] mode, for optimizing
#define TRADEMODE    (1<<6) // [Trade] mode
#define DEMO         (1<<7) // Running on demo account
#define LOOKBACK     (1<<8) // Lookback period, no trading
#define FIRSTRUN     (1<<9) // First run with valid price data, usually on bar 1
#define COMMAND      (1<<10) // Zorro started from the command line
//#define EXE        (1<<11)  see above, script is executable (*.x)
//#define RULES      (1<<12) // generate/use advise rules
//#define FACTORS    (1<<13) // generate reinvestment factors
//#define PARAMETERS (1<<14) // generate/use strategy parameters
#define CONTRACTS    (1<<15) // contracts are traded
#define PORTFOLIO    (1<<16) // assetList() or loop() function called
#define ASSETS       (1<<17) // asset() function called
#define SELECTED     (1<<18) // asset is same as [Asset] Scrollbox (not in loops)
#define PLOTSTATS    (1<<19) // plot histogram rather than price chart
#define AFFIRMED     (1<<20) // [Ok] clicked on nonmodal message box
#define SPECIALBAR   (1<<21) // user-defined bar length
#define MARGINCALL   (1<<22) // Margin + Loss exceeds Capital
#define NEWDAY       (1<<23) // Day change after last bar 
#define PROCESS      (1<<24) // ReTrain or ReTest
#define SPONSORED    (1<<25) // Zorro S version
#define RUNNING      (1<<26) // Simulation is running
#define FIRSTINITRUN (1<<27) // Really first run
#define SHORTING     (1<<28) // Short trades have been opened

// defines for functions and parameters
#define ALL       "*"   // all algos, all trades etc.
#define NOW       -999999
#define NAIVE     0
#define ATCLOSE   1
#define DELAYED   3
#define HFT       8
#define DIAG      8
#define UPDATE    (1<<5)
#define ALERT     (1<<4)
#define LOGMSG    (1<<9) // show log in message window

#define NEURAL     (1<<20) // use external AI
#define DTREE      (1<<21) // use a decision tree
#define PERCEPTRON (1<<22) // use a perceptron
#define PATTERN    (1<<23) // use pattern match
//#define FAST     (1<<24) // match fast
#define FUZZY      (1<<25) // match fuzzy
#define SIGNALS    (1<<26) // export signals + objective to .csv
#define BALANCED   (1<<28) // balance positive and negative results

#define NEURAL_INIT    (1<<20) // neural function modes
#define NEURAL_EXIT    (2<<20)
#define NEURAL_LEARN   (4<<20)
#define NEURAL_TRAIN   (5<<20)
#define NEURAL_PREDICT (8<<20)
#define NEURAL_SAVE    (16<<20)
#define NEURAL_LOAD    (17<<20)

#define CROSSOVER  (1<<21)
#define PEAK       (1<<22) // also for Optimize
#define VALLEY     (1<<23)
#define PARABOLIC  (1<<20)

#define UNADJUSTED  (1<<9)
#define FOR_ASSET   (1<<10)
#define IMMEDIATE   (1<<11)
#define FROM_YAHOO  (1<<12)
#define FROM_QUANDL (1<<13)
#define FROM_GOOGLE (1<<14)
#define FROM_AV     (1<<15)
#define FROM_STOOQ  (1<<16)
#define FROM_QTABLE (1<<17)

#define FOREX  1
#define INDEX  2 // stock index
#define CMDTY  3
#define STOCK  4
#define BOND   5

#define TRADES    (1<<0) // Detrend + randomize + Optimize settings
#define PRICES    (1<<1) 
#define CURVE     (1<<2)
#define DETREND   (1<<2)
#define INVERT    (1<<3)
#define NOPRICE   (1<<4)
#define SHUFFLE   (1<<5)
#define BOOTSTRAP (1<<6)
#define LUCKY     (1<<8)
#define PHANTOM   (1<<16)
//#define PEAK    (1<<22)

#define UTC  24 // Coordinated Universal Time
#define WET  0  // Western European Time (London)
#define CET  1  // European time zone (Frankfurt)
#define ET   -5 // Eastern Time (New York)
#define JST  9  // Japan Standard Time (Tokyo)
#define AEST 10 // Australian Eastern Standard Time (Sydney)

#define MONDAY    1
#define TUESDAY   2
#define WEDNESDAY 3
#define THURSDAY  4
#define FRIDAY    5
#define SATURDAY  6
#define SUNDAY    7

#define NEW       (1<<0)  // begin new chart
#define BARS      (1<<1)  // bars instead of curves
#define BAND1     (1<<2)  // upper band
#define BAND2     (BAND1+1) // lower band
#define MAIN      (1<<3)  // print in main window
#define STATS     (1<<4)  // print histogram
#define AXIS2     (1<<5)  // plot on 2nd axis
#define SUM       (1<<6)  // add values; fill skipped bars
#define AVG       (1<<7)  // calculate average
#define LOG       (1<<8)  // use logarithmic scale
#define DEV       (1<<9)  // calculate standard deviation
#define NRM       (1<<10) // normalize to 1
#define MINV      (1<<12) // plot the bar minimum
#define MAXV      (1<<13) // plot the bar maximum
#define DEL       (1<<14) // delete the previous plot and start over
#define LBL2      (1<<15) // label only even bars
#define GRAPH     (1<<16) // plot line/dot graph
#define LINE      (1<<17) // plot a straight line
#define END       (1<<18) // line end point
#define DOT       (1<<19) // plot a colored dot
#define SQUARE    (DOT+(1<<20))
#define DIAMOND   (DOT+(2<<20))
#define TRIANGLE  (DOT+(3<<20))
#define TRIANGLE2 (DOT+(4<<20))
#define TRIANGLE3 (DOT+(5<<20))
#define TRIANGLE4 (DOT+(6<<20))
#define CROSS     (DOT+(8<<20))
#define CROSS2    (DOT+(9<<20))

#define PL_ALL  (1<<6)
#define PL_LONG (1<<7)
#define PL_FINE (1<<8)

#define RED       0xff0000ul
#define GREEN     0x00ff00ul
#define BLUE      0x0000fful
#define CYAN      0x00fffful
#define DARKBLUE  0x0000a0ul
#define LIGHTBLUE 0xadd8e6ul
#define PURPLE    0x800080ul
#define YELLOW    0xffff00ul
#define MAGENTA   0xff00fful
#define ORANGE    0xffa500ul
#define DARKGREEN 0x008000ul
#define OLIVE     0x808000ul
#define MAROON    0x800000ul
#define SILVER    0xc0c0c0ul
#define GREY      0x808080ul
#define BLACK     0x010101ul
#define LIGHT     0x606060ul
#define TRANSP    0x80000000ul

#define TO_WINDOW 1 // print channels
#define TO_LOG    2
#define TO_DIAG   3
#define TO_REPORT 4
#define TO_HTML   5
#define TO_FILE   6
#define TO_CSV    10
#define TO_CSVHDR 11
#define TO_ALERT  13
#define TO_TITLE  16
#define TO_INFO   17
#define TO_PANEL  18
#define TO_ANY    (TO_WINDOW+TRAINMODE)

#define SV_TRADES   (1<<0) // save modes
#define SV_SLIDERS  (1<<1)
#define SV_ALGOVARS (1<<2)
#define SV_BACKUP   (1<<8)
#define SV_HTML     (1<<9)

#define GET_TIME            5 // brokerCommand, last incoming tick time
#define GET_DIGITS         12 // Count of digits after decimal point 
#define GET_STOPLEVEL      14 // Stop level in points.
#define GET_STARTING       20 // Market starting date (usually used for futures).
#define GET_EXPIRATION     21 // Market expiration date (usually used for futures).
#define GET_TRADEALLOWED   22 // Trade is allowed for the symbol.
#define GET_MINLOT         23 // Minimum permitted amount of a lot.
#define GET_LOTSTEP        24 // Step for changing lots.
#define GET_MAXLOT         25 // Maximum permitted amount of a lot.
#define GET_MARGININIT     29 // Initial margin requirements for 1 lot.
#define GET_MARGINMAINTAIN 30 // Margin to maintain open positions calculated for 1 lot.
#define GET_MARGINHEDGED   31 // Hedged margin calculated for 1 lot.
#define GET_MARGINREQUIRED 32 // Free margin required to open 1 lot for buying.
#define GET_DELAY          41
#define GET_WAIT           42
#define GET_TYPE           50 // Asset type. 
#define GET_COMPLIANCE     51 // NFA compliance.
#define GET_NTRADES        52 // Number of open trades
#define GET_POSITION       53 // Open net lots per asset 
#define GET_ACCOUNT        54 // Account number (string)
#define GET_BOOKASKS       60 // Ask volume in the order book
#define GET_BOOKBIDS       61 // Bid volume in the order book
#define GET_BOOKPRICE      62 // Price quote per price rank
#define GET_BOOKVOL        63 // Volume per price rank
#define GET_OPTIONS        64 // Option chain
#define GET_FUTURES        65
#define GET_FOP            66
#define GET_UNDERLYING     67

#define SET_PATCH         128 // Work around broker API bugs
#define SET_SLIPPAGE      129 // Max adverse slippage for orders
#define SET_MAGIC         130 // Magic number for trades
#define SET_ORDERTEXT     131 // Order comment for trades
#define SET_SYMBOL        132 // set asset symbol for subsequent commands
#define SET_MULTIPLIER    133 // set option/future multiplier filter
#define SET_CLASS         134 // set trading class filter
#define SET_LIMIT         135 // set limit price for entry limit orders
#define SET_HISTORY       136 // set file name for direct history download
#define SET_COMBO_LEGS    137 // declare the next n trades as an option combo
#define SET_DIAGNOSTICS   138 // activate plugin diagnostics output
#define SET_DELAY         169
#define SET_WAIT          170
#define SET_LOCK          171
#define SET_COMMENT       180 // Comment on the chart
#define DO_EXERCISE       300 // exercise option

#define PLOT_STRING       188 // send a string to a plot object
#define PLOT_REMOVE       260
#define PLOT_REMOVEALL    261
#define PLOT_HLINE        280 // plot to the MT4 chart window
#define PLOT_TEXT         281
#define PLOT_MOVE         282

#define CALL       (1<<0) // options
#define PUT        (1<<1)
#define EUROPEAN   (1<<2)
//#define BINARY 8 // shared with MODE()
#define FUTURE     (1<<5)
#define ONLYMATCH  (1<<6) // select only contracts that exactly match the parameters 
#define ONLYW3     (1<<7) // select only contracts in 3rd week
#define OPTION     (CALL|PUT|EUROPEAN)

#define MAType_SMA   0 // Types of Moving Average
#define MAType_EMA   1
#define MAType_WMA   2
#define MAType_DEMA  3
#define MAType_TEMA  4
#define MAType_TRIMA 5
#define MAType_KAMA  6
#define MAType_MAMA  7
#define MAType_T3    8

#define PERIOD_MS1 0.001/60.0
#define PERIOD_S1  1.0/60.0
#define PERIOD_M1  1.0
#define PERIOD_M5  5.0
#define PERIOD_M15 15.0
#define PERIOD_M30 30.0
#define PERIOD_H1  60.0
#define PERIOD_H4  240.0
#define PERIOD_D1  1440.0
#define PERIOD_W1  10080.0
#define PERIOD_MN1 43200.0

#define HEDGE_NONE            0 // no hedging; automatically close opposite positions with the same asset when a new position is opened (default for NFA accounts).
#define HEDGE_ALLOW_ALGO      1 // hedging across algos; automatically close opposite positions with the same algo when a new position is opened (default for unspecified accounts).
#define HEDGE_ALLOW_ANY       2 // full hedging; long and short positions can be open at the same time.
#define HEDGE_VIRTUAL         4 // virtual hedging without partial closing; enter long and short positions simultaneously, but send only the net amount to the broker.
#define HEDGE_PARTIAL_VIRTUAL 5 // virtual hedging with partial closing; open positions are partially closed to match the net amount. 

#define TRADE_DIR_UP    1
#define TRADE_DIR_DOWN -1

#endif // trading_h
