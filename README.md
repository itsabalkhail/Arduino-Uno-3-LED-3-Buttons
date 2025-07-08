# Arduino 3 LED Control Project

## 📋 Project Overview

This project demonstrates a simple Arduino circuit that controls three LEDs using three push buttons. Each button toggles its corresponding LED on/off, providing an interactive way to control multiple LEDs independently.

## 🎯 Features

- **3 Independent LED Control**: Each LED can be controlled separately
- **Toggle Functionality**: Each button press toggles the corresponding LED state
- **Debouncing**: Built-in delay to prevent button bounce issues
- **Simple Circuit**: Easy to understand and implement for beginners

## 🔧 Components Required

| Component | Quantity | Description |
|-----------|----------|-------------|
| Arduino Uno | 1 | Main microcontroller |
| LEDs | 3 | Red colored LEDs |
| Push Buttons | 3 | Momentary push buttons |
| Resistors (220Ω) | 3 | Current limiting resistors for LEDs |
| Resistors (10kΩ) | 3 | Pull-down resistors for buttons |
| Breadboard | 1 | For circuit connections |
| Jumper Wires | Multiple | For connections |

## 📊 Circuit Diagram

### Circuit Overview
![Circuit Initial State](https://github.com/itsabalkhail/Arduino-Uno-3-LED-3-Buttons/blob/main/Screenshot%202025-07-08%20154954.png?raw=true)

The circuit consists of:
- Three LEDs connected to digital pins 13, 12, and 8
- Three push buttons connected to digital pins 7, 4, and 2
- Each LED has a 220Ω current limiting resistor
- Each button has a 10kΩ pull-down resistor

### Circuit Operation States

#### State 1: Initial State - All LEDs OFF
![Circuit State 1](https://github.com/itsabalkhail/Arduino-Uno-3-LED-3-Buttons/blob/main/Screenshot%202025-07-08%20154850.png?raw=true)
*All LEDs are in OFF state at startup*

#### State 2: First LED Activated
![Circuit State 2](https://github.com/itsabalkhail/Arduino-Uno-3-LED-3-Buttons/blob/main/Screenshot%202025-07-08%20154911.png?raw=true)
*LED 1 (Pin 13) is turned ON after pressing Button 1*

#### State 3: Multiple LEDs Active
![Circuit State 3](https://i.imgur.com/placeholder3.png)
*Multiple LEDs can be controlled independently*


## 🔌 Pin Configuration

### LED Connections
- **LED 1**: Digital Pin 13 (Built-in LED + External LED)
- **LED 2**: Digital Pin 12
- **LED 3**: Digital Pin 8

### Button Connections
- **Button 1**: Digital Pin 7
- **Button 2**: Digital Pin 4
- **Button 3**: Digital Pin 2

## 💻 Arduino Code

```cpp
bool led1State = false;
bool led2State = false;
bool led3State = false;
bool lastButton1 = false;
bool lastButton2 = false;
bool lastButton3 = false;

void setup() {
  // Initialize button pins as inputs
  pinMode(7, INPUT);
  pinMode(4, INPUT);
  pinMode(2, INPUT);
  
  // Initialize LED pins as outputs
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  
  // Turn off all LEDs initially
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(8, LOW);
}

void loop() {
  // Read current button states
  bool currentButton1 = digitalRead(7);
  bool currentButton2 = digitalRead(4);
  bool currentButton3 = digitalRead(2);
  
  // Check for button 1 press (rising edge)
  if (currentButton1 == HIGH && lastButton1 == LOW) {
    led1State = !led1State;
    digitalWrite(13, led1State);
    delay(50); // Simple debouncing
  }
  
  // Check for button 2 press (rising edge)
  if (currentButton2 == HIGH && lastButton2 == LOW) {
    led2State = !led2State;
    digitalWrite(12, led2State);
    delay(50); // Simple debouncing
  }
  
  // Check for button 3 press (rising edge)
  if (currentButton3 == HIGH && lastButton3 == LOW) {
    led3State = !led3State;
    digitalWrite(8, led3State);
    delay(50); // Simple debouncing
  }
  
  // Update last button states
  lastButton1 = currentButton1;
  lastButton2 = currentButton2;
  lastButton3 = currentButton3;
}
```

## 🚀 How to Run

1. **Hardware Setup**:
   - Connect the circuit as shown in the circuit diagram
   - Ensure all connections are secure
   - Connect Arduino to your computer via USB

2. **Software Setup**:
   - Open Arduino IDE
   - Copy and paste the provided code
   - Select the correct board (Arduino Uno)
   - Select the correct port

3. **Upload and Test**:
   - Upload the code to your Arduino
   - Press each button to toggle its corresponding LED
   - Each LED should turn on/off independently

## 🎮 How It Works

1. **Initialization**: All LEDs start in the OFF state
2. **Button Detection**: The program continuously monitors button states
3. **Edge Detection**: Only responds to button press (LOW to HIGH transition)
4. **Toggle Logic**: Each button press inverts the corresponding LED state
5. **Debouncing**: A 50ms delay prevents multiple toggles from a single press

## 🔍 Detailed Code Explanation

### 🔤 Variables Declaration

```cpp
bool led1State = false;
bool led2State = false;
bool led3State = false;
```
**Purpose**: These boolean variables store the current state of each LED
- `false` = LED is OFF
- `true` = LED is ON
- Initialize all LEDs to OFF state at startup

```cpp
bool lastButton1 = false;
bool lastButton2 = false;
bool lastButton3 = false;
```
**Purpose**: These variables store the previous state of each button for edge detection
- Used to detect when a button changes from LOW to HIGH (button press)
- Prevents continuous toggling while button is held down

### 🔧 Setup Function

```cpp
void setup() {
  // Initialize button pins as inputs
  pinMode(7, INPUT);
  pinMode(4, INPUT);
  pinMode(2, INPUT);
  
  // Initialize LED pins as outputs
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  
  // Turn off all LEDs initially
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(8, LOW);
}
```

**Line-by-line breakdown**:
1. **`pinMode(7, INPUT)`**: Sets pin 7 as input for button 1
2. **`pinMode(4, INPUT)`**: Sets pin 4 as input for button 2
3. **`pinMode(2, INPUT)`**: Sets pin 2 as input for button 3
4. **`pinMode(13, OUTPUT)`**: Sets pin 13 as output for LED 1
5. **`pinMode(12, OUTPUT)`**: Sets pin 12 as output for LED 2
6. **`pinMode(8, OUTPUT)`**: Sets pin 8 as output for LED 3
7. **`digitalWrite(13, LOW)`**: Turns OFF LED 1 initially
8. **`digitalWrite(12, LOW)`**: Turns OFF LED 2 initially
9. **`digitalWrite(8, LOW)`**: Turns OFF LED 3 initially

### 🔁 Main Loop Function

```cpp
void loop() {
  // Read current button states
  bool currentButton1 = digitalRead(7);
  bool currentButton2 = digitalRead(4);
  bool currentButton3 = digitalRead(2);
```
**Purpose**: Continuously reads the current state of all three buttons
- `digitalRead()` returns HIGH when button is pressed, LOW when released
- These values are stored in temporary variables for comparison

#### 🔘 Button 1 Logic
```cpp
if (currentButton1 == HIGH && lastButton1 == LOW) {
    led1State = !led1State;
    digitalWrite(13, led1State);
    delay(50);
}
```
**Edge Detection Logic**:
- **`currentButton1 == HIGH`**: Button is currently pressed
- **`lastButton1 == LOW`**: Button was NOT pressed in previous cycle
- **Combined condition**: Detects the exact moment of button press (rising edge)

**Toggle Logic**:
- **`led1State = !led1State`**: Inverts the current LED state
  - If LED was OFF (false), it becomes ON (true)
  - If LED was ON (true), it becomes OFF (false)
- **`digitalWrite(13, led1State)`**: Applies the new state to the LED
- **`delay(50)`**: 50ms delay for simple debouncing

#### 🔘 Button 2 & 3 Logic
```cpp
if (currentButton2 == HIGH && lastButton2 == LOW) {
    led2State = !led2State;
    digitalWrite(12, led2State);
    delay(50);
}

if (currentButton3 == HIGH && lastButton3 == LOW) {
    led3State = !led3State;
    digitalWrite(8, led3State);
    delay(50);
}
```
**Same logic applies to buttons 2 and 3**:
- Each button independently controls its corresponding LED
- Each has its own state variable and edge detection

#### 💾 State Memory Update
```cpp
lastButton1 = currentButton1;
lastButton2 = currentButton2;
lastButton3 = currentButton3;
```
**Purpose**: Updates the "last" button states for the next loop iteration
- This enables edge detection in the next cycle
- Current state becomes "last" state for comparison

### 🎯 Key Programming Concepts

#### 1. **Edge Detection**
```cpp
if (currentButton == HIGH && lastButton == LOW)
```
- **Rising Edge**: Detects moment when button goes from unpressed to pressed
- **Prevents**: Continuous toggling while button is held
- **Alternative**: Falling edge would be `(currentButton == LOW && lastButton == HIGH)`

#### 2. **State Toggle**
```cpp
ledState = !ledState;
```
- **Boolean NOT operator**: Flips true to false, false to true
- **Equivalent to**:
  ```cpp
  if (ledState == true) {
      ledState = false;
  } else {
      ledState = true;
  }
  ```

#### 3. **Debouncing**
```cpp
delay(50);
```
- **Problem**: Mechanical buttons can "bounce" (rapid on/off)
- **Solution**: 50ms delay prevents multiple readings during bounce
- **Better alternatives**: Software debouncing with timers

#### 4. **State Machine**
Each LED operates as a simple 2-state machine:
- **State 0**: LED OFF
- **State 1**: LED ON
- **Transition**: Button press toggles between states

### 🧠 Program Flow

1. **Initialization**: Set up pins and initial states
2. **Read Inputs**: Check all button states
3. **Process**: For each button, check if it was just pressed
4. **Update**: Toggle corresponding LED if button was pressed
5. **Remember**: Store current button states for next iteration
6. **Repeat**: Go back to step 2

### ⚡ Performance Notes

- **Loop Speed**: Very fast (microseconds per cycle)
- **Debounce Delay**: Only occurs when button is pressed
- **Memory Usage**: Minimal (6 boolean variables)
- **CPU Usage**: Very low (simple boolean operations)

### 🔧 Advanced Improvements

#### Better Debouncing
```cpp
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

if ((millis() - lastDebounceTime) > debounceDelay) {
    // Process button
    lastDebounceTime = millis();
}
```

#### Interrupt-based Approach
```cpp
void setup() {
    attachInterrupt(digitalPinToInterrupt(2), button1ISR, RISING);
}

void button1ISR() {
    led1State = !led1State;
    digitalWrite(13, led1State);
}
```

## 🛠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| LED doesn't turn on | Check connections and resistor values |
| LED stays on | Verify button wiring and pull-down resistors |
| Multiple toggles per press | Increase debounce delay |
| Button not responding | Check button connections and pin assignments |

## 📝 Possible Enhancements

- Add serial communication for debugging
- Implement proper interrupt-based button handling
- Add different LED patterns or effects
- Include potentiometer for brightness control
- Add buzzer for audio feedback
- 
---

**Happy Coding! 🚀**
