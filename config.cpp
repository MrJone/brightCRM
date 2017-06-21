#include <gtk/gtk.h>
#include <config.hpp>
#include <stdio.h>
#include <errno.h>

int cfg_get(const char* _path, struct wMain* _wMainCfg)
{
    FILE* conf = fopen(_path,"r");
    if (conf == NULL)
    {
        fprintf(stderr, "Error: cannot read config file %s, error[%d]\n", _path, errno);
        return -1;
    }
    fscanf(conf, "%d", &_wMainCfg->w);
    fscanf(conf, "%d", &_wMainCfg->h);
    fclose(conf);
    return 0;
}

int cfg_set(const char* _path, struct wMain* _wMainCfg)
{

}
