#include <loginDialog.hpp>
#include <gtk/gtk.h>

#define WIN_H 200
#define WIN_W 400

struct _data{
    GtkWidget* login;
    GtkWidget* pass;
};

_data sigData;

void runLoginDialog(char* _name, GtkWidget* _win_perent)
{
    GtkWidget *window;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_parent_window(window, GDK_WINDOW(_win_perent));
    gtk_window_set_modal(GTK_WINDOW(window), TRUE);
    gtk_window_set_title(GTK_WINDOW(window), "LogIn Bright CRM");
    gtk_window_set_default_size(GTK_WINDOW(window), WIN_W, WIN_H);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);
    g_signal_connect(window,
                     "destroy",                 // При закрытии окна window (loginDialog)
                     G_CALLBACK(sig_destroy_loginDialog), // просто закрываем программу. Нет авторищации - нет доступа
                     NULL);

    GtkWidget *fixedDialog;
    fixedDialog = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixedDialog);

    GtkWidget *textLogin;
    textLogin = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(fixedDialog),
                  textLogin,
                  0,
                  10);
    gtk_entry_set_placeholder_text(GTK_ENTRY(textLogin), "Введите логин...");

    GtkWidget *textPass;
    textPass = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(textPass), FALSE); //Делаем магию - вместо букв кружооочки :D
    gtk_fixed_put(GTK_FIXED(fixedDialog),
                  textPass,
                  0,
                  70);

    GtkWidget *btnLogin;
    btnLogin = gtk_button_new_with_label("Войти");
    gtk_fixed_put(GTK_FIXED(fixedDialog),
                  btnLogin,
                  0,
                  130);
    gtk_window_set_focus(GTK_WINDOW(window), btnLogin);
    sigData.login = textLogin;
    sigData.pass = textPass;
    g_signal_connect(btnLogin,
                     "clicked",
                     G_CALLBACK(sig_click_btnLogin_loginDialog),
                     window);

    gtk_widget_show_all(window);
}

void sig_click_btnLogin_loginDialog(GtkWidget* _widget, gpointer data)
{
    gtk_window_set_modal(GTK_WINDOW(GTK_WIDGET(data)), FALSE);
    gtk_widget_hide(GTK_WIDGET(data));
    //TODO: авторизацию запилить
}

void sig_destroy_loginDialog(GtkWidget* _widget, gpointer data)
{
    gtk_main_quit();
}
