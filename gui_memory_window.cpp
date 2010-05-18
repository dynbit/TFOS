#include <gtk-2.0/gtk/gtkcontainer.h>
#include <gtk-2.0/gtk/gtkwindow.h>
#include <gtk-2.0/gtk/gtktreeview.h>
#include <gtk-2.0/gtk/gtkscrolledwindow.h>

#include "gui_memory_window.h"

GuiMemoryWindow::GuiMemoryWindow(int * mem){
    this->memory = mem;
    this->is_vm = false;
    this->rmword = new word("10", "10");
}

void GuiMemoryWindow::show_window(){
    GtkWidget * sw;

    this->mem_window = gtk_window_new( GTK_WINDOW_TOPLEVEL );
    sw = gtk_scrolled_window_new (NULL, NULL);
    gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (sw),
                                    GTK_POLICY_NEVER,
                                    GTK_POLICY_AUTOMATIC);

    gtk_window_set_title ( GTK_WINDOW ( this->mem_window ), "Memory Window" );
    g_signal_connect (this->mem_window, "delete-event", G_CALLBACK (GuiMemoryWindow::mem_window_delete_event), NULL);
    g_signal_connect (this->mem_window, "destroy", G_CALLBACK (GuiMemoryWindow::mem_window_destroy), gpointer(this));

    this->mem_view = this->init_mem_view();
    if (this->is_vm){
        this->show_vm_mem();
    } else {
        this->show_mem();
    }
    

    gtk_container_add ( GTK_CONTAINER ( sw ), this->mem_view );

    gtk_container_add ( GTK_CONTAINER ( this->mem_window ), sw );

    gtk_widget_show_all(this->mem_window);
}

gboolean GuiMemoryWindow::mem_window_delete_event ( GtkWidget *widget, GdkEvent  *event, gpointer data ){
    return FALSE;
}


void GuiMemoryWindow::mem_window_destroy ( GtkWidget *widget, gpointer data ){
    ((GuiMemoryWindow*)data)->mem_window = NULL;
}


GtkWidget * GuiMemoryWindow::init_mem_view(){
    // types def
    GtkWidget           *tree_view_widget;
    GtkCellRenderer     *renderer;
    GtkTreeViewColumn   *column;
    GtkListStore        *store;

    std::string headers = "0123456789ABCDEF";

    // init tree view
    tree_view_widget = gtk_tree_view_new ();
    
    /* create and append the single column */
    renderer = gtk_cell_renderer_text_new ();

    unsigned int i;
    for(i = 0; i < headers.length(); i++){
        gchar temp_char = headers.at(i);
        column = gtk_tree_view_column_new_with_attributes (&temp_char, renderer,
                "text", i, NULL); // i ekvivalent too enums
        gtk_tree_view_append_column ( GTK_TREE_VIEW (tree_view_widget), column);
    }
    

    /* create the model and add to tree view */

    store = gtk_list_store_new (GMW_COLS, 
                                G_TYPE_STRING,
                                G_TYPE_STRING,
                                G_TYPE_STRING,
                                G_TYPE_STRING,
                                G_TYPE_STRING,
                                G_TYPE_STRING,
                                G_TYPE_STRING,
                                G_TYPE_STRING,
                                G_TYPE_STRING,
                                G_TYPE_STRING,
                                G_TYPE_STRING,
                                G_TYPE_STRING,
                                G_TYPE_STRING,
                                G_TYPE_STRING,
                                G_TYPE_STRING,
                                G_TYPE_STRING);

    gtk_tree_view_set_model (GTK_TREE_VIEW (tree_view_widget), GTK_TREE_MODEL (store));

    /* free reference to the store */

    //g_object_unref (store);

    return tree_view_widget;
}

void GuiMemoryWindow::show_mem(){
    GtkListStore            *store;
    GtkTreeIter             iter;

    store = GTK_LIST_STORE (gtk_tree_view_get_model (GTK_TREE_VIEW (this->mem_view)));

    
    std::string GWM_0_str;
    std::string GWM_1_str;
    std::string GWM_2_str;
    std::string GWM_3_str;
    std::string GWM_4_str;
    std::string GWM_5_str;
    std::string GWM_6_str;
    std::string GWM_7_str;
    std::string GWM_8_str;
    std::string GWM_9_str;
    std::string GWM_A_str;
    std::string GWM_B_str;
    std::string GWM_C_str;
    std::string GWM_D_str;
    std::string GWM_E_str;
    std::string GWM_F_str;

    int i = 0;
    for (i = 0; i< 65536; i = i + 15){
        gtk_list_store_append (store, &iter);
        GWM_0_str = this->int2hex(*(this->memory+i));
        GWM_1_str = this->int2hex(*(this->memory+i+1));
        GWM_2_str = this->int2hex(*(this->memory+i+2));
        GWM_3_str = this->int2hex(*(this->memory+i+3));
        GWM_4_str = this->int2hex(*(this->memory+i+4));
        GWM_5_str = this->int2hex(*(this->memory+i+5));
        GWM_6_str = this->int2hex(*(this->memory+i+6));
        GWM_7_str = this->int2hex(*(this->memory+i+7));
        GWM_8_str = this->int2hex(*(this->memory+i+8));
        GWM_9_str = this->int2hex(*(this->memory+i+9));
        GWM_A_str = this->int2hex(*(this->memory+i+10));
        GWM_B_str = this->int2hex(*(this->memory+i+11));
        GWM_C_str = this->int2hex(*(this->memory+i+12));
        GWM_D_str = this->int2hex(*(this->memory+i+13));
        GWM_E_str = this->int2hex(*(this->memory+i+14));
        GWM_F_str = this->int2hex(*(this->memory+i+15));

        gtk_list_store_set (store, &iter,
                        GMW_0, GWM_0_str.c_str(),
                        GMW_1, GWM_1_str.c_str(),
                        GMW_2, GWM_2_str.c_str(),
                        GMW_3, GWM_3_str.c_str(),
                        GMW_4, GWM_4_str.c_str(),
                        GMW_5, GWM_5_str.c_str(),
                        GMW_6, GWM_6_str.c_str(),
                        GMW_7, GWM_7_str.c_str(),
                        GMW_8, GWM_8_str.c_str(),
                        GMW_9, GWM_9_str.c_str(),
                        GMW_A, GWM_A_str.c_str(),
                        GMW_B, GWM_B_str.c_str(),
                        GMW_C, GWM_C_str.c_str(),
                        GMW_D, GWM_D_str.c_str(),
                        GMW_E, GWM_E_str.c_str(),
                        GMW_F, GWM_F_str.c_str(),
                        -1);
    }    
}

void GuiMemoryWindow::redraw(){
    GtkListStore *store;
    store = GTK_LIST_STORE (gtk_tree_view_get_model (GTK_TREE_VIEW (this->mem_view)));
    gtk_list_store_clear ( store );
    gtk_widget_draw(GTK_WIDGET(this->mem_window), NULL);
    if (this->is_vm){
        this->show_vm_mem();
    } else {
        this->show_mem();
    }
}

std::string GuiMemoryWindow::int2hex(int a){
    std::string temp = "";
    std::stringstream out;
    out.str("");
    out << a;
    temp = out.str();
    this->rmword->renew("10", temp);
    temp = this->rmword->hexadimal();
    while (temp.length() != 8){
        temp = "0" + temp;
    }
    return temp;
}

void GuiMemoryWindow::show_vm_mem(){
    if (this->vmachine == NULL && this->rm == NULL){
        return;
    }

    GtkListStore            *store;
    GtkTreeIter             iter;

    store = GTK_LIST_STORE (gtk_tree_view_get_model (GTK_TREE_VIEW (this->mem_view)));


    std::string GWM_0_str;
    std::string GWM_1_str;
    std::string GWM_2_str;
    std::string GWM_3_str;
    std::string GWM_4_str;
    std::string GWM_5_str;
    std::string GWM_6_str;
    std::string GWM_7_str;
    std::string GWM_8_str;
    std::string GWM_9_str;
    std::string GWM_A_str;
    std::string GWM_B_str;
    std::string GWM_C_str;
    std::string GWM_D_str;
    std::string GWM_E_str;
    std::string GWM_F_str;

    int i = this->vmachine->ID * 255;
    int iend = i + 255;
    for ( ;i < iend; i = i + 15){
        gtk_list_store_append (store, &iter);
        GWM_0_str = this->int2hex(*(this->memory+i));
        GWM_1_str = this->int2hex(*(this->memory+i+1));
        GWM_2_str = this->int2hex(*(this->memory+i+2));
        GWM_3_str = this->int2hex(*(this->memory+i+3));
        GWM_4_str = this->int2hex(*(this->memory+i+4));
        GWM_5_str = this->int2hex(*(this->memory+i+5));
        GWM_6_str = this->int2hex(*(this->memory+i+6));
        GWM_7_str = this->int2hex(*(this->memory+i+7));
        GWM_8_str = this->int2hex(*(this->memory+i+8));
        GWM_9_str = this->int2hex(*(this->memory+i+9));
        GWM_A_str = this->int2hex(*(this->memory+i+10));
        GWM_B_str = this->int2hex(*(this->memory+i+11));
        GWM_C_str = this->int2hex(*(this->memory+i+12));
        GWM_D_str = this->int2hex(*(this->memory+i+13));
        GWM_E_str = this->int2hex(*(this->memory+i+14));
        GWM_F_str = this->int2hex(*(this->memory+i+15));

        gtk_list_store_set (store, &iter,
                        GMW_0, GWM_0_str.c_str(),
                        GMW_1, GWM_1_str.c_str(),
                        GMW_2, GWM_2_str.c_str(),
                        GMW_3, GWM_3_str.c_str(),
                        GMW_4, GWM_4_str.c_str(),
                        GMW_5, GWM_5_str.c_str(),
                        GMW_6, GWM_6_str.c_str(),
                        GMW_7, GWM_7_str.c_str(),
                        GMW_8, GWM_8_str.c_str(),
                        GMW_9, GWM_9_str.c_str(),
                        GMW_A, GWM_A_str.c_str(),
                        GMW_B, GWM_B_str.c_str(),
                        GMW_C, GWM_C_str.c_str(),
                        GMW_D, GWM_D_str.c_str(),
                        GMW_E, GWM_E_str.c_str(),
                        GMW_F, GWM_F_str.c_str(),
                        -1);
    }    
}