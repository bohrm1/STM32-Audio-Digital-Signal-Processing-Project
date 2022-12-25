# STM32-Audio-Digital-Signal-Processing-Project
Canonical digital notch filter using the STM32-F302R8 Nucleao board written in C. 

The C++ implementation of the notch filter is in the C++ Implementation of Notch Filter folder. The STM32 code is in the CORE folder. A MATLAB script plotting the frequnecy response of the notch filter is in the STM32 Notch Freq Response Folder. Photos of the circuit and PPT is in the Final Lab Deliverables folder. Download the PDF of the PPT to view the demo videos.

The digital filter consists of a few code blocks: a structure to hold the filter coefficients and states, a function to implement a direct form II IIR filter, and an ISR to periodically sample using the ADC and write using the DAC.

A timer is used to trigger the ISR periodically at a rate of 32 kHz. This is the rate the input signal is sampled at and the output signal is written to the DAC. 

The desired sampling frequency is obtained by adjusting the auto-reload register of the timer. The STM32-F302R8 is able to perform floating-point arithmetic. When the analog signal is read using the ADC, it is stored in a uint32_t variable. The function prototype performs floating point arithmetic to compute the filtered output signal. This value is type casted from a double to a uint32_t to be written to the DAC. 
