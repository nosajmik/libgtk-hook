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
typedef void (*gtk_text_view_insert_func)(GtkTextView *, GtkTextBuffer *, GtkTextIter *, const gchar *, gint);
typedef void (*gtk_text_buffer_insert_at_cursor_func)(GtkTextBuffer *, const gchar *, gint);
typedef void (*gtk_text_buffer_insert_func)(GtkTextBuffer *, GtkTextIter *, const gchar *, gint);
typedef void (*gtk_text_view_set_buffer_func)(GtkTextView *text_view, GtkTextBuffer *buffer);
typedef void (*gtk_text_view_scroll_to_mark_func)(GtkTextView *text_view, GtkTextMark *mark, gdouble within_margin, gboolean use_align, gdouble xalign, gdouble yalign);
typedef GtkTextBuffer *(*gtk_text_view_get_buffer_func)(GtkTextView *text_view);
typedef gchar *(*gtk_text_buffer_get_text_func)(GtkTextBuffer *buffer, const GtkTextIter *start, const GtkTextIter *end, gboolean include_hidden_chars);
typedef void (*gtk_text_buffer_delete_func)(GtkTextBuffer *buffer, GtkTextIter *start, GtkTextIter *end);
typedef void (*gtk_text_buffer_get_start_iter_func)(GtkTextBuffer *buffer, GtkTextIter *iter);
typedef void (*gtk_text_buffer_get_end_iter_func)(GtkTextBuffer *buffer, GtkTextIter *iter);
typedef void (*gtk_text_view_get_visible_rect_func)(GtkTextView *text_view, GdkRectangle *visible_rect);
typedef gboolean (*gtk_text_view_get_iter_at_position_func)(GtkTextView *text_view, GtkTextIter *iter, gint* trailing, gint x, gint y);
typedef void (*gtk_text_view_get_iter_location_func)(GtkTextView *text_view, const GtkTextIter *iter, GdkRectangle *location);
typedef gboolean (*gtk_text_view_get_iter_at_location_func)(GtkTextView *text_view, GtkTextIter *iter, gint x, gint y);
typedef void (*gtk_text_view_window_to_buffer_coords_func)(GtkTextView *text_view, GtkTextWindowType win, gint window_x, gint window_y, gint *buffer_x, gint *buffer_y);
typedef void (*gtk_text_view_buffer_to_window_coords_func)(GtkTextView *text_view, GtkTextWindowType win, gint buffer_x, gint buffer_y, gint *window_x, gint *window_y);
typedef void (*gtk_text_view_get_line_at_y_func)(GtkTextView *text_view, GtkTextIter *target_iter, gint y, gint *line_top);

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
    printf("%s: %s: %lu\n", __func__, class_name, counter++);
    
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

void gtk_text_view_insert(GtkTextView *text_view, GtkTextBuffer *buffer, GtkTextIter *iter,
                          const gchar *text, gint len)
{
    static uint64_t counter = 0;
    printf("%s: %.*s: %lu\n", __func__, len, text, counter++);

    gtk_text_view_insert_func original_gtk_text_view_insert =
        (gtk_text_view_insert_func)dlsym(RTLD_NEXT, "gtk_text_view_insert");

    original_gtk_text_view_insert(text_view, buffer, iter, text, len);
}

void gtk_text_buffer_insert_at_cursor(GtkTextBuffer *buffer, const gchar *text, gint len)
{
    static uint64_t counter = 0;
    printf("%s: '%s': %lu\n", __func__, text, counter++);

    gtk_text_buffer_insert_at_cursor_func original_gtk_text_buffer_insert_at_cursor =
        (gtk_text_buffer_insert_at_cursor_func)dlsym(RTLD_NEXT, "gtk_text_buffer_insert_at_cursor");

    original_gtk_text_buffer_insert_at_cursor(buffer, text, len);
}

void gtk_text_buffer_insert(GtkTextBuffer *buffer, GtkTextIter *iter, const gchar *text, gint len)
{
    static uint64_t counter = 0;
    printf("%s: '%.*s': %lu\n", __func__, len, text, counter++);

    gtk_text_buffer_insert_func original_gtk_text_buffer_insert =
        (gtk_text_buffer_insert_func)dlsym(RTLD_NEXT, "gtk_text_buffer_insert");

    original_gtk_text_buffer_insert(buffer, iter, text, len);
}

void gtk_text_view_set_buffer(GtkTextView *text_view, GtkTextBuffer *buffer)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);

    gtk_text_view_set_buffer_func original_gtk_text_view_set_buffer =
        (gtk_text_view_set_buffer_func)dlsym(RTLD_NEXT, "gtk_text_view_set_buffer");

    original_gtk_text_view_set_buffer(text_view, buffer);
}

void gtk_text_view_scroll_to_mark(GtkTextView *text_view, GtkTextMark *mark, gdouble within_margin, gboolean use_align, gdouble xalign, gdouble yalign)
{
    static uint64_t counter = 0;
    printf("%s: within_margin=%f, use_align=%d, xalign=%f, yalign=%f: %lu\n", __func__, within_margin, use_align, xalign, yalign, counter++);

    gtk_text_view_scroll_to_mark_func original_gtk_text_view_scroll_to_mark =
        (gtk_text_view_scroll_to_mark_func)dlsym(RTLD_NEXT, "gtk_text_view_scroll_to_mark");

    original_gtk_text_view_scroll_to_mark(text_view, mark, within_margin, use_align, xalign, yalign);
}

GtkTextBuffer *gtk_text_view_get_buffer(GtkTextView *text_view)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);

    gtk_text_view_get_buffer_func original_gtk_text_view_get_buffer =
        (gtk_text_view_get_buffer_func)dlsym(RTLD_NEXT, "gtk_text_view_get_buffer");

    return original_gtk_text_view_get_buffer(text_view);
}

gchar *gtk_text_buffer_get_text(GtkTextBuffer *buffer, const GtkTextIter *start, const GtkTextIter *end, gboolean include_hidden_chars)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);

    gtk_text_buffer_get_text_func original_gtk_text_buffer_get_text =
        (gtk_text_buffer_get_text_func)dlsym(RTLD_NEXT, "gtk_text_buffer_get_text");

    return original_gtk_text_buffer_get_text(buffer, start, end, include_hidden_chars);
}

void gtk_text_buffer_delete(GtkTextBuffer *buffer, GtkTextIter *start, GtkTextIter *end)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);

    gtk_text_buffer_delete_func original_gtk_text_buffer_delete =
        (gtk_text_buffer_delete_func)dlsym(RTLD_NEXT, "gtk_text_buffer_delete");

    original_gtk_text_buffer_delete(buffer, start, end);
}

void gtk_text_buffer_get_start_iter(GtkTextBuffer *buffer, GtkTextIter *iter)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);

    gtk_text_buffer_get_start_iter_func original_gtk_text_buffer_get_start_iter =
        (gtk_text_buffer_get_start_iter_func)dlsym(RTLD_NEXT, "gtk_text_buffer_get_start_iter");

    original_gtk_text_buffer_get_start_iter(buffer, iter);
}

void gtk_text_buffer_get_end_iter(GtkTextBuffer *buffer, GtkTextIter *iter)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);

    gtk_text_buffer_get_end_iter_func original_gtk_text_buffer_get_end_iter =
        (gtk_text_buffer_get_end_iter_func)dlsym(RTLD_NEXT, "gtk_text_buffer_get_end_iter");

    original_gtk_text_buffer_get_end_iter(buffer, iter);
}

void gtk_text_view_get_visible_rect(GtkTextView *text_view, GdkRectangle *visible_rect)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);

    gtk_text_view_get_visible_rect_func original_func =
        (gtk_text_view_get_visible_rect_func)dlsym(RTLD_NEXT, "gtk_text_view_get_visible_rect");

    original_func(text_view, visible_rect);
}

gboolean gtk_text_view_get_iter_at_position(GtkTextView *text_view, GtkTextIter *iter, gint *trailing, gint x, gint y)
{
    static uint64_t counter = 0;
    printf("%s: x=%d, y=%d: %lu\n", __func__, x, y, counter++);

    gtk_text_view_get_iter_at_position_func original_func =
        (gtk_text_view_get_iter_at_position_func)dlsym(RTLD_NEXT, "gtk_text_view_get_iter_at_position");

    return original_func(text_view, iter, trailing, x, y);
}

void gtk_text_view_get_iter_location(GtkTextView *text_view, const GtkTextIter *iter, GdkRectangle *location)
{
    static uint64_t counter = 0;
    printf("%s: %lu\n", __func__, counter++);

    gtk_text_view_get_iter_location_func original_func =
        (gtk_text_view_get_iter_location_func)dlsym(RTLD_NEXT, "gtk_text_view_get_iter_location");

    original_func(text_view, iter, location);
}

gboolean gtk_text_view_get_iter_at_location(GtkTextView *text_view, GtkTextIter *iter, gint x, gint y)
{
    static uint64_t counter = 0;
    printf("%s: x=%d, y=%d: %lu\n", __func__, x, y, counter++);

    gtk_text_view_get_iter_at_location_func original_func =
        (gtk_text_view_get_iter_at_location_func)dlsym(RTLD_NEXT, "gtk_text_view_get_iter_at_location");

    return original_func(text_view, iter, x, y);
}

void gtk_text_view_window_to_buffer_coords(GtkTextView *text_view, GtkTextWindowType win, gint window_x, gint window_y, gint *buffer_x, gint *buffer_y)
{
    static uint64_t counter = 0;
    printf("%s: window_x=%d, window_y=%d: %lu\n", __func__, window_x, window_y, counter++);

    gtk_text_view_window_to_buffer_coords_func original_func =
        (gtk_text_view_window_to_buffer_coords_func)dlsym(RTLD_NEXT, "gtk_text_view_window_to_buffer_coords");

    original_func(text_view, win, window_x, window_y, buffer_x, buffer_y);
}

void gtk_text_view_buffer_to_window_coords(GtkTextView *text_view, GtkTextWindowType win, gint buffer_x, gint buffer_y, gint *window_x, gint *window_y)
{
    static uint64_t counter = 0;
    printf("%s: buffer_x=%d, buffer_y=%d: %lu\n", __func__, buffer_x, buffer_y, counter++);

    gtk_text_view_buffer_to_window_coords_func original_func =
        (gtk_text_view_buffer_to_window_coords_func)dlsym(RTLD_NEXT, "gtk_text_view_buffer_to_window_coords");

    original_func(text_view, win, buffer_x, buffer_y, window_x, window_y);
}

void gtk_text_view_get_line_at_y(GtkTextView *text_view, GtkTextIter *target_iter, gint y, gint *line_top)
{
    static uint64_t counter = 0;
    printf("%s: y=%d: %lu\n", __func__, y, counter++);

    gtk_text_view_get_line_at_y_func original_func =
        (gtk_text_view_get_line_at_y_func)dlsym(RTLD_NEXT, "gtk_text_view_get_line_at_y");

    return original_func(text_view, target_iter, y, line_top);
}
