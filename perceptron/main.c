#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

float train[][2] = {
        {0,0},
        {1,2},
        {2,4},
        {3,6},
        {4,8}
};

#define train_count (sizeof(train)/sizeof(train[0]))

float rand_float()
{
    return (float) rand() / (float) RAND_MAX;
}
//mse func
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
    // srand(69);
    float w = rand_float()*10.0f;
    float b = rand_float()*5.0f;
    float eps = 1e-3;
    float rate =  1e-3;
    for (size_t i = 0; i < 500; ++i) {
        // finite difference method
        // its close to derivetive, instead of lim goes to 0 u basicly dont mesure the limit and just pick a number very close to 0
        float c = cost(w, b);
        float dw = (cost(w + eps, b) - c) / eps;
        float db = (cost(w, b + eps) - c) / eps;
        // without bias work more well idk why maybe we arrange false
        b = 0;
        // if dw is poisitive it will be decrease, else it will increase beacuse our target is getting closer to zero
        w -= dw * rate;
        b -= db * rate;
        printf("cost w %f dw %f\n", cost(w, b), dw);
    }
    printf("-----------\n%f\n", w);
    return 0;
}
