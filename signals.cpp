#include <gtk/gtk.h>
#include <signals.hpp>

void sig_destroy_mainWindow(GtkWidget* _widget, gpointer data)
{
    gtk_main_quit();
}
