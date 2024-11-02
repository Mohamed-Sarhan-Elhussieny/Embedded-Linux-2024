#include "server.hpp"
#define PORT_HOST 8000 // Defines the port number for the server to listen on
#define ADDRESS_HOST_IP "192.168.1.7" // Defines the IP address for the host server 

// Constructor
serverhandel::serverhandel() {}

// Destructor
serverhandel::~serverhandel()
{
    server_close();
}

/************************** Initialization method ***********************/

bool serverhandel::server_init(void)
{

    close(client_socket_state); // to surely close any soccket

    /******************************* Variable Declarations  **************** */
    struct sockaddr_in serverAddr;               // Structure for socket address details
    WSADATA wsaData;                             // Winsock API to hold information about the Windows Sockets

    /***************************************  Winsock Initialization *******************/
7
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "WSAStartup failed.\n"
                  << std::endl;
    }

    /********************** Socket Creation  *************************/
    socket_init = socket(AF_INET, SOCK_STREAM, 0);

    // Prepare the sockaddr_in structure
    serverAddr.sin_family = AF_INET;        // IPv4
    serverAddr.sin_port = htons(PORT_HOST); // Port in network byte order ="5000"
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the address and port
inet_pton(AF_INET, ADDRESS_HOST_IP, &serverAddr.sin_addr); // Convert the IP address from text to binary format for the sockaddr_in structure
    if (bind(socket_init, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
    std::cerr << "Bind failed. Error: " << std::endl;
    return -1; // Indicate failure
} else {
    std::cout << "Socket bound successfully" << std::endl;
    return 1;
}
  
}

/***************************** Listen Method ******************************/

bool serverhandel::server_listen(void)
{

    if (listen(socket_init, 2) == SOCKET_ERROR)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

/**************************** Accept Client Method  *****************************/

bool serverhandel::server_accept_client(void)
{

    struct sockaddr client_add;
    int size_of_client_add = sizeof(client_add);
    client_socket_state=accept(socket_init, (struct sockaddr *)&client_add, &size_of_client_add);
    if (client_socket_state == SOCKET_ERROR)
    {
        std::cerr << "accept failed.\n"
                  << std::endl;
        serverhandel::server_close();
        return -1;
    }
    else
    {
        std::cout << "Socket accept successfully" << std::endl;
        return 1;
    }
}

/**************************** Receive Client Message *****************************/
std::string serverhandel::server_recv_client_msg()
{
    int bytes_received = recv(client_socket_state, text_recv.data(), text_recv.size(), 0);
    if (bytes_received > 0)
    {
        std::cout << "Received successfully" << std::endl;
        return std::string(text_recv.data(), bytes_received); // Create a string from the received data
    }
    return ""; // Return an empty string if there’s an error
}

/**************************** Send Message Method *****************************/

bool serverhandel::server_send_msg(const std::string &message)
{
    if (send(socket_init, message.data(), sizeof(message), 0) )
    {
        return true;
    }
    return false;
}



/*************************** orgnize  text method **************************/

void serverhandel::trim_end(std::string &str)
{
    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(),str.end());
}

/*************************** Close Socket Method  ****************************/

void serverhandel::server_close()
{
    close(socket_init);
}



