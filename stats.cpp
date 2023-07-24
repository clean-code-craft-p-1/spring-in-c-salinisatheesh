#include "stats.h"

struct Stats compute_statistics(const float* numbers, int length) {
    struct Stats result;

    if (length == 0) {
        result.average = 0.0;
        result.max = 0.0;
        result.min = 0.0;
        return result;
    }

    result.min = numbers[0];
    result.max = numbers[0];
    float sum = numbers[0];

    for (int i = 1; i < length; ++i) {
        if (numbers[i] < result.min) {
            result.min = numbers[i];
        }
        if (numbers[i] > result.max) {
            result.max = numbers[i];
        }
        sum += numbers[i];
    }

    result.average = sum / static_cast<float>(length);

    return result;
}
alerter.h:
c
Copy code
#include "stats.h"

struct Stats compute_statistics(const float* numbers, int length) {
    struct Stats result;

    if (length == 0) {
        result.average = 0.0;
        result.max = 0.0;
        result.min = 0.0;
        return result;
    }

    result.min = numbers[0];
    result.max = numbers[0];
    float sum = numbers[0];

    for (int i = 1; i < length; ++i) {
        if (numbers[i] < result.min) {
            result.min = numbers[i];
        }
        if (numbers[i] > result.max) {
            result.max = numbers[i];
        }
        sum += numbers[i];
    }

    result.average = sum / static_cast<float>(length);

    return result;
}
alerter.h:
c
Copy code
#ifndef ALERTER_H
#include "stats.h"

struct Stats compute_statistics(const float* numbers, int length) {
    struct Stats result;

    if (length == 0) {
        result.average = 0.0;
        result.max = 0.0;
        result.min = 0.0;
        return result;
    }

    result.min = numbers[0];
    result.max = numbers[0];
    float sum = numbers[0];

    for (int i = 1; i < length; ++i) {
        if (numbers[i] < result.min) {
            result.min = numbers[i];
        }
        if (numbers[i] > result.max) {
            result.max = numbers[i];
        }
        sum += numbers[i];
    }

    result.average = sum / static_cast<float>(length);

    return result;
}
