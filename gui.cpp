#include "gui.h"

GUI::GUI(int argc, char *argv[] ){
	this->argc = argc;
	this->argv = argv;
}

void GUI::start(){

	gtk_init (&this->argc, &this->argv);


	/* create a new window */
    this->window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    
    /* set window start possition */
    gtk_window_set_position(GTK_WINDOW(this->window), GTK_WIN_POS_CENTER);
    
    /* When the window is given the "delete-event" signal (this is given
     * by the window manager, usually by the "close" option, or on the
     * titlebar), we ask it to call the delete_event () function
     * as defined above. The data passed to the callback
     * function is NULL and is ignored in the callback function. */
    g_signal_connect (this->window, "delete-event", G_CALLBACK (GUI::delete_event), NULL);
    
    
    /* Here we connect the "destroy" event to a signal handler.  
     * This event occurs when we call gtk_widget_destroy() on the window,
     * or if we return FALSE in the "delete-event" callback. */
    g_signal_connect (this->window, "destroy", G_CALLBACK (GUI::destroy), NULL);
    
    
    /* Set window size */
	gtk_widget_set_size_request (GTK_WIDGET(this->window), 1024, 600);
	
	/* set wondow border */
	gtk_container_set_border_width(GTK_CONTAINER(this->window), 5);

	/* Set Window title */
    gtk_window_set_title (GTK_WINDOW (this->window), "TFOS | Vytautas Galaunia | Aidas rudis | 2010");
    
    /* create main window table */
	this->table = gtk_table_new(4, 6, TRUE);
	gtk_table_set_row_spacings(GTK_TABLE(this->table), 2);
	gtk_table_set_col_spacings(GTK_TABLE(this->table), 2);
	
	//**************************************************************************
	/* create inner left table */
	this->left_inner_table = gtk_table_new(1, 1, TRUE);
	gtk_table_set_row_spacings(GTK_TABLE(this->left_inner_table), 2);
	gtk_table_set_col_spacings(GTK_TABLE(this->left_inner_table), 2);
	
	/* left inner table components */
	this->cpu_frame = gtk_frame_new ("CPU");
	
	this->register_table = gtk_table_new(3, 3, TRUE);
	gtk_table_set_row_spacings(GTK_TABLE(this->register_table), 2);
	gtk_table_set_col_spacings(GTK_TABLE(this->register_table), 2);
	gtk_container_set_border_width(GTK_CONTAINER(this->register_table), 5);
	
	
	this->st_label = gtk_label_new ("ST");
	this->st_text = gtk_entry_new ();
	gtk_editable_set_editable(GTK_EDITABLE(this->st_text), FALSE);

	gtk_table_attach_defaults(GTK_TABLE(this->register_table), this->st_label, 0, 1, 0, 1 );
	gtk_table_attach_defaults(GTK_TABLE(this->register_table), this->st_text, 1, 3, 0, 1 );
	

	this->ic_label = gtk_label_new ("IC");
	this->ic_text = gtk_entry_new ();
	gtk_editable_set_editable(GTK_EDITABLE(this->ic_text), FALSE);
	
	gtk_table_attach_defaults(GTK_TABLE(this->register_table), this->ic_label, 0, 1, 1, 2 );
	gtk_table_attach_defaults(GTK_TABLE(this->register_table), this->ic_text, 1, 3, 1, 2 );


	gtk_container_add (GTK_CONTAINER (this->cpu_frame), this->register_table);
	
	/* add cpu_frame */
	gtk_table_attach_defaults(GTK_TABLE(this->left_inner_table), this->cpu_frame, 0, 1, 0, 1 );
	
	//**************************************************************************
	/* create inner center table */
	this->center_inner_table = gtk_table_new(1, 1, TRUE);
	gtk_table_set_row_spacings(GTK_TABLE(this->center_inner_table), 2);
	gtk_table_set_col_spacings(GTK_TABLE(this->center_inner_table), 2);
	
	/* center inner table components */
	this->program_frame = gtk_frame_new ("Program");
	
	this->file_table = gtk_table_new(3, 3, TRUE);
	gtk_table_set_row_spacings(GTK_TABLE(this->file_table), 2);
	gtk_table_set_col_spacings(GTK_TABLE(this->file_table), 2);
	gtk_container_set_border_width(GTK_CONTAINER(this->file_table), 5);
	
	/* Create combo box */
	this->combo_prg_list = gtk_combo_box_new_text();
	
	/* create frame */
	this->select_file_frame = gtk_frame_new ("Select \"*.prg\" file:");
	gtk_container_add (GTK_CONTAINER (this->select_file_frame), this->combo_prg_list);
	gtk_table_attach_defaults(GTK_TABLE(this->file_table), this->select_file_frame, 0, 3, 0, 2 );
	
	

	gtk_container_add (GTK_CONTAINER (this->program_frame), this->file_table);
	
	/* add cpu_frame */
	gtk_table_attach_defaults(GTK_TABLE(this->center_inner_table), this->program_frame, 0, 1, 0, 1);
	
	//**************************************************************************
	/* create inner right table */
	this->right_inner_table = gtk_table_new(1, 1, TRUE);
	gtk_table_set_row_spacings(GTK_TABLE(this->right_inner_table), 2);
	gtk_table_set_col_spacings(GTK_TABLE(this->right_inner_table), 2);
	
	/* right inner table components */
	this->button_frame = gtk_frame_new ("Buttons");
	
	this->select_file_btn = gtk_button_new_with_label("Select a file...");
	this->run_btn = gtk_button_new_with_label("Run...");
	this->step_btn = gtk_button_new_with_label("Step By Step");
	
	/* create table */	
	this->button_table = gtk_table_new(3, 3, TRUE);
	
	/* Table preferences */
	gtk_table_set_row_spacings(GTK_TABLE(this->button_table), 2);
	gtk_table_set_col_spacings(GTK_TABLE(this->button_table), 2);
	gtk_container_set_border_width(GTK_CONTAINER(this->button_table), 5);
	
	g_signal_connect(this->select_file_btn, "clicked", G_CALLBACK (GUI::init_file_chooser), gpointer(this));


	
	gtk_table_attach_defaults(GTK_TABLE(this->button_table), this->select_file_btn, 0, 3, 0, 1 );
	gtk_table_attach_defaults(GTK_TABLE(this->button_table), this->run_btn, 0, 3, 1, 2 );
	gtk_table_attach_defaults(GTK_TABLE(this->button_table), this->step_btn, 0, 3, 2, 3 );
	gtk_container_add (GTK_CONTAINER (this->button_frame), this->button_table);
	
	
	/* add cpu_frame */
	gtk_table_attach_defaults(GTK_TABLE(this->right_inner_table), this->button_frame, 0, 1, 0, 1);
	

	/* add left inner table to table */
	gtk_table_attach_defaults(GTK_TABLE(this->table), this->left_inner_table, 0, 1, 0, 1 );
	gtk_table_attach_defaults(GTK_TABLE(this->table), this->center_inner_table, 1, 5, 0, 1);
	gtk_table_attach_defaults(GTK_TABLE(this->table), this->right_inner_table, 5, 6, 0, 1);

	
	
	
	
	/* add table to window */
	gtk_container_add(GTK_CONTAINER(this->window), this->table);
    
    
    
    
    /* and the window */
	gtk_widget_show_all(this->window);
	
	/* All GTK applications must have a gtk_main(). Control ends here
	 * and waits for an event to occur (like a key press or
	 * mouse event). */
	gtk_main();
	return;
}

void GUI::show_file_chooser(){
	this->file_chooser = gtk_file_selection_new ("Select file...");
	g_signal_connect (G_OBJECT (GTK_FILE_SELECTION (this->file_chooser)->ok_button), 
		"clicked", G_CALLBACK (GUI::add_file), gpointer(this));
	gtk_widget_show (this->file_chooser);
}

void GUI::init_file_chooser(GtkWidget *widget, gpointer guiObject){
	g_print ("Show chooser\n");
	/* Show file chooser */
	((GUI*)guiObject)->show_file_chooser();
}


void GUI::add_file(GtkWidget *widget, gpointer guiObject){
	const gchar* filepath;
	filepath = gtk_file_selection_get_filename (GTK_FILE_SELECTION (((GUI*)guiObject)->file_chooser));
	gtk_combo_box_append_text( GTK_COMBO_BOX( ((GUI*)guiObject)->combo_prg_list ), filepath);

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

