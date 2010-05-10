#include "gui.h"

GUI::GUI(int argc, char *argv[] ){
		GtkWidget *window;
		gtk_init (&argc, &argv);
		/* create a new window */
	    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    	gtk_widget_set_size_request (GTK_WIDGET (window), 200, 100);
	    gtk_window_set_title (GTK_WINDOW (window), "GTK Entry");
	    /* and the window */
		gtk_widget_show (window);
		
		/* All GTK applications must have a gtk_main(). Control ends here
		 * and waits for an event to occur (like a key press or
		 * mouse event). */
		gtk_main ();
}
