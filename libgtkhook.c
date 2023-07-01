#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>
#include <gtk/gtk.h>

// Function pointers for original GTK functions
typedef void (*gtk_button_clicked_func)(GtkButton *);
typedef GtkWidget *(*gtk_button_new_func)(void);
typedef GtkWidget *(*gtk_label_new_func)(const gchar *);
typedef GtkWidget *(*gtk_window_new_func)(GtkWindowType);

void gtk_button_clicked(GtkButton *button) {
    // Your custom code here
    printf("gtk_button_clicked\n");
    
    gtk_button_clicked_func original_gtk_button_clicked = 
        (gtk_button_clicked_func)dlsym(RTLD_NEXT, "gtk_button_clicked");

    original_gtk_button_clicked(button);
}

GtkWidget *gtk_button_new(void)
{
    printf("gtk_button_new\n");

    gtk_button_new_func original_gtk_button_new = (gtk_button_new_func)dlsym(RTLD_NEXT, "gtk_button_new");

    return original_gtk_button_new();
}

GtkWidget *gtk_label_new(const gchar *str)
{
    printf("gtk_label_new with text '%s'\n", str);

    gtk_label_new_func original_gtk_label_new = (gtk_label_new_func)dlsym(RTLD_NEXT, "gtk_label_new");

    return original_gtk_label_new(str);
}

GtkWidget *gtk_window_new(GtkWindowType type)
{
    printf("gtk_window_new\n");

    gtk_window_new_func original_gtk_window_new = (gtk_window_new_func)dlsym(RTLD_NEXT, "gtk_window_new");

    return original_gtk_window_new(type);
}