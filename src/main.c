#include <pebble.h>
#include "main_window.h"


int main(void) {
    show_main_window();
    app_event_loop();
    return 0;
}