#pragma once

#include "traffic_types.h"

void tc_download(const char* url);

int tc_upload_randomdata(const char* url,
                           size_t n_bytes,
                           progress_callback_func* callback,
                           void* callback_context,
                           double minimal_progress_interval_sec);
