# EDGE_TO_CLOUD_HEAT_MONITORING_SYSTEM
Welcome to the IoT Temperature and Smoke Monitoring System! 🎉 This project is a microcontroller-based solution using the LPC2148 to monitor environmental parameters like temperature 🌡️ and smoke 💨, display them on an LCD 📟, and send the data to ThingSpeak ☁️ for real-time monitoring over the internet. Perfect for applications like home safety, industrial monitoring, or environmental tracking! 🏠🏭

📋 Project Overview

This project integrates multiple hardware and software components to create a robust IoT system. Here's what it does:

Measures Temperature 🌡️: Uses an ADC to read temperature sensor data.

Detects Smoke 💨: Monitors a smoke sensor (MQ2) for hazardous conditions.

Displays Data 📟: Shows real-time temperature and smoke status on a 16x2 LCD.

Sends Data to Cloud ☁️: Transmits data to ThingSpeak via an ESP-01 Wi-Fi module for remote monitoring.

Real-Time Clock (RTC) ⏰: Tracks time to schedule data uploads every 3 minutes.

Buzzer Alert 🚨: Activates a buzzer if smoke is detected (though not implemented in the provided code).

The project is built around the LPC2148 microcontroller and uses a modular C codebase for easy maintenance and scalability. 🚀

🛠️ Hardware Requirements


LPC2148 Microcontroller 🖥️: The core of the system.
Temperature Sensor 🌡️: Connected to ADC channel 1.
MQ2 Smoke Sensor 💨: Connected to P0.14.
16x2 LCD Display 📟: For local data display.
ESP-01 Wi-Fi Module 📡: For internet connectivity.
Buzzer 🚨: For alerts (connected to P0.13, though not used in code).
Power Supply 🔌: 3.3V for LPC2148 and sensors.

📦 Software Requirements
*Keil uVision 🛠️: For compiling and flashing the code.
*ThingSpeak Account ☁️: For cloud data storage and visualization.
*Drivers: UART, ADC, RTC, and LCD libraries for LPC2148.

🚀 Getting Started

1. Clone the Repository

git clone <your-repo-url>

2. Hardware Setup
   *Connect the temperature sensor to ADC channel 1.
   *Connect the MQ2 smoke sensor to P0.14.
   *Wire the 16x2 LCD to P0.16 (RS), P0.17 (RW), P0.18 (EN), and P1.16-P1.23 (data).
   *Connect the ESP-01 module to UART0 (Tx: P0.0, Rx: P0.1).
   *Ensure a stable 3.3V power supply for all components.

3. Software Configuration
   *Update the Wi-Fi credentials in esp01.c:
     UART0_Str("AT+CWJAP=\"YOUR_WIFI_SSID\",\"YOUR_WIFI_PASSWORD\"\r\n");
   *Update the ThingSpeak API key in esp01.c:
   *UART0_Str("GET /update?api_key=YOUR_API_KEY&field1=");
   *Compile and flash the code using Keil uVision.

4. Run the System
   *Power on the LPC2148 board.
   *The LCD will display a welcome message: "WELCOME TO MAJOR PROJECT" 🎉.
   *The system will connect to Wi-Fi and display temperature and smoke status on the LCD.
   *Data is sent to ThingSpeak every 3 minutes or when smoke is detected.

📁 Project Structure

├── adc.c          # ADC initialization and reading
├── adc_defines.h  # ADC configuration macros
├── esp01.c        # ESP-01 Wi-Fi module control
├── esp01.h        # ESP-01 function declarations
├── lcd.c          # LCD control functions
├── lcd.h          # LCD function declarations
├── lcd_defines.h  # LCD configuration macros
├── rtc.c          # RTC initialization and control
├── rtc.h          # RTC function declarations
├── rtc_defines.h  # RTC configuration macros
├── uart0.c        # UART0 initialization and communication
├── uart0.h        # UART0 function declarations
├── delay.c        # Delay functions
├── delay.h        # Delay function declarations
├── types.h        # Custom data type definitions
├── defines.h      # Bit manipulation macros
├── main.c         # Main program logic

🌟 Features
Real-Time Monitoring ⏰: Displays temperature and smoke status on the LCD.
Cloud Integration ☁️: Sends data to ThingSpeak for remote access.
Modular Code 🧩: Well-organized C files for easy maintenance.
Error Handling 🛡️: Displays "OK" or "ERROR" on LCD for ESP-01 commands.
Low Power ⚡: Efficient use of LPC2148 resources.

🔧 Improvements & Future Enhancements
Buzzer Implementation 🚨: Add logic to activate the buzzer on smoke detection.
Error Recovery 🔄: Implement retry mechanisms for failed Wi-Fi or ThingSpeak connections.
More Sensors 📈: Add support for additional sensors (e.g., humidity, CO).
User Interface 🖱️: Add buttons to manually trigger data uploads or reset.
Power Optimization 💡: Use low-power modes of LPC2148 for energy efficiency.

🤝 Contributing

Feel free to fork this repository, make improvements, and submit pull requests! 🙌 Let's make this project even better together. 😊

📜 License

This project is licensed under the MIT License. See the LICENSE file for details.

🙏 Acknowledgments

LPC2148 Community for excellent documentation.
ThingSpeak for providing a free IoT platform.
You, for exploring this project! 🎉

Happy coding! 🚀
