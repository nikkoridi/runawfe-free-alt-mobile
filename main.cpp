#include <glibmm/keyfile.h>
#include <glibmm/miscutils.h>
#include <gtkmm.h>
#include <iostream>

using namespace std;

const string APP_ID = "ru.runawfe.Runner";
const string DEFAULT_URL = "https://runawfe.ru/";

void open_url(const std::string& url) {
    try {
        Gio::AppInfo::launch_default_for_uri(url);
    } catch (const Gio::Error& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

string read_url_from_config() {
    string url = "";
    Glib::KeyFile key_file;
    try {
        string config_path = Glib::build_filename(Glib::get_user_config_dir(),
                                                  APP_ID,
                                                  "config.ini");
        cout << config_path << endl;
        key_file.load_from_file(config_path);
        url = key_file.get_string("Settings", "url");
    }
    catch (const Glib::FileError& e) {
        cerr << "Failed to open config: " << endl << e.what() << endl;
    }
    catch (const Glib::Error& e) {
        cerr << e.what() << endl;
    }
    return url;
}


static void run() {
    string website_url = read_url_from_config();
    if (!website_url.empty()) {
        open_url(website_url);
    }
    else {
        open_url(DEFAULT_URL);
    }
}


int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(APP_ID);
    app->signal_activate().connect(sigc::ptr_fun(&run));
    return app->run();
}
