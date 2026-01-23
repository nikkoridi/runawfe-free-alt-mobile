#include <glib/gi18n.h>
#include <gtk/gtk.h>

const gchar *APP_ID = "ru.runawfe.Runner";
const gchar *DEFAULT_URL = "https://runawfe.ru/";

static gint open_url(const gchar *url) {
    GError *error = NULL;
    if (url == NULL || *url == '\0') {
        g_printerr("Url is empty\n");
        g_clear_error(&error);
        return 1;
    }
    if (!g_app_info_launch_default_for_uri(url, NULL, &error)) {
        g_printerr("Failed to open %s: %s\n", url, error->message);
        g_clear_error(&error);
        return 1;
    }
    return 0;
}

static gchar *read_url_from_config(void) {
    GKeyFile *key_file = g_key_file_new();
    GError *error = NULL;
    const gchar *config_dir = g_get_user_config_dir();
    gchar *config_path, *url;
    config_path = g_build_filename(config_dir, "config.ini", NULL);
    if (!g_key_file_load_from_file(key_file,
                                   config_path,
                                   G_KEY_FILE_NONE,
                                   &error)) {
        g_printerr("Failed to open config %s: %s\n", config_path, error->message);
        g_clear_error(&error);
        return NULL;
    }
    url = g_key_file_get_string(key_file,
                                "Settings",
                                "url",
                                &error);
    if (url == NULL) {
        g_printerr("Missing 'url' key in config %s: %s\n", config_path, error->message);
        g_clear_error(&error);
    }
    g_free(config_path);
    return (gchar *)url;
}

static void run(GApplication *app, gpointer *user_data) {
    gchar *website_url = read_url_from_config();
    if (website_url != NULL && *website_url != '\0') {
        open_url(website_url);
    }
    else {
        open_url(DEFAULT_URL);
    }
    g_free(website_url);
}

int main (int   argc, char *argv[]) {
    GtkApplication *app;
    int ret;

    app = gtk_application_new (APP_ID, G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (run), NULL);

    ret =  g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return ret;
}

