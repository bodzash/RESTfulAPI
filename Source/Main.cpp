#include <iostream>
#include <ctime>
#include "httplib.h"
#include "nlohmann/json.hpp"
#include "Core/Guid.h"
#include "Core/Logger.h"
#include "Models/Breakfast.h"

using JSON = nlohmann::json;

int main()
{
    int ConifgPort = 8080;

    Logger::Init();
    httplib::Server Server;

    // Read One
    Server.Get("/breakfasts/:id", [](const httplib::Request& Req, httplib::Response& Res)
    {
        auto UserID = Req.path_params.at("id");

        JSON Data;
        Data["id"] = UserID;
        Data["name"] = "American Pancakes";      
    
        Res.set_content(Data.dump(), "application/json");
    });

    // Read All
    Server.Get("/breakfasts", [](const httplib::Request& Req, httplib::Response& Res)
    {
        JSON Data1;
        Data1["id"] = Guid().GetString();
        Data1["name"] = "American Pancakes";

        JSON Data2;
        Data2["id"] = Guid().GetString();
        Data2["name"] = "European Pancakes";

        JSON Data = { Data1, Data2 };
    
        Res.set_content(Data.dump(), "application/json");
    });

    // Create
    Server.Post("/breakfasts", [](const httplib::Request& Req, httplib::Response& Res)
    {
        JSON ReqData = JSON::parse(Req.body);

        // TODO: somehow serialize / deserialize
        Breakfast _Breakfast(
            Guid(),
            ReqData.at("name").get<std::string>(),
            ReqData.at("description").get<std::string>(),
            ReqData.at("startDateTime").get<int>(),
            ReqData.at("endDateTime").get<int>(),
            (int)std::time(nullptr),
            ReqData.at("savory").get<std::vector<std::string>>(),
            ReqData.at("sweet").get<std::vector<std::string>>()
        );

        // TODO: somehow serialize / deserialize
        JSON ResData;
        ResData["id"] = _Breakfast.GetID().GetString();
        ResData["name"] = _Breakfast.GetName();
        ResData["description"] = _Breakfast.GetDescription();
        ResData["startDateTime"] = _Breakfast.GetStartDateTime();
        ResData["endDateTime"] = _Breakfast.GetEndDateTime();
        ResData["lastModifiedDateTime"] = _Breakfast.GetLastModifiedDateTime();
        ResData["savory"] = _Breakfast.GetSavory();
        ResData["sweet"] = _Breakfast.GetSweet();

        Res.status = 201;
        Res.set_content(ResData.dump(), "application/json");
    });

    // Update
    Server.Put("/breakfasts/:id", [](const httplib::Request& Req, httplib::Response& Res)
    {
        RA_TRACE("PUT: id: {0}\n{1}", Req.path_params.at("id"), Req.body);
        JSON Data = JSON::parse(Req.body);

        Res.set_content(Data.dump(), "application/json");
    });

    // Delete
    Server.Delete("/breakfasts/:id", [](const httplib::Request& Req, httplib::Response& Res)
    {
        RA_TRACE("DELETE: id: {0}", Req.path_params.at("id"));

        // If already deleted send code 204
        Res.status = 200;
        Res.set_content("{}", "application/json");
    });

    RA_INFO("Server listening on http://localhost:{0}", ConifgPort);
    Server.listen("0.0.0.0", ConifgPort);
}
