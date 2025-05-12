📘 [日本語 README](README.md) | [English README](README.en.md)


# ATtiny202 Solenoid Control Board

A compact microcontroller board designed to control 3 solenoids using an ATtiny202.

---

## 📌 Overview

This board controls up to 3 solenoids individually via USART serial communication.  
A single character input (`'0'`–`'7'`) is interpreted as a 3-bit ON/OFF signal for the solenoids.

Examples:
- `'0'` → `0b000` → All solenoids OFF
- `'2'` → `0b010` → Middle solenoid ON, others OFF
- `'7'` → `0b111` → All solenoids ON

Each bit represents the state of a solenoid: `0 = OFF`, `1 = ON`.

---

## 🧩 Features & Configuration

- **Main Chip**: ATtiny202
- **Power Input**: 18V–26V via XT30PW-M connector
- **DC-DC Converter**: BP5293-50 (steps down to 5V)
- **Logic Level**: 3.3V
- **Interfaces**:
  - USART (serial control)
  - UPDI (programming only)
- **Solenoid Drivers**: 2SK4017 (Nch MOSFET)
- **Isolation**: TLP291 (photocoupler)
- **Control Method**: Serial char input to control solenoid states
- **Development Environment**: Arduino (for ATtiny202)

---

## 🛠 Components Used

| Component    | Description                    |
|--------------|--------------------------------|
| ATtiny202    | Main microcontroller           |
| 2SK4017      | Nch MOSFET for solenoid drive  |
| TLP291       | Photocoupler for signal isolation |
| BP5293-50    | DC-DC converter (18–26V → 5V)  |
| XH Connector | Solenoid output connector      |
| XT30PW-M     | Power input connector          |

---

## 🧾 Manufacturing

- **PCB Service**: Compatible with JLCPCB
- **Part Sourcing**: All components available from Akizuki Denshi (秋月電子通商)
- **Assembly**: Hand-solder friendly, some double-sided parts

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).  
You are free to use, modify, and distribute it as long as the original license and copyright
notices are retained.

---