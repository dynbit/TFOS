#include <gtk/gtk.h>
#include "word.h"
#include "vm.h"
#include "realmachine.h"

#ifndef _GUI_H
#define	_GUI_H

class GUI {
	public: 
		GUI(int argc, char *argv[]);
		void start();
	private:
		int argc;
		char **argv;
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
		GtkWidget *select_file_frame;
		GtkWidget *file_chooser;
		
		/* Local variables */
		gchar** files_list;
	
		void show_file_chooser();
		static void init_file_chooser(GtkWidget *widget, gpointer data);
		static void add_file(GtkWidget *widget, gpointer);
		static gboolean delete_event( GtkWidget *widget, GdkEvent  *event, gpointer data);
		static void destroy(GtkWidget *widget, gpointer data);
};

#endif	/* _GUI_H */
