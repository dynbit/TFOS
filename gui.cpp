#include "gui.h"

GUI::GUI(int argc, char *argv[] ){
	this->argc = argc;
	this->argv = argv;
}

void GUI::start(){
	GtkWidget *window;
	gtk_init (&this->argc, &this->argv);
	/* create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    
    g_signal_connect (window, "delete-event", G_CALLBACK (GUI::delete_event), NULL);
    
    /* Here we connect the "destroy" event to a signal handler.  
     * This event occurs when we call gtk_widget_destroy() on the window,
     * or if we return FALSE in the "delete-event" callback. */
    g_signal_connect (window, "destroy", G_CALLBACK (GUI::destroy), NULL);
    
    
	gtk_widget_set_size_request (GTK_WIDGET (window), 200, 100);
    gtk_window_set_title (GTK_WINDOW (window), "GTK Entry");
    /* and the window */
	gtk_widget_show (window);
	
	/* All GTK applications must have a gtk_main(). Control ends here
	 * and waits for an event to occur (like a key press or
	 * mouse event). */
	gtk_main();
	return;
}


gboolean GUI::delete_event(	GtkWidget *widget,
               				GdkEvent  *event,
                   		    gpointer   data )
{
    /* If you return FALSE in the "delete-event" signal handler,
     * GTK will emit the "destroy" signal. Returning TRUE means
     * you don't want the window to be destroyed.
     * This is useful for popping up 'are you sure you want to quit?'
     * type dialogs. */

    g_print ("delete event occurred\n");

    /* Change TRUE to FALSE and the main window will be destroyed with
     * a "delete-event". */

    return FALSE;
}

void GUI::destroy(GtkWidget *widget, gpointer data){
	gtk_main_quit();
}


