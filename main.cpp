#include <gtk/gtk.h>
#include <curl/curl.h>

using namespace std;

int main(int argc, char *argv[]) {
        GtkBuilder *builder; 
        GtkWidget *window;
        GtkWidget *aboutwin;

        gtk_init(&argc, &argv);

        builder = gtk_builder_new();
        gtk_builder_add_from_file (builder, "installer.glade", NULL);

        window = GTK_WIDGET(gtk_builder_get_object(builder, "installer"));
        aboutwin = GTK_WIDGET(gtk_builder_get_object(builder, "about"));
        gtk_builder_connect_signals(builder, NULL);

        g_object_unref(builder);

        gtk_widget_show(window);
        gtk_widget_show(aboutwin);              
        gtk_main();

        return 0;
}

namespace mainspace {
    // called when button is clicked
    void on_exit_clicked() {
        gtk_main_quit();
    }

    void on_aboutexit_clicked() {

    }

    void on_aboutopen_clicked() {

    }

    // called when window is closed
    void on_window_main_destroy() {
        gtk_main_quit();
    }
}
