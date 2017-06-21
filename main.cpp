#include <gtk/gtk.h>
#include <signals.hpp>
#include <config.hpp>
#include <stdio.h>

static struct wMain wMainCfg;

int main(int argc, char** argv)
{
    GtkWidget* mainWindow; //Основное окно

    if (cfg_get("bcrm.conf", &wMainCfg) != 0)
    {
        fprintf(stderr, "Error: error in function cfg_get, close programm\n");
        return -1;
    }

    gtk_init(&argc, &argv); //Инициализируем GTK+

    mainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(
        GTK_WINDOW(mainWindow),
        "Bright CRM");
    gtk_window_set_default_size(
        GTK_WINDOW(mainWindow),
        wMainCfg.w,
        wMainCfg.h);

    g_signal_connect(
        mainWindow,
        "destroy",
        G_CALLBACK(sig_destroy_mainWindow),
        NULL); //При закрытие окна вызываем sig_destroy_mainWindow()

    gtk_widget_show(mainWindow);

    gtk_main();

    return 0;
}
