#include <gtk/gtk.h>
#include <signals.hpp>

int main(int argc, char** argv)
{
    GtkWidget* mainWindow; //Основное окно

    gtk_init(&argc, &argv); //Инициализируем GTK+

    mainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(
        GTK_WINDOW(mainWindow),
        "Bright CRM");
    g_signal_connect(
        mainWindow,
        "destroy",
        G_CALLBACK(sig_destroy_mainWindow),
        NULL);

    gtk_widget_show(mainWindow);

    gtk_main();

    return 0;
}
