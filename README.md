
# 🧪 Radon Concentration Calculator (E-PERM Method) — C Version

This C program calculates radon concentration in indoor air using E-PERM electret ion chambers. It also provides a detailed uncertainty analysis, accounting for system errors, voltage reading errors, and background radiation.

## 📈 Features

- Computes radon concentration (in Bq/m³) based on:
  - Initial and final electret voltages
  - Exposure time
  - Calibration factor
  - Background gamma radiation
- Calculates error contributions:
  - System error (E₁)
  - Voltage reading error (E₂)
  - Background correction error (E₃)
  - Total combined uncertainty
- Simple terminal interface with modifiable parameters in source code

## 🧮 Formula Used

**Radon concentration (CRn):**

$$
CRn = \frac{I - F}{C_f \times T} - BG
$$

Where:
- `I` = Initial voltage (V)
- `F` = Final voltage (V)
- `T` = Exposure time in days
- `Cf` = Calibration factor, calculated as `Cf = 0.0459 + 1.5519 × 10⁻⁵ × (I + F)`
- `BG` = Background gamma radiation (default: 32 Bq/m³)

## ❗ Error Estimation

Total uncertainty is calculated from:

- **E₁:** System error = 5%
- **E₂:** Voltage reading error (±1 V for both I and F)
- **E₃:** Background gamma correction uncertainty (default ±6 Bq/m³)

Combined using:

$$
E_{total} = \sqrt{E_1^2 + E_2^2 + E_3^2}
$$


## 🛠️ Usage

### Requirements

- C compiler (e.g., GCC)
- Basic terminal access

### Build and Run

```bash
gcc radon_calculator.c -o radon_calculator -lm
./radon_calculator
```

You can modify the values in the source code:

```c
double I = 708.0;  // Initial voltage in volts
double F = 640.0;  // Final voltage in volts
double T = 7.0;    // Exposure time in days
```

## 📜 Example Output

```
Initial Voltage (V): 708.00
Final Voltage (V): 640.00
Exposure Time (days): 7.00
Voltage Drop (V): 68.00
Calibration Factor (Cf): 0.05678
Radon Concentration (Bq/m³): 70.65

--- Error Estimates ---
System Component Error (E1): 5.00%
Voltage Reading Error (E2): 2.06%
Gamma Background Error (E3): 8.49%
Total Estimated Error: 9.98%
```

## 📁 Project Structure

```
├── radon_calculator.c      # Main C source file
├── README.md               # Project documentation
```

## 🔍 References

- **E-PERM® Electret Ion Chamber Technology**, Rad Elec Inc.
- Background gamma radiation values based on regional studies (default: 32 Bq/m³)
- Calibration formula derived from empirical measurements

## 📃 License

This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.
