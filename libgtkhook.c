#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>
#include <gtk/gtk.h>

// Function pointers for original GTK functions
typedef void (*gtk_button_clicked_func)(GtkButton *);
typedef GtkWidget *(*gtk_button_new_func)(void);
typedef GtkWidget *(*gtk_label_new_func)(const gchar *);
typedef GtkWidget *(*gtk_window_new_func)(GtkWindowType);
typedef GtkWidget *(*gtk_entry_new_func)(void);
typedef GtkWidget *(*gtk_image_new_from_file_func)(const gchar *);
typedef void (*gtk_widget_show_func)(GtkWidget *);
typedef GtkWidget *(*gtk_button_new_with_label_func)(const gchar *);
typedef void (*gtk_widget_hide_func)(GtkWidget *);
typedef void (*gtk_widget_set_sensitive_func)(GtkWidget *, gboolean);
typedef void (*gtk_container_add_func)(GtkContainer *, GtkWidget *);
typedef void (*gtk_container_remove_func)(GtkContainer *, GtkWidget *);
typedef GtkWidget *(*gtk_box_new_func)(GtkOrientation, gint);
typedef GtkWidget *(*gtk_grid_new_func)(void);
typedef GtkWidget *(*gtk_dialog_new_func)(void);
typedef gint (*gtk_dialog_run_func)(GtkDialog *);
typedef GtkWidget *(*gtk_dialog_add_button_func)(GtkDialog *, const gchar *, gint);
typedef GtkWidget *(*gtk_message_dialog_new_func)(GtkWindow *, GtkDialogFlags, GtkMessageType, GtkButtonsType, const gchar *, ...);
typedef GtkCssProvider *(*gtk_css_provider_new_func)(void);
typedef void (*gtk_style_context_add_class_func)(GtkStyleContext *, const gchar *);
typedef void (*gtk_widget_set_size_request_func)(GtkWidget *, gint, gint);
typedef void (*gtk_main_func)(void);
typedef void (*gtk_main_quit_func)(void);

void gtk_button_clicked(GtkButton *button)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);
    
    gtk_button_clicked_func original_gtk_button_clicked = 
        (gtk_button_clicked_func)dlsym(RTLD_NEXT, "gtk_button_clicked");

    original_gtk_button_clicked(button);
}

GtkWidget *gtk_button_new(void)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);

    gtk_button_new_func original_gtk_button_new = (gtk_button_new_func)dlsym(RTLD_NEXT, "gtk_button_new");

    return original_gtk_button_new();
}

GtkWidget *gtk_label_new(const gchar *str)
{
    static uint64_t counter = 0;
    printf("%s with '%s': %lu\n", __func__, str, counter++);

    gtk_label_new_func original_gtk_label_new = (gtk_label_new_func)dlsym(RTLD_NEXT, "gtk_label_new");

    return original_gtk_label_new(str);
}

GtkWidget *gtk_window_new(GtkWindowType type)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);

    gtk_window_new_func original_gtk_window_new = (gtk_window_new_func)dlsym(RTLD_NEXT, "gtk_window_new");

    return original_gtk_window_new(type);
}

GtkWidget *gtk_entry_new(void)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);

    gtk_entry_new_func original_gtk_entry_new = (gtk_entry_new_func)dlsym(RTLD_NEXT, "gtk_entry_new");

    return original_gtk_entry_new();
}

GtkWidget *gtk_image_new_from_file(const gchar *filename)
{
    static uint64_t counter = 0;
    printf("%s from '%s': %lu\n", __func__, filename, counter++);

    gtk_image_new_from_file_func original_gtk_image_new_from_file =
        (gtk_image_new_from_file_func)dlsym(RTLD_NEXT, "gtk_image_new_from_file");

    return original_gtk_image_new_from_file(filename);
}


void gtk_widget_show(GtkWidget *widget)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);
  
    gtk_widget_show_func original_gtk_widget_show = (gtk_widget_show_func)dlsym(RTLD_NEXT, "gtk_widget_show");
    
    original_gtk_widget_show(widget);
}


GtkWidget *gtk_button_new_with_label(const gchar *label)
{
    static uint64_t counter = 0;
    printf("%s '%s': %lu\n", __func__, label, counter++);
    
    gtk_button_new_with_label_func original_gtk_button_new_with_label =
        (gtk_button_new_with_label_func)dlsym(RTLD_NEXT, "gtk_button_new_with_label");

    return original_gtk_button_new_with_label(label);
}


void gtk_widget_hide(GtkWidget *widget)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);
    
    gtk_widget_hide_func original_gtk_widget_hide = (gtk_widget_hide_func)dlsym(RTLD_NEXT, "gtk_widget_hide");
    
    original_gtk_widget_hide(widget);
}


void gtk_widget_set_sensitive(GtkWidget *widget, gboolean sensitive)
{
    static uint64_t counter = 0;
    printf("%s to %d: %lu\n", __func__, sensitive, counter++);
    
    gtk_widget_set_sensitive_func original_gtk_widget_set_sensitive =
        (gtk_widget_set_sensitive_func)dlsym(RTLD_NEXT, "gtk_widget_set_sensitive");
    
    original_gtk_widget_set_sensitive(widget, sensitive);
}


void gtk_container_add(GtkContainer *container, GtkWidget *widget)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);
    
    gtk_container_add_func original_gtk_container_add = (gtk_container_add_func)dlsym(RTLD_NEXT, "gtk_container_add");
    
    original_gtk_container_add(container, widget);
}


void gtk_container_remove(GtkContainer *container, GtkWidget *widget)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);
    
    gtk_container_remove_func original_gtk_container_remove =
        (gtk_container_remove_func)dlsym(RTLD_NEXT, "gtk_container_remove");
    
    original_gtk_container_remove(container, widget);
}


GtkWidget *gtk_box_new(GtkOrientation orientation, gint spacing)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);
    
    gtk_box_new_func original_gtk_box_new = (gtk_box_new_func)dlsym(RTLD_NEXT, "gtk_box_new");
    
    return original_gtk_box_new(orientation, spacing);
}


GtkWidget *gtk_grid_new(void)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);
    
    gtk_grid_new_func original_gtk_grid_new = (gtk_grid_new_func)dlsym(RTLD_NEXT, "gtk_grid_new");
    
    return original_gtk_grid_new();
}

GtkWidget *gtk_dialog_new(void)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);
    
    gtk_dialog_new_func original_gtk_dialog_new = (gtk_dialog_new_func)dlsym(RTLD_NEXT, "gtk_dialog_new");
    
    return original_gtk_dialog_new();
}


gint gtk_dialog_run(GtkDialog *dialog)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);
    
    gtk_dialog_run_func original_gtk_dialog_run = (gtk_dialog_run_func)dlsym(RTLD_NEXT, "gtk_dialog_run");
    
    return original_gtk_dialog_run(dialog);
}


GtkWidget *gtk_dialog_add_button(GtkDialog *dialog, const gchar *button_text, gint response_id)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);
    
    gtk_dialog_add_button_func original_gtk_dialog_add_button =
        (gtk_dialog_add_button_func)dlsym(RTLD_NEXT, "gtk_dialog_add_button");
    
    return original_gtk_dialog_add_button(dialog, button_text, response_id);
}


GtkWidget *gtk_message_dialog_new(GtkWindow *parent_window, GtkDialogFlags flags, GtkMessageType type,
                                  GtkButtonsType buttons_type, const gchar *message_format, ...)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);
    
    gtk_message_dialog_new_func original_gtk_message_dialog_new =
        (gtk_message_dialog_new_func)dlsym(RTLD_NEXT, "gtk_message_dialog_new");
    
    va_list args;
    va_start(args, message_format);
    GtkWidget *dialog = original_gtk_message_dialog_new(parent_window, flags, type, buttons_type, message_format, args);
    va_end(args);

    return dialog;
}


GtkCssProvider *gtk_css_provider_new(void)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);
    
    gtk_css_provider_new_func original_gtk_css_provider_new =
        (gtk_css_provider_new_func)dlsym(RTLD_NEXT, "gtk_css_provider_new");
    
    return original_gtk_css_provider_new();
}


void gtk_style_context_add_class(GtkStyleContext *context, const gchar *class_name)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);
    
    gtk_style_context_add_class_func original_gtk_style_context_add_class =
        (gtk_style_context_add_class_func)dlsym(RTLD_NEXT, "gtk_style_context_add_class");
    
    original_gtk_style_context_add_class(context, class_name);
}


void gtk_widget_set_size_request(GtkWidget *widget, gint width, gint height)
{
    static uint64_t counter = 0;
    printf("%s to %d x %d: %lu\n", __func__, width, height, counter++);
    
    gtk_widget_set_size_request_func original_gtk_widget_set_size_request =
        (gtk_widget_set_size_request_func)dlsym(RTLD_NEXT, "gtk_widget_set_size_request");
    
    original_gtk_widget_set_size_request(widget, width, height);
}


void gtk_main(void)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);
    
    gtk_main_func original_gtk_main = (gtk_main_func)dlsym(RTLD_NEXT, "gtk_main");
    
    original_gtk_main();
}


void gtk_main_quit(void)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);
    
    gtk_main_quit_func original_gtk_main_quit = (gtk_main_quit_func)dlsym(RTLD_NEXT, "gtk_main_quit");
    
    original_gtk_main_quit();
}
