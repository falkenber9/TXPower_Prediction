 
#include <stdlib.h>
#include <stdio.h>
#include <gmodule.h>

#include "cmnalib/logger.h"

#include "cmnalib/enumerate.h"
#include "cmnalib/at_sierra_wireless_mc7455.h"

void item_function(void* data, void* user_data) {
    device_list_entry_t* entry = data;
    printf("%s\n", entry->device_name);
}

int main(int argc, char** argv) {
    enable_logger = 0;  //quiet

    GSList* list = sw_mc7455_enumerate_devices();
    if(list == NULL) {
        return EXIT_FAILURE;
    }

    g_slist_foreach(list, item_function, NULL);

    sw_mc7455_enumerate_devices_free(list);

    return EXIT_SUCCESS;
}
