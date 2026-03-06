#include <stdio.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

unsigned int getMax(unsigned int *arr, unsigned int array_size);
unsigned int getMin(unsigned int *arr, unsigned int array_size);
unsigned int getAverage(unsigned int *arr, unsigned int array_size);
void normalize(unsigned int *arr, float *normalized_array, unsigned int array_size);
unsigned int detectThreshold(unsigned int *arr,unsigned int Threshold, unsigned int array_size);

int main(void)
{
    unsigned int adc_buffer[10] = {120, 340, 560, 230, 800, 1023, 450, 300, 700, 200};
    float scaled_values[ARRAY_SIZE(adc_buffer)];

    printf("Max: %d\n", getMax(adc_buffer, ARRAY_SIZE(adc_buffer)));
    printf("Min: %d\n", getMin(adc_buffer, ARRAY_SIZE(adc_buffer)));
    printf("Average: %d\n", getAverage(adc_buffer, ARRAY_SIZE(adc_buffer)));
    printf("scale values to range (0 → 1):");
    normalize(adc_buffer, scaled_values, ARRAY_SIZE(adc_buffer));
    for (int i = 0; i < ARRAY_SIZE(adc_buffer); i++) {
        printf("%.2f ", scaled_values[i]);
    }
    printf("\n");
    printf("threshold : %d\n", detectThreshold(adc_buffer, 3000, ARRAY_SIZE(adc_buffer)));
}

unsigned int getMax(unsigned int *arr, unsigned int array_size)
{
    unsigned int max = arr[0];
    
    unsigned int i = 0;
    for(i; i <= array_size - 1; i++)
    {
        if(arr[i] >= max)
            max = arr[i];
    }

    return max;
}

unsigned int getMin(unsigned int *arr, unsigned int array_size)
{
    unsigned int min = arr[0];
    
    unsigned int i = 0;
    for(i; i <= array_size - 1; i++)
    {
        if(arr[i] < min)
            min = arr[i];
    }

    return min;
}

unsigned int getAverage(unsigned int *arr, unsigned int array_size)
{
    unsigned int average = arr[0];
    
    unsigned int i = 0;
    for(i; i <= array_size - 1; i++)
    {
        average += arr[i] / array_size;
    }

    return average;
}

void normalize(unsigned int *arr, float *normalized_array, unsigned int array_size)
{
    unsigned int max = getMax(arr, array_size);
    unsigned int min = getMin(arr, array_size);
    unsigned int range = max - min;

    unsigned int i = 0;
    for(i; i < array_size; i++)
    {
        if (range == 0) {
            normalized_array[i] = 0.0f;
        }
        else
        {
            normalized_array[i] = (float)(arr[i] - min) / (float)range;
        }
    }
}

unsigned int detectThreshold(unsigned int *arr,unsigned int Threshold, unsigned int array_size)
{
    unsigned int i = 0;

    for(i; i <= array_size-1; i++)
    {
        if(arr[i] <= Threshold)
            return 1;
    }
    
    return 0;
}
