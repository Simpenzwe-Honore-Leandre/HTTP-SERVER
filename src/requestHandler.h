#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

// struct request_struct{
//     std::string method = "";
//     int  status_code = -1;
//     std::string content_type = "";
// };



// void http_parse(char Buffer[], request_struct * request);
void handleRequest(const int &new_socket_fd);

#endif