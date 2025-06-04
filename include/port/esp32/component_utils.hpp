/**
 * @file component_utils.hpp
 * @brief Various helper macros
 * @version 0.1
 * @date 2025-06-01
 * @copyright Copyright (c) 2025
 */

#pragma once

#include "esp_log.h"

#define RETURN_IF_ERR(err, mess)                                                              \
    {                                                                                         \
        if (err)                                                                              \
        {                                                                                     \
            ESP_LOGE(TAG, "[%s,%d] %s (%s)", __func__, __LINE__, mess, esp_err_to_name(err)); \
            return (int)err;                                                                  \
        }                                                                                     \
    }

#define RETURN_IF_ERR2(err)  \
    {                        \
        if (err)             \
        {                    \
            return (int)err; \
        }                    \
    }

#define PRINT_IF_ERR(err, mess)                                                               \
    {                                                                                         \
        if (err)                                                                              \
        {                                                                                     \
            ESP_LOGE(TAG, "[%s,%d] %s (%s)", __func__, __LINE__, mess, esp_err_to_name(err)); \
        }                                                                                     \
    }

#define PRINT_IF_SUCC(err, mess)                                   \
    {                                                              \
        if (!err)                                                  \
        {                                                          \
            ESP_LOGI(TAG, "[%s,%d] %s", __func__, __LINE__, mess); \
        }                                                          \
    }

#define PRINT_LOC(mess) ESP_LOGI(TAG, "[%s,%d] %s", __func__, __LINE__, mess)
#define PRINT_LOC_D(mess) ESP_LOGD(TAG, "[%s,%d] %s", __func__, __LINE__, mess)
