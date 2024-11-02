#include"server.hpp"
#include"command.hpp"


 int main()
 {
    serverhandel server;
    COMMAND command;

    if(server.server_init())
    {
        std::cout << "Socket created successfully" << std::endl;
    } else {
        std::cerr << "Socket creation failed" << std::endl;
        return 0;
    }

    if(server.server_listen())
    {
        std::cout << "Socket listen successfully" << std::endl;
    }
    else
     {
        std::cerr << "listen failed." << std::endl;
        return 0;

     }



    while (true) {

        std::cout<<"waiting connection"<<std::endl;
 

        if(server.server_accept_client())
        {
             std::cout << "accept client" << std::endl;


            while(1){
                        

                     std::string text_recv = server.server_recv_client_msg();
                     server.trim_end(text_recv);

                        if (text_recv=="exit" || text_recv=="EXIT")
                        {  
                            
                            std::cout << "Received: " << text_recv<< std::endl;
                             server.server_send_msg("Exiting the server.\n");
                            server.server_close();
                            return 0;
                        }
                        
                       if (command.open_website(text_recv))
                            {
                                std::cout << "Opened website successfully: " << text_recv << std::endl;
                            }
                            else
                            {
                                // If not a website, treat it as a PC order
                                command.pc_orders(text_recv);
                            }
                                    
                                }
        }
        
        else
        {
            std::cerr << "Failed to accept client." << std::endl;
            return 0;
        }
     }


return 0;
}

































//pc_control
 // g++ pc_control.cpp server.cpp command.cpp -pthread -std=c++14 -lws2_32; ./a.exe
