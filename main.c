#include <gtk/gtk.h>
#include <stdlib.h>
#include <time.h>

// Structure to hold color data
typedef struct {
    GdkRGBA color;
} ColorData;

void generate_color_HEX(GtkWidget *button, gpointer data) {
    GtkWidget **widgets = (GtkWidget **)data;
    GtkWidget *drawing_area = widgets[0];
    GtkWidget *text_color = widgets[1];
    ColorData *color_data = (ColorData *)widgets[2];

    // Generate a random color
    char hex_color[8];
    sprintf(hex_color, "#%02X%02X%02X", rand() % 256, rand() % 256, rand() % 256);
    gdk_rgba_parse(&(color_data->color), hex_color);

    g_print("Generated Color HEX: %s\n", hex_color); // Print the generated color
    gtk_label_set_text(GTK_LABEL(text_color), hex_color);

    gtk_widget_queue_draw(drawing_area);
}

void generate_color_RGB(GtkWidget *button, gpointer data) {
    GtkWidget **widgets = (GtkWidget **)data;
    GtkWidget *drawing_area = widgets[0];
    GtkWidget *text_color = widgets[1];
    ColorData *color_data = (ColorData *)widgets[2];

    // Generate a random color
    char rgb_color[32];
    sprintf(rgb_color, "rgb(%d, %d, %d)", rand() % 256, rand() % 256, rand() % 256);
    gdk_rgba_parse(&(color_data->color), rgb_color);

    g_print("Generated Color RGB: %s\n", rgb_color); // Print the generated color
    gtk_label_set_text(GTK_LABEL(text_color), rgb_color);

    gtk_widget_queue_draw(drawing_area);
}

void generate_color_RGBA(GtkWidget *button, gpointer data) {
    GtkWidget **widgets = (GtkWidget **)data;
    GtkWidget *drawing_area = widgets[0];
    GtkWidget *text_color = widgets[1];
    ColorData *color_data = (ColorData *)widgets[2];

    // Generate a random color
    char rgba_color[32];
    snprintf(rgba_color, sizeof(rgba_color), "rgba(%d, %d, %d, %0.2f)", rand() % 256, rand() % 256, rand() % 256, (float)(rand() % 101) / 100);
    gdk_rgba_parse(&(color_data->color), rgba_color);

    g_print("Generated Color RGBA: %s\n", rgba_color); // Print the generated color
    gtk_label_set_text(GTK_LABEL(text_color), rgba_color);

    gtk_widget_queue_draw(drawing_area);
}

static gboolean draw_callback(GtkWidget *widget, cairo_t *cr, gpointer data) {
    ColorData *color_data = (ColorData *)data;
    gdk_cairo_set_source_rgba(cr, &(color_data->color));
    cairo_paint(cr);
    return FALSE;
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *drawing_area;
    GtkWidget *generate_button_hex;
    GtkWidget *generate_button_rgb;
    GtkWidget *generate_button_rgba;
    GtkWidget *text_color;

    ColorData color_data = { {0, 0, 0, 1} };  // Initialize with black color

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    char title[50];
    sprintf(title, "Colgen");

    gtk_window_set_title(GTK_WINDOW(window), title);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 200, 200);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    generate_button_hex = gtk_button_new_with_label("Generare HEX Color");
    generate_button_rgb = gtk_button_new_with_label("Generate RGB Color");
    generate_button_rgba = gtk_button_new_with_label("Generate RGBA Color");

    drawing_area = gtk_drawing_area_new();
    gtk_widget_set_size_request(drawing_area, 200, 100);  // Set a size for the drawing area
    gtk_box_pack_start(GTK_BOX(box), drawing_area, TRUE, TRUE, 0);

    text_color = gtk_label_new(" ");
    gtk_box_pack_start(GTK_BOX(box), text_color, FALSE, FALSE, 5);

    // Create an array to hold the widgets for passing to the callback
    GtkWidget *widgets[] = {drawing_area, text_color, (GtkWidget *)&color_data};
    g_signal_connect(generate_button_hex, "clicked", G_CALLBACK(generate_color_HEX), widgets);
    gtk_box_pack_start(GTK_BOX(box), generate_button_hex, FALSE, FALSE, 5);

    g_signal_connect(generate_button_rgb, "clicked", G_CALLBACK(generate_color_RGB), widgets);
    gtk_box_pack_start(GTK_BOX(box), generate_button_rgb, FALSE, FALSE, 5);

    g_signal_connect(generate_button_rgba, "clicked", G_CALLBACK(generate_color_RGBA), widgets);
    gtk_box_pack_start(GTK_BOX(box), generate_button_rgba, FALSE, FALSE, 5);
    
    g_signal_connect(drawing_area, "draw", G_CALLBACK(draw_callback), &color_data);

    gtk_widget_show_all(window);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();

    return 0;
}

