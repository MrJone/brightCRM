#ifndef _CONFIG_HPP_
#define _CONFIG_HPP_

#include <gtk/gtk.h>
#include <utility>

struct wMain {
    int w;
    int h;
};

int cfg_get(
    const char*,
    struct wMain*);
int cfg_set(
    const char*,
    struct wMain*);

#endif
