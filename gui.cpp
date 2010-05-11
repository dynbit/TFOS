#include "gui.h"

GUI::GUI(int argc, char *argv[] ){
	this->argc = argc;
	this->argv = argv;
	this->prgList = NULL;
}

void GUI::start(){
	GtkWidget *window;
	
	/* Tables declaration */
	GtkWidget *table;
	GtkWidget *left_inner_table;
	GtkWidget *center_inner_table;
	GtkWidget *right_inner_table;
	GtkWidget *register_table;
	GtkWidget *file_table;
	GtkWidget *button_table;
	
	GtkWidget *cpu_frame;
	GtkWidget *program_frame;
	GtkWidget *button_frame;
	
	GtkWidget *st_label;
	GtkWidget *ic_label;
	
	GtkWidget *select_file_btn;
	GtkWidget *run_btn;
	GtkWidget *step_btn;

	GtkWidget *st_text;
	GtkWidget *ic_text;
	
	GtkWidget *combo_prg_list;
	GtkWidget *combo_prg_list_item;

	
	



	gtk_init (&this->argc, &this->argv);


	/* create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    
    /* set window start possition */
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    
    /* When the window is given the "delete-event" signal (this is given
     * by the window manager, usually by the "close" option, or on the
     * titlebar), we ask it to call the delete_event () function
     * as defined above. The data passed to the callback
     * function is NULL and is ignored in the callback function. */
    g_signal_connect (window, "delete-event", G_CALLBACK (GUI::delete_event), NULL);
    
    
    /* Here we connect the "destroy" event to a signal handler.  
     * This event occurs when we call gtk_widget_destroy() on the window,
     * or if we return FALSE in the "delete-event" callback. */
    g_signal_connect (window, "destroy", G_CALLBACK (GUI::destroy), NULL);
    
    
    /* Set window size */
	gtk_widget_set_size_request (GTK_WIDGET(window), 1024, 800);
	
	/* set wondow border */
	gtk_container_set_border_width(GTK_CONTAINER(window), 5);

	/* Set Window title */
    gtk_window_set_title (GTK_WINDOW (window), "TFOS | Vytautas Galaunia | Aidas rudis | 2010");
    
    /* create main window table */
	table = gtk_table_new(4, 6, TRUE);
	gtk_table_set_row_spacings(GTK_TABLE(table), 2);
	gtk_table_set_col_spacings(GTK_TABLE(table), 2);
	
	//**************************************************************************
	/* create inner left table */
	left_inner_table = gtk_table_new(1, 1, TRUE);
	gtk_table_set_row_spacings(GTK_TABLE(left_inner_table), 2);
	gtk_table_set_col_spacings(GTK_TABLE(left_inner_table), 2);
	
	/* left inner table components */
	cpu_frame = gtk_frame_new ("CPU");
	
	register_table = gtk_table_new(3, 3, TRUE);
	gtk_table_set_row_spacings(GTK_TABLE(register_table), 2);
	gtk_table_set_col_spacings(GTK_TABLE(register_table), 2);
	gtk_container_set_border_width(GTK_CONTAINER(register_table), 5);
	
	
	st_label = gtk_label_new ("ST");
	st_text = gtk_entry_new ();
	gtk_editable_set_editable(GTK_EDITABLE(st_text), FALSE);

	gtk_table_attach_defaults(GTK_TABLE(register_table), st_label, 0, 1, 0, 1 );
	gtk_table_attach_defaults(GTK_TABLE(register_table), st_text, 1, 3, 0, 1 );
	

	ic_label = gtk_label_new ("IC");
	ic_text = gtk_entry_new ();
	gtk_editable_set_editable(GTK_EDITABLE(ic_text), FALSE);
	
	gtk_table_attach_defaults(GTK_TABLE(register_table), ic_label, 0, 1, 1, 2 );
	gtk_table_attach_defaults(GTK_TABLE(register_table), ic_text, 1, 3, 1, 2 );


	gtk_container_add (GTK_CONTAINER (cpu_frame), register_table);
	
	/* add cpu_frame */
	gtk_table_attach_defaults(GTK_TABLE(left_inner_table), cpu_frame, 0, 1, 0, 1 );
	
	//**************************************************************************
	/* create inner center table */
	center_inner_table = gtk_table_new(1, 1, TRUE);
	gtk_table_set_row_spacings(GTK_TABLE(center_inner_table), 2);
	gtk_table_set_col_spacings(GTK_TABLE(center_inner_table), 2);
	
	/* center inner table components */
	program_frame = gtk_frame_new ("Program");
	
	file_table = gtk_table_new(3, 3, TRUE);
	gtk_table_set_row_spacings(GTK_TABLE(file_table), 2);
	gtk_table_set_col_spacings(GTK_TABLE(file_table), 2);
	gtk_container_set_border_width(GTK_CONTAINER(file_table), 5);
	
	combo_prg_list = gtk_combo_box_new ();
	combo_prg_list_item = gtk_list_item_new ();
	
	/* You must set the string to display in the entry field when the item is
     selected. */
	gtk_combo_set_item_string (GTK_COMBO (combo_prg_list), GTK_ITEM (combo_prg_list_item), "1st Item");

	/* Now we simply add the item to the combo's list. */
	gtk_container_add (GTK_CONTAINER (GTK_COMBO (combo_prg_list)->list), combo_prg_list_item);

	gtk_table_attach_defaults(GTK_TABLE(file_table), combo_prg_list, 0, 3, 0, 1 );
	
	/* Create a new file selection widget */
//    filew = gtk_file_selection_new ("Add file...");
    
//    gtk_table_attach_defaults(GTK_TABLE(file_table), filew, 2, 3, 0, 1 );

	gtk_container_add (GTK_CONTAINER (program_frame), file_table);
	
	/* add cpu_frame */
	gtk_table_attach_defaults(GTK_TABLE(center_inner_table), program_frame, 0, 1, 0, 1);
	
	//**************************************************************************
	/* create inner right table */
	right_inner_table = gtk_table_new(1, 1, TRUE);
	gtk_table_set_row_spacings(GTK_TABLE(right_inner_table), 2);
	gtk_table_set_col_spacings(GTK_TABLE(right_inner_table), 2);
	
	/* right inner table components */
	button_frame = gtk_frame_new ("Buttons");
	
	select_file_btn = gtk_button_new_with_label("Select a file...");
	run_btn = gtk_button_new_with_label("Run...");
	step_btn = gtk_button_new_with_label("Step By Step");
	
	
	button_table = gtk_table_new(3, 3, TRUE);
	gtk_table_set_row_spacings(GTK_TABLE(button_table), 2);
	gtk_table_set_col_spacings(GTK_TABLE(button_table), 2);
	gtk_container_set_border_width(GTK_CONTAINER(button_table), 5);
	
	gtk_table_attach_defaults(GTK_TABLE(button_table), select_file_btn, 0, 3, 0, 1 );
	gtk_table_attach_defaults(GTK_TABLE(button_table), run_btn, 0, 3, 1, 2 );
	gtk_table_attach_defaults(GTK_TABLE(button_table), step_btn, 0, 3, 2, 3 );
	gtk_container_add (GTK_CONTAINER (button_frame), button_table);
	
	
	/* add cpu_frame */
	gtk_table_attach_defaults(GTK_TABLE(right_inner_table), button_frame, 0, 1, 0, 1);
	

	/* add left inner table to table */
	gtk_table_attach_defaults(GTK_TABLE(table), left_inner_table, 0, 1, 0, 1 );
	gtk_table_attach_defaults(GTK_TABLE(table), center_inner_table, 1, 5, 0, 1);
	gtk_table_attach_defaults(GTK_TABLE(table), right_inner_table, 5, 6, 0, 1);

	
	
	
	
	/* add table to window */
	gtk_container_add(GTK_CONTAINER(window), table);
    
    
    
    
    /* and the window */
	gtk_widget_show_all(window);
	
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

