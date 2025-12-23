//connection.cpp

#include <iostream>
#include <crow.h>
#include <string>
#include "static.h"

using namespace std;

crow::SimpleApp& init_server() {

    static crow::SimpleApp app;
    crow::mustache::set_global_base("templates/");

    return app;
}



int main () {

    crow::SimpleApp& app = init_server();

    CROW_ROUTE(app, "/")([](){return render("form.html");});
    //CROW_ROUTE(app, "/")([](crow::response res){return res.end();});
    CROW_ROUTE(app, "/static/ws.js")([](){
        crow::response res;
        res.set_static_file_info("templates/static/ws.js");
        return res;
    });

    CROW_WEBSOCKET_ROUTE(app, "/ws")
    .onopen([](crow::websocket::connection& conn) {std::cout << "Client connected\n";})
    .onclose([](crow::websocket::connection& conn, const std::string& reason, uint16_t code) {std::cout << "Client disconnected: " << reason << "\n";});


    app.port(18080).multithreaded().run();



    return 0;
}