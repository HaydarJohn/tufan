#include<gtk/gtk.h>
#include"window.h"



void initWindow(GtkApplication* app,GtkWidget** window,char* windowName,int width,int height)
{  
    *window = gtk_application_window_new(app);                          // assigns new window data
    gtk_window_set_title(GTK_WINDOW(*window),windowName);               // sets title of window
    gtk_window_set_default_size(GTK_WINDOW(*window),width,height);     // sets size of window
}


    // TODO: make a way to reload port list.



void runWindow(GtkApplication* app, gpointer user_data) // TODO: Add proper comments in  this function
{
    GtkWidget* window;

    initWindow(app,&window,"Tufan Elektromobil",1080,720);

    // WARNING: FIX THIS CODE
    
    GtkWidget* outer_box = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
    // gtk_widget_set_halign (outer_box, GTK_ALIGN_START);
    // gtk_widget_set_valign (outer_box, GTK_ALIGN_START);
    // gtk_window_set_child (GTK_WINDOW (window), outer_box);

    GtkWidget* list_box = gtk_list_box_new();
    GtkWidget* list_box_row = gtk_list_box_row_new();
    gtk_list_box_set_selection_mode(GTK_LIST_BOX(list_box),GTK_SELECTION_SINGLE);
    


    // WARNING: FIX THIS CODE

    gtk_window_present(GTK_WINDOW(window));
}