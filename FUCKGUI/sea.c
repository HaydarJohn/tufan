#include <gtk/gtk.h>

int main (int argc, char *argv[])
{

    GtkWidget *window;
    GtkWidget *menu;
    GtkWidget *menu_bar;
    GtkWidget *root_menu;
    GtkWidget *menu_items;
    char buf[128];
    int i;

    gtk_init (&argc, &argv);

    /* create a new window */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW (window), "GTK Menu Test");
    gtk_signal_connect(GTK_OBJECT (window), "destroy",
                       (GtkSignalFunc) gtk_exit, NULL);

    /* Init the menu-widget, and remember -- never
     * gtk_show_widget() the menu widget!! */
    menu = gtk_menu_new();

    /* This is the root menu, and will be the label will be the menu name displayed on
     * the menu bar.  There won't be
     * a signal handler attached, as it only pops up the rest of the menu when pressed. */
    root_menu = gtk_menu_item_new_with_label("Root Menu");

    gtk_widget_show(root_menu);

    /* Next we make a little loop that makes three menu-entries for "test-menu".
     * Notice the call to gtk_menu_append.  Here we are adding a list of menu items
     * to our menu.  Normally, we'd also catch the "clicked" signal on each of the
     * menu items and setup a callback for it, but it's omitted here to save space. */

    for(i = 0; i < 3; i++)
        {
            /* Copy the names to the buf. */
            sprintf(buf, "Test-undermenu - %d", i);

            /* Create a new menu-item with a name... */
            menu_items = gtk_menu_item_new_with_label(buf);

            /* ...and add it to the menu. */
            gtk_menu_append(GTK_MENU (menu), menu_items);

            /* Show the widget */
            gtk_widget_show(menu_items);
        }

    /* Now we specify that we want our newly created "menu" to be the menu for the "root menu" */
    gtk_menu_item_set_submenu(GTK_MENU_ITEM (root_menu), menu);

    /* Create a menu-bar to hold the menus and add it to our main window*/
    menu_bar = gtk_menu_bar_new();
    gtk_container_add(GTK_CONTAINER(window), menu_bar);
    gtk_widget_show(menu_bar);

    /* And finally we append the menu-item to the menu-bar -- this is the "root"
     * menu-item I have been raving about =) */
    gtk_menu_bar_append(GTK_MENU_BAR (menu_bar), root_menu);

    /* always display the window as the last step so it all splashes on the screen at once. */
    gtk_widget_show(window);

    gtk_main ();

    return 0;
}
