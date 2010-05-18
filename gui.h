#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <gtksourceview-2.0/gtksourceview/gtksourceview.h>
#include <gtksourceview-2.0/gtksourceview/gtksourcebuffer.h>
#include <gtksourceview-2.0/gtksourceview/gtksourcelanguage.h>
#include <gtksourceview-2.0/gtksourceview/gtksourcelanguagemanager.h>
#include <gtksourceview-2.0/gtksourceview/gtksourcestyleschememanager.h>
#include <gtksourceview-2.0/gtksourceview/gtksourceprintcompositor.h>
#include <gtksourceview-2.0/gtksourceview/gtksourceiter.h>
#include <glib.h>




#include "word.h"
#include "vm.h"
#include "realmachine.h"
#include "gui_notebook_item.h"
#include "gui_memory_window.h"


#ifndef _GUI_H
#define	_GUI_H



class GUI {
	public: 
		GUI(int argc, char *argv[]);
		void start();
	private:
		int argc;
		char **argv;

                // machines
                realmachine * rmachine;
                word * rmword;
                gint vmnumber;

		
		GtkWidget *window;
		
		GtkWidget *main_box;
		
		GtkWidget *left_box;
		GtkWidget *right_box;
		
		
		GtkWidget *st;
                GtkEntryBuffer *st_buffer;
		GtkWidget *ic;
                GtkEntryBuffer *ic_buffer;

                GtkWidget * keyboard_channel;
                GtkWidget * monitor_channel;
                GtkWidget * hdd_channel;

                GtkWidget * rm_mem_show_button;
                GuiMemoryWindow * rm_mem;

                std::vector <GuiNotebookItem> gui_notebook_item_list;

		GtkWidget *programs_notebook;
                bool is_empty_notebook;
                gint empty_notebook_index;
		
		// buttons
		GtkWidget *add_chooser;
                GtkFileFilter * add_chooser_filter;
		GtkWidget *add_file;
		GtkWidget *load_program;
	
		
		
		void setup_main_window();
		
		void setup_main_box();
		
		void setup_left_box();
		void setup_right_box();

                std::string read_file(char * filepath);

                void add_empty_notebook_window();
		void add_program_file(gchar * filepath);
                void run_program(GtkWidget * button_widget);
                void run_program_step(GtkWidget * button_widget);

                //void show_rm_memory();
                void show_vm_memory(GtkWidget * widget);

                gchar * extract_file_name(gchar * filepath);
                static void add_file_clicked( GtkWidget *widget, gpointer guiObject);
		static gboolean main_window_delete_event( GtkWidget *widget, GdkEvent  *event, gpointer data);
		static void main_window_destroy(GtkWidget *widget, gpointer data);

                static void run_button_clicked ( GtkWidget *widget, gpointer guiObject );
                static void run_step_button_clicked ( GtkWidget *widget, gpointer guiObject );

                static void rm_mem_show_button_clicked ( GtkWidget *widget, gpointer guiObject );

                static void view_vm_mem_clicked ( GtkWidget *widget, gpointer guiObject );
};

#endif	/* _GUI_H */
