#include <gtk/gtk.h>
#include <signals.hpp>
#include <config.hpp>
#include <stdio.h>

static struct wMain wMainCfg;

int main(int argc, char** argv)
{
    GtkWidget* mainWindow, //Основное окно
        *btnView,
        *btnEdit;

    GtkWidget *fixed;

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

    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(mainWindow),fixed);

    btnEdit = gtk_button_new_with_label("Изменение данных");
    gtk_fixed_put(GTK_FIXED(fixed), btnEdit, 0, 0);

    //btnView = gtk_button_new_with_label("Просмотр данных");

    g_signal_connect(
        mainWindow,
        "destroy",
        G_CALLBACK(sig_destroy_mainWindow),
        NULL); //При закрытие окна вызываем sig_destroy_mainWindow()

    gtk_widget_show_all(mainWindow);

    gtk_main();

    return 0;
}
