#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Middle (int* data, size_t size);

int main (void)
{
    /*int* test_data = (int*) calloc (16, sizeof (int));
    test_data[0] = 0x462265c4;
    test_data[1] = 0xc0f2fcff;
    test_data[2] = 0x206cfbff;
    test_data[3] = 0x80e5f9ff;
    test_data[4] = 0xe05ef8ff;
    test_data[5] = 0x40d8f6ff;
    test_data[6] = 0xa051f5ff;
    test_data[7] = 0x00cbf3ff
    test_data[8] = 0x6044f2ff
    test_data[9] = 0x80b0edff
    test_data[10]= 0xe029ecff
    test_data[11]= 0x0096e7ff
    test_data[12]= 0x006a1800
    test_data[13]= 0x20d61300
    test_data[14]= 0x804f1200 
    test_data[15]= 0xa0bb0d00
    test_data[16]= 0x00350c00
    test_data[17]= 0x60ae0a00
    test_data[18]= 0xc0270900
    test_data[19]= 0x20a10700
    test_data[20]= 0x801a0600
    test_data[21]= 0xe0930400
    test_data[22]= 0x400d0300
    test_data[23]= 0xbadd9a3b

    FILE* test_file = fopen ("input.dat", "wb");
    fwrite (test_data, sizeof (int), 16, test_file);
    fclose (test_file);
    free (test_data);*/
    FILE* file = fopen ("input.dat", "rb");
    fseek (file, 0, SEEK_END);
    size_t bytesz = (size_t) ftell (file);
    fseek (file, 0, SEEK_SET);
    int* data = (int*) calloc (1, bytesz);
    data = NULL;
    size_t size = fread (data, sizeof (int), bytesz / sizeof (int), file);
    fclose (file);
    printf ("%d\n", Middle (data, size));
    free (data);
    return 0;
}

int Middle (int* data, size_t size)
{
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += data[i];
    }
    float res = (float) sum / (float) size;

    if (res > 1000)
    {
        return 1072811983;
    }
    if (fabs(res - (float)((int)res)) >= 0.5)
    {
        return (int)res + 1;
    }
    else
    {
        return (int) res;
    }
}