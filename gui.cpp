#include <gtk-2.0/gtk/gtkvbox.h>
#include <gtk-2.0/gtk/gtkentry.h>
#include <gtk-2.0/gtk/gtklabel.h>

#include "gui.h"

GUI::GUI(int argc, char *argv[] ){
	this->argc = argc;
	this->argv = argv;
        this->rmachine = new realmachine();
        this->vmnumber = 0;
        this->rm_mem = NULL;

        this->rmword = new word("10", "10");
}

void GUI::setup_main_window(){
	/* create a new window */
    this->window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    
    /* set window start possition */
    gtk_window_set_position(GTK_WINDOW(this->window), GTK_WIN_POS_CENTER);
    
    /* When the window is given the "delete-event" signal (this is given
     * by the window manager, usually by the "close" option, or on the
     * titlebar), we ask it to call the delete_event () function
     * as defined above. The data passed to the callback
     * function is NULL and is ignored in the callback function. */
    g_signal_connect (this->window, "delete-event", G_CALLBACK (GUI::main_window_delete_event), NULL);
    
    /* Here we connect the "destroy" event to a signal handler.  
     * This event occurs when we call gtk_widget_destroy() on the window,
     * or if we return FALSE in the "delete-event" callback. */
    g_signal_connect (this->window, "destroy", G_CALLBACK (GUI::main_window_destroy), NULL);
    
    /* Set window size */
	//gtk_widget_set_size_request (GTK_WIDGET(this->window), 1024, 600);
	
	/* set window border */
	gtk_container_set_border_width(GTK_CONTAINER(this->window), 5);
	
	/* Set Window title */
    gtk_window_set_title (GTK_WINDOW (this->window), "TFOS | Vytautas Galaunia | Aidas Rudis | 2010");
    
    return;
}

void GUI::setup_main_box(){

	this->setup_left_box();	
	this->setup_right_box();
	// create header box 
	this->main_box = gtk_hbox_new (FALSE, 0);

	// add left_box to main_box
	gtk_box_pack_start (GTK_BOX (this->main_box), this->left_box, FALSE, FALSE, 5);
	gtk_box_pack_start (GTK_BOX (this->main_box), this->right_box, FALSE, FALSE, 5);
	
	// add main_box to window
	gtk_container_add (GTK_CONTAINER (this->window), this->main_box);
}



void GUI::setup_left_box(){
	// create label
	GtkWidget * cpu_frame;
	cpu_frame = gtk_frame_new ("CPU");
	
	// create cpu box
	GtkWidget * cpu_box;
	cpu_box = gtk_vbox_new (FALSE, 0);

	/*	IC REGISTER */	
	// ic box
	GtkWidget * ic_box;
	ic_box = gtk_hbox_new (FALSE, 0);
	// ic label 
	GtkWidget * ic_label;
	ic_label = gtk_label_new ("IC");
	gtk_widget_set_usize (ic_label, 80, 28);
	// create ic
        this->ic_buffer = gtk_entry_buffer_new (NULL, -1);
	this->ic = gtk_entry_new_with_buffer (this->ic_buffer);
	gtk_entry_set_editable (GTK_ENTRY(this->ic), FALSE);
	gtk_widget_set_can_focus (this->ic, FALSE);
	// add content to ic_box
	gtk_box_pack_start (GTK_BOX (ic_box), ic_label, FALSE, FALSE, 20);
	gtk_box_pack_start (GTK_BOX (ic_box), this->ic, FALSE, FALSE, 5);
	
	/*	ST REGISTER */
	// st box 
	GtkWidget * st_box;
	st_box = gtk_hbox_new (FALSE, 0);
	// ic label 
	GtkWidget * st_label;
	st_label = gtk_label_new ("ST");
	gtk_widget_set_usize (st_label, 80, 28);
	// create ic
        this->st_buffer = gtk_entry_buffer_new (NULL, -1);
	this->st = gtk_entry_new_with_buffer (this->st_buffer);
	gtk_entry_set_editable (GTK_ENTRY(this->st), FALSE);
	gtk_widget_set_can_focus (this->st, FALSE);
	// add content to ic_box
	gtk_box_pack_start (GTK_BOX (st_box), st_label, FALSE, FALSE, 20);
	gtk_box_pack_end (GTK_BOX (st_box), this->st, FALSE, FALSE, 5);
	
	// add ic_box to cpu box
	gtk_box_pack_start (GTK_BOX (cpu_box), ic_box, FALSE, FALSE, 5);
	gtk_box_pack_end (GTK_BOX (cpu_box), st_box, FALSE, FALSE, 5);
	
	// put cpu_box in cpu_frame
	gtk_container_add (GTK_CONTAINER (cpu_frame), cpu_box);

	// left top box
	GtkWidget * left_top_box;
	left_top_box = gtk_hbox_new (FALSE, 5);
	gtk_box_pack_start (GTK_BOX (left_top_box), cpu_frame, FALSE, FALSE, 0);
	this->left_box = gtk_vbox_new (FALSE, 0);
	gtk_box_pack_start (GTK_BOX (this->left_box), left_top_box, FALSE, FALSE, 0);


        // CHANNELS

        // channels frame
	GtkWidget * channels_frame;
	channels_frame = gtk_frame_new ("CHANNELS");

        GtkWidget * channels_vbox;
        channels_vbox = gtk_vbox_new (FALSE, 5);


        // keyboard
        GtkWidget * kb_box;
	kb_box = gtk_hbox_new (FALSE, 0);
        GtkWidget * kb_label;
	kb_label = gtk_label_new ("KEYBOARD");
        gtk_widget_set_usize (kb_label, 80, 28);
        this->keyboard_channel = gtk_entry_new ();
	gtk_entry_set_editable (GTK_ENTRY(this->keyboard_channel), FALSE);
	gtk_widget_set_can_focus (this->keyboard_channel, FALSE);
        gtk_box_pack_start (GTK_BOX (kb_box), kb_label, FALSE, FALSE, 20);
	gtk_box_pack_end (GTK_BOX (kb_box), this->keyboard_channel, FALSE, FALSE, 5);

        gtk_box_pack_start (GTK_BOX (channels_vbox ), kb_box, FALSE, FALSE, 0);


        // monitor
        GtkWidget * mn_box;
	mn_box = gtk_hbox_new (FALSE, 0);
        GtkWidget * mn_label;
	mn_label = gtk_label_new ("MONITOR");
        gtk_widget_set_usize (mn_label, 80, 28);
        this->monitor_channel = gtk_entry_new ();
	gtk_entry_set_editable (GTK_ENTRY(this->monitor_channel), FALSE);
	gtk_widget_set_can_focus (this->monitor_channel, FALSE);
        gtk_box_pack_start (GTK_BOX (mn_box), mn_label, FALSE, FALSE, 20);
	gtk_box_pack_end (GTK_BOX (mn_box), this->monitor_channel, FALSE, FALSE, 5);
        gtk_box_pack_start (GTK_BOX (channels_vbox), mn_box, FALSE, FALSE, 0);

        // hdd
        GtkWidget * hdd_box;
	hdd_box = gtk_hbox_new (FALSE, 0);
        GtkWidget * hdd_label;
	hdd_label = gtk_label_new ("HDD");
        gtk_widget_set_usize (hdd_label, 80, 28);
        this->hdd_channel = gtk_entry_new ();
	gtk_entry_set_editable (GTK_ENTRY(this->hdd_channel), FALSE);
	gtk_widget_set_can_focus (this->hdd_channel, FALSE);
        gtk_box_pack_start (GTK_BOX (hdd_box), hdd_label, FALSE, FALSE, 20);
	gtk_box_pack_end (GTK_BOX (hdd_box), this->hdd_channel, FALSE, FALSE, 5);
        gtk_box_pack_start (GTK_BOX (channels_vbox), hdd_box, FALSE, FALSE, 0);


        gtk_container_add (GTK_CONTAINER (channels_frame), channels_vbox);
        gtk_box_pack_start (GTK_BOX (this->left_box), channels_frame, FALSE, FALSE, 0);
        
        GtkWidget * control_buttons;
        control_buttons = gtk_vbutton_box_new ();

        this->rm_mem_show_button = gtk_button_new_with_label("Show RM memory");
        g_signal_connect (this->rm_mem_show_button, "clicked", G_CALLBACK (GUI::rm_mem_show_button_clicked), gpointer(this));

        gtk_box_pack_start (GTK_BOX (control_buttons), this->rm_mem_show_button, FALSE, FALSE, 0);
        gtk_box_pack_start (GTK_BOX (this->left_box), control_buttons, FALSE, FALSE, 0);

}

void GUI::setup_right_box(){
	this->right_box = gtk_vbox_new (FALSE, 0);
	
	// 
	GtkWidget * vm_programs_frame;
	vm_programs_frame = gtk_frame_new ("Add VM program");

	GtkWidget * add_file_vbox;
	add_file_vbox = gtk_vbox_new(FALSE, 0);

	// p_files_box
	GtkWidget * add_file_box;
	add_file_box = gtk_hbox_new(FALSE, 0);
	
	// add file button
        this->add_chooser_filter = gtk_file_filter_new ();
        gtk_file_filter_add_pattern (this->add_chooser_filter, "*.prg");

	this->add_chooser =  gtk_file_chooser_button_new ( "Select a file", GTK_FILE_CHOOSER_ACTION_OPEN);
            
        gtk_file_chooser_add_filter (GTK_FILE_CHOOSER(this->add_chooser), this->add_chooser_filter);
	gtk_widget_set_usize (this->add_chooser, 250, 28);
	gtk_box_pack_start (GTK_BOX (add_file_box), this->add_chooser, FALSE, FALSE, 5);
	
	this->add_file = gtk_button_new_with_label("Add");
        g_signal_connect (this->add_file, "clicked", G_CALLBACK (GUI::add_file_clicked), gpointer(this));
	gtk_widget_set_usize (this->add_file, 100, 28);
	gtk_box_pack_start (GTK_BOX (add_file_box), this->add_file, FALSE, FALSE, 5);
	
	gtk_box_pack_start (GTK_BOX (add_file_vbox), add_file_box, FALSE, FALSE, 5);
	// add 
	gtk_container_add (GTK_CONTAINER (vm_programs_frame), add_file_vbox);

	// add vm_programs_frame to right_box
	gtk_box_pack_start (GTK_BOX (this->right_box), vm_programs_frame, FALSE, FALSE, 0);

	// programs notebook
	this->programs_notebook = gtk_notebook_new();
        gtk_widget_set_usize (this->programs_notebook, 600, 400);

        gtk_box_pack_start (GTK_BOX (this->right_box), this->programs_notebook, FALSE, FALSE, 5);
        
}





void GUI::start(){
    gtk_init (&this->argc, &this->argv);
    this->setup_main_window();
    this->setup_main_box();
    this->add_empty_notebook_window();

   
    /* and the window */
    gtk_widget_show_all(this->window);

    /* All GTK applications must have a gtk_main(). Control ends here
     * and waits for an event to occur (like a key press or
     * mouse event). */
    gtk_main();
    return;
}

gboolean GUI::main_window_delete_event(	GtkWidget 	*widget, 
                                        GdkEvent 	*event,
                                        gpointer        data )
{
    /* If you return FALSE in the "delete-event" signal handler,
     * GTK will emit the "destroy" signal. Returning TRUE means
     * you don't want the window to be destroyed.
     * This is useful for popping up 'are you sure you want to quit?'
     * type dialogs. */
    g_print ("main_window_delete\n");
    /* Change TRUE to FALSE and the main window will be destroyed with
     * a "delete-event". */
    return FALSE;
}

void GUI::main_window_destroy(GtkWidget *widget, gpointer data){
	gtk_main_quit();
}



void GUI::add_file_clicked( GtkWidget *widget, gpointer guiObject){
    g_print ("Add file clicked.\n");
    gchar * selected_file_path;
    selected_file_path = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER( ((GUI*)guiObject)->add_chooser) );
    if (selected_file_path != NULL){
        g_print ("Added file path: %s\n", selected_file_path);
        ((GUI*)guiObject)->add_program_file(selected_file_path);
    }
}

void GUI::add_program_file(gchar * filepath){
    if (this->is_empty_notebook){
        this->is_empty_notebook = false;
        gtk_notebook_remove_page(GTK_NOTEBOOK(this->programs_notebook), this->empty_notebook_index);
    }
    GuiNotebookItem notebook_item;

    notebook_item.vmachine = NULL;
    notebook_item.filepath = filepath;
    // netobook label
    notebook_item.notebook_label_text = this->extract_file_name(notebook_item.filepath);
    notebook_item.notebook_label = gtk_label_new (notebook_item.notebook_label_text);

    // create inner notebook vbox
    notebook_item.notebook_vbox = gtk_vbox_new(FALSE, 0);
    
    // create scrolled_window
    notebook_item.notebook_scrolled_window = gtk_scrolled_window_new (NULL, NULL);
    gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (notebook_item.notebook_scrolled_window),
                                    GTK_POLICY_AUTOMATIC,
                                    GTK_POLICY_AUTOMATIC);
    
    gtk_box_pack_start (GTK_BOX (notebook_item.notebook_vbox),
                        notebook_item.notebook_scrolled_window,
                        TRUE, // vbox gives widget all remaining space
                        TRUE, // widget expands to fill given space
                        0); // pixel of padding around the widget

    // create notebook_source_view
    notebook_item.source_buffer = gtk_source_buffer_new (NULL);
    
    notebook_item.source_view = gtk_source_view_new_with_buffer(notebook_item.source_buffer);
    gtk_container_add (GTK_CONTAINER (notebook_item.notebook_scrolled_window), notebook_item.source_view);

    gtk_source_view_set_auto_indent (   GTK_SOURCE_VIEW (notebook_item.source_view),
                                        TRUE);
    // make a tab be two spaces
    gtk_source_view_set_indent_width (GTK_SOURCE_VIEW (notebook_item.source_view),
                                        2);
    gtk_source_view_set_highlight_current_line (GTK_SOURCE_VIEW (notebook_item.source_view),
                                                TRUE);
    gtk_source_view_set_show_line_numbers ( GTK_SOURCE_VIEW (notebook_item.source_view),
                                            TRUE);
    gtk_source_view_set_right_margin_position ( GTK_SOURCE_VIEW (notebook_item.source_view),
                                                80); // default is 70 chars
    gtk_source_view_set_show_right_margin ( GTK_SOURCE_VIEW (notebook_item.source_view),
                                            TRUE);
    gtk_text_view_set_wrap_mode (   GTK_TEXT_VIEW (notebook_item.source_view),
                                    GTK_WRAP_WORD_CHAR);
    gtk_text_view_set_editable  (   GTK_TEXT_VIEW (notebook_item.source_view),
                                    FALSE);
    gtk_text_view_set_cursor_visible (  GTK_TEXT_VIEW (notebook_item.source_view),
                                        FALSE);

    /* setup view */
    PangoFontDescription * font_desc = NULL;
    font_desc = pango_font_description_from_string ("monospace");
    if (font_desc != NULL){
        gtk_widget_modify_font (notebook_item.source_view, font_desc);
        pango_font_description_free (font_desc);
    }


    // get file content
    gchar * buffer;
    GError * error_here = NULL;

    if (g_file_get_contents (notebook_item.filepath, &buffer, NULL, &error_here)){
        gtk_source_buffer_begin_not_undoable_action (notebook_item.source_buffer);
        gtk_source_buffer_begin_not_undoable_action (notebook_item.source_buffer);
        gtk_text_buffer_set_text (GTK_TEXT_BUFFER (notebook_item.source_buffer), buffer, -1);
        gtk_source_buffer_end_not_undoable_action (notebook_item.source_buffer);
        gtk_text_buffer_set_modified (GTK_TEXT_BUFFER (notebook_item.source_buffer), FALSE);

        /* move cursor to the beginning */
        gtk_text_buffer_get_start_iter (GTK_TEXT_BUFFER (notebook_item.source_buffer), &notebook_item.iter);
        gtk_text_buffer_place_cursor (GTK_TEXT_BUFFER (notebook_item.source_buffer), &notebook_item.iter);
        
        {
            GtkTextIter start, end;
            char *text;
            gtk_text_buffer_get_bounds (GTK_TEXT_BUFFER (notebook_item.source_buffer), &start, &end);
            text = gtk_text_buffer_get_text (GTK_TEXT_BUFFER (notebook_item.source_buffer), &start, &end, TRUE);
            g_assert (!strcmp (text, buffer));
            g_free (text);
        }
        g_free (buffer);


        GtkWidget * vm_frame;
        vm_frame = gtk_frame_new ("VM operations");

        // create buttons
        notebook_item.notebook_button_hbox = gtk_hbox_new (FALSE, 0);
        notebook_item.run_step_button = gtk_button_new_with_label ("Run Step");
        notebook_item.run_button = gtk_button_new_with_label ("Run");
        notebook_item.view_vm_mem = gtk_button_new_with_label ("View Vm memory");

        // create time out input
        notebook_item.timeout_field = gtk_entry_new_with_max_length(10);

        GtkWidget * timeout_label;
        timeout_label = gtk_label_new("Timeout:");


        g_signal_connect (notebook_item.run_step_button, "clicked", G_CALLBACK (GUI::run_step_button_clicked), gpointer(this));
        g_signal_connect (notebook_item.run_button, "clicked", G_CALLBACK (GUI::run_button_clicked), gpointer(this));
        g_signal_connect (notebook_item.view_vm_mem, "clicked", G_CALLBACK (GUI::view_vm_mem_clicked), gpointer(this));


        gtk_box_pack_start (GTK_BOX (notebook_item.notebook_button_hbox),
                            notebook_item.view_vm_mem,
                            FALSE, // vbox gives widget all remaining space
                            FALSE, // widget expands to fill given space
                            5); // pixel of padding around the widget

        gtk_box_pack_start (GTK_BOX (notebook_item.notebook_button_hbox),
                            notebook_item.run_step_button,
                            FALSE, // vbox gives widget all remaining space
                            FALSE, // widget expands to fill given space
                            5); // pixel of padding around the widget

        gtk_box_pack_start (GTK_BOX (notebook_item.notebook_button_hbox),
                            timeout_label,
                            FALSE, // vbox gives widget all remaining space
                            FALSE, // widget expands to fill given space
                            5); // pixel of padding around the widget

        gtk_box_pack_start (GTK_BOX (notebook_item.notebook_button_hbox),
                            notebook_item.timeout_field,
                            FALSE, // vbox gives widget all remaining space
                            FALSE, // widget expands to fill given space
                            5); // pixel of padding around the widget

        gtk_box_pack_start (GTK_BOX (notebook_item.notebook_button_hbox),
                            notebook_item.run_button,
                            FALSE, // vbox gives widget all remaining space
                            FALSE, // widget expands to fill given space
                            5); // pixel of padding around the widget

        gtk_container_add(GTK_CONTAINER (vm_frame), notebook_item.notebook_button_hbox);
        
        gtk_box_pack_start (GTK_BOX (notebook_item.notebook_vbox),
                            vm_frame,
                            FALSE, // vbox gives widget all remaining space
                            FALSE, // widget expands to fill given space
                            5);

        gtk_notebook_append_page(   GTK_NOTEBOOK(this->programs_notebook),
                                    notebook_item.notebook_vbox,
                                    notebook_item.notebook_label);
        this->gui_notebook_item_list.push_back(notebook_item);
        gtk_widget_show_all(this->programs_notebook);
    } else {
        g_print("WRONG \n");
    }
}

void GUI::add_empty_notebook_window(){
    GtkWidget * label;
    GtkWidget * content_label;

    gchar * text = (gchar *) "No file selected";
    
    label = gtk_label_new (text);
    content_label = gtk_label_new (text);

    this->empty_notebook_index = gtk_notebook_append_page(  GTK_NOTEBOOK(this->programs_notebook),
                                                            label,
                                                            content_label);
    this->is_empty_notebook = true;
    gtk_widget_show_all(this->programs_notebook);
}

gchar * GUI::extract_file_name(gchar * filepath){
    std::string temp = "";
    bool found = false;
    int length = strlen(filepath);
    length--;
    while ((length >= 0) && !found){
        if (filepath[length] != '/'){
            temp += filepath[length];
            length--;
        } else {
            found = true;
        }
    }
    std::reverse (temp.begin(), temp.end());
    gchar * filename = (char*)temp.c_str();
    return filename;
}



void GUI::run_button_clicked( GtkWidget *widget, gpointer guiObject){
    g_print("run button clicked\n");
    ((GUI*)guiObject)->run_program(widget);
    return;
}

void GUI::run_program(GtkWidget * button_widget){
    std::vector<GuiNotebookItem>::iterator iter;
    iter = this->gui_notebook_item_list.begin();
    bool widget_found = false;
    GuiNotebookItem * needed_item;
    while( (iter != this->gui_notebook_item_list.end()) && !widget_found) {
        needed_item = & *iter;
        if (button_widget == needed_item->run_button){
            widget_found = true;
        }
        ++iter;
    }

    if (needed_item->vmachine == NULL){
        needed_item->vmachine = new vm(this->rmachine, (int)this->vmnumber, needed_item->filepath);
        this->vmnumber++;
    }

    gchar * timeout_temp = ( gchar* ) gtk_entry_get_text( GTK_ENTRY ( needed_item->timeout_field) );
    gulong timeout_wait = (gulong) atoi(timeout_temp);

    while (needed_item->vmachine->finish == false ){
        this->run_program_step(button_widget);
        GTimer * timeout;
        gulong elapsed_time_microsec;
        gdouble elapsed_time;
        timeout = g_timer_new();
        g_timer_start(timeout);
        elapsed_time = g_timer_elapsed(timeout, &elapsed_time_microsec);
        while ( elapsed_time_microsec < timeout_wait){
            elapsed_time = g_timer_elapsed(timeout, &elapsed_time_microsec);
        }
        g_timer_destroy (timeout);
    }
    return;
}

void GUI::run_step_button_clicked ( GtkWidget * widget, gpointer guiObject ){
    g_print("run_step_button_clicked\n");
    ((GUI*)guiObject)->run_program_step(widget);
}

void GUI::run_program_step(GtkWidget * button_widget){
    std::vector<GuiNotebookItem>::iterator iter;
    iter = this->gui_notebook_item_list.begin();
    bool widget_found = false;
    GuiNotebookItem * needed_item;
    while( (iter != this->gui_notebook_item_list.end()) && !widget_found) {
        needed_item = & *iter;
        if (button_widget == needed_item->run_button){
            widget_found = true;
        }
        ++iter;
    }

    if (needed_item->vmachine == NULL){
        needed_item->vmachine = new vm(this->rmachine, (int)this->vmnumber, needed_item->filepath);
        this->vmnumber++;
    }

    std::string temp_reg;
    std::stringstream out;

    if (needed_item->vmachine->finish == false ){
        needed_item->vmachine->step();

        out.str("");
        out << needed_item->vmachine->IC;
        temp_reg = out.str();
        this->rmword->renew("10", temp_reg);
        temp_reg = this->rmword->hexadimal();
        gtk_entry_buffer_set_text (this->ic_buffer, temp_reg.c_str(), -1);

        temp_reg = "";
        out.str("");
        out << needed_item->vmachine->ST;
        out >> temp_reg;
        this->rmword->renew("10", temp_reg);
        temp_reg = this->rmword->hexadimal();
        gtk_entry_buffer_set_text (this->st_buffer, temp_reg.c_str(), -1);
    }
    gtk_widget_draw(GTK_WIDGET(this->ic), NULL);
    gtk_widget_draw(GTK_WIDGET(this->st), NULL);
    if (needed_item->vm_mem != NULL){
        if (needed_item->vm_mem->mem_window != NULL){
            needed_item->vm_mem->redraw();
        }
    }
    if (this->rm_mem != NULL){
        if (this->rm_mem->mem_window != NULL){
            this->rm_mem->redraw();
        }
    }
}


void GUI::rm_mem_show_button_clicked ( GtkWidget *widget, gpointer guiObject ){
    ((GUI*)guiObject)->rm_mem = new GuiMemoryWindow( ((GUI*)guiObject)->rmachine->memory );
    ((GUI*)guiObject)->rm_mem->show_window();
}

void GUI::view_vm_mem_clicked(GtkWidget* widget, gpointer guiObject){
    ((GUI*)guiObject)->show_vm_memory(widget);
}

void GUI::show_vm_memory(GtkWidget * widget){
    std::vector<GuiNotebookItem>::iterator iter;
    iter = this->gui_notebook_item_list.begin();
    bool widget_found = false;
    GuiNotebookItem * needed_item;
    while( (iter != this->gui_notebook_item_list.end()) && !widget_found) {
        needed_item = & *iter;
        if (widget == needed_item->view_vm_mem){
            widget_found = true;
        }
        ++iter;
    }

    if (needed_item->vmachine == NULL){
        needed_item->vmachine = new vm(this->rmachine, (int)this->vmnumber, needed_item->filepath);
        this->vmnumber++;
    }

    needed_item->vm_mem = new GuiMemoryWindow(this->rmachine->memory);
    needed_item->vm_mem->is_vm = true;
    needed_item->vm_mem->rm = this->rmachine;
    needed_item->vm_mem->vmachine = needed_item->vmachine;
    needed_item->vm_mem->show_window();
}

