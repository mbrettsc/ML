#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define train_count (sizeof(train)/sizeof(train[0]))

float train[][2] = {
        {0,0},
        {1,2},
        {2,4},
        {3,6},
        {4,8}
};

float rand_float()
{
    return (float) rand() / (float) RAND_MAX;
}

// Mse function.
float cost(float w, float b)
{
    float result = 0.0f;

    for (size_t i = 0; i < train_count; ++i) {
        float x = train[i][0];
        float y = (x*w) + b;
        float d = y - train[i][1];
        result += d*d;
    }
    return result / train_count;
}

int main()
{
    srand(time(0));
    float w = rand_float()*10.0f;
    float b = rand_float()*5.0f;
    float eps = 1e-3;
    float rate =  1e-3;
    for (size_t i = 0; i < 500; ++i) {
        // Finite difference method.
        // It's close to derivative, instead of lim goes to 0 you basically don't measure the limit and just pick a number very close to 0 like 1e-3 (0.001).
        float c = cost(w, b);
        float dw = (cost(w + eps, b) - c) / eps;
        float db = (cost(w, b + eps) - c) / eps;
        // Without bias program work more well in single input.
        b = 0;
        // If dw is positive, weight will decrease, otherwise it will increase. We apply this method until our cost is close to zero.
        w -= dw * rate;
        b -= db * rate;
        printf("cost w %f dw %f\n", cost(w, b), dw);
    }
    printf("---------------------------\nWeight = %f\nResult:\n---------------------------\n", w);
    for (size_t i = 0; i < train_count; ++i) {
        printf("input = %f, expected output = %f, our output = %f\n", train[i][0], train[i][1], train[i][0] * w);
    }
    return 0;
}