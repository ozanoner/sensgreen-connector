/**
 * @file component_utils.hpp
 * @brief Various helper macros
 * @version 0.1
 * @date 2025-06-01
 * @copyright Copyright (c) 2025
 */

#pragma once

#include "esp_log.h"

#define RETURN_IF_ERR(err, fmt, ...)                                                                    \
    {                                                                                                   \
        if (err)                                                                                        \
        {                                                                                               \
            ESP_LOGE(TAG, "[%s,%d] %s: " fmt, __func__, __LINE__, esp_err_to_name(err), ##__VA_ARGS__); \
            return (int)err;                                                                            \
        }                                                                                               \
    }

#define RETURN_IF_ERR2(err)  \
    {                        \
        if (err)             \
        {                    \
            return (int)err; \
        }                    \
    }

#define PRINT_IF_ERR(err, fmt, ...)                                                                     \
    {                                                                                                   \
        if (err)                                                                                        \
        {                                                                                               \
            ESP_LOGE(TAG, "[%s,%d] %s: " fmt, __func__, __LINE__, esp_err_to_name(err), ##__VA_ARGS__); \
        }                                                                                               \
    }

#define PRINT_IF_SUCC(err, fmt, ...)                                          \
    {                                                                         \
        if (!err)                                                             \
        {                                                                     \
            ESP_LOGI(TAG, "[%s,%d] " fmt, __func__, __LINE__, ##__VA_ARGS__); \
        }                                                                     \
    }

#define PRINT_IF_SUCC_D(err, fmt, ...)                                        \
    {                                                                         \
        if (!err)                                                             \
        {                                                                     \
            ESP_LOGD(TAG, "[%s,%d] " fmt, __func__, __LINE__, ##__VA_ARGS__); \
        }                                                                     \
    }

#define PRINT_LOC(fmt, ...) ESP_LOGI(TAG, "[%s,%d] " fmt, __func__, __LINE__, ##__VA_ARGS__)
#define PRINT_LOC_D(fmt, ...) ESP_LOGD(TAG, "[%s,%d] " fmt, __func__, __LINE__, ##__VA_ARGS__)
