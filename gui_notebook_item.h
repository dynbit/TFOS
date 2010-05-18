#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <gtk-2.0/gtk/gtk.h>
#include <gtksourceview-2.0/gtksourceview/gtksourceview.h>
#include <gtksourceview-2.0/gtksourceview/gtksourcebuffer.h>
#include <gtksourceview-2.0/gtksourceview/gtksourcelanguage.h>
#include <gtksourceview-2.0/gtksourceview/gtksourcelanguagemanager.h>
#include <gtksourceview-2.0/gtksourceview/gtksourcestyleschememanager.h>
#include <gtksourceview-2.0/gtksourceview/gtksourceprintcompositor.h>
#include <gtksourceview-2.0/gtksourceview/gtksourceiter.h>

#include "vm.h"
#include "gui_memory_window.h"

#ifndef _GUI_NOTEBOOK_ITEM_H
#define	_GUI_NOTEBOOK_ITEM_H

class GuiNotebookItem {
public:
    vm * vmachine;
    gchar * filepath;
    GtkWidget * notebook_label;
    gchar * notebook_label_text;
    
    GtkWidget * notebook;
    GtkWidget * notebook_vbox;
    GtkWidget * notebook_scrolled_window;

    GtkWidget * source_view;
    GtkSourceBuffer * source_buffer;
    GtkTextIter iter;

    GtkWidget * notebook_button_hbox;
    GtkWidget * run_button;
    GtkWidget * run_step_button;
    GtkWidget * view_vm_mem;

    GtkWidget * timeout_field;

    gint * step_timeout;

    GuiMemoryWindow * vm_mem;

    GuiNotebookItem();
};



#endif	/* _GUI_NOTEBOOK_ITEM_H */

