import serial
import time
import pandas as pd

# Establish serial connection with the Arduino (adjust the port to match your system)
ser = serial.Serial('COM3', 9600)  # On Windows, it could be 'COM3', or '/dev/ttyACM0' on Linux/Mac

# Wait for the serial connection to initialize
time.sleep(2)

# Create a list to hold the data
data = []

# Read data for a set number of iterations
for _ in range(50):  # Number of data points to collect
    line = ser.readline().decode('utf-8').strip()  # Read the line from the Arduino
    print(line)  # Optionally, print it out for real-time viewing
   
    # Parse the data to get the temperature and humidity values
    if "Temperature:" in line and "Humidity:" in line:
        parts = line.split("\t")
        temp_str = parts[0].split(":")[1].strip()
        hum_str = parts[1].split(":")[1].strip()
       
        # Convert to float and add to the data list
        try:
            temperature = float(temp_str)
            humidity = float(hum_str)
            data.append([temperature, humidity])
        except ValueError:
            continue  # Skip if there's a parsing error

    time.sleep(2)  # Wait before reading the next data point

# Close the serial connection
ser.close()

# Convert the list of data into a pandas DataFrame
df = pd.DataFrame(data, columns=["Temperature (C)", "Humidity (%)"])

# Save the data to a CSV file
df.to_csv('temperature_humidity_data.csv', index=False)

# Display the first few rows of the data
print(df.head())

# Optionally, perform basic analysis
print("Basic Statistics:")
print(df.describe())

# Plot the data (requires matplotlib)
import matplotlib.pyplot as plt
df.plot(x='Temperature (C)', y='Humidity (%)', kind='scatter', color='blue', alpha=0.5)
plt.title('Temperature vs Humidity')
plt.xlabel('Temperature (°C)')
plt.ylabel('Humidity (%)')
plt.show()