#include <gtk/gtk.h>
#include <signals.hpp>
#include <config.hpp>
#include <stdio.h>
#include <loginDialog.hpp>

static struct wMain wMainCfg;

int main(int argc, char** argv)
{
    GtkWidget *mainWindow,
        *fixedLout;
    GtkWidget *btn;

    char* name = new char[10];

    if (cfg_get("bcrm.conf", &wMainCfg) != 0)
    {
        fprintf(stderr, "Error: error in function cfg_get, close programm\n");
        return -1;
    }

    gtk_init(&argc, &argv); //Инициализируем GTK+

    mainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(mainWindow), "Bright CRM");
    gtk_window_set_default_size(GTK_WINDOW(mainWindow),
                                wMainCfg.w,
                                wMainCfg.h);
    gtk_container_set_border_width(GTK_CONTAINER(mainWindow), 20);

    runLoginDialog(name, mainWindow);

    fixedLout = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(mainWindow),fixedLout);
    //----------
    btn = gtk_button_new();
    gtk_fixed_put(GTK_FIXED(fixedLout),btn,20,20);
    gtk_button_set_label(GTK_BUTTON(btn), "КНОПАЩЬКА");
    //----------
    g_signal_connect(mainWindow,
                     "destroy",
                     G_CALLBACK(sig_destroy_mainWindow),
                     NULL); //При закрытие окна вызываем sig_destroy_mainWindow()

    gtk_main();

    return 0;
}

