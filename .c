#property indicator_separate_window
#property indicator_buffers 1
#property indicator_color1 Blue

// Parameters for the Serenity Index
extern int ATRPeriod = 14;  // ATR Period
extern int MAPeriod = 50;   // Moving Average Period
extern int RSIPeriod = 14;  // RSI Period

// Indicator buffer
double SerenityBuffer[];

// Initialize the indicator
int OnInit()
{
    // Set the indicator properties
    SetIndexBuffer(0, SerenityBuffer);  // Assign the buffer
    SetIndexStyle(0, DRAW_LINE);       // Set the line style
    IndicatorShortName("Serenity Index");  // Set the indicator name
    return(INIT_SUCCEEDED);
}

// Calculate True Range
double CalculateTrueRange(int i)
{
    double TRValue = MathMax(High[i] - Low[i], MathMax(MathAbs(High[i] - Close[i+1]), MathAbs(Low[i] - Close[i+1])));
    return TRValue;
}

// Calculate the Serenity Index for each bar
int OnCalculate(const int rates_total,
                const int prev_calculated,
                const datetime &time[],
                const double &open[],
                const double &high[],
                const double &low[],
                const double &close[],
                const long &tick_volume[],
                const long &volume[],
                const int &spread[])
{
    int start = MathMax(prev_calculated - 1, ATRPeriod);  // Start from the first uncalculated bar

    for (int i = start; i < rates_total; i++)
    {
        // Calculate components
        double TRValue = CalculateTrueRange(i);
        double ATRValue = iATR(NULL, 0, ATRPeriod, i);  // Average True Range
        double MALong = iMA(NULL, 0, MAPeriod, 0, MODE_SMA, PRICE_CLOSE, i);  // Moving Average
        double RSIValue = iRSI(NULL, 0, RSIPeriod, PRICE_CLOSE, i);  // RSI
        
        // Avoid division by zero
        if (MALong > 0)
        {
            SerenityBuffer[i] = (100 - ATRValue) * (RSIValue / 100) * (close[i] / MALong);
        }
        else
        {
            SerenityBuffer[i] = 0;  // Set to zero if MALong is invalid
        }
    }

    return(rates_total);
}
