#ifndef _LOGINDIALOG_HPP_
#define _LOGINDIALOG_HPP_

#include <gtk/gtk.h>

void runLoginDialog(char* _name, GtkWidget* _win);

void sig_click_btnLogin_loginDialog(GtkWidget* _widget, gpointer data);
void sig_destroy_loginDialog(GtkWidget* _widget, gpointer data);

#endif // _LOGINDIALOG_HPP_
