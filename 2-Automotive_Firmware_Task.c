#include <stdio.h>

#define BUF_SIZE 8
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

typedef enum {INT, FLOAT, DOUBLE}type;

static signed int wheel_speed_buf[BUF_SIZE];
static signed int *write_ptr = wheel_speed_buf;
static signed int count = 0;

signed int sum(unsigned int *arr,unsigned int array_size);
signed int moving_avg(unsigned int *arr, unsigned int array_size);
void insert(float value);

int main(void)
{
    unsigned int test[] = {21, 88, 98, 90, 86, 86, 48, 99, 86};

    printf("sum: %d\n", sum(test, ARRAY_SIZE(test)));

    printf("Moving Average: %d\n", moving_avg(test, ARRAY_SIZE(test)));
    
    for(int i = 0; i < 9; i++)
    {
        insert(test[i]);
        printf("Inserted: %.1f | Current Write Ptr: %p\n", test[i], (void*)write_ptr);
    }
}

// sum calculation
signed int sum(unsigned int *arr, unsigned int array_size)
{
    unsigned int sum = 0;
    for(int i = 0; i < array_size; i++)
        sum += arr[i];
    
    return sum;
}

// Moving average computation
signed int moving_avg(unsigned int *arr, unsigned int array_size)
{
    return sum(arr, array_size) / array_size;
}

// insertion
void insert(float value)
{
    if(write_ptr == NULL)
        return;

    *write_ptr = (signed int)value;

    write_ptr++;
    if(write_ptr == (wheel_speed_buf + BUF_SIZE))
        write_ptr = wheel_speed_buf;

    if (count < BUF_SIZE)
        count++;
}

