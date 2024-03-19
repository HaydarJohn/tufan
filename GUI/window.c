#include<gtk/gtk.h>
#include"window.h"



void initWindow(GtkApplication* app,GtkWidget** window,char* windowName,int width,int height)
{  
    *window = gtk_application_window_new(app);                          // assigns new window data
    gtk_window_set_title(GTK_WINDOW(*window),windowName);               // sets title of window
    gtk_window_set_default_size(GTK_WINDOW(*window),width,height);     // sets size of window
}


    // TODO: make a way to reload port list.



void runWindow(GtkApplication* app, gpointer user_data)
{
    GtkWidget* window;

    initWindow(app,&window,"Tufan Elektromobil",1080,720);

    gtk_window_present(GTK_WINDOW(window));
}