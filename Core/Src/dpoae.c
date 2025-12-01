#include "dpoae.h"
// #include "arm_math_types.h"
// #include <stdint.h>
/**
 * @brief Autofit function to rescale data values to a range of 0-max_val, inclusive of endpoints.
 * @param data_src Pointer to the source data
 * @param data_out Pointer to the output data
 * @param size Size of the data
 * @param max_val Maximum output value of the data
 */
void autofit(uint32_t* data_src,int* data_out, uint16_t size, uint32_t max_val){
    uint32_t min = 4294967295;
    uint32_t max = 0;
    for (uint16_t i = 0; i < size; i++) {
        if (data_src[i] > max) {
          max = data_src[i];
        }
        if (data_src[i] < min) {
          min = data_src[i];
        }
      }
        for (uint16_t i = 0; i < size; i++) {
          // rescale to be between 0 and 128
          data_out[i] = (data_src[i] - min) / ((max - min) / 128);
        }
}
/**
 * @brief Checks if DFSDM data is saturated
 * @param data_src Pointer to the source data
 * @param size Size of the data
 * @return false if any value is close to clipping, true otherwise
 */

bool check_clipping(uint32_t *data_src, uint16_t size){
    for (uint16_t i = 0; i < size; i++) {
        if (data_src[i] >= 0xFFFFFF-1 || data_src[i] < 1) {
          return false;
        }
      }
      return true;
}
/**
 * @brief Computes a log-scaled FFT on given input data, storing the result in the first half of the output buffer
 * @param fft_instance Pointer to the FFT instance structure
 * @param input Pointer to the input data
 * @param output Pointer to the output data (length at least size/2)
 * @param size Size of the input data
 * @param temp_buffer Pointer to a temporary buffer used for the transform, at least size long
 * @param temp_buffer2 Pointer to a temporary buffer used for the transform, at least size long
 * @return false if any value would cause NaN, true otherwise
 */
bool do_fft(arm_rfft_fast_instance_f32* fft_instance, uint32_t* input, float32_t* output, uint16_t size, float32_t* temp_buffer, float32_t* temp_buffer2){
    for (uint16_t i = 0; i < size; i++) {
        temp_buffer[i] = (float32_t) input[i];
    }
    arm_rfft_fast_f32(fft_instance, temp_buffer, temp_buffer2,0);
    arm_cmplx_mag_f32(temp_buffer2, temp_buffer, size / 2);
    for (uint16_t i = 0; i < size / 2; i++) {
        if (temp_buffer[i] <= 0) return false;
    }
    for (uint16_t i = 0; i < size / 2; i++) {
        output[i] = /*20*log10*/(temp_buffer[i]);
    }
    return true;
}
/**
 * @brief Checks if a sample is good based on clipping and FFT results
 * @param data_src Pointer to the source data
 * @param size Size of the data
 * @param fft_instance Pointer to the FFT instance structure
 * @param temp_buffer Pointer to a temporary buffer, at least size long
 * @param temp_buffer2 Pointer to a temporary buffer, at least size long
 * @param output Pointer to a temporary buffer, at least size/2 long, where the FFT output will be stored
 * @return false if sample is bad, true otherwise
 */
bool sample_good(uint32_t* data_src, uint16_t size, arm_rfft_fast_instance_f32* fft_instance, float32_t* temp_buffer, float32_t* temp_buffer2, float32_t* output){
    if (!check_clipping(data_src, size)) {
        return false;
    }
    if (!do_fft(fft_instance, data_src, output, size, temp_buffer, temp_buffer2)) {
        return false;
    }
    // uint16_t output_size = size / 2;
    // double sum_bin[4] = {0,0,0,0};
    // //TODO: implement a more robust noise check
    // for (uint16_t i = 0; i < output_size; i += output_size/4) {
    //     for (uint16_t j = 0; j < output_size/4; j++) {
    //         sum_bin[j] += output[i+j];
    //     }
    // }
    // for (uint16_t i = 1; i < 4; i++) {
    //     if (sum_bin[i] > sum_bin[0]) return false; //we expect that in a well behaved fft, more signal will be in the first bins due to 1/f noise
    // }
    return true;
}