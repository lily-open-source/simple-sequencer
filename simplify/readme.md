<!DOCTYPE html>
<html>
<body>
  <h1>Relay Control Code</h1>
  <p>This code is used to control a set of relays using a push button and an analog sensor.</p>
  <h2>Hardware connections</h2>
  <ul>
    <li>Relay 1 is connected to pin D4 (GPIO 2).</li>
    <li>Relay 2 is connected to pin D5 (GPIO 14).</li>
    <li>Relay 3 is connected to pin D6 (GPIO 12).</li>
    <li>Relay 4 is connected to pin D7 (GPIO 13).</li>
    <li>Push button is connected to pin D8 (GPIO 15).</li>
    <li>Analog sensor is connected to pin A0.</li>
  </ul>
  <h2>Code functionality</h2>
  <ul>
    <li>The code sets the pin modes for the relays and push button in the setup function.</li>
    <li>In the loop function, the code reads the value of the analog sensor and maps it to a value between 1 and 255.</li>
    <li>The code then checks the state of the push button, if it's pressed, the relays are turned on in sequence and delayed by the value obtained from the sensor.</li>
    <li>If the push button is not pressed, the relays are turned off in sequence and delayed by the same value obtained from the sensor.</li>
    <li>The code uses the millis() function to limit the frequency of sensor reading and relay switching to every 100ms.</li>
  </ul>
</body>
</html>
