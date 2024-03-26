#include<gtk/gtk.h>





void click_dropdown(GtkWidget* widget,gpointer data)
{
    g_print("Drop down event: %s \n",data);
    
    const char* id = gtk_drop_down_get_active_id( (GtkDropDown *) widget );
    const char* item = gtk_drop_down_text_get_active_text( (GtkDropDown *) widget );

}



void init_combobox( GtkWidget* drop_down )
{
    drop_down = gtk_drop_down_text_new();
    
    if ( !drop_down )
    {
        g_print( "Dropdown could not initilized!\n" );
    }
}

