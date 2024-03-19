#include<gtk/gtk.h>
#include"window.h" 

int main(int argc, char** argv)
{
    GtkApplication* app;    // Application pointer
    int status;             // App return value

    app = gtk_application_new("com.tufan.AKS",G_APPLICATION_DEFAULT_FLAGS);     // allocate new app
    g_signal_connect (app, "activate", G_CALLBACK (runWindow), NULL);          // starts to run window
    status = g_application_run (G_APPLICATION (app), argc, argv);               // TODO: What does this do
    g_object_unref(app);     // free the app


    return status;
}