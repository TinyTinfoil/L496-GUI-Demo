#ifndef DPOAE_H
#define DPOAE_H
#include <stdint.h>
#include <stdbool.h>
#include "arm_math.h"
void autofit(float32_t* data_src,int* data_out, uint16_t size, uint32_t max_val);
bool check_clipping(uint32_t* data_src, uint16_t size);
bool do_fft(arm_rfft_fast_instance_f32* fft_instance, uint32_t* input, float32_t* output, uint16_t size, float32_t* temp_buffer, float32_t* temp_buffer2);
bool sample_good(uint32_t* data_src, uint16_t size, arm_rfft_fast_instance_f32* fft_instance, float32_t* temp_buffer, float32_t* temp_buffer2, float32_t* output);
#endif // DPOAE_H