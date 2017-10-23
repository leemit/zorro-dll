
#ifndef trading_types_h
#define trading_types_h

typedef double      var;
typedef var*        vars;
typedef const var*  cvars;
typedef const char* string;
typedef long        function;
#ifdef ZORRO_CPP
typedef const wchar_t* wstring;
#else
typedef const short* wstring;
typedef int ETradeFlag;
typedef int EZorroFlag;
typedef int EStatusFlag;
typedef int EOrderFillMode;
typedef int EVerbosity;
typedef int EAdviseMode;
typedef int ENeuralMode;
typedef int EPredictionType;
typedef int EHistoryMode;
typedef int EAssetType;
typedef int EDetrendMode;
typedef int ERandomizeMode;
typedef int ETrainFlag;
typedef int ETimeZone;
typedef int EWeekday;
typedef int EWeekendMode;
typedef int EPlotType;
typedef int EPlotMode;
typedef DWORD EColor;
typedef int EPrintMode;
typedef int ESaveMode;
typedef int EBrokerCmd;
typedef int EContractMode;
typedef int EContractType;
typedef int EMAType;
typedef int EHedgeMode;
typedef int ETradeDir;
#endif

typedef struct T1
{
	DATE  time; // time stamp, GMT
	float fVal; // positive for ask, negative for bid
} T1;           // single-stream tick, .t1 file content

typedef struct T2
{
	DATE  time; // timestamp in OLE date/time format
	float fVal; // price level, positive for ask and negative for bid
	float fVol; // volume
} T2;           // order book data

typedef struct THL
{
	DATE  time;
	float fHigh, fLow;
} THL; // two-stream tick, internal format

typedef struct T6
{
	DATE  time;
	float fHigh, fLow;   // (f1,f2)
	float fOpen, fClose; // (f3,f4)
	float fVal, fVol;    // optional data, like spread and volume (f5,f6)
} T6;                    // 6-stream tick, .t6 file content

typedef struct CONTRACT
{
	DATE  time;       // or trading class
	float fAsk, fBid; // premium without multiplier (f1,f2)
	float fVal;       // open interest or multiplier (f3)
	float fVol;       // volume (f4)
	float fUnl;       // unadjusted underlying price (f5)
	float fStrike;    // (f6)
	long  Expiry;     // YYYYMMDD (i7)
	long  Type;       // PUT, CALL, FUTURE, EUROPEAN, BINARY (s8)
} CONTRACT;           // for options, futures, FOPs

typedef struct TICK
{
	float fOpen, fClose;
	float fHigh, fLow;
	DATE  time; // time stamp, GMT
} TICK;         // .bar file content, outdated

typedef struct BAR
{
	DATE time_base,time_span; // start and duration of the bar in GMT time zone
} BAR;

typedef struct DATA
{
	int start,end; // first and last plotted data in the array
	var* Data;     // data array
} DATA;

typedef struct DATASET
{
	int    rows,cols; // records and fields
	int    allocrows; // allocated records, or 0
	float* fData;     // data array
} DATASET;

typedef struct MATRIX
{
	int rows,cols,total;
	var* dat;
} MATRIX;

typedef MATRIX* mat;

typedef struct ASSET
{
	var  vPrice;                 // last ask price
	var  vSpread;                // difference between ask and bid prices
	var  vRollLong,vRollShort;   // interest for short and long position rollover per 10K
	var  vPIP;                   // conversion factor Pip -> Price (0.0001 for most currencies, 1 for most CFDs)
	var  vPIPCost;               // cost of one Pip per lot, in account currency
	var  vMarginCost;            // broker's margin cost per lot (usually between 5 and 100), determining the leverage
	var  vLotAmount;             // number of contracts per lot
	char sName[NAMESIZE];        // short name of the asset
	var  *pOpen,*pClose,*pHigh,*pLow,*pPrice; // price history data array
	void **pTicks;               // tick pointer array, used for tick simulation in trade functions
	void *tick_start,*tick_end;  // tick list in THL or T6 format, dependent on LEAN
	int  nFirstPriceBar;         // first simulation bar for this asset
	int  nLastPriceBar;          // last simulation bar for this asset
	int  nBar,nCounter,nOffset;
	var  vBarAvg;                // Average price of one bar, intermediate value
	int  nMaxLots;               // Max # of lots per trade
	int  flags;
	int  nSkipped,nFrame;        // distance to the last bar with a price quote
	int  nNetSum,nPhantomSum;    // number of lots of all open trades
	int  nExtSum;                // number of lots of externally closed trades
	var  vFactor,vOffset;        // for normalizing price ticks
	var  vCommission;            // commission per 10K, in account currency
	var  Skill[NUM_SKILLS];      // asset-specific general purpose variables
	var  vSlipPerSec;            // price difference per second by slippage
	var  vBack[6];               // price backup for intrabar simulation
	var  vWinPayout,vLossPayout; // payouts in percent for binary trading
	int  nZone,nHour;            // asset time zone
	var  vLeverage;              // buying power
	char sSymbol[NAMESIZE2];     // long broker name of the asset
	var  vInitialPrice;          // from the asset parameters
	var  vStrength;              // currency strength difference
	var  vVal,vVol;              // volume data or quote frequencies
	var  *pVal,*pVol;            // additional price data lists, f.i. spread and volume
	CONTRACT *pContracts;        // contract chain
	int  numContracts;           // number of contracts
	int  nHandle;                // handle of options/futures dataset, + year <<16
	int  nPad;
	var  tAsk,tBid;              // time stamp of last quote
	int  nMultiplier;            // options multiplier
	int  nMarket;                // timezone for not trading outside market hours
	int  nSource;                // asset source flag, f.i. FROM_QUANDL
	char sSource[NAMESIZE];      // asset price source, if not the broker
	int  nContractRow,nContractOffs; // dataset numbers of the found contract
} ASSET;

// trade specific performance statistics (per lot)
typedef struct STATUS { 
	var    vSkippedMargin;   // margin accumulation of skipped trades
	var    vWin,vLoss;       // gross wins and losses
	var    vWinVal,vLossVal; // value of open trades, test/trade mode only
	var    vReturn2;         // sum of squared returns
	var    vWinMax,vLossMax; // largest win and loss
	var    vLossLotMax;      // largest loss per lot
	var    vWinStreakVal,vLossStreakVal; // size of current win/loss streak
	int    numWin,numLoss;         // number of won and lost trades 
	int    nWinStreak,nLossStreak; // length of current win and loss streak
	int    numWinning,numLosing;   // number of winning and losing open trades, test/trade mode only
	DWORD  dwWin,dwLoss;           // WFO win/loss flags 
	EColor dwColorWin,dwColorLoss; // trade colors in chart
								   // clear statistics until here
	EStatusFlag flags;
	int    nModel;        // model number for prediction
	int    nComponent;    // component number
	DWORD  pad[1];
	var    vPad[4];
	var    Skill[NUM_SKILLS];   // general purpose variables for money managemement
	var    Result[NUM_RESULTS]; // last 20 trade results
	char   sAlgo[NAMESIZE];     // algo identifier
								// save until here
	var    vTrainPF;      // training profit factor
	var    vOptimalF;     // component reinvestment factor, long/short
	var    vOptimalF2;    // OptimalF (short), R2 (long)
	var    vWFOProfit;    // profit of the current WFO cycle
	int    numPending;    // number of pending trades
	int    nBalance;      // net sign sum of advise objective
	int    numSignals;    // signals per rule
	void*  History;       // signal history for rule learning
	void*  Rule;          // pointer to tree or perceptron function
						  // clear again until here
	struct STATUS *other; // other status (short<->long)
	ASSET* asset;         // asset pointer
	int    nCycles;       // number of optimize cycles
	int    nSteps[MAX_PARAMS]; // list of optimize steps
	float  fParam[MAX_PARAMS]; // list of optimal parameters
	float* fStat;         // matrix of optimize results
	var*   pCurve;        // component equity/balance curve
} STATUS;

typedef struct TRADE
{
	float fEntryPrice;  // buy price, or premium without multiplicator
	float fExitPrice;   // sell price per unit, without spread
	float fResult;      // current profit of the trade
	float fEntryLimit;  // buy entry limit
	float fProfitLimit; // profit limit price
	float fTrailLock;   // profit target distance to initial price, positive (long) or negative (short)
	float fStopLimit;   // stop loss limit price
	float fStopDiff;    // signed stop loss distance to initial price, positive (short) or negative (long)
	float fTrailLimit;  // trail limit price
	float fTrailDiff;   // signed stop loss adaption distance, positive (short) or negative (long)
	float fTrailSlope;  // stop loss adaption factor, 0..1
	float fTrailStep;   // stop loss bar step factor, 0..1
	float fSpread;      // spread at entry for short, current spread for long trades
	float fMAE,fMFE;    // Max adverse excursion, max favorite excursion without slippage, spread etc.
	float fRoll;        // accumulated rollover, < 0
	float fSlippage;    // Slippage, < 0
	float fUnits;       // conversion factor from asset price to account money
	float fTrailSpeed;  // break even speed factor 
	int   nExitTime;    // sell at market after this number of bars
	int   nEntryTime;   // wait this number of bars for entry limit orders
	int   nLots;        // number of Lots. fUnits = nLots * vPIPCost/vPIP.
	int   nBarOpen;     // bar number of order and entry
	int   nBarClose;    // current bar number while open, otherwise exit bar number
	int   nID;          // active trade id, or 0 for pending trades; can change when trades are partially closed
	DATE  tEntryDate;   // entry time target
	DATE  tExitDate;    // exit time target
	ETradeFlag flags;   // trade flags, see below
	float fArg[8];      // TMF arguments
	var   Skill[NUM_SKILLS]; // general purpose variables for TMF
	EContractType nContract; // contract type & exchange code
	float fStrike;      // contract strike price
	float fUnl;         // contract underlying price, needed for futures
	char  sInfo[8];     // contract class
	float fMarginCost;  // used margin cost by the trade
						// saved until this element
	STATUS *status;     // trade STATUS 
	function manage;    // trade management function pointer
	var	*dSignals;      // pointer to advise parameters
	int	nCounter;       // for reducing BrokerTrade calls
	float fLastStop;    // for comparing the stop
	float fSimProfit;   // simulated profit, externally set 
} TRADE;

// overall performance statistics
typedef struct PERFORMANCE
{
	var vWin,vLoss;       // gross wins and losses
	var vPips;            // gross win-loss in pips
	var vWinMax,vLossMax; // largest win and loss
	var vDrawDown;        // maximum balance-equity drawdown 
	var vEquityDown;      // max equity drawdown
	var vCommissionCost;  // accumulated negative commissions
	var vPhantomWin,vPhantomLoss; // win/loss by virtual trades
	var vMarginMax;       // maximum margin 
	var vRiskMax;         // maximum risk 
	var vVolume;          // total trade volume
	var vObjective;       // result of objective function
	var vR2;              // coefficient of determination
	var vMean;            // average simple return per bar
	var vStdDev;          // standard deviation of simple returns
	var vUlcer;           // ulcer index; root of mean of squared drawdown percentages
	var vRollCost;        // accumulated rollover costs
	var vSlippageWin,vSlippageLoss;  // accumulated slippage costs
	var vSpreadCost;      // accumulated spread costs
	int numWin,numLoss;   // number of winning and losing trades 
	int numWinStreakMax;  // max number of consecutive wins
	int numLossStreakMax; // max number of consecutive losses
	int numMarketBars;    // number of bars with active trading
	int numDrawDownBars;  // number of bars in balance drawdown
	int numMAEBars;       // number of bars in equity drawdown
	int numDrawDownMax;   // max drawdown bars
	int numMarketWin,numMarketLoss; // bars in market of winning/losing trades
	int numMarketTotal;   // total number of bars in market
	int numTradeBarsMax;  // max length of trade
	long pad[16];
} PERFORMANCE;

// global variables
typedef struct GLOBALS
{
	// trade parameters (r/w)
	var vLots;       // number of lots to buy; 1 lot = minimum order amount = vPIPCost/vPIP contracts
	var vMargin;     // margin per trade; determines lots when nonzero
	var vRisk;       // risk limit per trade; limits lots according to from vStop
	var vCapital;    // initial capital for reinvesting strategies
	var vStop;       // stop loss - sell when the trade loses this amount 
	var vTrail;      // adapt stop loss when the trade wins this amount 
	var vTrailSlope; // move stop loss by this percentage of current trade profit
	var vTrailLock;  // lock this percentage of favorite excursion
	var vTrailStep;  // move stop loss every bar by this percentage of price-stop distance
	var vTakeProfit; // profit limit - sell when the trade goes your way by this amount 
	var vEntry;      // order entry - buy when the price rises or falls by this amount 
	var vEntryDelay;
	int nExitTime;   // sell at market after this number of bars
	int nEntryTime;  // wait this number of bars for entry limit orders

	EHedgeMode nHedge;   // hedging mode
	EVerbosity nVerbose; // verbosity level
	int nBoxState;       // external message box state
	int nLifeTime;       // trade duration in bars

	var vSlippage;   // simulated order execution delay in seconds (default = 0.5)
	var vBarPeriod;  // bar period in minutes, fractional

	var vRound;      // rounding factor, i.e 0.1 = round to the first decimal
	var vFuzzyRange; // for fuzzy logic
	var vFuzzyLevel; // for defuzzy

	int nGapDays;    // gap tolerance
	int nPad01;
	int nMonteCarlo; // Monte Carlo iterations
	int nConfidence; // Monte Carlo confidence level
	var vMCDrawDown; // Drawdown at confidence level

	var vStopFactor; // for sending the stop to the broker
	var vOrderLimit; // for sending limit orders to the broker
	var vTrailSpeed; // trail weight factor in percent
	var vAssetFactor,vAssetOffset;
	int numCores;    // multi-core training
	int nCore;       // current core, 1..numCores
	var vAdvise[2];  // advise parameters
	ETrainFlag nOptimize; // optimize mode
	EOrderFillMode nFill; // order fill mode
	int nTickSize;        // T6 or THL
	int nMinutesPerDay;   // minimum trading time per day, default = 60*6*5/7 ~ 256
	DATE tNow;            // for time/date functions
	var vSpreadFactor;    // 0.5 = open at mid price
	int nStartMarket,nEndMarket; // market hours
	int nMaxLong,nMaxShort;      // limits to number of long/short trades
	var vCBIScale;   // scale factor for CBI depth
	int nLogNumber;  // append this number to log files.
	ETradeFlag nTradeMode;  // TR_BROKER2,TR_PHANTOM
	long pad1[12];

	// simulation performance (r/o)
	STATUS *statLong,*statShort; // component statistics, set up by asset() and algo()
	PERFORMANCE w;        // overall win and loss statistics
	int numTradesMax;     // max number of concurrent trades
	var vBalancePeak;     // current balance peak
	var vEquityPeak,vEquityValley; // current equity peak and subsequent valley
	var vEquityMin;       // not used
	int nBalancePeakBar;  // and their bar numbers
	int nEquityPeakBar,nEquityValleyBar; 
	int nDnMaxBar;        // bar number of the longest down time 
	int nWinStreak,nLossStreak; // number of consecutive wins / losses
	var vWinStreakVal,vLossStreakVal; // size of current win/loss streak
	var vMarginAvg;       // average margin
	var tTimestamp;       // of last price quote
	var tTimeNext;        // next bar increase  
	var vBarRange;        // sum of all price movements
	long pad11[14];

	// account situation (r/o)
	var vMarginVal;       // total margin required for all open positions on the account
	var vMarginSum;       // total margin required for all open positions of the strategy
	var vRiskSum;         // total risk of all open positions
	var vWinVal,vLossVal; // current win/loss of all open positions
	var vBalance;         // account balance in trade mode
	var vEquity;          // account balance plus open trade value in trade mode
	int numTrades;        // number of open or pending trades
	int numPending;       // number of virtual or real pending trades
	int numShort,numLong; // number of open long or short positions
	int numWinning,numLosing,numEven; // # of trades winning, losing, break even
	int numWFOWin,numWFOLoss; // number of won or lost WFO cycles

	// simulation/optimization parameters (r/w)
	ETimeZone nBarZone;  // DST zone for local time bars
	int nBarOffset;      // bar period offset in minutes
	int nTimeFrame;      // time frame for price() and series() in number of bars
	int nFrameOffset;    // timeframe offset in bars
	int numTotalCycles;  // number of complete cycles
	int numSampleCycles; // number of oversampling cycles 
	int numOptCycles;    // number of parameter optimize runs
	int numWFOCycles;    // number of WFO runs
	int numYears;        // number of years of the simulation (default = 0 = all years up to last year)
	int numDays;         // number of days of the simulation (default = 0 = all)
	int nStartDate;      // simulation start year (yyyy) or exact start date (yyyymmdd] (default = 2010)
	int nEndDate;        // simulation end date (yyyymmdd] (default = current year)
	int nStartWeek,nEndWeek;  // Week start and end day & hour
	int nUpdateDays;     // automatically update history when older than given number of days (default: 60)
	int nMaxBars;        // the maximum number of bars to simulate
	int nUnstablePeriod; // number of lookback bars added for exponential indicators (default = 40)
	int nLookBack;       // number of bars before the simulation starts (automatically adjusted)
	int nDataSplit;      // Percentage of in sample data (f.i. 90 for 90% in sample, 10% out of sample)
	int nDataSkip;       // Bars to skip with the SKIP1..3 flag
	EDetrendMode nDetrend; // 1 = detrend trade results; 2 = detrend price functions; 4 = detrend price curve
	EWeekendMode nWeekend; // 1 = don't trade during weekend (default); 2 = don't manage trades during weekend; 4 = log out during weekend
	int nTradesPerBar;   // max trades / numbars
	var vDataSlope;      // 1..3, bias factor for giving more weight to the last trades
	var vDataWeight;     // automatically set, 3 or 1.5 for one-week and two-week data sets
	var dOptFactor[2];   // Optimize factors at range borders
	var vOptimalFRatio;  // 0 or 2..10, ratio of maximum to minimum OptimalF
	float fWeight;       // current weight factor
	int nTimeStep;       // last time frame
	int nWFOPeriod;      // length of the WFO period
	int nWFOMethod; 
	int nDay;            // current simulation day (after lookback)
	int numAllocDays;    // maximum number of days in the simulation
	int nReTrainDays;    // re-training interval
	DATE tStartTime;     // session start time
	int nCommand[4];     // command line numbers
	DATE tDayOffset;     // for simulating live trading on a different day
	CONTRACT *contract;  // selected contract
	int nAttempts;       // download attempts
	var vOutlier;        // Outlier detection
	int nTickTime;       // minimum tick time in milliseconds (default = 100)
	int nTickAvg;        // Price smoothing on incoming prices
	int nTimeFix;        // ms, add this to historical price quotes
	int nTockTime;       // Minimum tock time in milliseconds (default = 60000);
	int nExpiryTime;     // UTC HHMM, time of day for contract expiration

	var vSlider[4];      // current values from the sliders, in the range defined by slider()
	int nProgress1,nProgress2; // progress bar
	string sInfo;        // info window

						 // simulation state (r/o)
	int nFirstBar;       // first bar that lies at or after g->nStartDate
	int numBars;         // total number of bars of the simulation, depends on nBarPeriod
	int numAllocBars;    // size of the bar, plot, and price arrays
	int numMinutes;      // total minutes of the test frame 
	int nTick;           // current tick number in trade management functions
	int nBar;            // current bar number
	int nTotalCycle;     // current cycle
	int nSampleCycle;    // current oversampling cycle number 
	int nParLoop;        // current optimize call number within one loop
	int nParTotal;       // current optimize call number of all loops
	int numParTrain;     // number of parameters trained per loop
	int nStepCycle;      // current optimize step
	int nParCycle;       // current parameter optimizing run, 1..numParTrain
	int nOptCycle;       // when parameters are optimized twice
	int nWFOCycle;       // current WFO cycle
	int nFrameStart;     // start bar of the active data frame
	int numFrameBars;    // size of the active data frame in bars
	int numLoops[2];     // total number of loops in training mode
	int nLoop[2];        // current loop argument number (starting with 1)
	int nLoopCycle[2];   // trained loop argument number, or 0 for whole loop
	void* pLoopPar[2];   // current loop parameter
	int nSelectWFO;      // WFO cycle to select, or 0 for all cycles
	int nLogCycle;       // Log trades of a certain train cycle; format WLLPS (Walk Loop0 Loop1 Par Step)
	BOOL bDoStep,bDoLoop; // TRUE during optimization
	int numAssets;       // number of assets used in the script
	var vParameter;      // current optimize value
	var vProfitMax,vProfitMin; // maximum and minimum result of all bar cycles
	int nWFOStart;       // bar number of the current WFO cycle start
	int nTrainFrame,nTestFrame;  // size of the training/test period in bars
	int nModels;         // number of models for prediction
	int nUserBar;        // return value from bar() function
	BOOL bFor;           // inside a for(trade) loop
	int numPhantom;      // number of phantom trades
	int numRejected;     // number of rejected trades
	int nComponents;     // component counter

	long pad3[2];

	var *pPrevCurve;     // daily balance/equity curve from previous backtest
	long nPrevLength;    // length of the balance/equity curve
	T6  *pTick;          // current tick for TMF and tick functions
	int nLastPeriod;     // last time period passed to an indicator
	var *pLastSeries;    // last series passed to an indicator
	var *pTime;          // daily date 
	var *pCurve;         // daily balance/equity curve from
	long RHandle;        // handle of the R Bridge
	string sParameters;  // content of the parameter file
	string sFactors;     // content of the OptimalF factor file
	string sRules;       // content of the rule file
	var  *pParameters;   // array of parameters from the optimize loop
	var  *pParLoop;      // parameter list in current loop
	void *pRules;        // compiled advise rules

	TRADE *tr;           // current trade in trade function or enumeration
	ASSET *asset;        // current asset, set up by asset()
	BAR *bars;           // list of bars
	float *pResults;     // array of bar results
	var *pEquity;        // displayed equity curve
	var *pDrawDown;      // displayed drawdown curve
	var *pMonteCarlo;    // Monte Carlo simulation results

	string sAlgo;        // current algorithm identifier, set up by algo()
	string sScript;      // current script name, used for .par/.fac/.c/.csv
	string sExeName;     // current name for the .x file to compile
	string sAssetList;   // file name of current assets list
	string sCSVLogName;  // CSV log file path for storing trade results
	string sBroker;      // name returned by the broker plugin
	string sHistory;     // extension of the history files
	string sWebFolder;   // HTML page folder
	string sFactorList;  // factor file name
	string sZorroFolder; // Zorro's own folder
	string sRTermPath;   // path to the R terminal
	string sCurves;      // file name for daily balance curves
	string *pAssets;     // list of asset names
	string sMessage;     // last critical message f.i. for possible orphans
	string sAccount;     // Account name from the scrollbox
	string sContractSymbol;  // selected option or future underlying
	string sButton;      // Text for the Result button
	string sError;       // Error string for identifying code positions
	long pad4[20];

	// chart/log parameters (r/w)
	int nPlotScale;      // width of a bar in the chart image, in pixels (default = 4; 0 for no chart)
	int nPlotWidth;      // maximum main chart width in pixels
	int nPlotHeight1,nPlotHeight2; // Main chart and additional chart height in pixels
	int nPlotDate;       // start date of the plot (default = 0 = plot all)
	int nPlotBars;       // number of bars to plot (default = 0 = all)
	EColor dwColorCandle;
	EColor dwColorUp,dwColorDn; // color of white / black candles
	EColor dwColorEquity,dwColorDD;
	EColor dwColorWin,dwColorLoss;
	string sPlotLabelFormat;
	int nPlotTrade;
	EColor dwColorBars[3];
	EColor dwColorPanel[6];
	int nPlotPeriod;     // Chart update period in minutes
	EPlotMode nPlotMode;

	long pad5[14];

	ESaveMode nSaveMode; // load/save flags
	DWORD dwBrokerPatch; // work around API bugs
	DWORD dwMode;        // mode switches
	DWORD dwStatus;      // status flags
	int nState;          // training machine state
	DWORD flags;         // internal flags
	DWORD flags2;        // more internal flags
	DWORD* Functions;    // null terminated function list
	HINSTANCE RLib;      // R DLL Handle

	long pad6[13];

	// Indicator return variables
	var vAroonDown,vAroonUp;
	var vRealUpperBand,vRealMiddleBand,vRealLowerBand;
	var vInPhase,vQuadrature;
	var vSine,vLeadSine;
	var vMACD,vMACDSignal,vMACDHist;
	var vMAMA,vFAMA;
	var vMin,vMax;
	var vMinIdx,vMaxIdx;
	var vSlowK,vSlowD,vFastK,vFastD;
	var vDominantPeriod,vDominantPhase;
	var vRed,vGreen,vBlue;
	var vError;
	var vEMA;
	var vPeak,vSlope,vSign,vLength;
	var vMean;
	var vMomentum;
	var vTenkan,vKijun,vSenkouA,vSenkouB;

	long pad7[14];

} GLOBALS;

#endif // trading_types_h