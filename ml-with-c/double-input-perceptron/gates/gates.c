#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define train_count 4

// all gates will work except xor
float train[][3] = {
        {0,0,0},
        {1,0,1},
        {0,1,1},
        {1,1,1},
};

float rand_float()
{
    return (float) rand() / (float) RAND_MAX;
}

// Sigmoid Function
float sigmoidf(float x)
{
    return 1.f / (1.f + expf(-x));
}

// Mse Function
float cost(float w1, float w2, float b)
{
    float result = 0.0f;
    for (size_t i = 0; i < train_count; ++i) {
        float x1 = train[i][0];
        float x2 = train[i][1];
        float y = sigmoidf((x1 * w1 + x2 * w2) + b);
        float d = y - train[i][2];
        result += d*d;
    }
    return result / train_count;
}

int main()
{
    srand(time(0));
    float w1 = rand_float();
    float w2 = rand_float();
    float b = rand_float();
    float eps = 1e-1;
    float rate = 1e-1;
    float dw1, dw2, db, c;
    for (size_t i = 0; i < 100*1000; ++i) {
        c = cost(w1, w2, b);
        dw1 = (cost(w1 + eps, w2, b) - c)/eps;
        dw2 = (cost(w1, w2 + eps, b) - c)/eps;
        // Bias is basically shift the activation function and helps to feed our model
        db = (cost(w1, w2, b + eps) - c)/eps;
        w1 -= dw1 * rate;
        w2 -= dw2 * rate;
        b -= db * rate;
    }
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            printf("%zu | %zu = %f\n", i, j, sigmoidf(i * w1 + j * w2 + b));
        }
    }
    return 0;
}
