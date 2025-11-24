# Real-Time Sign Language Translator
A fully embedded ASL recognition system using an ESP32 + camera + speaker.  
Translates hand gestures or full ASL signs into spoken audio.  
Includes reverse translation: microphone → text on LCD so a deaf user can read replies.

## 🎯 Goal
Enable low-cost, real-time communication between deaf/hard-of-hearing users and non-signers without smartphones or cloud services.

## 🚀 Features
### **Phase 1: Gesture Control (completed)**
- Detects hand direction / open–closed gestures
- Triggers events based on gesture

### **Phase 2: ASL Alphabet Translator**
- 26 static letter shapes
- CNN classifier trained on your custom dataset
- Real-time inference on microcontroller

### **Phase 3: Full Sign Language Translator (extension)**
- LSTM sequence recognition for full-motion signs
- Real-time display + audio synthesis

### **Reverse Translation**
- Microphone captures speech  
- ESP32 runs real-time STT model (lightweight) OR streams to a cloud endpoint  
- LCD displays the speech as text for deaf user

## 🧠 System Architecture
Hand → Camera → CNN (A–Z classifier) → Word builder → Speaker output Speech → Microphone → STT → LCD text output

## 📂 Repository Structure
```
realtime-sign-language-translator/
├── firmware
│   ├── main.ino
├── models
├── src
├── tests
├── training
├── dataset
├── notebooks
|    ├── train_cnn.ipynb
├── hardware
|    ├── wiring_diagrams  
```

## 🛠️ Tech Stack
- ESP32-CAM
- TensorFlow Lite Micro
- On-device MFCC / audio preprocessing
- Speaker + amplifier
- I2C LCD screen
- Python for training dataset

## ▶️ Demo Ideas
- Spell full names using fingerspelling
- Bidirectional communication demo: sign → speech, speech → text

## 📌 Roadmap
- [ ] Add dynamic ASL signs (“hello”, “thank you”, “where”)
- [ ] Add noise-robust STT module
- [ ] Add Bluetooth headphone option
