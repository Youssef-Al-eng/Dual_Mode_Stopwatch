# ⏱️ DualMode Stopwatch

The **DualMode Stopwatch** is an AVR microcontroller-based project designed to function as a versatile digital stopwatch. It provides both **count-up** and **count-down** modes, intuitive push-button controls, buzzer alarms, and a user-friendly interface using **6-digit seven-segment displays**.  

---

## 🚀 Features

### Stopwatch Modes
- **Count-Up Mode (default):** Increments time from `00:00:00` until the maximum.
- **Count-Down Mode:** Decrements time until it reaches `00:00:00`.

### User Input Controls
- Increment/Decrement **hours, minutes, seconds** individually.  
- **Mode toggle button** to switch between count-up and count-down.  
- **Pause, Resume, and Reset** functionality.  

### Visual Indicators
- **6 x Seven-Segment Displays** to show hours, minutes, and seconds.  
- **Red LED** → Indicates count-up mode.  
- **Yellow LED** → Indicates count-down mode.  

### Alarm
- **Buzzer activates** when:
  - Maximum time is reached (count-up).
  - Time reaches zero (count-down).  

---

## 🛠️ Components Required

- **Microcontroller:** ATmega32  
- **Display:** 6 × Seven-Segment Displays  
- **Inputs:** Push buttons (increment, decrement, mode, reset, pause, resume)  
- **Outputs:** Buzzer, Red LED, Yellow LED  
- **Optional:** 74LS47 BCD to Seven-Segment Decoder  

---

## ⚙️ How It Works

1. **Initialization**
   - Configures I/O pins for displays, LEDs, and buzzer.  
   - Sets up **Timer1** for timekeeping.  
   - Initializes **external interrupts** for user input.  

2. **Modes of Operation**
   - **Count-Up:** Time increments until `99:59:59`.  
   - **Count-Down:** Time decrements until `00:00:00`.  

3. **Button Controls**
   - Adjust hours, minutes, and seconds.  
   - Pause, resume, or reset stopwatch.  

4. **Visual Feedback**
   - Real-time display on seven-segment modules.  
   - LED indicators show active mode.  

---

## 🧩 Code Overview

- **Language:** C (AVR-GCC)  
- **Core Libraries:** AVR I/O, Interrupts  

### Key Functions
- `TIMER1_INIT()` → Configures Timer1 in **CTC mode** with 1024 prescaler (1s intervals).  
- `INT0_INIT(), INT1_INIT(), INT2_INIT()` → Configure external interrupts.  
- `Seven_Segment_Displays()` → Updates displayed time.  
- `Increment_Decrement_PUSH_BUTTONS()` → Handles button logic.  

### Interrupts
- `INT0` → Reset stopwatch  
- `INT1` → Pause stopwatch  
- `INT2` → Resume stopwatch  
- `TIMER1_COMPA_vect` → Increments/Decrements time  

---

## 📟 Pin Configuration

| Port   | Pin   | Function                        |
|--------|-------|---------------------------------|
| PORTA  | PA0–PA5 | Power source for 7-segment displays |
| PORTB  | PB0–PB7 | Push button inputs             |
| PORTC  | PC0–PC3 | Data lines for 7-segment decoder |
| PORTD  | PD0   | Buzzer output                   |
| PORTD  | PD2   | Reset input (INT0)              |
| PORTD  | PD3   | Pause input (INT1)              |
| PORTD  | PD4   | Count-Up LED (RED)              |
| PORTD  | PD5   | Count-Down LED (YELLOW)         |

---

## ▶️ How to Run

1. **Assemble Hardware**
   - Build the circuit based on the pin configuration.  

2. **Upload Code**
   - Use an AVR programmer to flash the ATmega32.  

3. **Power On**
   - Stopwatch starts in **count-up mode** by default.  
   - Use push buttons to set, control, and toggle modes.  

---

## 📐 Circuit Diagram
<img width="1367" height="843" alt="Image" src="https://github.com/user-attachments/assets/cb05e4c6-1a82-4b63-9a9e-ccb372b3b849" />

---

## 🔮 Future Enhancements

- Replace 7-segment displays with **OLED/LCD** for better visualization.  
- Add **memory functionality** to save states.  
- Support **custom alarms** and alerts.  

---

## 📜 License
This project is released under the **MIT License**.  
Feel free to use, modify, and share.  

---

## 👤 Author
**Youssef Alaa**  
- GitHub: [@Youssef-Al-eng](https://github.com/Youssef-Al-eng)  
- LinkedIn: [Youssef Alaa](https://www.linkedin.com/in/youssef-alaa-1b9580332/)  


