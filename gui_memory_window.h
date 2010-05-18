/* 
 * File:   gui_memory_window.h
 * Author: vytautas
 *
 * Created on May 17, 2010, 10:23 PM
 */

#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
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
#include <glib-2.0/glib.h>
#include "word.h"
#include "realmachine.h"

#ifndef _GUI_MEMORY_WINDOW_H
#define	_GUI_MEMORY_WINDOW_H

enum {
    GMW_0 = 0,
    GMW_1,
    GMW_2,
    GMW_3,
    GMW_4,
    GMW_5,
    GMW_6,
    GMW_7,
    GMW_8,
    GMW_9,
    GMW_A,
    GMW_B,
    GMW_C,
    GMW_D,
    GMW_E,
    GMW_F,
    GMW_COLS
};

class GuiMemoryWindow {
    public:
        GtkWidget * mem_window;
        GtkWidget * mem_view;
        
        int * memory;
        word * rmword;
        bool is_vm;
        
        vm * vmachine;
        realmachine * rm;

        GuiMemoryWindow(int * mem);

        void show_window();
        void show_mem();
        void show_vm_mem();
        void redraw();
        std::string int2hex(int a);
        GtkWidget * init_mem_view();

        static gboolean mem_window_delete_event ( GtkWidget *widget, GdkEvent  *event, gpointer data );
        static void mem_window_destroy ( GtkWidget *widget, gpointer data );
        

};

#endif	/* _GUI_MEMORY_WINDOW_H */

