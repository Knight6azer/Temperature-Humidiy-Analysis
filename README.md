# Temperature & Humidity Data Collection and Analysis

This project collects temperature and humidity data from an Arduino device via a serial connection, processes the data, and visualizes it using Python. The data is filtered to include only values within a specified range (20-120) and saved for further analysis.

---

## Features

- Reads temperature and humidity data from an Arduino.
- Filters data where temperature and humidity values are between 20 and 120.
- Saves the filtered data to a CSV file.
- Provides basic statistical analysis.
- Plots a scatter graph of temperature vs. humidity for visualization.

---

## Prerequisites

1. **Hardware Requirements**:
   - Arduino device with a temperature and humidity sensor (e.g., DHT11/DHT22).
   - USB cable to connect the Arduino to your computer.

2. **Software Requirements**:
   - Python 3.x installed on your system.
   - Arduino IDE for uploading the appropriate sketch to your Arduino.

3. **Python Libraries**:
   - `pyserial`
   - `pandas`
   - `matplotlib`

Install these libraries using:
```bash
pip install pyserial pandas matplotlib
```

---

## Setup and Usage

1. **Upload Arduino Sketch**:
   - Upload the appropriate sketch to your Arduino to send temperature and humidity data in the format:
     ```
     Temperature: XX.X °C   Humidity: YY.Y %
     ```

2. **Connect Arduino**:
   - Connect the Arduino to your computer and note the COM port it uses (e.g., `COM4`).

3. **Run the Python Script**:
   - Clone the repository:
     ```bash
     git clone <repo_url>
     cd <repo_folder>
     ```
   - Execute the script:
     ```bash
     python collect_data.py
     ```

4. **Output**:
   - The filtered data will be saved to `temperature_humidity_filtered.csv`.
   - A scatter plot will visualize the relationship between temperature and humidity.

---

## Code Overview

- **Data Collection**:
  - Connects to the Arduino via the serial port.
  - Reads, parses, and filters temperature and humidity data.

- **Data Saving**:
  - Saves the filtered data into a CSV file for future use.

- **Visualization**:
  - Generates a scatter plot of temperature vs. humidity.

---

## Example Output

- **Sample Data**:
  ```
  Temperature (C),Humidity (%)
  33.3,67.0
  32.8,65.0
  ...
  ```

- **Scatter Plot**:
  ![Scatter Plot Example](https://github.com/Knight6azer/Temperature-Humidiy-Analysis/blob/main/Screenshot%20(13).png)

---

## Troubleshooting

1. **Serial Port Issues**:
   - Ensure the correct COM port is specified in the script.
   - Close other applications (e.g., Arduino IDE) using the same port.

2. **Data Parsing Errors**:
   - Ensure the Arduino sends data in the correct format.
   - Check the sensor's functionality and calibration.

3. **Empty Output**:
   - Verify that the temperature and humidity values are within the specified range (20-120).

---

## Contributions

Contributions are welcome! Please submit a pull request with your proposed changes or open an issue for discussion.

---

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

---

## Acknowledgments

- Arduino community for providing excellent resources.
- Python libraries for enabling seamless data processing and visualization.
