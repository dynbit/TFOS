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
		static gboolean delete_event( GtkWidget *widget, GdkEvent  *event, gpointer data);
		static void destroy(GtkWidget *widget, gpointer data);
};

#endif	/* _GUI_H */
