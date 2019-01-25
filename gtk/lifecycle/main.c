/*
 * =====================================================================================
 *
 *       Filename:  001.c
 *
 *    Description:  调用GTK+-2.0库，作界面开发
 *
 *        Version:  1.0
 *        Created:  08/21/2018 11:39:15 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <gtk/gtk.h>

void hello(GtkWidget *widget, gpointer data)
{
    g_print("Hello Debian!\n");
}

gint delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
{
    g_print("delete event occurred\n");
    return TRUE;
}

void destory(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *button;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);

    gtk_signal_connect(GTK_OBJECT(window), "delete_event", GTK_SIGNAL_FUNC(delete_event), NULL);
    gtk_signal_connect(GTK_OBJECT(window), "destroy", GTK_SIGNAL_FUNC(destory), NULL);

    button = gtk_button_new_with_label("Hello Debian!\n");
    gtk_signal_connect(GTK_OBJECT(button), "clicked", GTK_SIGNAL_FUNC(hello), NULL);
    gtk_signal_connect_object(GTK_OBJECT(button), "clicked", GTK_SIGNAL_FUNC(gtk_widget_destroy), GTK_OBJECT(window));
    gtk_container_add(GTK_CONTAINER(window), button);

    gtk_widget_show(button);
    gtk_widget_show(window);
    gtk_main();

    return 0;
}
