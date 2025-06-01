/**
 * @file app_utils.hpp
 * @brief application utilities
 * @version 0.1
 * @date 2025-06-01
 * @copyright Copyright (c) 2025
 */

#pragma once

#define RETURN_IF_ERR(err)   \
    {                        \
        if (err)             \
        {                    \
            return (int)err; \
        }                    \
    }

#define PRINT_IF_ERR(err)                                                          \
    {                                                                              \
        if (err)                                                                   \
        {                                                                          \
            ESP_LOGE(TAG, "[%s,%d] %s", __func__, __LINE__, esp_err_to_name(err)); \
        }                                                                          \
    }

#define PRINT_LOC(str) ESP_LOGI(TAG, "[%s,%d] %s", __func__, __LINE__, str)
#define PRINT_LOC_D(str) ESP_LOGD(TAG, "[%s,%d] %s", __func__, __LINE__, str)
