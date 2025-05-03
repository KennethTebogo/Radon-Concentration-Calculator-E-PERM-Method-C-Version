#include <stdio.h>
#include <math.h>

// Constants
#define SYSTEM_ERROR_PERCENT 5.0
#define VOLTAGE_READING_ERROR 1.0 // ±1 V
#define BACKGROUND_GAMMA 32.0     // Bq/m³
#define BACKGROUND_ERROR 6.0      // Bq/m³

// Function to compute calibration factor
double compute_calibration_factor(double I, double F) {
    return 0.0459 + 1.5519e-5 * (I + F);
}

// Function to compute radon concentration
double compute_radon_concentration(double I, double F, double T, double Cf, double BG) {
    return ((I - F) / (Cf * T)) - BG;
}

// Function to compute voltage reading error as percentage
double compute_voltage_error_percent(double I, double F) {
    double deltaV = fabs(VOLTAGE_READING_ERROR * 2); // ±1V for both I and F
    return (deltaV / fabs(I - F)) * 100.0;
}

// Function to compute background error as percentage
double compute_background_error_percent(double CRn, double BG) {
    return (BACKGROUND_ERROR / (CRn + BG)) * 100.0;
}

// Function to compute total error
double compute_total_error(double E1, double E2, double E3) {
    return sqrt(E1 * E1 + E2 * E2 + E3 * E3);
}

int main() {
    // Example values
    double I = 708.0;  // Initial voltage
    double F = 640.0;  // Final voltage
    double T = 7.0;    // Exposure time in days

    // Calculations
    double deltaV = I - F;
    double Cf = compute_calibration_factor(I, F);
    double CRn = compute_radon_concentration(I, F, T, Cf, BACKGROUND_GAMMA);

    double E1 = SYSTEM_ERROR_PERCENT;
    double E2 = compute_voltage_error_percent(I, F);
    double E3 = compute_background_error_percent(CRn, BACKGROUND_GAMMA);
    double E_total = compute_total_error(E1, E2, E3);

    // Output
    printf("Initial Voltage (V): %.2f\n", I);
    printf("Final Voltage (V): %.2f\n", F);
    printf("Exposure Time (days): %.2f\n", T);
    printf("Voltage Drop (V): %.2f\n", deltaV);
    printf("Calibration Factor (Cf): %.5f\n", Cf);
    printf("Radon Concentration (Bq/m³): %.2f\n", CRn);
    printf("\n--- Error Estimates ---\n");
    printf("System Component Error (E1): %.2f%%\n", E1);
    printf("Voltage Reading Error (E2): %.2f%%\n", E2);
    printf("Gamma Background Error (E3): %.2f%%\n", E3);
    printf("Total Estimated Error: %.2f%%\n", E_total);

    return 0;
}

