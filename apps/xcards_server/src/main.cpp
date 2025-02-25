#include <networking/networking.hpp>

//using namespace ph::networking;




template <typename... T>
ostream& operator<< (ostream& os, const tuple<T...>& t)
{
      apply([&os](auto&&... args){((os << args << endl), ...);}, t);
      return os;
}

ostream& operator << (ostream& os, const vector<string>& v)
{
      os << "{" << endl;
      for(const auto& i : v){
            os << "\t" << i << endl;
      }
      os << "}";
      return os;
}








auto split2 (const char* str) -> vector<string> {
      istringstream iss(str);
      return {istream_iterator<string>(iss), {}};
      vector<string> result{
            istream_iterator<string>(iss), {}
      };
}

auto split (const char* str) -> tuple<string> {
      istringstream iss(str);
      tuple<string> tup;
      for(std::string s; iss >> s; )
      tuple_cat(tup, make_tuple(s));
      return tup;
}




#define FILE_accounts "/Users/pw/xcodeProjects/sockets/accounts.json"
#define FILE_decks "/Users/pw/xcodeProjects/sockets/decks.json"

#define PORT_get_accounts "54001"
#define PORT_get_decks "54002"
#define PORT_set_accounts "54003"
#define PORT_set_decks "54004"

auto getDataWithUserID = [](const char* dataFile, const char* port) {
      ph::networking::server(port, 10, [&dataFile](const char* clientMsg) -> string {
            if ( !ph::utility::isInteger(clientMsg) ) {
                  return "not an integer";
            } else {
                  int userID = atoi(clientMsg);
                  json userIDsJson = ph::utility::file::read<nlohmann::json>(dataFile)["ids"];
                  if ( userID < 0 || userID >= userIDsJson.size() ) {
                        return "user id out of range";
                  } else {
                        return userIDsJson[userID].dump();
                  }
            }
      });
};


auto getUserIDWithEmailAndPassword = [](const char* userIDsFile, const char* port) {
      ph::networking::server(port, 10, [id = ph::utility::file::read<json>(userIDsFile)["userinfo"]](const auto& msg) -> string {
            //                  string msg = clientMsg;
            vector<string> result = split2(msg);
            auto clientEmail = result.front();
            auto clientPassword = result.back();
            
            for(const auto& userID : id)
            {
                  if ( userID["email"] == clientEmail ) {
                        if ( userID["password"] != clientPassword ) {
                              return "wrong password";
                        }
                        return userID["id"].dump().c_str();
                  }
            }
            return "email not found";
      });
};

enum class SETDATA {
      ERASE
};

auto setDataWithUserID = [](const char* dataFile, const char* port) {
      
      ph::networking::server(port, 10, [&dataFile](const char* msg){
            json data = ph::utility::file::read<json>(dataFile);
            vector<string> res = split2(msg);
            const string& userID = res[0];
            const string& method = res[1];
            string newData = res[2];
            if ( !ph::utility::isInteger(userID) ) {
                  return "userID is not an integer";
            }
            int userID_int = atoi(userID.c_str());
            
            if ( userID_int < 0 || userID_int >= data.size() ) {
                  return "user id out of range";
            }
            
            if ( method == "SET" ) {
                  for(auto& i : data){
                        //                        cout << i.dump(4) << endl;
                        if ( i["id"] == userID ) {
                              //                              cout << "before:" << i.dump()
                              i["root_deck"] = nlohmann::json::parse(newData);
                              ph::utility::file::write(dataFile, data.dump().c_str());
                              return "SUCCESS";
                        }
                  }
            }
            //            cout << ":" << split2(msg) << endl;
            //            vector<string> res = split(msg);
            //            cout << res << endl;
            
            return "FAILURE";
      });
};


auto getData = bind (getDataWithUserID, FILE_decks, PORT_get_decks);
auto getUserID = bind (getUserIDWithEmailAndPassword, FILE_accounts, PORT_get_accounts);
auto setData = bind (setDataWithUserID, FILE_decks, PORT_set_decks);







int main()
{
      
      
      //      json j1 = ph::file::read<json>(FILE_accounts);
      //      cout << j1.dump(4) << endl;
      //      return 0;
      //      return 0;
      
      
      
      thread th1([server = getUserID]{
            server();
      });
      
      thread th2([server = getData]{
            server();
      });
      
      thread th3([server = setData]{
            server();
      });
      
      th1.join();
      th2.join();
      th3.join();
      
      
      
      //      runServer("54001", 10, [](const char* clientMsg){return "hello from server";});
      //      Server s ("54001");
      //      s.run();
      
      
      //      SetAccounts server("accounts.json", "54000");
      //      server.run();
      
      std::cout << "Hello, World!\n";
      return 0;
}
