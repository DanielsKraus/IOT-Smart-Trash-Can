## IOT-Smart-Trash-Can
D1 Mini NodeMCU made into a home automation device for opening and closing of the lid of a trash can via voice commands utilizing Amazon Alexa/Echo.  The trash can already has an electronic push button for opening and closing of the lid.  The microcontroller will just take the state coming from the wifi **ON** or **OFF** and turn on a pin to it's corresponding area to trigger the switch to simulate pushing of the button.  

Installation instructions
  1. Clone this repository and navigate to the downloaded folder.
  
      ```git clone https://github.com/DanielsKraus/IOT-Smart-Trash-Can```
  
  2. Unzip the file and place in your Arduino sketch folder
      
  3. Download required libraries from Arduino IDE
  
      Go to your **sketch** tab, scroll down to **include Library**, then click **Manage Libraries...**. Type in the search box **ESP8266WiFi**, then install the latest version. Repeat the same steps for **FauxmoESP**.
      
      
      
#### Warning: if using ESP8266 esp-01 input voltage is 3.3v

*Fauxmo is required to spoof the gen3 Amazon Alexa/Echo.
