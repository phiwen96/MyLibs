#include <ph/networking/networking.hpp>

using namespace std;

namespace ph::networking{


template <>
auto client (const char* msg, const char* ipaddress, const int& port) -> const char* {
      addrinfo info, *res;
      info.ai_family = AF_UNSPEC;
      info.ai_socktype = SOCK_STREAM;
      info.ai_flags = AI_PASSIVE;
      info.ai_protocol = IPPROTO_TCP;
      
      getaddrinfo(ipaddress, to_string(port).c_str(), &info, &res);
      
      int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
      
      connect(sock, res->ai_addr, res->ai_addrlen);
      
      freeaddrinfo(res);
      
      //            const char* toClient = "hejsan från klienten";
      
      send(sock, msg, strlen(msg) + 1, 0);
      
      char buf[4096];
      
      read (sock , buf, 4096);
      
      
      close (sock);
      
      
      return buf;
}

template <>
auto client (const char* msg, const char* ipaddress, const int& port) -> std::string {
      return std::string (client<const char*, const char*>(msg, ipaddress, port));
}

template <>
auto client (const char* msg, const char* ipaddress, const int& port) -> nlohmann::json {
      return nlohmann::json (nlohmann::json::parse(client<std::string, const char*>(msg, ipaddress, port)));
}







void sigchld_handler(int s)
{
      // waitpid() might overwrite errno, so we save and restore it:
      int saved_errno = errno;
      
      while(waitpid(-1, NULL, WNOHANG) > 0);
      
      errno = saved_errno;
}


// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
      if (sa->sa_family == AF_INET) {
            return &(((struct sockaddr_in*)sa)->sin_addr);
      }
      
      return &(((struct sockaddr_in6*)sa)->sin6_addr);
}



}
