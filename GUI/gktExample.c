#include<gtk/gtk.h>

static void print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
}

static void activate(GtkApplication* app, gpointer user_data)
{
    GtkWidget* window;
    GtkWidget* button;
    GtkWidget* box;
    

    GtkWidget* portList; // The section that make posible to pick a uart port.


    // TODO: make a way to reload port list.

    portList = gtk_list_box_new(); // This takes no parameter. IDK why

    // gtk_widget_set_halign(portBox, GTK_ALIGN_START);
    // gtk_widget_set_valign(portBox, GTK_ALIGN_START);
  
    //core dump veriyordu surekli ben de https://www.youtube.com/watch?v=UHaJP2sQMic bu videodan biraz "esinlendim". Allah gtk nin belasini versin. Ama daha geciremedim. Surekli core dump aliyorum





    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window),"Tufan Elektromobil");
    gtk_window_set_default_size(GTK_WINDOW(window),720,480);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
    gtk_widget_set_halign(box, GTK_ALIGN_END);
    gtk_widget_set_valign(box, GTK_ALIGN_START);
    gtk_window_set_child(GTK_WINDOW(window),box);

    button = gtk_button_new_with_label("Reset");
    g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
    //g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_destroy), window);
    
    gtk_box_append (GTK_BOX (box), button);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char** argv)
{
    GtkApplication* app;
    int status;

    app = gtk_application_new("com.tufan.AKS",G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);



    return status;
}