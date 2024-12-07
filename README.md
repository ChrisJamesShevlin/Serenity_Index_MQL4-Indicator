# Serenity Index Indicator for MetaTrader 4 (MT4)

This repository contains the MQL4 code for the **Serenity Index**, a custom indicator designed to calculate and display a composite metric based on ATR, RSI, and a moving average. The indicator is plotted in a separate window below the main chart.

## Features

- **True Range Calculation**: Incorporates the True Range for accurate volatility measurement.
- **ATR and RSI Integration**: Combines the Average True Range (ATR) and Relative Strength Index (RSI) for advanced insights.
- **Dynamic Plot**: Displays the Serenity Index as a line chart in a separate indicator window.

## Formula

The Serenity Index is calculated using the formula:

```
Serenity Index = (100 - ATR) * (RSI / 100) * (Close / MA)
```

Where:
- **ATR**: Average True Range over a specified period.
- **RSI**: Relative Strength Index over a specified period.
- **MA**: Simple Moving Average (SMA) over a specified period.

## Installation

1. **Download the Code**:
   - Clone this repository or download the `SerenityIndex.mq4` file directly.

   ```bash
   git clone https://github.com/your-username/serenity-index-mt4.git
   ```

2. **Copy to MT4**:
   - Place the `SerenityIndex.mq4` file in the `Indicators` folder of your MT4 installation:
     ```
     MQL4/Indicators/SerenityIndex.mq4
     ```

3. **Compile the Indicator**:
   - Open MetaEditor (part of MT4) and compile the file to ensure there are no errors.

4. **Add to Chart**:
   - Restart MT4.
   - Navigate to the **Navigator** panel, find **Serenity Index**, and drag it onto your chart.

## Parameters

| Parameter    | Description                              | Default Value |
|--------------|------------------------------------------|---------------|
| `ATRPeriod`  | Period for the Average True Range (ATR). | `14`          |
| `MAPeriod`   | Period for the Simple Moving Average.    | `50`          |
| `RSIPeriod`  | Period for the Relative Strength Index.  | `14`          |

## Screenshot

![image](https://github.com/user-attachments/assets/ce81dcf2-b6d4-416a-ae45-6c25c534cfc6)


## How It Works

1. **True Range Calculation**:
   - Uses the highest of the current high-low, high-previous close, and low-previous close.
2. **Indicator Buffers**:
   - Values are stored in an indicator buffer and plotted as a line in the separate window.
3. **Automatic Updates**:
   - The indicator recalculates on every new tick or when the chart data is refreshed.

## Notes

- Ensure that the **ATRPeriod**, **MAPeriod**, and **RSIPeriod** parameters are set appropriately for your trading strategy.
- The Serenity Index is designed for informational purposes and should be used as part of a broader trading strategy.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvement, please create a pull request or open an issue.

